// 更新:
// <memory> にはまだ 6 つのエラーがあります。
// これは理解できません。<memory> は私たちが書いたコードではなく、
// 公式のコードなので、どうしてエラーが発生するのでしょうか?



//まだ 4 つのエラーがあります。エラーの場所はわかりましたが、原因はまだ正確にはわかりません。
//ただし、エラーの原因となっているファイルをコメントアウトすれば、問題は解決するはずです。
//ファイルはおそらく「Unicode」である必要がありますが、「リソース ファイル」以外は UTF - 8 である必要があります。
//また、シェーダーのプロパティを変更することを忘れないでください。


#undef UNICODE

#include <Windows.h>
#include "Keyboard.h"
#include "direct3d.h"

#include "Game.h"
#include "Input.h"

#include "main.h"

#include "Audio.h"
#include "BufferHelpers.h"
#include "CommonStates.h"
#include "DDSTextureLoader.h"
#include "DirectXHelpers.h"
#include "Effects.h"
#include "GamePad.h"
#include "GeometricPrimitive.h"
#include "GraphicsMemory.h"
// 


// マクロ定義
constexpr auto CLASS_NAME = "DX21Smpl";
constexpr auto WINDOW_NAME = "DirectX初期化";

// 関数のプロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//--------------------------------------------------------------------------------------
// エントリポイント＝一番最初に実行される関数
//--------------------------------------------------------------------------------------
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // ウィンドウクラス情報をまとめる
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_CLASSDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = CLASS_NAME;
    wc.hIconSm = NULL;

    RegisterClassEx(&wc);

    // ウィンドウの情報をまとめる
    HWND hWnd = CreateWindowEx(0, CLASS_NAME, WINDOW_NAME, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_WIDTH, SCREEN_HEIGHT, NULL, NULL, hInstance, NULL);
    hWnd = CreateWindowEx(0,	// 拡張ウィンドウスタイル
        CLASS_NAME,				// ウィンドウクラスの名前
        WINDOW_NAME,			// ウィンドウの名前
        WS_OVERLAPPEDWINDOW,	// ウィンドウスタイル
        CW_USEDEFAULT,			// ウィンドウの左上Ｘ座標
        CW_USEDEFAULT,			// ウィンドウの左上Ｙ座標 
        SCREEN_WIDTH,			// ウィンドウの幅
        SCREEN_HEIGHT,			// ウィンドウの高さ
        NULL,					// 親ウィンドウのハンドル
        NULL,					// メニューハンドルまたは子ウィンドウID
        hInstance,				// インスタンスハンドル
        NULL);					// ウィンドウ作成データ

    RECT rc1, rc2;
    GetWindowRect(hWnd, &rc1);
    GetClientRect(hWnd, &rc2);
    int sx = SCREEN_WIDTH;
    int sy = SCREEN_HEIGHT;
    sx += ((rc1.right - rc1.left) - (rc2.right - rc2.left));
    sy += ((rc1.bottom - rc1.top) - (rc2.bottom - rc2.top));
    SetWindowPos(hWnd, NULL, 0, 0, sx, sy, (SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOMOVE));

    // 指定されたウィンドウの表示状態を設定(ウィンドウを表示)
    ShowWindow(hWnd, nCmdShow);
    // ウィンドウの状態を直ちに反映(ウィンドウのクライアント領域を更新)
    UpdateWindow(hWnd);

    // ゲームループに入る前にDirectXの初期化をする
    D3D_Create(hWnd);

    Game game;
    game.Init(hWnd);

    MSG msg;

    // ゲームループ
    while (1)
    {
        // 新たにメッセージがあれば
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            // ウィンドウプロシージャにメッセージを送る
            DispatchMessage(&msg);

            // 「WM_QUIT」メッセージを受け取ったらループを抜ける
            if (msg.message == WM_QUIT) {
                break;
            }
        }
        else
        {
            // ゲーム処理実行
            D3D_StartRender();

            game.Update();
            game.Draw();
        }
    }

    game.Uninit();
    D3D_Release();

    UnregisterClass(CLASS_NAME, hInstance);

    return (int)msg.wParam;
}

//--------------------------------------------------------------------------------------
//ウィンドウプロシージャ
//--------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY: // ウィンドウ破棄のメッセージ
        PostQuitMessage(0); // 「WM_QUIT」メッセージを送る　→　アプリ終了
        break;// 「WM_DESTROY」メッセージを送る

    case WM_CLOSE: // 「x」ボタンが押されたら
    {
        int res = MessageBoxA(NULL, "終了しますか？", "確認", MB_OKCANCEL);
        if (res == IDOK)
        {
            DestroyWindow(hWnd); // 「WM_DESTROY」メッセージを送る
        }
    }
    break;

    case WM_KEYDOWN: //キー入力があったメッセージ
        if (LOWORD(wParam) == VK_ESCAPE) //入力されたキーがESCAPEなら
        {
            PostMessage(hWnd, WM_CLOSE, wParam, lParam); //「WM_CLOSE」を送る
        }

    default:
        // 受け取ったメッセージに対してデフォルトの処理を実行
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }

    return 0;
}
