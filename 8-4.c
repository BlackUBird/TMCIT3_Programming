/*
	学生の身長を読み込み、ソートします。
	バブルソートで行いますが、走査を末尾からではなく先頭から行います。
	また、155, 180, 160, 175, 170が入力された場合の繰り返しパスごとの配列のソートの様子は次のようになると考えられます。
	
	[1パス目]
	155 180 160 175 170
	[155 180] 160 175 170
	155 [160 180] 175 170
	155 160 [175 180] 170
	155 160 175 [170 180]
	155 160 175 170 180
	
	[2パス目]
	155 160 175 170 180
	155 [160 175] 170 180
	155 160 [170 175] 180
	155 160 170 [175 180]
	155 160 170 175 180
	
	[3パス目]
	155 160 170 175 180
	155 160 [170 175] 180
	155 160 170 [175 180]
	155 160 170 175 180
	
	[4パス目]
	155 160 170 175 180
	155 160 170 [175 180]
	155 160 170 175 180
*/
#include <stdio.h>

//学生の人数
#define NUMBER 5

//ソートを行う関数
void bsort(int a[],int n)
{
	//ループ用変数
	int i,j;

	//先頭から走査します
	for( i = 1 ; i < NUMBER ; i++ )
	{
		for( j = 0 ; j < (NUMBER-i) ; j++ )
		{
			//もし評価中の値が一つ前の値よりも小さいとき、
			//値を入れ替えます。
			if( a[j] > a[j+1] )
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

//メイン関数
int main(void)
{
	//ループ用
	int i;

	//学生の身長を記憶
	int height[NUMBER] = {0};

	//学生の身長を入力
	printf("%d人の身長を入力してください。\n",NUMBER);
	for( i = 0 ; i < NUMBER ; i++ )
	{
		printf("%2d番：",i+1);
		scanf("%d",&height[i]);
	}

	//ソートします
	bsort(height,NUMBER);

	//ソート結果を表示
	printf("昇順にソートしました。\n");
	for( i = 0 ; i < NUMBER ; i++ )
	{
		printf("%2d番目：%d\n",i+1,height[i]);
	}
	
	return 0;
}