/*
	課題12-2のプログラム
	最終更新	:2021/01/11
*/
/*
	関数「hiroko」について
	宣言	void hiroko(Student *std);
	概略	学生のステータス(身長、体重)を、条件によって、更新します。
	引数	*std	:参照する学生のステータスへのポインタです。
	戻り値	ありません。
	解説	超　能　力　を　も　っ　た　ひ　ろ　子　さ　ん　。
			受けた学生のステータスの内、身長と体重を参照し、「身長が180未満」なら
			180に、「体重が80より大きい」なら80に、それぞれ更新します。
	
	メイン関数について
	概略	関数「hiroko」の動作確認。
	解説	学生のステータスをキーボードから入力し格納します。
*/
/*
	関数の実態
*/
/*
	超能力をもったひろ子さん（構造体にtypedef名を導入）	
*/
#include <stdio.h>

#define NAME_LEN 64		/*名前の文字数*/

/*===学生を表す構造体===*/
typedef struct student{
	char	name[NAME_LEN];	/*名前*/
	int		height;			/*身長*/
	float	weight;			/*体重*/
	long	schols;			/*奨学金*/
} Student;

/*--- stdが指す学生の身長を180cmまで伸ばして体重を80kgまで減らす ---*/
void hiroko(Student *std)
{
	if(std->height < 180)	std->height = 180;
	if(std->weight > 80)	std->weight =  80;
}

//メイン関数
int main(void)
{
	Student sanaka;

	printf("氏　名：");	scanf("%s",sanaka.name);
	printf("身　長：");	scanf("%d",&sanaka.height);
	printf("体　重：");	scanf("%f",&sanaka.weight);
	printf("奨学金：");	scanf("%ld",&sanaka.schols);

	hiroko(&sanaka);

	printf("氏　名 ＝ %s\n",sanaka.name);
	printf("身　長 ＝ %d\n",sanaka.height);
	printf("体　重 ＝ %.1f\n",sanaka.weight);
	printf("奨学金 ＝ %ld\n",sanaka.schols);

	return 0;
}

