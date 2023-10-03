#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <conio.h> // For kbhit() and getch() on Windows
#include <unistd.h> // For sleep() on Linux/Unix

int i, j, height = 28, width = 28;
int game_over, score = 0;
int x, y, flag, food_x, food_y;
int food_proximity = 2, boundary_proximity = 1;
char player_name[20];

void border() {
    system("cls"); // Clear the console (for Windows, use "clear" for Linux/Unix)
    // Loop through each row
    for (i = 0; i < height; i++) {
        // Loop through each column
        for (j = 0; j < width; j++) {
            // If we are at the first row, last row, first column, or last column,
            // print '#' to create the boundary; otherwise, print a space.
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("#");
            }
            else {
                if (i == x && j == y) {
                    printf("0");
                }
                else if (i == food_x && j == food_y) {
                    printf("#");
                }
                else {
                    printf(" ");
                }
            }
        }
        // Move to the next row
        printf("\n");
    }

    // Print the score after the ending of the game.
    printf("Score = %d\n", score);
    printf("Press Q to end the game\n");
}

void setup() {
    // srand(time(NULL));
    game_over = 0;
    x = height / 2; // Initialize the snake in the middle of the screen
    y = width / 2;  // Initialize the snake in the middle of the screen
    food_x = rand() % (height - 2) + 1; // Randomize food x position within boundaries
    food_y = rand() % (width - 2) + 1; // Randomize food y position within boundaries
}

void input() {
    if (kbhit()) {
        switch (getch()) {
        case 77: // Up arrow key
            flag = 1;
            break;
        case 75: // Down arrow key
            flag = 2;
            break;
        case 80: // Left arrow key
            flag = 3;
            break;
        case 72: // Right arrow key
            flag = 4;
            break;
        case 'q':
            game_over = 1;
            break;
        }
    }
}

void game() {
    sleep(0.01);
    switch (flag) {
    case 1:
        y++;
        break;
    case 2:
        y--;
        break;
    case 3:
        x++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    if (x < 0 || x >= height || y < 0 || y >= width) { // Corrected the boundary conditions
        game_over = 1;
    }

    if (abs(x - food_x) <= food_proximity && abs(y - food_y) <= food_proximity) {
        food_x = rand() % (height - 2) + 1;
        food_y = rand() % (width - 2) + 1;
        score += 10;
    }
}

int main() {
    setup();
    while (!game_over) {
      border();
      input();
      game();
    }
    system("cls");
    printf("Game Over!\n");
    FILE *file = fopen("scores.txt", "a");
    if(file != NULL){
      printf("Enter your name: ");
      scanf("%s", player_name);
      fprintf(file, "Name:%s \t\t Score:%d\n----------------------------\n", player_name, score);
      fclose(file);
      printf("Score saved to scores.txt\n");
    }
    else{
      printf("Error opening file!\n");
    }

    return 0;
}
