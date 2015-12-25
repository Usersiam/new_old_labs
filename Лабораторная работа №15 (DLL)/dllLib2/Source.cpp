#include <Windows.h>
#include <iostream>
#include "Lib2.h"
#pragma comment ( lib ,  "IPHLPAPI.lib" )
extern "C" __declspec(dllexport) PIP_ADAPTER_INFO getSize2()
{
	IP_ADAPTER_INFO AdapterInfo[16];			// Allocate information for up to 16 NICs
	DWORD dwBufLen = sizeof(AdapterInfo);
	DWORD dwStatus = GetAdaptersInfo(			// Call GetAdapterInfo
		AdapterInfo,							// [out] buffer to receive data
		&dwBufLen);
	PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info
	return pAdapterInfo;
}

Log2* GetPointer2()
{
	return new Log2;
}

Log2::Log2()
{
}
Log2::~Log2()
{
}

PIP_ADAPTER_INFO Log2::write2()
{
	IP_ADAPTER_INFO AdapterInfo[16];			// Allocate information for up to 16 NICs
	DWORD dwBufLen = sizeof(AdapterInfo);
	DWORD dwStatus = GetAdaptersInfo(			// Call GetAdapterInfo
		AdapterInfo,							// [out] buffer to receive data
		&dwBufLen);
	PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info
	
	return	pAdapterInfo;
	
}