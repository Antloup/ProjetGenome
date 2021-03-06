
// GenomeServer2017Dlg.cpp : fichier d'impl�mentation
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
#define DEFAULT_PORT 8080
#define DEFAULT_ANALYSE_FOLDER "analyse.txt"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;


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


// bo�te de dialogue CGenomeServer2017Dlg



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
	ON_BN_CLICKED(IDC_EDIT_START, &CGenomeServer2017Dlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON2, &CGenomeServer2017Dlg::OnBnClickedButtonLoad)
END_MESSAGE_MAP()


// gestionnaires de messages pour CGenomeServer2017Dlg

BOOL CGenomeServer2017Dlg::OnInitDialog()
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

	// TODO: ajoutez ici une initialisation suppl�mentaire
	this->ss = NULL;
	LoadFile();

	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
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

// Si vous ajoutez un bouton R�duire � votre bo�te de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'ic�ne.  Pour les applications MFC utilisant le mod�le Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CGenomeServer2017Dlg::OnPaint()
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
HCURSOR CGenomeServer2017Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



list<Maladie>* CGenomeServer2017Dlg::getMaladies()
{
	return maladies;
}

void CGenomeServer2017Dlg::OnBnClickedButtonStart()
{
	if (this->ss == NULL) {
		this->ss = new SocketServer(this);
		this->ss->Create(DEFAULT_PORT);
		this->ss->Listen();
		CString output("Socket cr��e");
		this->setOutput(output);
		CString cs_button("Arreter le serveur");
		SetDlgItemText(IDC_EDIT_START, cs_button);
		
	}
	else {
		delete this->ss;
		this->ss = NULL;
		CString output("Socket d�truite");
		this->setOutput(output);
		CString cs_button("Lancer le serveur");
		SetDlgItemText(IDC_EDIT_START, cs_button);
	}
	
}

void CGenomeServer2017Dlg::setOutput(CString out) {
	CString text;
	GetDlgItemText(IDC_EDIT_LOG,text);
	if (!text.IsEmpty()) {
		text += "\r\n";
	}
	SetDlgItemText(IDC_EDIT_LOG,text+out);
}

void CGenomeServer2017Dlg::LoadFile() {
	ifstream fichier(DEFAULT_ANALYSE_FOLDER, ios::in);
	string ligne;
	getline(fichier, ligne);
	list<Maladie> * maladies = new list<Maladie>();
	if (fichier.good())
	{
		if (ligne != "MA v1.0")
		{
			CString output("Ce fichier n'est pas un dictionnaire.");
			this->setOutput(output);
		}
		else
		{
			string nom;
			string mot;

			while (getline(fichier, nom, ';'))
			{
				list<string> mots;
				getline(fichier, ligne);
				istringstream iss(ligne);

				while (getline(iss, mot, ';'))
				{
					mots.push_back(mot);
				}

				Maladie maladie = Maladie(nom, mots);
				maladies->push_back(maladie);
			}

		}

		this->maladies = maladies;
		CString output("Le fichier a �t� charg� correctement");
		this->setOutput(output);
	}
	else
	{
		CString output("Erreur dans l'ouverture du fichier");
		this->setOutput(output);
	}
}

void CGenomeServer2017Dlg::OnBnClickedButtonLoad()
{
	LoadFile();
}


