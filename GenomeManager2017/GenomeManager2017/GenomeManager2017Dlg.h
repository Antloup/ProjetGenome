
// GenomeManager2017Dlg.h : fichier d'en-tête
//

#pragma once
#include "afxwin.h"
#include "afxdialogex.h" // AJOUTEE
#include <fstream>
#include <vector>
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
	std::vector<std::string>* m_servers;
	std::ifstream* m_analyse;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButtonClear();

	CEdit m_edit2;
	void setOutput(CString out);
	CString getFile();
	std::string getServerAddress();
	void setServersList(std::string filename);
	std::string getMaladie();
};
