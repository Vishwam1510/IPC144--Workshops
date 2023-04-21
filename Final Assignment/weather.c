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
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "weather" where the function prototypes are declared
#include "weather.h"

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("< Press [ENTER] key to continue >");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void)
{
    char newLine = 'x';
    int value;

    do
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    } while (newLine != '\n');

    return value;
}

int inputIntRange(int lower, int upper)
{
    int value2 = lower - 1;
    do
    {
        value2 = inputInt();
        if (value2<lower || value2>upper)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
        }
    } while (value2<lower || value2>upper);

    return value2;
}

void displayTableHeader(void)
{
    printf("Year Month Precip.Amt Unit Region Name \n"
           "---- ----- ---------- ---- ------ ---------------\n");
}

void displayWeatherRecord(struct WeatherRecord data)
{
    printf("%d    %02d %10.1lf %4c %6d %s\n", 
        data.date.year, 
        data.date.month,
        data.precipAmt,
        data.unit,
        data.location.regionCode,
        data.location.name);
}

void menuMain(struct WeatherRecord* data,int max)
{
    int choice;
    do
    {
        printf("=======================================================\n"
               "         Ontario Weather Analysis Service\n"
               "                  Year: 2021\n"
               "=======================================================\n");
        printf("1. View all data\n"
               "2. View by region (sorted DESCENDING by precip.)\n"
               "3. View by month (sorted ASCENDING by precip.)\n"
               "4. View by location name (sorted DESCENDING by precip.)\n"
               "-------------------------------------------------------\n"
               "0. Exit\n"
               "-------------------------------------------------------\n"
               "Selection: ");
        choice = inputIntRange(0, 4);
        putchar('\n');
        switch (choice)
        {
        case 1:
            viewalldata(data, max);
            break;
        case 2:
            viewbyregion(data, max);
            break;
        case 3:
            viewbymonth(data, max);
            break;
        case 4:
            viewbylocation(data,max);
            break;
        }
    } while (choice != 0);
}


int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max)
{
    int recs = 0;

    if (fp != NULL)
    {
        while (recs < max &&
                fscanf(fp, "%d,%d,%lf,%c,%d,%15[^\n]\n",
                &data[recs].date.year, &data[recs].date.month,
                &data[recs].precipAmt, &data[recs].unit,
                &data[recs].location.regionCode,
                data[recs].location.name) == 6)
        {
            recs++; 
        }
    }
    return recs;
}

void viewalldata(struct WeatherRecord* data,int max)
{
    int i,j,cnt=0;
    displayTableHeader();
    for (i = 0;i <max;i+=15)
    { 
        cnt = 0;
        if (cnt < max)
        {
            for (j = i;j < i+15;j++)
            {
                if (data[j].location.regionCode != 0)
                {
                    displayWeatherRecord(data[j]);
                    cnt++;
                }
            }
        }
        putchar('\n');
        if (cnt == 15)
        {
            suspend();
        }
    }
}

void viewbyregion(struct WeatherRecord* data, const int max)
{
    int i, j;
    const int reg = 4;
    double total = 0, east = 0, north = 0, west = 0, central = 0;
             
    for (j = 0;j < max;j++)
    {
        if (data[j].location.regionCode == 10)
        {
            if (data[j].unit == 'c')
            {
                west = west + (data[j].precipAmt * 10);
            }
            else
            {
                west = west + data[j].precipAmt;
            }
        }
        if (data[j].location.regionCode == 20)
        {
            if (data[j].unit == 'c')
            {
                north = north + (data[j].precipAmt * 10);
            }
            else
            {
                north = north + data[j].precipAmt;
            }
        }
        if (data[j].location.regionCode == 30)
        {
            if (data[j].unit == 'c')
            {
                east = east + (data[j].precipAmt * 10);
            }
            else
            {
                east = east + data[j].precipAmt;
            }
        }
        if (data[j].location.regionCode == 40)
        {
            if (data[j].unit == 'c')
            {
                central = central + (data[j].precipAmt * 10);
            }
            else
            {
                central = central + data[j].precipAmt;
            }
        }
    }
    
   
    total = west + north + east + central;

    double regcodetotal[4] = {west,north,east,central};

    int temp;

    for (i = 0; i < reg; i++)//sorting
    {
        for (j =i+1; j < reg; j++)
        {
            if (regcodetotal[i] < regcodetotal[j])
            {
                temp = regcodetotal[i];
                regcodetotal[i] = regcodetotal[j];
                regcodetotal[j] = temp;
            }
        }
        
    }

    printf("Region Name     Precip(mm)\n");
    printf("------ -------- ----------\n");
    for (i = 0;i < 4;i++)
    {
        if (regcodetotal[i] == west)
        {
            printf("    10 %s  %10.0lf\n", REGION10, regcodetotal[i]);
        }
        if (regcodetotal[i] == north)
        {
            printf("    20 %s %10.0lf\n", REGION20, regcodetotal[i]);
        }
        if (regcodetotal[i] == east)
        {
            printf("    30 %s  %10.0lf\n", REGION30, regcodetotal[i]);
        }
        if (regcodetotal[i] == central)
        {
            printf("    40 %s  %10.0lf\n", REGION40, regcodetotal[i]);
        }
    }
    printf("------ -------- ----------\n");
    printf("         Total: %10d\n", (int)total);
    printf("       Average: %10.2lf\n\n", (total / reg));
}



