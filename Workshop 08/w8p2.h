/*
*****************************************************************************
                          Workshop - #8 (P2)
Full Name  : Vishwam Shailesh Kapadia
Student ID#: 154933212
Email      : vkapadia3@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/


// ----------------------------------------------------------------------------
// defines/macros
#define MAXPRODUCTS 3
#define SERVING 64
#define CONVERSION 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int skuNumber;
    double price;
    int calorie;
    double weight;
};

struct ReportData
{
    int repSkuNumber;
    double repPrice;
    int repCalorie;
    double pounds;
    double kilograms;
    int grams;
    double totalServings;
    double costPerServing;
    double costCalories;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* value);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* floatPositiveValue);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int nProducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productnumber);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int SKU, const double* productprice, const int cal, const double* productweight);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* equivalentKg);

// 9. convert lbs: g
int convertLbsG(const double* lbs, int* equivalentG);

// 10. convert lbs: kg / g
void convertLbs(const double* lbs, double* equivalentKg, int* equivalentG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servG, const int totalgrams, double* nServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* nServings, double* costPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCalories, double* costPerCalorie);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo itemInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rowDisplay, const int checkProduct);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo productData);


// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);

