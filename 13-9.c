/*
	ファイル内の英大文字を英小文字にしてコピーする関数
	最終更新	:
*/
/*
	関数「komoji_to_OOMOJI」について
	宣言	int	komoji_to_OOMOJI(int c);
	概略	小文字を大文字にして返します
	引数	int	c	:大文字に変換する小文字
	戻り値	(c - 'a') + 'A'
					:大文字にしたもの
	解説	　文字cを対応する大文字にして返します。
			　引数が小文字以外の時の動作は保証されません。
			　
	メイン関数について
	概略	英大文字を英小文字にする
	解説	　ファイルsfp内の文字をファイルdfpに書き込みます。その際、英小文字は
			英大文字になります。
*/
/*
	関数の実態
*/
/*
	ファイル内の英小文字を英大文字にしてコピーする
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	komoji_to_OOMOJI(int c)
{
	return (c - 'a') + 'A';
}

int main(void)
{
	int		ch;
	FILE	*sfp;					//コピー元ファイル
	FILE	*dfp;					//コピー先ファイル
	char	sname[FILENAME_MAX];	//コピー元ファイル名
	char	dname[FILENAME_MAX];	//コピー先ファイル名

	printf("コピー元ファイル名：");	scanf("%s",sname);
	printf("コピー先ファイル名：");	scanf("%s",dname);

	if( (sfp =  fopen(sname,"r")) == NULL )
	{
		puts("コピー元ファイルをオープンできませんでした。");
	}
	else
	{
		if( (dfp = fopen(dname,"w")) == NULL )
		{
			puts("コピー先ファイルをオープンできませんでした。");
		}
		else
		{
			while( (ch = fgetc(sfp)) != EOF )
			{
				if( ch < 'z' && ch > 'a' )
				{
					ch = komoji_to_OOMOJI(ch);
				}
				fputc(ch,dfp);
			}
			fclose(dfp);
		}
		fclose(sfp);
	}

	system("pause");
	return 0;
}
