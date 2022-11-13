
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
	DDX_Control(pDX, IDC_SCROLLBAR_X, m_bar_x);
	DDX_Control(pDX, IDC_SCROLLBAR_Y, m_bar_y);
	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Control(pDX, IDC_WND_SIZE, m_wnd_size);
	DDX_Control(pDX, IDC_IMG_SIZE, m_img_size);
	DDX_Control(pDX, IDC_RATIO, m_ratio_list2);
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
//ON_WM_ERASEBKGND()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
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


void CViewerTempDlg::OnPaint()
{
	if (IsIconic())
	{
		/*
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		//SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
		*/
	}
	else{}
}


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
		RedrawWindow();
		filepath = dlg.GetPathName(); // 전체 경로를 입력하는 함수

		CStatic* picturebox = (CStatic*)(GetDlgItem(IDC_PIC)); 
		GetClientRect(&Rect);
		picturebox->GetClientRect(Rect);
		CClientDC dc(picturebox);
		CImage m_image2;
		m_image2.Load(filepath);
		CBitmap m_pic;
		m_pic.Attach(m_image2);
		CDC memoryDC;
		memoryDC.CreateCompatibleDC(&dc);
		memoryDC.SelectObject(m_pic);
		BITMAP bmp;
		m_pic.GetBitmap(&bmp);
		dc.SetStretchBltMode(COLORONCOLOR);

		double img_width, img_height;
		img_width = m_image2.GetWidth();
		img_height = m_image2.GetHeight();
		double img_ratio = img_height / img_width;
		double img_ratio_r = img_width / img_height;
		
		if (img_ratio >= 1.) // ratio가 1보다 큰 경우 = 세로가 더 길다 = 세로 기준으로 출력.
		{
			show_w = Rect.Height() * img_ratio;
			show_h = Rect.Height();
			
			if (show_w <= Rect.Width()){}
			else // 세로비가 더 길지만, 계산된 가로 출력 길이가 Rect를 초과하는 경우. 가로 기준 제한 출력.
			{
				show_w = Rect.Width();
				show_h = Rect.Width() * img_ratio_r;
			}
		}
		else // ratio가 1보다 작은 경우 = 가로가 더 길다 = 가로 기준으로 출력
		{
			show_w = Rect.Width();
			show_h = Rect.Width() * img_ratio;

			if (show_h <= Rect.Height()){}
			else // 가로비가 더 길지만, 계산된 세로 출력 길이가 Rect를 초과하는 경우. 세로 기준 제한 출력.
			{
				show_w = Rect.Height() * img_ratio_r;
				show_h = Rect.Height();
			}
		}
		
		/*
		BOOL StrechBlt(
			1)표시 외부 프레임의 좌상단 x좌표,
			2)표시 외부 프레임의 좌상단 y좌표,
			3)표시 외부 프레임의 가로 폭,
			4)표시 외부 프레임의 세로 폭,
			소스 장치 컨텍스트 지정,
			a)내부 출력 이미지 좌상단 x 좌표,
			b)내부 출력 이미지 좌상단 y좌표,
			c)내부 출력 이미지의 너비,
			d)내부 출력 이미지의 높이,
			옵션)
		*/
		origin_w = show_w, origin_h = show_h; // 원본 배율 출력을 위한 변수 설정

		loc_x = 0 - (show_w / m_pos - show_w) / 2;
		loc_y = 0 - (show_h / m_pos - show_h) / 2;

		dc.StretchBlt(
			abs(Rect.Width()-show_w)/2, 
			abs(Rect.Height()-show_h)/2, 
			origin_w, 
			origin_h, 
			&memoryDC, 
			0, 
			0, 
			img_width, 
			img_height,
			SRCCOPY); // 이미지가 전체 윈도우 대비 여백이 있을 때 중앙으로 옮겨줌.

		CString ratioData = _T("");
		ratioData.Format(_T("H/W : %.3f"), img_ratio);
		m_ratio_list2.DeleteString(0);
		m_ratio_list2.AddString(ratioData);
		m_ratio_list2.SetCurSel(m_ratio_list2.GetCount() - 1);

		CString wndData = _T("");
		ratioData.Format(_T(" %d * %d"), Rect.Width(), Rect.Height());
		m_wnd_size.DeleteString(0);
		m_wnd_size.AddString(wndData);
		m_wnd_size.SetCurSel(m_wnd_size.GetCount() - 1);

		CString imgData = _T("");
		imgData.Format(_T(" %.0f * %.0f"), show_w, show_h);
		m_img_size.DeleteString(0);
		m_img_size.AddString(imgData);
		m_img_size.SetCurSel(m_img_size.GetCount() - 1);

		m_bar_x.SetScrollRange(0, Rect.Width() * m_pos);
		m_bar_y.SetScrollRange(0, Rect.Height() * m_pos);
		m_bar_x.SetScrollPos(0);
		m_bar_y.SetScrollPos(0);
	}
}


