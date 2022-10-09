#pragma once

class InputSystem;
class RenderSystem;


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
	 * ���� ������Ʈ ���¸� ������Ʈ�մϴ�.
	 * 
	 * @param InInput - ���� ������ �Է� �ý����Դϴ�.
	 * @param InDeltaTime - �ʴ��� ��Ÿ �ð��� �Դϴ�.
	 */
	virtual void Update(const InputSystem& InInput, float InDeltaTime) = 0;


	/**
	 * ���� ������Ʈ�� ȭ�鿡 �׸��ϴ�.
	 * 
	 * @param InRenderer - ���� ������ ���� �ý����Դϴ�.
	 * 
	 * @throws �������� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Render(const RenderSystem& InRenderer) = 0;
};