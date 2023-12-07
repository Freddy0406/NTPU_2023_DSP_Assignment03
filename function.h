#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>
#define FS 44100.0f                             //sampling frequency
#define FL 4000.0f                              //cutoff frequency
#define PI 3.141592653589793f



float hamming(int N, int n);


/* low-pass filter coef: n=0,1,2...,2M */
float low_pass(int m, int n);

typedef struct				//定義複數結構,通過歐拉公式運算
{
	double real,imag;   
}complex;


void gen_lowpass(FILE *fp, int M, float *h);





#endif