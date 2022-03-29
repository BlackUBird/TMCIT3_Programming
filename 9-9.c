/*
	9-9
*/
/*
	関数「rev_string」について
		宣言	rev_string(const char s[]);
		概略	読み込んだ文字列を反転します。
		引数	s	:表示される文字列を受けます。
		戻り値	ありません。(void型)
		解説	読み込んだ文字列を、反転したものに更新します。
				void型関数となっています。
*/
//文字列を反転
void rev_string(char s[])
{
	//読み込んだ文字列の長さを記憶
	int len = 0;

	//入れ替えられる文字をいったん記憶
	int tmp;

	//ループ用
	int i;

	//文字列の長さを測定
	while( s[len] )
	{
		len++;
	}

	//文字列を反転
	for( i = 0 ; i < (len / 2) ; i++ )
	{
		tmp = s[i];
		s[i] = s[ len - 1 - i ];
		s[ len - 1 - i ] = tmp;
	}
}




