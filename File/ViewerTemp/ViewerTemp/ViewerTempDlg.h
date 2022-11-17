// ViewerTempDlg.h: 헤더 파일
//

#pragma once

// CViewerTempDlg 대화 상자
class CViewerTempDlg : public CDialogEx
{

// 생성입니다.
public:
	CViewerTempDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CPoint m_ptMouse;
	CRect Rect;
	float m_pos = 1.f;
	int origin_w, origin_h;
	double rect_w_center, rect_h_center;
	double loc_x, loc_y;
	double show_w, show_h;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEWERTEMP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

private:
	CListBox m_loc_x_list;
	CListBox m_loc_y_list;
	CListBox m_ratio_list;
	CListBox m_wnd_size;
	CListBox m_img_size;
	
// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnMenuFileOpen();
	afx_msg void OnBnClickedOk();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	CImage m_image;
	CImage m_image2;
	CString filepath;
	CScrollBar m_bar_x;
	CScrollBar m_bar_y;
	CStatic m_pic;
	bool m_bDragFlag;
	bool m_first_show;
	CListBox m_ratio_list2;
	int capture_x, capture_y;
	int Mx, My;

	afx_msg void OnMenuFileReset();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnBnClickedOriginBtn();
	afx_msg void OnBnClickedUpBtn();
	afx_msg void OnBnClickedDownBtn();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	double CViewerTempDlg::ImageNSize(int part, double x, double y, int cap_x, int cap_y);
};
