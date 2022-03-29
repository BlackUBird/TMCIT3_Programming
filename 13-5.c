/*
	前回のプログラム実行時の日付と時刻を表示するプログラム
	最終更新	:2021/02/02
*/
/*
	関数「get_data」について
	宣言	void get_data(void);
	概略	前回の日付・時刻・気分を取得、表示
	引数	ありません。
	戻り値	ありません。
	解説	　前回の日付・時刻・気分が記録されているファイルを「fopen」の"r"で
			開き、ファイルがなければ"本プログラムを実行するのは初めてですね。"
			と表示、あれば前回の日付・時刻・気分を「fprintf」で取得し表示します。
			その際、前回の気分が「最高!!」(!は半角)の場合、日付・時刻を全て99に
			して、表示します。
			気分が「最高!!」(!は半角)であったかを判断する際に「strcmp」を用いて
			いるため、ヘッダーファイル「string.h」のインクルードが必要です。
	
	関数「put_data」について
	宣言	void put_data(void);
	概略	現在の日付・時刻・気分を書き込む
	引数	ありません。
	戻り値	ありません。
	解説	　前回の日付・時刻・気分が記録されているファイルを「fopen」の"w"で
			開き、ファイルが開けなければ"ファイルをオープンできませんでした。"
			と表示、開ければ現在の日付・時刻・気分を「fscanf」で書き込みます。
	
	メイン関数について
	概略	「get_data」、「put_data」の動作確認
	解説	　上記2種の関数の呼び出しのみ行っています。
*/
/*
	関数の実態
*/
/*
	前回のプログラム実行時の日付と時刻を表示する
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data_file[] ="datetime.txt";

/*前回の日付・時刻・気分を取得・表示*/
void get_data(void)
{
	FILE *fp;		//ファイル用ポインタ

	if((fp = fopen(data_file,"r")) == NULL)
	{
		printf("本プログラムを実行するのは初めてですね。\n");
	}
	else
	{
		//前回実行時の日付・時刻・気分を保持する変数
		int		year,month,day,h,m,s;
		char	kibun[128];

		//前回の日付・時刻・気分を取得、表示
		fscanf(fp,"%d %d %d %d %d %d %s",&year,&month,&day,&h,&m,&s,kibun);

		//もし前回の気分が「最高!!」だったら
		if( strcmp(kibun,"最高!!") == 0)
		{
			year = month = day = h = m = s = 99;
		}

		//書き込み
		printf("前回は%d年%d月%d日%d時%d分%d秒で、気分は%sでした。\n",
			year,month,day,h,m,s,kibun);

		fclose(fp);	//ファイルクローズ
	}
}

/*今回の日付・時刻・気分を書き込む*/
void put_data(void)
{
	FILE *fp;	//ファイル用ポインタ
	time_t current = time(NULL);			//現在の暦時刻
	struct tm *timer = localtime(&current);	//要素別の時刻(地方時)

	char kibun[128];	//現在の気分

	//ファイルを開く
	if( (fp = fopen(data_file,"w")) == NULL )	//開けなければ何もしない
	{
		printf("ファイルをオープンできませんでした。\n");
	}
	else	//開けたら現在の日付・時刻・気分を書き込む
	{
		//現在の気分を入力
		printf("現在の気分は：");	scanf("%s",kibun);

		//書き込む
		fprintf(fp,"%d %d %d %d %d %d %s",
			timer->tm_year + 1900,	timer->tm_mon + 1,	timer->tm_mday,
			timer->tm_hour,			timer->tm_min,		timer->tm_sec,
			kibun);

		fclose(fp);
	}
}

int main(void)
{
	get_data();

	put_data();

	system("pause");
	return 0;
}

