
// Helicopter.h : ������� ���� ��������� ��� ���������� Helicopter
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CHelicopterApp:
// � ���������� ������� ������ ��. Helicopter.cpp
//

class CHelicopterApp : public CWinApp
{
public:
	CHelicopterApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHelicopterApp theApp;
