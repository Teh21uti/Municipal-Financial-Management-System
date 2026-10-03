
#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 100

typedef struct {
    int departmentID;
    char departmentName[50];
    double allocatedBudget;
    double expenditure;
    double remainingBudget;
} Budget;

// Function declarations
void addBudget();
void displayBudgets();
void calculateBudget();
void checkExceededBudgets();
void budgetMenu();

#endif