

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


//最初の状態に戻す
void play_start(void)
{
    int x, y;

    count = 0;

    px = 1;

    py = 1;

    for (x = 0; x < RETU; x++)
    {
        for (y = 0; y < GYO; y++)
        {
            if (meiro[x][y] == 2)meiro[x][y] = 0; //床が塗られて(x,y = 2)たら元に戻す(0に戻す)
        }
    }
}

//迷路を書く
void draw_meiro(void)
{
    int x, y;
    for (x = 0; x < RETU; x++)      //
    {
        for (y = 0; y < GYO; y++)
        {
            if (x == px && y == py)     //プレイヤーの場所        
            {
                meiro[x][y] = 2;        //塗りつぶし    
                count++;                //塗った床をカウント
                printf("人");           //プレイヤー 
            }
            else if (meiro[x][y] == 0)printf("　");
            else if (meiro[x][y] == 1)printf("■");
            else if (meiro[x][y] == 2)printf("○");
        }
        printf("\n");
    }
    printf("move:←↑→↓&restart:ESC\n"); //操作説明

}


int main()
{
   
}
