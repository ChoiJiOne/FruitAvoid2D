#pragma once

#include <Windows.h>
#include <Dbghelp.h>
#include <minidumpapiset.h>


/**
 * 구조화 되지 않은 에러 처리 및 덤프 파일을 생성하는 클래스입니다.
 */
class CrashReport
{
public:
	/**
	 * 크래쉬 덤프 클래스를 초기화합니다.
	 * 덤프 파일을 생성하기 위해서는 반드시 호출해야 합니다.
	 */
	static void Init();


	/**
	 * 구조화 되지 않은 예외를 처리합니다.
	 * 
	 * @param InExceptionInfo - 예외가 발생한 지점의 관련된 정보입니다.
	 * 
	 * @return EXCEPTION_CONTINUE_SEARCH 기본 값을 반환합니다.
	 */
	static LONG WINAPI UnhandledExceptionHandler(struct _EXCEPTION_POINTERS* InExceptionInfo);


	/**
	 * 크래시 덤프 파일을 생성합니다.
	 * 이때, 덤프 파일 이름은 YYYY-MM-DD-HH-MM-SS.dmp 형식 입니다.
	 * 
	 * @param InExceptionInfo - 예외가 발생한 지점의 관련된 정보입니다.
	 */
	static void CreateCrashDumpFile(struct _EXCEPTION_POINTERS* InExceptionInfo);
};