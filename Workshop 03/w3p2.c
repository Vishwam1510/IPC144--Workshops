/*
*****************************************************************************
                          Workshop - #3 (P2)
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

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    
    double s_shirt, m_shirt, l_shirt;
    double priceSmall, priceMedium, priceLarge;
    double avg, avgTax, subTotal, totalTAX, total;
    double taxesSmall, taxesMedium, taxesLarge;
    
    int nShirtsPatty, nShirtsTommy, nShirtsSally;
    int centsSmall, centsMedium, centsLarge, centstaxSmall, centstaxMedium, centstaxLarge;
    int toonies, loonies, quarters, dimes, nickels, pennies;


    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &s_shirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &m_shirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &l_shirt);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%0.2lf\n", s_shirt);
    printf("MEDIUM : $%0.2lf\n", m_shirt);
    printf("LARGE  : $%0.2lf\n\n", l_shirt);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &nShirtsPatty);

    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &nShirtsTommy);

    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &nShirtsSally);

    priceSmall = nShirtsPatty * s_shirt;
    priceSmall += 0.005;
    centsSmall = priceSmall * 100;

    taxesSmall = TAX * nShirtsPatty * s_shirt;
    taxesSmall += 0.005;
    centstaxSmall = taxesSmall * 100;

    priceMedium = nShirtsSally * m_shirt;
    priceMedium += 0.005;
    centsMedium = priceMedium * 100;

    taxesMedium = TAX * nShirtsSally * m_shirt;
    taxesMedium += 0.005;
    centstaxMedium = taxesMedium * 100;

    priceLarge = nShirtsTommy * l_shirt;
    priceLarge += 0.005;
    centsLarge = priceLarge * 100;

    taxesLarge = TAX * nShirtsTommy * l_shirt;
    taxesLarge += 0.005;
    centstaxLarge = taxesLarge * 100;

    subTotal = (double)(centsSmall + centsMedium + centsLarge) / 100;
    totalTAX = (double)(centstaxSmall + centstaxMedium + centstaxLarge) / 100;
    total = ((double)(centsSmall + centstaxSmall) / 100) + ((double)(centsMedium + centstaxMedium) / 100) + ((double)(centsLarge + centstaxLarge) / 100);


    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
        patSize, s_shirt, nShirtsPatty, (double)centsSmall / 100, (double)centstaxSmall / 100, (double)(centsSmall + centstaxSmall) / 100);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
        salSize, m_shirt, nShirtsSally, (double)centsMedium / 100, (double)centstaxMedium / 100, (double)(centsMedium + centstaxMedium) / 100);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
        tomSize, l_shirt, nShirtsTommy, (double)centsLarge / 100, (double)centstaxLarge / 100, (double)(centsLarge + centstaxLarge) / 100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n",
        subTotal,totalTAX,total);


    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");

    avg = subTotal / (nShirtsPatty + nShirtsSally + nShirtsTommy);
    subTotal = subTotal * 100;

    avgTax = total / (nShirtsPatty + nShirtsSally + nShirtsTommy);
    total = total * 100;

    printf("%22.4lf\n", (double)subTotal / 100);

    toonies = (int)subTotal / 200;
    subTotal = (int)subTotal % 200;


    printf("Toonies  %3d %9.4lf\n", toonies, (double)subTotal / 100);

    loonies = (int)subTotal / 100;
    subTotal = (int)subTotal % 100;


    printf("Loonies  %3d %9.4lf\n", loonies, (double)subTotal / 100);

    quarters = (int)subTotal / 25;
    subTotal = (int)subTotal % 25;


    printf("Quarters %3d %9.4lf\n", quarters, (double)subTotal / 100);

    dimes = (int)subTotal / 10;
    subTotal = (int)subTotal % 10;

    printf("Dimes    %3d %9.4lf\n", dimes, (double)subTotal / 100);

    nickels = (int)subTotal / 5;
    subTotal = (int)subTotal % 5;

    printf("Nickels  %3d %9.4lf\n", nickels, (double)subTotal / 100);

    pennies = (int)subTotal / 1;
    subTotal = (int)subTotal % 1;

    printf("Pennies  %3d %9.4lf\n\n", pennies, (double)subTotal / 100);
    printf("Average cost/shirt: $%0.4lf\n\n", avg);
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (double)total / 100);

    toonies = (int)total / 200;
    total = (int)total % 200;

    printf("Toonies  %3d %9.4lf\n", toonies, (double)total / 100);

    loonies = (int)total / 100;
    total = (int)total % 100;

    printf("Loonies  %3d %9.4lf\n", loonies, (double)total / 100);

    quarters = (int)total / 25;
    total = (int)total % 25;

    printf("Quarters %3d %9.4lf\n", quarters, (double)total / 100);

    dimes = (int)total / 10;
    total = (int)total % 10;

    printf("Dimes    %3d %9.4lf\n", dimes, (double)total / 100);

    nickels = (int)total / 5;
    total = (int)total % 5;

    printf("Nickels  %3d %9.4lf\n", nickels, (double)total / 100);

    pennies = (int)total / 1;
    total = (int)total % 1;

    printf("Pennies  %3d %9.4lf\n\n", pennies, (double)total / 100);
    printf("Average cost/shirt: $%0.4lf\n", avgTax);

    return 0;
}













