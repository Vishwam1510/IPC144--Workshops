/*
*****************************************************************************
                          Workshop - #2 (P1)
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

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    int productid_1 = 111, productid_2 = 222, productid_3 = 111;
    double price1 = 111.49, price2 = 222.99, price3 = 334.49, avg;
    char taxed_1 = 'Y', taxed_2 = 'N', taxed_3 = 'N';
    avg = ((price1 + price2 + price3) / 3);
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", productid_1);
    printf("  Taxed: %c\n", taxed_1);
    printf("  Price: $%0.4lf\n\n", price1);
    
    printf("Product-2 (ID:%d)\n", productid_2);
    printf("  Taxed: %c\n", taxed_2);
    printf("  Price: $%0.4lf\n\n", price2);

    printf("Product-3 (ID:%d)\n", productid_3);
    printf("  Taxed: %c\n", taxed_3);
    printf("  Price: $%0.4lf\n\n", price3);

    printf("The average of all prices is: $%0.4lf\n\n", avg);
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");

    
    printf("1. Is product 1 taxable? -> %d\n\n", taxed_1=='Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", taxed_2 && taxed_3 == 'N');
    printf("3. Is product 3 less than testValue ($%0.2lf)? -> %d\n\n", testValue, price3 < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", price3 > price1 + price2);
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%0.2lf)\n\n", price1 >= price3 - price2, price3 - price2);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", price2 >= avg);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", productid_1 != productid_2 && productid_1 != productid_3);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", productid_2 != productid_1 && productid_2 != productid_3);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", productid_3 != productid_1 && productid_3 != productid_2);

    return 0;
}