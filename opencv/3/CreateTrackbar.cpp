
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

//-----------------------------------���궨�岿�֡�-------------------------------------------- 
//  ����������һЩ������ 
//------------------------------------------------------------------------------------------------ 
#define WINDOW_NAME "���������Ĵ���&���Ի��ʾ����"        //Ϊ���ڱ��ⶨ��ĺ� 


//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//		������ȫ�ֱ�������
//-----------------------------------------------------------------------------------------------
const int g_nMaxAlphaValue = 100;//Alphaֵ�����ֵ
int g_nAlphaValueSlider;//��������Ӧ�ı���
double g_dAlphaValue;
double g_dBetaValue;

//�����洢ͼ��ı���
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;


void on_Trackbar( int, void* )
{
	//�����ǰalphaֵ��������ֵ�ı���
	g_dAlphaValue = (double) g_nAlphaValueSlider/g_nMaxAlphaValue ;
	//��betaֵΪ1��ȥalphaֵ
	g_dBetaValue = ( 1.0 - g_dAlphaValue );

	//����alpha��betaֵ�������Ի��
	addWeighted( g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);

	//��ʾЧ��ͼ
	imshow( WINDOW_NAME, g_dstImage );
}


//-----------------------------��ShowHelpText( )������--------------------------------------
//		���������������Ϣ
//-------------------------------------------------------------------------------------------------
//-----------------------------------��ShowHelpText( )������----------------------------------
//		���������һЩ������Ϣ
//----------------------------------------------------------------------------------------------
void ShowHelpText()
{
	//�����ӭ��Ϣ��OpenCV�汾
	printf("\n\n\t\t\t\n");
	printf("\n\n\t\t\t\n");
	printf("\n\n\t\t\t   ��ǰʹ�õ�OpenCV�汾Ϊ��" CV_VERSION );
	printf("\n\n  ----------------------------------------------------------------------------\n");
}

int main( int argc, char** argv )
{

	//��ʾ������Ϣ
	//ShowHelpText();

	//����ͼ�� (��ͼ��ĳߴ�����ͬ)
	g_srcImage1 = imread("1.jpg");
	g_srcImage2 = imread("2.jpg");
	if( !g_srcImage1.data ) { printf("MISTAKE1 \n"); return -1; }
	if( !g_srcImage2.data ) { printf("MISTAKE2 \n"); return -1; }

	//���û�������ֵΪ70
	g_nAlphaValueSlider = 70;

	//��������
	namedWindow(WINDOW_NAME, 1);

	//�ڴ����Ĵ����д���һ���������ؼ�
	char TrackbarName[50];
	sprintf( TrackbarName, "value %d", g_nMaxAlphaValue );

	createTrackbar( TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar );

	//����ڻص���������ʾ
	on_Trackbar( g_nAlphaValueSlider, 0 );

	//��������˳�
	waitKey(0);

	return 0;
}
