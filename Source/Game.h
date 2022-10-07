#pragma once

#include "Player.h"
#include "Fruit.h"
#include "GameEngine.h"


/**
 * ������ �����ϴ� Ŭ�����Դϴ�.
 */
class Game
{
public:
	/**
	 * ������ �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	Game() = default;


	/**
	 * ������ �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Game();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� ����
	 */
	DISALLOW_COPY_AND_ASSIGN(Game);


	/**
	 * ������ �ʱ�ȭ�մϴ�.
	 * 
	 * @throws ���� �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Init();


	/**
	 * ������ �����մϴ�.
	 * 
	 * @throws ���� ���࿡ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Run();


private:
	/**
	 * ������ ������Ʈ�մϴ�.
	 * 
	 * @throws ���� ������Ʈ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Update();


	/**
	 * ������ ȭ�鿡 �������մϴ�.
	 * 
	 * @throws ���� ������Ʈ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Render();


private:
	/**
	 * ���� Ÿ�̸��Դϴ�.
	 */
	Timer Timer_;


	/**
	 * ���� �÷��̾��Դϴ�.
	 */
	std::unique_ptr<Player> Player_ = nullptr;


	/**
	 * �÷��̾ ���ؾ� �� ���ϵ��Դϴ�.
	 */
	std::list<Fruit> Fruits_;
};