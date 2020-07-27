
#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;


int main( )
{
	//��0������ԭʼͼ  
	Mat srcImage = imread("1.jpg");  //����Ŀ¼��Ӧ����һ����Ϊ1.jpg���ز�ͼ
	imshow("Canny", srcImage); 	//��ʾԭʼͼ 
	Mat dstImage,edge,grayImage;	//��������

	//��1��������srcͬ���ͺʹ�С�ľ���(dst)
	dstImage.create( srcImage.size(), srcImage.type() );


	cvtColor( srcImage, grayImage, COLOR_BGR2GRAY );

	//��3������ʹ�� 3x3�ں�������
	blur( grayImage, edge, Size(3,3) );

	//��4������Canny����
	Canny( edge, edge, 3, 9,3 );

	//��5����ʾЧ��ͼ 
	imshow("Canny", edge); 

	waitKey(0); 

	return 0; 
}
