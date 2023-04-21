/******************************************************************************
                           FINAL ASSESSMENT
1) Full Name  : Vishwam Shailesh Kapadia
   Student ID#: 154933212
   Email      : vkapadia3@myseneca.ca
   Section    : NAA

2) Full Name  : Harsh Achal Shah
   Student ID#: 151169216
   Email      : hshah78@myseneca.ca
   Section    : NAA

3) Full Name  : Raj Manish Barvaliya
   Student ID#: 149664211
   Email      : rbarvaliya@myseneca.ca
   Section    : NAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#include <stdio.h>

#include "weather.h"

#define MAX_RECORDS 250

int main(void)
{
	FILE *fp1 = fopen("weatherdata.txt", "r");

	struct WeatherRecord data[MAX_RECORDS];

	int records=importWeatherDataFile(fp1, data, MAX_RECORDS);

	menuMain(data,records);
 
	printf("Application Terminated!\n\n");

	return 0;
}