
// GenomeManager2017Dlg.h : fichier d'en-tête
//

#pragma once
#include "afxwin.h"
#include "afxdialogex.h" // AJOUTEE
#include <fstream>
#include <list>
#include <string>


// boîte de dialogue CGenomeManager2017Dlg
class CGenomeManager2017Dlg : public CDialogEx
{
// Construction
public:
	CGenomeManager2017Dlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GENOMEMANAGER2017_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Implémentation
protected:
	HICON m_hIcon;
	std::list<std::string>* m_servers;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	std::ifstream* m_analyse;
	afx_msg void OnBnClickedButton1();
	void moveItemTo(CListBox& source, CListBox& destination);
	void setOutput(CString out);
	CString getFile();
	void setServersList(std::string filename);
	//list<string>* getServersList();
	std::string getMaladie();
	afx_msg void OnEnChangeEdit3();
	CEdit m_edit2;
	afx_msg void OnBnClickedButton3();
};
