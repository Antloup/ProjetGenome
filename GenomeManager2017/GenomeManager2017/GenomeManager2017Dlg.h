
// GenomeManager2017Dlg.h : fichier d'en-t�te
//

#pragma once
#include "afxwin.h"
#include "afxdialogex.h" // AJOUTEE


// bo�te de dialogue CGenomeManager2017Dlg
class CGenomeManager2017Dlg : public CDialogEx
{
// Construction
public:
	CGenomeManager2017Dlg(CWnd* pParent = NULL);	// constructeur standard

// Donn�es de bo�te de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GENOMEMANAGER2017_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Impl�mentation
protected:
	HICON m_hIcon;

	// Fonctions g�n�r�es de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList3();
	CListBox m_clbMaladies;
	CListBox m_clbAnalyse;
	afx_msg void OnBnClickedButton1();
	void moveItemTo(CListBox& source, CListBox& destination);
	afx_msg void OnLbnSelchangeList1();
	int add(int a, int b) { return a + b; };
};
