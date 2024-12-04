#include "Game.h"
#include <iostream>
#include <string> 
#include "direct3d.h"
//#include "Input.h"
#include "Keyboard.h"
#include "Audio.h"

int YukaX = YUKA_X; // 現在のYUKA_X
int YukaY = YUKA_Y; // 現在のYUKA_Y
void Game::Init(HWND hWnd) {
	D3D_Create(hWnd);
	srand(GetTickCount());
	//sound.Init();
	//sound.Play(SOUND_LABEL_BGM000);

	player.Init(L"asset/char01.png", 3, 4); //プレイヤーを初期化
	player.SetPos(-100.0f, -154.0f, 0.0f);     //位置を設定
	player.SetSize(45.0f, 60.0f, 0.0f);  //大きさを設定
	player.SetAngle(0.0f);                 //角度を設定
	player.SetColor(1.0f, 1.0f, 1.0f, 1.0f);

	player2.Init(L"asset/char01.png", 3, 4); //プレイヤーを初期化
	player2.SetPos(-90.0f, -174.0f, 0.0f);     //位置を設定
	player2.SetSize(40.0f, 20.0f, 0.0f);  //大きさを設定
	player2.SetAngle(0.0f);                 //角度を設定
	player2.SetColor(1.0f, 1.0f, 1.0f, 0.0f);

	player3.Init(L"asset/char01.png", 3, 4); //プレイヤーを初期化
	player3.SetPos(-110.0f, -164.0f, 0.0f);     //位置を設定
	player3.SetSize(40.0f, 20.0f, 0.0f);  //大きさを設定
	player3.SetAngle(0.0f);                 //角度を設定
	player3.SetColor(1.0f, 1.0f, 1.0f, 0.0f);

	title.Init(L"asset/Title.png");
	title.SetPos(0.0f, 0.0f, 0.0f);
	title.SetSize(640.0f, 480.0f, 0.0f);

	pause.Init(L"asset/haikei.png");
	pause.SetPos(0.0f, 0.0f, 0.0f);
	pause.SetSize(640.0f, 480.0f, 0.0f);
	pauseFg = false;

	background.Init(L"asset/stage.jpg");
	background.SetPos(0.0f, 0.0f, 0.0f);
	background.SetSize(640.0f, 480.0f, 0.0f);
	background.SetAngle(0.0f);
	for (int x = 0; x < STAGE_X; x++) {
		for (int y = 0; y < STAGE_Y; y++) {
			blocks[x][y].Init(L"asset/block.png");//ブロックを初期化
			blocks[x][y].SetPos(BLOCK_SIZE * (x - STAGE_X / 2), y - STAGE_Y - 200, 00.0f);//位置を設定
			blocks[x][y].SetSize(BLOCK_SIZE, BLOCK_SIZE, 0.0f);//大きさを設定
		}
	}
	for (int x = 0; x < YukaX; x++) {
		for (int y = 0; y < YukaY; y++) {
			blocks[x][y].Init(L"asset/block.png");  // ブロックを初期化
			blocks[x][y].SetPos(BLOCK_SIZE * (x - YukaX / 2), y - YukaY - 130, 00.0f); // 位置を設定
			blocks[x][y].SetSize(BLOCK_SIZE, BLOCK_SIZE, 0.0f); // 大きさを設定
			blocks[x][y].SetAngle(0.0f);
		}
	}
	
	scoreboard.Init(L"asset/number.png", 10, 1);
	scoreboard.SetPos(-145.0f, 200.0f, 0.0f);
	scoreboard.SetSize(40.0f, 40.0f, 0.0f);
	score = 0;

	result.Init(L"asset/result1.png");
	result.SetPos(0.0f, 0.0f, 0.0f);
	result.SetSize(640.0f, 480.0f, 0.0f);

	
	
}
// 下にブロックがないときに落下を開始する関数
		
