/*
	キーボードからの入力をファイルに書き込むプログラム
	最終更新	:2021/02/02
*/
/*	
	メイン関数について
	概略	ファイルへの書き込み
	解説	　まず、書き込むデータの数(人数)を記憶し、その後書き込み先ファイル
			を関数「fopen」の書き込みモード"w"で開きます。
			　ファイルを開ければwhle文でninzuがゼロになるまで(人数分)キーボード
			からの入力、ファイルへの書き込みを行います。
			　ちなみに書き込み先のファイルがない場合、関数「fopen」の"w"モード
			の仕様上、このプログラムのソースファイルがあるディレクトリ内に指定
			した名前のファイルが生成されます。
			　書き込み先ファイルはテキストファイルとしています。
			
*/
/*
	関数の実態
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;				//ファイル操作用ポインタ

	char	fname[] = "sta.txt";	//書き込み先ファイル名

	int		ninzu = 0;		//人数
	char	name[100];		//名前
	double	height,weight;	//身長・体重

	int		moji = 0;		//書き込んだ文字数

	//何人分の入力か
	printf("%sに何人分のデータを書き込みますか？\n",fname);
	scanf("%d",&ninzu);


	if(fp = fopen(fname,"w") == NULL)
	{
		fprintf(stderr,"ファイルをオープンできません。\n");
	}
	else
	{
		while( ninzu-- )
		{
			printf("名前:");	scanf("%s",name);
			printf("身長:");	scanf("%lf",&height);
			printf("体重:");	scanf("%lf",&weight);

			if(moji = fprintf(fp,"%s %f %f\n",name,height,weight) < 0)
			{
				fprintf(fp,"書き込みに失敗しました\n");
			}
		}
		printf("%sに名前、身長、体重を書き込みました。\n",fname);
		fclose(fp);
	}

	system("pause");
	return 0;
}

