
// CHAN_BmpSampleView.cpp: CCHANBmpSampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "CHAN_BmpSample.h"
#endif

#include "CHAN_BmpSampleDoc.h"
#include "CHAN_BmpSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCHANBmpSampleView

IMPLEMENT_DYNCREATE(CCHANBmpSampleView, CView)

BEGIN_MESSAGE_MAP(CCHANBmpSampleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCHANBmpSampleView 생성/소멸

CCHANBmpSampleView::CCHANBmpSampleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCHANBmpSampleView::~CCHANBmpSampleView()
{
}

BOOL CCHANBmpSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CCHANBmpSampleView 그리기

void CCHANBmpSampleView::OnDraw(CDC* /*pDC*/)
{
	CCHANBmpSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CCHANBmpSampleView 인쇄

BOOL CCHANBmpSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCHANBmpSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCHANBmpSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CCHANBmpSampleView 진단

#ifdef _DEBUG
void CCHANBmpSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CCHANBmpSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCHANBmpSampleDoc* CCHANBmpSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCHANBmpSampleDoc)));
	return (CCHANBmpSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CCHANBmpSampleView 메시지 처리기


void CCHANBmpSampleView::OnPaint()
{
	CPaintDC dc(this); 

	CDC memdc;
	memdc.CreateCompatibleDC(&dc);		// 해당 윈도우 체계와 호환되는 memory dc 생성 

	CBitmap bmp; 
	bmp.LoadBitmap(IDB_CHAN);			// 비트맵 소스를 res 디렉토리에서 불러오기 
	BITMAP info = { 0 };				// 비트맵 정보 구조체 생성 
	bmp.GetBitmap(&info);				// 불러온 비트맵 정보를 생성한 구조체에 저장 
	memdc.SelectObject(&bmp);			// memory dc에 비트맵 정보 등록 

	// 생성한 memory dc에 각종 GDI들을 기존 dc처럼 생성하여 등록할 수 있다. 
	// 이렇게 해서 한번에 일괄적으로 bitblt 시키는게 성능이 더 좋고 빠른 장점이 있다. 
	// 나중에 Double Buffering 기법 쓸 때도 요긴하게 쓰인다. 
	CRect rect(100, 100, 150, 150);
	CBrush color = RGB(0, 225, 0);

	memdc.SelectObject(&color);
	memdc.Rectangle(rect);

	dc.BitBlt(
		0,				// Draw 시작 좌표 x
		0,				// Draw 시작 좌표 y
		info.bmWidth,	// Draw 할 비트맵 width
		info.bmHeight,	// Draw 할 비트맵 height
		&memdc,			// Draw 할 dc
		0,				// Draw 할 dc 소스 시작 좌표 x
		0,				// Draw 할 dc 소스 시작 좌표 y
		SRCCOPY			// Draw 모드 
	);

}
