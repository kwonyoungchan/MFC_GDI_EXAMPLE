
// CHAN_FontSampleView.cpp: CCHANFontSampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "CHAN_FontSample.h"
#endif

#include "CHAN_FontSampleDoc.h"
#include "CHAN_FontSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCHANFontSampleView

IMPLEMENT_DYNCREATE(CCHANFontSampleView, CView)

BEGIN_MESSAGE_MAP(CCHANFontSampleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCHANFontSampleView 생성/소멸

CCHANFontSampleView::CCHANFontSampleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCHANFontSampleView::~CCHANFontSampleView()
{
}

BOOL CCHANFontSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CCHANFontSampleView 그리기

void CCHANFontSampleView::OnDraw(CDC* /*pDC*/)
{
	CCHANFontSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CCHANFontSampleView 인쇄

BOOL CCHANFontSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCHANFontSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCHANFontSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CCHANFontSampleView 진단

#ifdef _DEBUG
void CCHANFontSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CCHANFontSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCHANFontSampleDoc* CCHANFontSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCHANFontSampleDoc)));
	return (CCHANFontSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CCHANFontSampleView 메시지 처리기


void CCHANFontSampleView::OnPaint()
{
	CPaintDC dc(this); 
	
	// 기본 배경화면 설정 
	CRect Rect;
	CBrush BackgroundColor = RGB(225, 225, 225);
	this->GetClientRect(&Rect);

	dc.SelectObject(&BackgroundColor);
	dc.Rectangle(&Rect);

	DrawDefaultText(dc);
	DrawColorText(dc);
	DrawTextWithBkColor(dc);
	SetTextFont(dc);
	DrawTabbedText(dc);
	UseDrawTextFunc(dc);
}

// 아주 기본적인 텍스트 그리는 법 
// Q. 텍스트는 작성하는게 아니나요? 
// A. 결국에는 윈도우에 보여져야 하니까 그리는게 맞죠.
void CCHANFontSampleView::DrawDefaultText(CPaintDC& dc)
{
	// 텍스트 박스의 배경 색상을 윈도우 배경 색상과 일치시켜준다.
	// 이것을 입력하지 않고 텍스트를 출력하면 흰 바탕의 텍스트 박스가 출력된다. 
	dc.SetBkMode(TRANSPARENT);

	dc.TextOut(
		20,		// x 좌표
		10,		// y 좌표 
		_T("1. This is Default Text Example.")	// 코멘트
	);

}

void CCHANFontSampleView::DrawColorText(CPaintDC& dc)
{
	dc.SetTextColor(RGB(225, 0, 0));
	dc.TextOut(
		20,		// x 좌표
		50,		// y 좌표 
		_T("2. This is Red Color Text Example.")	// 코멘트
	);
	dc.SetTextColor(RGB(0, 0, 0));
}

void CCHANFontSampleView::DrawTextWithBkColor(CPaintDC& dc)
{
	dc.SetBkMode(OPAQUE);
	dc.SetBkColor(RGB(255, 255, 0));

	dc.TextOut(
		20,		// x 좌표
		100,		// y 좌표 
		_T("3. This is Yellow Background Color Text Example.")	// 코멘트
	);

	dc.SetBkMode(TRANSPARENT);
}

// 폰트 객체를 생성하여 텍스트에 내가 원하는 폰트를 적용하는 예제
// 나중에 일 귀찮아질 수 있으니, 초기 실행 할 때 내가 사용하고자 하는 폰트들을 미리 생성해놓는 것이 좋음.
void CCHANFontSampleView::SetTextFont(CPaintDC& dc)
{
	// 가장 일반적인 폰트 생성 방법
	CFont fnt;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));

	lf.lfHeight = 36;								// 폰트 픽셀단위 크기 정의

	wsprintf(lf.lfFaceName, _T("%s"), _T("Arial"));	// 폰트 정의 
	fnt.CreateFontIndirect(&lf);					// 폰트 생성
	
	dc.SelectObject(&fnt);
	dc.TextOut(
		20,
		150,
		_T("4. This is Arial Font Text Example.")
	);
}

// 탭이 들어간 텍스트를 입력할 때 사용하기 좋은 예시
void CCHANFontSampleView::DrawTabbedText(CPaintDC& dc)
{
	CFont fnt;

	int nTabStop = 40; // tab 할 픽셀 길이
	dc.TextOut(20, 200, _T("5. Tabbed String Example."));
	dc.TabbedTextOut(20, 250, _T("\t1 Tabbed String."), 1, &nTabStop, 20);
	dc.TabbedTextOut(20, 300, _T("\t\t2 Tabbed String."), 1, &nTabStop, 20);
}

// TextOut() 함수가 있는데 DrawText()는 어디에 쓰는걸까?
// -> 텍스트를 정렬 해야 할 때 해당 함수를 많이 사용함. 
void CCHANFontSampleView::UseDrawTextFunc(CPaintDC& dc)
{
	CRect textBox(20,350,300,500);
	CBrush textBoxColor = RGB(255, 255, 255);

	dc.SelectObject(&textBoxColor);
	dc.Rectangle(&textBox);
	
	dc.DrawText(
		_T("6. DrawText Function Example !!!!!!!!!"),		// 코멘트
		&textBox,											// 텍스트 적용 할 네모
		DT_WORDBREAK | DT_LEFT								// 텍스트 정렬 설정 
	);

}
