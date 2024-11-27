#include "Game.h"
#include <iostream>
#include <string> 
#include "direct3d.h"
//#include "Input.h"
#include "Keyboard.h"
#include "Audio.h"

// ゲームを初期化する
void Game::Init(HWND hWnd)
{
    // DirectX を初期化する
    D3D_Create(hWnd);

    EndGame();
}

// ゲームの状態を更新する
void Game::Update(void)
{
    keyInput.Update(); // キー入力を更新する
}

// ゲームの状態をドロー
void Game::Draw(void)
{
    D3D_StartRender();  // レンダリングを開始

    D3D_FinishRender(); // レンダリングを終了
}

// Uninitialize the game
void Game::Uninit(void)
{
    // UninitSound(); // サウンドを初期化しない
    /*↑↑↑↑↑↑
    これは私の「Sound.cpp」 + 「Sound.h」からの名前ですが、
   「Audio.h」ファイル内の同等のものが何であるかはわかりません。
   (そして、「Audio.h」ファイルの方が間違いなく優れているので、それを使用する必要があります。)*/

    D3D_Release(); // DirectXリソースをリリースする
}

// タイトル画面からゲームを開始する
void Game::StartGame()
{

}

// ゲームを終了する
void Game::EndGame()
{
   
}

// ゲームの状態をリセットする
void Game::ResetGame()
{
  
}
