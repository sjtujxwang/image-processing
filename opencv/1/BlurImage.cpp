
#include "opencv2/highgui/highgui.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 
using namespace cv; 

int main( )
{ 
	//��1������ԭʼͼ
	Mat srcImage=imread("1.jpg"); 

	//��2����ʾԭʼͼ
	imshow( "��ֵ�˲���ԭͼ��", srcImage ); 

	//��3�����о�ֵ�˲�����
	Mat dstImage; 
	blur( srcImage, dstImage, Size(7, 7)); 

	//��4����ʾЧ��ͼ
	imshow( "��ֵ�˲���Ч��ͼ��" ,dstImage ); 

	waitKey( 0 );     
} 
