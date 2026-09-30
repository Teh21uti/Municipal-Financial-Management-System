#include <stdio.h>
#include "suppliers.h"
#include <string.h>
#define MAX_SUPPLIERS 100
int suppliersID[MAX_SUPPLIERS];
char suppliersName[MAX_SUPPLIERS][100];
char suppliersEmail[MAX_SUPPLIERS][100];
char suppliersPhone[MAX_SUPPLIERS][30];
char suppliersTowns[MAX_SUPPLIERS][50];
int suppliersCount = 0;

void addSupplier(void)
{
 printf("Adding supplier...\n");
 int id=0;
 printf("Enter supplier ID: ");
 scanf("%d", &id);

 if(id <= 0) {
    printf("Invalid ID, must be a positive number.\n");
    return;
 }
 printf("You entered ID: %d\n", id);
}

void listSuppliers(void)
{
 printf("Listing suppliers...\n");
}

void searchSupplier(void)
{
 printf("Searching supplier...\n");
}