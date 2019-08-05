#pragma once
class DrawSolution
{
public:
	CDC *pdc;
	void Setpdc(CDC *dc);
	DrawSolution();
	~DrawSolution();
	void Cirpot(int x0, int y0,int x, int y);
	void Bres_Circle(CPoint Center,CPoint Radius);

};

