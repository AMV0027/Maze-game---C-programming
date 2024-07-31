#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SIZE 10

char maze[SIZE][SIZE] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'}
};

int playerX = 1;
int playerY = 1;
int endX = SIZE - 2;
int endY = SIZE - 2;

void printMaze() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("P ");
            } else if (i == endX && j == endY) {
                printf("E ");
            } else {
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    while (1) {
        printMaze();

        if (playerX == endX && playerY == endY) {
            printf("Congratulations! You reached the end of the maze.\n");
            break;
        }

        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);

        int newX = playerX;
        int newY = playerY;

        switch (move) {
            case 'w':
                newX--;
                break;
            case 'a':
                newY--;
                break;
            case 's':
                newX++;
                break;
            case 'd':
                newY++;
                break;
            default:
                printf("Invalid move. Please try again.\n");
                continue;
        }

        if (maze[newX][newY] == ' ') {
            playerX = newX;
            playerY = newY;
        } else {
            printf("Invalid move. Please try again.\n");
        }
        system("cls");
    }

    return 0;
}
