#pragma once
#include "MyGDI.H"
class HelicopterPoints
{
public:
	HelicopterPoints(void);
	CRectD rs;
	CMatrix HelicopterBodyPoints,HelicopterRotorPoints;
	double Corner,X,Y;
	void Draw(CDC& dc,CRect& RW,COLORREF ColorOfHelicopterRotor,COLORREF ColorOfHelicopterBody);
	void RotorTurn(double Crnr);
	void Move(double X,double Y);
	~HelicopterPoints(void);
};

