#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#define _weights 3
double w[_weights];
double activate(double a){
    return (a <= 0) ? 0 : 1;
}
double RightProp(double inputs[3]){
    double res = 0;
    for(int i = 0; i < 3; i++)
        res += w[i] * inputs[i];
    return res;
}
void train(int data[4][3], int exp[4]){
    const double LR = 0.1, EPOCH = 50;
    int d, i, n;
    double error;
    for(i = 0; i < EPOCH; i++)
        for(d = 0; d < 4; d++){
            error = exp[d] - activate(RightProp((double*)data[d]));
            for(n = 0; n < _weights; n++)
                w[n] += LR * error * data[d][n];
        }
}
int main(int argc, char *argv[]){
    int trainingdata[4][3] = { {0, 0, 1}, {0, 1, 1}, {1, 0, 1}, {0, 1, 0} }, expresults[4] = {0, 0, 1}, i;
    srand(1);
    for(i = 0; i < 3; i++)
        w[i] = fmod(rand()%100000000 * 0.1, 1.05);
    train(trainingdata, expresults);
    for(i = 0; i < 3; i++)
        w[i] = (w[i] > 0) ? w[i] : 0;
    double new[3] = {1, 1, 0};
    printf("%.1f", activate(RightProp(new)));
}