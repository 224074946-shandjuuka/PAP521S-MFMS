#include "suppliers.h"
#include <stdio.h>
#include <string.h>

    void addSupplier();
    void displaySuppliers();
    void searchSupplier();



    
    char supplierName[50][50];
    char email[50][50];
    char telephoneNumber[50][20];
    char town[50][50];
    int supplierCount = 0;
    int choice;

    void supplierMenu() {
    do {
        printf("\nSupplier Management System\n");
        printf("1. Add New Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search for a Supplier\n");
        printf("0. Back to Main Menu\n");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) 
        {

            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                searchSupplier();
                break;
            case 0:
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    
}


    void addSupplier()
    {
    if (supplierCount >= 50) {
        printf("Maximum number of suppliers reached. Cannot add more.\n");
        return;
    }
    int i = supplierCount;

        
        printf("Enter Supplier Name: ");
        scanf(" %49[^\n]", supplierName[i]);
        printf("Enter Email: ");
        scanf(" %49s", email[i]);
        printf("Enter Telephone Number: ");
        scanf(" %19s", telephoneNumber[i]);
        printf("Enter Town: ");
        scanf(" %49[^\n]", town[i]);
        supplierCount++;
        printf("\nSupplier added successfully!\n");
        }


    void displaySuppliers() {
    int i;
        
        if(supplierCount == 0) {
            printf("No suppliers to display.\n");
        } else {    for (i = 0; i < supplierCount; i++) {
            printf("\nSupplier %d:\n", i + 1);
            printf("Supplier Name: %s\n", supplierName[i]);
            printf("Email: %s\n", email[i]);
            printf("Telephone Number: %s\n", telephoneNumber[i]);
            printf("Town: %s\n", town[i]);
        }
        
                       }
                    }

     void searchSupplier() {
    char searchName[50];
    printf("Enter Supplier Name to search: ");    
    scanf("%49[^\n]", searchName);
    for (int i = 0; i < supplierCount; i++) {  

    if (strcmp(searchName, supplierName[i]) == 0) {
        printf("Supplier found:\n");
        printf("Supplier Name: %s\n", supplierName[i]);
        printf("Email: %s\n", email[i]);
        printf("Telephone Number: %s\n", telephoneNumber[i]);
        printf("Town: %s\n", town[i]);
        return; // Exit the function after finding the supplier
    } }
    
        printf("Supplier not found.\n");
    }



   

        
