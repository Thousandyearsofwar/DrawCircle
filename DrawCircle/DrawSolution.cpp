#include "stdafx.h"
#include "DrawSolution.h"


void DrawSolution::Setpdc(CDC *dc)
{
	this->pdc = dc;
}

DrawSolution::DrawSolution()
{
}


DrawSolution::~DrawSolution()
{
}

void DrawSolution::Cirpot(int x0, int y0, int x, int y)
{
	this->pdc->SetPixel((x0+x),(y0+y),RGB(0,0,0));
	this->pdc->SetPixel((x0+y),(y0+x),RGB(0,0,0));
	this->pdc->SetPixel((x0+y),(y0-x),RGB(0,0,0));
	this->pdc->SetPixel((x0+x),(y0-y),RGB(0,0,0));
	this->pdc->SetPixel((x0-x),(y0-y),RGB(0,0,0));
	this->pdc->SetPixel((x0-y),(y0-x),RGB(0,0,0));
	this->pdc->SetPixel((x0-y),(y0+x),RGB(0,0,0));
	this->pdc->SetPixel((x0-x),(y0+y),RGB(0,0,0));


}

void DrawSolution::Bres_Circle(CPoint Center, CPoint Radius)
{
	int x0=Center.x, y0=Center.y;
	double r=sqrt((Radius.x-Center.x)*(Radius.x - Center.x)+ (Radius.y - Center.y)*(Radius.y - Center.y));

	int x, y, d;

	x = 0;
	y = (int)r;
	d = int(3 - 2 * r);
	while (x < y) {
		Cirpot(x0, y0, x, y);
		if (d < 0)
			d += 4 * x + 6;
		else {
			d += 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
	if (x = y)
		Cirpot(x0,y0,x,y);
}

void DrawSolution::MidPoint_Circle(CPoint Center, CPoint Radius)
{
	int x0 = Center.x, y0 = Center.y;
	double r = sqrt((Radius.x - Center.x)*(Radius.x - Center.x) + (Radius.y - Center.y)*(Radius.y - Center.y));


	int x = 0, y = r;
	int d = 1 - r;
	Cirpot(x0, y0, x, y);
	while (x < y) {
	
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		Cirpot(x0, y0, x, y);
	}
	
}


