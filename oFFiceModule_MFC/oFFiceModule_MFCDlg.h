
// oFFiceModule_MFCDlg.h : ͷ�ļ�
//

#pragma once

#pragma warning(disable : 4067)

#pragma region My define

/*�궨�尴ť�����Ϣ������*/
#ifndef BUTTON_CLICKED(BUTTON_NUM)			
#define BUTTON_CLICKED(BUTTON_NUM)												\
	void CoFFiceModule_MFCDlg::OnBnClickedButton##BUTTON_NUM()		    \
{																											\
	theApp.dlg_control(BUTTON_NUM);													\
}																											
#endif // !BUTTON_CLICKED(BUTTON_NUM)	


/*����Ϳؼ��󶨺궨��*/
#ifndef BIND_BUTTON_OBJ(BUTTON_NUM)			
#define BIND_BUTTON_OBJ(BUTTON_NUM) \
	DDX_Control(pDX,IDC_BUTTON##BUTTON_NUM,this->m_button[BUTTON_NUM - 1]);
#endif // !BIND_BUTTON_OBJ(BUTTON_NUM)

#ifndef _BIND_BUTTON_OBJ(BUTTON_NUM)
#define _BIND_BUTTON_OBJ(BUTTON_NUM)	BIND_BUTTON_OBJ(BUTTON_NUM)
#endif // !_BIND_BUTTON_OBJ(BUTTON_NUM)


/*�ؼ��ͺ�����*/
#ifndef _BIND_BUTTON_FUNC(BUTTON_NUM)	
#define	 _BIND_BUTTON_FUNC(BUTTON_NUM)								\
	ON_BN_CLICKED(IDC_BUTTON##BUTTON_NUM,							\
	&CoFFiceModule_MFCDlg::OnBnClickedButton##BUTTON_NUM)
#endif // !_BIND_BUTTON_FUNC(BUTTON_NUM)	

#ifndef BIND_BUTTON_FUNC(BUTTON_NUM)
#define BIND_BUTTON_FUNC(BUTTON_NUM) _BIND_BUTTON_FUNC(BUTTON_NUM)
#endif // !BIND_BUTTON_FUNC(BUTTON_NUM)


/*��Ϣ�����������궨��*/
#ifndef AFX_BUTTON_SHOW(BUTTON_NUM)
#define AFX_BUTTON_SHOW(BUTTON_NUM)   \
	afx_msg void OnBnClickedButton##BUTTON_NUM()
#endif // !AFX_BUTTON_SHOW(BUTTON_NUM)

#pragma endregion 

// CoFFiceModule_MFCDlg �Ի���
class CoFFiceModule_MFCDlg : public CDialogEx
{
	// ����
public:
	CoFFiceModule_MFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

	// �Ի�������
	enum { IDD = IDD_OFFICEMODULE_MFC_DIALOG };

	CButton m_button[30];

protected:

	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	// ʵ��

protected:
	HICON m_hIcon;

	/*��������������Ϣ����������*/
	virtual void OnOK();
	virtual BOOL PreTranslateMessage(MSG *pMsg);

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void Identify_button(int);	

public:

#pragma region ��Ϣ����������

	/*��ť��Ϣ����������*/
	AFX_BUTTON_SHOW(1);
	AFX_BUTTON_SHOW(2);
	AFX_BUTTON_SHOW(3);
	AFX_BUTTON_SHOW(4);
	AFX_BUTTON_SHOW(5);
	AFX_BUTTON_SHOW(6);
	AFX_BUTTON_SHOW(7);
	AFX_BUTTON_SHOW(8);
	AFX_BUTTON_SHOW(9);
	AFX_BUTTON_SHOW(10);
	AFX_BUTTON_SHOW(11);
	AFX_BUTTON_SHOW(12);
	AFX_BUTTON_SHOW(13);
	AFX_BUTTON_SHOW(14);
	AFX_BUTTON_SHOW(15);
	AFX_BUTTON_SHOW(16);
	AFX_BUTTON_SHOW(17);
	AFX_BUTTON_SHOW(18);
	AFX_BUTTON_SHOW(19);
	AFX_BUTTON_SHOW(20);
	AFX_BUTTON_SHOW(21);

#pragma endregion

};
