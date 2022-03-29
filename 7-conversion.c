/*
10進数を2進数、8進数、16進数に基数変換するプログラムです。
HENKAN(x,y);に
	x:変換後の基数
	y:変換したい数
を入力すると変換後の数が表示されます。
*/
#include <stdio.h>

//10進数を基数変換し表示する関数
int HENKAN(const int car,int n)
{
	//変換後の数を一桁ずつ格納していく変数
	int num[16] = {0};
	//カウンタ 
	int cnt = 0;
	//ループ用
	int i;

	//car進数に変換
	printf("10進数の%dを%d進数にすると:",n,car);
	while( n )
	{
		num[cnt] = n % car;

		n = n / car;
		cnt++;
	}
	for( i = cnt ; i >= 0 ; i-- )
	{
		printf("%d",num[i]);
	}
	printf("\n");

	return 0;
}
int main(void)
{
	//変換される10進数
	int N = 55;

	//2進数に変換
	HENKAN(2,N);
	//8進数に変換
	HENKAN(8,N);
	//16進数に変換
	HENKAN(16,N);

	return 0;
}
