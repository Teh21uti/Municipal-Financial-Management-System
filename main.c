#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "employees.h"
#include "assets.h"
#include "budget.h"
#include "reports.h"

void DisplayMenu(void)
{
    printf("=========Municipal Financial Management System=========\n");
 printf("=======================================================\n");
 printf(" 1. Employee Management\n");
 printf(" 2. Budget Management\n");
 printf(" 3. Supplier Management\n");
 printf(" 4. Asset Management\n");
 printf(" 5. Reports\n");
 printf(" 6. Exit\n");
 printf("=======================================================\n");
 printf("\n");
 printf("Enter your choice: ");
}



int main(void)
{
 char choice[10];

 do {
    DisplayMenu();
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0';


    switch(choice[0]) {
        case '1':
            employeeMenu();
            break;
        case '2':
            budgetMenu();
       fgets(choice, sizeof(choice), stdin);  /* clears the Enter left by their scanf */
       break;
            case '3':
            supplierMenu();
            break;
            case '4':
            assetMenu();
            break;
            case '5':
            reportsMenu();
       fgets(choice, sizeof(choice), stdin);  /* clears the Enter left by their scanf */
       break;
            case '6':
            printf("MFMS compiled by NUST students, Tehuti Billawer, Henok Josef, Ashipala Richard, Anton Ngondo, Eva Niimbwele and Robert Gaingob, Thank you!\n");
            break;
            default:
            printf("Invalid choice. Please try again.\n");

    }    
 }  while(strcmp(choice, "6") != 0);
                
 
 return 0;
}
