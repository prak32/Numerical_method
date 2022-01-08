#include<stdio.h>
#define max 5
void printTable(float el[max][max]);
float calculateAnswer(float el[max][max],int xterm[max],float resAt); 
int main() { 
  int x[max] = {0,1,3,4,7};
  int f[max] = {1,3,49,129,813};
  float totalResult[max][max] = {};
  float resultAt = 0.3;
  float finalResult; 
  for(int i=0;i<=max-1;i++){
    totalResult[0][i] = f[i];
  } 
  //applying formula 
  for(int j=0;j<max-1;j++){
    for(int i=0;i<((max-j)-1);i++){
      totalResult[j+1][i] = (totalResult[j][i+1] - totalResult[j][i])/(x[(i+1)+j]-x[i]); 
    }
  }
//function to show calculated portions in table;
  printTable(totalResult); 
  finalResult = calculateAnswer(totalResult,x,resultAt);
  printf("answer is %.2f",finalResult); 
} 
void printTable(float el[max][max]){
   for(int i=0;i<=5-1;i++){
    int total = (5-i)-1;
    for(int j=0;j<=total;j++){
    printf("%.2f ",el[i][j]);
    }
    printf("\n");
  }
}
float calculateAnswer(float el[max][max],int xterm[max],float resAt){ 
  float finalAnswer = 0; 
   for(int i=0;i<=max-1;i++){
    float result = 1;
    for(int j=0;j<i;j++){
      result *= (resAt - xterm[j]);
    }
    finalAnswer += (el[i][0] * result); 
  }
  return finalAnswer;
}

