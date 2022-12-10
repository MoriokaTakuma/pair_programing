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
	int meiro[GYO][RETU];/*迷路データ*/
	int px, py;			 /*プレイヤーの座標*/
	int goal_count;		 /*塗りつぶす床の数*/
	int count;			 /*塗りつぶした床の数*/
	/*メンバ関数*/
	void play_start(void);
	void goal_count_check(void);
	void draw_meiro(void);
	void key_input(void);

private:

};
/*コンストラクタ定義*/
Game::Game() :px(1), py(1), count(0), goal_count(0),
meiro{
	 {1,1,1,1,1,1,1,1,1,1,},
	 {1,0,0,0,0,0,1,0,0,1,},
	 {1,1,1,1,1,0,1,0,0,1,},
	 {1,0,0,0,0,0,1,0,0,1,},
	 {1,0,0,0,1,1,1,0,0,1,},
	 {1,0,0,0,0,0,0,0,0,1,},
	 {1,1,1,1,1,1,1,1,0,1,},
	 {1,1,0,0,0,0,0,1,0,1,},
	 {1,1,0,0,0,0,0,0,0,1,},
	 {1,1,1,1,1,1,1,1,1,1,}, }
{};
/*デストラクタ定義*/
Game::~Game()//デストラクタ
{
	std::cout << "クリア" << std::endl;
}



//
class Title : public Game
{
public:
	Title();    //コンストラクタ
	~Title();   //デストラクタ
	/*メンバ変数*/
	int title[GYO][RETU];/*迷路データ*/
	/*メンバ関数*/
	void draw_title(void);
	void key_input_t(void);

private:

};

Title::Title() :

	title{
   {1,1,1,0,0,1,1,0,0,0,},
   {1,0,0,0,0,1,0,1,0,0,},
   {0,1,2,2,2,1,1,2,2,2,},
   {0,0,1,2,0,1,0,1,2,0,},
   {1,1,1,2,6,1,0,1,2,0,},
   {0,0,0,0,0,0,0,0,0,0,},
   {0,0,0,0,0,0,0,0,0,0,},
   {0,0,0,0,5,0,5,0,0,0,},
   {0,0,0,4,0,0,3,0,0,0,},
   {0,0,0,0,4,3,0,0,0,0,}, }
{}

Title::~Title()
{
}