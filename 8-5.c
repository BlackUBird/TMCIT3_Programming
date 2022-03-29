/*
	番号を選択し、その番号に合った名前を表示します。
*/
#include <stdio.h>
#include <stdlib.h>

//プレイアデスを識別するための列挙体
enum pleiades { InvalidS, Maia, Electra, Taygete, Alcyone, Calaeno, Sterope, Merope, InvalidE };

//マイア
void maia(void)
{
	puts("マイア");
}
//エレクトラ
void electra(void)
{
	puts("エレクトラ");
}
//ターユゲテー
void taygete(void)
{
	puts("ターユゲテー");
}
//アルキュオネー
void alcyone(void)
{
	puts("アルキュオネー");
}
//ケライノー
void calaeno(void)
{
	puts("ケライノー");
}
//ステロペー
void sterope(void)
{
	puts("ステロペー");
}
//メロペー
void merope(void)
{
	puts("メロペー");
}
//姉妹を選択
enum pleiades select(void)
{
	//選択された番号を記憶
	int tmp;

	//選択します
	do
	{
		printf(" 1:長女,2:次女,3:三女,4:四女,5:五女,6:六女,7:末妹,8:終了\n->");
		scanf("%d",&tmp);
	}while( tmp < Maia || tmp > InvalidE );//1<=tmp<=8を満たさなければ続ける。

	//選択された番号を返却
	return (enum pleiades)tmp;
}
//メイン関数
int main(void)
{
	//enum eto型の変数
	//プレイアデスの誰が選ばれたかを記憶します。
	enum pleiades selected;

	//プレイアデスの誰かを選択し、名前を表示します
	do
	{
		switch( selected = select() )
		{
		case Maia		:
			maia();
			break;
		case Electra	:
			electra();
			break;
		case Taygete	:
			taygete();
			break;
		case Alcyone	:
			alcyone();
			break;
		case Calaeno	:
			calaeno();
			break;
		case Sterope	:
			sterope();
			break;
		case Merope		:
			merope();
			break;		
		}
	}while( selected != InvalidE );//終了が選択されるまで続ける

	return 0;
}
