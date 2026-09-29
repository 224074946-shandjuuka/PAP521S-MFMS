#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "budget.h"

char deptNames[MAX_DEPARTMENTS][NAME_LEN];
double allocatedBudget[MAX_DEPARTMENTS];
double expenditure[MAX_DEPARTMENTS];
int deptCount = 0;

void clearBuffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
	{
	}
}

double getAmount(const char *prompt) {
	double value;
	int result;

	while (1) {
		printf("%s", prompt);
		result = scanf("%lf", &value);

		if (result == EOF) {
			exit(0);
		}
		clearBuffer();

		if (result != 1) {
			printf("Error: please enter a number.\n");
		}
		else if (value < 0) {
			printf("Error: please enter a positive number.\n");
		}
		else {
			return value;
		}

	}
}

void getName(char prompt[], char name[]) {
	int len;

	while (1) {
		printf("%s", prompt);
		if (fgets(name, NAME_LEN, stdin) == NULL) {
			exit(0);
		}
		len = strlen(name);
		if (len > 0 && name[len - 1] == '\n') {
			name[len - 1] = '\0';
		}
		else {
			clearBuffer();
		}
		if (strlen(name) == 0) {
			printf("Error: please enter a name.\n");
		}
		else {
			return;
		}
	}
}

int findDepartment(char name[]) {
	int i;
	for (int i = 0; i < deptCount; i++) {
		if (strcmp(name, deptNames[i]) == 0) {
			return i;
		}
	}
	return -1;
}

void printHeader(void) {
	printf("\n%-20s %14s %14s %14s  %s\n", "Department", "Allocated", "Spent", "Remaining", "status");
	printf("-------------------------------------------------------------------------------------------\n");
}

void printDepartment(int i) {
	double remaining = calculateRemaining(allocatedBudget[i], expenditure[i]);

	printf("%-20s N$%12.2f N$%12.2f N$%12.2f   ", deptNames[i], allocatedBudget[i], expenditure[i], remaining);

	if (isWithinBudget(allocatedBudget[i], expenditure[i]) == 1) {
		printf("Within Budget\n");
	}
	else {
		printf("Over Budget\n");
	}
}

double calculateRemaining(double allocated, double spent) {
	return allocated - spent;
}

int isWithinBudget(double allocated, double spent) {
	if (spent <= allocated) {
		return 1;
	}
	return 0;
}

double getTotalAllocatedBudget(void) {
	double total = 0;
	int i;

	for (int i = 0; i < deptCount; i++) {
		total += allocatedBudget[i];
	}
	return total;
}

double getTotalExpenditure(void) {
	double total = 0;
	int i;
	for (int i = 0; i < deptCount; i++) {
		total += expenditure[i];
	}
	return total;
}

int getDepartmentCount(void) {
	return deptCount;
}

void addDepartmentBudget(void) {
	char name[NAME_LEN];
	double amount;

	printf("\n--- Add Department Budget ---\n");

	if (deptCount >= MAX_DEPARTMENTS) {
		printf("Error: the system is full.\n");
		return;
	}
	getName("Enter Department name: ", name);
	if (findDepartment(name) != -1) {
		printf("Error: this department already has a budget.\n");
		return;
	}

	amount = getAmount("Enter allocated budget (N$): ");
	
	strcpy(deptNames[deptCount], name);
	allocatedBudget[deptCount] = amount;
	expenditure[deptCount] = 0;
	deptCount++;

	printf("Budget added successfully.\n");
 }

void recordExpenditure(void) {
	char name[NAME_LEN];
	double amount;
	int position;

	printf("\n--- Record Expenditure ---\n");
	if (deptCount == 0) {
		printf("There are no departments yet. Add a budget first.\n");
		return;
	}
	getName("Enter Department name: ", name);
	position = findDepartment(name);
	if (position == -1) {
		printf("Error: department not found.\n");
		return;
	}

	amount = getAmount("Enter expenditure (N$): ");
	expenditure[position] = expenditure[position] + amount;

	printHeader();
	printDepartment(position);

	if (isWithinBudget(allocatedBudget[position], expenditure[position]) == 0) {
		printf("\nWarning: this department has exceeded it's budget!\n");
	}
}

void displayBudget(void) {
	int i;
	printf("\n--- All Department Budgets ---\n");

	if (deptCount == 0) {
		printf("No budget records found.\n");
		return;
	}
	printHeader();
	for (i = 0; i < deptCount; i++) {
		printDepartment(i);
	}
}

void searchDepartmentBudget(void) {
	char name[NAME_LEN];
	int position;

	printf("\n--- Search Department ---\n");

	if (deptCount == 0) {
		printf("No budget records found.\n");
		return;
	}
	getName("Enter Department name to search: ", name);
	position = findDepartment(name);

	if (position == -1) {
		printf("Department not found.\n");
	}
	else {
		printHeader();
		printDepartment(position);
	}
}

void displayExceededDepartment(void) {
	int i;
	int found = 0;

	printf("\n--- Departments Over Budget ---\n");

	for (i = 0; i < deptCount; i++) {
		if (isWithinBudget(allocatedBudget[i], expenditure[i]) == 0)
		{
			printf("%s - over by N$%.2f\n", deptNames[i], expenditure[i] - allocatedBudget[i]);
			found = 1;
		}
	}

	if (found == 0) {
		printf("No department has exceeded it's budget.\n");
	}
}

void displayBudgetReport(void) {
	double totalAllocated = getTotalAllocatedBudget();
	double totalSpent = getTotalExpenditure();
	printf("\n ========= BUDGET REPORT ========\n");

	if (deptCount == 0) {
		printf("No budget records found.\n");
		return;
	}

	printf("Total allocated budget: N$%.2f\n", totalAllocated);
	printf("Total expenditure:      N$%.2f\n", totalSpent);
	printf("Remaining budget:       N$%.2f\n", calculateRemaining(totalAllocated, totalSpent));

	displayExceededDepartment();
}

void budgetMenu(void) {
	int choice;
	int result;

	do {
		printf("\n==================================================\n");
		printf("                  BUDGET MANAGEMENT\n");
		printf("===================================================\n");
		printf("1. Add department budget\n");
		printf("2. Record expenditure\n");
		printf("3. Display all budgets\n");
		printf("4. Search department\n");
		printf("5. Show departments over the budget\n");
		printf("6. Budget summary report\n");
		printf("7. Back to main menu\n");
		printf("Enter your choice: ");


		result = scanf("%d", &choice);
		if (result == EOF) {
			exit(0);
		}
		clearBuffer();
		
		if (result != 1) {
			choice = 0;
		}
		switch (choice) {
		case 1:
			addDepartmentBudget();
			break;
		case 2:
			recordExpenditure();
			break;
		case 3:
			displayBudget();
			break;
		case 4:
			searchDepartmentBudget();
				break;
		case 5:
			displayExceededDepartment();
			break;
		case 6:
			displayBudgetReport();
			break;
		case 7:
			printf("Returning to main menu...\n");
			break;
		default:
			printf("Invalid choice. Please enter 1 to 7\n");
		}
	} while (choice != 7);
}
