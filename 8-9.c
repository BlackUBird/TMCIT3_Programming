/*
	標準入力に現れた行数をカウントするプログラム
*/
#include <stdio.h>

int main(void)
{
	//入力された文字列を記憶します
	int ch;
	//標準入力に現れた行数を記憶します
	int cnt = 0;

	//標準入力を受け付けし、
	//行数をカウント
	while( (ch = getchar()) != EOF )
	{
		if( ch == '\n' )
		{
			cnt++;
		}
	}

	//数えた行数を出力・表示
	printf("行数：%d\n",cnt);

	return 0;
}