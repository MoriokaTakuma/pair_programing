#include"class.h"

//最初の状態に戻す
void Game::play_start(void)
{
    int x, y;

    count = 0;

    px = 1;

    py = 1;

    for (y = 0; y < GYO; y++)
    {
        for (x = 0; x < RETU; x++)
        {
            if (meiro[x][y] == 2)meiro[x][y] = 0; //床が塗られて(x,y = 2)たら元に戻す(0に戻す)
        }
    }
}

/* 塗りつぶすべき床の数をカウントする */
void Game::goal_count_check(void)
{
    int x, y;
    goal_count = 0;
    for (y = 0; y < GYO; y++)
        for (x = 0; x < RETU; x++)
            if (meiro[y][x] == 0) goal_count++;		/* 移動可能な床の数をカウント */
}

//迷路を書く
void Game::draw_meiro(void)
{
    int x, y;
    for (y = 0; y < GYO; y++)
    {
        for (x = 0; x < RETU; x++)
        {
            if (x == px && y == py)     //プレイヤーの場所        
            {
                meiro[y][x] = 2;        //塗りつぶし    
                count++;                //塗った床をカウント
                printf("人");           //プレイヤー 
            }
            else if (meiro[y][x] == 0)std::cout << "　";//塗りつぶしの種類
            else if (meiro[y][x] == 1)std::cout << "■";
            else if (meiro[y][x] == 2)std::cout << "○";
        }
        std::cout << std::endl;
    }
    std::cout << "move:←↑→↓&restart:ESC" << std::endl; //操作説明

}
/* キー入力判定 */
void Game::key_input(void)
{
    int key;
    while (1) {	/* キーが押されるまで待つ */
        if (_kbhit()) {
            key = _getch();	/* 入力されたキー番号 */
            break;
        }
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
    Game* pgame = new Game;

    pgame->goal_count_check();

    /* ゲームループ */
    while (1) {
        system("cls");	/* コンソール画面をクリア */
        pgame -> draw_meiro();	/* 迷路を表示 */

        if (pgame->count == pgame->goal_count) {	/* 床を全て塗りつぶしたかのチェック */
            std::cout << "全て塗りました！" << std::endl;
            delete pgame;
            if (pgame != nullptr)
            {
                pgame = nullptr;
            }
            break;
            pgame->play_start();
        }

        pgame->key_input();		/* キー入力受付 */
    }
    return 0;
}
