// Settings.cpp: ���� ����������
//

#include "stdafx.h"
#include "Helicopter.h"
#include "Settings.h"
#include "afxdialogex.h"


// ���������� ���� Settings

IMPLEMENT_DYNAMIC(Settings, CDialogEx)

Settings::Settings(CWnd* pParent /*=NULL*/)
	: CDialogEx(Settings::IDD, pParent)
{

	EnableAutomation();
	�=10;
}

Settings::~Settings()
{
}

void Settings::OnFinalRelease()
{
	// ����� ����� ����������� ��������� ������ �� ������ �������������,
	// ���������� OnFinalRelease. ������� ����� �������������
	// ������ ������. ����� ������� �������� ������ ��������
	// �������������� �������, ����������� ������ �������.

	CDialogEx::OnFinalRelease();
}

void Settings::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, Slider);
}


BEGIN_MESSAGE_MAP(Settings, CDialogEx)
	ON_BN_CLICKED(IDOK, &Settings::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Settings::OnBnClickedCancel)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &Settings::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Settings, CDialogEx)
END_DISPATCH_MAP()

// ����������: �� �������� ��������� ��� IID_ISettings, ����� ���������� ���������� � ����� ������ ����� ��������
//  �� VBA. ���� IID ������ ��������������� GUID, ���������� � 
//  disp-����������� � ����� .IDL.

// {B19C8FA6-0A8B-4961-BEC4-D4D9E596EA8A}
static const IID IID_ISettings =
{ 0xB19C8FA6, 0xA8B, 0x4961, { 0xBE, 0xC4, 0xD4, 0xD9, 0xE5, 0x96, 0xEA, 0x8A } };

BEGIN_INTERFACE_MAP(Settings, CDialogEx)
	INTERFACE_PART(Settings, IID_ISettings, Dispatch)
END_INTERFACE_MAP()


// ����������� ��������� Settings


void Settings::OnBnClickedOk()
{
	// TODO: �������� ���� ��� ����������� �����������
	CDialogEx::OnOK();
}


void Settings::OnBnClickedCancel()
{
	// TODO: �������� ���� ��� ����������� �����������
	CDialogEx::OnCancel();
}


void Settings::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	�=Slider.GetPos()*99.9+10;
	*pResult = 0;
}

double Settings::GetT(){
	return �;
}