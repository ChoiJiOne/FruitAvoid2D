#pragma once

#include <unordered_map>

#include "Text.h"


/**
 * Ŀ�ǵ� ������ �Ľ��ϰ�, Ŀ�ǵ� ���� ���ڸ� �����ϴ� Ŭ�����Դϴ�.
 */
class CommandLine
{
public:
	/**
	 * �Է¹��� Ŀ�ǵ� ������ �Ľ��ϰ�, �ʱ�ȭ�մϴ�.
	 */
	static void Parse();


	/**
	 * �ɼ��� �����ϴ��� Ȯ���մϴ�.
	 * 
	 * @param InOption - �����ϴ��� Ȯ���� �ɼ��Դϴ�.
	 * 
	 * @return �ɼ��� �����ϸ� true, �׷��� �ʴٸ� false�� ��ȯ�մϴ�.
	 */
	static bool HaveOption(const std::wstring& InOption);


	/**
	 * �ɼǿ� �ش��ϴ� ���� ����ϴ�.
	 * �̶�, �ɼǿ� �����ϴ� ���� �������� �ʴ´ٸ�, �� ���ڿ��� ��ȯ�մϴ�.
	 * 
	 * @param InOption - �ɼ��Դϴ�.
	 * 
	 * @return �ɼǿ� �����ϴ� ���� ��ȯ�մϴ�.
	 */
	static std::wstring GetValue(const std::wstring& InOption);


private:
	/**
	 * ���� ���� �� ���� ���� ��ü Ŀ�ǵ� �����Դϴ�.
	 */
	static std::wstring CommandLine_;
	

	/**
	 * ���� ���� �ÿ� ���� ���� Ŀ�ǵ� ������ �����Դϴ�.
	 */
	static std::vector<std::wstring> Arguments_;


	/**
	 * Ŀ�ǵ� ���� �Է����� ���� �ɼ��Դϴ�.
	 */
	static std::unordered_map<std::wstring, std::wstring> Options_;
};