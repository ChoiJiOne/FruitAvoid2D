#pragma once

#include "Vector.h"

#include <vector>


/**
 * �Է� ���¸� ��Ÿ���ϴ�.
 * --------------------------------------
 * | ���� ������ | ���� ������ | �Է� ���� |
 * --------------------------------------
 * |     0      |     0      | None     |
 * |     0      |     1      | Pressed  |
 * |     1      |     0      | Released |
 * |     1      |     1      | Held     |
 * --------------------------------------
 */
enum class EPressState
{
	None = 0,
	Pressed = 1,
	Released = 2,
	Held = 3
};


/**
 * Ű���� ���¸� ��Ÿ���� Ŭ�����Դϴ�.
 */
class KeyboardState
{
public:
	/**
	 * Ű���� ���¸� ��Ÿ���� Ŭ������ �������Դϴ�.
	 */
	explicit KeyboardState();


	/**
	 * Ű���� ���¸� ��Ÿ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	KeyboardState(KeyboardState&& InInstance) noexcept;


	/**
	 * Ű���� ���¸� ��Ÿ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	KeyboardState(const KeyboardState& InInstance) noexcept;


	/**
	 * Ű���� ���¸� ��Ÿ���� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~KeyboardState();


	/**
	 * Ű���� ���¸� ��Ÿ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	KeyboardState& operator=(KeyboardState&& InInstance) noexcept;


	/**
	 * Ű���� ���¸� ��Ÿ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	KeyboardState& operator=(const KeyboardState& InInstance) noexcept;


	/**
	 * Ű������ ���¸� ������Ʈ�մϴ�.
	 */
	void Update();


	/**
	 * Ű�� �Է� ���¸� ��ȯ�մϴ�.
	 *
	 * @param InKeyCode - Ű�� �Է� ���¸� Ȯ���� Ű �ڵ� ���Դϴ�.
	 *
	 * @return Ű�� ��ư ���¸� ��ȯ�մϴ�.
	 */
	EPressState GetKeyPressState(uint8_t InKeyCode) const;


private:
	/**
	 * Ư�� Ű�� ���ȴ��� Ȯ���մϴ�.
	 *
	 * @param InKeyboardState - �˻縦 ������ Ű������ �����Դϴ�.
	 * @param InKeyCode - �˻縦 ������ Ű�Դϴ�.
	 *
	 * @return ���� Ű�� �����ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsPressKey(const std::vector<uint8_t>& InKeyboardState, uint8_t InKeyCode) const;


private:
	/**
	 * ������Ʈ ������ Ű���� �����Դϴ�.
	 */
	std::vector<uint8_t> PrevKeyboardState;


	/**
	 * ������Ʈ ���� Ű���� �����Դϴ�.
	 */
	std::vector<uint8_t> CurrKeyboardState;
};


/**
 * ���콺�� ���¸� ��Ÿ���� Ŭ�����Դϴ�.
 */
class MouseState
{
public:
	/**
	 * ���콺�� ��ư Ÿ���Դϴ�.
	 */
	enum class EButtonType
	{
		Left = 0,
		Right = 1,
	};


public:
	/**
	 * ���콺 ���¸� ��Ÿ���� Ŭ������ �������Դϴ�.
	 */
	explicit MouseState();


	/**
	 * ���콺 ���¸� ��Ÿ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	MouseState(MouseState&& InInstance) noexcept;


	/**
	 * ���콺 ���¸� ��Ÿ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	MouseState(const MouseState& InInstance) noexcept;


	/**
	 * ���콺�� ��Ÿ���� Ŭ������ �Ҹ����Դϴ�.
	 */
	virtual ~MouseState();


	/**
	 * ���콺 ���¸� ��Ÿ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	MouseState& operator=(MouseState&& InInstance) noexcept;


	/**
	 * ���콺 ���¸� ��Ÿ���� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	MouseState& operator=(const MouseState& InInstance) noexcept;


	/**
	 * ���콺�� ���¸� ������Ʈ�մϴ�.
	 */
	void Update();


