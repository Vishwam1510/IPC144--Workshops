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
#ifndef WEATHER_H
#define WEATHER_H
#define MAX_RECORDS 250

#define NAME_LEN 16

#define REGION10 "Western"
#define REGION20 "Northern"
#define REGION30 "Eastern"
#define REGION40 "Central"

//////////////////////////////////////
// Structures
//////////////////////////////////////

struct Date
{
	int year;
	int month;
};
struct Location
{
	int regionCode;
	char name[NAME_LEN+1];
};
struct WeatherRecord
{
	struct Date date;
	double precipAmt;
	struct Location location;
	char unit;
};
struct StoreLocation
{
	char location[NAME_LEN+1];
	double precipamt;
};

void clearInputBuffer(void);

void suspend(void);

int inputIntRange(int lower, int upper);

void displayTableHeader(void);

void displayWeatherRecord(struct WeatherRecord data);

void menuMain(struct WeatherRecord* data,const int max);

void viewalldata(struct WeatherRecord* data,const int max);

void viewbyregion(struct WeatherRecord* data,const int max);

void viewbymonth(struct WeatherRecord* data,const int max);

void viewbylocation(struct WeatherRecord* data,const int max);

int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max);

#endif // !WEATHER_H 