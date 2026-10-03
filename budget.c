#include<stdio.h>

int main() {
    char department[50];
    float allocatedBudget, expenditure, remainingBudget;

    printf("Enter Department Name: ");
    scanf("%s", department);

    printf("Enter Allocated Budget: ");
    scanf("%f", &allocatedBudget);

    printf("Enter Expenditure: ");
    scanf("%f", &expenditure);

    remainingBudget = allocatedBudget - expenditure;

    printf("\nDepartment: %s", department);
    printf("\nAllocated Budget: N$%.2f", allocatedBudget);
    printf("\nExpenditure: N$%.2f", expenditure);
    printf("\nRemaining Budget: N$%.2f", remainingBudget);

    if (expenditure <= allocatedBudget) {
        printf("\nStatus: WITHIN BUDGET\n");
    } else {
        printf("\nStatus: EXCEEDED BUDGET\n");
    }

    return 0;
}
