#include <opencv2/opencv.hpp>  //头文件
using namespace cv;  //包含cv命名空间

int main( )
{    
	// 【1】读入一张图片，载入图像
	Mat srcImage = imread("1.jpeg");
	// 【2】显示载入的图片
	imshow("picture",srcImage);
	// 【3】等待任意按键按下
	waitKey(0);
        return 0;

}  
