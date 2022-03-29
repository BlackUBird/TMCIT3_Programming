/*
	9-7
*/
/*
	関数「put_stringn」について
		宣言	put_stringn(const char s[],int n);
		概略	読み込んだ文字列を指定回数、連続で表示します。
		引数	s	:表示される文字列を受けます。
				n	:何回表示するかを受けます。
		戻り値	ありません。(void型)
		解説	読み込んだ文字列を指定回数、改行せずに続けて表示します。
				void型関数となっています。
*/
//文字列をn回続けて表示する関数
void put_stringn(const char s[],int n)
{
	//ループ用
	int i,j;

	//表示
	for( j = 0 ; j < n ; j++ )
	{
		i = 0;
		while( s[i] )
		{
			putchar(s[i++]);
		}
	}
	printf("\n");
}




