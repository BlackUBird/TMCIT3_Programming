/*
	オブジェクトの各メンバのアドレスを表示するプログラム
	最終更新	:2020/12/27
*/
/*	
	メイン関数について
	概略	構造体オブジェクトの各メンバのアドレスを表示します
	解説	構造体を用いて宣言・初期化された変数の各メンバのア
			ドレスを表示します。
			takaoの初期化の際メンバweightの初期化子は、教科書
			では「86.2」とdouble型の定数でしたが、メンバweight
			はfloat型で宣言されているため「86.2F」と明示的に
			float型定数としています。
*/
/*
	関数の実態
*/
/*
	オブジェクトの各メンバのアドレスを表示する	
*/
#include <stdio.h>

#define NAME_LEN 64		/*名前の文字数*/

/*===学生を表す構造体===*/
struct student {
	char	name[NAME_LEN];	/*名前*/
	int		height;			/*身長*/
	float	weight;			/*体重*/
	long	schols;			/*奨学金*/
};

//メイン関数
int main(void)
{
	struct student takao = {"Takao", 173, 86.2F};

	printf("氏　名 ＝ %p\n",takao.name);
	printf("身　長 ＝ %p\n",&(takao.height));
	printf("体　重 ＝ %p\n",&(takao.weight));
	printf("奨学金 ＝ %p\n",&(takao.schols));

	return 0;
}
