/*
	演習9-3
*/
/*
	文字列の配列を好きなだけ("$$$$"が入力されるまで)読み込んで表示
*/
#include <stdio.h>

//文字列の個数
#define STR_MAX 89

int main(void)
{
	//文字列を格納する配列
	char s[STR_MAX][128] = {0};
	//"$$$$"が入力された文字列の添え字を格納
	int send;
	//ループ用
	int i;

	//文字列の読み込み
	for( i = 0 ; i < STR_MAX ; i++ )
	{
		printf("s[%d]:",i);
		scanf("%s",s[i]);
		//もし"$$$$"が入力されたら読み込みフェーズを終了
		if( s[i][0] =='$' && s[i][1] =='$' && s[i][2] =='$' && s[i][3] =='$' )
		{
			send = i;
			break;
		}
	}

	//読み込んだものを表示
	for( i = 0 ; i < send ; i++ )
	{
		printf("s[%d] = \"%s\"\n",i,s[i]);
	}

	return 0;
}
