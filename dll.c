#include <Windows.h>
#include <iostream>
#include <string>

void test_func()
{
	DWORD pid = GetCurrentProcessId();
	MessageBoxA(NULL, std::to_string(pid).c_str(), "PID", MB_OK);
}

BOOL APIENTRY DllMain(HMODULE hmodule, DWORD reason_for_call, LPVOID lp_reserved)
{
	switch(reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hmodule);
			test_func()
			break;
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE:
}
