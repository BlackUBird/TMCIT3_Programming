/*
	5人の学生を身長/名前の昇順にソートするプログラム
	最終更新	:2020/01/12
*/
/*
	関数「swap_Student」について
	宣言	void swap_Student(Student *x,Student *y);
	引数	*x,*y	:入れ替える構造体へのポインタを受けます。
	戻り値	ありません。
	解説	受けた構造体を入れ替えます。
			Student構造体同士を入れ替えていることができます。
			使用するにあたっては以下の構造体を宣言してください。
				typedef struct{
					char	name[NAME_LEN];	//名前
					int		height;			//身長
					float	weight;			//体重
					long	schols;			//奨学金
				} Student;
				
	関数「sort」について
	宣言	void sort(Student a[],int n);
	引数	a[]		:ソートする構造体を受けます。
			n		:構造体配列の要素数を受けます。
	戻り値	ありません。
	解説	受けた配列を身長または名前の昇順にソートします。
			1キーを押せば身長、2キーを押せば名前の順番でソート、
			それ以外のキーが押されたら失敗を返します。
			使用するにあたっては以下の構造体を宣言してください。
				typedef struct{
					char	name[NAME_LEN];	//名前
					int		height;			//身長
					float	weight;			//体重
					long	schols;			//奨学金
				} Student;
	
	メイン関数について
	概略	関数「sort」の動作確認。
	解説	学生のステータスを入力し、ソートして、結果を表示します。
*/
/*
	関数の実態
*/
/*
	5人の学生を身長/名前の昇順にソート
*/
#include <stdio.h>

#define NUMBER		5	//学生の人数
#define NAME_LEN	64	//名前の文字数

/*学生を表す構造体*/
typedef struct{
	char	name[NAME_LEN];	//名前
	int		height;			//身長
	float	weight;			//体重
	long	schols;			//奨学金
} Student;

/*xおよびyが指す学生を交換*/
void swap_Student(Student *x,Student *y)
{
	Student temp = *x;
	*x = *y;
	*y = temp;
}

/*学生の配列aの先頭n個の要素を指定された大小関係に基づいて昇順にソート*/
void sort(Student a[],int n)
{
	//ソート方法指定
	int sel;
	printf("どの大小関係に基づいてソートしますか?\n");
	printf("1:身長,2:名前\n");
	scanf_s("%d",&sel);

	//ソート
	int i,j;	//ループ用
	for( i = 0 ; i < (n - 1) ; i++ )
		for( j = (n - 1) ; j > i ; j-- )
			if( sel == 1 && a[j-1].height		> a[j].height ||
				sel == 2 && a[j-1].name[0]	> a[j].name[0] )
				swap_Student(&a[j-1],&a[j]);

	switch(sel)
	{
	case 1:
		puts("身長順にソートしました。");	break;
	case 2:
		puts("名前順にソートしました。");	break;
	default:
		puts("ソートに失敗しました。");		break;
	}
}

//メイン関数
int main(void)
{
	int i;
	Student std[NUMBER] = {0};

	//入力
	puts("学生の、名前、身長、体重、奨学金を入力してください");
	for( i = 0 ; i < NUMBER ; i++ )
	{
		printf("名　前:");	scanf("%s",&std[i].name);
		printf("身　長:");	scanf("%d",&std[i].height);
		printf("体　重:");	scanf("%f",&std[i].weight);
		printf("奨学金:");	scanf("%ld",&std[i].schols);
	}

	//ソート
	sort(std,NUMBER);

	//ソート結果表示
	for( i = 0 ; i < NUMBER ; i++ )
		printf("%-8s %6d%6.1f%7ld\n"
			,std[i].name,std[i].height,std[i].weight,std[i].schols);

	return 0;
}

