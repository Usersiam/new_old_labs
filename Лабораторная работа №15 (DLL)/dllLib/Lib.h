
#ifdef LOG_EXPORTS
#define LOG_API __declspec(dllexport)
#else
#define LOG_API __declspec(dllimport)
#endif

#include <iostream>
#include <Windows.h>
#include <Iphlpapi.h>

class Log;
extern "C" __declspec(dllexport)  Log* GetPointer();

class Log
{
public:
	Log();
	virtual ~Log();
	virtual PIP_ADAPTER_INFO write();
};