#pragma once

#include "Player.h"
#include "Fruit.h"
#include "GameFramework.h"
#include "GameEngine.h"


/**
 * FruitAvoid2D ������ �����ϴ� Ŭ�����Դϴ�.
 */
class FruitAvoid2D : public GameFramework
{
public:
	/**
	 * ������ �����ϴ� Ŭ������ �������Դϴ�.
	 */
	FruitAvoid2D() = default;


	/**
	 * ������ �����ϴ� Ŭ������ ���� �Ҹ����Դϴ�.
	 */
	virtual ~FruitAvoid2D();


	/**
	 * ���� �����ڿ� ���� �����ڸ� ��������� ����
	 */
	DISALLOW_COPY_AND_ASSIGN(FruitAvoid2D);


	/**
	 * ������ �ʱ�ȭ�մϴ�.
	 * 
	 * @throws ���� �ʱ�ȭ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Init() override;
	

	/**
	 * ������ �����մϴ�.
	 * 
	 * @throws ���� ���࿡ �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Run() override;


	/**
	 * ������ ������Ʈ�մϴ�.
	 * 
	 * @throws ���� ������Ʈ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Update() override;


	/**
	 * ������ ȭ�鿡 �������մϴ�.
	 * 
	 * @throws ���� ������Ʈ�� �����ϸ� C++ ǥ�� ���ܸ� �����ϴ�.
	 */
	virtual void Render() override;


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


	/**
	 * ���� ���� �ִ� ������ ���Դϴ�.
	 */
	int32_t MaxFruits = 10;


	/**
	 * �÷��̾��� ����Դϴ�.
	 */
	int32_t Life_ = 3;


	/**
	 * ������ ������ Y��ǥ�Դϴ�.
	 */
	int32_t RespawnYPosition = 0;


	/**
	 * ������ �� �����Դϴ�.
	 */
	int32_t EndYPosition = 800;
};