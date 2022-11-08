
// ViewerTempDlg.h: 헤더 파일
//

#pragma once

// CViewerTempDlg 대화 상자
class CViewerTempDlg : public CDialogEx
{

// 생성입니다.
public:
	CViewerTempDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEWERTEMP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

private:

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
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton3();

	CImage m_image;
	CImage m_image2;
	CPoint m_ptMouse;
	CListBox m_loc_list;
	afx_msg void OnMenuFileReset();
};
