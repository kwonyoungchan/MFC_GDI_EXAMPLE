
// CHAN_PenSampleView.h: CCHANPenSampleView 클래스의 인터페이스
//

#pragma once


class CCHANPenSampleView : public CView
{
protected: // serialization에서만 만들어집니다.
	CCHANPenSampleView() noexcept;
	DECLARE_DYNCREATE(CCHANPenSampleView)

// 특성입니다.
public:
	CCHANPenSampleDoc* GetDocument() const;

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
	virtual ~CCHANPenSampleView();
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
	void DrawBackground(CPaintDC& dc);
	void DrawRect(CPaintDC& dc);
	void DrawPen(CPaintDC& dc);

	void DrawBadCase(CPaintDC& dc);
};

#ifndef _DEBUG  // CHAN_PenSampleView.cpp의 디버그 버전
inline CCHANPenSampleDoc* CCHANPenSampleView::GetDocument() const
   { return reinterpret_cast<CCHANPenSampleDoc*>(m_pDocument); }
#endif

