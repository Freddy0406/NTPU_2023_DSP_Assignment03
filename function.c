# include "function.h"


/* hamming: for n=0,1,2,...N, length of N+1 */
float hamming(int N, int n)
{
	return 0.54 - 0.46 * cosf(2*PI*((float)(n))/((float)N));
}


/* low-pass filter coef: n=0,1,2...,2M */
float low_pass(int m, int n)
{
	float wc = 2*PI*FL/FS;
	if(n==m) {// L'Hopital's Rule
		return wc/PI;
	}
	else {
		return sinf(wc*((float)(n-m)))/PI/((float)(n-m)) * hamming(2*m+1, n);
	}
}

void generateSin(int fs,int f,double T, short *sinedata){

    int sampTimes = fs * T;                    // 取樣次數 = 取樣頻率(次數/時間) * 時間
    int i = 0;

    for(i = 0; i < sampTimes; i++){                                              //生成sin波
        sinedata[i] = roundf(10000 * sin(2 * PI * f * (float)i / fs));
    }
}


/*Generate low-pass filter after DTFT*/
void gen_lowpass(FILE *fp, int M, float *h)
{
    if( NULL == fp ){

        printf( "open failure" );

    }
	else{
        int n = 0;
        int N = 4096;
        float result[N];
    
        double *cos_array = (double*)malloc(sizeof(double)*N);
    	double *sin_array = (double*)malloc(sizeof(double)*N);	
        for(n=0;n<(2*M+1);n++) {
            h[n] = low_pass(M, n);
        }
        for(n=-(N/2);n<(N/2);n++) {
            cos_array[n+(N/2)] = cos(2*PI*(double)n/N);
        	sin_array[n+(N/2)] = sin(2*PI*(double)n/N);
        }
                    
        /*DTFT (Use Eular form)*/
        complex Sum_Point;
        for(int k = (N/2)-1;k>0;k--){    
            Sum_Point.real = 0.0;                                                                 
            Sum_Point.imag = 0.0;                                                  
            for(int n = 0;n<N;n++){                                           //DFT is computed by Eula formula 
                if(n<2*M+1){
                    Sum_Point.real += (double)h[n]*cos_array[(k*n)%N];            //complex real
                    Sum_Point.imag -= (double)h[n]*sin_array[(k*n)%N];            //complex imagine
                }
            }
            result[k] = sqrt(pow(Sum_Point.real,2)+pow(Sum_Point.imag,2));
            fprintf(fp,"%lf ",result[k]);                                           //write into txt
            fflush(fp);                                                             //clear cache
        }
        for(int k = 0;k<=(N/2);k++){    
            Sum_Point.real = 0.0;                                                                 
            Sum_Point.imag = 0.0;                                                  
            for(int n = 0;n<N;n++){                                           //DFT is computed by Eula formula 
                if(n<2*M+1){
                    Sum_Point.real += (double)h[n]*cos_array[(k*n)%N];            //complex real
                    Sum_Point.imag -= (double)h[n]*sin_array[(k*n)%N];            //complex imagine
                }
            }
            result[k] = sqrt(pow(Sum_Point.real,2)+pow(Sum_Point.imag,2));
            fprintf(fp,"%lf ",result[k]);                                           //write into txt
            fflush(fp);                                                             //clear cache
        }
        free(cos_array);
        free(sin_array);
		fclose(fp);
		fflush(fp);
    }
}





