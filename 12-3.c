/*
	演習12-3のプログラム
	最終更新	:2021/01/11
*/
/*
	関数「scan_xyz」について
	宣言	struct xyz scan_xyz();
	概略	int,long,double型のメンバの値を読み込み
			それらをメンバとして持つ構造体を返す関数
	引数	ありません。
	戻り値	a	:入力した値をメンバに持つ構造体を返します。
	解説	int型、long型、double型の値を入力し、それぞれ構造体の対応するメンバ
			に格納していき、その後、構造体をそのまま返します。
			使用するにあたっては次の構造体を宣言しておく必要があります。
				struct xyz{
					int		x;
					long	y;
					double	z;
				};
	
	メイン関数について
	概略	関数「scanf_xyz」の動作確認
	解説	構造体NUMの初期化時に「scan_xyz」を呼び出し、入力された値をそのまま代入して、
			printfで表示・確認を行います。
*/
/*
	関数の実態
*/
/*
	値(int,long,double)をキーボードから読み込み、
	その値をメンバとして持つ構造体を返す関数「scan_xyz」の動作確認
*/
#include <stdio.h>

/*int,long,double型のメンバを持つ構造体*/
struct xyz{
	int		x;
	long	y;
	double	z;
};

/*
	int,long,double型のメンバの値を読み込み
	それらをメンバとして持つ構造体を返す関数
*/
struct xyz scan_xyz(void)
{
	struct xyz a;

	printf("(int型)		x:");	scanf("%d",&a.x);
	printf("(long型)	y:");	scanf("%ld",&a.y);
	printf("(double型)	z:");	scanf("%lf",&a.z);

	return (a);
}

//メイン関数
int main(void)
{
	/*入力されたものを記憶*/
	struct xyz NUM;
	NUM = scan_xyz();

	/*確認(表示)*/
	printf("(int型)		x:%d\n",NUM.x);
	printf("(long型)	y:%ld\n",NUM.y);
	printf("(double型)	z:%lf\n",NUM.z);

	return 0;
}

