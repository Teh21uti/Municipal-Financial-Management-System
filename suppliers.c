#include <stdio.h>
#include "suppliers.h"
#include <string.h>
#define MAX_SUPPLIERS 100
char suppliersID[MAX_SUPPLIERS][20];
char suppliersName[MAX_SUPPLIERS][100];
char suppliersEmail[MAX_SUPPLIERS][100];
char suppliersPhone[MAX_SUPPLIERS][30];
char suppliersTowns[MAX_SUPPLIERS][50];
int suppliersCount = 0;

void addSupplier(void)
{
 printf("Adding supplier...\n");
 char id[20];
 char name[100];
 char email[100];
 char phone[30];
 char town[50];

 printf("Enter supplier ID: ");
   fgets(id, sizeof(id), stdin);
     id[strcspn(id, "\n")] = '\0';

      if(strlen(id) == 0) {
         printf("Invalid, ID cannot be empty.\n");
           return;
 }
             printf("You entered ID: %s\n", id);


         printf("Enter Supplier Name: ");
       fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

      if(strlen(name) == 0) {
           printf("Name cannot be empty.\n");
             return;
 }
           printf("You entered Name: %s\n", name);

   printf("Enter Supplier Email: ");
      fgets(email, sizeof(email), stdin);
          email[strcspn(email, "\n")] = '\0';

   if(strlen(email) == 0) {
      printf("Email cannot be empty.\n");
            return;
   }
          printf("You entered Email: %s\n", email);

   printf("Enter Supplier Phone: ");
      fgets(phone, sizeof(phone), stdin);
          phone[strcspn(phone, "\n")] = '\0';

   if(strlen(phone) == 0) {
      printf("Phone cannot be empty.\n");
            return;
   }
          printf("You entered Phone: %s\n", phone);

   printf("Enter Supplier Town: ");
      fgets(town, sizeof(town), stdin);
          town[strcspn(town, "\n")] = '\0';

   if(strlen(town) == 0) {
      printf("Town cannot be empty.\n");
            return;
   }
          printf("You entered Town: %s\n", town);
}

void listSuppliers(void)
{
 printf("Listing suppliers...\n");
}

void searchSupplier(void)
{
 printf("Searching supplier...\n");
}