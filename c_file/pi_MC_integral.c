#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// gcc pi_MC_integral.c -lm

int main(void){
  int niter=1000000;
  // srand((unsigned)time(NULL)); 

  double sum_y=0e0;
  /*************/
  /* Main loop */
  /*************/

  int out_iter = 0;

  for(int iter=1;iter<niter+1;iter++){

    double x = (double)rand()/RAND_MAX;
    double y=sqrt(1e0-x*x);
    sum_y=sum_y+y;
    if((iter%10000==0)|((iter<500))&(iter%10==1)){
      printf("%d   %.10f\n",iter,sum_y/iter);}
    out_iter = iter;
  }
    printf("%d   %.10f\n",out_iter,4*sum_y/out_iter);
}
