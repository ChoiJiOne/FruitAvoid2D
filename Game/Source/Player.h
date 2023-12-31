#pragma once

#include "GameObject.h"

#include <unordered_map>


/**
 * 게임 플레이어 클래스입니다.
 */
class Player : public GameObject
{
public:
	/**
	 * 게임 플레이어의 색상 타입입니다.
	 */
	enum class EColor
	{
		None   = 0,
		Blue   = 1,
		Green  = 2,
		Orange = 3,
		Purple = 4,
		Red    = 5,
		Sky    = 6,
		Yellow = 7
	};


public:
	/**
	 * 게임 플레이어 클래스의 생성자입니다.
	 * 이때, 게임 플레이어의 속도는 초당 픽셀 이동값으로 계산됩니다.
	 *
	 * @param InWorld - 게임 플레이어가 위치할 월드입니다.
	 * @param InPosition - 게임 플레이어의 화면상 위치입니다.
	 * @param InWidth - 게임 플레이어의 가로 크기입니다.
	 * @param InHeight - 게임 플레이어의 세로 크기입니다.
	 * @param InVelocity - 게임 플레이어의 속도입니다.
	 * @param InColor - 게임 플레이어의 색상입니다.
	 */
	explicit Player(
		World* InWorld, 
		const Vec2f& InPosition, 
		const float& InWidth, 
		const float& InHeight, 
		const float& InVelocity,
		const EColor& InColor
	);


	/**
	 * 게임 플레이어의 가상 소멸자입니다.
	 */
	virtual ~Player();


	/**
	 * 게임 플레이어의 복사 생성자와 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Player);


	/**
	 * 게임 플레이어를 업데이트합니다.
	 *
	 * @param InInput - 게임의 입력 처리 인스턴스입니다.
	 * @param InDeltaTime - 초단위 델타 시값값 입니다.
	 */
	virtual void Update(Input& InInput, float InDeltaSeconds) override;


	/**
	 * 게임 플레이어를 화면에 그립니다.
	 *
	 * @param InGraphics - 게임의 렌더링 처리 인스턴스입니다.
	 */
	virtual void Render(Graphics& InGraphics) override;


private:
	/**
	 * 게임 플레이어의 색상 타입입니다.
	 */
	EColor Color_;


	/**
	 * 게임 플레이어 생상에 대응하는 텍스처 키 값입니다.
	 */
	static std::unordered_map<EColor, std::size_t> ColorTextureKeys_;
};