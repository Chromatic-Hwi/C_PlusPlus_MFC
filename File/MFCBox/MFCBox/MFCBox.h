
// MFCBox.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCBoxApp:
// �� Ŭ������ ������ ���ؼ��� MFCBox.cpp�� �����Ͻʽÿ�.
//

class CMFCBoxApp : public CWinApp
{
public:
	CMFCBoxApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCBoxApp theApp;