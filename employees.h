

/* ---- Functions for main.c and reports.c ---- */


void employeeMenu(void);
void employeeReport(void);


int employeeMenuRun(char ids[][10], char names[][50], char departments[][30],
                    float basic[], float housing[], float transport[], int count);

/* Adds one employee. Returns the new number of employees. */
int addEmployee(char ids[][10], char names[][50], char departments[][30],
                float basic[], float housing[], float transport[], int count);

void displayEmployees(char ids[][10], char names[][50], char departments[][30],
                      float basic[], float housing[], float transport[], int count);

/* Asks for an ID and shows that employee. */
void findEmployee(char ids[][10], char names[][50], char departments[][30],
                  float basic[], float housing[], float transport[], int count);

/* Asks for an ID and shows that employee's salary. */
void displaySalaryInfo(char ids[][10], char names[][50],
                       float basic[], float housing[], float transport[], int count);

/* Returns the position of the employee in the arrays, or -1 if not found. */
int searchEmployee(char id[], char ids[][10], int size);

/* Gross salary = basic + housing + transport */
float calculateSalary(float basic, float housing, float transport);

/* Employee report on the arrays it is given. */
void displayEmployeeReport(float basic[], float housing[], float transport[], int count);
