/*
	8-8
	[プログラムの説明]
	　最大公約数をユークリッドの互除法により求めるプログラムです。
*/
/*
	関数「gcd」について
	宣言	int gcd(int x,int y);
	概略	受けた2値の最大公約数を求めます。
	引数	x,y		:最大公約数を求める際の2値を受けます。
	戻り値	( x > y ) ? y : x
					:最大公約数を返します
			( x > y ) ? gcd(a,y) : gcd(a,x)
					:ユークリッドの互除法をもとにした、再帰関数呼び出しを行い、
					最大公約数を返します。
	解説	ユークリッドの互除法を用いて最大公約数を求めます。
			ユークリッドの互除法とは、二つの整数を長方形の辺の長さとし、短いほうの辺を一辺とした正方
			形で埋め尽くし、長方形が残ればその長方形で同じことを、余すことなく埋め尽くせれば、正方形
			の一辺が最大公約数となる、という理論です。
			プログラムでは、まず2値の大小関係を調べ、剰余を記憶します。その後、剰余が0(正方形で余す
			ことなく埋め尽くすことができた)なら2値の内小さいほうを返し、剰余が非0(長方形が余った)な
			ら余りと2値の内小さいほうを関数gcdに渡し、再帰呼び出しをします。
*/


/*
	最大公約数を求めるプログラム
*/
#include <stdio.h>

//最大公約数を求める関数
int gcd(int x,int y)
{
	//受けた2整数値の剰余を記憶
	int a;
	a = ( x > y ) ? (x % y) : (y % x);

	if( a == 0 )
	{
		return ( x > y ) ? y : x;
	}
	else
	{
		return ( x > y ) ? gcd(a,y) : gcd(a,x);
	}
}

//メイン関数
int main(void)
{
	//整数値を記憶
	int x,y;

	//整数値を入力
	printf("整数値を二つ入力してください\n");
	printf("x	: ");	scanf("%d",&x);
	printf("y	: ");	scanf("%d",&y);

	//最大公約数を求める
	printf("%dと%dの最大公約数は%dです。\n",x,y,gcd(x,y));

	return 0;
}