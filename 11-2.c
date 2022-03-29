/*
	ポインタによる文字列の配列で文字列を表示する関数
	最終更新	:2020/11/14
*/
/*	
	メイン関数について
	概略	2次元配列とポインタによる文字列の配列で、文字列を表示します。
	解説	ポインタの配列で文字列を表示できることを確認できます。
			for文の終了条件では、sizeof関数を用いて
				(配列全体の長さ)/(配列の要素１つの長さ)
			で配列の要素数を計算して、それを条件としています。
*/
/*
	文字列の配列
*/
#include <stdio.h>

int main(void)
{
	int i;
	char a[][5]	= {"LISP" , "C" , "Ada"};
	char *p[]	= {"PAUL" , "X" , "MAC"};
	
	for( i = 0 ; i < (sizeof(a)/sizeof(a[0])) ; i++ )
	{
		printf("a[%d] = \"%s\"\n",i,a[i]);
	}
	
	for( i = 0 ; i < (sizeof(p)/sizeof(p[0])) ; i++ )
	{
		printf("p[%d] = \"%s\"\n",i,p[i]);
	}
	
	return 0;
}
