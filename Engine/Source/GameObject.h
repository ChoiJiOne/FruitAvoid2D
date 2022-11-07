#pragma once

#include "Vector.h"

#include <memory>

class World;
class Input;
class Graphics;


/**
 * ���� ������Ʈ Ŭ�����Դϴ�.
 * ���� ���� ������Ʈ�� �� Ŭ������ ��ӹ޾ƾ� �մϴ�.
 */
class GameObject
{
public:
	/**
	 * ���� ������Ʈ�� �������Դϴ�.
	 * 
	 * @param InWorld - ���� ������Ʈ�� ��ġ�� �����Դϴ�.
	 */
	explicit GameObject(World* InWorld);


	/**
	 * ���� ������Ʈ�� ���� �������Դϴ�.
	 * 
	 * @param InInstance - ������ ���� ������Ʈ�� �ν��Ͻ��Դϴ�.
	 */
	explicit GameObject(GameObject&& InInstance);


	/**
	 * ���� ������Ʈ�� ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ���� ������Ʈ�� �ν��Ͻ��Դϴ�.
	 */
	explicit GameObject(const GameObject& InInstance);


	/**
	 * ���� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~GameObject();

	
	/**
	 * ���� ������Ʈ�� ���� �������Դϴ�.
	 * 
	 * @param InInstance - ������ ���� ������Ʈ�� �ν��Ͻ��Դϴ�.
	 * 
	 * @return ������ ���� ������Ʈ�� �����ڸ� ��ȯ�մϴ�.
	 */
	GameObject& operator=(GameObject&& InInstance);


	/**
	 * ���� ������Ʈ�� ���� �������Դϴ�.
	 *
	 * @param InInstance - ������ ���� ������Ʈ�� �ν��Ͻ��Դϴ�.
	 *
	 * @return ������ ���� ������Ʈ�� �����ڸ� ��ȯ�մϴ�.
	 */
	GameObject& operator=(const GameObject& InInstance);


	/**
	 * ���� ������Ʈ�� ������Ʈ�մϴ�.
	 *
	 * @param InInput - ������ �Է� ó�� �ν��Ͻ��Դϴ�.
	 * @param InDeltaTime - �ʴ��� ��Ÿ �ð��� �Դϴ�.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) = 0;


	/**
	 * ���� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 * 
	 * @param InGraphics - ������ ������ ó�� �ν��Ͻ��Դϴ�.
	 */
	virtual void Render(Graphics& InGraphics) = 0;


	/**
	 * ���� ������Ʈ�� ȭ�鿡 ǥ�õ��� Ȯ���մϴ�.
	 * 
	 * @return ���� ������Ʈ�� ȭ�鿡 ǥ�õǾ�� �Ѵٸ� true, �׷��� ������ false�� ��ȯ�մϴ�.
	 */
	bool IsVisible() const { return bIsVisible_; }


	/**
	 * ���� ������Ʈ�� ȭ�鿡 ǥ�õ��� ���� �����մϴ�.
	 * 
	 * @param bIsVisible - true �̸� ȭ�鿡 ǥ���ϰ�, false ��� ȭ�鿡 ǥ������ �ʽ��ϴ�.
	 */
	void SetVisible(bool bIsVisible) { bIsVisible_ = bIsVisible; }


	/**
	 * ���� ������Ʈ�� ��ġ�� ����ϴ�.
	 * 
	 * @return ���� ������Ʈ�� ��ġ�� ��ȯ�մϴ�.
	 */
	Vec2i GetPosition() const { return Position_; }


	/**
	 * ���� ������Ʈ�� ��ġ�� �����մϴ�.
	 * 
	 * @param InPosition - ������ ���� ������Ʈ�� ��ġ�Դϴ�.
	 */
	void SetPosition(const Vec2i& InPosition) { Position_ = InPosition; }


	/**
	 * ���� ������Ʈ�� ���� ũ�⸦ ����ϴ�.
	 * 
	 * @return ���� ������Ʈ�� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	int32_t GetWidth() const { return Width_; }


	/**
	 * ���� ������Ʈ�� ���� ũ�⸦ �����մϴ�.
	 * 
	 * @param InWidth - ������ ���� ������Ʈ�� ���� ũ���Դϴ�.
	 */
	void SetWidth(const int32_t& InWidth) { Width_ = InWidth; }


	/**
	 * ���� ������Ʈ�� ���� ũ�⸦ ����ϴ�.
	 *
	 * @return ���� ������Ʈ�� ���� ũ�⸦ ��ȯ�մϴ�.
	 */
	int32_t GetHeight() const { return Height_; }


	/**
	 * ���� ������Ʈ�� ���� ũ�⸦ �����մϴ�.
	 *
	 * @param InWidth - ������ ���� ������Ʈ�� ���� ũ���Դϴ�.
	 */
	void SetHeight(const int32_t& InHeight) { Height_ = InHeight; }


	/**
	 * ���� ������Ʈ�� ����, ���� ũ�⸦ ����ϴ�.
	 * 
	 * @param OutWidth - ���� ������Ʈ�� ���� ũ���Դϴ�.
	 * @param OutHeight - ���� ������Ʈ�� ���� ũ���Դϴ�.
	 */
	void GetSize(int32_t& OutWidth, int32_t& OutHeight) const
	{
		OutWidth = Width_;
		OutHeight = Height_;
	}


	/**
	 * ���� ������Ʈ�� ����, ���� ũ�⸦ �����մϴ�.
	 *
	 * @param OutWidth - ������ ���� ������Ʈ�� ���� ũ���Դϴ�.
	 * @param OutHeight - ������ ���� ������Ʈ�� ���� ũ���Դϴ�.
	 */
	void SetSize(const int32_t& OutWidth, const int32_t& OutHeight)
	{
		Width_ = OutWidth;
		Height_ = OutHeight;
	}


protected:
	/**
	 * ���� ������Ʈ�� ��ġ�� �����Դϴ�.
	 */
	World* World_ = nullptr;


	/**
	 * ȭ�鿡 ���̴��� Ȯ���մϴ�.
	 */
	bool bIsVisible_ = true;


	/**
	 * ���� ������Ʈ�� ȭ��� �߽� ��ġ�Դϴ�.
	 */
	Vec2i Position_;


	/**
	 * ���� ������Ʈ�� ���� ũ���Դϴ�.
	 */
	int32_t Width_ = 0;


	/**
	 * ���� ������Ʈ�� ���� ũ���Դϴ�.
	 */
	int32_t Height_ = 0;
};