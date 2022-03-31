# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <omp.h>

int main(){
clock_t begin = clock();

double yy = 0.0;
int N = 20;

int i;


for (i = 0; i < N; i++){
	yy += pow(-1./3., (double)i) / (2.*(double)i+1.);}

yy *= pow(12., 0.5);

clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

printf("Without multi \nNumber: %f \nComputing time: %f \n\n", yy, time_spent);




// DYNAMIC OMP PARALLEL
clock_t beginn = clock();

yy = 0.0;

#pragma omp parallel for private(i) shared(yy, N) schedule(dynamic)
for (i = 0; i < N; i++){
	yy += pow(-1./3., (double)i) / (2.*(double)i+1.);}

yy *= pow(12., 0.5);

clock_t endd = clock();
time_spent = (double)(endd - beginn) / CLOCKS_PER_SEC;

printf("With dynamic multi \nNumber: %f \nComputing time: %f \n\n", yy, time_spent);




// STATIC OMP PARALLEL
clock_t beginnn = clock();

yy = 0.0;

#pragma omp parallel for private(i) shared(yy, N) schedule(static)
for (i = 0; i < N; i++){
	yy += pow(-1./3., (double)i) / (2.*(double)i+1.);}

yy *= pow(12., 0.5);

clock_t enddd = clock();
time_spent = (double)(enddd - beginnn) / CLOCKS_PER_SEC;

printf("With static multi \nNumber: %f \nComputing time: %f \n", yy, time_spent);

return 0;}
