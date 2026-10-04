#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void reportsMenu(void)
{
    int choice;

    do {
        printf("\n--- Reports ---\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        } else {
            while (getchar() != '\n');
        }

        switch (choice) {
            case 1: employeeReport(); break;
            case 2: budgetReport(); break;
            case 3: supplierReport(); break;
            case 4: assetReport(); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}

void employeeReport(void)
{
    int i;
    double total = 0.0;
    double highest = 0.0;
    double lowest = 0.0;

    if (employeeCount == 0) {
        printf("\nNo employee data available.\n");
        return;
    }

    for (i = 0; i < employeeCount; i++) {
        double salary = calculateSalary(&employees[i]);
        total += salary;

        if (i == 0 || salary > highest) {
            highest = salary;
        }
        if (i == 0 || salary < lowest) {
            lowest = salary;
        }
    }

    printf("\n--- Employee Report ---\n");
    printf("Total Employees: %d\n", employeeCount);
    printf("Average Salary: N$%.2f\n", total / employeeCount);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);
}

void budgetReport(void)
{
    int i;
    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    int exceeded = 0;

    for (i = 0; i < budgetCount; i++) {
        totalAllocated += budgets[i].allocated;
        totalExpenditure += budgets[i].expenditure;

        if (budgets[i].expenditure > budgets[i].allocated) {
            exceeded++;
        }
    }

    printf("\n--- Budget Report ---\n");
    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Remaining Budget: N$%.2f\n", totalAllocated - totalExpenditure);
    printf("Departments Exceeding Budget: %d\n", exceeded);

    if (exceeded > 0) {
        showExceededBudgets();
    }
}

void supplierReport(void)
{
    printf("\n--- Supplier Report ---\n");
    displaySuppliers();
}

void assetReport(void)
{
    printf("\n--- Asset Report ---\n");
    displayAssets();
}
