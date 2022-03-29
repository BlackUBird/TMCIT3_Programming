/*
	数字文字の出現回数を「*」を並べたグラフとして表示
*/
#include <stdio.h>

//「*」を並べたグラフを表示する関数
void Graph(const int a[])
{
	//ループ用
	int i,j;

	for( i = 0 ; i < 10 ; i++ )
	{
		printf("'%d':",i);
		for( j = 0 ; j < a[i] ; j++ )
		{
			printf("*");
		}
		printf("\n");
	}
}

//メイン関数
int main(void)
{
	//文字列を記憶します
	int ch;
	//数字文字の出現回数を記憶します
	int cnt[10] = {0};
	//ループ用
	int i;

	//文字列を入力し、数字文字の出現回数を数えます
	while( ( ch = getchar() ) != EOF )
	{
		if( ch >= '0' && ch <= '9' )
		{
			cnt[ch - '0']++;
		}
	}

	//数字文字の出現回数を表示
	puts("数字文字の出現回数");
	for( i = 0 ; i < 10 ; i++ )
	{
		printf("'%d':%d\n",i,cnt[i]);
	}

	//出現回数の分布グラフを表示
	printf("---分布グラフ---\n");
	Graph(cnt);

	return 0;
}