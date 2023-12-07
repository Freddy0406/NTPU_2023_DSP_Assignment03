# include "function.h"

/*Main function*/
int main(int argc, char **argv)
{   
    int i =0;
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

    generateWav(fopen("test.wav","wb"),44100,16,440,10000,1);                   //test

    /*Generate test wav*/
    int T = 5;          //wav長度:單位秒
    short *sinedata_3500 = (short*)malloc(sizeof(short)*(FS*T));				//生成儲存指定cos波的動態陣列
    short *sinedata_5000 = (short*)malloc(sizeof(short)*(FS*T));				//生成儲存指定cos波的動態陣列
    generateSin(FS,3500,T,sinedata_3500);
    generateSin(FS,5000,T,sinedata_5000);
    
    




    free(sinedata_3500);
    free(sinedata_5000);
}

