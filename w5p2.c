/*
    ==================================================
    Workshop #5 (Part-2):
    ==================================================
    Name   : Nasim Khodapanah
    ID     : 131929200
    Email  : nkhodapanah@myseneca.ca
    Section: NGG
*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_PATH_LEN 70
#define MIN_PATH_LEN 10
#define MIN_LIVES 1
#define MAX_LIVES 10
#define MULTIPLE 5
#define MAX_MOVE 15
#define MIN_MOVE 3

typedef struct {
    int numOfLive;
    char playerName;
    int numOfTreasure;
    int moves[MAX_PATH_LEN];

}playerInfo;

typedef struct {
    int maxNumOfMoves;
    int pathLength;
    int bombs[MAX_PATH_LEN];
    int treasures[MAX_PATH_LEN];
}gameInfo;


int main() {
    playerInfo player1 = { 0, '\0' , 0 , {0} };
    gameInfo game = { 0 , 0 , {0} , {0} };
    int history[MAX_PATH_LEN] = { 0 };
    int i, j, nextMove = 0, goOn = 1;
    printf("================================\n");
    printf("         Treasure Hunt!         \n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player1.playerName);
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player1.numOfLive);
        if (player1.numOfLive > MAX_LIVES || player1.numOfLive < MIN_LIVES)
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
    } while (player1.numOfLive <MIN_LIVES || player1.numOfLive > MAX_LIVES);
    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    while (game.pathLength < MIN_PATH_LEN || game.pathLength > MAX_PATH_LEN || game.pathLength % MULTIPLE != 0) {
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MIN_PATH_LEN, MAX_PATH_LEN);
        scanf("%d", &game.pathLength);
        if (game.pathLength > MAX_PATH_LEN || game.pathLength < MIN_PATH_LEN || game.pathLength % 5 != 0)
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_PATH_LEN, MAX_PATH_LEN);
    }

    while (game.maxNumOfMoves < MIN_MOVE || game.maxNumOfMoves > MAX_MOVE) {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxNumOfMoves);
        if (game.maxNumOfMoves < MIN_MOVE || game.maxNumOfMoves> MAX_MOVE) {
            printf("    Value must be between %d and %d\n", MIN_MOVE, MAX_MOVE);
        }
    }
    int multcount[MULTIPLE] = { 1 ,0 ,0 ,1 ,1 };
    printf("\nBOMB Placement\n");
    printf("--------------\n");

    printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example:");
    for ( i = 0; i < MULTIPLE; i++) {
        printf("%2d", multcount[i]);
    }
    printf(") NOTE: there are 20 to set!\n");
    for (i = 0; i < game.pathLength / MULTIPLE; i++) {
        printf("   Positions [%2d-%2d]: ", i * MULTIPLE + 1, i * MULTIPLE + 5);
        for (j = 0; j < MULTIPLE; j++)
            scanf("%d", &game.bombs[i * MULTIPLE + j]);
    }
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example:");
    for ( i = 0; i < MULTIPLE; i++) {
        printf("%2d", multcount[i]);
    }
    printf(") NOTE: there are 20 to set!\n");
    for (i = 0; i < game.pathLength / MULTIPLE; i++) {
        printf("   Positions [%2d-%2d]: ", i * MULTIPLE + 1, i * MULTIPLE + 5);
        for (j = 0; j < MULTIPLE; j++)
            scanf("%d", &game.treasures[i * MULTIPLE + j]);
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player1.playerName);
    printf("   Lives      : %d\n", player1.numOfLive);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++) {

        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.treasures[i]);
    }
    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    char secondLine[MAX_PATH_LEN] = "";
    printf("  ");
    for (i = 0; i < game.pathLength; i++) {
        secondLine[i] = '-';
        printf("-");
    }
    printf("\n");
    printf("  ");

    for (i = 1; i <= game.pathLength; i++) {
        if (i % 10 == 0)
            printf("%d", (i / 10));
        else
            printf("|");
    }
    printf("\n");
    printf("  ");

    for (i = 1; i <= game.pathLength; i++) {

        printf("%d", (i % 10));
    }
    printf("\n");

    printf("+---------------------------------------------------+\n");
    printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %d\n", player1.numOfLive, player1.numOfTreasure, game.maxNumOfMoves);
    printf("+---------------------------------------------------+\n");

    while (goOn) {
        do {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &nextMove);
            if (nextMove > game.pathLength || 1 > nextMove)
                printf("  Out of Range!!!\n");
        } while (nextMove > game.pathLength || 1 > nextMove);
        if (history[nextMove - 1] == 1) {
            printf("\n===============> Dope! You've been here before!\n\n");
            printf("  ");
            for (i = 1; i <= game.pathLength; i++) {
                if (i == nextMove) {
                    printf("%c", player1.playerName);
                }
                else printf(" ");
            }
            
            printf("\n");
            printf("  ");
            for (i = 1; i <= game.pathLength; i++) {
                printf("%c", secondLine[i - 1]);
            }
        }
        else {
            if (game.bombs[nextMove - 1] == 0 && game.treasures[nextMove - 1] == 0) {
                printf("\n===============> [.] ...Nothing found here... [.]\n\n");
            }
            if (game.bombs[nextMove - 1] == 1 && game.treasures[nextMove - 1] == 0) {
                printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
                if (player1.numOfLive == 1) { printf("No more LIVES remaining!\n\n"); }
            }
            if (game.bombs[nextMove - 1] == 0 && game.treasures[nextMove - 1] == 1) {
                printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            }
            if (game.bombs[nextMove - 1] == 1 && game.treasures[nextMove - 1] == 1) {
                printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                if (player1.numOfLive == 1) { printf("No more LIVES remaining!\n\n"); }
            }
            game.maxNumOfMoves--;
           history[nextMove - 1] = 1;
            
            printf("  ");
            for (i = 1; i <= game.pathLength; i++) {
                if (i == nextMove) {
                    printf("%c", player1.playerName);
                }
                else printf(" ");
            }
            if (game.bombs[nextMove - 1] == 0 && game.treasures[nextMove - 1] == 0) {
                printf("\n");
                printf("  ");
                for (i = 1; i <= game.pathLength; i++) {
                    if (i == nextMove) {
                        printf(".");
                        secondLine[nextMove - 1] = '.';
                    }
                    else printf("%c", secondLine[i - 1]);
                }
            }
            if (game.bombs[nextMove - 1] == 1 && game.treasures[nextMove - 1] == 0) {
                player1.numOfLive--;
                 
                printf("\n");
                printf("  ");
                for (i = 1; i <= game.pathLength; i++) {
                    if (i == nextMove) {
                        printf("!");
                        secondLine[nextMove - 1] = '!';
                    }
                    else printf("%c", secondLine[i - 1]);
                }
            }
            if (game.bombs[nextMove - 1] == 0 && game.treasures[nextMove - 1] == 1) {
                player1.numOfTreasure += 1;
                printf("\n");
                printf("  ");
                for (i = 1; i <= game.pathLength; i++) {
                    if (i == nextMove) {
                        printf("$");
                        secondLine[nextMove - 1] = '$';
                    }
                    else printf("%c", secondLine[i - 1]);
                }
            }
            if (game.bombs[nextMove - 1] == 1 && game.treasures[nextMove - 1] == 1) {
                player1.numOfLive--;
                player1.numOfTreasure += 1;
                printf("\n");
                printf("  ");
                for (i = 1; i <= game.pathLength; i++) {
                    if (i == nextMove) {
                        printf("&");
                        secondLine[nextMove - 1] = '&';
                    }
                    else printf("%c", secondLine[i - 1]);
                }
            }
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= game.pathLength; i++) {
            if (i % 10 == 0)
                printf("%d", (i / 10));
            else
                printf("|");
        }
       
        printf("\n");
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
            printf("%d", (i % 10));
       
        printf("\n+---------------------------------------------------+\n");
        printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining:  %d\n", player1.numOfLive, player1.numOfTreasure, game.maxNumOfMoves);
        printf("+---------------------------------------------------+\n");
        
        if (player1.numOfLive == 0) {
            printf("\n##################\n");
            printf("#   Game over!   #\n");
            printf("##################\n\n");
            printf("You should play again and try to beat your score!\n");
            goOn = 0;
        }
        
    }
    return 0;
}


