
// SdiSeqView.cpp: CSdiSeqView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SdiSeq.h"
#endif

#include "SdiSeqDoc.h"
#include "SdiSeqView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiSeqView

IMPLEMENT_DYNCREATE(CSdiSeqView, CView)

BEGIN_MESSAGE_MAP(CSdiSeqView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSdiSeqView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSdiSeqView 생성/소멸

CSdiSeqView::CSdiSeqView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSdiSeqView::~CSdiSeqView()
{
}

BOOL CSdiSeqView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSdiSeqView 그리기

void CSdiSeqView::OnDraw(CDC* /*pDC*/)
{
	CSdiSeqDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSdiSeqView 인쇄


void CSdiSeqView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSdiSeqView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSdiSeqView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSdiSeqView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CSdiSeqView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSdiSeqView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSdiSeqView 진단

#ifdef _DEBUG
void CSdiSeqView::AssertValid() const
{
	CView::AssertValid();
}

void CSdiSeqView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSdiSeqDoc* CSdiSeqView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiSeqDoc)));
	return (CSdiSeqDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiSeqView 메시지 처리기
