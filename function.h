#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <memory.h>
#define FS 44100.0f                             //sampling frequency
#define FL 4000.0f                              //cutoff frequency
#define PI 3.141592653589793f


struct WaveHeader 
{
	char chRIFF[4];                 //RIFF tag
	int32_t  total_Len;             //檔案(header+語音)長度 = 36 + dataSize
	char chWAVE[4];                 //WAVE tag
	char chFMT[4];                  //fmt tag
	int32_t  FMTLen;               
	int16_t fmt_pcm;                //格式類別:1(PCM)
	int16_t  channels;              //聲道數
	int32_t samplehz;               //取樣點/秒
	int32_t bytepsec;               //位元速率 = 取樣頻率*位元深度/8
	int16_t sample_size;            //一個取樣多聲道資料塊大小(bytes)
	int16_t sample_bits;            //取樣位元深度(m)
	char chDATA[4];                 //data tag
	int32_t  DATALen;               //語音資料的大小
};


float hamming(int N, int n);


/* low-pass filter coef: n=0,1,2...,2M */
float low_pass(int m, int n);

typedef struct				//定義複數結構,通過歐拉公式運算
{
	double real,imag;   
}complex;


void gen_lowpass(FILE *fp, int M, float *h);

void generateWav(FILE *fp,int fs,int m ,int f,double A,double T);



#endif