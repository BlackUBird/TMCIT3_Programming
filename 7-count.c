/*
配列a[] = {1,3,5,7,9}の要素数を測定するプログラムです。
*/
#include <stdio.h>

int main(void)
{
	//要素数を数えられる配列
	int a[] = {1,3,5,7,9};

	printf("配列a[]の要素数:%u\n",(unsigned)(sizeof(a) / sizeof(a[0])));

	return 0;
}
