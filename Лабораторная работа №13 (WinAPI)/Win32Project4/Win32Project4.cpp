// Win32Project4.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32Project4.h"
#include "time.h"

#define ID_ONE	100
#define ID_TWO	101
#define ID_THREE	102
#define ID_FORE	103
#define ID_FIVE	104
#define ID_SIX	105
#define ID_SEVEN 106

int i = 1;
#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT4, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT4));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT4));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT4);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;


   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	srand(time(NULL));
	LPCWSTR titles[7] = { L"1", L"2", L"3", L"4", L"5", L"6", L"7" };
	LPCWSTR title_2[2] = { L"заголовок №1", L"заголовок №2" };
	WNDCLASS w;
	memset(&w, 0, sizeof(WNDCLASS));
	w.lpfnWndProc = ChildProc;
	w.hInstance = hInst;
	w.hbrBackground = NULL;
	w.lpszClassName = L"ChildWClass";
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	RegisterClass(&w);
	HWND child[8];
	switch (message)
	{
	case WM_LBUTTONUP:
	{SetWindowText(hWnd, title_2[rand() % 2]);


	int new_x = rand() % 866 + 100;  //1360
	int new_y = rand() % 468;   //900
	int Width = rand() % 400 + 310;
	int Height = rand() % 400 + 310;
	SetWindowText(hWnd, title_2[rand() % 2]);
	MoveWindow(hWnd, new_x, new_y, Width, Height, TRUE);
	UpdateWindow(hWnd);

	if (i < 8) {
		child[i] = CreateWindowEx(0, L"ChildWClass", (LPCTSTR)NULL,
			WS_CAPTION | WS_MINIMIZEBOX | WS_CHILD, 50, 50,
			200, 200, hWnd, (HMENU)(int)(ID_ONE + i), hInst, NULL);



		ShowWindow(child[i], SW_NORMAL);
		SetWindowText(child[i], titles[i - 1]);

		new_x = 100;
		new_y = 100;

		Width = 200;
		Height = 200;

		MoveWindow(child[i], new_x + 50 * i, new_y + 50 * i, Width + i * 10, Height + i * 10, TRUE);

		UpdateWindow(child[i]);

		i++;
	}
	break;
	}
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
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
		break;
	case WM_CLOSE:
	{EnableWindow(hWnd, TRUE);
	int msg;
	msg = MessageBox(hWnd, L"Выйти из программы?", L"Выход",
		MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
	switch (msg)
	{
	case IDOK:
		PostQuitMessage(0);
		break;
	case IDCANCEL:
		break;

	}
	break;
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
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
LRESULT CALLBACK ChildProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	switch (Message)
	{
	case WM_LBUTTONUP:
	{ 
		DestroyWindow(hwnd);
	}
	}
	return DefWindowProc(hwnd, Message, wparam, lparam);
}