void CViewerTempDlg::OnBnClickedOk() // 초기화 버튼
{
	RedrawWindow();
	m_bar_x.SetScrollPos(0);
	m_bar_y.SetScrollPos(0);
}


void CViewerTempDlg::OnMenuFileReset() //메뉴의 초기화 탭
{
	RedrawWindow();
	m_bar_x.SetScrollPos(0);
	m_bar_y.SetScrollPos(0);
}


void CViewerTempDlg::OnMouseMove(UINT nFlags, CPoint point) // 커서 좌표 출력
{
	m_ptMouse = point;
	CDialogEx::OnMouseMove(nFlags, point);

	CStatic* picturebox = (CStatic*)(GetDlgItem(IDC_PIC)); // Rect 사이즈를 측정해야 영역 외 미표시 설정이 되기 때문에 추가해줬음.
	GetClientRect(&Rect);
	picturebox->GetClientRect(Rect);

	int Mx, My;
	Mx = m_ptMouse.x - 19;
	My = m_ptMouse.y - 19;

	if (Mx >= 0 && My >= 0 && Mx <= Rect.Width() && My <= Rect.Height())
	{
		CString strDataX = _T("");
		CString strDataY = _T("");
		strDataX.Format(_T("    X : %d"), Mx);
		strDataY.Format(_T("    Y : %d"), My);

		m_loc_x_list.DeleteString(0);
		m_loc_y_list.DeleteString(0);
		m_loc_x_list.AddString(strDataX);
		m_loc_y_list.AddString(strDataY);
		m_loc_x_list.SetCurSel(m_loc_x_list.GetCount() - 1);
		m_loc_y_list.SetCurSel(m_loc_y_list.GetCount() - 1);
	}
	else{}
}


