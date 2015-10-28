#pragma once
#include "Engine/Math/Vector2Int.hpp"

class XInputController;

class InputSystem
{
public:
	InputSystem(void* hWnd);
	~InputSystem();

	void Update(float deltaTime);
	void AdvanceFrameNumber();
	void SetKeyDownStatus(unsigned char keyCode, bool isDown);
	bool IsKeyDown(unsigned char keyCode);
	bool WasKeyJustPressed(unsigned char keyCode);
	void HideMouseCursor();
	void ShowMouseCursor();
	Vector2Int GetDeltaMouse();
	Vector2Int GetMousePos();
	void SetCursorPosition(Vector2Int newPosition);
	bool HasFocus();

	static InputSystem* instance;
	XInputController* m_controllers[4];

private:
	static const int NUM_KEYS = 256;
	static const int MAX_CONTROLLERS = 3;
	static const int SNAP_BACK_X = 800;
	static const int SNAP_BACK_Y = 600;

	bool m_isKeyDown[NUM_KEYS];
	bool m_isCursorVisible;
	bool m_hasFocus;
	int m_frameNumberKeyLastChanged[NUM_KEYS];
	int m_frameCounter;
	Vector2Int m_cursorDelta;
	Vector2Int m_cursorPosition;
	void* m_hWnd;
};
