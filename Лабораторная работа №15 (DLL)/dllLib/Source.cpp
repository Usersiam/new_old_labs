#include <Windows.h>
#include <iostream>
#include "Lib.h"
#pragma comment ( lib ,  "IPHLPAPI.lib" )
extern "C" __declspec(dllexport) std::string getSize(int L_or_R)
{
	IP_ADAPTER_INFO AdapterInfo[16];			// Allocate information for up to 16 NICs
	DWORD dwBufLen = sizeof(AdapterInfo);
	DWORD dwStatus = GetAdaptersInfo(			// Call GetAdapterInfo
		AdapterInfo,							// [out] buffer to receive data
		&dwBufLen);
	PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info
	if(L_or_R ==1) pAdapterInfo = pAdapterInfo->Next;
	std::string a;
	for (int d = 1; d <= 6; d++)
	{
		int z = pAdapterInfo->Address[d - 1];


		int radix = 16;
		char buffer[sizeof(z) + 1];

		_itoa_s(z, buffer, radix);
		if(d!=6)
		a = a + buffer + "-";
		else a = a + buffer + " ";
	}
	
	return a;
}

Log* GetPointer()
{
	return new Log;
}

Log::Log()
{
}
Log::~Log()
{
}

PIP_ADAPTER_INFO Log::write()
{
	IP_ADAPTER_INFO AdapterInfo[16];			// Allocate information for up to 16 NICs
	DWORD dwBufLen = sizeof(AdapterInfo);
	DWORD dwStatus = GetAdaptersInfo(			// Call GetAdapterInfo
		AdapterInfo,							// [out] buffer to receive data
		&dwBufLen);
	PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info
	return pAdapterInfo;
}
