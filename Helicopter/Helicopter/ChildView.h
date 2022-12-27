
// ChildView.h : интерфейс класса CChildView
//


#pragma once
#include "HelicopterPoints.h"

// окно CChildView

class CChildView : public CWnd
{
// Создание
public:
	CChildView();

// Атрибуты
public:
	HelicopterPoints HP;
	CRect RW;
	double Т;
	COLORREF ColorOfHelicopterBlade, ColorOfHelicopterBody;
	bool Hovering,Timer; //зависание, таймер
// Операции
public:

// Переопределение
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CChildView();

	// Созданные функции схемы сообщений
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

