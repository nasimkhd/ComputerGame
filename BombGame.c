/*
    ==================================================
    Workshop #5 (Part-1):
    ==================================================
    Name   : Nasim Khodapanah
    ID     : 131929200
    Email  : nkhodapanah@myseneca.ca
    Section: NGG
*/
#include <stdio.h>
#define MAX_PATH_LEN 70
#define MIN_PATH_LEN 10
#define MIN_LIVES 1
#define MAX_LIVES 10
#define MULTIPLE 5
#define MAX_MOVE 26
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

    while (game.pathLength < MIN_PATH_LEN || game.pathLength > MAX_PATH_LEN || game.pathLength % 5 != 0) {
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
    int i;
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    
    for(i = 0; i < game.pathLength ; i+=5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);
    }

    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.treasures[i], &game.treasures[i + 1], &game.treasures[i + 2], &game.treasures[i + 3], &game.treasures[i + 4]);
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
    printf("====================================");

    return 0;
}
