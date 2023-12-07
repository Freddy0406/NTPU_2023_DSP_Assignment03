# include "function.h"


void generateWav(FILE *fp,int fs,int m ,int f,double A,double T){

	if( NULL == fp ){

        printf( "open failure" );

    }
	else{


		int sampTimes = fs * T;                    // 取樣次數 = 取樣頻率(次數/時間) * 時間
		int dataSize = sampTimes * 2 * (m / 8);    // 音檔大小 = 取樣次數 * 聲道數 * 每次取樣次數大小(Bytes)
		int i = 0;

		short  *sinedata = (short*)malloc(sizeof(short)*sampTimes);				//生成儲存指定cos波的動態陣列
		short  *cosinedata = (short*)malloc(sizeof(short)*sampTimes);  			//生成儲存指定cos波的動態陣列                  
		
		struct WaveHeader WavInf;              //生成空的wav標頭檔以便寫入

		WavInf.chRIFF[0]='R';                  //RIFF tag
		WavInf.chRIFF[1]='I';
		WavInf.chRIFF[2]='F';
		WavInf.chRIFF[3]='F';

		WavInf.total_Len = 36 + dataSize;      //檔案(header+語音)長度 = 36 + dataSize   

		WavInf.chWAVE[0]='W';                  //WAVE tag
		WavInf.chWAVE[1]='A';
		WavInf.chWAVE[2]='V';
		WavInf.chWAVE[3]='E';

		WavInf.chFMT[0]='f';                   //fmt tag
		WavInf.chFMT[1]='m';
		WavInf.chFMT[2]='t';
		WavInf.chFMT[3]=' ';

		WavInf.FMTLen = 16;                    //16
		WavInf.fmt_pcm = 1;                    //格式類別:1(PCM)
		WavInf.channels = 2;                   //聲道數
		WavInf.samplehz = fs;                  //取樣點/秒
		WavInf.bytepsec = fs * 2 * (m / 8);    //位元速率 = 取樣頻率*位元深度/8  
		WavInf.sample_size = 2 * (m / 8);      //一個取樣單聲道資料塊大小(bytes)      
		WavInf.sample_bits = m;               //取樣位元深度(m，單位為bit)              

		WavInf.chDATA[0]='d';                  //data tag
		WavInf.chDATA[1]='a';
		WavInf.chDATA[2]='t';
		WavInf.chDATA[3]='a';

		WavInf.DATALen = dataSize;             //語音資料的大小

		fwrite(&WavInf,sizeof(WavInf),1,fp);                                         //寫入標頭檔

		for(i = 0; i < sampTimes; i++){                                              //生成sin波
			sinedata[i] = round(A * sin(2 * PI * f * (float)i / fs));
			fwrite(&sinedata[i],sizeof(short),1,fp);			
			fflush(fp);
			sinedata[i] = round(A * sin(2 * PI * f * (float)i / fs));
			fwrite(&sinedata[i],sizeof(short),1,fp);			
			fflush(fp);
		}
		//free malloc
		free(sinedata);
		free(cosinedata);
		fclose(fp);
		fflush(fp);
    }
}


