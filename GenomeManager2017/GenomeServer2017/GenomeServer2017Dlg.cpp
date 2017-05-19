
// GenomeServer2017Dlg.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "GenomeServer2017.h"
#include "GenomeServer2017Dlg.h"
#include "afxdialogex.h"
#include "RequestHandler.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include "Maladie.h"
#define DEFAULT_PORT 8080

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;


// boîte de dialogue CAboutDlg utilisée pour la boîte de dialogue 'À propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Implémentation
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


// boîte de dialogue CGenomeServer2017Dlg



CGenomeServer2017Dlg::CGenomeServer2017Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GENOMESERVER2017_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGenomeServer2017Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGenomeServer2017Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CGenomeServer2017Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CGenomeServer2017Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// gestionnaires de messages pour CGenomeServer2017Dlg

BOOL CGenomeServer2017Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Ajouter l'élément de menu "À propos de..." au menu Système.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes système.
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

	// Définir l'icône de cette boîte de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO: ajoutez ici une initialisation supplémentaire
	this->ss = NULL;

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

void CGenomeServer2017Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône.  Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CGenomeServer2017Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CGenomeServer2017Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGenomeServer2017Dlg::OnBnClickedButton1()
{
	if (this->ss == NULL) {
		this->ss = new SocketServer(this);
		this->ss->Create(DEFAULT_PORT);
		this->ss->Listen();
		CString output("Socket créée");
		this->setOutput(output);
		CString cs_button("Arreter le serveur");
		SetDlgItemText(IDC_BUTTON1, cs_button);
		
	}
	else {
		delete this->ss;
		CString output("Socket détruite");
		this->setOutput(output);
		CString cs_button("Lancer le serveur");
		SetDlgItemText(IDC_BUTTON1, cs_button);
	}
	
}

void CGenomeServer2017Dlg::setOutput(CString out) {
	CString text;
	GetDlgItemText(IDC_EDIT2,text);
	if (!text.IsEmpty()) {
		text += "\r\n";
	}
	SetDlgItemText(IDC_EDIT2,text+out);
}


void CGenomeServer2017Dlg::OnBnClickedButton2()
{
	ifstream fichier("chemin", ios::in);
	string ligne;
	getline(fichier, ligne);
	list<Maladie> * maladies = new list<Maladie>();
	if (ligne != "MA v1.0")
	{
		cerr << "Ce fichier n'est pas un dictionnaire." << endl;
	}
	else
	{
		string nom;
		string mot;

		while (getline(fichier, nom, ';'))
		{
			list<string> * mots = new list<string>();
			getline(fichier, ligne);
			istringstream iss(ligne);

			while (getline(iss, mot, ';'))
			{
				mots->push_back(mot);
			}

			Maladie maladie = Maladie(nom, mots);
			maladies->push_back(maladie);
		}

	}

	// affeccter maladies au serveur à l'aide d'un setter
}
