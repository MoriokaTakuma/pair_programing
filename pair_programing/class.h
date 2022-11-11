#pragma once

#include<iostream>
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

#define GYO  10
#define RETU 10


/*クラス宣言*/
class Game
{
public:
	Game();
	~Game();
	/*メンバ変数*/
	int meiro[GYO][RETU] = { { 1,1,1,1,1,1,1,1,1,1, },
							 { 1,0,0,0,0,0,1,0,0,1, },
							 { 1,1,1,1,1,0,1,0,0,1, },
							 { 1,0,0,0,0,0,1,0,0,1, },
							 { 1,0,0,0,1,1,1,0,0,1, },
							 { 1,0,0,0,0,0,0,0,0,1, },
							 { 1,1,1,1,1,1,1,1,0,1, },
							 { 1,1,0,0,0,0,0,1,0,1, },
							 { 1,1,0,0,0,0,0,0,0,1, },
							 { 1,1,1,1,1,1,1,1,1,1, }, };/*迷路データ*/
	int px, py;			 /*プレイヤーの座標*/
	int goal_count;		 /*塗りつぶす床の数*/
	int count;			 /*塗りつぶした床の数*/
	/*メンバ関数*/
	void play_start(void);
	void goal_count_check(void);
	virtual void draw_meiro(void);
	virtual void key_input(void);

private:

};
/*コンストラクタ定義*/
Game::Game() 
{
	px = 1;
	py = 1;
	count = 0;
	goal_count = 0;
};
/*デストラクタ定義*/
Game::~Game() //デストラクタ
{
	//std::cout << "クリア" << std::endl;
}



class Title : public Game
{
public:
	Title();    //コンストラクタ
	~Title();   //デストラクタ
	/*メンバ変数*/
	int title[GYO][RETU] = 
 { {1,1,1,0,0,1,1,0,0,0,},
   {1,0,0,0,0,1,0,1,0,0,},
   {0,1,2,2,2,1,1,2,2,2,},
   {0,0,1,2,0,1,0,1,2,0,},
   {1,1,1,2,6,1,0,1,2,0,},
   {0,0,0,0,0,0,0,0,0,0,},
   {0,0,0,0,0,0,0,0,0,0,},
   {0,0,0,0,5,0,5,0,0,0,},
   {0,0,0,4,0,0,3,0,0,0,},
   {0,0,0,0,4,3,0,0,0,0,}, };/*迷路データ*/
	/*メンバ関数*/
	void draw_meiro(void)override;
	void key_input(void)override;

private:

};

Title::Title() 
{}

Title::~Title()
{
}


class stage2 : public Game
{

public:
	int meiro2[GYO][RETU] = { { 1,1,1,1,1,1,1,1,1,1, },
							  { 1,0,1,1,1,1,1,1,1,1, },
							  { 1,0,1,1,1,1,1,1,1,1, },
							  { 1,0,0,0,0,0,0,0,0,1, },
							  { 1,0,0,0,0,0,0,0,0,1, },
							  { 1,0,0,0,0,0,0,0,0,1, },
							  { 1,0,0,0,0,0,0,0,0,1, },
							  { 1,0,0,0,0,0,0,0,0,1, },
							  { 1,0,0,0,0,0,0,0,0,1, },
							  { 1,1,1,1,1,1,1,1,1,1, }, };/*迷路データ*/

	void draw_meiro(void) {
		int x, y;
		for (y = 0; y < GYO; y++)
		{
			for (x = 0; x < RETU; x++)
			{
				if (x == px && y == py)     //プレイヤーの場所        
				{
					meiro2[y][x] = 2;        //塗りつぶし    
					count++;                //塗った床をカウント
					printf("人");           //プレイヤー 
				}
				else if (meiro2[y][x] == 0)std::cout << "　";//塗りつぶしの種類
				else if (meiro2[y][x] == 1)std::cout << "■";
				else if (meiro2[y][x] == 2)std::cout << "○";
			}
			std::cout << std::endl;
		}
		std::cout << "move:←↑→↓&restart:ESC" << std::endl; //操作説明];
	}
};