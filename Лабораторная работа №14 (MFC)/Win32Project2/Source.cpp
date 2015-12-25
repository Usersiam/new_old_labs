#include <afxwin.h>
#include "time.h"


class CMyMainWnd : public CFrameWnd 
{
public:

	CMyMainWnd()
	{ 
		Create(NULL, L"Проект 14 MFC ");
	};	
	int i=0;
	int x=0,y=0,h=100,w=100;
	
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnPaint();

	DECLARE_MESSAGE_MAP();


	
};
BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

	

class CMyApp : public CWinApp {
public:
	CMyApp() {}; // конструктор
	virtual BOOL InitInstance() {
		m_pMainWnd = new CMyMainWnd();
		m_pMainWnd->ShowWindow(SW_SHOW);
		return TRUE;
	}
};
CMyApp theApp;

void CMyMainWnd::OnPaint() {
	CPaintDC dc(this);
	CFont font;
	CFont font2;
	CFont font3;
	font.CreateFont(rand()%20+20, 0, 0, 0, SYMBOL_FONTTYPE, FALSE, FALSE, 0, DEFAULT_CHARSET,
		  OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		   DEFAULT_PITCH | FF_SWISS, L"AAAAA");
	font2.CreateFont(rand() % 20 + 18, 0, 0, 0, ITALIC_FONTTYPE, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, L"ZZZZZ");
	font3.CreateFont(rand() % 30 + 18, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, L"56565");
	int random = rand() % 3;
	if (random == 1)
	{
		dc.SelectObject(font);
	}
	if (random == 2)
	{
		dc.SelectObject(font2);
	}
	if (random == 3)
	{
		dc.SelectObject(font3);
	}
	CTime ct = CTime::GetCurrentTime();	// получить текущее время
	
	dc.SetTextColor(RGB(rand()%255, rand() % 255, rand() % 255)); // устанавливаем цвет фонта
	
	
	CString s = ct.Format("%d.%m.%Y %H:%M:%S");
	dc.TextOut(10, 10, s);

	
	
		if (i == 0)
		{
			dc.Arc(50, 50, 200, 200, 100, 100, 10, 10);
		
			
		} // окружность
		if (i == 1)
		{
			dc.Ellipse(50, 100, h + 150, w + 100);
		} // эллипс
		if (i == 2)
		{
			dc.Rectangle(x + 50, y + 50, h + 400, w + 50);
		} //прямоугольник
		if (i == 3)
		{
			dc.Rectangle(x + 50, y + 50, h + 50, w + 50);
		}  //квадрат
		if (i == 4)
		{
			dc.Chord(x + 50, y + 50, h + 50, w + 50, 130, 130, 50, 50);
		} // сегмент
		if (i == 5)
		{
			dc.Pie(x + 50, y + 50, h + 100, w + 100, 60, 60, 60, 170);
		}//сектор
	
	
}
void CMyMainWnd::OnLButtonDown(UINT, CPoint) {

	i++;
	
	if (i > 5) i = 0;
	this->Invalidate();
	
	
}







