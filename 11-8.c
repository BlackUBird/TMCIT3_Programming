/*
	文字列内の数字文字を削除するするプログラム
	最終更新	:2020/11/28
*/
/*
	関数「del_digit」について
	宣言	void del_digit(char *str);
	概略	文字列str内の数字文字を削除します。
	引数	char *str	:数字文字を削除する文字列を受けます。
	戻り値	ありません。
	解説	まず、受けた文字列と同じ長さのcharのポインタ型変数tを宣言します。
			その後while文でstrを走査し、数字文字でなければtに現在のstrが指す文字を代入して、tをイン
			クリメントします。走査はstrがヌル文字になるまで続けます。
			while文を抜けたら、現在のtが指す文字にヌル文字を代入し、関数を終了します。
	
	メイン関数について
	概略	関数「del_digit」の動作確認
	解説	文字列を入力し、その文字列を「del_degit」で数字文字を削除し、再度文字列を表示します。
*/
/*
	関数の実態
*/
/*
	数字文字を削除
*/
#include <stdio.h>

//文字列内の数字文字を削除する関数
void del_digit(char *str)
{
	char *t = str;

	//削除
	while( *str )
	{
		if( *str < '0' && *str > '9' )
		{
			*t++ = *str;
		}

		str++;
	}

	*t = '\0';
}

//メイン関数
int main(void)
{
	//文字列を記憶（入力）
	char s[128];
	printf("文字列を入力してください：");	scanf("%s",s);

	//数字文字を削除
	del_digit(s);

	//削除後の文字列を表示
	printf("数字文字を削除しました：%s\n",s);
	
	return 0;
}
