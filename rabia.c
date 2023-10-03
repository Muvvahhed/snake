#include <stdio.h>
int main(){
 int num,sum = 0;
 float avg;
 printf("Enter the amount of numbers: ");
 scanf("%d", &num);
  int x;
 for(int i=0; i<num; i++){
  printf("\nenter number ");
  scanf("%d", &x);
  sum = sum + x;
 }
 avg = sum/num;
  printf("Average is %.2f", avg);
  return 0;
}