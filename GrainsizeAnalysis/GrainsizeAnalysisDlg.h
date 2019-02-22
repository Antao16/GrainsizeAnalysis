
// GrainsizeAnalysisDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

#define MARGIN 60
#define PI 3.14159265
#define E 2.71828182

// ������λС��
#define FIX001(x) ((double)((int)((x)*100+0.5))/100.0)

// ������ʾY�᳤�ȣ����أ�
#define YLEN 410

// ����ط�ʶ��ľ��ȣ��Ƽ�2~4������
#define SPAN 3

// ���ݳ���
#define XMAX 8000

// �����ɫ
#define BS_GRAVEL	RGB(0, 64, 128)
#define BS_SAND		RGB(64, 0, 128)
#define BS_SILT		RGB(255, 128, 128)
#define BS_CLAY		RGB(106, 57, 6)

// �����ֲ����
#define GS_WIDTH	220
#define GS_HEIGHT	155
#define GS_MARGIN	30

// CGrainsizeAnalysisDlg �Ի���
class CGrainsizeAnalysisDlg : public CDialogEx
{
	// ����
public:
	CGrainsizeAnalysisDlg(CWnd* pParent = NULL);	// ��׼���캯��

	// �Ի�������
	enum { IDD = IDD_GRAINSIZEANALYSIS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


	// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	// ��Ʒ�ṹ��
	struct EachSample
	{
		CString sampleID; // ��Ʒ���
		CString positionNum; // վλ��
		CString longitude; // ����
		CString latitude; // γ��
		CString deep; // ���
		CString gravel; // ��ʯ
		CString sand; // ɰ
		CString silt; // ��ɰ
		CString clay; // ��
		CString averageSize; // ƽ������
		CString mediumSize; // ��ֵ����
		CString skewnessCoefficient; // ƫ̬ϵ��
		CString kurtosisCoefficient; // ��̬ϵ��
		CString sortingCoefficient; // ��ѡϵ��
		int dataCount; // ��Ʒ��Ч���ݸ���
		int suspectBreakpoint[128]; // ���ƹ�����±�
		int suspectBreakpointCount; // ���ƹ�����±����
		int breakPointCount; // ת�۵����
		int breakPointIndex[4]; // ��¼������±�
		double sizeDistribution[128]; // ��������С�ֲ���Ƶ�ʣ�
		double xDataArray[128]; // ���ȣ���ȡ��������-3~16
		double yDataArray[128]; // �ۼ�Ƶ�ʣ�0~100�����в�ֵǰ��ת��Ϊ��ʾ������Ҫ����100ת���� 0~1��
		int normalY[128 + 2 * SPAN]; // ��̫Y: 0~2048;
	};

	double xStep; // PHIֵ��0.25 0.5 1
	double dataStep; // ���ں���ֶ�ֵ
	double gs_dataStep; // �����ֲ�ͼ�ֶ�ֵ
	double distributionMap[2048]; // ��̫��ѯ�� 0~1
	int base; // ��׼�� 0.01ʱ����̫��ѯ���±�
	int sampleCount; // ��¼��Ʒ��������
	CArray<EachSample, EachSample> sampleArray; // ��Ʒ����
	int currentSample; // ��ǰ��Ʒ���к�
	double globleXValue[128]; // ����Xֵ�ֲ�����ͷXֵ��
	int globleXCount; // ����Դ��Xֵ�ֲ���Χ
	char breakPointTitle[4][5]; // ��������
	bool isShowBreakPoint; // �Ƿ���ʾ��ɫ�ϵ����ڵ���
	CString filePath;  // ��ǰ�ļ���·��
	bool fileIsModified; // ��ǰ���ļ��ѱ��Ķ���

