
// DrawCircleView.cpp: CDrawCircleView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DrawCircle.h"
#endif

#include "DrawCircleDoc.h"
#include "DrawCircleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawCircleView

IMPLEMENT_DYNCREATE(CDrawCircleView, CView)

BEGIN_MESSAGE_MAP(CDrawCircleView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDrawCircleView 构造/析构

CDrawCircleView::CDrawCircleView() noexcept
{
	// TODO: 在此处添加构造代码

}

CDrawCircleView::~CDrawCircleView()
{
}

BOOL CDrawCircleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawCircleView 绘图

void CDrawCircleView::OnDraw(CDC* /*pDC*/)
{
	CDrawCircleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CDrawCircleView 打印

BOOL CDrawCircleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawCircleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawCircleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDrawCircleView 诊断

#ifdef _DEBUG
void CDrawCircleView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawCircleDoc* CDrawCircleView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawCircleDoc)));
	return (CDrawCircleDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawCircleView 消息处理程序


void CDrawCircleView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	this->Center = point;
	CDC *pdc=this->GetDC();
	
	pdc->Ellipse(point.x-5,point.y-5,point.x+5,point.y+5);


	this->ReleaseDC(pdc);
	CView::OnRButtonDown(nFlags, point);
}


void CDrawCircleView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	this->Radius = point;
	CDC *pdc = this->GetDC();
	pdc->MoveTo(this->Center);
	pdc->LineTo(this->Radius);
	this->Sol.Setpdc(pdc);
	this->Sol.Bres_Circle(this->Center, this->Radius);
	CView::OnRButtonUp(nFlags, point);
}
