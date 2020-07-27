
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;


int main( )
{
	//-----------------------------------��һ��ͼ����������ʾ��---------------------------------
	//	�������������д����������ͼ����������ʾ
	//--------------------------------------------------------------------------------------------------

	Mat girl=imread("girl.jpg"); //����ͼ��Mat
	namedWindow("virtul"); //����һ����Ϊ "��1������ͼ"�Ĵ���  
	imshow("virtul",girl);//��ʾ��Ϊ "��1������ͼ"�Ĵ���  

	//-----------------------------------����������ͼ���ϡ�--------------------------------------
	//	��������������ͼ����
	//--------------------------------------------------------------------------------------------------
	//����ͼƬ
	Mat image= imread("dota.jpg",199);
	Mat logo= imread("dota_logo.jpg");

	//���������ʾ
	namedWindow("origin");
	imshow("origin",image);

	namedWindow("logo");
	imshow("logo",logo);

	// ����һ��Mat���ͣ����ڴ�ţ�ͼ���ROI
	Mat imageROI;
	//����һ
	imageROI= image(Rect(800,350,logo.cols,logo.rows));
	//������
	//imageROI= image(Range(350,350+logo.rows),Range(800,800+logo.cols));

	// ��logo�ӵ�ԭͼ��
	addWeighted(imageROI,0.5,logo,0.3,0.,imageROI);

	//��ʾ���
	namedWindow("orign+logo");
	imshow("orign+logo",image);

	//-----------------------------------������ͼ��������--------------------------------------
	//	��������һ��Matͼ�������ͼ���ļ�
	//-----------------------------------------------------------------------------------------------
	//���һ��jpgͼƬ������Ŀ¼��
	imwrite("imwrite_save.jpg",image);

	waitKey();

	return 0;
}
