# include "function.h"

/*Main function*/
int main(int argc, char **argv)
{   
    int i =0;
    int T = 5;          //wav長度:單位秒
    int sinedata_length = FS*T;
    /*Create h array to save coeficient*/
    float *h_M_1 = (float*)malloc(sizeof(float)*(2*1+1));
    float *h_M_4 = (float*)malloc(sizeof(float)*(2*4+1));
    float *h_M_16 = (float*)malloc(sizeof(float)*(2*16+1));
    float *h_M_64 = (float*)malloc(sizeof(float)*(2*64+1));
    float *h_M_256 = (float*)malloc(sizeof(float)*(2*256+1));
    float *h_M_512 = (float*)malloc(sizeof(float)*(2*512+1));
    float *h_M_1024 = (float*)malloc(sizeof(float)*(2*1024+1));
    float *h_M_2048 = (float*)malloc(sizeof(float)*(2*2048+1));

    /*Generate low-pass filter*/
    gen_lowpass_DTFT(fopen("M_1_LPF.txt","w+"),1,h_M_1);
    gen_lowpass_DTFT(fopen("M_4_LPF.txt","w+"),4,h_M_4);    
    gen_lowpass_DTFT(fopen("M_16_LPF.txt","w+"),16,h_M_16);
    gen_lowpass_DTFT(fopen("M_64_LPF.txt","w+"),64,h_M_64);
    gen_lowpass_DTFT(fopen("M_256_LPF.txt","w+"),256,h_M_256);
    gen_lowpass_DTFT(fopen("M_512_LPF.txt","w+"),512,h_M_512);
    gen_lowpass_DTFT(fopen("M_1024_LPF.txt","w+"),1024,h_M_1024);
    gen_lowpass_DTFT(fopen("M_2048_LPF.txt","w+"),2048,h_M_2048);

    /*Generate test wav*/
    short *sinedata_3500 = (short*)malloc(sizeof(short)*sinedata_length);				//生成儲存3500Hz sin波的動態陣列
    short *sinedata_5000 = (short*)malloc(sizeof(short)*sinedata_length);				//生成儲存5000Hz sin波的動態陣列
    generateSin(FS,3500,T,sinedata_3500);
    generateSin(FS,5000,T,sinedata_5000);


    short *data_3500 = (short*)malloc(sizeof(short)*sinedata_length);
    short *data_5000 = (short*)malloc(sizeof(short)*sinedata_length);


    /*3500Hz*/

    through_LPF(sinedata_3500, h_M_1, data_3500, sinedata_length, 1);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin3500Hz_M1.wav","wb"),FS,16,T,data_3500);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin3500Hz_M1.txt","w+"),data_3500,sinedata_length);

    through_LPF(sinedata_3500, h_M_4, data_3500, sinedata_length, 4);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin3500Hz_M4.wav","wb"),FS,16,T,data_3500);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin3500Hz_M4.txt","w+"),data_3500,sinedata_length);

    through_LPF(sinedata_3500, h_M_16, data_3500, sinedata_length, 16);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin3500Hz_M16.wav","wb"),FS,16,T,data_3500);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin3500Hz_M16.txt","w+"),data_3500,sinedata_length);

    through_LPF(sinedata_3500, h_M_64, data_3500, sinedata_length, 64);     //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin3500Hz_M64.wav","wb"),FS,16,T,data_3500);           //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin3500Hz_M64.txt","w+"),data_3500,sinedata_length);

    through_LPF(sinedata_3500, h_M_256, data_3500, sinedata_length, 256);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin3500Hz_M256.wav","wb"),FS,16,T,data_3500);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin3500Hz_M256.txt","w+"),data_3500,sinedata_length);

    through_LPF(sinedata_3500, h_M_512, data_3500, sinedata_length, 512);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin3500Hz_M512.wav","wb"),FS,16,T,data_3500);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin3500Hz_M512.txt","w+"),data_3500,sinedata_length);

    through_LPF(sinedata_3500, h_M_1024, data_3500, sinedata_length, 1024);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin3500Hz_M1024.wav","wb"),FS,16,T,data_3500);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin3500Hz_M1024.txt","w+"),data_3500,sinedata_length);

    through_LPF(sinedata_3500, h_M_2048, data_3500, sinedata_length, 2048);     //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin3500Hz_M2048.wav","wb"),FS,16,T,data_3500);           //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin3500Hz_M2048.txt","w+"),data_3500,sinedata_length);

    /*5000Hz*/

    through_LPF(sinedata_5000, h_M_1, data_5000, sinedata_length, 1);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin5000Hz_M1.wav","wb"),FS,16,T,data_5000);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin5000Hz_M1.txt","w+"),data_5000,sinedata_length);

    through_LPF(sinedata_5000, h_M_4, data_5000, sinedata_length, 4);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin5000Hz_M4.wav","wb"),FS,16,T,data_5000);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin5000Hz_M4.txt","w+"),data_5000,sinedata_length);

    through_LPF(sinedata_5000, h_M_16, data_5000, sinedata_length, 16);         //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin5000Hz_M16.wav","wb"),FS,16,T,data_5000);             //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin5000Hz_M16.txt","w+"),data_5000,sinedata_length);

    through_LPF(sinedata_5000, h_M_64, data_5000, sinedata_length, 64);         //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin5000Hz_M64.wav","wb"),FS,16,T,data_5000);             //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin5000Hz_M64.txt","w+"),data_5000,sinedata_length);

    through_LPF(sinedata_5000, h_M_256, data_5000, sinedata_length, 256);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin5000Hz_M256.wav","wb"),FS,16,T,data_5000);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin5000Hz_M256.txt","w+"),data_5000,sinedata_length);

    through_LPF(sinedata_5000, h_M_512, data_5000, sinedata_length, 512);           //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin5000Hz_M512.wav","wb"),FS,16,T,data_5000);              //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin5000Hz_M512.txt","w+"),data_5000,sinedata_length);

    through_LPF(sinedata_5000, h_M_1024, data_5000, sinedata_length, 1024);         //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin5000Hz_M1024.wav","wb"),FS,16,T,data_5000);             //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin5000Hz_M1024.txt","w+"),data_5000,sinedata_length);

    through_LPF(sinedata_5000, h_M_2048, data_5000, sinedata_length, 2048);         //(原音檔,LPF種類,輸出檔案,檔案長度,LPF級數M)
    generateWav(fopen("sin5000Hz_M2048.wav","wb"),FS,16,T,data_5000);             //(檔案名稱,取樣率,取樣位元深度,音檔時長(單位秒),輸出資料)
    result_txt(fopen("sin5000Hz_M2048.txt","w+"),data_5000,sinedata_length); 




    /*Output some data, do "minimum phase" on matlab*/
    result_txt(fopen("sin3500Hz.txt","w+"),sinedata_3500,sinedata_length);
    result_txt(fopen("sin5000Hz.txt","w+"),sinedata_5000,sinedata_length);

    lowpass_coef_txt(fopen("h_M_4.txt","w+"), h_M_4 ,(2*4+1));
    lowpass_coef_txt(fopen("h_M_16.txt","w+"), h_M_16 ,(2*16+1));
    lowpass_coef_txt(fopen("h_M_64.txt","w+"), h_M_64 ,(2*64+1));







    /*Free malloc*/
    free(sinedata_3500);
    free(sinedata_5000);
    free(data_3500);
    free(data_5000);
    free(h_M_1);
    free(h_M_4);
    free(h_M_16);
    free(h_M_64);
    free(h_M_256);
    free(h_M_512);
    free(h_M_1024);
    free(h_M_2048);
}

