/*====================================================
  main.c
  PAP521S Project A - Municipal Financial Management System
  Role 6: Integration and Menu
  Author: Laimi Shandjuka (224074946)
====================================================*/

#include <stdio.h>
#include "reports.h"

void employeeMenu();
void budgetMenu();
void supplierMenu();
void assetMenu();
void reportMenu();
        
int main() {
    int choice = 0;

    while (choice != 6) {

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