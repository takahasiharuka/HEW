#pragma once
#include <vector>
#include <utility>
#include <Windows.h>
#include "Input.h"

class Game
{
private:
	Input keyInput;

	void StartGame();
	void EndGame();
	void ResetGame();

public:
	void Init(HWND hWnd); //初期化
	void Update(void);    //更新
	void Draw();          //描画
	void Uninit();        //終了
};

