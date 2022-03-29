/*
	演習9-4
	文字列sを空文字列にする関数
*/
/*
	関数「null_string」について
		宣言	null_string(char s);
		概略	読み込んだ文字列を空文字列にする。
		引数	s	:空文字列にする文字列。
		戻り値	なし。
		解説	読み込んだ文字列の先頭の文字をナル文字にすることで、
				読み込んだ文字列をプログラム上で空文字列として扱うようにします。
*/
#include <stdio.h>

//文字列を空文字列にする関数
void null_string(char s[])
{
	s[0] = '\0';
}

//メイン関数
int main(void)
{
	//文字列宣言
	char s[] = "ABC";

	//文字列を表示
	printf("文字列sは	\"%s\"	です。\n",s);

	//文字列s[]を空文字列にする
	null_string(s);
	printf("文字列sは	\"%s\"	です。\n",s);

	return 0;
}



