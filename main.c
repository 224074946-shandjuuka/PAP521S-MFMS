/*====================================================
  main.c
  PAP521S Project A - Municipal Financial Management System
  Role 6: Integration and Menu
  Author: Laimi Shandjuka (224074946)
====================================================*/

#include <stdio.h>

void employeeMenu();
void budgetMenu();
void supplierMenu();
void assetMenu();
void reportsMenu();

int main() {
    int choice = 0;

    printf("Welcome to the Municipal Financial Management System\n");

    while (choice != 6) {
        printf("\n========================================\n");
        printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("  1. Employee Management\n");
        printf("  2. Budget Management\n");
        printf("  3. Supplier Management\n");
        printf("  4. Asset Management\n");
        printf("  5. Reports\n");
        printf("  6. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: employeeMenu(); break;
            case 2: budgetMenu();   break;
            case 3: supplierMenu(); break;
            case 4: assetMenu();    break;
            case 5: reportsMenu();  break;
            case 6: printf("\nGoodbye. Exiting MFMS.\n"); break;
            default: printf("\nInvalid choice. Please enter 1 to 6.\n");
        }
    }
    return 0;
}