#pragma once

#include <string>
#include <memory>
#include <stdexcept>


/**
 * ���ڿ� ���� ����� �����ϴ� Ŭ�����Դϴ�.
 * �̶� �� Ŭ������ ���� Ŭ������ ��� ���� �ϸ�
 * �ν��Ͻ� ���� ���� �ٷ� ����� �� �ֽ��ϴ�.
 */
class Text
{
public:
	/**
	 * ����ȭ�� ���ڿ��� ��ȯ�մϴ�.
	 * �� �޼���� snprintf�� ��ü�ϱ� ���� �޼����Դϴ�.
	 *
	 * @param InFormat - ���� ���ڿ��Դϴ�.
	 * @param ... InArgs - �������� ������ �����͸� �����ϴ� �μ��Դϴ�.
	 *
	 * @return �������� �Ϸ�� ���ڿ��� ��ȯ�մϴ�.
	 *
	 * @see https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
	 */
	template<typename ... Args>
	static inline std::string Format(const std::string& InFormat, Args ... InArgs_)
	{
		size_t Size = static_cast<size_t>(std::snprintf(nullptr, 0, InFormat.c_str(), InArgs_ ...)) + 1;

		auto Buffer = std::make_unique<char[]>(Size);
		std::snprintf(Buffer.get(), Size, InFormat.c_str(), InArgs_ ...);

		return std::string(Buffer.get(), Buffer.get() + Size - 1);
	}


	/**
	 * ����ȭ�� ���ڿ��� ��ȯ�մϴ�.
	 * �� �޼���� swprintf�� ��ü�ϱ� ���� �޼����Դϴ�.
	 *
	 * @param InFormat - ���� ���ڿ��Դϴ�.
	 * @param ... InArgs - �������� ������ �����͸� �����ϴ� �μ��Դϴ�.
	 *
	 * @return �������� �Ϸ�� ���ڿ��� ��ȯ�մϴ�.
	 *
	 * @see https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
	 */
	template<typename ... Args>
	static inline std::wstring Format(const std::wstring& InFormat, Args ... InArgs_)
	{
		size_t Size = static_cast<size_t>(std::swprintf(nullptr, 0, InFormat.c_str(), InArgs_ ...)) + 1;

		auto Buffer = std::make_unique<wchar_t[]>(Size);
		std::swprintf(Buffer.get(), Size, InFormat.c_str(), InArgs_ ...);

		return std::wstring(Buffer.get(), Buffer.get() + Size - 1);
	}


	/**
	 * ���ڿ��� Hash ���� ��ȯ�մϴ�.
	 *
	 * @param InText - Hash ������ ��ȯ�� ���ڿ��Դϴ�.
	 *
	 * @return �Է� ���� ���ڿ��� Hash ���Դϴ�.
	 */
	static inline std::size_t GetHash(const std::string& InText)
	{
		return std::hash<std::string>{}(InText);
	}


	/**
	 * ���ڿ��� Hash ���� ����ϴ�.
	 *
	 * @param InText - Hash ������ ��ȯ�� ���ڿ��Դϴ�.
	 *
	 * @return �Է� ���� ���ڿ��� Hash ���Դϴ�.
	 */
	static inline std::size_t GetHash(const std::wstring& InText)
	{
		return std::hash<std::wstring>{}(InText);
	}
};