	/**
	 * ���콺 ��ư�� �Է� ���¸� ��ȯ�մϴ�.
	 *
	 * @param InKeyType - ���콺 Ű�� Ÿ���Դϴ�.
	 *
	 * @return ���� Ű�� �����ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	EPressState GetButtonPressState(const EButtonType& InKeyType) const;


	/**
	 * ���콺�� ������Ʈ ������ ��ġ�� ��ȯ�մϴ�.
	 *
	 * @return ���콺�� ������Ʈ ������ ��ġ�� ��ȯ�մϴ�.
	 */
	Vec2i GetPrevPosition() const { return PrevCursorPosition; }


	/**
	 * ���콺�� ������Ʈ ������ ��ġ�� ��ȯ�մϴ�.
	 *
	 * @return ���콺�� ������Ʈ ������ ��ġ�� ��ȯ�մϴ�.
	 */
	Vec2i GetCurrPosition() const { return CurrCursorPosition; }


private:
	/**
	 * ���� ���콺�� ���¸� ����ϴ�.
	 *
	 * @param OutCursorPosition - ���� ���콺�� ��ġ�Դϴ�.
	 * @param OutButtonState - ��ư �����Դϴ�.
	 */
	void GetCurrentMouseState(Vec2i& OutCursorPosition, uint32_t& OutButtonState);


	/**
	 * ���콺 ��ư�� ���ȴ��� Ȯ���մϴ�.
	 *
	 * @param InButtonState - ���콺 ��ư�� �����Դϴ�.
	 * @param InButtonType - ���콺 ��ư�� Ÿ���Դϴ�.
	 *
	 * @return ���� Ű�� �����ٸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	bool IsPressButton(const uint32_t& InButtonState, const EButtonType& InButtonType) const;


private:
	/**
	 * ������Ʈ ������ ���콺 ��ġ�Դϴ�.
	 */
	Vec2i PrevCursorPosition;


	/**
	 * ������Ʈ ������ ���콺 ��ư �����Դϴ�.
	 */
	uint32_t PrevButtonState = 0;


	/**
	 * ������Ʈ ������ ���콺 ��ġ�Դϴ�.
	 */
	Vec2i CurrCursorPosition;


	/**
	 * ������Ʈ ������ ���콺 ��ư �����Դϴ�.
	 */
	uint32_t CurrButtonState = 0;
};


/**
 * �Է� ó�� Ŭ�����Դϴ�.
 */
class InputSystem
{
public:
	/**
	 * �Է� Ŭ������ �������Դϴ�.
	 */
	InputSystem() = default;


	/**
	 * �Է� ó�� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	InputSystem(InputSystem&& InInstance) noexcept;


	/**
	 * �Է� ó�� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 */
	InputSystem(const InputSystem& InInstance) noexcept;


	/**
	 * �Է� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~InputSystem();


	/**
	 * �Է� ó�� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	InputSystem& operator=(InputSystem&& InInstance) noexcept;


	/**
	 * �Է� ó�� Ŭ������ ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ��ü�Դϴ�.
	 *
	 * @return ������ ��ü�� �����ڸ� ��ȯ�մϴ�.
	 */
	InputSystem& operator=(const InputSystem& InInstance) noexcept;


	/**
	 * �Է� ���¸� ������Ʈ�մϴ�.
	 * @note �̶�, �� �޼���� �� ������ ȣ��Ǿ�� �մϴ�.
	 *
	 * @return QUIT �޽����� ������ ��� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 *
	 */
	bool Tick();


	/**
	 * �Է� Ŭ������ �����ϴ� Ű���带 ��ȯ�մϴ�.
	 *
	 * @return �Է� Ŭ������ �����ϴ� Ű���带 ��ȯ�մϴ�.
	 */
	const KeyboardState& GetKeyboardState() const { return KeyboardState_; }


	/**
	 * �Է� Ŭ������ �����ϴ� ���콺�� ��ȯ�մϴ�.
	 *
	 * @return �Է� Ŭ������ �����ϴ� ���콺�� ��ȯ�մϴ�.
	 */
	const MouseState& GetMouseState() const { return MouseState_; }


private:
	/**
	 * �Է� Ŭ������ �����ϴ� Ű�����Դϴ�.
	 */
	KeyboardState KeyboardState_;


	/**
	 * �Է� Ŭ������ �����ϴ� ���콺�Դϴ�.
	 */
	MouseState MouseState_;
};