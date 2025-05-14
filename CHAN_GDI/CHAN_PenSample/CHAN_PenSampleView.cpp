
// CHAN_PenSampleView.cpp: CCHANPenSampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "CHAN_PenSample.h"
#endif

#include "CHAN_PenSampleDoc.h"
#include "CHAN_PenSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCHANPenSampleView

IMPLEMENT_DYNCREATE(CCHANPenSampleView, CView)

BEGIN_MESSAGE_MAP(CCHANPenSampleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCHANPenSampleView 생성/소멸

CCHANPenSampleView::CCHANPenSampleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCHANPenSampleView::~CCHANPenSampleView()
{
}

BOOL CCHANPenSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CCHANPenSampleView 그리기

void CCHANPenSampleView::OnDraw(CDC* /*pDC*/)
{
	CCHANPenSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CCHANPenSampleView 인쇄

BOOL CCHANPenSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCHANPenSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCHANPenSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CCHANPenSampleView 진단

#ifdef _DEBUG
void CCHANPenSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CCHANPenSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCHANPenSampleDoc* CCHANPenSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCHANPenSampleDoc)));
	return (CCHANPenSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CCHANPenSampleView 메시지 처리기


void CCHANPenSampleView::OnPaint()
{
	CPaintDC dc(this);
	// ** 주의 ** : 펜, 도형, 브러쉬, 텍스트를 그릴 때 그리는 순서를 생각하고 그려야 한다. 
	
	// ======= 순서==========
	// 0. 바탕화면 그리기 샘플
	// 1. 팬 그리기 샘플 
	// 2. 도형 그리기 샘플 
	// 3. 그리기 작업 중 나쁜 케이스 
	DrawBackground(dc);
	DrawPen(dc);
	DrawRect(dc);
	DrawBadCase(dc);

}

void CCHANPenSampleView::DrawBackground(CPaintDC& dc)
{
	// 사각형 테두리 없애는 구문
	CPen nullPen(PS_NULL, 0, (COLORREF)0);
	
	// 도형 색상 정의하는 브러쉬 객체 
	CBrush backgroundColor = RGB(100, 100, 100);

	// 배경으로 사용할 사각형 객체 생성 
	CRect rect;
	// 클라이언트 영역 윈도우 사이즈 정보를 rect 객체로 가져온다.
	this->GetClientRect(&rect);

	// 앞으로 그리게 될 색상을 배경 색상으로 설정
	dc.SelectObject(&backgroundColor);
	// 사각형 테두리 제거 설정 
	dc.SelectObject(&nullPen);
	// 사각형 그리기 
	dc.Rectangle(&rect);
}

void CCHANPenSampleView::DrawRect(CPaintDC& dc)
{
	// 도형 색상 정의하는 브러쉬 객체 
	CBrush brush = RGB(100, 200, 100);
	// 사각형 테두리 없애는 구문
	CPen nullPen(PS_NULL, 0, (COLORREF)0);

	// 사각형 객체 생성 
	CRect rect(
		200,	// 시작 좌표 x
		400,	// 시작 좌표 y
		300,	// 종료 좌표 x
		500		// 종료 좌표 y
	);

	// 앞으로 그리게 될 색상을 브러쉬 색상으로 설정
	dc.SelectObject(&brush);
	// 테두리 제거
	dc.SelectObject(&nullPen);
	// 사각형 그리기 
	dc.Rectangle(&rect);
}

void CCHANPenSampleView::DrawPen(CPaintDC& dc)
{
	// 팬 객체 생성 (
	CPen Pen(
		PS_SOLID,			// 펜 스타일 (자세한 정보는 DOC참조)
		5,					// 펜 두께
		RGB(255, 0, 0)		// 펜 색상
	);

	// 색상 정보를 파라매터에서 매크로 사용하지않고 객체 생성하여 부르는 방법은 아래와 같다.
	COLORREF cBlue = RGB(0, 0, 192);
	CPen PenBlue(
		PS_SOLID,			// 펜 스타일 (자세한 정보는 DOC참조)
		5,					// 펜 두께
		cBlue		// 펜 색상
	);

	// 제어하고자 하는 객체를 펜 객체로 설정한다. 
	dc.SelectObject(&Pen);
	// 펜 그리기 기준점(원점) 이동
	dc.MoveTo(100, 100);
	// 원점에서 정의된 좌표까지 선긋기
	dc.LineTo(200, 100);

	dc.SelectObject(&PenBlue);
	dc.MoveTo(100, 200);
	dc.LineTo(200, 200);
}

// 해당 함수는 펜을 그리고 도형을 그리는 함수이다.
// 이론상으로 도형 위에 직선이 있을 것 같지만 실제는 
// 펜이 그려진 위치에 도형이 그대로 덮어씌어지게 된다. 
void CCHANPenSampleView::DrawBadCase(CPaintDC& dc)
{
	CBrush OverDrawnRectColor = RGB(200, 200, 200);

	// 팬 객체 생성 (
	CPen Pen(
		PS_SOLID,			// 펜 스타일 (자세한 정보는 DOC참조)
		5,					// 펜 두께
		RGB(255, 0, 0)		// 펜 색상
	);
	
	dc.SelectObject(&Pen);
	dc.MoveTo(500, 200);
	dc.LineTo(900, 200);
	dc.MoveTo(500, 210);
	dc.LineTo(900, 210);

	dc.SelectObject(&OverDrawnRectColor);
	CRect Rect(600,100,800,300);
	dc.Rectangle(&Rect);
}


