
#include <opencv2/opencv.hpp>  
using namespace cv;  
int main( )  
{  
	//��1��������ͷ������Ƶ
	VideoCapture capture(0);

	//��2��ѭ����ʾÿһ֡
	while(1)  
	{  
		Mat frame;  //����һ��Mat���������ڴ洢ÿһ֡��ͼ��
		capture>>frame;  //��ȡ��ǰ֡
		imshow("video loading",frame);  //��ʾ��ǰ֡
		waitKey(30);  //��ʱ30ms
	}  
	return 0;     
}  
