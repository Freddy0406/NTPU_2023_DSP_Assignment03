# include "function.h"

void through_LPF(short *sindata, float *h, short *data, int data_length, int M){

    int n = 0;
    int k = 0;
    float y = 0;
    for(n=0;n<data_length;n++) {
		y = 0;
		for(k=0;k<(2*M+1);k++) {
			if( (n-k)>=0 )
		 		y = y + h[k] * ((float)(sindata[n-k]));
		}
		data[n] = (short)(roundf(y));					//將quantize之後的資訊存入data
		
	}
}
