/*
	関数atoi,atol,atofを疑似的に表現するプログラム
	最終更新	:2020/11/28
*/
/*
	関数「strtoi」について
	宣言	int strtoi(const char *nptr);
	概略	受けた数字文字列に対応するint型の値を返します。
	引数	const char *nptr
					;数字文字列を受けます。
	戻り値	v*s		:対応するint型の値を返します。
	解説	関数「atoi」を疑似的に表現したものです。
			まずnptrが指す文字列の先頭文字が負の符号であるかを判別してsに、「正なら1を代入」、「負な
			ら-1を代入後nptrをインクリメント」をそれぞれ行います。
			その後、while文でnptrを走査し現在の文字に対応するint型の値をvに代入し、次の数字があれば
			10倍を、ない或いは小数点ならばwhileを終了を繰り返し、while文終了後にvの値を返します。
			受けた文字列に数字文字、小数点、符号以外が含まれていた場合の動作は保証していません。
	
	関数「strtol」について
	宣言	long strtol(const char *nptr);
	概略	受けた数字文字列に対応するlong型の値を返します。
	引数	const char *nptr
					;数字文字列を受けます。
	戻り値	v*s		:対応するlong型の値を返します。
	解説	関数「atol」を疑似的に表現したものです。
			各変数の宣言がlong型になっている以外は前述のstrtoiと同じです。
			受けた文字列に数字文字、小数点、符号以外が含まれていた場合の動作は保証していません。
	
	関数「strtof」について
	宣言	double strtof(const char *nptr);
	概略	受けた数字文字列に対応するdouble型の値を返します。
	引数	const char *nptr
					;数字文字列を受けます。
	戻り値	v*s		:対応するdouble型の値を返します。
	解説	関数「atof」を疑似的に表現したものです。
			まずnptrが指す文字列の先頭文字が負の符号であるかを判別してsに、「正なら1を代入」、「負な
			ら-1を代入後nptrをインクリメント」をそれぞれ行います。
			一つ目のwhile文は受けた文字列の数字を、文字列内での順番通りに、整数部に並べたものを生成
			しています。例えば*nptrに「123.456」を受けていたら「123456.000000」という値をvに代入しま
			す。
			二つ目のwhile文は一つ目のwhile文の値を小数点を考慮した値に補正しています。具体的に説明す
			ると、一つ目のwhile文でnptrは最後のナル文字まで進んでいるため、そこから小数点があったと
			ころまでデクリメントをし、さらに一回のデクリメントにつきvを0.1倍すれば、文字列に対応した
			double型の値が得られるということです。
			受けた文字列に数字文字、小数点、符号以外が含まれていた場合の動作は保証していません。
	
	メイン関数について
	概略	関数「strtoi」「strtol」「strtof」の動作確認
	解説	数字文字列を入力し、それを上述の3つの関数の実引数として、動作確認を行います。
*/
/*
	関数の実態
*/
/*
	関数atoi,atol,atofを表現	
*/
#include <stdio.h>

//atoi
int strtoi(const char *nptr)
{
	//数字文字列をint型にする
	int v = 0;	//int型にした値を記憶
	int	s = 1;		//符号を記憶
	if( *nptr == '-' )
	{
		s = -1;
		nptr++;
	}
	while( *nptr )
	{
		//数字文字だったら対応する数字に変える
		if( *nptr >= '0' && *nptr <= '9' )
		{
			v += (int)(*nptr - '0');
		}
		
		nptr++;
		
		//最下位桁・小数点でなければ
		if( *nptr != '\0' && *nptr != '.' )
		{
			v *= 10;	//位を一つ上げる
		}
		else
		{
			break;
		}
	}

	return v*s;
}

//atol
long strtol(const char *nptr)
{
	//数字文字列をlong型にする
	long v = 0;	//long型にした値を記憶
	long s = 1;		//符号を記憶
	if( *nptr == '-' )
	{
		s = -1;
		nptr++;
	}
	while( *nptr )
	{
		//数字文字だったら対応する数字に変える
		if( *nptr >= '0' && *nptr <= '9' )
		{
			v += (long)(*nptr - '0');
		}

		nptr++;
		
		//最下位桁・小数点でなければ
		if( *nptr != '\0' && *nptr != '.' )
		{
			v *= 10;	//位を一つ上げる
		}
		else
		{
			break;
		}
	}

	return v*s;
}

//atof
double strtof(const char *nptr)
{
	//数字文字列をdouble型にする
	double v = 0;	//double型にした値を記憶
	double s = 1;	//符号を記憶
	int dp = 0;		//受けた文字列は小数化を記憶
	if( *nptr == '-' )
	{
		s = -1;
		nptr++;
	}
	//全部整数にしたものを記憶
	while( *nptr )
	{
		//数字文字だったら対応する数字に変える
		if( *nptr >= '0' && *nptr <= '9' )
		{
			v += (double)(*nptr - '0');
		}

		nptr++;

		//最下位桁・小数点でなければ
		if( *nptr != '\0' && *nptr != '.' )
		{
			v *= 10.0;	//位を一つ上げる
		}
		else if( *nptr == '.' )
		{
			dp = 1;
		}
	}
	//小数点に戻るまで位を下げる
	while( dp == 1 && !(*(--nptr) == '.') )
	{
		v *= 0.1;
	}

	//もし結果が0だったら符号を+にする
	if( !v )
	{
		s = 1;
	}

	return v*s;
}

//メイン関数
int main(void)
{
	//文字列を記憶（入力）
	char s[128];

	while(1)
	{
		printf("数字文字列を入力してください  ：");	scanf("%s",s);

		//各型に変更後の文字列を表示
		printf("数字文字列をint型にしました   ：%d\n",strtoi(s));
		printf("数字文字列をlong型にしました  ：%ld\n",strtol(s));
		printf("数字文字列をdouble型にしました：%lf\n\n",strtof(s));
	}

	return 0;
}

