
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;


int main( )
{
	//-----------------------------------【一、图像的载入和显示】---------------------------------
	//	描述：以下三行代码用于完成图像的载入和显示
	//--------------------------------------------------------------------------------------------------

	Mat girl=imread("girl.jpg"); //载入图像到Mat
	namedWindow("virtul"); //创建一个名为 "【1】动漫图"的窗口  
	imshow("virtul",girl);//显示名为 "【1】动漫图"的窗口  

	//-----------------------------------【二、初级图像混合】--------------------------------------
	//	描述：二、初级图像混合
	//--------------------------------------------------------------------------------------------------
	//载入图片
	Mat image= imread("dota.jpg",199);
	Mat logo= imread("dota_logo.jpg");

	//载入后先显示
	namedWindow("origin");
	imshow("origin",image);

	namedWindow("logo");
	imshow("logo",logo);

	// 定义一个Mat类型，用于存放，图像的ROI
	Mat imageROI;
	//方法一
	imageROI= image(Rect(800,350,logo.cols,logo.rows));
	//方法二
	//imageROI= image(Range(350,350+logo.rows),Range(800,800+logo.cols));

	// 将logo加到原图上
	addWeighted(imageROI,0.5,logo,0.3,0.,imageROI);

	//显示结果
	namedWindow("orign+logo");
	imshow("orign+logo",image);

	//-----------------------------------【三、图像的输出】--------------------------------------
	//	描述：将一个Mat图像输出到图像文件
	//-----------------------------------------------------------------------------------------------
	//输出一张jpg图片到工程目录下
	imwrite("imwrite_save.jpg",image);

	waitKey();

	return 0;
}
