#include <stdio.h>
#include <string.h>
#include "assets.h"

/* Parallel arrays — max 50 assets */
static int    assetIDs[50];
static char   names[50][50];
static char   types[50][50];
static double values[50];
static char   departments[50][50];
static char   conditions[50][50];
static int    assetCount = 0;

/* ---------- SUBMENU ---------- */
void assetMenu(void) {
    int choice;

    do {
        printf("\n===== ASSET MANAGEMENT =====\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset\n");
        printf("0. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addAsset();      break;
            case 2: displayAssets(); break;
            case 3: searchAsset();   break;
            case 0: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}

/* ---------- ADD ASSET ---------- */
void addAsset(void) {
    if (assetCount >= 50) {
        printf("Asset register is full.\n");
        return;
    }

    int    id;
    char   name[50];
    char   type[50];
    double value;
    char   department[50];
    char   condition[50];

    printf("\nEnter Asset ID: ");
    scanf("%d", &id);

    /* Reject duplicate ID */
    for (int i = 0; i < assetCount; i++) {
        if (assetIDs[i] == id) {
            printf("Error: Asset ID %d already exists.\n", id);
            return;
        }
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Type (Vehicle/Computer/Building): ");
    scanf(" %[^\n]", type);

    printf("Enter Purchase Value: ");
    scanf("%lf", &value);

    /* Reject negative values */
    if (value < 0) {
        printf("Error: Purchase value cannot be negative.\n");
        return;
    }

    printf("Enter Department: ");
    scanf(" %[^\n]", department);

    printf("Enter Condition (New/Good/Fair/Poor): ");
    scanf(" %[^\n]", condition);

    /* Store in parallel arrays */
    assetIDs[assetCount] = id;
    strcpy(names[assetCount], name);
    strcpy(types[assetCount], type);
    values[assetCount] = value;
    strcpy(departments[assetCount], department);
    strcpy(conditions[assetCount], condition);

    assetCount++;
    printf("Asset added successfully.\n");
}

/* ---------- DISPLAY ALL ---------- */
void displayAssets(void) {
    if (assetCount == 0) {
        printf("\nNo assets recorded yet.\n");
        return;
    }

    printf("\n%-5s | %-20s | %-12s | %-12s | %-15s | %-10s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");
    printf("------------------------------------------------------------------------------------\n");

    for (int i = 0; i < assetCount; i++) {
        printf("%-5d | %-20s | %-12s | %-12.2f | %-15s | %-10s\n",
               assetIDs[i], names[i], types[i],
               values[i], departments[i], conditions[i]);
    }
}

/* ---------- SEARCH ---------- */
void searchAsset(void) {
    if (assetCount == 0) {
        printf("\nNo assets to search.\n");
        return;
    }

    int id;
    printf("\nEnter Asset ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < assetCount; i++) {
        if (assetIDs[i] == id) {
            printf("\n--- Asset Found ---\n");
            printf("  ID          : %d\n", assetIDs[i]);
            printf("  Name        : %s\n", names[i]);
            printf("  Type        : %s\n", types[i]);
            printf("  Value       : %.2f\n", values[i]);
            printf("  Department  : %s\n", departments[i]);
            printf("  Condition   : %s\n", conditions[i]);
            return;
        }
    }

    printf("Asset not found\n");
}