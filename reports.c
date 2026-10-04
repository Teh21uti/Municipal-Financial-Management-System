#include <stdio.h>
#include <stdlib.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void runEmployeeReport(void);
void budgetReport(void);
void supplierReport(void);
void assetReport(void);

void reportsMenu(void) {
    int choice;
    do {
        printf("\n========================================\n");
        printf("            REPORTS MENU               \n");
        printf("========================================\n");
        printf("1. Employee Summary Report\n");
        printf("2. Budget & Expenditure Report\n");
        printf("3. Supplier Directory Report\n");
        printf("4. Asset Management Report\n");
        printf("5. Back to Main Menu\n");
        printf("========================================\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1: runEmployeeReport(); break;
            case 2: budgetReport(); break;
            case 3: supplierReport(); break;
            case 4: assetReport(); break;
            case 5: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);
}

void runEmployeeReport(void) {
    printf("\n--- EMPLOYEE REPORT ---\n");
    employeeMenu();
}

void budgetReport(void) {
    printf("\n--- BUDGET & EXPENDITURE REPORT ---\n");
    displayBudgets();
    checkExceededBudgets();
}

void supplierReport(void) {
    printf("\n--- SUPPLIER DIRECTORY REPORT ---\n");
    listSuppliers();
}

void assetReport(void) {
    printf("\n--- ASSET MANAGEMENT REPORT ---\n");
    assetMenu();
}