	void ShowTheMap(CDC *, CRect, EachSample); // ��������ͼ
	void SetDataStep(EachSample); // ���ú��Ჽ��
	void GetNormalDistributionMap(); // ������̫�ֲ���ѯ��
	int GetShowPointX(double, EachSample); // ����Դ���ݵ�ת����ʾ��
	int GetShowPointY(double); // ����Դ���ݵ�ת����ʾ�㣬ͨ�����ķ�ʽ����
	int GetGSShowPointX(double, EachSample); // ����Դ���ݵ�ת�������ֲ�ͼ��ʾ��
	int GetGSShowPointY(double); // ����Դ���ݵ�ת����ʾ��
	void ShowPointToValue(int, int, double*, double*, EachSample); // ��ʾ�ĵ㷵��ȥ��ֵ
	int GetNormalY(double); // ����Դ���ݵ�ת����̫�㣬ͨ�����ķ�ʽ����
	void GetBreakPointIndex(EachSample *); // ��ȡ������±꣬��������ӵ������򣬹��ֶ�ѡ��
	void SortBreakPoint(EachSample *); // �ϵ��±��С��������
	void AddData2Combo(); // ��ӹ�����ѡ���ݵ�������
	void ShowThePoint(CDC *, EachSample); // ��ʾ���ݵ�
	int GetDataFromCSVLine(CString); // ��CSV�ļ���ÿһ����ӱ�ͷ����Ʒ���ݣ�������������ʼ��
	void ShowSampleInfo(); // ��ʾ��Ʒ��������
	void SaveSampleInfo(); // ������Ʒ��������
	void ShowRawData(); // ��ʾ��Ʒ���������Դ���õ���ԭʼ���ݣ����ڲ��
	void InitNoneSample(); // ����һ���յ���Ʒ����������ʾ
	void OldDrawTheAnalysisLine1(CDC *, EachSample); // ��ʾ1���ϵ�ʱ���͵�ֱ��
	void OldDrawTheAnalysisLine2(CDC *, EachSample); // ��ʾ2���ϵ�ʱ���͵�ֱ��
	void OldDrawTheAnalysisLine3(CDC *, EachSample); // ��ʾ3���ϵ�ʱ���͵�ֱ��
	void OldDrawTheAnalysisLine4(CDC *, EachSample); // ��ʾ4���ϵ�ʱ���͵�ֱ��
	void DrawTheAnalysisLine1(CDC *, EachSample); // ��ʾ1���ϵ�ʱ���͵�ֱ��
	void DrawTheAnalysisLine2(CDC *, EachSample); // ��ʾ2���ϵ�ʱ���͵�ֱ��
	void DrawTheAnalysisLine3(CDC *, EachSample); // ��ʾ3���ϵ�ʱ���͵�ֱ��
	void DrawTheAnalysisLine4(CDC *, EachSample); // ��ʾ4���ϵ�ʱ���͵�ֱ��
	void DrawSizeDitribution(CDC *, CRect, EachSample); // �������ȴ�С�ֲ�
	void LineFitting(double *, double *, int, int, double *, double *); // ���Իع�
	void GetFocusPoint(double, double, double, double, double *, double *); // ���㽹��

public:
	afx_msg void OnMenuImportdata();
	// ����
	CStatic m_DrawPanelControl;
	afx_msg void OnBnClickedBtnBefor();
	afx_msg void OnBnClickedBtnNext();
	// ԭʼ������ʾ��
	CListBox m_RawDataListControl;
	afx_msg void OnToolCleandata();
	// ���͵���
	CComboBox m_NumberSelectControl;
	afx_msg void OnCbnSelchangeComboNumber();
	// ��һ��ת�۵�������ؼ�
	CComboBox m_firBreakPointComboControl;
	// �ڶ���ת�۵�������ؼ�
	CComboBox m_secBreakPointComboControl;
	// ������ת�۵�������ؼ�
	CComboBox m_thrBreakPointComboControl;
	// ���ĸ�ת�۵�������ؼ�
	CComboBox m_forBreakPointComboControl;
	afx_msg void OnCbnSelchangeCombo1st();
	afx_msg void OnCbnSelchangeCombo2nd();
	afx_msg void OnCbnSelchangeCombo3rd();
	afx_msg void OnCbnSelchangeCombo4th();
	afx_msg void OnAboutAboutgrainsizeanalysis();
	afx_msg void OnAboutHowtouse();
	afx_msg void OnMenuQuit();
	// ��Ʒ������
	CComboBox m_SampleListControl;
	afx_msg void OnCbnSelchangeComboSample();
	afx_msg void OnMenuOpen();
	afx_msg void OnMenuSave();
	afx_msg void OnMenuSaveto();
	afx_msg void OnToolExportascsv();
	afx_msg void OnToolPrevious();
	afx_msg void OnToolNext();
	afx_msg void OnEnChangeStaticPosition();
	afx_msg void OnEnChangeStaticLongitude();
	afx_msg void OnEnChangeStaticLatitude();
	afx_msg void OnEnChangeStaticDeep();
	afx_msg void OnMenuNew();
	CButton m_CheckToShowControl;
	afx_msg void OnBnClickedCheckShowbreakpoint();
};
