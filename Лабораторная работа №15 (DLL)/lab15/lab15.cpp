
#include "stdafx.h"
#include "lab15.h"
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include "../dllLib/Lib.h"
#include "../dllLib2/Lib2.h"
#pragma comment(lib,"dllLib2.lib")
#define MAX_LOADSTRING 100
using namespace std;
HINSTANCE hInst;                                
WCHAR szTitle[MAX_LOADSTRING];                  
WCHAR szWindowClass[MAX_LOADSTRING];            
int x = 10, y = 10, counter=0;

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)

{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB15, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB15));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB15));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB15);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной
   
   HWND hWnd = CreateWindowW(szWindowClass, L"", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void COUT_(PIP_ADAPTER_INFO pAdapterInfo,  HWND hWnd, string a, int L_or_R)
{
	
	if(L_or_R == 1) pAdapterInfo = pAdapterInfo->Next;
	
	counter++;
	for (int d = 1; d <= 6; d++)
	{
		int z = pAdapterInfo->Address[d - 1];
		int radix = 16;
		char buffer[sizeof(z) + 1];
		_itoa_s(z, buffer, radix);
		if(buffer=="d") MessageBoxA(hWnd, "d", "NO TITLE", NULL);
		if (d != 6)
			a = a + buffer + "-";
		else a = a + buffer + " ";
	}
	LPCSTR into_a;
	into_a = (LPCSTR)a.c_str();
	HDC hdc;
		hdc = (HDC)GetDC(hWnd);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkColor(hdc, RGB(255, 255, 255));
		
		if(L_or_R==0) TextOutA(hdc, x, y+counter*20, into_a, strlen(into_a));
		else TextOutA(hdc, x+500, y + counter * 20, into_a, strlen(into_a));
		ReleaseDC(hWnd, hdc); 
			MessageBoxA(hWnd, into_a, "NO TITLE", NULL);
		}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
		    case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
	case WM_RBUTTONDOWN:
	{
		HMODULE hLib = LoadLibrary(L"dllLib.dll");
		if (hLib == NULL)
		{

			MessageBox(hWnd, L"Error", L"Error", NULL);
			break;
		}
		
		counter = 0;   

		string(*MYFUNC)(int L_or_R);
		string a_0 = "первая  библиотека(1)    ";

		MYFUNC = (string(*) (int L_or_R))GetProcAddress(hLib, "getSize");
		a_0 = a_0 + MYFUNC(1);
		LPCSTR into_a;
		into_a = (LPCSTR)a_0.c_str();
		HDC hdc;
		hdc = (HDC)GetDC(hWnd);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkColor(hdc, RGB(255, 255, 255));
		counter++;
		TextOutA(hdc, x + 500, y, "MAC второго адаптера", 22);
		TextOutA(hdc, x + 500, y + counter * 20, into_a, strlen(into_a));
		ReleaseDC(hWnd, hdc);
		MessageBoxA(hWnd, into_a, "NO TITLE", NULL);
		typedef Log* (*GET_POINTER)();

		GET_POINTER pGetPointer = (GET_POINTER)GetProcAddress(hLib, "GetPointer");
		Log* log = pGetPointer();

		PIP_ADAPTER_INFO pAdapterInfo2 = log->write();
		string b_0 = "первая  библиотека(2)    ";
		COUT_(pAdapterInfo2, hWnd, b_0,1);
		FreeLibrary(hLib);
		PIP_ADAPTER_INFO pAdapterInfo3 = getSize2();
		string a_2 = "вторая  библиотека(1)     ";
		COUT_(pAdapterInfo3, hWnd, a_2,1);
		Log2* log2 = GetPointer2();
		PIP_ADAPTER_INFO pAdapterInfo4 = log2->write2();
		string b_2 = "вторая  библиотека(2)     ";
		COUT_(pAdapterInfo4, hWnd, b_2,1);




		break;
	}
	case WM_LBUTTONDOWN:
	{
		
		HMODULE hLib = LoadLibrary(L"dllLib.dll");
		if (hLib == NULL)
		{
			
			MessageBox(hWnd, L"Error", L"Error", NULL);
			break;
		}
		
		counter = 0;

		string(*MYFUNC)(int L_or_R);
		string a_0 = "первая  библиотека(1)    ";

		MYFUNC = (string(*) (int L_or_R))GetProcAddress(hLib, "getSize");
		a_0 = a_0 + MYFUNC(0);
		LPCSTR into_a;
		into_a = (LPCSTR)a_0.c_str();
		HDC hdc;
		hdc = (HDC)GetDC(hWnd);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkColor(hdc, RGB(255, 255, 255));
		counter++;
		TextOutA(hdc, x , y, "MAC первого адаптера", 22);
		TextOutA(hdc, x, y + counter * 20, into_a, strlen(into_a));
		ReleaseDC(hWnd, hdc);
		MessageBoxA(hWnd, into_a, "NO TITLE", NULL);
		typedef Log* (*GET_POINTER)();

		GET_POINTER pGetPointer = (GET_POINTER)GetProcAddress(hLib, "GetPointer");
		Log* log = pGetPointer();

		PIP_ADAPTER_INFO pAdapterInfo2 = log->write();
		string b_0 = "первая  библиотека(2)    ";
		COUT_(pAdapterInfo2, hWnd, b_0, 0);
		FreeLibrary(hLib);
		PIP_ADAPTER_INFO pAdapterInfo3 = getSize2();
		string a_2 = "вторая  библиотека(1)     ";
		COUT_(pAdapterInfo3, hWnd, a_2, 0);
		Log2* log2 = GetPointer2();
		PIP_ADAPTER_INFO pAdapterInfo4 = log2->write2();
		string b_2 = "вторая  библиотека(2)     ";
		COUT_(pAdapterInfo4, hWnd, b_2, 0);
			
			
			
			
		

	
	}
	break;

    case WM_PAINT: 
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
