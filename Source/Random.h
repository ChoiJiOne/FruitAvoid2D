#pragma once

#include <chrono>
#include <random>


/**
 * 임의의 정수를 생성합니다.
 *
 * @param InMinValue - 생성할 난수 범위의 최솟값입니다.
 * @param InMaxValue - 생성할 난수 범위의 최댓값입니다.
 *
 * @return  생성된 임의의 정수를 반환합니다.
 */
template <typename T>
inline static int32_t GenerateRandomInt(const T& InMinValue, const T& InMaxValue)
{
	T MinValue = std::min<T>(InMinValue, InMaxValue);
	T MaxValue = std::max<T>(InMinValue, InMaxValue);

	std::random_device RandomDevice;
	std::mt19937 Generator(RandomDevice());
	std::uniform_int_distribution<T> Distribution(InMinValue, InMaxValue);

	return Distribution(Generator);
}


/**
 * 임의의 실수를 생성합니다.
 *
 * @param InMinValue - 생성할 난수 범위의 최솟값입니다.
 * @param InMaxValue - 생성할 난수 범위의 최댓값입니다.
 *
 * @return  생성된 임의의 실수를 반환합니다.
 */
template <typename T>
inline static float GenerateRandomFloat(const T& InMinValue, const T& InMaxValue)
{
	T MinValue = std::min<T>(InMinValue, InMaxValue);
	T MaxValue = std::max<T>(InMinValue, InMaxValue);

	std::random_device RandomDevice;
	std::mt19937 Generator(RandomDevice());
	std::uniform_real_distribution<T> Distribution(MinValue, MaxValue);

	return Distribution(Generator);
}