void viewbymonth(struct WeatherRecord* data, int max)
{
    int i, j,totalmonths=12;
    double monthpretotal[12] = { 0 };
    int month[12] = { 0 };
    double total = 0;
    double temp,temp2;
   
    for (i = 0;i < max; i++)
    {
        total = 0;
        for (j = 1;j <= totalmonths;j++)
        {
            if (data[i].date.month == j)
            {
                month[j - 1] = j;
                if (data[i].unit == 'c')
                {
                    monthpretotal[j - 1] = monthpretotal[j - 1] + (data[i].precipAmt*10);
                }
                else
                {
                    monthpretotal[j - 1] = monthpretotal[j - 1] + data[i].precipAmt;
                }
            }
        }
    }
    for (i = 0;i < totalmonths;i++)
    {
        for (j = i + 1;j < totalmonths;j++)
        {
            if (monthpretotal[i] > monthpretotal[j])
            {
                temp = monthpretotal[i];
                monthpretotal[i] = monthpretotal[j];
                monthpretotal[j] = temp;
                temp2 = month[i];
                month[i] = month[j];
                month[j] = temp2;
            }
        }
    }

    for (i = 0;i < totalmonths;i++)
    {
        total = total + monthpretotal[i];
    }

    printf("Month     Precip(mm)\n");
    printf("--------- ----------\n");

    for (i = 0;i < totalmonths;i++)
    {
        if (month[i] == 1)
        {
            printf("January   %10.0lf\n", monthpretotal[i]);
        }
        if (month[i] == 2)
        {
            printf("February  %10.0lf\n", monthpretotal[i]);
        }
        if (month[i] == 3)
        {
            printf("March     %10.0lf\n", monthpretotal[i]);
        }
        if (month[i] == 4)
        {
            printf("April     %10.0lf\n", monthpretotal[i]);
        }
        if (month[i] == 5)
        {
            printf("May       %10.0lf\n", monthpretotal[i]);
        }
        if (month[i] == 6)
        {
            printf("June      %10.0lf\n", monthpretotal[i]);
        }
        if (month[i] == 7)
        {
            printf("July      %10.0lf\n", monthpretotal[i]);
        }
        if (month[i] == 8)
        {
            printf("August    %10.0lf\n", monthpretotal[i]);
        }
        if (month[i] == 9)
        {
            printf("September %10.0lf\n", monthpretotal[i]);
        }
        if (month[i] == 10)
        {
            printf("October   %10.0lf\n", monthpretotal[i]);
        }
        if (month[i] == 11)
        {
            printf("November  %10.0lf\n", monthpretotal[i]);
        }
        if (month[i] == 12)
        {
            printf("December  %10.0lf\n", monthpretotal[i]);
        }
    }
    printf("--------- ----------\n");
    printf("   Total: %10d\n", (int)total);
    printf(" Average: %10.2lf\n\n", total / totalmonths);
}

void viewbylocation(struct WeatherRecord* data, const int max)
{
    int i, j, cnt = 0, size = 0;
    double total = 0;
    struct StoreLocation locations[96];
    struct StoreLocation temp = { {0} };

    for (i = 0;i < max;i++)
    {
        cnt = 0;
        for (j = 0;j <=size;j++)
        {
            
            if (cnt == 0)
            {
                if ((strcmp(data[i].location.name, locations[j].location)) == 0)
                {
                    cnt++;
                }
            }
            
        }
        if (cnt==0)
        {
            strcpy(locations[size].location,data[i].location.name);
            size++;
        }
    }
    for (i = 0;i < size; i++)
    {
        total = 0;
        for (j = 0;j < max;j++)
        {
            if (strcmp(data[j].location.name,locations[i].location)==0)
            {
                if (data[j].unit == 'c')
                {
                    locations[i].precipamt = locations[i].precipamt + (data[j].precipAmt*10);
                }
                else
                {
                    locations[i].precipamt = locations[i].precipamt + data[j].precipAmt;
                }
            }
        }
    }
    for (i = 0; i < size; i++)//sorting
    {
        for (j = i + 1; j < size; j++)
        {
            if (locations[i].precipamt < locations[j].precipamt)
            {
                temp = locations[i];
                locations[i] = locations[j];
                locations[j] = temp;
            }
        }

    }
    for (i = 0;i < size;i++)
    {
        total = total + locations[i].precipamt;
    }
    printf("Location        Precip(mm)\n");
    printf("--------------- ----------\n");
    for (i = 0;i < size;i++)
    {
        printf("%15s %10d\n", locations[i].location, (int)locations[i].precipamt);
    }
    printf("--------------- ----------\n");
    printf("         Total: %10d\n", (int)total);
    printf("       Average: %10.2lf\n\n", (total / size));
}
