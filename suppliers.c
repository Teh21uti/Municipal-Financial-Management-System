#include <stdio.h>
#include "suppliers.h"
#include <string.h>
#define MAX_SUPPLIERS 100
//parallel arrays, they are parallel because the same row number is used to store the same supplier's info across the different arrays.
//2D arrays, These arrays are also 2D arrays because they store mutliple strings, the first part of the array represents the total number of suppliers, while the second part represents the maximum length of each string.
char suppliersID[MAX_SUPPLIERS][20];
char suppliersName[MAX_SUPPLIERS][100];
char suppliersEmail[MAX_SUPPLIERS][100];
char suppliersPhone[MAX_SUPPLIERS][30];
char suppliersTowns[MAX_SUPPLIERS][50];
int suppliersCount = 0;


//The following function is used to add a new supplier to the system. prompting the user for supplier details.
void addSupplier(void)
{
   if(suppliersCount >= MAX_SUPPLIERS) {
      printf("Cannot add more suppliers. Maximum limit reached.\n");
      return;
   }
 
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
      for(int i = 0; i < suppliersCount; i++) {
         if(strcmp(suppliersID[i], id) == 0) {
            printf("Supplier ID already exists. Please enter a unique ID.\n");
            return;
         }
      }
             


         printf("Enter Supplier Name: ");
       fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

      if(strlen(name) == 0) {
           printf("Name cannot be empty.\n");
             return;
 }
           

   printf("Enter Supplier Email: ");
      fgets(email, sizeof(email), stdin);
          email[strcspn(email, "\n")] = '\0';

   if(strlen(email) == 0) {
      printf("Email cannot be empty.\n");
            return;
   }
          

   printf("Enter Supplier Phone: ");
      fgets(phone, sizeof(phone), stdin);
          phone[strcspn(phone, "\n")] = '\0';

   if(strlen(phone) == 0) {
      printf("Phone cannot be empty.\n");
            return;
   }
          

   printf("Enter Supplier Town: ");
      fgets(town, sizeof(town), stdin);
          town[strcspn(town, "\n")] = '\0';

   if(strlen(town) == 0) {
      printf("Town cannot be empty.\n");
            return;
   }
         
          
          strcpy(suppliersID[suppliersCount], id);
          strcpy(suppliersName[suppliersCount], name);
          strcpy(suppliersEmail[suppliersCount], email);
          strcpy(suppliersPhone[suppliersCount], phone);
          strcpy(suppliersTowns[suppliersCount], town);

          suppliersCount++;

          printf("Supplier added successfully!\n");
}


//this following function is used to list ALL the suppliers within the system, then outputting their details.
void listSuppliers(void)
{
   
 

 if(suppliersCount == 0) {
   printf("No suppliers to list.\n");
 } else {
   for(int i = 0; i < suppliersCount; i++) {
      printf("Supplier %d:\n", i + 1);
      printf("ID: %s\n", suppliersID[i]);
      printf("Name: %s\n", suppliersName[i]);
      printf("Email: %s\n", suppliersEmail[i]);
      printf("Phone: %s\n", suppliersPhone[i]);
      printf("Town: %s\n", suppliersTowns[i]);
   }
}
  printf("Total suppliers: %d\n", suppliersCount);
 
 }


 //This function is used to search for a SPECIFIC supplier within the system, then outputting the supplier or not if its not in the system.
void searchSupplier(void)
{
   char searchName[100];
   int found = 0;
 

 printf("Enter supplier name to search: ");
 fgets(searchName, sizeof(searchName), stdin);
 searchName[strcspn(searchName, "\n")] = '\0';

 if(strlen(searchName) == 0) {
   printf("Search name cannot be empty.\n");
   return;

 }

 for(int i = 0; i < suppliersCount; i++) {
   if(strcmp(suppliersName[i], searchName) == 0) {
      printf("Supplier found:  \n");
      found = 1;
      printf("ID: %s\n", suppliersID[i]);
      printf("Name: %s\n", suppliersName[i]);
      printf("Email: %s\n", suppliersEmail[i]);
      printf("Phone: %s\n", suppliersPhone[i]);
      printf("Town: %s\n", suppliersTowns[i]);

   } 
    
 }
 if(found == 0) {
      printf("Supplier Not Found\n");

   }
}

//This function is used to display the supplier management menu, once it it clicked in the main MFMS menu.
void supplierMenu(void)
{
   char choice[10];
   
   do {
      printf("========Supplier Management Menu=======\n");
      printf("1. Add Supplier\n");
      printf("2. List Suppliers\n");
      printf("3. Search Supplier\n");
      printf("4. Exit, Back To Main Menu\n");
      printf("=======================================\n");
      printf("Enter your Choice: ");
      fgets(choice, sizeof(choice), stdin);
      choice[strcspn(choice, "\n")] = '\0';

      switch(choice[0]) {
      case '1':
         addSupplier();
         break;
         case '2':
         listSuppliers();
         break;
         case '3':
         searchSupplier();
         break;
         case '4':
         printf("Exiting Supplier Management Menu.\n");
         break;
         default:
         printf("Invalid choice. Please choose between 1 and 4.\n");
   }
   } while(strcmp(choice, "4") != 0);

   
}