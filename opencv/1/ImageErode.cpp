
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
int main(   )
{
	//载入原图  
	Mat srcImage = imread("1.jpg");
	//显示原图
	imshow("origin", srcImage);
	//进行腐蚀操作 
	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(srcImage, dstImage, element);
	//显示效果图 
	imshow("after", dstImage);
	waitKey(0); 
	return 0;
}

