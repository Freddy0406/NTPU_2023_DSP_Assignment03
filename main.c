# include "function.h"

/*Main function*/
int main(int argc, char **argv)
{   
    int i =0;
    int T = 5;          //wav長度:單位秒
    int sinedata_length = FS*T;
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

    /*Generate test wav*/
    short *sinedata_3500 = (short*)malloc(sizeof(short)*sinedata_length);				//生成儲存指定sin波的動態陣列
    short *sinedata_5000 = (short*)malloc(sizeof(short)*sinedata_length);				//生成儲存指定sin波的動態陣列
    generateSin(FS,3500,T,sinedata_3500);
    generateSin(FS,5000,T,sinedata_5000);


    /**/
    short *data_3500 = (short*)malloc(sizeof(short)*sinedata_length);
    short *data_5000 = (short*)malloc(sizeof(short)*sinedata_length);


    through_LPF(sinedata_3500, h_M_4, data_3500, sinedata_length, 4);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin3500Hz_M4.wav","wb"),FS,16,T,data_3500);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)

    result_txt(fopen("sin3500Hz_M4.txt","w+"),data_3500,sinedata_length);

    through_LPF(sinedata_3500, h_M_16, data_3500, sinedata_length, 16);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin3500Hz_M16.wav","wb"),FS,16,T,data_3500);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin3500Hz_M16.txt","w+"),data_3500,sinedata_length);

    through_LPF(sinedata_3500, h_M_64, data_3500, sinedata_length, 64);     //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin3500Hz_M64.wav","wb"),FS,16,T,data_3500);           //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin3500Hz_M64.txt","w+"),data_3500,sinedata_length);



    through_LPF(sinedata_5000, h_M_4, data_5000, sinedata_length, 4);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin5000Hz_M4.wav","wb"),FS,16,T,data_5000);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin5000Hz_M4.txt","w+"),data_5000,sinedata_length);

    through_LPF(sinedata_5000, h_M_16, data_5000, sinedata_length, 16);         //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin5000Hz_M16.wav","wb"),FS,16,T,data_5000);             //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin5000Hz_M16.txt","w+"),data_5000,sinedata_length);

    through_LPF(sinedata_5000, h_M_64, data_5000, sinedata_length, 64);         //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin5000Hz_M64.wav","wb"),FS,16,T,data_5000);             //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin5000Hz_M64.txt","w+"),data_5000,sinedata_length);

    

    free(sinedata_3500);
    free(sinedata_5000);
    free(data_3500);
    free(data_5000);
}

