#pragma once

#include <cstdint>
#include <algorithm>


/**
 * 수학에서 정의하는 int32_t 타입의 2차원 벡터 구조체입니다.
 */
struct Vec2i
{
	/**
	 * 2차원 벡터의 타입입니다.
	 */
	using Vector = Vec2i;


	/**
	 * 2차원 벡터의 원소 타입입니다.
	 */
	using Type = int32_t;


	/**
	 * 벡터의 크기입니다.
	 */
	static const std::size_t SIZE = 2;


	/**
	 * 벡터의 기본 생성자입니다.
	 * 이때, 모든 원소의 값을 0으로 초기화합니다.
	 */
	explicit Vector() noexcept : Vector(0) { }


	/**
	 * 생성자입니다.
	 *
	 * @param InX - 벡터의 첫 번째 성분입니다.
	 * @param InY - 벡터의 두 번째 성분입니다.
	 */
	explicit Vector(Type InX, Type InY) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 * 
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 * 
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 원소에 - 부호를 취합니다.
	 * 
	 * @return 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 * 
	 * @param 연산을 수행할 피연산자입니다.
	 * 
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 * 
	 * @param InIndex - 참조할 인덱스 값입니다.
	 * 
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 * 
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소입니다.
	 */
	Type Element_[SIZE];


	/**
	 * 벡터의 첫 번째 원소입니다.
	 */
	Type& x = Element_[0];


	/**
	 * 벡터의 두 번째 원소입니다.
	 */
	Type& y = Element_[1];
};


/**
 * 수학에서 정의하는 float 타입의 2차원 벡터 구조체입니다.
 */
struct Vec2f
{
	/**
	 * 2차원 벡터의 타입입니다.
	 */
	using Vector = Vec2f;


	/**
	 * 2차원 벡터의 원소 타입입니다.
	 */
	using Type = float;


	/**
	 * 벡터의 크기입니다.
	 */
	static const std::size_t SIZE = 2;


	/**
	 * 벡터의 기본 생성자입니다.
	 * 이때, 모든 원소의 값을 0으로 초기화합니다.
	 */
	explicit Vector() noexcept : Vector(0.0f) { }


	/**
	 * 생성자입니다.
	 *
	 * @param InX - 벡터의 첫 번째 성분입니다.
	 * @param InY - 벡터의 두 번째 성분입니다.
	 */
	explicit Vector(Type InX, Type InY) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 원소에 - 부호를 취합니다.
	 *
	 * @return 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소입니다.
	 */
	Type Element_[SIZE];


	/**
	 * 벡터의 첫 번째 원소입니다.
	 */
	Type& x = Element_[0];


	/**
	 * 벡터의 두 번째 원소입니다.
	 */
	Type& y = Element_[1];
};


/**
 * 수학에서 정의하는 int32_t 타입의 3차원 벡터 구조체입니다.
 */
struct Vec3i
{
	/**
	 * 3차원 벡터의 타입입니다.
	 */
	using Vector = Vec3i;


	/**
	 * 3차원 벡터의 원소 타입입니다.
	 */
	using Type = int32_t;


	/**
	 * 벡터의 크기입니다.
	 */
	static const std::size_t SIZE = 3;


	/**
	 * 벡터의 기본 생성자입니다.
	 * 이때, 모든 원소의 값을 0으로 초기화합니다.
	 */
	explicit Vector() noexcept : Vector(0) { }


	/**
	 * 생성자입니다.
	 *
	 * @param InX - 벡터의 첫 번째 성분입니다.
	 * @param InY - 벡터의 두 번째 성분입니다.
	 * @param InZ - 벡터의 세 번째 성분입니다.
	 */
	explicit Vector(Type InX, Type InY, Type InZ) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
		Element_[2] = InZ;
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 원소에 - 부호를 취합니다.
	 *
	 * @return 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소입니다.
	 */
	Type Element_[SIZE];


	/**
	 * 벡터의 첫 번째 원소입니다.
	 */
	Type& x = Element_[0];


