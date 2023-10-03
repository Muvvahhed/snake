// C program to multiply 2 multidimensional matrices together
#include <stdio.h>
int main(){
  int matrix1row, matrix1column, matrix2row, matrix2column;//variables to store the order of the matrices
  printf("Enter the dimension of matrix 1 e.g 2,2 for a 2x2 matrix: ");
  scanf("%d,%d", &matrix1row, &matrix1column);//read the dimension of matrix 1
  printf("Enter the dimension of matrix 2 e.g 2,2 for a 2x2 matrix: ");
  scanf("%d,%d", &matrix2row, &matrix2column);//read the dimension of matrix 2
  if(matrix1column != matrix2row){
    //if the number of columns in matrix 1 is not equal to the number of rows in matrix 2, the matrices cannot be multiplied together
    printf("The matrices cannot be multiplied together\n");
    return 0;
  }
  int matrix1[matrix1row][matrix1column], matrix2[matrix2row][matrix2column], resultMatrix[matrix1row][matrix2column]; //declare the matrices
  printf("Enter the elements of matrix 1: \n");
  for(int i = 0; i < matrix1row; i++){
    //read the elements of matrix 1
    for(int j = 0; j < matrix1column; j++){
      scanf("%d", &matrix1[i][j]);
    }
  } 
  printf("Enter the elements of matrix 2: \n");
  for(int i = 0; i < matrix2row; i++){
    //read the elements of matrix 2
    for(int j = 0; j < matrix2column; j++){
      scanf("%d", &matrix2[i][j]);
    }
  };
  printf("The product of the matrices is: \n");

  for(int i = 0; i < matrix1row; i++){
    printf("[ ");
    //for each row in matrix 1 and matrix 2 multiply the elements in the row of matrix 1 by the elements in the column of matrix 2 and add the products
    for(int j = 0; j < matrix2column; j++){
      resultMatrix[i][j] = 0;
      for(int k = 0; k < matrix1column; k++){
        resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
      printf("%d ", resultMatrix[i][j]);
    }
    printf("]");
    printf("\n");
  }
  return 0;
}