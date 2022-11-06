#pragma once

#include "Vector.h"

#include <memory>

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
	 * ���� ������Ʈ�� ����Ʈ �������Դϴ�.
	 * ���� Ŭ���������� ������ Ȥ�� �ʱ�ȭ �޼��带 �̿��ؼ� ������Ʈ�� �ʱ�ȭ �ؾ� �մϴ�.
	 */
	GameObject() = default;


	/**
	 * ���� ������Ʈ�� ���� �Ҹ����Դϴ�.
	 */
	virtual ~GameObject() {}


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


protected:
	/**
	 * ȭ�鿡 ���̴��� Ȯ���մϴ�.
	 */
	bool bIsVisible_ = true;
};