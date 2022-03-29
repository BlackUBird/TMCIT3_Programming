/*
演習7-1のプログラムコードです。sizeofで求めた型の大きさを用いた計算を出力します。
char 型を１とした場合に、int型が4, double型が8で表される計算機を用いた場合の想定される結果は次のようになると考えられます。
	sizeof 1:4
	sizeof+1:4
	sizeof-1:4

	sizeof(unsigned)-1:3
	sizeof(double)-1:7
	sizeof((double)-1):8

	sizeof n+2:6
	sizeof(n+2):4
	sizeof(n+2.0):8
*/
#include <stdio.h>

int main(void)
{
	//int型変数
	int n;

	printf("sizeof 1:%u\n",sizeof(1));
	printf("sizeof+1:%u\n",sizeof(+1));
	printf("sizeof-1:%u\n",sizeof(-1));

	printf("sizeof(unsigned)-1:%u\n",sizeof(unsigned)-1);
	printf("sizeof(double)-1:%u\n",sizeof(double)-1);
	printf("sizeof((double)-1):%u\n",sizeof((double)-1));

	printf("sizeof n+2:%u\n",sizeof n+2);
	printf("sizeof(n+2):%u\n",sizeof(n+2));
	printf("sizeof(n+2.0):%u\n",sizeof(n+2.0));

	return 0;
}
