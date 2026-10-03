/* employees.h - list of the functions in employees.c

   The employee data is stored in arrays

       char  ids[100][10];
       char  names[100][50];
       char  departments[100][30];
       float basic[100];
       float housing[100];
       float transport[100];
       int   employeeCount = 0;
*/

/* The employee menu. Returns the new number of employees. */
int employeeMenu(char ids[][10], char names[][50], char departments[][30],
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

/* Employee report: total, average, highest and lowest salary. */
void displayEmployeeReport(float basic[], float housing[], float transport[], int count);
