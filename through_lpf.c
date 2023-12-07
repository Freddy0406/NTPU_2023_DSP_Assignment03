# include "function.h"




void through_LPF(short *sindata, float h, short *data){


    int data_length = sizeof(sindata)/sizeof(short);
    
    int n = 0;
    int k = 0;
    int y = 0;
    for(n=0;n<data_length;n++) {
		y = 0;
		for(k=0;k<(2*M+1);k++) {
			if( (n-k)>=0 )
		 		y = y + h_L[k] * ((float)(wavin.LChannel[n-k]));
		}
		wavout.LChannel[n] = (short)(roundf(y));
		Y_L[n] = wavout.LChannel[n];								//將quantize之後的資訊存入Y_L

}

