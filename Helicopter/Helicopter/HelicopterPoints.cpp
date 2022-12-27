#include "StdAfx.h"
#include "HelicopterPoints.h"


HelicopterPoints::HelicopterPoints(void)
{
	//угол
	Corner = 0; X = 0; Y = 0;

	//устаналиваем начальное положение корпуса и винта
	HelicopterBodyPoints.RedimMatrix(3,18);
	HelicopterRotorPoints.RedimMatrix(3,28);

	//точки корпуса
	for(int i=0;i<18;i++)
	{
		HelicopterBodyPoints(2,i)=1;
	}

	//точки винта
	for(int i=0;i<28;i++)
	{
		HelicopterRotorPoints(2,i)=1;
	}

	HelicopterBodyPoints(0,0)=-10;
	HelicopterBodyPoints(1,0)=20;
	HelicopterBodyPoints(0,1)=10;
	HelicopterBodyPoints(1,1)=20;
	HelicopterBodyPoints(0,2)=20;
	HelicopterBodyPoints(1,2)=10;
	HelicopterBodyPoints(0,3)=20;
	HelicopterBodyPoints(1,3)=-10;
	HelicopterBodyPoints(0,4)=10;
	HelicopterBodyPoints(1,4)=-20;
	HelicopterBodyPoints(0,5)=-10;
	HelicopterBodyPoints(1,5)=-20;
	HelicopterBodyPoints(0,6)=-30;
	HelicopterBodyPoints(1,6)=-15;
	HelicopterBodyPoints(0,7)=-130;
	HelicopterBodyPoints(1,7)=-5;
	HelicopterBodyPoints(0,8)=-130;
	HelicopterBodyPoints(1,8)=-15;
	HelicopterBodyPoints(0,9)=-135;
	HelicopterBodyPoints(1,9)=-15;
	HelicopterBodyPoints(0,10)=-135;
	HelicopterBodyPoints(1,10)=-5;
	HelicopterBodyPoints(0,11)=-140;
	HelicopterBodyPoints(1,11)=-5;
	HelicopterBodyPoints(0,12)=-140;
	HelicopterBodyPoints(1,12)=5;
	HelicopterBodyPoints(0,13)=-135;
	HelicopterBodyPoints(1,13)=5;
	HelicopterBodyPoints(0,14)=-135;
	HelicopterBodyPoints(1,14)=15;
	HelicopterBodyPoints(0,15)=-130;
	HelicopterBodyPoints(1,15)=15;
	HelicopterBodyPoints(0,16)=-130;
	HelicopterBodyPoints(1,16)=5;
	HelicopterBodyPoints(0,17)=-30;
	HelicopterBodyPoints(1,17)=15;

		HelicopterRotorPoints(0,0)=-5;
		HelicopterRotorPoints(1,0)=5;
		HelicopterRotorPoints(0,1)=-5;
		HelicopterRotorPoints(1,1)=15;
		HelicopterRotorPoints(0,2)=-10;
		HelicopterRotorPoints(1,2)=15;
		HelicopterRotorPoints(0,3)=-10;
		HelicopterRotorPoints(1,3)=100;
		HelicopterRotorPoints(0,4)=10;
		HelicopterRotorPoints(1,4)=100;
		HelicopterRotorPoints(0,5)=10;
		HelicopterRotorPoints(1,5)=15;
		HelicopterRotorPoints(0,6)=5;
		HelicopterRotorPoints(1,6)=15;

		HelicopterRotorPoints(0,7)=5;
		HelicopterRotorPoints(1,7)=5;
		HelicopterRotorPoints(0,8)=15;
		HelicopterRotorPoints(1,8)=5;
		HelicopterRotorPoints(0,9)=15;
		HelicopterRotorPoints(1,9)=10;
		HelicopterRotorPoints(0,10)=100;
		HelicopterRotorPoints(1,10)=10;
		HelicopterRotorPoints(0,11)=100;
		HelicopterRotorPoints(1,11)=-10;
		HelicopterRotorPoints(0,12)=15;
		HelicopterRotorPoints(1,12)=-10;
		HelicopterRotorPoints(0,13)=15;
		HelicopterRotorPoints(1,13)=-5;

		HelicopterRotorPoints(0,14)=5;
		HelicopterRotorPoints(1,14)=-5;
		HelicopterRotorPoints(0,15)=5;
		HelicopterRotorPoints(1,15)=-15;
		HelicopterRotorPoints(0,16)=10;
		HelicopterRotorPoints(1,16)=-15;
		HelicopterRotorPoints(0,17)=10;
		HelicopterRotorPoints(1,17)=-100;
		HelicopterRotorPoints(0,18)=-10;
		HelicopterRotorPoints(1,18)=-100;
		HelicopterRotorPoints(0,19)=-10;
		HelicopterRotorPoints(1,19)=-15;
		HelicopterRotorPoints(0,20)=-5;
		HelicopterRotorPoints(1,20)=-15;

		HelicopterRotorPoints(0,21)=-5;
		HelicopterRotorPoints(1,21)=-5;
		HelicopterRotorPoints(0,22)=-15;
		HelicopterRotorPoints(1,22)=-5;
		HelicopterRotorPoints(0,23)=-15;
		HelicopterRotorPoints(1,23)=-10;
		HelicopterRotorPoints(0,24)=-100;
		HelicopterRotorPoints(1,24)=-10;
		HelicopterRotorPoints(0,25)=-100;
		HelicopterRotorPoints(1,25)=10;
		HelicopterRotorPoints(0,26)=-15;
		HelicopterRotorPoints(1,26)=10;
		HelicopterRotorPoints(0,27)=-15;
		HelicopterRotorPoints(1,27)=5;
	
	rs.SetRectD(-50,-50,50,50);
}

