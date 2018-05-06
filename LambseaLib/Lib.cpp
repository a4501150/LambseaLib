#pragma once
#include "Exports.h"
#include "LambseaDriver.h"


void PocLoadUnsignedDriver() {

	AdjustRights(L"SeLoadDriverPrivilege", true);

	//unload before load
	SafeUnloadDriver(L"Lambsea");
	//SafeDeleteFile(L"Lambsea.sys", false);
	//DropFile(Lambsea, L"Lambsea.sys", sizeof(Lambsea));

	auto ret = LoadUnsignedDriver(L"Lambsea");

	//clean up
	SafeUnloadDriver(L"cpuz141");
	SafeDeleteFile(L"cpuz141.sys", true);
	DeleteDriverRegKey(L"cpuz141");
	//DeleteDriverRegKey(L"Lambsea");

	if (ret)
		printf("Load Done\n");
	else
		printf("Load Failed\n");

}

int main() {
	
	//show up load an unsigned shit 
	//PocLoadUnsignedDriver();
	//SafeDeleteFile(L"Lambsea.sys", false);
	AdjustRights(L"SeLoadDriverPrivilege", true);
	SafeUnloadDriver(L"Lambsea");
	LoadDriver(L"Lambsea");
	system("pause");
	SafeUnloadDriver(L"Lambsea");

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
