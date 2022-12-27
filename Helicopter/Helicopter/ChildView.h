
// ChildView.h : ��������� ������ CChildView
//


#pragma once
#include "HelicopterPoints.h"

// ���� CChildView

class CChildView : public CWnd
{
// ��������
public:
	CChildView();

// ��������
public:
	HelicopterPoints HP;
	CRect RW;
	double �;
	COLORREF ColorOfHelicopterBlade, ColorOfHelicopterBody;
	bool Hovering,Timer; //���������, ������
// ��������
public:

// ���������������
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����������
public:
	virtual ~CChildView();

	// ��������� ������� ����� ���������
protected:
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT flag);
	afx_msg void OnKeyDown(UINT nChar,UINT nRepCount,UINT nFlags);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
};

