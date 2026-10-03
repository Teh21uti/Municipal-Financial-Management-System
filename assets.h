#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100
#define STR_LEN 50

typedef struct {
    int assetID;
    char name[STR_LEN];
    char type[STR_LEN];
    double purchaseValue;
    char department[STR_LEN];
    char condition[STR_LEN];
} Asset;

void initAssets(void);
void addAsset(void);
void displayAssets(void);
void searchAsset(void);
void updateAssetCondition(void);

int getAssetCount(void);
double getTotalAssetValue(void);

void saveAssetsToFile(const char *filename);
void loadAssetsFromFile(const char *filename);

void assetMenu(void);

#endif