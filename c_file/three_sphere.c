#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// gcc three_sphere.c -lm

int main(void){
  int niter=100000;
  srand((unsigned)time(NULL)); 
  
  double pi=asin(1e0)*2e0;
  double sum_z=0e0;
  int n_in=0;
  /*************/
  /* Main loop */
  /*************/

  /*
  
  V/8 = \int_D \sqrt(1 - x^2 - y^2) dx dy
      = [\int \sqrt(1 - x^2 - y^2) dP] * 1/dP # dP が離散の場合

  */
  for(int iter=1;iter<niter+1;iter++){

    double x = (double)rand()/RAND_MAX;
    double y = (double)rand()/RAND_MAX;
    if(x*x+y*y < 1e0){
      n_in=n_in+1;
      double z=sqrt(1e0-x*x-y*y);
      sum_z=sum_z+z;
    }

    if((iter%10000==0)|((iter<500))&(iter%10==1)){
      printf("%d   %.10f\n",iter,sum_z/n_in*(2e0*pi));
    }
  
  }
}
