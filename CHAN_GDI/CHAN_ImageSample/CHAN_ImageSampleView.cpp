
// CHAN_ImageSampleView.cpp: CCHANImageSampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "CHAN_ImageSample.h"
#endif

#include "CHAN_ImageSampleDoc.h"
#include "CHAN_ImageSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "resource.h"


// CCHANImageSampleView

IMPLEMENT_DYNCREATE(CCHANImageSampleView, CView)

BEGIN_MESSAGE_MAP(CCHANImageSampleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCHANImageSampleView 생성/소멸

CCHANImageSampleView::CCHANImageSampleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCHANImageSampleView::~CCHANImageSampleView()
{
}

BOOL CCHANImageSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CCHANImageSampleView 그리기

void CCHANImageSampleView::OnDraw(CDC* /*pDC*/)
{
	CCHANImageSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CCHANImageSampleView 인쇄

BOOL CCHANImageSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCHANImageSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCHANImageSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CCHANImageSampleView 진단

#ifdef _DEBUG
void CCHANImageSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CCHANImageSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCHANImageSampleDoc* CCHANImageSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCHANImageSampleDoc)));
	return (CCHANImageSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CCHANImageSampleView 메시지 처리기


void CCHANImageSampleView::OnPaint()
{
	CPaintDC dc(this); 

	// 일반적인 이미지 불러오기 방식 
	// 해당 방식은 이미지소스를 외부에서 변경하면 
	// 변경된 이미지 소스를 그대로 불러오는 위혐성이 있다. 
	CImage img;
	img.Load(_T("res//CHAN.jpg"));
	img.BitBlt(dc.m_hDC, 0, 0);

	// 해당 방식은 이미지 소스를 리소스에 저장하고 불러내는 방식
	// 안전한 방법이지만 빌드 프로그램 용량이 커질 수 있음
	CImage mountedImg; 
	mountedImg.LoadFromResource(AfxGetApp()->m_hInstance, IDB_BITMAP_CHAN);
	mountedImg.BitBlt(dc.m_hDC, 500, 0);
	

	CImageList list;
	list.Create(
		128,			// 각 이미지의 크기(픽셀) x
		128,			// 각 이미지의 크기(픽셀) y
		ILC_COLOR32,	// 만들 이미지의 형식 지정
		3,				// 이미지 목록의 처음 포함된 이미지 수(리스트 길이)
		0				// 스페어 이미지 인덱스 수 
	);
	list.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	list.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	list.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	list.Draw(
		&dc,				// 현재 dc
		0,					// 출력할 이미지 리스트 인덱스
		CPoint(0, 400),		// 아이콘 출력 좌표
		ILD_TRANSPARENT		// 투명성 보장
		);
	list.Draw(
		&dc,				// 현재 dc
		1,					// 출력할 이미지 리스트 인덱스
		CPoint(200, 400),	// 아이콘 출력 좌표
		ILD_TRANSPARENT		// 투명성 보장
	);
	list.Draw(
		&dc,				// 현재 dc
		2,					// 출력할 이미지 리스트 인덱스
		CPoint(400, 400),	// 아이콘 출력 좌표
		ILD_TRANSPARENT		// 투명성 보장
	);

}
