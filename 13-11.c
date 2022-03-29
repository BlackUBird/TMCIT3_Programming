/*
	double型、要素数10の配列の全要素の値を読み書きするプログラム
	最終更新	:2021/02/09
*/
/*
	メイン関数について
	概略	:　バイナリファイルの入出力
	解説	:　バイナリファイル「dbl.bin」をオープンまたは作成し、
			double型定数値を書き込み、その後再度オープンし、読み取ります。
			
*/
/*
	関数の実態
*/
/*
	double型、要素数10の配列の全要素の値を読み書きする
*/
#include <stdio.h>

#define ELE_MAX	10

int main(void)
{
	int i;
	FILE	*fp;
	double	dbl[ELE_MAX] = {8.0 , 8.1 , 8.2 , 8.3 , 8.4 , 8.5 , 8.6 , 8.7 , 8.8 , 8.9};

	puts("書き込むdouble型定数");
	for( i = 0 ; i < ELE_MAX ; i++ )
	{
		printf("%6.1lf",dbl[i]);
	}

	//書き込み
	if( (fp = fopen("dbl.bin","wb")) == NULL )
	{
		puts("ファイルをオープンできません。");
	}
	else
	{
		fwrite(dbl,sizeof(double),ELE_MAX,fp);
		fclose(fp);
	}

	//読み取り
	if( (fp = fopen("dbl.bin","wb")) == NULL )
	{
		puts("ファイルをオープンできません。");
	}
	else
	{
		fread(dbl,sizeof(double),ELE_MAX,fp);
		puts("ファイルに書き込まれた数値");
		for( i = 0 ; i < ELE_MAX ; i++ )
		{
			printf("%6.1lf",dbl[i]);
		}
		fclose(fp);
	}

	return 0;
}

