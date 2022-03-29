/*
	9-8
*/
/*
	関数「put_stringr」について
		宣言	put_stringr(const char s[]);
		概略	読み込んだ文字列を逆から表示します。
		引数	s	:表示される文字列を受けます。
		戻り値	ありません。(void型)
		解説	読み込んだ文字列を逆から、1回だけ表示します。
				void型関数となっています。
*/
//文字列を逆から表示
void put_stringr(const char s[])
{
	//読み込んだ文字列の長さを記憶
	int len = 0;

	//ループ用
	int i;

	//文字列の長さを測定
	while( s[len] )
	{
		len++;
	}

	//文字列を逆から表示
	for( i = 0 ; i < len ; i++ )
	{
		putchar(s[ len - 1 - i ]);
	}
	printf("\n");
}




