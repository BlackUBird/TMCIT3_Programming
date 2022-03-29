/*
	9-10
*/
/*
	関数「del_digit」について
	宣言	void del_digit(char s[]);
	概略	文字列内の数字文字を消去します。
	引数	s[]	数字文字を削除される文字列を受けます。
	戻り値	ありません。(void型)
	解説	文字列内の数字文字を削除します。その際新たにつくった配列str[128]に、s[]に受けた文字列の文字だけを格納していき、
			最後にs[]の内部をstr[128]に更新していきます。
*/


#include <stdio.h>

//文字列内の数字文字を削除する関数
void del_digit(char s[])
{
	//文字だけを記憶する配列(ピック配列)
	char str[128] = {0};
	//ピック配列操作用
	int a = 0;
	
	//文字列操作用
	int len = 0;
	
	//ループ用
	int i;
	
	//文字だけをピック
	while( s[len] )
	{
		if( (s[len] - '0') > 9 ||
		    (s[len] - '0') < 0 )
		{
			str[a] = s[len];
			a++;
		}
		len++;
	}
	
	//数字文字を削除したものに書き換え
	for( i = 0 ; i <= len ; i++ )
	{
		s[i] = str[i];
	}
}

//メイン関数
int main(void)
{
	//ピックする文字列
	char moji[128];
	
	//文字列を入力
	printf("文字列を入力してください。：");
	scanf("%s",moji);

	//ピック前を表示
	printf("%s\n",moji);

	//ピック
	del_digit(moji);

	//ピック後を表示
	printf("%s\n",moji);

	return 0;
}