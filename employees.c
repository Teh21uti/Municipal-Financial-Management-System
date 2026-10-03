#include <stdio.h>
#include <string.h>
#include "employees.h"

/* EMPLOYEE DATA */
char empIds[100][10];
char empNames[100][50];
char empDepartments[100][30];
float empBasic[100];
float empHousing[100];
float empTransport[100];
int employeeCount = 0;

/* FUNCTION PROTOTYPE */
void empClearLine();
float empReadAmount();
void empShowEmployee(int i, char ids[][10], char names[][50], char departments[][30],
                     float basic[], float housing[], float transport[]);

/*
   FUNCTIONS CALLED BY main.c AND reports.c*/

void employeeMenu(void)
{
    employeeCount = employeeMenuRun(empIds, empNames, empDepartments,
                                    empBasic, empHousing, empTransport,
                                    employeeCount);
}

void employeeReport(void)
{
    displayEmployeeReport(empBasic, empHousing, empTransport, employeeCount);
}

/* 
   EMPLOYEE MENU
*/

int employeeMenuRun(char ids[][10], char names[][50], char departments[][30],
                    float basic[], float housing[], float transport[], int count)
{
    char choice[50];

    strcpy(choice, "0");

    while (strcmp(choice, "5") != 0)
    {
        printf("\n========================================\n");
        printf("          EMPLOYEE MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add employee\n");
        printf("2. Display all employees\n");
        printf("3. Search for an employee\n");
        printf("4. Calculate salary\n");
        printf("5. Back to main menu\n");
        printf("Enter your choice: ");

        /* fgets reads the whole line */
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';

        if (strlen(choice) != 1)
        {
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
        }
        else
        {
            switch (choice[0])
            {
                case '1':
                    count = addEmployee(ids, names, departments, basic, housing, transport, count);
                    break;
                case '2':
                    displayEmployees(ids, names, departments, basic, housing, transport, count);
                    break;
                case '3':
                    findEmployee(ids, names, departments, basic, housing, transport, count);
                    break;
                case '4':
                    displaySalaryInfo(ids, names, basic, housing, transport, count);
                    break;
                case '5':
                    break;
                default:
                    printf("Invalid choice. Please enter a number from 1 to 5.\n");
            }
        }
    }

    return count;
}

/*  INPUT HELPERS */


void empClearLine()
{
    char junk[50];

    fgets(junk, sizeof(junk), stdin);
}

/* Keeps asking until the user enters a number that is not negative. */
float empReadAmount()
{
    float amount = 0;
    char junk[50];
    int result;
    int valid = 0;

    while (valid == 0)
    {
        result = scanf("%f", &amount);

        if (result != 1)
        {
            scanf("%49s", junk);    /* remove the wrong text from the input */
        }
        empClearLine();             /* remove the Enter key left behind */

        if (result != 1)
        {
            printf("That is not a number. Please try again: ");
        }
        else if (amount < 0)
        {
            printf("The amount cannot be negative. Please try again: ");
        }
        else
        {
            valid = 1;
        }
    }
    return amount;
}

/*
   ADD, DISPLAY AND SEARCH*/

int addEmployee(char ids[][10], char names[][50], char departments[][30],
                float basic[], float housing[], float transport[], int count)
{
    char id[10];
    int valid = 0;

    printf("\n--- ADD EMPLOYEE ---\n");

    if (count >= 100)
    {
        printf("The employee list is full.\n");
        return count;
    }

    /* The ID must be at least 3 characters and must not already exist. */
    while (valid == 0)
    {
        printf("Employee ID (3 to 9 characters, e.g. E001): ");
        scanf("%9s", id);
        empClearLine();

        if (strlen(id) < 3)
        {
            printf("The ID is too short. Please try again.\n");
        }
        else if (searchEmployee(id, ids, count) != -1)
        {
            printf("An employee with ID %s already exists.\n", id);
        }
        else
        {
            valid = 1;
        }
    }
    strcpy(ids[count], id);

    printf("Full name: ");
    scanf(" %49[^\n]", names[count]);
    empClearLine();

    printf("Department: ");
    scanf(" %29[^\n]", departments[count]);
    empClearLine();

    printf("Basic salary (N$): ");
    basic[count] = empReadAmount();

    printf("Housing allowance (N$): ");
    housing[count] = empReadAmount();

    printf("Transport allowance (N$): ");
    transport[count] = empReadAmount();

    printf("\nEmployee added successfully.\n");

    
    return count + 1;
}

