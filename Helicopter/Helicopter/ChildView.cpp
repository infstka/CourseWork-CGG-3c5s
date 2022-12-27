
// ChildView.cpp : ���������� ������ CChildView
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
	Timer=false; //����� ���������
	Hovering=true; //����� ���������
	RW.SetRect(300,300,400,400);
	ColorOfHelicopterBlade=RGB(255,0,0); //����������� ���� ��������
	ColorOfHelicopterBody=RGB(255,0,0); //����������� ���� �������
	�=1000; //��������� �������� �������� ��������
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



// ����������� ��������� CChildView

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
	CPaintDC dc(this); // �������� ���������� ��� ���������
	if(Timer==false){
		SetTimer(1,30,NULL);
		Timer=true;
	}
	HP.Draw(dc,RW,ColorOfHelicopterBlade,ColorOfHelicopterBody);
}


// ���������� ������� ������

void CChildView::OnKeyDown(UINT nChar,UINT nRepCount,UINT nFlags){
	if(nChar==38){	//�����
		HP.Move(0,-5);
		Invalidate();
	}
	else if(nChar==40){ //����
		HP.Move(0,5);
		Invalidate();
	}
	else if(nChar==32){ //������
		Hovering=!Hovering;
	}
}

void CChildView::OnTimer(UINT flag){
	if(!Hovering){
		HP.Move(�/300,0);
	}
	HP.RotorTurn(360/�*30);
	Invalidate();
}

//����� ������� ��������� ����� ��������
void CChildView::On32771()
{
	CColorDialog DiagColor;
	if(DiagColor.DoModal()==IDOK){
		ColorOfHelicopterBlade=DiagColor.GetColor();
		Invalidate();
	}
}


//����� ������� ��������� ����� �������
void CChildView::On32772()
{
	CColorDialog DiagColor;
	if(DiagColor.DoModal()==IDOK){
		ColorOfHelicopterBody=DiagColor.GetColor();
		Invalidate();
	}
}

//����� ������� ��������� ������� ��������
void CChildView::On32773()
{
	Settings MyDialog;
	if(MyDialog.DoModal()==IDOK){
		�=MyDialog.GetT();
		Invalidate();
	}
}
