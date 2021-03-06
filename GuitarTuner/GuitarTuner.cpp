// GuitarTuner.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "GuitarTuner.h"

#define MAX_LOADSTRING 100

// Global Variables:
HBITMAP bitmap;
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void				PaintImage(HDC);
void				PaintButtons(HDC);
void				CreateButtons(HWND);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GUITARTUNER, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GUITARTUNER));

    MSG msg;

    // Main message loop:
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



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GUITARTUNER));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GUITARTUNER);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
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
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 600, 700, nullptr, nullptr, hInstance, nullptr);

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
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		{
		bitmap = (HBITMAP)LoadImage(NULL, L"C:\\Users\owner\Documents\C++\GuitarTuner\Images\headstock.bmp", IMAGE_BITMAP, 400, 550, LR_LOADFROMFILE);
		CreateButtons(hWnd);
		}
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
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
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
			PaintImage(hdc);
			PaintButtons(hdc);
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

void CreateButtons(HWND hWnd) {
	HWND eButton = CreateWindow(
		L"BUTTON",
		L"E",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		30,
		70,
		100,
		100,
		hWnd,
		NULL,
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL
		);

	HWND aButton = CreateWindow(
		L"BUTTON",
		L"A",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		30,
		220,
		100,
		100,
		hWnd,
		NULL,
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL
	);

	HWND dButton = CreateWindow(
		L"BUTTON",
		L"D",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		30,
		370,
		100,
		100,
		hWnd,
		NULL,
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL
	);

	HWND gButton = CreateWindow(
		L"BUTTON",
		L"G",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		470,
		70,
		100,
		100,
		hWnd,
		NULL,
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL
	);

	HWND bButton = CreateWindow(
		L"BUTTON",
		L"B",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		470,
		220,
		100,
		100,
		hWnd,
		NULL,
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL
	);

	HWND hiEButton = CreateWindow(
		L"BUTTON",
		L"E",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		470,
		370,
		100,
		100,
		hWnd,
		NULL,
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL
	);
}

void PaintImage(HDC hdc) {
	HDC hMemDC = CreateCompatibleDC(hdc);
	SelectObject(hMemDC, bitmap);
	BitBlt(hdc, 0, 0, 400, 550, hMemDC, 0, 0, SRCCOPY);
	DeleteDC(hMemDC);
}

void PaintButtons(HDC hdc) {
	Rectangle(hdc, 130, 50, 470, 500);
	Rectangle(hdc, 180, 500, 420, 720);
	Rectangle(hdc, 300, 70, 400, 400);
	//HBRUSH hBrownBrush = CreateSolidBrush(RGB(94, 44, 0));
	//HPEN prevPen = SelectObject(hdc, hBrownBrush);
	Ellipse(hdc, 30, 70, 130, 170);
	Ellipse(hdc, 30, 220, 130, 320);
	Ellipse(hdc, 30, 370, 130, 470);
	Ellipse(hdc, 470, 70, 570, 170);
	Ellipse(hdc, 470, 220, 570, 320);
	Ellipse(hdc, 470, 370, 570, 470);
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
