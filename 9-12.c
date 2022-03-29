/*
	9-12
*/
/*
	関数「rev_strings」について
		宣言	void rev_strings(char s[][128],int n);
		概略	受け取った文字列の配列に格納されている文字列の文字の並びを反転します。
		引数	s[][128]	:表示される文字列を受けます。
				n			:受けた配列に文字列はいくつ格納されているかを受けます。
		戻り値	ありません。(void型)
		解説	受け取った文字列の配列に格納されている、n個の文字列の文字の並びを反転します。
				s[][128]に受け取る文字列配列内の文字列の個数と、nに受け取る値は同じでなければなりません。
*/

#include <stdio.h>

//文字列の並びを反転する関数
void rev_strings(char s[][128],int n)
{
	//文字列操作用	
	int len;
	
	//文字列入れ替えの際に仮に記憶する変数
	int tmp = 0;
	
	//ループ用
	int i,j;
	
	//文字列を入れ替え
	for( i = 0 ; i < n ; i++ )
	{
		//文字列操作用変数を初期化
		len = 0;

		//文字列の長さを取得
		while( s[ i ][ len ] )
		{
			len++;
		}

		//文字列を反転
		for( j = 0 ; j < (len/2) ; j++ )
		{
			tmp = s[ i ][ j ];
			s[ i ][ j ] = s[ i ][ len - j - 1 ];
			s[ i ][ len - j - 1 ] = tmp;
		}
	}
}

//メイン関数
int main(void)
{
	//文字列の数を記憶
	int N;

	//文字列を記憶
	char moji[][128] = {0};

	//ループ用
	int i;

	//入力する文字列の数を入力
	printf("文字列はいくつですか？：\n");
	scanf("%d",&N);
	

	//文字列を入力
	printf("文字列を入力してください。:");
	for( i = 0 ; i < N ; i++ )
	{
		scanf("%s",moji[i]);
	}
	
	//文字列を反転
	rev_strings(moji,N);
	
	//反転後の文字列を表示
	printf("反転しました。\n");
	for( i = 0 ; i < N ; i++ )
	{
		printf("%s\n",moji[i]);
	}

	return 0;
}