void Game::Update(void) {
	input.Update();
	switch (scene) {
	case 0://タイトル画面
		if (input.GetKeyTrigger(VK_3)) {
			scene = 1;
			
			state = 0;
			score - 0;
		}
		break;
	case 1:
	{

		if (state == 3)
		{
			if (input.GetKeyTrigger(VK_2)) {
				scene = 0;
			}
			return;
		}
		if (pauseFg == true)
		{
			//ポーズ
			if (input.GetKeyTrigger(VK_1)) {
				pauseFg = false;
			}
			//タイトル
			if (input.GetKeyTrigger(VK_2)) {
				pauseFg = false;
				scene = 0;
			}
			return;
		}
		if (input.GetKeyTrigger(VK_1)) {
			pauseFg = true;
			return;
		}
		count++;
		//player.numU++;
		//if (player.numU >= 3) {
			//player.numU = 0;
		//}
		
		// プレイヤーの処理
		DirectX::XMFLOAT3 pos = player.GetPos();
		DirectX::XMFLOAT3 pos2 = player2.GetPos(); // player2 の座標を取得
		DirectX::XMFLOAT3 pos3 = player3.GetPos(); // player2 の座標を取得

		bool blockCollision = false; // player2 とブロックの接触フラグ
		bool blockCollision2 = false; // player2 とブロックの接触フラグ
		// player2 とブロックの衝突判定
		for (int x = 0; x < STAGE_X; x++) {
			for (int y = 0; y < STAGE_Y; y++) {
				if (pos2.x >= blocks[x][y].GetPos().x && pos2.x <= blocks[x][y].GetPos().x + BLOCK_SIZE &&
					pos2.y >= blocks[x][y].GetPos().y - BLOCK_SIZE && pos2.y - 10.0f <= blocks[x][y].GetPos().y) {
					blockCollision = true;
					break;
				}
			}
			if (blockCollision) break;
		}
		//player3とブロックの衝突判定
		for (int x = 0; x < STAGE_X; x++) {
			for (int y = 0; y < STAGE_Y; y++) {
				if (pos3.x >= blocks[x][y].GetPos().x && pos3.x <= blocks[x][y].GetPos().x + BLOCK_SIZE &&
					pos3.y >= blocks[x][y].GetPos().y - BLOCK_SIZE && pos3.y - 10.0f <= blocks[x][y].GetPos().y) {
					blockCollision2 = true;
					break;
				}
			}
			if (blockCollision2) break;
		}
		const int JUMP_COUNT = 30;  // ジャンプのカウント（最大カウント）
		if (!jumpFg && !rakka) {
			bool blockBelow = false; // 足元にブロックがあるかのフラグ
			for (int x = 0; x < STAGE_X; x++) {
				for (int y = 0; y < STAGE_Y; y++) {
					if (pos.x >= blocks[x][y].GetPos().x && pos.x <= blocks[x][y].GetPos().x + BLOCK_SIZE &&
						pos.y - 30.0f <= blocks[x][y].GetPos().y && pos.y - 30.0f >= blocks[x][y].GetPos().y - BLOCK_SIZE) {
						blockBelow = true;
						break;
					}
				}
				if (blockBelow) break;
			}

			if (!blockBelow) {
				pos.y -= GRAVITY * 0.4f; // 重力を適用
			}
		}

		if (input.GetKeyTrigger(VK_SPACE) && rakka == false && !jumpFg) {  // 落下していない場合にジャンプ開始
			jumpFg = true;  // ジャンプ開始
			count = 0;      // カウントをリセット

			// YUKA_XとYUKA_Yを切り替え
			if (YukaX == 8 && YukaY == 1) {
				YukaX = 1; // YUKA_Xを1に
				YukaY = 8; // YUKA_Yを10に
			}
			else {
				YukaX = 8; // YUKA_Xを10に
				YukaY = 1; // YUKA_Yを1に
			}

			// 地面の位置を更新
			// ここで、変更されたYukaX, YukaYに基づいて地面ブロックの配置を更新
			for (int x = 0; x < YukaX; x++) {
				for (int y = 0; y < YukaY; y++) {
					blocks[x][y].SetPos(BLOCK_SIZE * (x - YukaX / 2), BLOCK_SIZE * (y - YukaY / 2) - 130, 00.0f); // 新しい位置を設定
				}
			}
		}

		if (jumpFg) {
			if (count < JUMP_COUNT) {
				pos.y += JUMP_HEIGHT; // player のジャンプ上昇
				pos2.y = pos.y - 20.0f; // player2 のジャンプ上昇（player より -20）
				pos3.y = pos.y - 20.0f; // player3 のジャンプ上昇（player より -20）
				count++;
			}
			if (count == JUMP_COUNT) {
				jumpFg = false; // ジャンプ終了
				rakka = true;   // 落下開始
			}
		}


		if (rakka) {
			pos.y -= GRAVITY * 0.4f;  // player の重力による落下
			pos2.y -= GRAVITY * 0.4f;
			pos3.y -= GRAVITY * 0.4f;
			pos2.y = pos.y - 20.0f;   // player2 の位置も player より -20 に設定
			pos3.y = pos.y - 20.0f;   // player3 の位置も player より -20 に設定
			// player1 の着地判定
			bool blockBelow = false;
			for (int x = 0; x < STAGE_X; x++) {
				for (int y = 0; y < STAGE_Y; y++) {
					if (pos.x >= blocks[x][y].GetPos().x && pos.x <= blocks[x][y].GetPos().x + BLOCK_SIZE &&
						pos.y >= blocks[x][y].GetPos().y - BLOCK_SIZE && pos.y - 50.0f <= blocks[x][y].GetPos().y) {
						blockBelow = true;
						rakka = false;
						pos.y = blocks[x][y].GetPos().y + 50.0f; // player の位置合わせ
						pos2.y = pos.y - 20.0f; // player2 の位置を player から -20 に設定
						pos3.y = pos.y - 20.0f; // player3 の位置を player から -20 に設定
						break;
					}
				}
				if (!rakka) break;
			}

			if (!blockBelow) {
				rakka = true; // 足元にブロックがなければ落下継続
			}
		}
		// ブロック接触による左右制限の追加
		
		
		// 横方向の移動制限
		// A, D キーの処理制限
		if (!blockCollision && input.GetKeyPress(VK_D)) {
			pos.x += 0.6f; // player を右に移動
			pos2.x += 0.6f; // player2 を右に移動
			pos3.x += 0.6f; // player3 を右に移動
		}

		// Aキーの動作制限（左移動）
		// Aキーの動作制限（左移動）
		if(!blockCollision2 && input.GetKeyPress(VK_A)) {
			pos.x -= 0.6f; // player を右に移動
			pos2.x -= 0.6f; // player2 を右に移動
			pos3.x -= 0.6f; // player3 を右に移動
		}
		// player2 と player3 の x 座標を更新
		pos2.x = pos.x + 10.0f; // player2 は player の x + 10
		pos2.y = pos.y - 2.0f; // player2 は player の y - 20

		pos3.x = pos.x - 10.0f; // player3 は player の x - 10
		pos3.y = pos.y - 2.0f; // player3 は player の y - 10
		// 画面外に行かないように位置を制限
		if (pos.x < SCREEN_LEFT) pos.x = SCREEN_LEFT;
		if (pos.x > SCREEN_RIGHT) pos.x = SCREEN_RIGHT;
		if (pos.y < SCREEN_BOTTOM) pos.y = SCREEN_BOTTOM;
		if (pos.y > SCREEN_TOP) pos.y = SCREEN_TOP;
		
		if (pos2.x < SCREEN_LEFT) pos2.x = SCREEN_LEFT;
		if (pos2.x > SCREEN_RIGHT) pos2.x = SCREEN_RIGHT;
		if (pos2.y < SCREEN_BOTTOM) pos2.y = SCREEN_BOTTOM;
		if (pos2.y > SCREEN_TOP) pos2.y = SCREEN_TOP;
		
		if (pos3.x < SCREEN_LEFT) pos3.x = SCREEN_LEFT;
		if (pos3.x > SCREEN_RIGHT) pos3.x = SCREEN_RIGHT;
		if (pos3.y < SCREEN_BOTTOM) pos3.y = SCREEN_BOTTOM;
		if (pos3.y > SCREEN_TOP) pos3.y = SCREEN_TOP;
		
		// 座標を設定
		player.SetPos(pos.x, pos.y, pos.z);
		player2.SetPos(pos2.x, pos2.y, pos2.z);
		player3.SetPos(pos3.x, pos3.y, pos3.z);
		
	}
	break;
	case 2:

		if (input.GetKeyTrigger(VK_3)) {
			scene = 0;
		}
		break;
	}
}
void Game::Draw(void) {
	D3D_StartRender();

	switch (scene) {
	case 0:
		title.Draw();
		break;
	case 1:
	{
		
		background.Draw();
		player.Draw();
		player2.Draw();
		player3.Draw();
		//ブロックを表示
		for (int x = 0; x < STAGE_X; x++) {
			for (int y = 0; y < STAGE_Y; y++) {
				blocks[x][y].Draw();
			}
		}
		
		DirectX::XMFLOAT3 pos = scoreboard.GetPos();
		DirectX::XMFLOAT3 size = scoreboard.GetSize();
		int keta = 0;
		do {
			scoreboard.numU = score % (int)pow(10, keta + 1) / (int)pow(10, keta);
			scoreboard.SetPos(pos.x - size.x * keta, pos.y, pos.z);
			scoreboard.Draw();
			keta++;
		} while (score >= (int)pow(10, keta));
		scoreboard.SetPos(pos.x, pos.y, pos.z);
		if (pauseFg == true) {
			pause.Draw();
		}
	}
	break;

	case 2:
		result.Draw();
		DirectX::XMFLOAT3 pos = { 0,0,0 };
		DirectX::XMFLOAT3 size = scoreboard.GetSize();
		int keta = 0;
		do {
			scoreboard.numU = score % (int)pow(10, keta + 1) / (int)pow(10, keta);
			scoreboard.SetPos(pos.x - size.x * keta, pos.y, pos.z);
			scoreboard.SetColor(1.0f, 1.0f, 1.0f, 1.0f);
			scoreboard.Draw();
			keta++;
		} while (score >= (int)pow(10, keta));
		
		if (pauseFg == true) {
			pause.Draw();
		}
		
		break;

	}
	
	D3D_FinishRender();
}

void Game::Uninit(void) {
	player.Uninit();
	player2.Uninit();
	player3.Uninit();
	background.Uninit();
	scoreboard.Uninit();
	//ef.Uninit();
	//ブロックを終了
	for (int x = 0; x < STAGE_X; x++) {
		for (int y = 0; y < STAGE_Y; y++) {
			blocks[x][y].Uninit();
		}
	}
	title.Uninit();
	result.Uninit();
	pause.Uninit();
	//sound.Uninit();
	D3D_Release();
}
