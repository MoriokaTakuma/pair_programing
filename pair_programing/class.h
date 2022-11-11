#pragma once

#include<iostream>
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

#define GYO  10
#define RETU 10


/*�N���X�錾*/
class Game
{
public:
	Game();
	~Game();
	/*�����o�ϐ�*/
	int meiro[GYO][RETU];/*���H�f�[�^*/
	int px, py;			 /*�v���C���[�̍��W*/
	int goal_count;		 /*�h��Ԃ����̐�*/
	int count;			 /*�h��Ԃ������̐�*/
	/*�����o�֐�*/
	void play_start(void);
	void goal_count_check(void);
	void draw_meiro(void);
	void key_input(void);

private:

};
/*�R���X�g���N�^��`*/
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
/*�f�X�g���N�^��`*/
Game::~Game()//�f�X�g���N�^
{
	std::cout << "�N���A" << std::endl;
}



//
class Title : public Game
{
public:
	Title();    //�R���X�g���N�^
	~Title();   //�f�X�g���N�^
	/*�����o�ϐ�*/
	int title[GYO][RETU];/*���H�f�[�^*/
	/*�����o�֐�*/
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