
// ViewerTempDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ViewerTemp.h"
#include "ViewerTempDlg.h"
#include "afxdialogex.h"
#include "Resource.h"

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
	DDX_Control(pDX, IDC_LOC_X_LIST, m_loc_x_list);
	DDX_Control(pDX, IDC_LOC_Y_LIST, m_loc_y_list);
	DDX_Control(pDX, IDC_RATIO_LIST, m_ratio_list);
}

BEGIN_MESSAGE_MAP(CViewerTempDlg, CDialogEx)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_COMMAND(ID_FILE_OPEN32771, &CViewerTempDlg::OnMenuFileOpen)
ON_BN_CLICKED(IDOK, &CViewerTempDlg::OnBnClickedOk)
ON_WM_MOUSEMOVE()
ON_COMMAND(ID_FILE_RESET, &CViewerTempDlg::OnMenuFileReset)
ON_WM_MOUSEWHEEL()
ON_BN_CLICKED(IDC_ORIGIN_BTN, &CViewerTempDlg::OnBnClickedOriginBtn)
ON_BN_CLICKED(IDC_UP_BTN, &CViewerTempDlg::OnBnClickedUpBtn)
ON_BN_CLICKED(IDC_DOWN_BTN, &CViewerTempDlg::OnBnClickedDownBtn)
ON_WM_HSCROLL()
ON_WM_VSCROLL()
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

	//m_image.Load(L"TestCard.PNG");

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
	{}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CViewerTempDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void ImagePrint(int mode)
{
	switch (mode)
	{
	case 0:// 일반 출력
	{
		
	}
		break;

	case 1:// 원본 배율 출력
	{

	}
		break;

	case 2: // 휠 가변 배율 출력
	{
	
	}
		break;

	case 3: // 버튼 가변 배율 출력
	{
	
	}
		break;
	}
}

void CViewerTempDlg::OnMenuFileOpen()
{
	CFileDialog dlg(TRUE);
	UINT ok = dlg.DoModal(); // 파일 열기 창 표시

	if (ok == IDOK)
	{
		RedrawWindow();
		filepath = dlg.GetPathName(); // 전체 경로를 입력하는 함수

		CPaintDC dc(this);
		CRect Rect;
		GetClientRect(&Rect);

		int rect_width = Rect.right - Rect.left, rect_height = Rect.bottom - Rect.top;
		int rect_ratio = rect_height / rect_width;

		CImage m_image2;
		m_image2.Load(filepath);

		double img_width, img_height;
		img_width = m_image2.GetWidth();
		img_height = m_image2.GetHeight();
		double img_ratio = img_height / img_width;
		double img_ratio_r = img_width / img_height;

		double show_w, show_h;

		if (img_ratio >= 1.) // ratio가 1보다 큰 경우 = 세로가 더 길다 = 세로 기준으로 출력.
		{
			show_w = (rect_height - 90) * img_ratio;
			show_h = rect_height - 90;
			if (show_w <= rect_width)
			{
				m_image2.Draw(dc, 0 - (show_w * m_pos - show_w), 0 - (show_h * m_pos - show_h), show_w * m_pos, show_h * m_pos);
			}
			else // 세로비가 더 길지만, 계산된 가로 출력 길이가 Rect를 초과하는 경우. 가로 기준 제한 출력.
			{
				show_w = rect_width - 160;
				show_h = (rect_width - 160) * img_ratio_r;
				m_image2.Draw(dc, 0 - (show_w * m_pos - show_w), 0 - (show_h * m_pos - show_h), show_w * m_pos, show_h * m_pos);
			}
			origin_w = show_w, origin_h = show_h; // 원본 배율 출력을 위한 변수 설정
		}
		else // ratio가 1보다 작은 경우 = 가로가 더 길다 = 가로 기준으로 출력
		{
			show_w = rect_width - 160;
			show_h = (rect_width - 160) * img_ratio;
			if (show_h <= rect_height)
			{
				m_image2.Draw(dc, 0 - (show_w * m_pos - show_w), 0 - (show_h * m_pos - show_h), show_w * m_pos, show_h * m_pos);
			}
			else // 가로비가 더 길지만, 계산된 세로 출력 길이가 Rect를 초과하는 경우. 세로 기준 제한 출력.
			{
				show_w = (rect_height - 90) * img_ratio_r;
				show_h = rect_height - 90;
				m_image2.Draw(dc, 0 - (show_w * m_pos - show_w), 0 - (show_h * m_pos - show_h), show_w * m_pos, show_h * m_pos);
			}
			origin_w = show_w, origin_h = show_h; // 원본 배율 출력을 위한 변수 설정
		}
	}
}


void CViewerTempDlg::OnBnClickedOk()
{RedrawWindow();}


void CViewerTempDlg::OnMouseMove(UINT nFlags, CPoint point) // 커서 좌표 출력
{
	m_ptMouse = point;
	CDialogEx::OnMouseMove(nFlags, point);
	CString strDataX = _T("");
	CString strDataY = _T("");
	strDataX.Format(_T("    X : %d"), m_ptMouse.x);
	strDataY.Format(_T("    Y : %d"), m_ptMouse.y);
	
	m_loc_x_list.DeleteString(0);
	m_loc_y_list.DeleteString(0);
	m_loc_x_list.AddString(strDataX);
	m_loc_y_list.AddString(strDataY);
	m_loc_x_list.SetCurSel(m_loc_x_list.GetCount() - 1);
	m_loc_y_list.SetCurSel(m_loc_y_list.GetCount() - 1);
}


