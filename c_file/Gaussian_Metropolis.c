#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// gcc Gaussian_Metropolis.c -lm
int main(void){
  int niter=100000;
  int Burnin = 0;
  int numGroup = 10;
  double step_size=0.5e0;

  float sum_x = 0;
  float sum_x2 = 0;

  float x_arr[numGroup];
  float x2_arr[numGroup];
  int count = 0;

  // srand((unsigned)time(NULL)); 

  /*********************************/
  /* Set the initial configuration */
  /*********************************/      
  double x=0e0;
  int naccept=0;
  /*************/
  /* Main loop */
  /*************/

  float jack_x = 0;
  float jack_x2 = 0;

  for(int iter=1;iter<niter+1;iter++){
    double backup_x=x;    
    double action_init=0.5e0*x*x;
    
    double dx = (double)rand()/RAND_MAX;
    dx=(dx-0.5e0)*step_size*2e0;
    x=x+dx;
    
    double action_fin=0.5e0*x*x;
    /*******************/
    /* Metropolis test */
    /*******************/
    double metropolis = (double)rand()/RAND_MAX;    
    if(exp(action_init-action_fin) > metropolis)
      /* accept */
      naccept=naccept+1;
    else 
      /* reject */
      x=backup_x;
    

    if (iter>=Burnin){
      sum_x += x;
      sum_x2 += pow(x,2);
      x_arr[iter%numGroup] += x;
      x2_arr[iter%numGroup] += pow(x,2);

      if(iter % numGroup == numGroup-1){
        count+=1;
        float ave_x = 0;
        float ave_x2 = 0;
        for(int i=0; i<numGroup;i++){
          ave_x += x_arr[i]/count;
          ave_x2 += x2_arr[i]/count;
        }
        
        ave_x /= numGroup;
        ave_x2 /= numGroup;

        jack_x = 0;
        jack_x2 = 0;

        for(int i=0; i<numGroup;i++){
          jack_x += pow(x_arr[i]/count-ave_x,2);
          jack_x2 += pow(x2_arr[i]/count-ave_x2,2);
        }
        jack_x /= numGroup*(numGroup-1);
        jack_x2 /= numGroup*(numGroup-1);

        jack_x = sqrt(jack_x);
        jack_x2 = sqrt(jack_x2);
      }

      if(iter % (niter/100) ==0){
        printf("%i - time \n",iter);
        printf("Sample : %.10f   %f\n",x,(double)naccept/iter);
        printf("Sum : %4f, %4f\n",sum_x/(iter+1),sum_x2/(iter+1));
        printf("Jack Knife : %4f, %4f\n",jack_x,jack_x2);
      }
    }
    /***************/
    /* data output */
    /***************/
    }
}
