
// Helicopter.h : главный файл заголовка для приложения Helicopter
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CHelicopterApp:
// О реализации данного класса см. Helicopter.cpp
//

class CHelicopterApp : public CWinApp
{
public:
	CHelicopterApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHelicopterApp theApp;
