//#include <stdio.h>
//#include <conio.h>
//
//#define SIZE 5
//
//void displayGrid(char grid[SIZE][SIZE]);
//void movePlayer(char grid[SIZE][SIZE], char move, int *playerX, int *playerY, int *itemsCollected);
//
//int main() {
//    char grid[SIZE][SIZE] = {
//        {' ', ' ', 'I', 'X', ' '},
//        {' ', 'X', ' ', ' ', ' '},
//        {'I', ' ', 'X', 'X', ' '},
//        {' ', ' ', ' ', 'I', 'X'},
//        {' ', 'X', ' ', ' ', 'P'}
//    };
//
//    int playerX = 4, playerY = 4; // Player's initial position
//    int itemsCollected = 0;
//    char move;
//    
//    while (1) {
//        displayGrid(grid);
//        printf("Move (W/A/S/D, Q to quit): ");
//        move = _getch();
//        if (move == 'Q' || move == 'q') {
//            break;
//        }
//        movePlayer(grid, move, &playerX, &playerY, &itemsCollected);
//    }
//
//    printf("Game over! You collected %d items.\n", itemsCollected);
//    return 0;
//}
//
//void displayGrid(char grid[SIZE][SIZE]) {
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < SIZE; j++) {
//            printf("%c ", grid[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//void movePlayer(char grid[SIZE][SIZE], char move, int *playerX, int *playerY, int *itemsCollected) {
//    int newX = *playerX;
//    int newY = *playerY;
//
//    switch (move) {
//        case 'W':
//        case 'w':
//            newX--;
//            break;
//        case 'S':
//        case 's':
//            newX++;
//            break;
//        case 'A':
//        case 'a':
//            newY--;
//            break;
//        case 'D':
//        case 'd':
//            newY++;
//            break;
//        default:
//            printf("Invalid move!\n");
//            return;
//    }
//
//    if (newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE || grid[newX][newY] == 'X') {
//        printf("Move not allowed!\n");
//        return;
//    }
//
//    if (grid[newX][newY] == 'I') {
//        (*itemsCollected)++;
//        printf("Item collected!\n");
//    }
//
//    grid[*playerX][*playerY] = ' ';
//    grid[newX][newY] = 'P';
//    *playerX = newX;
//    *playerY = newY;
//}

#include <stdio.h>

void displayGrid(char grid[5][5]);
void movePlayer(char grid[5][5], char move, int player[2], int *itemsCollected);

int main() {
	puts("** P - is your Current Position!");
	puts("** I - are Items to be collected!");
	puts("** X - block you can't pass through!");
	
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int player[2] = {4, 4};
    int itemsCollected = 0;
    char move;

    while (1) {
        displayGrid(grid);
        printf("\nMove (W/A/S/D, Q to quit): ");
        move = getchar();
        getchar();
        if (move == 'Q' || move == 'q') {
            break;
        }
        movePlayer(grid, move, player, &itemsCollected);
    }

    printf("\nGame over! You collected %d items.\n", itemsCollected);
    
    
    return 0;
}

void displayGrid(char grid[5][5]) {
	printf("\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char grid[5][5], char move, int player[2], int *itemsCollected) {
    int newX = player[0];
    int newY = player[1];

    switch (move) {
        case 'W':
        case 'w':
            newX--;
            break;
        case 'S':
        case 's':
            newX++;
            break;
        case 'A':
        case 'a':
            newY--;
            break;
        case 'D':
        case 'd':
            newY++;
            break;
        default:
            printf("Invalid move!\n");
            return;
    }

    if (newX < 0 || newX >= 5 || newY < 0 || newY >= 5 || grid[newX][newY] == 'X') {
        printf("Move not allowed!\n");
        return;
    }

    if (grid[newX][newY] == 'I') {
        (*itemsCollected)++;
        printf("\nItem collected!\n");
    }

    grid[player[0]][player[1]] = ' ';
    grid[newX][newY] = 'P';
    player[0] = newX;
    player[1] = newY;
}
