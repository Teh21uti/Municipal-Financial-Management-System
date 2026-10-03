#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assets.h"

static Asset assetList[MAX_ASSETS];
static int assetCount = 0;

static void clean_input(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

static void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void initAssets(void) {
    assetCount = 0;
}

void addAsset(void) {
    if (assetCount >= MAX_ASSETS) {
        printf("Error: Max asset capacity reached.\n");
        return;
    }

    Asset a;

    printf("\n--- Add New Asset ---\n");
    
    printf("Enter Asset ID: ");
    while (scanf("%d", &a.assetID) != 1 || a.assetID <= 0) {
        printf("Invalid ID. Enter a positive number: ");
        clear_buffer();
    }
    clear_buffer();

    for (int i = 0; i < assetCount; i++) {
        if (assetList[i].assetID == a.assetID) {
            printf("Error: Asset ID %d already exists.\n", a.assetID);
            return;
        }
    }

    printf("Enter Asset Name: ");
    fgets(a.name, STR_LEN, stdin);
    clean_input(a.name);

    printf("Enter Asset Type: ");
    fgets(a.type, STR_LEN, stdin);
    clean_input(a.type);

    printf("Enter Department: ");
    fgets(a.department, STR_LEN, stdin);
    clean_input(a.department);

    printf("Enter Condition: ");
    fgets(a.condition, STR_LEN, stdin);
    clean_input(a.condition);

    printf("Enter Purchase Value (N$): ");
    while (scanf("%lf", &a.purchaseValue) != 1 || a.purchaseValue < 0) {
        printf("Invalid amount. Enter a valid purchase value: ");
        clear_buffer();
    }
    clear_buffer();

    assetList[assetCount] = a;
    assetCount++;

    printf("Asset '%s' added successfully.\n", a.name);
}

void displayAssets(void) {
    if (assetCount == 0) {
        printf("\nNo assets found in system.\n");
        return;
    }

    printf("\n%-8s %-20s %-15s %-15s %-15s %-12s\n", 
           "ID", "Name", "Type", "Department", "Condition", "Value (N$)");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < assetCount; i++) {
        printf("%-8d %-20s %-15s %-15s %-15s N$%-10.2f\n",
               assetList[i].assetID,
               assetList[i].name,
               assetList[i].type,
               assetList[i].department,
               assetList[i].condition,
               assetList[i].purchaseValue);
    }
    printf("-----------------------------------------------------------------------------------\n");
    printf("Total Assets: %d | Total Value: N$%.2f\n", assetCount, getTotalAssetValue());
}

void searchAsset(void) {
    if (assetCount == 0) {
        printf("\nNo assets to search.\n");
        return;
    }

    int option;
    printf("\n--- Search Options ---\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("Select: ");
    
    if (scanf("%d", &option) != 1) {
        clear_buffer();
        printf("Invalid selection.\n");
        return;
    }
    clear_buffer();

    if (option == 1) {
        int searchID;
        printf("Enter ID: ");
        if (scanf("%d", &searchID) != 1) {
            clear_buffer();
            printf("Invalid input.\n");
            return;
        }
        clear_buffer();

        for (int i = 0; i < assetCount; i++) {
            if (assetList[i].assetID == searchID) {
                printf("\nAsset Found:\n");
                printf("ID: %d\nName: %s\nType: %s\nDept: %s\nCondition: %s\nValue: N$%.2f\n",
                       assetList[i].assetID, assetList[i].name, assetList[i].type,
                       assetList[i].department, assetList[i].condition, assetList[i].purchaseValue);
                return;
            }
        }
        printf("No asset found with ID %d.\n", searchID);
    } 
    else if (option == 2) {
        char term[STR_LEN];
        printf("Enter search term: ");
        fgets(term, STR_LEN, stdin);
        clean_input(term);

        int found = 0;
        for (int i = 0; i < assetCount; i++) {
            if (strstr(assetList[i].name, term) != NULL) {
                if (!found) {
                    printf("\n%-8s %-20s %-15s %-15s %-12s\n", "ID", "Name", "Type", "Dept", "Value");
                    printf("-------------------------------------------------------------------\n");
                }
                printf("%-8d %-20s %-15s %-15s N$%-10.2f\n",
                       assetList[i].assetID, assetList[i].name, assetList[i].type, 
                       assetList[i].department, assetList[i].purchaseValue);
                found = 1;
            }
        }
        if (!found) {
            printf("No assets matched '%s'.\n", term);
        }
    } 
    else {
        printf("Invalid option.\n");
    }
}

void updateAssetCondition(void) {
    if (assetCount == 0) {
        printf("\nNo assets available.\n");
        return;
    }

    int id;
    printf("\nEnter Asset ID to update: ");
    if (scanf("%d", &id) != 1) {
        clear_buffer();
        printf("Invalid input.\n");
        return;
    }
    clear_buffer();

    for (int i = 0; i < assetCount; i++) {
        if (assetList[i].assetID == id) {
            printf("Current Condition: %s\n", assetList[i].condition);
            printf("Enter New Condition: ");
            fgets(assetList[i].condition, STR_LEN, stdin);
            clean_input(assetList[i].condition);
            printf("Condition updated.\n");
            return;
        }
    }
    printf("Asset ID %d not found.\n", id);
}

int getAssetCount(void) {
    return assetCount;
}

double getTotalAssetValue(void) {
    double total = 0.0;
    for (int i = 0; i < assetCount; i++) {
        total += assetList[i].purchaseValue;
    }
    return total;
}

void saveAssetsToFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < assetCount; i++) {
        fprintf(fp, "%d;%s;%s;%.2f;%s;%s\n",
                assetList[i].assetID,
                assetList[i].name,
                assetList[i].type,
                assetList[i].purchaseValue,
                assetList[i].department,
                assetList[i].condition);
    }

    fclose(fp);
    printf("Data saved to %s.\n", filename);
}

void loadAssetsFromFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    assetCount = 0;
    char line[256];
    while (assetCount < MAX_ASSETS && fgets(line, sizeof(line), fp)) {
        Asset a;
        if (sscanf(line, "%d;%49[^;];%49[^;];%lf;%49[^;];%49[^\n]",
                   &a.assetID, a.name, a.type, &a.purchaseValue,
                   a.department, a.condition) == 6) {
            assetList[assetCount++] = a;
        }
    }

    fclose(fp);
}

void assetMenu(void) {
    int choice = 0;
    loadAssetsFromFile("assets.txt");

    do {
        printf("\n--- Asset Management ---\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset\n");
        printf("4. Update Asset Condition\n");
        printf("5. Save Records\n");
        printf("6. Exit Submenu\n");
        printf("Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            clear_buffer();
            choice = 0;
        } else {
            clear_buffer();
        }

        switch (choice) {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: searchAsset(); break;
            case 4: updateAssetCondition(); break;
            case 5: saveAssetsToFile("assets.txt"); break;
            case 6:
                saveAssetsToFile("assets.txt");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);
}