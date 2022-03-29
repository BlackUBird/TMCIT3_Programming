/*
	オブジェクトの各メンバをキーボードからの入力し、表示するプログラム
	最終更新	:2020/12/27
*/
/*	
	メイン関数について
	概略	オブジェクトの各メンバをキーボードからの入力し、表示します。
	解説	構造体オブジェクトのメンバを宣言時の初期化ではなく
			キーボード入力によって値を得て、その結果を出力します。
*/
/*
	関数の実態
*/
/*
	オブジェクトの各メンバをキーボードからの入力し、表示する	
*/
#include <stdio.h>

#define NAME_LEN 64		/*名前の文字数*/

/*===学生を表す構造体===*/
struct student{
	char	name[NAME_LEN];	/*名前*/
	int		height;			/*身長*/
	float	weight;			/*体重*/
	long	schols;			/*奨学金*/
};

//メイン関数
int main(void)
{
	struct student takao;

	printf("氏　名：");	scanf("%s",takao.name);
	printf("身　長：");	scanf("%d",&takao.height);
	printf("体　重：");	scanf("%f",&takao.weight);
	printf("奨学金：");	scanf("%ld",&takao.schols);

	printf("氏　名 ＝ %s\n",takao.name);
	printf("身　長 ＝ %d\n",takao.height);
	printf("体　重 ＝ %.1f\n",takao.weight);
	printf("奨学金 ＝ %ld\n",takao.schols);

	return 0;
}

