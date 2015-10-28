#include "Engine/Input/InputSystem.hpp"
#include "Engine/Input/XInputController.hpp"
#include "Engine/Math/Vector2Int.hpp"
InputSystem* InputSystem::instance = nullptr;


InputSystem::InputSystem(void* hWnd)
: m_frameCounter(0)
, m_cursorDelta(0, 0)
, m_cursorPosition(0, 0)
, m_isCursorVisible(false)
, m_hasFocus(false)
, m_hWnd(hWnd)
{
	m_controllers[0] = new XInputController(0);
	m_controllers[1] = new XInputController(1);
	m_controllers[2] = new XInputController(2);
	m_controllers[3] = new XInputController(3);

	//Initialize all keys to up
	for (int keyIndex = 0; keyIndex < NUM_KEYS; ++keyIndex)
	{
		m_isKeyDown[keyIndex] = false;
		m_frameNumberKeyLastChanged[keyIndex] = m_frameCounter;
	}
	ShowCursor(TRUE);
}

InputSystem::~InputSystem()
{
	for (int i = 0; i < MAX_CONTROLLERS; i++)
	{
		delete m_controllers[i];
	}
}

void InputSystem::Update(float deltaTime)
{
	for (int i = 0; i < MAX_CONTROLLERS; i++)
	{
		m_controllers[i]->Update(deltaTime);
	}

	HWND hWnd = static_cast<HWND>(m_hWnd);
	m_hasFocus = hWnd == GetFocus();

	if (m_hasFocus)
	{
		POINT cursorPos;
		BOOL success = GetCursorPos(&cursorPos);
		if (success)
		{
			m_cursorPosition = Vector2Int(cursorPos.x, cursorPos.y);
			m_cursorDelta.x = cursorPos.x - SNAP_BACK_X;
			m_cursorDelta.y = cursorPos.y - SNAP_BACK_Y;
			if (!m_isCursorVisible)
			{
				SetCursorPos(SNAP_BACK_X, SNAP_BACK_Y);
			}
		}
	}
}

bool InputSystem::IsKeyDown(unsigned char keyCode)
{
	return m_isKeyDown[keyCode];
}

bool InputSystem::WasKeyJustPressed(unsigned char keyCode)
{
	return (m_isKeyDown[keyCode] && (m_frameNumberKeyLastChanged[keyCode] == m_frameCounter));
}

void InputSystem::HideMouseCursor()
{
	ShowCursor(FALSE);
	m_isCursorVisible = false;
}

void InputSystem::ShowMouseCursor()
{
	ShowCursor(TRUE);
	m_isCursorVisible = true;
}

Vector2Int InputSystem::GetDeltaMouse()
{
	return m_cursorDelta;
}

Vector2Int InputSystem::GetMousePos()
{
	return m_cursorPosition;
}

void InputSystem::SetCursorPosition(Vector2Int newPosition)
{
	SetCursorPos(newPosition.x, newPosition.y);
}

bool InputSystem::HasFocus()
{
	return m_hasFocus;
}

void InputSystem::AdvanceFrameNumber()
{
	m_frameCounter++;
}

void InputSystem::SetKeyDownStatus(unsigned char keyCode, bool isNowDown)
{
	//If we are getting a keyboard repeat, ignore it when updating "just pressed" values.
	if (m_isKeyDown[keyCode] != isNowDown)
	{
		m_frameNumberKeyLastChanged[keyCode] = m_frameCounter;
	}
	m_isKeyDown[keyCode] = isNowDown;
}