void HelicopterPoints::Draw(CDC& dc,CRect& RW,COLORREF ColorOfHelicopterBlade,COLORREF ColorOfHelicopterBody){
	CBrush* br=new CBrush(ColorOfHelicopterBody);//кисть для рисования корпуса
	//матрица пересчета из мировой системы координат (МСК) в оконную (ОСК)
	//с учетом смещения вертолета в МСК
	CMatrix K=SpaceToWindow(rs,RW)*Translate2D(X,Y);
	CMatrix KV=Rotate2D(Corner);//матрица пересчета для поворота лопастей
	CPoint* Points=new CPoint[18];//точки корпуса в ОСК
	for(int i=0;i<18;i++){
		CMatrix W(3);
		W=K*HelicopterBodyPoints.GetCol(i);//пересчет координат точек корпуса из МСК в ОСК
		Points[i].x=W(0);
		Points[i].y=W(1);
	}
	dc.SelectObject(br);//выбор кисти
	dc.Polygon(Points,18);//прорисовка корпуса

	Points=new CPoint[28];
	for(int i=0;i<28;i++){
		CMatrix W(3);
		W=K*KV*HelicopterRotorPoints.GetCol(i);//пересчет коорцинат точек лопастей из МСК в ОСК
		Points[i].x=W(0);
		Points[i].y=W(1);
	}
	br=new CBrush(ColorOfHelicopterBlade);//кисть цвета лопастей
	dc.SelectObject(br);//выбор кисти
	dc.Polygon(Points,28);//прорисовка лопастей
	//кружочек - центр вращения лопастей
	CMatrix E(3,2);
	E(0,0)=-10;E(1,0)=-10;E(2,0)=1;
	E(0,1)=10;E(1,1)=10;E(2,1)=1;
	for(int i=0;i<2;i++){
		CMatrix W(3);
		W=K*E.GetCol(i);//пересчет координат кружочка из МСК в ОСК
		Points[i].x=W(0);
		Points[i].y=W(1);
	}
	dc.Ellipse(Points[0].x,Points[0].y,Points[1].x,Points[1].y);
	delete Points;
	delete br;
}

void HelicopterPoints::RotorTurn(double Crnr){
	Corner+=Crnr;
}

//движение вертолета с проверкой вылета за предел экрана
void HelicopterPoints::Move(double iX,double iY){
	X+=iX;
	if(X>700)X-=1400;
	Y+=iY;
	if(Y>700)Y-=1400;
	else if(Y<0)Y+=1400;
}

HelicopterPoints::~HelicopterPoints(void)
{
}
