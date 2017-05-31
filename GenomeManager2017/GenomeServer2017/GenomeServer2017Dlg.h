
// GenomeServer2017Dlg.h : fichier d'en-tête
//

#pragma once
#include <string>
#include <list>
#include "Maladie.h"
class SocketServer;



// boîte de dialogue CGenomeServer2017Dlg
class CGenomeServer2017Dlg : public CDialogEx
{
// Construction
public:
	CGenomeServer2017Dlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GENOMESERVER2017_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV

// Implémentation
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	list<Maladie>* getMaladies();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonLoad();
	void setOutput(CString out);
	void LoadFile();

private:
	SocketServer* ss;
	std::list<Maladie>* maladies;

};
