#include <opencv2/opencv.hpp>  
using namespace cv;  
int main( )  
{  
	//��1��������Ƶ
	VideoCapture capture("1.avi");

	//��2��ѭ����ʾÿһ֡
	while(1)  
	{  
		Mat frame;//����һ��Mat���������ڴ洢ÿһ֡��ͼ��
		capture>>frame;  //��ȡ��ǰ֡

		//����Ƶ������ɣ��˳�ѭ��
		if (frame.empty())
		{
			break;
		}

		imshow("video",frame);  //��ʾ��ǰ֡
		waitKey(30);  //��ʱ30ms
	}  
	return 0;     
}  
