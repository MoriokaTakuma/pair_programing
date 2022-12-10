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
	int meiro[GYO][RETU] = { { 1,1,1,1,1,1,1,1,1,1, },
							 { 1,0,0,0,0,0,1,0,0,1, },
							 { 1,1,1,1,1,0,1,0,0,1, },
							 { 1,0,0,0,0,0,1,0,0,1, },
							 { 1,0,0,0,1,1,1,0,0,1, },
							 { 1,0,0,0,0,0,0,0,0,1, },
							 { 1,1,1,1,1,1,1,1,0,1, },
							 { 1,1,0,0,0,0,0,1,0,1, },
							 { 1,1,0,0,0,0,0,0,0,1, },
							 { 1,1,1,1,1,1,1,1,1,1, }, };/*���H�f�[�^*/
	int px, py;			 /*�v���C���[�̍��W*/
	int goal_count;		 /*�h��Ԃ����̐�*/
	int count;			 /*�h��Ԃ������̐�*/
	/*�����o�֐�*/
	void play_start(void);
	void goal_count_check(void);
	virtual void draw_meiro(void);
	virtual void key_input(void);

private:

};
/*�R���X�g���N�^��`*/
Game::Game() 
{
	px = 1;
	py = 1;
	count = 0;
	goal_count = 0;
};
/*�f�X�g���N�^��`*/
Game::~Game() //�f�X�g���N�^
{
	//std::cout << "�N���A" << std::endl;
}



class Title : public Game
{
public:
	Title();    //�R���X�g���N�^
	~Title();   //�f�X�g���N�^
	/*�����o�ϐ�*/
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
   {0,0,0,0,4,3,0,0,0,0,}, };/*���H�f�[�^*/
	/*�����o�֐�*/
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
							  { 1,1,1,1,1,1,1,1,1,1, }, };/*���H�f�[�^*/

	void draw_meiro(void) {
		int x, y;
		for (y = 0; y < GYO; y++)
		{
			for (x = 0; x < RETU; x++)
			{
				if (x == px && y == py)     //�v���C���[�̏ꏊ        
				{
					meiro2[y][x] = 2;        //�h��Ԃ�    
					count++;                //�h���������J�E���g
					printf("�l");           //�v���C���[ 
				}
				else if (meiro2[y][x] == 0)std::cout << "�@";//�h��Ԃ��̎��
				else if (meiro2[y][x] == 1)std::cout << "��";
				else if (meiro2[y][x] == 2)std::cout << "��";
			}
			std::cout << std::endl;
		}
		std::cout << "move:��������&restart:ESC" << std::endl; //�������];
	}
};