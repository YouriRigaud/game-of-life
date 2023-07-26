#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>


void random_config(int** board, const int lenght, const int height) {

    // Set the seed for the random number generator
    srand(time(NULL));

    // Fill the board with random numbers
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < lenght; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void glider_config(int** board, const int lenght, const int height) {
    board[10][1] = 1;
    board[11][2] = 1;
    board[12][2] = 1;
    board[12][1] = 1;
    board[12][0] = 1;
}


void LWSS_config(int** board, const int lenght, const int height) {
    board[10][1] = 1;
    board[10][4] = 1;
    board[11][5] = 1;
    board[12][5] = 1;
    board[13][2] = 1;
    board[13][3] = 1;
    board[13][4] = 1;
    board[13][5] = 1;
    board[12][1] = 1;
}


void configure_board(int** board, const int lenght, const int height) {
    
    system("clear");
    printf("Choose a configuration:\n");
    printf("1. Random\n");
    printf("2. Glider\n");
    printf("3. Lightweight spaceship\n");
    printf("4. Pulsar\n");
    printf("5. Gosper glider gun\n");
    printf("6. Pentadecathlon\n");
    printf("7. Diehard\n");
    printf("8. Acorn\n");
    printf("9. R-pentomino\n");
    printf("10. Queen bee shuttle\n");
    printf("11. Exit\n");

    printf("WARNING: config >= 4 not implemented yet\n");

    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            random_config(board, lenght, height);
            break;
        case 2:
            glider_config(board, lenght, height);
            break;
        case 3:
            LWSS_config(board, lenght, height);
            break;
        // case 4:
        //     pulsar_config(board, lenght, height);
        //     break;
        // case 5:
        //     gosper_glider_gun_config(board, lenght, height);
        //     break;
        // case 6:
        //     pentadecathlon_config(board, lenght, height);
        //     break;
        // case 7:
        //     diehard_config(board, lenght, height);
        //     break;
        // case 8:
        //     acorn_config(board, lenght, height);
        //     break;
        // case 9:
        //     r_pentomino_config(board, lenght, height);
        //     break;
        // case 10:
        //     queen_bee_shuttle_config(board, lenght, height);
        //     break;
        case 11:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
    }
}