	/**
	 * 벡터의 두 번째 원소입니다.
	 */
	Type& y = Element_[1];


	/**
	 * 벡터의 세 번째 원소입니다.
	 */
	Type& z = Element_[2];
};


/**
 * 수학에서 정의하는 float 타입의 3차원 벡터 구조체입니다.
 */
struct Vec3f
{
	/**
	 * 3차원 벡터의 타입입니다.
	 */
	using Vector = Vec3f;


	/**
	 * 3차원 벡터의 원소 타입입니다.
	 */
	using Type = float;


	/**
	 * 벡터의 크기입니다.
	 */
	static const std::size_t SIZE = 3;


	/**
	 * 벡터의 기본 생성자입니다.
	 * 이때, 모든 원소의 값을 0으로 초기화합니다.
	 */
	explicit Vector() noexcept : Vector(0.0f) { }


	/**
	 * 생성자입니다.
	 *
	 * @param InX - 벡터의 첫 번째 성분입니다.
	 * @param InY - 벡터의 두 번째 성분입니다.
	 * @param InZ - 벡터의 세 번째 성분입니다.
	 */
	explicit Vector(Type InX, Type InY, Type InZ) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
		Element_[2] = InZ;
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 원소에 - 부호를 취합니다.
	 *
	 * @return 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소입니다.
	 */
	Type Element_[SIZE];


	/**
	 * 벡터의 첫 번째 원소입니다.
	 */
	Type& x = Element_[0];


	/**
	 * 벡터의 두 번째 원소입니다.
	 */
	Type& y = Element_[1];


	/**
	 * 벡터의 세 번째 원소입니다.
	 */
	Type& z = Element_[2];
};


/**
 * 수학에서 정의하는 int32_t 타입의 4차원 벡터 구조체입니다.
 */
struct Vec4i
{
	/**
	 * 4차원 벡터의 타입입니다.
	 */
	using Vector = Vec4i;


	/**
	 * 4차원 벡터의 원소 타입입니다.
	 */
	using Type = int32_t;


	/**
	 * 벡터의 크기입니다.
	 */
	static const std::size_t SIZE = 4;


	/**
	 * 벡터의 기본 생성자입니다.
	 * 이때, 모든 원소의 값을 0으로 초기화합니다.
	 */
	explicit Vector() noexcept : Vector(0) { }


	/**
	 * 생성자입니다.
	 *
	 * @param InX - 벡터의 첫 번째 성분입니다.
	 * @param InY - 벡터의 두 번째 성분입니다.
	 * @param InZ - 벡터의 세 번째 성분입니다.
	 * @param InW - 벡터의 네 번째 성분입니다.
	 */
	explicit Vector(Type InX, Type InY, Type InZ, Type InW) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
		Element_[2] = InZ;
		Element_[3] = InW;
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 원소에 - 부호를 취합니다.
	 *
	 * @return 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소입니다.
	 */
	Type Element_[SIZE];



	/**
	 * 벡터의 첫 번째 원소입니다.
	 */
	Type& x = Element_[0];


	/**
	 * 벡터의 두 번째 원소입니다.
	 */
	Type& y = Element_[1];


	/**
	 * 벡터의 세 번째 원소입니다.
	 */
	Type& z = Element_[2];


	/**
	 * 벡터의 네 번째 원소입니다.
	 */
	Type& w = Element_[3];
};


/**
 * 수학에서 정의하는 float 타입의 4차원 벡터 구조체입니다.
 */
struct Vec4f
{
	/**
	 * 4차원 벡터의 타입입니다.
	 */
	using Vector = Vec4f;


	/**
	 * 4차원 벡터의 원소 타입입니다.
	 */
	using Type = float;


	/**
	 * 벡터의 크기입니다.
	 */
	static const std::size_t SIZE = 4;


	/**
	 * 벡터의 기본 생성자입니다.
	 * 이때, 모든 원소의 값을 0으로 초기화합니다.
	 */
	explicit Vector() noexcept : Vector(0.0f) { }


