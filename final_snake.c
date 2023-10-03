#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include <unistd.h> 

int height = 28, width = 56;
int i, j, snake_x, snake_y, food_x, food_y, direction;
int game_over, score;

void draw_board(){
  system("cls");

  printf("Score: %d\n",score);
  for(i=0; i<height; i++){
    for(j=0; j<width; j++){
      if(i==0 || i==height-1 || j==0 || j==width-1 ){
        printf("#");
      }
      else{
        if(i==snake_x && j == snake_y){
          printf("0");
        }
        else if(i==food_x && j == food_y){
          printf("*");
        }
        else{
          printf(" ");
        }
      }
    }
    printf("\n");
  }
}

void set_up_game(){
  srand(time(NULL)); //resets the random number generator
  game_over = 0;
  score=0;
  snake_x = height/2;
  snake_y = width/2;
  food_x = rand() % (height-2) + 1;
  food_y = rand() % (width-2) + 1;
}

void input(){
  if(kbhit()){
    switch(getch()){
      case 72: // Up arrow
        direction = 1;
        break;
      case 75: // Left arrow
        direction = 2;
        break;
      case 77: // Right arrow
        direction = 3;
        break;
      case 80: // Down arrow
        direction = 4;
        break;
      case 'q':
        game_over = 1;
        break;
      default:
        break;
    }
  }
}

void controller(){
  sleep(0.1);
  switch(direction){
    case 1:
      snake_x--;
      break;
    case 2:
      snake_y--;
      break;
    case 3:
      snake_y++;
      break;
    case 4:
      snake_x++;
      break;
    default:
      break;
  }
  if(snake_x == 0 || snake_x == height-1 || snake_y == 0 || snake_y == width-1){
    game_over = 1;
  }
  if(abs(snake_x -food_x) <= 1 && abs(snake_y - food_y) <= 1){
    score++;
    food_x = rand() % (height-2) + 1;
    food_y = rand() % (width-2) + 1;
  }


}

int main(){
  set_up_game();
  while (!game_over){
    draw_board();
    input();
    controller();
  }
  
  return 0;
}