BOOL CViewerTempDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) // 휠 가변 배율 출력
{
	if (zDelta > 0) // 휠 인
	{if(m_pos < 40) m_pos += 0.1f;}
	else //휠 아웃
	{if (m_pos >= 0.1f) m_pos -= 0.1f;} // 최소 배율을 제한해주어야 이미지 사이즈가 음수가 되서 강제종료되는 것을 방지할 수 있음.
	
	CString intData = _T("");
	intData.Format(_T("배율 : %.01f배"), m_pos);
	m_ratio_list.DeleteString(0);
	m_ratio_list.AddString(intData);
	m_ratio_list.SetCurSel(m_ratio_list.GetCount() - 1);

	RedrawWindow();
	CStatic* picturebox = (CStatic*)(GetDlgItem(IDC_PIC)); 
	GetClientRect(&Rect);
	picturebox->GetClientRect(Rect);
	CClientDC dc(picturebox);
	CImage m_image2;
	m_image2.Load(filepath);
	CBitmap m_pic;
	m_pic.Attach(m_image2);
	CDC memoryDC;
	memoryDC.CreateCompatibleDC(&dc);
	memoryDC.SelectObject(m_pic);
	BITMAP bmp;
	m_pic.GetBitmap(&bmp);
	dc.SetStretchBltMode(COLORONCOLOR);

	double img_width, img_height;
	img_width = m_image2.GetWidth();
	img_height = m_image2.GetHeight();
	double img_ratio = img_height / img_width;
	double img_ratio_r = img_width / img_height;
	
	if (img_ratio >= 1.) // ratio가 1보다 큰 경우 = 세로가 더 길다 = 세로 기준으로 출력.
	{
		show_h = Rect.Height();
		show_w = Rect.Height() * img_ratio;

		if (show_w <= Rect.Width()){}
		else // 세로비가 더 길지만, 계산된 가로 출력 길이가 Rect를 초과하는 경우. 가로 기준 제한 출력.
		{
			show_w = Rect.Width();
			show_h = Rect.Width() * img_ratio_r;
		}
	}
	else // ratio가 1보다 작은 경우 = 가로가 더 길다 = 가로 기준으로 출력
	{
		show_w = Rect.Width();
		show_h = Rect.Width() * img_ratio;
		if (show_h <= Rect.Height()){}
		else // 가로비가 더 길지만, 계산된 세로 출력 길이가 Rect를 초과하는 경우. 세로 기준 제한 출력.
		{
			show_h = Rect.Height();
			show_w = Rect.Height() * img_ratio_r;
		}
	}

	loc_x = 0 - (show_w / m_pos - show_w) / 2;
	loc_y = 0 - (show_h / m_pos - show_h) / 2;

	origin_w = show_w, origin_h = show_h;

	dc.StretchBlt(
		abs(Rect.Width() - show_w) / 2,
		abs(Rect.Height() - show_h) / 2,
		origin_w,
		origin_h,
		&memoryDC,
		loc_x,
		loc_y,
		img_width / m_pos,
		img_height / m_pos,
		SRCCOPY);

	m_bar_x.SetScrollRange(0, Rect.Width() * m_pos); // 배율이 변하면 스크롤바의 이동 폭도 변해줘야 함. 예로 확대되면 그만큼 많이 이동해야 하니까.
	m_bar_y.SetScrollRange(0, Rect.Height() * m_pos);

	CString wndData = _T(""); // Wnd 사이즈
	wndData.Format(_T(" %d * %d"), Rect.Width(), Rect.Height());
	m_wnd_size.DeleteString(0);
	m_wnd_size.AddString(wndData);
	m_wnd_size.SetCurSel(m_wnd_size.GetCount() - 1);

	CString imgData = _T(""); // 이미지 사이즈
	imgData.Format(_T(" %.0f * %.0f"), show_w*m_pos, show_h*m_pos);
	m_img_size.DeleteString(0);
	m_img_size.AddString(imgData);
	m_img_size.SetCurSel(m_img_size.GetCount() - 1);

	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void CViewerTempDlg::OnBnClickedUpBtn() // 배율 증가 버튼
{
	m_pos += 1.0f;
	CString intData = _T("");
	intData.Format(_T("배율 : %.01f배"), m_pos);
	m_ratio_list.DeleteString(0);
	m_ratio_list.AddString(intData);
	m_ratio_list.SetCurSel(m_ratio_list.GetCount() - 1);

	m_bar_x.SetScrollRange(0, Rect.Width() * m_pos);
	m_bar_y.SetScrollRange(0, Rect.Height() * m_pos);

	RedrawWindow();
	CStatic* picturebox = (CStatic*)(GetDlgItem(IDC_PIC));
	GetClientRect(&Rect);
	picturebox->GetClientRect(Rect);
	CClientDC dc(picturebox);
	CImage m_image2;
	m_image2.Load(filepath);
	CBitmap m_pic;
	m_pic.Attach(m_image2);
	CDC memoryDC;
	memoryDC.CreateCompatibleDC(&dc);
	memoryDC.SelectObject(m_pic);
	BITMAP bmp;
	m_pic.GetBitmap(&bmp);
	dc.SetStretchBltMode(COLORONCOLOR);

	double img_width, img_height;
	img_width = m_image2.GetWidth();
	img_height = m_image2.GetHeight();
	double img_ratio = img_height / img_width;
	double img_ratio_r = img_width / img_height;

	if (img_ratio >= 1.) // ratio가 1보다 큰 경우 = 세로가 더 길다 = 세로 기준으로 출력.
	{
		show_h = Rect.Height();
		show_w = Rect.Height() * img_ratio;

		if (show_w <= Rect.Width()) {}
		else // 세로비가 더 길지만, 계산된 가로 출력 길이가 Rect를 초과하는 경우. 가로 기준 제한 출력.
		{
			show_w = Rect.Width();
			show_h = Rect.Width() * img_ratio_r;
		}
	}
	else // ratio가 1보다 작은 경우 = 가로가 더 길다 = 가로 기준으로 출력
	{
		show_w = Rect.Width();
		show_h = Rect.Width() * img_ratio;
		if (show_h <= Rect.Height()) {}
		else // 가로비가 더 길지만, 계산된 세로 출력 길이가 Rect를 초과하는 경우. 세로 기준 제한 출력.
		{
			show_h = Rect.Height();
			show_w = Rect.Height() * img_ratio_r;
		}
	}

	origin_w = show_w, origin_h = show_h;

	dc.StretchBlt(
		abs(Rect.Width() - show_w) / 2,
		abs(Rect.Height() - show_h) / 2,
		origin_w,
		origin_h,
		&memoryDC,
		0 - (show_w / m_pos - show_w) / 2,
		0 - (show_h / m_pos - show_h) / 2,
		img_width / m_pos,
		img_height / m_pos,
		SRCCOPY);

	CString wndData = _T(""); // Wnd 사이즈
	wndData.Format(_T(" %d * %d"), Rect.Width(), Rect.Height());
	m_wnd_size.DeleteString(0);
	m_wnd_size.AddString(wndData);
	m_wnd_size.SetCurSel(m_wnd_size.GetCount() - 1);

	CString imgData = _T(""); // 이미지 사이즈
	imgData.Format(_T(" %.0f * %.0f"), show_w * m_pos, show_h * m_pos);
	m_img_size.DeleteString(0);
	m_img_size.AddString(imgData);
	m_img_size.SetCurSel(m_img_size.GetCount() - 1);
}


void CViewerTempDlg::OnBnClickedDownBtn() // 배율 감소
{
	if (m_pos > 0)
	{
		m_pos -= 1.0f;
		CString intData = _T("");
		intData.Format(_T("배율 : %.01f배"), m_pos);
		m_ratio_list.DeleteString(0);
		m_ratio_list.AddString(intData);
		m_ratio_list.SetCurSel(m_ratio_list.GetCount() - 1);

		m_bar_x.SetScrollRange(0, Rect.Width() * m_pos);
		m_bar_y.SetScrollRange(0, Rect.Height() * m_pos);
	}

	RedrawWindow();
	CStatic* picturebox = (CStatic*)(GetDlgItem(IDC_PIC));
	GetClientRect(&Rect);
	picturebox->GetClientRect(Rect);
	CClientDC dc(picturebox);
	CImage m_image2;
	m_image2.Load(filepath);
	CBitmap m_pic;
	m_pic.Attach(m_image2);
	CDC memoryDC;
	memoryDC.CreateCompatibleDC(&dc);
	memoryDC.SelectObject(m_pic);
	BITMAP bmp;
	m_pic.GetBitmap(&bmp);
	dc.SetStretchBltMode(COLORONCOLOR);

	double img_width, img_height;
	img_width = m_image2.GetWidth();
	img_height = m_image2.GetHeight();
	double img_ratio = img_height / img_width;
	double img_ratio_r = img_width / img_height;

	if (img_ratio >= 1.) // ratio가 1보다 큰 경우 = 세로가 더 길다 = 세로 기준으로 출력.
	{
		show_h = Rect.Height();
		show_w = Rect.Height() * img_ratio;

		if (show_w <= Rect.Width()) {}
		else // 세로비가 더 길지만, 계산된 가로 출력 길이가 Rect를 초과하는 경우. 가로 기준 제한 출력.
		{
			show_w = Rect.Width();
			show_h = Rect.Width() * img_ratio_r;
		}
	}
	else // ratio가 1보다 작은 경우 = 가로가 더 길다 = 가로 기준으로 출력
	{
		show_w = Rect.Width();
		show_h = Rect.Width() * img_ratio;
		if (show_h <= Rect.Height()) {}
		else // 가로비가 더 길지만, 계산된 세로 출력 길이가 Rect를 초과하는 경우. 세로 기준 제한 출력.
		{
			show_h = Rect.Height();
			show_w = Rect.Height() * img_ratio_r;
		}
	}

	origin_w = show_w, origin_h = show_h;

	dc.StretchBlt(
		abs(Rect.Width() - show_w) / 2,
		abs(Rect.Height() - show_h) / 2,
		origin_w,
		origin_h,
		&memoryDC,
		0 - (show_w / m_pos - show_w) / 2,
		0 - (show_h / m_pos - show_h) / 2,
		img_width / m_pos,
		img_height / m_pos,
		SRCCOPY);

	CString wndData = _T(""); // Wnd 사이즈
	wndData.Format(_T(" %d * %d"), Rect.Width(), Rect.Height());
	m_wnd_size.DeleteString(0);
	m_wnd_size.AddString(wndData);
	m_wnd_size.SetCurSel(m_wnd_size.GetCount() - 1);

	CString imgData = _T(""); // 이미지 사이즈
	imgData.Format(_T(" %.0f * %.0f"), show_w * m_pos, show_h * m_pos);
	m_img_size.DeleteString(0);
	m_img_size.AddString(imgData);
	m_img_size.SetCurSel(m_img_size.GetCount() - 1);
}


void CViewerTempDlg::OnBnClickedOriginBtn() // 원본 비율 출력
{
	RedrawWindow();
	m_pos = 1.0f;
	CString intData = _T("");
	intData.Format(_T("배율 : %.01f배"), m_pos);
	m_ratio_list.DeleteString(0);
	m_ratio_list.AddString(intData);
	m_ratio_list.SetCurSel(m_ratio_list.GetCount() - 1);

	CStatic* picturebox = (CStatic*)(GetDlgItem(IDC_PIC));
	GetClientRect(&Rect);
	picturebox->GetClientRect(Rect);
	CClientDC dc(picturebox);
	CImage m_image2;
	m_image2.Load(filepath);
	CBitmap m_pic;
	m_pic.Attach(m_image2);
	CDC memoryDC;
	memoryDC.CreateCompatibleDC(&dc);
	memoryDC.SelectObject(m_pic);
	BITMAP bmp;
	m_pic.GetBitmap(&bmp);
	dc.SetStretchBltMode(COLORONCOLOR);
	dc.StretchBlt(abs(Rect.Width()-show_w)/2, abs(Rect.Height()-show_h)/2, show_w, show_h, &memoryDC, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

	m_bar_x.SetScrollRange(0, Rect.Width() * m_pos);
	m_bar_y.SetScrollRange(0, Rect.Height() * m_pos);
	m_bar_x.SetScrollPos(0);
	m_bar_y.SetScrollPos(0);
}


void CViewerTempDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) // 횡스크롤바
{
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	int pos_x, move_x;
	pos_x = m_bar_x.GetScrollPos();
	move_x = show_w / (50 * m_pos);

	if (nSBCode == SB_LINEDOWN)
	{
		m_bar_x.SetScrollPos(pos_x + move_x);
		loc_x += move_x;
	}
	else if (nSBCode == SB_LINEUP) 
	{
		m_bar_x.SetScrollPos(pos_x - move_x);
		loc_x -= move_x;
	}
	else if (nSBCode == SB_THUMBTRACK) 
	{
		m_bar_x.SetScrollPos(nPos);
		// 바가 증가되는지 감소되는지 다시 경우를 나누는게 맞나?
		loc_x += pos_x;
	}

	RedrawWindow();
	CStatic* picturebox = (CStatic*)(GetDlgItem(IDC_PIC));
	GetClientRect(&Rect);
	picturebox->GetClientRect(Rect);
	CClientDC dc(picturebox);
	CImage m_image2;
	m_image2.Load(filepath);
	CBitmap m_pic;
	m_pic.Attach(m_image2);
	CDC memoryDC;
	memoryDC.CreateCompatibleDC(&dc);
	memoryDC.SelectObject(m_pic);
	BITMAP bmp;
	m_pic.GetBitmap(&bmp);
	dc.SetStretchBltMode(COLORONCOLOR);

	double img_width, img_height;
	img_width = m_image2.GetWidth();
	img_height = m_image2.GetHeight();
	double img_ratio = img_height / img_width;
	double img_ratio_r = img_width / img_height;

	if (img_ratio >= 1.) // ratio가 1보다 큰 경우 = 세로가 더 길다 = 세로 기준으로 출력.
	{
		show_h = Rect.Height();
		show_w = Rect.Height() * img_ratio;

		if (show_w <= Rect.Width()) {}
		else // 세로비가 더 길지만, 계산된 가로 출력 길이가 Rect를 초과하는 경우. 가로 기준 제한 출력.
		{
			show_w = Rect.Width();
			show_h = Rect.Width() * img_ratio_r;
		}
	}
	else // ratio가 1보다 작은 경우 = 가로가 더 길다 = 가로 기준으로 출력
	{
		show_w = Rect.Width();
		show_h = Rect.Width() * img_ratio;
		if (show_h <= Rect.Height()) {}
		else // 가로비가 더 길지만, 계산된 세로 출력 길이가 Rect를 초과하는 경우. 세로 기준 제한 출력.
		{
			show_h = Rect.Height();
			show_w = Rect.Height() * img_ratio_r;
		}
	}

	origin_w = show_w, origin_h = show_h;

	dc.StretchBlt(
		abs(Rect.Width() - show_w) / 2,
		abs(Rect.Height() - show_h) / 2,
		origin_w,
		origin_h,
		&memoryDC,
		loc_x,
		loc_y,
		img_width / m_pos,
		img_height / m_pos,
		SRCCOPY);
	}


void CViewerTempDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) // 종스크롤바
{
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
	int pos_y, move_y;
	pos_y = m_bar_y.GetScrollPos();
	move_y = show_h / (50 * m_pos);

	if (nSBCode == SB_LINEDOWN)
	{
		m_bar_y.SetScrollPos(pos_y + move_y);
		loc_y += move_y;
	}
	else if (nSBCode == SB_LINEUP)
	{
		m_bar_y.SetScrollPos(pos_y - move_y);
		loc_y -= move_y;
	}
	else if (nSBCode == SB_THUMBTRACK)
	{
		m_bar_y.SetScrollPos(nPos);
		loc_y += pos_y;
	}

	RedrawWindow();
	CStatic* picturebox = (CStatic*)(GetDlgItem(IDC_PIC));
	GetClientRect(&Rect);
	picturebox->GetClientRect(Rect);
	CClientDC dc(picturebox);
	CImage m_image2;
	m_image2.Load(filepath);
	CBitmap m_pic;
	m_pic.Attach(m_image2);
	CDC memoryDC;
	memoryDC.CreateCompatibleDC(&dc);
	memoryDC.SelectObject(m_pic);
	BITMAP bmp;
	m_pic.GetBitmap(&bmp);
	dc.SetStretchBltMode(COLORONCOLOR);

	double img_width, img_height;
	img_width = m_image2.GetWidth();
	img_height = m_image2.GetHeight();
	double img_ratio = img_height / img_width;
	double img_ratio_r = img_width / img_height;

	if (img_ratio >= 1.) // ratio가 1보다 큰 경우 = 세로가 더 길다 = 세로 기준으로 출력.
	{
		show_h = Rect.Height();
		show_w = Rect.Height() * img_ratio;

		if (show_w <= Rect.Width()) {}
		else // 세로비가 더 길지만, 계산된 가로 출력 길이가 Rect를 초과하는 경우. 가로 기준 제한 출력.
		{
			show_w = Rect.Width();
			show_h = Rect.Width() * img_ratio_r;
		}
	}
	else // ratio가 1보다 작은 경우 = 가로가 더 길다 = 가로 기준으로 출력
	{
		show_w = Rect.Width();
		show_h = Rect.Width() * img_ratio;
		if (show_h <= Rect.Height()) {}
		else // 가로비가 더 길지만, 계산된 세로 출력 길이가 Rect를 초과하는 경우. 세로 기준 제한 출력.
		{
			show_h = Rect.Height();
			show_w = Rect.Height() * img_ratio_r;
		}
	}

	origin_w = show_w, origin_h = show_h;

	dc.StretchBlt(
		abs(Rect.Width() - show_w) / 2,
		abs(Rect.Height() - show_h) / 2,
		origin_w,
		origin_h,
		&memoryDC,
		loc_x,
		loc_y,
		img_width / m_pos,
		img_height / m_pos,
		SRCCOPY);
}


/*
BOOL CViewerTempDlg::OnEraseBkgnd(CDC* pDC)
{
	bool state=false;
	return TRUE;
	//return CDialogEx::OnEraseBkgnd(pDC);
}
*/


