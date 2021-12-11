
// oFFiceModule_MFCDlg.h : 头文件
//

#pragma once

#pragma warning(disable : 4067)

#pragma region My define

/*宏定义按钮点击消息处理函数*/
#ifndef BUTTON_CLICKED(BUTTON_NUM)			
#define BUTTON_CLICKED(BUTTON_NUM)												\
	void CoFFiceModule_MFCDlg::OnBnClickedButton##BUTTON_NUM()		    \
{																											\
	theApp.dlg_control(BUTTON_NUM);													\
}																											
#endif // !BUTTON_CLICKED(BUTTON_NUM)	


/*对象和控件绑定宏定义*/
#ifndef BIND_BUTTON_OBJ(BUTTON_NUM)			
#define BIND_BUTTON_OBJ(BUTTON_NUM) \
	DDX_Control(pDX,IDC_BUTTON##BUTTON_NUM,this->m_button[BUTTON_NUM - 1]);
#endif // !BIND_BUTTON_OBJ(BUTTON_NUM)

#ifndef _BIND_BUTTON_OBJ(BUTTON_NUM)
#define _BIND_BUTTON_OBJ(BUTTON_NUM)	BIND_BUTTON_OBJ(BUTTON_NUM)
#endif // !_BIND_BUTTON_OBJ(BUTTON_NUM)


/*控件和函数绑定*/
#ifndef _BIND_BUTTON_FUNC(BUTTON_NUM)	
#define	 _BIND_BUTTON_FUNC(BUTTON_NUM)								\
	ON_BN_CLICKED(IDC_BUTTON##BUTTON_NUM,							\
	&CoFFiceModule_MFCDlg::OnBnClickedButton##BUTTON_NUM)
#endif // !_BIND_BUTTON_FUNC(BUTTON_NUM)	

#ifndef BIND_BUTTON_FUNC(BUTTON_NUM)
#define BIND_BUTTON_FUNC(BUTTON_NUM) _BIND_BUTTON_FUNC(BUTTON_NUM)
#endif // !BIND_BUTTON_FUNC(BUTTON_NUM)


/*消息处理函数声明宏定义*/
#ifndef AFX_BUTTON_SHOW(BUTTON_NUM)
#define AFX_BUTTON_SHOW(BUTTON_NUM)   \
	afx_msg void OnBnClickedButton##BUTTON_NUM()
#endif // !AFX_BUTTON_SHOW(BUTTON_NUM)

#pragma endregion 

// CoFFiceModule_MFCDlg 对话框
class CoFFiceModule_MFCDlg : public CDialogEx
{
	// 构造
public:
	CoFFiceModule_MFCDlg(CWnd* pParent = NULL);	// 标准构造函数

	// 对话框数据
	enum { IDD = IDD_OFFICEMODULE_MFC_DIALOG };

	CButton m_button[30];

protected:

	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	// 实现

protected:
	HICON m_hIcon;

	/*按键处理和鼠标消息处理函数声明*/
	virtual void OnOK();
	virtual BOOL PreTranslateMessage(MSG *pMsg);

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void Identify_button(int);	

public:

#pragma region 消息处理函数声明

	/*按钮消息处理函数声明*/
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
