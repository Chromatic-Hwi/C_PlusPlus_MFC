﻿
// ViewerTempDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ViewerTemp.h"
#include "ViewerTempDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CViewerTempDlg 대화 상자



CViewerTempDlg::CViewerTempDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VIEWERTEMP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CViewerTempDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CViewerTempDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_OPEN32771, &CViewerTempDlg::OnMenuFileOpen)
	ON_BN_CLICKED(IDOK, &CViewerTempDlg::OnBnClickedOk)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDCANCEL, &CViewerTempDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CViewerTempDlg 메시지 처리기

BOOL CViewerTempDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	m_image.Load(L"TestCard.PNG");

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CViewerTempDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CViewerTempDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();

		/*
		고정 경로의 이미지만 출력하는 코드
		CPaintDC dc(this);
		m_image.Draw(dc, 0, 0);
		*/
		
		/*
		CPaintDC dc(this);
		CString strData = _T("");
		strData.Format(_T("X:%03d, Y:%03d"), m_ptMouse.x, m_ptMouse.y);
		dc.TextOutW(10, 10, strData);
		*/
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CViewerTempDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CViewerTempDlg::OnMenuFileOpen()
{
	CFileDialog dlg(TRUE);
	UINT ok = dlg.DoModal(); // 파일 열기 창 표시

	if (ok == IDOK)
	{
		CString filepath = dlg.GetPathName(); // 전체 경로를 입력하는 함수
		CImage m_image2;
		m_image2.Load(filepath);
		int w, h;
		w = m_image2.GetWidth();
		h = m_image2.GetHeight();
		RedrawWindow();
		CPaintDC dc(this);
		//CCleintDC dc(this); 도 똑같이 동작함.
		m_image2.Draw(dc, 0, 0, w, h);
	}
}

void CViewerTempDlg::OnBnClickedOk()
{
	//CDialogEx::OnOK();
	RedrawWindow();
}

void CViewerTempDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	m_ptMouse = point;
	//RedrawWindow();
	CDialogEx::OnMouseMove(nFlags, point);
}

void CViewerTempDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}
