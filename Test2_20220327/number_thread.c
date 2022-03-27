// gcc -o p -fopenmp hello_openmp.c 
#include <stdio.h>
#include <omp.h>

void main(){
  #pragma omp parallel
  {
    int ID = omp_get_thread_num(); // returns the thread number
    printf("hello(%d)", ID);
    printf("world(%d)\n", ID);
  }
<<<<<<< HEAD
  printf("aaaaahhhhhhh \n")
=======
>>>>>>> aa6f19a9a5f6d3ef512bb24860aae09341e11b36
}
