// TLS_test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<Windows.h>

#ifdef _WIN64
#pragma comment(linker,"/INCLUDE:_tls_used")
#else
#pragma comment(linker,"/INCLUDE:__tls_used")
#endif // _WIN64

void NTAPI TlsCallBac(PVOID h, DWORD dwReason, PVOID pv);

#ifdef _WIN64
#pragma const_seg(".CRT$XLX")
const
#else
#pragma data_seg(".CRT$XLX")
#endif
PIMAGE_TLS_CALLBACK p_thread_callback = TlsCallBac;
#ifdef _WIN64
#pragma const_seg()
#else
#pragma data_seg()
#endif // _WIN64




void NTAPI TlsCallBac(PVOID h, DWORD dwReason, PVOID pv)
{
	MessageBoxA(NULL, "In TLS", "In TLS", MB_OK);
	return;
}

int main()
{
	printf("hello world");
	system("pause");
    return 0;
}

