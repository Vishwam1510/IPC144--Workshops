/*
*****************************************************************************
                          Workshop - #7 (P2)
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

#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70
#define MULTIPLE_FOR_PATH_LENGTH 5
#define MIN_LIVES 1
#define MAX_LIVES 10


struct PlayerInfo
{
    int lives;
    char playername;
    int treasuresfound;
    int history[MAX_PATH_LENGTH];
};

struct GameInfo
{
    int maxmoves;
    int pathlength;
    int bombs[MAX_PATH_LENGTH];
    int treasures[MAX_PATH_LENGTH];
};

int main(void)
{
    const char undiscovered = '-';
    const char bomb = '!';
    const char treasure = '$';
    const char bombtreasure = '&';
    const char nothing = '.';
    int flag;
    int calculation;
    int i, j, nextmove = -1, c = 0;
    struct PlayerInfo player = { 0 };
    struct GameInfo game = { 0 };

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.playername);

    do
    {
        flag = 0;
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives<1 || player.lives>MAX_LIVES)
        {
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
            flag = 1;
        }
    } while (flag == 1);
    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    do
    {
        flag = 0;
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathlength);
        if ((game.pathlength % MULTIPLE_FOR_PATH_LENGTH != 0) || (game.pathlength<MIN_PATH_LENGTH || game.pathlength>MAX_PATH_LENGTH))
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE_FOR_PATH_LENGTH, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
            flag = 1;
        }
    } while (flag == 1);

    calculation = ((double)0.75 * game.pathlength) * 100;
    if (calculation % 100 >= 50)
    {
        calculation += 50;
    }
    calculation = calculation / 100;


    do
    {
        flag = 0;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxmoves);
        if (game.maxmoves<player.lives || game.maxmoves>calculation)
        {
            printf("    Value must be between %d and %d\n", player.lives, calculation);
            flag = 1;
        }
    } while (flag == 1);

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE_FOR_PATH_LENGTH);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathlength);

    for (i = 0; i < game.pathlength / MULTIPLE_FOR_PATH_LENGTH; i++)
    {
        printf("   Positions [%2d-%2d]: ", (MULTIPLE_FOR_PATH_LENGTH * i) + 1, MULTIPLE_FOR_PATH_LENGTH * (i + 1));
        for (j = 0; j < MULTIPLE_FOR_PATH_LENGTH;j++)
        {
            scanf("%d", &game.bombs[j + (MULTIPLE_FOR_PATH_LENGTH * i)]);
        }
    }

    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE_FOR_PATH_LENGTH);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathlength);

    for (i = 0; i < game.pathlength / MULTIPLE_FOR_PATH_LENGTH; i++)
    {
        printf("   Positions [%2d-%2d]: ", (MULTIPLE_FOR_PATH_LENGTH * i) + 1, MULTIPLE_FOR_PATH_LENGTH * (i + 1));
        for (j = 0; j < MULTIPLE_FOR_PATH_LENGTH;j++)
        {
            scanf("%d", &game.treasures[j + (MULTIPLE_FOR_PATH_LENGTH * i)]);
        }
    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.playername);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathlength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathlength;i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathlength;i++)
    {
        printf("%d", game.treasures[i]);
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    do
    {
        if (nextmove > 0)
        {
            if (player.history[nextmove - 1] == 1)
            {
                printf("===============> Dope! You've been here before!\n");
            }
            else if (game.bombs[nextmove - 1] == 1 && game.treasures[nextmove - 1] == 1)
            {
                player.history[nextmove - 1] = 1;
                player.lives--;
                game.maxmoves--;
                player.treasuresfound++;
                printf("===============> [%c] !!! BOOOOOM !!! [%c]\n", bombtreasure, bombtreasure);
                printf("===============> [%c] $$$ Life Insurance Payout!!! [%c]\n", bombtreasure, bombtreasure);
            }
            else if (game.bombs[nextmove - 1] == 1)
            {
                player.history[nextmove - 1] = 1;
                player.lives--;
                game.maxmoves--;
                printf("===============> [%c] !!! BOOOOOM !!! [%c]\n", bomb, bomb);
            }
            else if (game.treasures[nextmove - 1] == 1)
            {
                player.history[nextmove - 1] = 1;
                player.treasuresfound++;
                game.maxmoves--;
                printf("===============> [%c] $$$ Found Treasure! $$$ [%c]\n", treasure, treasure);
            }
            else
            {
                player.history[nextmove - 1] = 1;
                game.maxmoves--;
                printf("===============> [%c] ...Nothing found here... [%c]\n", nothing, nothing);
            }
        }

        if (game.maxmoves == 0)
        {
            printf("\nNo more MOVES remaining!\n");
        }
        if (player.lives == 0)
        {
            printf("\nNo more LIVES remaining!\n");
        }

        if (nextmove > 0)
        {
            printf("\n  ");
            for (i = 0;i < nextmove;i++)
            {
                if (i == nextmove - 1)
                {
                    printf("%c", player.playername);
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n  ");

        for (i = 0;i < game.pathlength;i++)
        {
            if (player.history[i] == 0)
            {
                printf("%c", undiscovered);
            }
            if (player.history[i] == 1)
            {
                if (game.bombs[i] == 1 && game.treasures[i] == 1)
                {
                    printf("%c", bombtreasure);
                }
                else if (game.bombs[i] == 1 && game.treasures[i] == 0)
                {
                    printf("%c", bomb);
                }
                else if (game.treasures[i] == 1 && game.bombs[i] == 0)
                {
                    printf("%c", treasure);
                }
                else
                {
                    printf("%c", nothing);
                }
            }
        }

        printf("\n  ");

        for (i = 0;i < game.pathlength;i++)
        {
            if ((i + 1) % 10 == 0)
            {
                printf("%d", ++c);
            }
            else
            {
                printf("|");
            }
        }


        c = 0;
        printf("\n  ");

        for (i = 0;i < game.pathlength;i++)
        {
            if ((i + 1) % 10 == 0)
            {
                printf("0");
                c = 0;
            }
            else
            {
                printf("%d", ++c);
            }
        }
        c = 0;
        

        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasuresfound, game.maxmoves);
        printf("+---------------------------------------------------+\n");

        if (player.lives > 0 && game.maxmoves > 0)
        {
            do
            {
                flag = 0;
                printf("Next Move [1-%d]: ", game.pathlength);
                scanf("%d", &nextmove);
                if (nextmove<1 || nextmove> game.pathlength)
                {
                    printf("  Out of Range!!!\n");
                    flag = 1;
                }
            } while (flag == 1);
            printf("\n");
        }
    } while (player.lives > 0 && game.maxmoves > 0);

    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");

    printf("You should play again and try to beat your score!\n");


    return 0;
}
