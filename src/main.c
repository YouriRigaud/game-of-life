#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "../include/configure.h"



int** init_board(const int lenght, const int height) {

    // Allocate the board and make it empty
    int** board = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        board[i] = calloc(lenght, sizeof(int));
    }

    return board;
}


void print_board(int** board, const int lenght, const int height) {

    for (int i = 0; i < lenght + 2; i++) {
        printf("\033[100m  \033[0m");
    }
    printf("\n");
    for (int i = 0; i < height; i++) {
        printf("\033[100m  \033[0m");
        for (int j = 0; j < lenght; j++) {
            if (board[i][j] == 0) {
                printf("\033[107m  \033[0m");
            } else {
                printf("\033[40m  \033[0m");
            }
        }
        printf("\033[100m  \033[0m");
        printf("\n");
    }

    for (int i = 0; i < lenght + 2; i++) {
        printf("\033[100m  \033[0m");
    }
    printf("\n");
}

void calc_neighbours(int** board, const int lenght, const int height, int** nb_neighbours) {
    
        // Calculate the number of neighbours for each cell
        for (int i = 1; i < height-1; i++) {
            for (int j = 1; j < lenght-1; j++) {
                
                // Genius Copilot
                int x = 0;
                for (int k = -1; k < 2; k++) {
                    for (int l = -1; l < 2; l++) {
                        if (k == 0 && l == 0) {
                            continue;
                        }
                        x += board[i+k][j+l];
                    }
                }

                nb_neighbours[i][j] = x;
            }
        }

        for (int j = 1; j < lenght-1; j++) {

            int x = 0;
            for (int k = 0; k < 2; k++) {
                for (int l = -1; l < 2; l++) {
                    if (k == 0 && l == 0) {
                        continue;
                    }
                    x += board[k][j+l];
                }
            }
            nb_neighbours[0][j] = x;

            x = 0;
            for (int k = height-2; k < height; k++) {
                for (int l = -1; l < 2; l++) {
                    if (k == 0 && l == 0) {
                        continue;
                    }
                    x += board[k][j+l];
                }
            }
            nb_neighbours[height-1][j] = x;
        }

        for (int i = 1; i < height-1; i++) {

            int x = 0;
            for (int k = -1; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    if (k == 0 && l == 0) {
                        continue;
                    }
                    x += board[i+k][l];
                }
            }
            nb_neighbours[i][0] = x;

            x = 0;
            for (int k = -1; k < 2; k++) {
                for (int l = lenght-2; l < lenght; l++) {
                    if (k == 0 && l == 0) {
                        continue;
                    }
                    x += board[i+k][l];
                }
            }
            nb_neighbours[i][lenght-1] = x;
        }

        nb_neighbours[0][0] = board[0][1] + board[1][0] + board[1][1];
        nb_neighbours[0][lenght-1] = board[0][lenght-2] + board[1][lenght-1] + board[1][lenght-2];
        nb_neighbours[height-1][0] = board[height-1][1] + board[height-2][0] + board[height-2][1];
        nb_neighbours[height-1][lenght-1] = board[height-1][lenght-2] + board[height-2][lenght-1] + board[height-2][lenght-2];

}


void update_board(int** board, const int lenght, const int height, int** new_board, int** nb_neighbours) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < lenght; j++) {
            if (board[i][j]) {
                if (nb_neighbours[i][j] < 2 || nb_neighbours[i][j] > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                if (nb_neighbours[i][j] == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
}


int main(void) {

    // Create the board of the game
    int lenght = 90;
    int height = 50;
    int** board = init_board(lenght, height);
    int** nb_neighbours = init_board(lenght, height);
    
    // Configure the board
    configure_board(board, lenght, height);
    calc_neighbours(board, lenght, height, nb_neighbours);
    system("clear");

    while(1) {

        // Print the board
        print_board(board, lenght, height);

        // Update the board
        int** new_board = init_board(lenght, height);
        update_board(board, lenght, height, new_board, nb_neighbours);
        calc_neighbours(new_board, lenght, height, nb_neighbours);


        usleep(100000);
        system("clear");
        board = new_board;



    }

    return 0;
}