#include <stdio.h>
#include "reports.h"

void employeeReport(void) {
    int n;
    printf("\n===== EMPLOYEE REPORT =====\n");
    printf("How many employees? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No employees to report.\n");
        return;
    }

    double salaries[100];
    double total = 0.0;
    double highest, lowest;

    for (int i = 0; i < n; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%lf", &salaries[i]);
        total += salaries[i];
    }

    highest = lowest = salaries[0];
    for (int i = 1; i < n; i++) {
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest)  lowest  = salaries[i];
    }

    printf("\n--- Employee Summary ---\n");
    printf("Total salary   : %.2f\n", total);
    printf("Average salary : %.2f\n", total / n);
    printf("Highest salary : %.2f\n", highest);
    printf("Lowest salary  : %.2f\n", lowest);
}

void budgetReport(void) {
    int n;
    printf("\n===== BUDGET REPORT =====\n");
    printf("How many departments? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No departments to report.\n");
        return;
    }

    char names[100][50];
    double allocated[100], spent[100];
    double totalAllocated = 0.0, totalSpent = 0.0;

    for (int i = 0; i < n; i++) {
        printf("\nDepartment %d name: ", i + 1);
        scanf("%s", names[i]);
        printf("Allocated budget : ");
        scanf("%lf", &allocated[i]);
        printf("Amount spent     : ");
        scanf("%lf", &spent[i]);

        totalAllocated += allocated[i];
        totalSpent += spent[i];
    }

    printf("\n--- Budget Summary ---\n");
    printf("Total allocated : %.2f\n", totalAllocated);
    printf("Total spent     : %.2f\n", totalSpent);
    printf("Remaining       : %.2f\n", totalAllocated - totalSpent);

    printf("\nOver-budget departments:\n");
    int anyOver = 0;
    for (int i = 0; i < n; i++) {
        if (spent[i] > allocated[i]) {
            printf("  %s (over by %.2f)\n",
                   names[i], spent[i] - allocated[i]);
            anyOver = 1;
        }
    }
    if (!anyOver) printf("  None. All departments within budget.\n");
}

void supplierReport(void) {
    int n;
    printf("\n===== SUPPLIER REPORT =====\n");
    printf("How many suppliers? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No suppliers to report.\n");
        return;
    }

    char names[100][50];

    for (int i = 0; i < n; i++) {
        printf("Supplier %d name: ", i + 1);
        scanf("%s", names[i]);
    }

    printf("\n--- Supplier List ---\n");
    for (int i = 0; i < n; i++) {
        printf("  %d. %s\n", i + 1, names[i]);
    }
    printf("Total suppliers : %d\n", n);
}

void assetReport(void) {
    int n;
    printf("\n===== ASSET REPORT =====\n");
    printf("How many assets? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No assets to report.\n");
        return;
    }

    char names[100][50];
    double values[100];
    double total = 0.0;

    for (int i = 0; i < n; i++) {
        printf("Asset %d name  : ", i + 1);
        scanf("%s", names[i]);
        printf("Asset %d value : ", i + 1);
        scanf("%lf", &values[i]);
        total += values[i];
    }

    printf("\n--- Asset Summary ---\n");
    for (int i = 0; i < n; i++) {
        printf("  %-15s : %.2f\n", names[i], values[i]);
    }
    printf("Total value     : %.2f\n", total);
    printf("Average value   : %.2f\n", total / n);
}

void reportsMenu(void) {
    int choice;
    do {
        printf("\n===== REPORTS MENU =====\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("0. Back to Main Menu\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: employeeReport(); break;
            case 2: budgetReport();   break;
            case 3: supplierReport(); break;
            case 4: assetReport();    break;
            case 0: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}