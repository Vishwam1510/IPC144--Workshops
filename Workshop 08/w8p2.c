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

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* value)
{

	int n;
	do
	{
		scanf("%d", &n);
		if (n <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (n <= 0);
	if (value != NULL)
	{
		*value = n;
	}
	return n;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* floatPositiveValue)
{
	double n;
	do
	{
		scanf("%lf", &n);
		if (n <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (n <= 0);
	if (floatPositiveValue != NULL)
	{
		*floatPositiveValue = n;
	}
	return n;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int nProducts)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", nProducts);
	printf("NOTE: A 'serving' is %dg\n\n", SERVING);

}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productnumber)
{
	struct CatFoodInfo catfood = { 0 };
	printf("Cat Food Product #%d\n", productnumber+1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&catfood.skuNumber);

	printf("PRICE         : $");
	getDoublePositive(&catfood.price);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&catfood.weight);

	printf("CALORIES/SERV.: ");
	getIntPositive(&catfood.calorie);

	printf("\n");

	return catfood;

}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int SKU, const double* productprice, const int cal, const double* productweight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", SKU, *productprice, *productweight, cal);
	
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* equivalentKg)
{
	double i;
	i = *lbs / CONVERSION;
	if (equivalentKg != NULL)
	{
		*equivalentKg = i;
	}
	return (i);
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* equivalentG)
{
	int j;
	j = convertLbsKg(lbs, 0) * 1000;
	if (equivalentG != NULL)
	{
		*equivalentG = j;
	}
	return(j);
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* equivalentKg, int* equivalentG)
{
	convertLbsKg(lbs, equivalentKg);
	convertLbsG(lbs, equivalentG);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servG, const int equivalentG, double* nServings)
{
	double i;
	i = (double)equivalentG / (double)servG;
	if (nServings != NULL)
	{
		*nServings = i;
	}
	return(i);

}
// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* nServings, double* costPerServing)
{
	double cost = 0;
	cost = *productPrice / *nServings;
	if (costPerServing != NULL)
	{
		*costPerServing = cost;
	}
	return(cost);
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCalories, double* costPerCalorie)
{
	double cost = 0;
	cost = *productPrice / *totalCalories;
	if (costPerCalorie != NULL)
	{
		*costPerCalorie = cost;
	}
	return(cost);
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo itemInfo)
{
	struct ReportData reportInfo;
	double cal;

	reportInfo.repSkuNumber = itemInfo.skuNumber;
	reportInfo.repPrice = itemInfo.price;
	reportInfo.pounds = itemInfo.weight;
	reportInfo.repCalorie = itemInfo.calorie;
	convertLbsKg(&reportInfo.pounds, &reportInfo.kilograms);
	convertLbsG(&reportInfo.pounds, &reportInfo.grams);
	calculateServings(SERVING, reportInfo.grams, &reportInfo.totalServings);
	cal = reportInfo.repCalorie	 * reportInfo.totalServings;
    calculateCostPerServing(&reportInfo.repPrice, &reportInfo.totalServings, &reportInfo.costPerServing);
	calculateCostPerCal(&reportInfo.repPrice, &cal, &reportInfo.costCalories);

	return(reportInfo);
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\n");
	printf("Analysis Report (Note: Serving = %dg)\n", SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportInfo, const int checkProduct)
{
	 printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", reportInfo.repSkuNumber, reportInfo.repPrice, reportInfo.pounds, reportInfo.kilograms,
        reportInfo.grams, reportInfo.repCalorie, reportInfo.totalServings, reportInfo.costPerServing, reportInfo.costCalories);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo productData)
{
	printf("\n");
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", productData.skuNumber, productData.price);
	printf("Happy shopping!\n");

}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catFoodDetail[MAXPRODUCTS];
	{
		int i = 0, cheaperProduct = 0;
		openingMessage(MAXPRODUCTS);
		for (i = 0; i < MAXPRODUCTS; i++)
		{
			catFoodDetail[i] = getCatFoodInfo(i);
		}

		displayCatFoodHeader();
		for (i = 0; i < MAXPRODUCTS; i++)
		{
			displayCatFoodData(catFoodDetail[i].skuNumber, &catFoodDetail[i].price, catFoodDetail[i].calorie, &catFoodDetail[i].weight);
		}

		struct ReportData reportArray[MAXPRODUCTS];
		displayReportHeader();
		for (i = 0; i < MAXPRODUCTS; i++)
		{
			reportArray[i] = calculateReportData(catFoodDetail[i]);
			if (reportArray[i].costPerServing < reportArray[i - 1].costPerServing)
			{
				cheaperProduct = i;
			}
		}
		int j;
		for (j = 0; j < MAXPRODUCTS; j++)
		{
			struct ReportData x = { 0 };
			x = reportArray[j];
			displayReportData(x, cheaperProduct);
			if (cheaperProduct == j)
			{
				printf(" ***");
			}
			printf("\n");

		}
		displayFinalAnalysis(catFoodDetail[cheaperProduct]);
	};
}
