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
 printf("Enter supplier ID: ");
 fgets(id, sizeof(id), stdin);
 id[strcspn(id, "\n")] = '\0';

 if(strlen(id) == 0) {
    printf("Invalid, ID cannot be empty.\n");
    return;
 }
 printf("You entered ID: %s\n", id);
}

void listSuppliers(void)
{
 printf("Listing suppliers...\n");
}

void searchSupplier(void)
{
 printf("Searching supplier...\n");
}