
// CHAN_FontSampleView.h: CCHANFontSampleView 클래스의 인터페이스
//

#pragma once


class CCHANFontSampleView : public CView
{
protected: // serialization에서만 만들어집니다.
	CCHANFontSampleView() noexcept;
	DECLARE_DYNCREATE(CCHANFontSampleView)

// 특성입니다.
public:
	CCHANFontSampleDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CCHANFontSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
public:
	void DrawDefaultText(CPaintDC& dc);
	void DrawColorText(CPaintDC& dc);
	void DrawTextWithBkColor(CPaintDC& dc);
	void SetTextFont(CPaintDC& dc);
	void DrawTabbedText(CPaintDC& dc);
	void UseDrawTextFunc(CPaintDC& dc);
};

#ifndef _DEBUG  // CHAN_FontSampleView.cpp의 디버그 버전
inline CCHANFontSampleDoc* CCHANFontSampleView::GetDocument() const
   { return reinterpret_cast<CCHANFontSampleDoc*>(m_pDocument); }
#endif