void displayEmployees(char ids[][10], char names[][50], char departments[][30],
                      float basic[], float housing[], float transport[], int count)
{
    printf("\n--- ALL EMPLOYEES ---\n");

    if (count == 0)
    {
        printf("No employees have been added yet.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        empShowEmployee(i, ids, names, departments, basic, housing, transport);
    }

    printf("\nTotal employees: %d\n", count);
}

/* Linear search: checks the IDs one by one. Returns the position or -1. */
int searchEmployee(char id[], char ids[][10], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(ids[i], id) == 0)
        {
            return i;
        }
    }
    return -1;
}

void findEmployee(char ids[][10], char names[][50], char departments[][30],
                  float basic[], float housing[], float transport[], int count)
{
    char id[10];
    int index;

    printf("\n--- SEARCH EMPLOYEE ---\n");

    if (count == 0)
    {
        printf("No employees have been added yet.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%9s", id);
    empClearLine();

    index = searchEmployee(id, ids, count);

    if (index == -1)
    {
        printf("No employee found with ID %s.\n", id);
    }
    else
    {
        printf("\nEmployee found:\n");
        empShowEmployee(index, ids, names, departments, basic, housing, transport);
    }
}

/* Shows the details of the employee at position i. */
void empShowEmployee(int i, char ids[][10], char names[][50], char departments[][30],
                     float basic[], float housing[], float transport[])
{
    float gross = calculateSalary(basic[i], housing[i], transport[i]);

    printf("  ID           : %s\n", ids[i]);
    printf("  Name         : %s\n", names[i]);
    printf("  Department   : %s\n", departments[i]);
    printf("  Basic salary : N$%.2f\n", basic[i]);
    printf("  Housing      : N$%.2f\n", housing[i]);
    printf("  Transport    : N$%.2f\n", transport[i]);
    printf("  Gross salary : N$%.2f\n", gross);
}

/* ==================================================================
   SALARY
   ================================================================== */

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

void displaySalaryInfo(char ids[][10], char names[][50],
                       float basic[], float housing[], float transport[], int count)
{
    char id[10];
    int index;
    float gross;

    printf("\n--- CALCULATE SALARY ---\n");

    if (count == 0)
    {
        printf("No employees have been added yet.\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%9s", id);
    empClearLine();

    index = searchEmployee(id, ids, count);

    if (index == -1)
    {
        printf("No employee found with ID %s.\n", id);
        return;
    }

    gross = calculateSalary(basic[index], housing[index], transport[index]);

    printf("\nEmployee     : %s (%s)\n", names[index], ids[index]);
    printf("Basic salary : N$%.2f\n", basic[index]);
    printf("Housing      : N$%.2f\n", housing[index]);
    printf("Transport    : N$%.2f\n", transport[index]);
    printf("Gross salary : N$%.2f\n", gross);
}

/* ==================================================================
   EMPLOYEE REPORT
   ================================================================== */

void displayEmployeeReport(float basic[], float housing[], float transport[], int count)
{
    float gross;
    float total = 0;
    float highest = 0;
    float lowest = 0;

    printf("\n--- EMPLOYEE REPORT ---\n");

    if (count == 0)
    {
        printf("No employees have been added yet.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        gross = calculateSalary(basic[i], housing[i], transport[i]);
        total = total + gross;

        /* The first salary is the starting highest and lowest. */
        if (i == 0)
        {
            highest = gross;
            lowest = gross;
        }
        if (gross > highest)
        {
            highest = gross;
        }
        if (gross < lowest)
        {
            lowest = gross;
        }
    }

    printf("Total Employees: %d\n", count);
    printf("Total Payroll  : N$%.2f\n", total);
    printf("Average Salary : N$%.2f\n", total / count);
    printf("Highest Salary : N$%.2f\n", highest);
    printf("Lowest Salary  : N$%.2f\n", lowest);
}
