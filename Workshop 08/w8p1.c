/*
*****************************************************************************
                          Workshop - #8 (P1)
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

// User Libraries
#include "w8p1.h"

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
	printf("Enter the details for %d dry food bags of product data for analysis.\n", MAXPRODUCTS);
	printf("NOTE: A 'serving' is %dg\n\n", SERVING);
	
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productnumber)
{
	struct CatFoodInfo catfood = { 0 };
	printf("Cat Food Product #%d\n", productnumber	);
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
void displayCatFoodData(const int SKU, const double* productprice, const int cal,const double* productweight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", SKU, *productprice, *productweight, cal);
}


// 7. Logic entry point
void start(void)
{
	int i;
	struct CatFoodInfo foodinformation[MAXPRODUCTS] = { { 0 } };
	openingMessage(MAXPRODUCTS);
	for (i = 0;i < MAXPRODUCTS;i++)
	{
		foodinformation[i] = getCatFoodInfo(i + 1);
	}
	displayCatFoodHeader();
	for (i = 0;i < MAXPRODUCTS;i++)
	{
		displayCatFoodData(foodinformation[i].skuNumber, &foodinformation[i].price, foodinformation[i].calorie, &foodinformation[i].weight);
	}
}