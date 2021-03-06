
// GenomeManager2017Dlg.cpp : fichier d'impl�mentation
//

#include "stdafx.h"
#include "GenomeManager2017.h"
#include "GenomeManager2017Dlg.h"
#include "afxdialogex.h"
#include "SocketClient.h"
#include "ResponseHandler.h"
#include <fstream>
#include <string>
#include <iostream>

class ResponseHandler;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define DEFAULT_SERVERS_LIST_FILE "servers_list.txt"
#define DEFAULT_SERVER_ADDRESS "127.0.0.1"


// bo�te de dialogue CAboutDlg utilis�e pour la bo�te de dialogue '� propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Donn�es de bo�te de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Impl�mentation
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


// bo�te de dialogue CGenomeManager2017Dlg



CGenomeManager2017Dlg::CGenomeManager2017Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GENOMEMANAGER2017_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGenomeManager2017Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_LOG, m_edit2);
}

BEGIN_MESSAGE_MAP(CGenomeManager2017Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CGenomeManager2017Dlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CGenomeManager2017Dlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// gestionnaires de messages pour CGenomeManager2017Dlg

BOOL CGenomeManager2017Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Ajouter l'�l�ment de menu "� propos de..." au menu Syst�me.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes syst�me.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// D�finir l'ic�ne de cette bo�te de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne

	setServersList(DEFAULT_SERVERS_LIST_FILE);

	// TODO: ajoutez ici une initialisation suppl�mentaire
	m_analyse = NULL;
	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
}

void CGenomeManager2017Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si vous ajoutez un bouton R�duire � votre bo�te de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'ic�ne.  Pour les applications MFC utilisant le mod�le Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CGenomeManager2017Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de p�riph�rique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'ic�ne dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'ic�ne
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le syst�me appelle cette fonction pour obtenir le curseur � afficher lorsque l'utilisateur fait glisser
//  la fen�tre r�duite.
HCURSOR CGenomeManager2017Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CGenomeManager2017Dlg::OnBnClickedButtonSend()
{
	CString file;
	GetDlgItemText(IDC_EDIT1, file);
	ifstream fichier(file, ios::in);
	if (fichier) { // Le fichier existe
		ResponseHandler* rh = new ResponseHandler(this);
	}
	else {
		CString output("Le fichier n'existe pas.\r\n");
		setOutput(output);
	}
	
}

void CGenomeManager2017Dlg::setOutput(CString out)
{
	CString text;
	GetDlgItemText(IDC_EDIT_LOG, text);
	if (!text.IsEmpty()) {
		text += "\r\n";
	}
	SetDlgItemText(IDC_EDIT_LOG, text + out);
}

CString CGenomeManager2017Dlg::getFile() {
	CString file;
	GetDlgItemText(IDC_EDIT1, file);
	return file;
}

string CGenomeManager2017Dlg::getServerAddress()
{
	return m_servers->at(0);
}

void CGenomeManager2017Dlg::setServersList(std::string filename) {
	if (m_servers != NULL) {
		delete m_servers;
	}
	m_servers = new std::vector<std::string>();
	std::ifstream file(filename);
	std::string str;
	while (std::getline(file, str))
	{
		m_servers->push_back(str);
	}
	if (m_servers->size() == 0) {
		m_servers->push_back(DEFAULT_SERVER_ADDRESS);
	}
}

std::string CGenomeManager2017Dlg::getMaladie()
{
	CString maladie;
	GetDlgItemText(IDC_EDIT_FILE, maladie);
	std::string s_maladie = CT2A((LPCTSTR)maladie);
	return s_maladie;
}


void CGenomeManager2017Dlg::OnBnClickedButtonClear()
{
	SetDlgItemText(IDC_EDIT_LOG, L"");
}
