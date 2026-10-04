
#include <stdio.h>
#include <string.h>
#include "budget.h"

Budget budgets[MAX_DEPARTMENTS];
int budgetCount = 0;

void addBudget() {
    if (budgetCount >= MAX_DEPARTMENTS) {
        printf("\nMaximum departments reached!\n");
        return;
    }

    printf("\n===== ADD DEPARTMENT BUDGET =====\n");

    budgets[budgetCount].departmentID = budgetCount + 1;

    printf("Enter Department Name: ");
    scanf(" %49[^\n]", budgets[budgetCount].departmentName);

    printf("Enter Allocated Budget (N$): ");
    scanf("%lf", &budgets[budgetCount].allocatedBudget);

    if (budgets[budgetCount].allocatedBudget < 0) {
        printf("Invalid budget! Cannot be negative.\n");
        return;
    }

    printf("Enter Expenditure (N$): ");
    scanf("%lf", &budgets[budgetCount].expenditure);

    if (budgets[budgetCount].expenditure < 0) {
        printf("Invalid expenditure!\n");
        return;
    }

    budgets[budgetCount].remainingBudget =
        budgets[budgetCount].allocatedBudget -
        budgets[budgetCount].expenditure;

    budgetCount++;

    printf("\nBudget added successfully!\n");
}

void displayBudgets() {
    int i;

    if (budgetCount == 0) {
        printf("\nNo budget records available.\n");
        return;
    }

    printf("\n========== BUDGET RECORDS ==========\n");

    for (i = 0; i < budgetCount; i++) {
        printf("\nDepartment ID: %d\n",
               budgets[i].departmentID);

        printf("Department: %s\n",
               budgets[i].departmentName);

        printf("Allocated Budget: N$%.2f\n",
               budgets[i].allocatedBudget);

        printf("Expenditure: N$%.2f\n",
               budgets[i].expenditure);

        printf("Remaining Budget: N$%.2f\n",
               budgets[i].remainingBudget);

        if (budgets[i].remainingBudget >= 0) {
            printf("Status: WITHIN BUDGET\n");
        } else {
            printf("Status: EXCEEDED BUDGET\n");
        }
    }
}

void calculateBudget() {
    int i;

    if (budgetCount == 0) {
        printf("\nNo budgets available to calculate.\n");
        return;
    }

    for (i = 0; i < budgetCount; i++) {
        budgets[i].remainingBudget =
            budgets[i].allocatedBudget -
            budgets[i].expenditure;
    }

    printf("\nBudget calculations completed!\n");

    displayBudgets();
}

void checkExceededBudgets() {
    int i;
    int found = 0;

    printf("\n===== DEPARTMENTS EXCEEDING BUDGET =====\n");

    for (i = 0; i < budgetCount; i++) {
        if (budgets[i].expenditure >
            budgets[i].allocatedBudget) {

            printf("\nDepartment: %s\n",
                   budgets[i].departmentName);

            printf("Allocated: N$%.2f\n",
                   budgets[i].allocatedBudget);

            printf("Expenditure: N$%.2f\n",
                   budgets[i].expenditure);

            printf("Overspent: N$%.2f\n",
                   budgets[i].expenditure -
                   budgets[i].allocatedBudget);

            found = 1;
        }
    }

    if (found == 0) {
        printf("No departments have exceeded their budgets.\n");
    }
}

void budgetMenu() {
    int choice;

    do {
        printf("\n================================\n");
        printf("       BUDGET MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Department Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Calculate Remaining Budget\n");
        printf("4. Check Exceeded Budgets\n");
        printf("5. Return to Main Menu\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBudget();
                break;

            case 2:
                displayBudgets();
                break;

            case 3:
                calculateBudget();
                break;

            case 4:
                checkExceededBudgets();
                break;

            case 5:
                printf("Returning to Main Menu...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);
}
