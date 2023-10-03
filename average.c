#include <stdio.h>
int main(){
  int num;
  float average, sum = 0;
  printf("enter amount of numbers: \n");
  scanf("%d", &num);
  float array[num];
  for(int j=0; j<num; j++){
    printf("enter number: \n");
    scanf("%f", &array[j]);
    sum = sum + array[j];
  }
  average = sum/num;
  printf("Average is %.2f", average);
  return 0;
}