# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <omp.h>

int main(){

// Start the clock and the main variables
clock_t begin = clock();

long int num_total = 20; // Sum top (only variable that can be changed)
double yy;
double zz=0.;
int i;
float sum_data[num_total];


// We calculate each value of the sum separately
# pragma omp parallel for private(i) shared(sum_data, zz) schedule(static)
for (i=0; i<num_total; i++){
	sum_data[i] = pow(-1./3., i) / (2.*(double)i +1.);
	zz += pow(-1./3., i) / (2.*(double)i +1.);
}

// We sum the elements of the array and calculate the actual value of pi
yy = 0.;
for (i=0; i<num_total; i++){yy += sum_data[i];}
yy *= pow(12., 0.5);

zz *= pow(12., 0.5);

// End the clock and print the outputs
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("With multi \nNumber: %f %f \nComputing time: %f \n\n", yy, zz, time_spent);

}
