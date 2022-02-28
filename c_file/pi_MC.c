#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int niter=1000000;

  // srand((unsigned)time(NULL)); 

  int n_in=0;
  /*************/
  /* Main loop */
  /*************/
  int out_iter = 0;
  for(int iter=1;iter<niter+1;iter++){

    double x = (double)rand()/RAND_MAX;
    double y = (double)rand()/RAND_MAX;
    if(x*x+y*y < 1e0)
      n_in=n_in+1;
    
    if((iter%10000==0)|((iter<500))&(iter%10==1)){
      printf("%d :  %.10f\n",iter,(double)n_in/iter);}
    out_iter=iter;
  }
  printf("%d :  %.10f\n",out_iter,(double)n_in*4/out_iter);
}
