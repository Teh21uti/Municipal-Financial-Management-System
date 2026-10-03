/* employees.h
   This file lists the functions in employees.c.
   Other files include it so they know these functions exist. */

/* Functions used by main.c and reports.c */
void employeeMenu(void);
void employeeReport(void);

/* Functions used inside employees.c */
int employeeMenuRun(char ids[][10], char names[][50], char departments[][30],
                    float basic[], float housing[], float transport[], int count);

int addEmployee(char ids[][10], char names[][50], char departments[][30],
                float basic[], float housing[], float transport[], int count);

void displayEmployees(char ids[][10], char names[][50], char departments[][30],
                      float basic[], float housing[], float transport[], int count);

void findEmployee(char ids[][10], char names[][50], char departments[][30],
                  float basic[], float housing[], float transport[], int count);

void displaySalaryInfo(char ids[][10], char names[][50],
                       float basic[], float housing[], float transport[], int count);

int searchEmployee(char id[], char ids[][10], int size);

float calculateSalary(float basic, float housing, float transport);

void displayEmployeeReport(float basic[], float housing[], float transport[], int count);
