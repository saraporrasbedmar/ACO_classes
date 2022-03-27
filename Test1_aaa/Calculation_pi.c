# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main(){

double yy = 0.0;
int N = 18;

for (int i = 0; i < N; i++){
	yy += pow(-1./3., (double)i) / (2.*(double)i+1.);}

yy *= pow(12., 0.5);


printf("Number: %f \n", yy);

return 0;}
