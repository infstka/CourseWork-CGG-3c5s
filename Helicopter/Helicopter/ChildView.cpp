
// ChildView.cpp : реализация класса CChildView
//

#include "stdafx.h"
#include "Helicopter.h"
#include "ChildView.h"
#include "Settings.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	Timer=false; //время зависания
	Hovering=true; //режим зависания
	RW.SetRect(300,300,400,400);
	ColorOfHelicopterBlade=RGB(255,0,0); //изначальный цвет лопастей
	ColorOfHelicopterBody=RGB(255,0,0); //изначальный цвет корпуса
	Т=1000; //стартовая скорость вращения лопастей
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_32771, &CChildView::On32771)
	ON_COMMAND(ID_32772, &CChildView::On32772)
	ON_COMMAND(ID_32773, &CChildView::On32773)
END_MESSAGE_MAP()



// обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // контекст устройства для рисования
	if(Timer==false){
		SetTimer(1,30,NULL);
		Timer=true;
	}
	HP.Draw(dc,RW,ColorOfHelicopterBlade,ColorOfHelicopterBody);
}


// обработчик нажатия кнопок

void CChildView::OnKeyDown(UINT nChar,UINT nRepCount,UINT nFlags){
	if(nChar==38){	//вверх
		HP.Move(0,-5);
		Invalidate();
	}
	else if(nChar==40){ //вниз
		HP.Move(0,5);
		Invalidate();
	}
	else if(nChar==32){ //вперед
		Hovering=!Hovering;
	}
}

void CChildView::OnTimer(UINT flag){
	if(!Hovering){
		HP.Move(Т/300,0);
	}
	HP.RotorTurn(360/Т*30);
	Invalidate();
}

//вызов диалога установки цвета лопастей
void CChildView::On32771()
{
	CColorDialog DiagColor;
	if(DiagColor.DoModal()==IDOK){
		ColorOfHelicopterBlade=DiagColor.GetColor();
		Invalidate();
	}
}


//вызов диалога установки цвета корпуса
void CChildView::On32772()
{
	CColorDialog DiagColor;
	if(DiagColor.DoModal()==IDOK){
		ColorOfHelicopterBody=DiagColor.GetColor();
		Invalidate();
	}
}

//вызов диалога установки периода вращения
void CChildView::On32773()
{
	Settings MyDialog;
	if(MyDialog.DoModal()==IDOK){
		Т=MyDialog.GetT();
		Invalidate();
	}
}
