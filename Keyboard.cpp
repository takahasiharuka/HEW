
//このエラーの原因は、「Keyboard.」コードのどこかにあります。
//Error	C2027	use of undefined type 'DirectX::Keyboard::Impl'
//Error	C2338	static_assert failed: 'can't delete an incomplete type'

#include "Keyboard.h"

// とりあえずエラーが発生する部分はコメントアウトしておきました。

DirectX::Keyboard::Keyboard() noexcept(false)
{
}

DirectX::Keyboard::Keyboard(Keyboard&& moveFrom) noexcept
{
}

//Keyboard& DirectX::Keyboard::operator=(Keyboard&& moveFrom) noexcept
//{
//	// TODO: insert return statement here
//}

DirectX::Keyboard::~Keyboard()
{
}

//State __cdecl DirectX::Keyboard::GetState() const
//{
//	return State();
//}

void __cdecl DirectX::Keyboard::Reset() noexcept
{
}

bool __cdecl DirectX::Keyboard::IsConnected() const
{
	return false;
}

//void __cdecl DirectX::Keyboard::ProcessMessage(UINT message, WPARAM wParam, LPARAM lParam)
//{
//}
//
//void __cdecl DirectX::Keyboard::SetWindow(ABI::Windows::UI::Core::ICoreWindow* window)
//{
//}

void __cdecl DirectX::Keyboard::KeyboardStateTracker::Update(const State& state) noexcept
{
}

void __cdecl DirectX::Keyboard::KeyboardStateTracker::Reset() noexcept
{
}
