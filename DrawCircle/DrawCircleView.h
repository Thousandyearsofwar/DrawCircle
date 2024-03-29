﻿
// DrawCircleView.h: CDrawCircleView 类的接口
//

#pragma once
#include"DrawSolution.h"

class CDrawCircleView : public CView
{
protected: // 仅从序列化创建
	CDrawCircleView() noexcept;
	DECLARE_DYNCREATE(CDrawCircleView)
	CPoint Center;
	CPoint Radius;


// 特性
public:
	CDrawCircleDoc* GetDocument() const;

// 操作
public:
	DrawSolution Sol;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDrawCircleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DrawCircleView.cpp 中的调试版本
inline CDrawCircleDoc* CDrawCircleView::GetDocument() const
   { return reinterpret_cast<CDrawCircleDoc*>(m_pDocument); }
#endif

