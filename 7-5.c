/*
	7-5
	[プログラムの説明]
	　符号無し整数の指定ビット目から指定数ビットまでを変化させるプログラム。
	　符号無し整数、指定ビットの値(2つ)は入力です。
*/
/*
	関数「set_n」について
	宣言	unsinged set_n(unsigned x,int pos,int n);
	概略	符号無し整数xの第posビット目からnビットまでを1にします。
	引数	x		:マスクされる値を受けます。unsigned型で受けます。
			pos		:何ビット目からマスクするかを受けます。
			n		:posビット目から何ビットまでを変化させるかを受けます。
	戻り値	(x | ((~((~(0U))<<n))<<(pos-1)) )
					:マスクした結果を返します。
	解説	戻り値では、
			まず全ビットが1である符号無し整数(~(0U))をnビット左シフトし反転します。
				「~((~(0U))<<n」
			それにより、変化させる部分と同じ数(ビット数)だけ1で他が0である2進数の数ができます。
			その後、その数をpos-1ビット左シフトすることでマスクする部分に数を合わせています。
				「(~((~(0U))<<n))<<(pos-1)」
	
	関数「reset_n」について
	宣言	unsinged reset_n(unsigned x,int pos,int n);
	概略	符号無し整数xの第posビット目からnビットまでを0にします。
	引数	x		:マスクされる値を受けます。unsigned型で受けます。
			pos		:何ビット目からマスクするかを受けます。
			n		:posビット目から何ビットまでを変化させるかを受けます。
	戻り値	(x & ~((~((~(0U))<<n))<<(pos-1)) )
					:マスクした結果を返します。
	解説	戻り値では、
			まず全ビットが1である符号無し整数(~(0U))をnビット左シフトし反転します。
				「~((~(0U))<<n」
			それにより、変化させる部分と同じ数(ビット数)だけ1で他が0である2進数の数ができます。
			その後、その数をpos-1ビット左シフトし反転することでマスクする部分に数を合わせています。
				「~((~((~(0U))<<n))<<(pos-1))」
				
	関数「inverse_n」について
	宣言	unsinged invserse_n(unsigned x,int pos,int n);
	概略	符号無し整数xの第posビット目からnビットまでを反転します。
	引数	x		:マスクされる値を受けます。unsigned型で受けます。
			pos		:何ビット目からマスクするかを受けます。
			n		:posビット目から何ビットまでを変化させるかを受けます。
	戻り値	(x ^ ((~((~(0U))<<n))<<(pos-1)) )
					:マスクした結果を返します。
	解説	戻り値では、
			まず全ビットが1である符号無し整数(~(0U))をnビット左シフトし反転します。
				「~((~(0U))<<n」
			それにより、変化させる部分と同じ数(ビット数)だけ1で他が0である2進数の数ができます。
			その後、その数をpos-1ビット左シフトすることでマスクする部分に数を合わせています。
				「(~((~(0U))<<n))<<(pos-1)」
				
	関数「count_bits」について
	宣言	int count_bits(unsigned x);
	概略	引数のビット数を計測します。
	引数	x		:計測する値を受けます。unsigned型で受けます。
	戻り値	bits	:計測した結果を返します。
	解説	仮引数の最小桁と「1」の論理積を求め、真であった場合はローカル変数bitsをインクリメント/偽
			であった場合は何もせず、その後仮引数xを右シフトします。
	
	関数「bits」について
	宣言	int bits(void);
	概略	unsinged型のビット数を返します。
	引数	ありません。
	戻り値	count_bits(~0U)	:unsigned型のビット数を返します。
	解説	「count_bits」に実引数「~0U」を渡します。ここで、「~0U」とは、unsigned型の全ビットに
			「1」が入っている値です。その値を「count_bits」に渡すことでcount_bitsの性質上、ビット数
			の最大値を得ることができます。
	
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

//符号無し整数の指定ビットからnビットまでを1にする
unsigned set_n(unsigned x,int pos,int n)
{
	//符号無し整数の論理和を返す
	return (x | ((~((~(0U))<<n))<<(pos-1)) );
}

//符号無し整数の指定ビットからnビットまでを0にする
unsigned reset_n(unsigned x,int pos,int n)
{
	//符号無し整数との論理積を返す
	return (x & ~((~((~(0U))<<n))<<(pos-1)) );
}

//符号無し整数の指定ビットからnビットまでを反転する
unsigned inverse_n(unsigned x,int pos,int n)
{
	//符号無し整数との排他的論理和を返す
	return (x ^ ((~((~(0U))<<n))<<(pos-1)) );
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
	int b,n;

	//非負の整数を入力
	printf("非負の整数を入力してください。\n");
	printf("a : ");	scanf("%u",&a);
	//第何ビットにマスクするか
	printf("第何ビット目を変化させますか？\n");
	printf("b : ");	scanf("%d",&b);
	//bビット目から何ビットまで変化させるか
	printf("そこから何ビット変化させますか？\n");
	printf("n : ");	scanf("%d",&n);

	//入力した整数を2進数で表示
	printf("\n入力した整数					:");	print_bits(a);	//aのビット数

	//入力した整数の指定ビット目を1にし、表示する
	printf("\n第%dビットから%dビットまでを1にしました。		:",b,n);	print_bits( set_n(a,b,n) );

	//入力した整数の指定ビット目を0にし、表示する
	printf("\n第%dビットから%dビットまでを0にしました。		:",b,n);	print_bits( reset_n(a,b,n) );

	//入力した整数の指定ビット目を反転し、表示する
	printf("\n第%dビットから%dビットまでを反転しました。	:",b,n);	print_bits( inverse_n(a,b,n) );

	puts("");

	return 0;
}