
#include <opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;


int main( )
{
	//【0】载入原始图  
	Mat srcImage = imread("1.jpg");  //工程目录下应该有一张名为1.jpg的素材图
	imshow("Canny", srcImage); 	//显示原始图 
	Mat dstImage,edge,grayImage;	//参数定义

	//【1】创建与src同类型和大小的矩阵(dst)
	dstImage.create( srcImage.size(), srcImage.type() );


	cvtColor( srcImage, grayImage, COLOR_BGR2GRAY );

	//【3】先用使用 3x3内核来降噪
	blur( grayImage, edge, Size(3,3) );

	//【4】运行Canny算子
	Canny( edge, edge, 3, 9,3 );

	//【5】显示效果图 
	imshow("Canny", edge); 

	waitKey(0); 

	return 0; 
}
