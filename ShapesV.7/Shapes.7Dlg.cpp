
// Shapes.7Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Shapes.7.h"
#include "Shapes.7Dlg.h"
#include "afxdialogex.h"
#include "pShapes.h"

#include <string>
#include <vector>
#include <sstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CShapes7Dlg dialog



CShapes7Dlg::CShapes7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPES7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapes7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CShapes7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_CBN_SELCHANGE(IDC_COMBO1, &CShapes7Dlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT1, &CShapes7Dlg::OnEnChangeEdit1)
	//ON_EN_CHANGE(IDC_EDIT2, &CShapes7Dlg::OnEnChangeEdit2)
	//ON_EN_CHANGE(IDC_EDIT3, &CShapes7Dlg::OnEnChangeEdit3)
	//ON_EN_CHANGE(IDC_EDIT4, &CShapes7Dlg::OnEnChangeEdit4)
	//ON_EN_CHANGE(IDC_EDIT5, &CShapes7Dlg::OnEnChangeEdit5)

	//ON_EN_CHANGE(IDC_EDIT1, &CShapes7Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CShapes7Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CShapes7Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &CShapes7Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &CShapes7Dlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT7, &CShapes7Dlg::OnEnChangeEdit7)
	ON_STN_CLICKED(IDC_STATIC66, &CShapes7Dlg::OnStnClickedStatic100)
	ON_EN_CHANGE(IDC_EDIT9, &CShapes7Dlg::OnEnChangeEdit9)
	ON_EN_CHANGE(IDC_EDIT6, &CShapes7Dlg::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT8, &CShapes7Dlg::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT10, &CShapes7Dlg::OnEnChangeEdit10)

END_MESSAGE_MAP()


// CShapes7Dlg message handlers

BOOL CShapes7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here


	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pCombo->InsertString(0, _T("Square"));
	pCombo->InsertString(1, _T("Rectangle"));
	pCombo->InsertString(2, _T("Circle"));
	pCombo->InsertString(3, _T("Triangle"));
	pCombo->InsertString(4, _T("Cube"));
	pCombo->InsertString(5, _T("Box"));
	pCombo->InsertString(6, _T("Cylinder"));
	pCombo->InsertString(7, _T("Prism"));
	pCombo->SetCurSel(-1); // -1 for unselected

	CStatic* pPicture = (CStatic*)GetDlgItem(IDC_STATIC66);
	pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture->SetBitmap(hb);



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShapes7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShapes7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

void CShapes7Dlg::OnCbnSelchangeCombo1()
{
	CComboBox* pCombo1 = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int x = pCombo1->GetCurSel(); // 0 for first item...
	CEdit* pEdit6 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT6));
	CEdit* pEdit8 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT8));
	CEdit* pEdit9 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT9));
	CEdit* pEdit10 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT10));
	//{"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "CUBE", "BOX", "CYLINDER", "PRISM"}; 
	//^sample code to help with switch
	//6 is length/side, 9 is height, 8 is width, 10 is radius
	if (x == 0)
	{
		pEdit6->SetWindowText(CString(_T("Side")));
		pEdit9->SetWindowText(CString(_T("")));
		pEdit8->SetWindowText(CString(_T("")));
		pEdit10->SetWindowText(CString(_T("")));
	}
	if (x == 1)
	{
		pEdit6->SetWindowText(CString(_T("Length")));
		pEdit9->SetWindowText(CString(_T("")));
		pEdit8->SetWindowText(CString(_T("Width")));
		pEdit10->SetWindowText(CString(_T("")));
	}
	if (x == 2)
	{
		pEdit6->SetWindowText(CString(_T("")));
		pEdit9->SetWindowText(CString(_T("")));
		pEdit8->SetWindowText(CString(_T("")));
		pEdit10->SetWindowText(CString(_T("Radius")));
	}
	if (x == 3)
	{
		pEdit6->SetWindowText(CString(_T("Side")));
		pEdit9->SetWindowText(CString(_T("")));
		pEdit8->SetWindowText(CString(_T("")));
		pEdit10->SetWindowText(CString(_T("")));
	}
	if (x == 4)
	{
		pEdit6->SetWindowText(CString(_T("Side")));
		pEdit9->SetWindowText(CString(_T("")));
		pEdit8->SetWindowText(CString(_T("")));
		pEdit10->SetWindowText(CString(_T("")));
	}
	if (x == 5)
	{
		pEdit6->SetWindowText(CString(_T("Length")));
		pEdit9->SetWindowText(CString(_T("Height")));
		pEdit8->SetWindowText(CString(_T("Width")));
		pEdit10->SetWindowText(CString(_T("")));
	}
	if (x == 6)
	{
		pEdit6->SetWindowText(CString(_T("")));
		pEdit9->SetWindowText(CString(_T("Height")));
		pEdit8->SetWindowText(CString(_T("")));
		pEdit10->SetWindowText(CString(_T("Radius")));
	}
	if (x == 7)
	{
		pEdit6->SetWindowText(CString(_T("Length")));
		pEdit9->SetWindowText(CString(_T("Height")));
		pEdit8->SetWindowText(CString(_T("")));
		pEdit10->SetWindowText(CString(_T("")));
	}
	// TODO: Add your control notification handler code here
}





// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShapes7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShapes7Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShapes7Dlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShapes7Dlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CShapes7Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int n = pCombo->GetCurSel(); // 0 for first item...

	CString mEdit1;
	CEdit* pEdit1 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT1));
	pEdit1->GetWindowText(mEdit1); // copy control's text into an MFC string
	CString mEdit2;
	CEdit* pEdit2 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT2));
	pEdit2->GetWindowText(mEdit2); // copy control's text into an MFC string
	CString mEdit3;
	CEdit* pEdit3 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT3));
	pEdit3->GetWindowText(mEdit3); // copy control's text into an MFC string
	CString mEdit4;
	CEdit* pEdit4 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT4));
	pEdit4->GetWindowText(mEdit4); // copy control's text into an MFC string
	CEdit* pEdit5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT7));

	string length = CStringA(mEdit1); //or used for side
	string width = CStringA(mEdit2);
	string height = CStringA(mEdit3);
	string radius = CStringA(mEdit4);
	//{"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "CUBE", "BOX", "CYLINDER", "PRISM"}; 
	//^sample code to help with switch
	vector<string> params;
	ostringstream sout;

	switch (n)
	{
	case 0:
	{
		params.push_back("Square");
		params.push_back(length.c_str());
		Square s(params);
		s.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 1:
	{
		params.push_back("Rectangle");
		params.push_back(length);
		params.push_back(width);
		comsc::Rectangle re(params);
		re.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 2:
	{
		params.push_back("Circle");
		params.push_back(radius);
		Circle c(params);
		c.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 3:
	{
		params.push_back("Triangle");
		params.push_back(length);
		Triangle t(params);
		t.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 4:
	{
		params.push_back("Cube");
		params.push_back(length);
		Cube c(params);
		c.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 5:
	{
		params.push_back("Box");
		params.push_back(length);
		params.push_back(width);
		params.push_back(height);
		Box b(params);
		b.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 6:
	{
		params.push_back("Cylinder");
		params.push_back(radius);
		params.push_back(height);
		Cylinder c(params);
		c.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 7:
	{
		params.push_back("Prism");
		params.push_back(length);
		params.push_back(height);
		Prism p(params);
		p.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	}
}

void CShapes7Dlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShapes7Dlg::OnEnChangeEdit7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShapes7Dlg::OnStnClickedStatic100()
{
	// TODO: Add your control notification handler code here
}



void CShapes7Dlg::OnEnChangeEdit9()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShapes7Dlg::OnEnChangeEdit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShapes7Dlg::OnEnChangeEdit8()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CShapes7Dlg::OnEnChangeEdit10()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
