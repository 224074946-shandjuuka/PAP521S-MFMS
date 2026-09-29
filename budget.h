#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 20
#define NAME_LEN 50

void budgetMenu(void);
void addDepartmentBudget(void); 
void recordExpenditure(void);
void displayBudgets(void);
void searchDepartmentBudget(void);
void displayExceededDepartments(void);

double calculateRemaining(double allocated, double spent);
int isWithinBudget(double allocated, double spent);

double getTotalAllocatedBudget(void);
double getTotalExpenditure(void);
int  getDepartmentCount(void);    
void  displayBudgetReport(void);
#endif // BUDGET_H