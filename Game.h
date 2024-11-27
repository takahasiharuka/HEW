#pragma once
#include <vector>
#include <utility>
#include <Windows.h>
#include "Input.h"
#include"Object.h"

#include"Sound.h"
#define STAGE_X    (100)
#define STAGE_Y    (1)
#define BLOCK_SIZE (10)
#define YUKA_X    (8)
#define YUKA_Y    (1)
class Game
{
private:
	Input keyInput;
	Input input;
	Object player;
	Object player2;
	Object player3;
	Object background;
	Object scoreboard;
	Object blocks[STAGE_X][STAGE_Y];
	Object ef;
	bool isOnBlock = false;
	bool jumpFg = false;
	bool rakka = false;
	const float GRAVITY = 10.0f;  // 重力の設定
	const float JUMP_HEIGHT = 6.0f;  // ジャンプの高さ
	const float JUMP_SPEED_X = 2.0f; // ジャンプ中の横方向の速度
	const int JUMP_COUNT = 30;  // ジャンプのカウント（最大カウント）

	// プレイヤーの大きさ（当たり判定用）
	const float PLAYER_WIDTH = 45.0f;  // プレイヤーの幅
	const float PLAYER_HEIGHT = 60.0f; // プレイヤーの高さ

	// ブロックとの当たり判定用修正
	// 足での着地判定、頭の衝突判定、側面の衝突判定を考慮したコード
	bool blockBelow = false;    // 足元の判定

	bool blockCollision2 = false; // player2 とブロックの接触フラグ
	bool headHit = false;       // 頭での衝突判定
	bool blockRight = false;    // 右側の判定
	bool blockLeft = false;     // 左側の判定

	const float SCREEN_LEFT = -300.0f;   // 左端の座標
	const float SCREEN_RIGHT = 300.0f;  // 右端の座標
	const float SCREEN_BOTTOM = -300.0f; // 下端の座標
	const float SCREEN_TOP = 300.0f;    // 上端の座標
	
	typedef struct
	{
		LPCSTR filename;
		bool bloop;
	}PARAM;

	int data[STAGE_X][STAGE_Y + 3] = {};
	int count = -100;
	int state = 0;//ゲームの状態(0:落下するものがない、１:落下中)
	int score = 0;
	bool effect = false;
	Object pause;//ポーズ画面オブジェクト」
	bool pauseFg = false;//ポーズフラグ
	int scene = 0;
	bool isMovingRight = false;
	Object title;
	Object result;

	void StartGame();
	void EndGame();
	void ResetGame();

public:
	void Init(HWND hWnd); //初期化
	void Update(void);    //更新
	void Draw();          //描画
	void Uninit();        //終了
};

