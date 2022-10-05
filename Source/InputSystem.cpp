#include "Macro.h"
#include "InputSystem.h"

// @third party code - BEGIN
#include <SDL2/SDL.h>
// @third party code - END

KeyboardState::KeyboardState()
	: CurrKeyboardState(SDL_Scancode::SDL_NUM_SCANCODES, 0)
	, PrevKeyboardState(SDL_Scancode::SDL_NUM_SCANCODES, 0)
{
}

KeyboardState::KeyboardState(KeyboardState&& InInstance) noexcept
	: CurrKeyboardState(InInstance.CurrKeyboardState)
	, PrevKeyboardState(InInstance.PrevKeyboardState)
{
}

KeyboardState::KeyboardState(const KeyboardState& InInstance) noexcept
	: CurrKeyboardState(InInstance.CurrKeyboardState)
	, PrevKeyboardState(InInstance.PrevKeyboardState)
{
}

KeyboardState::~KeyboardState()
{
}

KeyboardState& KeyboardState::operator=(KeyboardState&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	CurrKeyboardState = InInstance.CurrKeyboardState;
	PrevKeyboardState = InInstance.PrevKeyboardState;

	return *this;
}

KeyboardState& KeyboardState::operator=(const KeyboardState& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	CurrKeyboardState = InInstance.CurrKeyboardState;
	PrevKeyboardState = InInstance.PrevKeyboardState;

	return *this;
}

void KeyboardState::Update()
{
	const uint8_t* KeyState = SDL_GetKeyboardState(NULL);

	std::memcpy(
		reinterpret_cast<void*>(&PrevKeyboardState[0]),
		reinterpret_cast<const void*>(&CurrKeyboardState[0]),
		static_cast<size_t>(SDL_Scancode::SDL_NUM_SCANCODES)
	);

	std::memcpy(
		reinterpret_cast<void*>(&CurrKeyboardState[0]),
		reinterpret_cast<const void*>(&KeyState[0]),
		static_cast<size_t>(SDL_Scancode::SDL_NUM_SCANCODES)
	);
}

EPressState KeyboardState::GetKeyPressState(uint8_t InKeyCode) const
{
	EPressState PressState = EPressState::None;

	if (IsPressKey(PrevKeyboardState, InKeyCode))
	{
		if (IsPressKey(CurrKeyboardState, InKeyCode))
		{
			PressState = EPressState::Held;
		}
		else
		{
			PressState = EPressState::Released;
		}
	}
	else
	{
		if (IsPressKey(CurrKeyboardState, InKeyCode))
		{
			PressState = EPressState::Pressed;
		}
		else
		{
			PressState = EPressState::None;
		}
	}

	return PressState;
}

bool KeyboardState::IsPressKey(const std::vector<uint8_t>& InKeyboardState, uint8_t InKeyCode) const
{
	return InKeyboardState[InKeyCode] == 0 ? false : true;
}

MouseState::MouseState()
{
	GetCurrentMouseState(PrevCursorPosition, PrevButtonState);
	GetCurrentMouseState(CurrCursorPosition, CurrButtonState);
}

MouseState::MouseState(MouseState&& InInstance) noexcept
	: PrevCursorPosition(InInstance.PrevCursorPosition)
	, PrevButtonState(InInstance.PrevButtonState)
	, CurrCursorPosition(InInstance.CurrCursorPosition)
	, CurrButtonState(InInstance.CurrButtonState)
{
}

MouseState::MouseState(const MouseState& InInstance) noexcept
	: PrevCursorPosition(InInstance.PrevCursorPosition)
	, PrevButtonState(InInstance.PrevButtonState)
	, CurrCursorPosition(InInstance.CurrCursorPosition)
	, CurrButtonState(InInstance.CurrButtonState)
{
}

MouseState::~MouseState()
{
}

MouseState& MouseState::operator=(MouseState&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	PrevCursorPosition = InInstance.PrevCursorPosition;
	PrevButtonState = InInstance.PrevButtonState;
	CurrCursorPosition = InInstance.CurrCursorPosition;
	CurrButtonState = InInstance.CurrButtonState;

	return *this;
}

MouseState& MouseState::operator=(const MouseState& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	PrevCursorPosition = InInstance.PrevCursorPosition;
	PrevButtonState = InInstance.PrevButtonState;
	CurrCursorPosition = InInstance.CurrCursorPosition;
	CurrButtonState = InInstance.CurrButtonState;

	return *this;
}

void MouseState::Update()
{
	PrevCursorPosition = CurrCursorPosition;
	PrevButtonState = CurrButtonState;

	GetCurrentMouseState(CurrCursorPosition, CurrButtonState);
}

EPressState MouseState::GetButtonPressState(const EButtonType& InButtonType) const
{
	EPressState PressState = EPressState::None;

	if (IsPressButton(PrevButtonState, InButtonType))
	{
		if (IsPressButton(CurrButtonState, InButtonType))
		{
			PressState = EPressState::Held;
		}
		else
		{
			PressState = EPressState::Released;
		}
	}
	else
	{
		if (IsPressButton(CurrButtonState, InButtonType))
		{
			PressState = EPressState::Pressed;
		}
		else
		{
			PressState = EPressState::None;
		}
	}

	return PressState;
}

void MouseState::GetCurrentMouseState(Vec2i& OutCursorPosition, uint32_t& OutButtonState)
{
	OutButtonState = SDL_GetMouseState(&OutCursorPosition.x, &OutCursorPosition.y);
}

bool MouseState::IsPressButton(const uint32_t& InButtonState, const EButtonType& InButtonType) const
{
	uint32_t Mask = 0;

	switch (InButtonType)
	{
	case EButtonType::Left:
		Mask = SDL_BUTTON_LMASK;
		break;

	case EButtonType::Right:
		Mask = SDL_BUTTON_RMASK;
		break;

	default:
		ENFORCE_THROW_EXCEPTION("undefined mouse button type");
		break;
	}

	return (InButtonState & Mask) == 0 ? false : true;
}

InputSystem::InputSystem(InputSystem&& InInstance) noexcept
	: KeyboardState_(InInstance.KeyboardState_)
	, MouseState_(InInstance.MouseState_)
{
}

InputSystem::InputSystem(const InputSystem& InInstance) noexcept
	: KeyboardState_(InInstance.KeyboardState_)
	, MouseState_(InInstance.MouseState_)
{
}

InputSystem::~InputSystem()
{
}

InputSystem& InputSystem::operator=(InputSystem&& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	KeyboardState_ = InInstance.KeyboardState_;
	MouseState_ = InInstance.MouseState_;

	return *this;
}

InputSystem& InputSystem::operator=(const InputSystem& InInstance) noexcept
{
	if (this == &InInstance) return *this;

	KeyboardState_ = InInstance.KeyboardState_;
	MouseState_ = InInstance.MouseState_;

	return *this;
}

bool InputSystem::Tick()
{
	bool bIsDetectQuitMessage = false;

	SDL_Event Event;
	while (SDL_PollEvent(&Event))
	{
		if (Event.type == SDL_QUIT)
		{
			bIsDetectQuitMessage = true;
		}
	}

	KeyboardState_.Update();
	MouseState_.Update();

	return bIsDetectQuitMessage;
}