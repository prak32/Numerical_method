#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
//#define    f(x) exp((-x))-5
//#define   df(x) -exp((-x))
#define f(x) log(x)+6*x-5
#define df(x) (1/x)+6
void main()
{
	 float x0, x1, f0, df0, tol_err, err;
	 int step = 1;
	 printf("\nEnter initial guess:");
	 scanf("%f", &x0);
	 printf("Enter tolerable error:");
	 scanf("%f", &tol_err);

	 printf("\nStep\t\tx0\t\tf(x0)\t\tdf(x0)\t\tx1\t\terror\n");
	 do
	 {
		  df0 = df(x0);
		  f0 = f(x0);
		  if(df0 == 0.0)
		  {
			   printf("The root doesnot exist.");
			   exit(0);
		  }

		
		  x1 = x0 - f0/df0;
		  err = fabs((x1-x0)/x1);

		
		  printf("%d\t\t%f\t%f\t%f\t%f\t%f\n", step, x0, f0, df0, x1, err);
		  x0 = x1;
		  step = step + 1;
		 
	 }while(fabs(err) > tol_err);
	
	 printf("\nRoot is: %f", x1);
	 getch();
}
