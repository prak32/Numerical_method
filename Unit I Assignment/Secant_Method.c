#include<stdio.h>
#include<math.h>
double f(double x){
   // return exp((-x))-5;
    return log(x)+6*x-5;
}
void main(){
    int iter=1;
    double x1,x2,x3,err,E;
    //printf("Given equation is:f(x)=e^(-x)-5\n\n");
    printf("Given equation is:f(x)=ln(x)+6x-5\n\n");
    
    loop:
    printf("Enter the intial guesses:\n");
    scanf("%lf %lf",&x1, &x2);
    printf("Enter the tolerance error:\n");
    scanf("%lf",&E);
    printf("f(%.2f)=%lf\n",x1,f(x1));
    printf("f(%.2f)=%lf",x2,f(x2));
    
    if(f(x1)==f(x2)){
    printf("\nWrong guessses.The root is not defined.\n\n");
    goto loop;
    }
    printf("\n________________________________________________________________________________________________");
    
    printf("\n\niter\tx1\t\tf(x1)\t\tx2\t\tf(x2)\t\tx3\t\terror\n");
    printf("________________________________________________________________________________________________\n");
    do{
        x3=x2-((x2-x1)*f(x2))/(f(x2)-f(x1));
        err = fabs((x3-x2)/x3);
        printf("%d.\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",iter,x1,f(x1),x2,f(x2),x3,err);
        x1=x2;
        x2=x3;
        iter++;
    }while(fabs(err)> E);
    printf("________________________________________________________________________________________________");
    printf("\nThe required roots is %lf",x3);
}
