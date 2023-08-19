#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WEIGHTS 3
#define LR 0.1
#define EPOCH 50

static double w[WEIGHTS];

double activate(const double a) {
     return (a <= 0) ? 0 : 1;
}

double RightProp(const double inputs[3]) {
     double res = 0;
     for(int i = 0; i < 3; i++)
	  res += w[i] * inputs[i];
     return res;
}

void train(const int data[4][3], const int exp[4]) {
     int d, i, n;
     double error;
     for(i = 0; i < EPOCH; i++)
	  for(d = 0; d < 4; d++){
	       error = exp[d] - activate(RightProp((double*)data[d]));
	       for(n = 0; n < WEIGHTS; n++)
		    w[n] += LR * error * data[d][n];
	  }
}
int main(void) {
     int i;
     const int trainingdata[4][3] = {
	  {0, 0, 1},
	  {0, 1, 1},
	  {1, 0, 1},
	  {0, 1, 0}
     };
     
     const int expresults[4] = {0, 0, 1, 0};
     
     srand(time(NULL));
     
     for(i = 0; i < 3; i++)
	  w[i] = fmod(rand() % 100000000 * 0.1, 1.05);
     
     train(trainingdata, expresults);

     for(i = 0; i < 3; i++)
	  w[i] = (w[i] > 0) ? w[i] : 0;
     
     const double new[3] = {1, 1, 0};

     printf("%.1f\n", activate(RightProp(new)));
}
