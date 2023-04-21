/*
*****************************************************************************
                          Workshop - #3 (P1)
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
    const char patSize = 'S';
    double s_shirt, m_shirt, l_shirt;
    int nShirts;
    int subTotal, taxes;

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
    scanf("%d", &nShirts);

    s_shirt = s_shirt * nShirts;
    s_shirt += 0.005;
    subTotal = (double)s_shirt * 100;

    s_shirt = s_shirt * TAX;
    s_shirt += 0.005;
    taxes = (double)s_shirt * 100;

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", nShirts);
    printf("Sub-total: $%8.4lf\n", (double)subTotal / 100);
    printf("Taxes    : $%8.4lf\n", (double)taxes / 100);
    printf("Total    : $%8.4lf\n", (double)subTotal / 100 + (double)taxes / 100);

    return 0;
}