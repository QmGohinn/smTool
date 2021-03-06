
// ButtonSDlg.h : 头文件
//

#pragma once

#ifndef ON
#define ON true
#endif // !ON

#ifndef OFF
#define OFF false
#endif // !OFF

#ifndef OFF_NUM
#define OFF_NUM 0
#endif // !OFF_NUM

#pragma warning(disable : 4067)

#pragma region Mydefine

#ifndef BUTTON_CLICKED(BUTTON_NUM)	
#define BUTTON_CLICKED(BUTTON_NUM)												\
	void CButtonSDlg::OnBnClickedButton##BUTTON_NUM()		\
	{																										\
		theApp._wb_dlg_control(BUTTON_NUM);											\
	}																											
#endif // !BUTTON_CLICKED(BUTTON_NUM)	

#ifndef BIND_BUTTON_OBJ(BUTTON_NUM)
#define BIND_BUTTON_OBJ(BUTTON_NUM)				\
	DDX_Control(pDX,IDC_BUTTON##BUTTON_NUM,this->m_button[BUTTON_NUM - 1]);
#endif // !BIND_BUTTON_OBJ(BUTTON_NUM)

#ifndef _BIND_BUTTON_OBJ(BUTTON_NUM)
#define _BIND_BUTTON_OBJ(BUTTON_NUM)	BIND_BUTTON_OBJ(BUTTON_NUM)
#endif // !_BIND_BUTTON_OBJ(BUTTON_NUM)

#ifndef _BIND_BUTTON_FUNC(BUTTON_NUM)	
#define	 _BIND_BUTTON_FUNC(BUTTON_NUM)								    \
	ON_BN_CLICKED(IDC_BUTTON##BUTTON_NUM,							\
	&CButtonSDlg::OnBnClickedButton##BUTTON_NUM)
#endif // !_BIND_BUTTON_FUNC(BUTTON_NUM)	

#ifndef BIND_BUTTON_FUNC(BUTTON_NUM)
#define BIND_BUTTON_FUNC(BUTTON_NUM) _BIND_BUTTON_FUNC(BUTTON_NUM)
#endif // !BIND_BUTTON_FUNC(BUTTON_NUM)

#ifndef AFX_BUTTON_SHOW(BUTTON_NUM)
#define AFX_BUTTON_SHOW(BUTTON_NUM)   \
	afx_msg void OnBnClickedButton##BUTTON_NUM()
#endif // !AFX_BUTTON_SHOW(BUTTON_NUM)

#pragma endregion 

// CButtonSDlg 对话框
class CButtonSDlg : public CDialogEx
{
	// 构造
public:
	CButtonSDlg(CWnd* pParent = NULL);	// 标准构造函数

	// 对话框数据
	enum { IDD = IDD_ButtonS_DIALOG };

	// 自定义控件
	CButton m_button[14];

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:

#pragma region 自定义函数

	void Identify_button(int);
	void set_default();
	void rand_on_off(int);
	bool is_on_off(int);
	void button_opposite(int);
	void button_rand(int);

#pragma endregion

#pragma region 按钮函数声明

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

#pragma endregion

};
