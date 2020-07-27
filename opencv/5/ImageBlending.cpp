                                                                                
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


bool  ROI_AddImage();
bool  LinearBlending();
bool  ROI_LinearBlending();
void   ShowHelpText();


int main(   )
{
	system("color 6F");
 
	ShowHelpText();

	if(ROI_AddImage( )&& LinearBlending( )&&ROI_LinearBlending( ))
	{
		cout<<endl<<"\n运行成功，得出了需要的图像";
	}

	waitKey(0);
	return 0;
}



void ShowHelpText()
{
	//输出欢迎信息和OpenCV版本
	printf("\n\n\t\t\t   当前使用的OpenCV版本为：" CV_VERSION );
	printf("\n\n  ----------------------------------------------------------------------------\n");
}




//----------------------------------【ROI_AddImage( )函数】----------------------------------
// 函数名：ROI_AddImage（）
//	描述：利用感兴趣区域ROI实现图像叠加
//----------------------------------------------------------------------------------------------
bool  ROI_AddImage()
{

	// 【1】读入图像
	Mat srcImage1= imread("dota_pa.jpg");
	Mat logoImage= imread("dota_logo.jpg");
	if( !srcImage1.data ) { printf("读取srcImage1错误~！ \n"); return false; }
	if( !logoImage.data ) { printf("读取logoImage错误~！ \n"); return false; }

	// 【2】定义一个Mat类型并给其设定ROI区域
	Mat imageROI= srcImage1(Rect(200,250,logoImage.cols,logoImage.rows));

	// 【3】加载掩模（必须是灰度图）
	Mat mask= imread("dota_logo.jpg",0);

	//【4】将掩膜拷贝到ROI
	logoImage.copyTo(imageROI,mask);

	// 【5】显示结果
	namedWindow("<1>利用ROI实现图像叠加示例窗口");
	imshow("<1>利用ROI实现图像叠加示例窗口",srcImage1);

	return true;
}



bool  LinearBlending()
{
	//【0】定义一些局部变量
	double alphaValue = 0.5; 
	double betaValue;
	Mat srcImage2, srcImage3, dstImage;

	// 【1】读取图像 ( 两幅图片需为同样的类型和尺寸 )
	srcImage2 = imread("mogu.jpg");
	srcImage3 = imread("rain.jpg");

	if( !srcImage2.data ) { printf("读取srcImage2错误！ \n"); return false; }
	if( !srcImage3.data ) { printf("读取srcImage3错误！ \n"); return false; }

	// 【2】进行图像混合加权操作
	betaValue = ( 1.0 - alphaValue );
	addWeighted( srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);

	// 【3】显示原图窗口
	imshow( "<2>线性混合示例窗口【原图】", srcImage2 );
	imshow( "<3>线性混合示例窗口【效果图】", dstImage );

	return true;

}


bool  ROI_LinearBlending()
{

	//【1】读取图像
	Mat srcImage4= imread("dota_pa.jpg",1);
	Mat logoImage= imread("dota_logo.jpg");

	if( !srcImage4.data ) { printf("读取srcImage4错误~！ \n"); return false; }
	if( !logoImage.data ) { printf("读取logoImage错误~！ \n"); return false; }

	//【2】定义一个Mat类型并给其设定ROI区域
	Mat imageROI;
	//方法一
	imageROI= srcImage4(Rect(200,250,logoImage.cols,logoImage.rows));
	//方法二
	//imageROI= srcImage4(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));

	//【3】将logo加到原图上
	addWeighted(imageROI,0.5,logoImage,0.3,0.,imageROI);

	//【4】显示结果
	imshow("<4>区域线性图像混合示例窗口",srcImage4);

	return true;
}