	/**
	 * 생성자입니다.
	 *
	 * @param InX - 벡터의 첫 번째 성분입니다.
	 * @param InY - 벡터의 두 번째 성분입니다.
	 * @param InZ - 벡터의 세 번째 성분입니다.
	 * @param InW - 벡터의 네 번째 성분입니다.
	 */
	explicit Vector(Type InX, Type InY, Type InZ, Type InW) noexcept
	{
		Element_[0] = InX;
		Element_[1] = InY;
		Element_[2] = InZ;
		Element_[3] = InW;
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(const Type& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 원소를 하나의 값으로 초기화합니다.
	 *
	 * @param InElement - 모든 원소를 초기화 할 값입니다.
	 */
	Vector(Type&& InElement) noexcept
	{
		std::fill(Element_, Element_ + SIZE, InElement);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터의 인스턴스입니다.
	 */
	Vector(const Vector& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 복사 생성자입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 */
	Vector(Vector&& InInstance) noexcept
	{
		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(const Vector& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 대입 연산자 입니다.
	 *
	 * @param InInstance - 원소를 복사할 벡터 구조체의 인스턴스입니다.
	 *
	 * @return 대입한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator=(Vector&& InInstance) noexcept
	{
		if (this == &InInstance) return *this;

		std::copy(InInstance.Element_, InInstance.Element_ + SIZE, Element_);

		return *this;
	}


	/**
	 * 벡터의 원소에 - 부호를 취합니다.
	 *
	 * @return 벡터의 원소에 -부호를 취한 새로운 벡터를 반환합니다.
	 */
	Vector operator-() const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = -Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param InInstance 벡터의 덧셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 더한 결과를 반환합니다.
	 */
	Vector operator+(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] + InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param InInstance 벡터의 뺄셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 뺀 결과를 반환합니다.
	 */
	Vector operator-(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] - InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(const Vector& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 * 이때, 내적 연산(Dot, Inner Product)와는 다릅니다.
	 *
	 * @param InInstance 벡터의 곱셈을 수행할 피연산자입니다.
	 *
	 * @return 두 벡터에 대응하는 원소를 곱한 결과를 반환합니다.
	 */
	Vector operator*(Vector&& InInstance) const
	{
		Vector Result;

		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Result[Index] = Element_[Index] * InInstance.Element_[Index];
		}

		return Result;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 더합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator+=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] += InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 뺍니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator-=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] -= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(const Vector& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 두 벡터에 대응하는 원소를 곱합니다.
	 *
	 * @param 연산을 수행할 피연산자입니다.
	 *
	 * @return 연산을 수행한 벡터의 참조자를 반환합니다.
	 */
	Vector& operator*=(Vector&& InInstance) noexcept
	{
		for (int32_t Index = 0; Index < SIZE; ++Index)
		{
			Element_[Index] *= InInstance.Element_[Index];
		}

		return *this;
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](const int32_t& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 있습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	Type& operator[](int32_t&& InIndex)
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](const int32_t& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소를 인덱스로 참조합니다.
	 * 이때, 원소의 값을 변경할 수 없습니다.
	 *
	 * @param InIndex - 참조할 인덱스 값입니다.
	 *
	 * @throws 인덱스 값이 범위를 벋어나면 덤프 파일을 생성하고 프로그램이 종료됩니다.
	 *
	 * @return 인덱스에 대응하는 원소를 반환합니다.
	 */
	const Type& operator[](int32_t&& InIndex) const
	{
		return Element_[InIndex];
	}


	/**
	 * 벡터의 원소입니다.
	 */
	Type Element_[SIZE];


	/**
	 * 벡터의 첫 번째 원소입니다.
	 */
	Type& x = Element_[0];


	/**
	 * 벡터의 두 번째 원소입니다.
	 */
	Type& y = Element_[1];


	/**
	 * 벡터의 세 번째 원소입니다.
	 */
	Type& z = Element_[2];


	/**
	 * 벡터의 네 번째 원소입니다.
	 */
	Type& w = Element_[3];
};