void CViewerTempDlg::OnMenuFileReset()
{RedrawWindow();}


BOOL CViewerTempDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) // 휠 가변 배율 출력
{
	if (zDelta > 0)
	{if(m_pos < 40) m_pos += 0.1f;}
	else
	{if (m_pos > 1.0) m_pos -= 0.1f;}
	
	CString intData = _T("");
	intData.Format(_T("배율 : %.01f배"), m_pos);
	m_ratio_list.DeleteString(0);
	m_ratio_list.AddString(intData);
	m_ratio_list.SetCurSel(m_ratio_list.GetCount() - 1);
	
	RedrawWindow();
	CPaintDC dc(this);
	CRect Rect;
	GetClientRect(&Rect);

	CImage m_image2;
	m_image2.Load(filepath);

	double img_width, img_height;
	img_width = m_image2.GetWidth();
	img_height = m_image2.GetHeight();
	double img_ratio = img_height / img_width;
	double img_ratio_r = img_width / img_height;
	double show_w, show_h;

	double rect_width = Rect.right - Rect.left, rect_height = Rect.bottom - Rect.top;
	int rect_ratio = rect_height / rect_width;

	new_w = m_ptMouse.x / rect_width;
	new_h = m_ptMouse.y / rect_height;

	if (img_ratio >= 1.) // ratio가 1보다 큰 경우 = 세로가 더 길다 = 세로 기준으로 출력.
	{
		show_w = (rect_height - 90) * img_ratio;
		show_h = rect_height - 90;
		if (show_w <= rect_width)
		{
		}
		else // 세로비가 더 길지만, 계산된 가로 출력 길이가 Rect를 초과하는 경우. 가로 기준 제한 출력.
		{
			show_w = rect_width - 160;
			show_h = (rect_width - 160) * img_ratio_r;
		}
	}
	else // ratio가 1보다 작은 경우 = 가로가 더 길다 = 가로 기준으로 출력
	{
		show_w = rect_width - 160;
		show_h = (rect_width - 160) * img_ratio;
		if (show_h <= rect_height)
		{
		}
		else // 가로비가 더 길지만, 계산된 세로 출력 길이가 Rect를 초과하는 경우. 세로 기준 제한 출력.
		{
			show_w = (rect_height - 90) * img_ratio_r;
			show_h = rect_height - 90;
		}
	}

	// 자자 제대로 시작해봅시다. 필요한것 = 커서 위치, 이미지 센터
	double rect_w_center, rect_h_center;
	rect_w_center = rect_width / 2;
	rect_h_center = rect_height / 2;
	//m_ptMouse.x
	if (m_ptMouse.x >= rect_w_center && m_ptMouse.y < rect_h_center) // 1사분면. (원점-Xd, 원점+Yd)
	{
		start_x = 0 - (show_w * m_pos - show_w); // 괄호 안 수식이 맞는지는 좀 긴가민가한데(근소차) 일단 해보자
		start_y = 0 + (show_h * m_pos - show_h);
	}
	else if (m_ptMouse.x < rect_w_center && m_ptMouse.y < rect_h_center) // 2사분면. (원점+Xd, 원점+Yd)
	{
		start_x = 0 + (show_w * m_pos - show_w); 
		start_y = 0 + (show_h * m_pos - show_h);
	}
	else if (m_ptMouse.x < rect_w_center && m_ptMouse.y >= rect_h_center) // 3사분면. (원점+Xd, 원점-Yd)
	{
		start_x = 0 + (show_w * m_pos - show_w); 
		start_y = 0 - (show_h * m_pos - show_h);
	}
	else // 4사분면. (원점-Xd, 원점-Yd)
	{
		start_x = 0 - (show_w * m_pos - show_w);
		start_y = 0 - (show_h * m_pos - show_h);
	}
	
	m_image2.Draw(dc, start_x, start_y, show_w * m_pos, show_h * m_pos);
	origin_w = show_w, origin_h = show_h; // 원본 배율 출력을 위한 변수 설정
	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void CViewerTempDlg::OnBnClickedUpBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 기본 출력과 휠 가변 배율에서 시작점을 public 변수로 저장하도록 해서 여기서 불러 쓸 수 있도록 해야 이미지가 갑자기 다른 곳으로 가지 않고 그대로 배율만 움직일 수 있음.
}


void CViewerTempDlg::OnBnClickedDownBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CViewerTempDlg::OnBnClickedOriginBtn()
{
	m_pos = 1.0f;
	CString intData = _T("");
	intData.Format(_T("배율 : %.01f배"), m_pos);
	m_ratio_list.DeleteString(0);
	m_ratio_list.AddString(intData);
	m_ratio_list.SetCurSel(m_ratio_list.GetCount() - 1);

	RedrawWindow();
	CPaintDC dc(this);
	CRect Rect;
	GetClientRect(&Rect);
	CImage m_image2;
	m_image2.Load(filepath);
	m_image2.Draw(dc, 0, 0, origin_w, origin_h);
}

void CViewerTempDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 휠이 증가할 때 마다 스크롤바도 변해야 하는데
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CViewerTempDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 휠이 증가할 때마다 스크롤바도 변동
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}
