#pragma once

#include <Windows.h>
#include <Dbghelp.h>
#include <minidumpapiset.h>


/**
 * ����ȭ ���� ���� ���� ó�� �� ���� ������ �����ϴ� Ŭ�����Դϴ�.
 */
class CrashReport
{
public:
	/**
	 * ũ���� ���� Ŭ������ �ʱ�ȭ�մϴ�.
	 * ���� ������ �����ϱ� ���ؼ��� �ݵ�� ȣ���ؾ� �մϴ�.
	 */
	static void Init();


	/**
	 * ����ȭ ���� ���� ���ܸ� ó���մϴ�.
	 * 
	 * @param InExceptionInfo - ���ܰ� �߻��� ������ ���õ� �����Դϴ�.
	 * 
	 * @return EXCEPTION_CONTINUE_SEARCH �⺻ ���� ��ȯ�մϴ�.
	 */
	static LONG WINAPI UnhandledExceptionHandler(struct _EXCEPTION_POINTERS* InExceptionInfo);


	/**
	 * ũ���� ���� ������ �����մϴ�.
	 * �̶�, ���� ���� �̸��� YYYY-MM-DD-HH-MM-SS.dmp ���� �Դϴ�.
	 * 
	 * @param InExceptionInfo - ���ܰ� �߻��� ������ ���õ� �����Դϴ�.
	 */
	static void CreateCrashDumpFile(struct _EXCEPTION_POINTERS* InExceptionInfo);
};