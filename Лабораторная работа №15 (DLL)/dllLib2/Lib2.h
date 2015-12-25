#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <Iphlpapi.h>
#include <Assert.h>
#pragma comment(lib, "iphlpapi.lib")
extern "C" __declspec(dllexport) PIP_ADAPTER_INFO getSize2();

class  Log2;


class Log2
{
public:
	Log2();
	virtual ~Log2();
	virtual PIP_ADAPTER_INFO write2();
};
extern "C" __declspec(dllexport)  Log2* GetPointer2();