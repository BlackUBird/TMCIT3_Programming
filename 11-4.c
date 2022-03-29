/*
	文字列を表示する関数
	最終更新	:2020/11/23
*/
/*
	関数「put_string」について
	宣言	void put_string(const char *s);
	概略	文字列sを表示します。
	引数	const char *s
					:表示する文字列を受けます。
	戻り値	ありません。
	解説	受けた文字列を、「putchar」を用いて表示します。
			for文の継続条件はまず、関数strlenで測定した文字列の長さを一文字の長さで割ることで、文字
			列の文字数を測定し、条件としています。
			関数strlenを使うため、本プログラムではヘッダー「strng.h」をインクルードする必要がありま
			す。
	
	メイン関数について
	概略	put_stringの動作確認。
	解説	表示する文字列の入力を行い、put_stringで表示します。
*/
/*
	関数の実態
*/
/*
	文字列の表示
*/
#include <stdio.h>
#include <string.h>

//文字列sを表示する
void put_string(const char *s)
{
	int i;	//ループ用
	
	for( i = 0 ; i < strlen(s)/sizeof(*(s+0)) ; i++ )
	{
		putchar(*(s+i));
	}
}

//メイン関数
int main(void)
{
	char str[128] = "ABCDEFGH";
	char tmp[128];

	printf("str=");	put_string(str);		//strを表示
	
	printf("\ntmp：");	scanf("%s",tmp);	//tmpに入力

	printf("tmp=");	put_string(tmp);		//tmpを表示
	
	puts("");
	
	return 0;
}

