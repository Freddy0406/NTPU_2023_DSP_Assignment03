# include "function.h"


/*Generate Sine*/
void gen_sinusoid(int N,double freq,char txt[]){
    double *sin_array = (double*)malloc(sizeof(double)*N);

    for(int a = 0;a<N;a++){                                             //Create cos and sin data (Represent x[n] = e^(j*omega*n/N) in euler's form)
        sin_array[a] = sin(2*PI*freq*(double)a/N);
    }
    
        FILE *txtfp;                                                        //Open a txt file
    txtfp=fopen(txt,"wb");
    if(txtfp==NULL){
        printf( "open failure" );
    }
    else{

        for(int a = 0; a < N; a++){
            fprintf(txtfp,"%lf\n",sin_array[a]);     //write into txt
            fflush(txtfp);                                   //clear cache
        }

        free(sin_array);                               
        fclose(txtfp);                                       //close txt file
        fflush(txtfp);
    }
}



/*Main function*/
int main(int argc, char **argv)
{   
    /*Create h array to save coeficient*/
    float h_M_1[2*1+1];
    float h_M_4[2*4+1];
    float h_M_16[2*16+1];
    float h_M_64[2*64+1];
    float h_M_256[2*256+1];
    float h_M_512[2*512+1];
    float h_M_1024[2*1024+1];
    float h_M_2048[2*2048+1];

    /*Generate low-pass filter*/
    gen_lowpass(fopen("M_1_LPF.txt","w+"),1,h_M_1);
    gen_lowpass(fopen("M_4_LPF.txt","w+"),4,h_M_4);    
    gen_lowpass(fopen("M_16_LPF.txt","w+"),16,h_M_16);
    gen_lowpass(fopen("M_64_LPF.txt","w+"),64,h_M_64);
    gen_lowpass(fopen("M_256_LPF.txt","w+"),256,h_M_256);
    gen_lowpass(fopen("M_512_LPF.txt","w+"),512,h_M_512);
    gen_lowpass(fopen("M_1024_LPF.txt","w+"),1024,h_M_1024);
    gen_lowpass(fopen("M_2048_LPF.txt","w+"),2048,h_M_2048);



    generateWav(fopen("cos_3500Hz-16k.wav","wb"),FS,16,3500,10000,1);
    


                     


}

