/*
	L7-6
	
	[プログラムの説明]
	　キーボードから非負の整数二つa、bを入力し、それらを「2進数で表示(表示桁数は環境に依存)」「aとbの論理積」「aとbの論理和」「aとbの排他的論理和」「aの1の補数」「bの1の補数」を表示します。
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
*/

/*
	ビット単位の論理演算
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
int bits(void)
{
	return count_bits(~0U);
}

//unsigned型のビット内容を表示
void print_bits(unsigned x)
{
	int i;
	for( i = bits() - 1 ; i >= 0 ; i-- )
	{
		putchar( ((x >> i) & 1U) ? '1' : '0' );
	}
}

//メイン関数
int main(void)
{
	//入力する非負の整数を記憶
	unsigned a,b;
	
	//非負の整数を入力
	printf("非負の整数を二つ入力してください。\n");
	printf("a : ");	scanf("%u",&a);
	printf("b : ");	scanf("%u",&b);
	
	//表示
	printf("\na	= ");	print_bits(a);	//aのビット数	
	printf("\nb	= ");	print_bits(b);	//bのビット数
	printf("\na&b	= ");	print_bits(a&b);	//aとbの論理積
	printf("\na|b	= ");	print_bits(a|b);	//aとbの論理和
	printf("\na^b	= ");	print_bits(a^b);	//aとbの排他的論理和
	printf("\n~a	= ");	print_bits(~a);	//aの1の補数
	printf("\n~b	= ");	print_bits(~b);	//bの1の補数
	printf("\n");
	
	return 0;
}
