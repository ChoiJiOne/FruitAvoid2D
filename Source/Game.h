#pragma once

#include "Player.h"
#include "Fruit.h"
#include "GameEngine.h"


/**
 * FruitAvoid2D ������ �����ϴ� Ŭ�����Դϴ�.
 */
class Game
{
public:
	/**
	 * FruitAvoid2D ������ �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	Game() = default;


	/**
	 * FruitAvoid2D ������ �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~Game();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� ����
	 */
	DISALLOW_COPY_AND_ASSIGN(Game);


	/**
	 * FruitAvoid2D ������ �ʱ�ȭ�մϴ�.
	 * 
	 * @throws FruitAvoid2D ���� �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Init();


	/**
	 * FruitAvoid2D ������ �����մϴ�.
	 * 
	 * @throws FruitAvoid2D ���� ���࿡ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	void Run();


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