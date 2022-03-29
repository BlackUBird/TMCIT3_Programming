/*
	仮想自動車を移動させるプログラム
	最終更新	:20210119
*/
/*
	割愛
*/
/*
	関数の実態
*/
/*
	自動車の移動
*/

#include <math.h>
#include <stdio.h>

#define sqr(n) ((n) * (n))

/*点の座標を表す構造体*/
typedef struct{
	double	x;	//X座標
	double	y;	//Y座標
} Point;

/*自動車を表す構造体*/
typedef struct{
	Point	pt;		//現在位置
	double	fuel;	//残り燃料
} Car;

/*点paと点pbの距離を返す*/
double distance_of(Point pa,Point pb)
{
	return sqrt(sqr(pa.x - pb.x) + sqr(pa.y - pb.y));
}

/*自動車の現在地と残り燃料を表示*/
void put_info(Car c)
{
	printf("現在座標：(%.2f,%.2f)\n",c.pt.x,c.pt.y);
	printf("残り燃料：%.2fリットル\n",c.fuel);
}

/*cの指す車を目的座標destに移動*/
int move_point(Car *c,Point dest)
{
	double	d = distance_of(c->pt,dest);	/*移動距離*/

	if(d > c->fuel)	/*燃料を超過したら*/
		return 0;	/*移動不可*/

	c->pt = dest;	/*現在位置を更新*/
	c->fuel -= d;	/*残り燃料を移動距離dだけ減らす*/

	return 1;	/*移動成功*/
}

/*cの指す車を移動距離destだけ移動*/
int move_dest(Car *c,Point dest)
{
	double	d = sqrt(sqr(dest.x) + sqr(dest.y)); 	/*移動距離*/

	if(d > c->fuel)	/*燃料を超過したら*/
		return 0;	/*移動不可*/
	
	c->pt.x += dest.x;	/*現在位置を更新*/
	c->pt.y += dest.y;	/*現在位置を更新*/

	c->fuel -= d;	/*残り燃料を移動距離dだけ減らす*/

	return 1;	/*移動成功*/
}

/*車を動かす*/
int move_manager(Car *c)
{
	int	sel;	//分岐用
	Point dest;	//目的地の座標
	int r;		//返却値

	/*移動先指定方法による分岐*/
	printf("移動先の指定方法【座標…1/移動距離…2】:");
	scanf("%d",&sel);

	//移動
	switch(sel)
	{
	case 1:
		printf("目的地のX座標:");	scanf("%lf",&dest.x);
		printf("目的地のY座標:");	scanf("%lf",&dest.y);
		r =  move_point(c,dest);
		break;
	case 2:
		printf("目的地までの距離(X方向):");	scanf("%lf",&dest.x);
		printf("目的地までの距離(Y方向):");	scanf("%lf",&dest.y);
		r = move_dest(c,dest);
		break;
	default:
		r = 0;
		break;
	}
	
	return r;
}

int main(void)
{
	Car mycar = {{0.0 , 0.0} , 90.0};

	while(1)
	{
		int select;
		put_info(mycar);	/*現在位置と残り燃料を表示*/

		printf("移動しますか【Yes…1/No…0】:");
		scanf("%d",&select);
		if(select != 1)	break;

		if( !move_manager(&mycar) )
			printf("移動できません。\n");

		printf("\n");
	}
	
    return 0;
}

