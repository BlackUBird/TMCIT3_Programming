/*
	7-2
	[プログラムの説明]
	　キーボードから非負の整数aとシフトする桁数bを受け、aをb桁左または右にシフトした値が a*2^bまたはa*(1/2)^b と一致するかを確認するためのプログラムです。
*/
/*
	関数「count_bits」について
	宣言	int count_bits(unsigned x);
	概略	引数のビット数を計測します。
	引数	x		:計測する値を受けます。unsigned型で受けます。
	戻り値	bits	:計測した結果を返します。
	解説	仮引数の最小桁と「1」の論理積を求め、真であった場合はローカル変数bitsをインクリメント/偽であった場合は何もせず、その後仮引数xを右シフトします。
	
	関数「bits」について
	宣言	int bits(void);
	概略	unsinged型のビット数を返します。
	引数	ありません。
	戻り値	count_bits(~0U)	:unsigned型のビット数を返します。
	解説	「count_bits」に実引数「~0U」を渡します。ここで、「~0U」とは、unsigned型の全ビットに「1」が入っている値です。その値を「count_bits」に渡すことでcount_bitsの性質上、ビット数の最大値を得ることができます。
	
	関数「print_bits」について
	宣言	void print_bits(unsigned x);
	概略	unsinged型のビット内容を表示します。
	引数	x		:ビット内容を表示する値を受けます。
	戻り値	ありません。
	解説	仮引数x(unsigned型)を受け取り、その数値を2進数(01)で表示します。
	
	関数「beki_kake」について
	宣言	void beki_kake(unsigned x,unsigned n);
	概略	unsinged型の仮引数xを2^n倍した値を2進数(01)で表示します。
	引数	x		:2^n倍される値を受けます。
			n		:xにかかる係数の指数部を受けます。
	戻り値	ありません。
	解説	仮引数x(unsigned型)とn(unsigned型)を受け取り、その数値を2^n倍し、その後2進数(01)で表示します。
			関数内で仮引数xの値が変化します。
			
	関数「beki_wari」について
	宣言	void beki_wari(unsigned x,unsigned n);
	概略	unsinged型の仮引数xを(1/2)^n倍した値を2進数(01)で表示します。
	引数	x		:(1/2)^n倍される値を受けます。
			n		:xにかかる係数の指数部を受けます。
	戻り値	ありません。
	解説	仮引数x(unsigned型)とn(unsigned型)を受け取り、その数値を(1/2)^n倍し、その後2進数(01)で表示します。
			関数内で仮引数xの値が変化します。
*/


/*
	ビットシフト確認用プログラム
*/
#include <stdio.h>

//整数中のセットされたビット数を返す
int count_bits(unsigned x)
{
	int bits = 0;
	while( x )
	{
		if( x & 1U )
		{
			bits++;
		}
		x >>= 1;
	}
	
	return bits;
}

//unsigned型のビット数を返す
int int_bits(void)
{
	return count_bits(~0U);
}

//unsigned型のビット内容を表示
void print_bits(unsigned x)
{
	int i;
	for( i = int_bits() - 1 ; i >= 0 ; i-- )
	{
		putchar( ((x >> i) & 1U) ? '1' : '0' );
	}
}

//数値xを2のべき乗でn回乗算した値を表示
void beki_kake(unsigned x,unsigned n)
{
	//ループ用
	int i;
	
	//べき乗
	for( i = 0 ; i < n ; i++ )
	{
		x = x * 2;
	}
	
	//表示
	print_bits(x);
}

//数値xを2のべき乗でn回除算した値を表示
void beki_wari(unsigned x,unsigned n)
{
	//ループ用
	int i;
	
	//べき乗
	for( i = 0 ; i < n ; i++ )
	{
		x = x / 2;
	}
	
	//表示
	print_bits(x);
}

//メイン関数
int main(void)
{
	//a	:シフトされる整数
	//b	:左右にシフトするビット数
	//を記憶
	unsigned a,b;
	
	//シフトされる数値を入力
	printf("非負の正数を入力してください。\n");
	printf("a : ");	scanf("%u",&a);
	
	//シフトするビット数を入力
	printf("シフトするビット数を入力してください。\n");
	printf("b : ");	scanf("%u",&b);
	
	//ビット数を表示
	printf("\nビット数	=%d",int_bits());

	//入力した整数
	//入力した整数を左シフトしたもの
	//入力した整数を右シフトしたもの
	//を表示
	printf("\n整数		=");	print_bits(a);
	printf("\n左シフト	=");	print_bits(a << b);	
	printf("\n右シフト	=");	print_bits(a >> b);

	//入力した整数を
	//2^b倍したもの
	//(1/2)^b倍したもの
	printf("\n整数に掛け算	=");	beki_kake(a,b);
	printf("\n整数に割り算	=");	beki_wari(a,b);
	
	printf("\n");
	
	return 0;
}