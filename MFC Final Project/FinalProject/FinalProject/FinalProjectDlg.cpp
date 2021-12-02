// Programmer: Kristina Fout
// Programmer ID: 186884

// FinalProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "FinalProject.h"
#include "FinalProjectDlg.h"
#include "afxdialogex.h"
#include "pFinal.h"

#include <string>
#include <vector>
#include <sstream>

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


// CFinalProjectDlg dialog



CFinalProjectDlg::CFinalProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFinalProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFinalProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_CBN_SELCHANGE(IDC_COMBO1, &CFinalProjectDlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT1, &CFinalProjectDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CFinalProjectDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CFinalProjectDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT7, &CFinalProjectDlg::OnEnChangeEdit7)
	ON_STN_CLICKED(IDC_STATIC4, &CFinalProjectDlg::OnStnClickedStatic100)
	ON_EN_CHANGE(IDC_EDIT6, &CFinalProjectDlg::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT8, &CFinalProjectDlg::OnEnChangeEdit8)
	ON_STN_CLICKED(IDC_STATIC5, &CFinalProjectDlg::OnStnClickedStatic101)

	ON_BN_CLICKED(IDOK, &CFinalProjectDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CFinalProjectDlg message handlers

BOOL CFinalProjectDlg::OnInitDialog()
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
	pCombo->InsertString(0, _T("Multiplication(*)"));
	pCombo->InsertString(1, _T("Division(/)"));
	pCombo->InsertString(2, _T("Subtraction(-)"));
	pCombo->InsertString(3, _T("Addition(+)"));
	pCombo->InsertString(4, _T("Square Root"));
	pCombo->InsertString(5, _T("Power of Two Numbers"));

	pCombo->SetCurSel(-1); // -1 for unselected

	CStatic* pPicture = (CStatic*)GetDlgItem(IDC_STATIC4);
	pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture->SetBitmap(hb);

	CStatic* pPicture2 = (CStatic*)GetDlgItem(IDC_STATIC5);
	pPicture2->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb2 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture2->SetBitmap(hb2);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFinalProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFinalProjectDlg::OnPaint()
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


void CFinalProjectDlg::OnCbnSelchangeCombo1()
{
	CComboBox* pCombo1 = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int x = pCombo1->GetCurSel(); // 0 for first item...
	CEdit* pEdit6 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT6));
	CEdit* pEdit8 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT8));

	//{"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "CUBE", "BOX", "CYLINDER", "PRISM"}; 
	//^sample code to help with switch
	//6 is length/side, 9 is height, 8 is width, 10 is radius
	if (x == 0)
	{
		pEdit6->SetWindowText(CString(_T("First Number")));
		pEdit8->SetWindowText(CString(_T("Second Number")));
	}
	if (x == 1)
	{
		pEdit6->SetWindowText(CString(_T("First Number")));
		pEdit8->SetWindowText(CString(_T("Second Number")));
	}
	if (x == 2)
	{
		pEdit6->SetWindowText(CString(_T("First Number")));
		pEdit8->SetWindowText(CString(_T("Second Number")));
	}
	if (x == 3)
	{
		pEdit6->SetWindowText(CString(_T("First Number")));
		pEdit8->SetWindowText(CString(_T("Second Number")));

	}
	if (x == 4)
	{
		pEdit6->SetWindowText(CString(_T("First Number")));
		pEdit8->SetWindowText(CString(_T("Second Number")));

	}
	if (x == 5)
	{
		pEdit6->SetWindowText(CString(_T("First Number")));
		pEdit8->SetWindowText(CString(_T("Second Number")));

	}
	
	// TODO: Add your control notification handler code here
}


// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFinalProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFinalProjectDlg::OnBnClickedButton1()
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
	
	CEdit* pEdit5 = reinterpret_cast<CEdit*>(GetDlgItem(IDC_EDIT7));

	string length = CStringA(mEdit2); //or used for side
	string width = CStringA(mEdit1);

	//{"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE"}; 
	//^sample code to help with switch
	vector<string> params;
	ostringstream sout;

	switch (n)
	{
	case 0:
	{
		params.push_back("Multiplication(*)");
		params.push_back(length);
		params.push_back(width);
		comsc::Square s(params);
		s.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 1:
	{
		params.push_back("Division(/)");
		params.push_back(length);
		params.push_back(width);
		comsc::Rectangle re(params);
		re.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 2:
	{
		params.push_back("Subtraction(-)");
		params.push_back(length);
		params.push_back(width);
		comsc::Circle c(params);
		c.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 3:
	{
		params.push_back("Addition(+)");
		params.push_back(length);
		params.push_back(width);
		comsc::Triangle t(params);
		t.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 4:
	{
		params.push_back("Square Root");
		params.push_back(length);
		params.push_back(width);
		comsc::Root t(params);
		t.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	case 5:
	{
		params.push_back("Power of Two Numbers");
		params.push_back(length);
		params.push_back(width);
		comsc::Power t(params);
		t.output(sout);
		pEdit5->SetWindowText(CString(sout.str().c_str()));
		break;
	}
	}
}

void CFinalProjectDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CFinalProjectDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CFinalProjectDlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CFinalProjectDlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CFinalProjectDlg::OnEnChangeEdit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CFinalProjectDlg::OnEnChangeEdit7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CFinalProjectDlg::OnEnChangeEdit8()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CFinalProjectDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

void CFinalProjectDlg::OnStnClickedStatic100()
{
	// TODO: Add your control notification handler code here
}

void CFinalProjectDlg::OnStnClickedStatic101()
{
	// TODO: Add your control notification handler code here
}
