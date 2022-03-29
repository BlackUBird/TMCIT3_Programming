/*
	7-4
	[プログラムの説明]
	　キーボードから非負の整数aとマスクするビット位置bを受け、aの第bビット目を「1にする」「0にする」「反転する」を行うプログラムです。
*/
/*
	関数「set」について
	宣言	unsigned set(unsigned x,int pos);
	概略	unsinged型の仮引数xの第posビット目を1にした値を返します。
	引数	x		:マスクされる値を受けます。
			pos		:マスクするビット位置を表す値を受けます。
	戻り値	(x | a)	:受けた数とマスクとの論理和を返します。
	解説	仮引数x(unsigned型)とpos(int型)を受け取り、xの第posビットを1にした値を返します。
			関数内で、2進数で最下位桁のみ1である値a(1U)をposだけビット左シフトし、
			その後、xとaの論理和をとることで、指定ビット位置以外を変化させず、指定ビット位置を1にしています。
			
	関数「reset」について
	宣言	unsigned reset(unsigned x,int pos);
	概略	unsinged型の仮引数xの第posビット目を0にした値を返します。
	引数	x		:マスクされる値を受けます。
			pos		:マスクするビット位置を表す値を受けます。
	戻り値	(x & ~a):受けた数とマスクを反転したものとの論理積を返します。
	解説	仮引数x(unsigned型)とpos(int型)を受け取り、xの第posビット0にした値を返します。
			関数内で、2進数で最下位桁のみ1である値a(1U)をposビットだけ左シフトし、
			その後、~aとすることで指定ビット位置を0、他の位置は全て1である数を生成し、
			xと~aの論理積をとることで、
			指定ビット位置以外を変化させず、指定ビット位置を0にしています。
			
	関数「inverse」について
	宣言	unsigned inverse(unsigned x,int pos);
	概略	unsinged型の仮引数xの第posビット目を反転した値を返します。
	引数	x		:マスクされる値を受けます。
			pos		:マスクするビット位置を表す値を受けます。
	戻り値	(x ^ a)	:受けた数とマスクとの排他的論理和を返します。
	解説	仮引数x(unsigned型)とpos(int型)を受け取り、xの第posビット反転した値を返します。
			関数内で、2進数で最下位桁のみ1である値a(1U)をposビットだけ左シフトし、
			その後、xとaの排他的論理和をとることで、
			指定ビット位置以外を変化させず、指定ビット位置を反転しています。
			排他的論理和は、「Y=0^X」としたときはYはXと同じ値になり、「Y=1^X」としたときはYはXを反転したものになります。

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
	指定ビット位置にマスクするプログラム
*/
#include <stdio.h>

//符号無し整数の指定ビットを1にする
unsigned set(unsigned x,int pos)
{
	//マスクの原型
	unsigned a = 1U;

	//マスクを指定ビットまでシフト
	a <<= pos;

	//マスクと
	//符号無し整数の論理和を返す
	return (x | a);
}

//符号無し整数の指定ビットを0にする
unsigned reset(unsigned x,int pos)
{
	//マスクの原型
	unsigned a = 1U;

	//マスクを指定ビットまでシフト
	a <<= pos;

	//マスクを反転させたものと
	//符号無し整数との論理積を返す
	return (x & ~a);
}

//符号無し整数の指定ビットを反転する
unsigned inverse(unsigned x,int pos)
{
	//マスクの原型
	unsigned a = 1U;

	//マスクを指定ビットまでシフト
	a <<= pos;

	//マスクと
	//符号無し整数との排他的論理和を返す
	return (x ^ a);
}

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
	unsigned a;
	//マスクするビット位置を記憶
	int b;

	//非負の整数を入力
	printf("非負の整数を入力してください。\n");
	printf("a : ");	scanf("%u",&a);
	//第何ビットにマスクするか
	printf("第何ビット目を変化させますか？\n");
	printf("b : ");	scanf("%d",&b);

	//入力した整数を2進数で表示
	printf("\n入力した整数			:");	print_bits(a);	//aのビット数

	//入力した整数の指定ビット目を1にし、表示する
	printf("\n第%dビットを1にしました。	:",b);	print_bits( set(a,b) );

	//入力した整数の指定ビット目を0にし、表示する
	printf("\n第%dビットを0にしました。	:",b);	print_bits( reset(a,b) );

	//入力した整数の指定ビット目を反転し、表示する
	printf("\n第%dビットを反転しました。	:",b);	print_bits( inverse(a,b) );

	return 0;
}
