/*
*****************************************************************************
                          Workshop - #2 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char c1t1,c1g1,c1cr1,c2t2,c2g2,c2cr2, c3t3, c3g3, c3cr3, cs, cwc, mkr;
    int bw1, bw2, bw3, ds;
    double c1temp1, c2temp2, c3temp3;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &c1t1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &c1g1);
    printf("Bag weight (g): ");
    scanf(" %d", &bw1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c1cr1);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &c1temp1);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &c2t2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &c2g2);
    printf("Bag weight (g): ");
    scanf(" %d", &bw2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c2cr2);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &c2temp2);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &c3t3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &c3g3);
    printf("Bag weight (g): ");
    scanf(" %d", &bw3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &c3cr3);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &c3temp3);

    printf("\n---+---------------+---------------+---------------+-------+--------------\n");
    printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
    printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
    printf("   +---------------+---------------+---------------+ With  +--------------\n");
    printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
    printf("---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  |  %d |  %0.3lf |   %d   |  %0.1lf | %0.1lf\n",
        (c1t1=='l'||c1t1=='L'),(c1t1=='b'||c1t1=='B'),
        (c1g1=='c'||c1g1=='C'), (c1g1 == 'f' || c1g1 == 'F'),
        bw1, (bw1/GRAMS_IN_LBS), (c1cr1=='y'||c1cr1=='Y'),
        c1temp1, ((c1temp1*1.8)+32));
    printf(" 2 |   %d   |   %d   |    %d   |   %d  |  %d |  %0.3lf |   %d   |  %0.1lf | %0.1lf\n",
        (c2t2 == 'l' || c2t2 == 'L'), (c2t2 == 'b' || c2t2 == 'B'),
        (c2g2 == 'c' || c2g2 == 'C'), (c2g2 == 'f' || c2g2 == 'F'),
        bw2, (bw2 / GRAMS_IN_LBS), (c2cr2 == 'y' || c2cr2 == 'Y'),
        c2temp2, ((c2temp2 * 1.8) + 32));
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %d |  %0.3lf |   %d   |  %0.1lf | %0.1lf\n\n",
        (c3t3 == 'l' || c3t3 == 'L'), (c3t3 == 'b' || c3t3 == 'B'),
        (c3g3 == 'c' || c3g3 == 'C'), (c3g3 == 'f' || c3g3 == 'F'),
        bw3, (bw3 / GRAMS_IN_LBS), (c3cr3 == 'y' || c3cr3 == 'Y'),
        c3temp3, ((c3temp3 * 1.8) + 32));

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
    
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &cs);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cwc);
    printf("Typical number of daily servings: ");
    scanf(" %d", &ds);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &mkr);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");
   
    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",
        (cs == 'm' || cs == 'M') && (c1t1 == 'l' || c1t1 == 'L'),
        (mkr == 'c' || mkr == 'C') && (c1g1 == 'f' || c1g1 == 'F'),
        (ds>=1&&ds<=4) && (bw1<250),
        (cwc == 'y' || cwc == 'Y') && (c1cr1 == 'y' || c1cr1 == 'Y'),
        (mkr == 'r' || mkr == 'R')&&(c1temp1>60.0 && c1temp1<=69.9));
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n",
        (cs == 'm' || cs == 'M') && (c2t2 == 'l' || c2t2 == 'L'),
        (mkr == 'c' || mkr == 'C') && (c2g2 == 'f' || c2g2 == 'F'),
        (ds >= 1 && ds <= 9) && (bw2 <= 500),
        (cwc == 'y' || cwc == 'Y') && (c2cr2 == 'y' || c2cr2 == 'Y'),
        (mkr == 'c' || mkr == 'C') && (c2temp2>=70.0));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n",
        (cs == 'm' || cs == 'M') && (c3t3 == 'l' || c3t3 == 'L'),
        (mkr == 'c' || mkr == 'C') && (c3g3 == 'f' || c3g3 == 'F'),
        (ds>=10) && (bw3 <= 1000),
        (cwc == 'y' || cwc == 'Y') && (c3cr3 == 'y' || c3cr3 == 'Y'),
        (mkr == 'c' || mkr == 'C') && (c3temp3 >= 70.0));

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");

    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &cs);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cwc);
    printf("Typical number of daily servings: ");
    scanf(" %d", &ds);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &mkr);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",
        (cs == 'm' || cs == 'M') && (c1t1 == 'l' || c1t1 == 'L'),
        (mkr == 'r' || mkr == 'R') && (c1g1 == 'c' || c1g1 == 'C'),
        (ds >= 1 && ds <= 4) && (bw1 < 250),
        (cwc == 'y' || cwc == 'Y') && (c1cr1 == 'y' || c1cr1 == 'Y'),
        (mkr == 'r' || mkr == 'R') && (c1temp1 > 60.0 && c1temp1 <= 69.9));
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n",
        (cs == 'r' || cs == 'R') && (c2t2 == 'b' || c2t2 == 'B'),
        (mkr == 'c' || mkr == 'C') && (c2g2 == 'f' || c2g2 == 'F'),
        (ds >= 1 && ds <= 9) && (bw2 <= 500),
        (cwc == 'n' || cwc == 'N') && (c2cr2 == 'n' || c2cr2 == 'N'),
        (mkr == 'c' || mkr == 'C') && (c2temp2 >= 70.0));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n",
        (cs == 'm' || cs == 'M') && (c3t3 == 'l' || c3t3 == 'L'),
        (mkr == 'c' || mkr == 'C') && (c3g3 == 'f' || c3g3 == 'F'),
        (ds >= 10) && (bw3 <= 1000),
        (cwc == 'n' || cwc == 'N') && (c3cr3 == 'n' || c3cr3 == 'N'),
        (mkr == 'c' || mkr == 'C') && (c3temp3 >= 70.0));

    printf("Hope you found a product that suits your likes!\n");







    return 0;
}
