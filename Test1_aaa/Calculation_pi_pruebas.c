# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <omp.h>

int main(){
clock_t begin = clock();

double yy = 0.0;
long int N = 1800000000;


for (int i = 0; i < N; i++){
	yy += pow(-1./3., (double)i) / (2.*(double)i+1.);}

yy *= pow(12., 0.5);



clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;



printf("Without multi \nNumber: %f \nComputing time: %f \n\n", yy, time_spent);


// NEW WAY OF DOING STUFF
clock_t beginn = clock();

yy = 0.0;

#pragma omp parallel for shared(yy, N) schedule(dynamic)
for (int i = 0; i < N; i++){
	yy += pow(-1./3., (double)i) / (2.*(double)i+1.);}

yy *= pow(12., 0.5);



clock_t endd = clock();
time_spent = (double)(endd - beginn) / CLOCKS_PER_SEC;

printf("With dynamic multi \nNumber: %f \nComputing time: %f \n\n", yy, time_spent);


// NEW WAY OF DOING STUFF
clock_t beginnn = clock();

yy = 0.0;

#pragma omp parallel for shared(yy, N) schedule(static)
for (int i = 0; i < N; i++){
	yy += pow(-1./3., (double)i) / (2.*(double)i+1.);}

yy *= pow(12., 0.5);



clock_t enddd = clock();
time_spent = (double)(enddd - beginnn) / CLOCKS_PER_SEC;

printf("With static multi \nNumber: %f \nComputing time: %f \n", yy, time_spent);

return 0;}
