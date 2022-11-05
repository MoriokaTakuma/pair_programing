

#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

#define GYO  10
#define RETU 10

//迷路データ
int meiro[GYO][RETU] = {
    {1,1,1,1,1,1,1,1,1,1,},
    {1,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,0,0,1,},
    {1,1,1,1,1,1,1,1,1,1,},
};

int px, py;		/* プレイヤーのxy座標 */
int goal_count;	/* 塗りつぶすべき床の数 */
int count;		/* 塗りつぶした床の数 */


void play_start()//スタートに戻る
{
	int x, y;
	count = 0;
	px = 1;
	py = 1;
	for (y = 0; y < GYO; y++)
		for (x = 0; x < RETU; x++)
			if (meiro[y][x] == 2) meiro[y][x] = 0;	/* 塗りつぶし部分をもとに戻す */
}
void key_input(void)
{
	char key;
	while (1) {	/* キーが押されるまで待つ */

		if (kbhit()) {
			key = getch();	/* 入力されたキー番号 */
			break;
		}

		/*if(std::cin.get(key))
		break;*/
	}
	if (key == 72 && meiro[py - 1][px] == 0)			/* ↑キー */
		py--;	/* 上に移動 */

	else if (key == 80 && meiro[py + 1][px] == 0)		/* ↓キー */
		py++;	/* 下に移動 */

	else if (key == 75 && meiro[py][px - 1] == 0)		/* ←キー */
		px--;	/* 左に移動 */

	else if (key == 77 && meiro[py][px + 1] == 0)		/* →キー */
		px++;	/* 右に移動 */

	else if (key == 27)								/* ESCキー */
		play_start();	/* 最初の状態に戻る */

	else											/* 上記以外のキーの場合は */
		key_input();								/* 再度キー入力受付 */
}

int main()
{
    
}
