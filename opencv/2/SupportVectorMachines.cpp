
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/ml/ml.hpp>
using namespace cv;

//OpenCV3需额外加入：
include <opencv2/imgproc.hpp>
include "opencv2/imgcodecs.hpp"
using namespace cv::ml;


//--------------------------------【help( )函数】----------------------------------------------
//		描述：输出帮助信息
//-------------------------------------------------------------------------------------------------

//-----------------------------------【ShowHelpText( )函数】----------------------------------
//          描述：输出一些帮助信息
//----------------------------------------------------------------------------------------------
void ShowHelpText()
{
	//输出欢迎信息和OpenCV版本
	printf("\n\n\t\t\t\n");
	printf("\n\n\t\t\t\n");
	printf("\n\n\t\t\t   当前使用的OpenCV版本为：" CV_VERSION );
	printf("\n\n  

int main()
{
	// 视觉表达数据的设置（Data for visual representation）
	int width = 512, height = 512;
	Mat image = Mat::zeros(height, width, CV_8UC3);

	//建立训练数据（ Set up training data）
	int labels[4] = {1, -1, -1, -1};
	Mat labelsMat(4, 1, CV_32SC1, labels);

	float trainingData[4][2] = { {501, 10}, {255, 10}, {501, 255}, {10, 501} };
	Mat trainingDataMat(4, 2, CV_32FC1, trainingData);

	ShowHelpText();

	//设置支持向量机的参数（Set up SVM's parameters）
	SVM::Params params;
	params.svmType    = SVM::C_SVC;
	params.kernelType = SVM::LINEAR;
	params.termCrit   = TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6);


	// 训练支持向量机（Train the SVM）
	Ptr<SVM> svm = StatModel::train<SVM>(trainingDataMat, ROW_SAMPLE, labelsMat, params);

	Vec3b green(0,255,0), blue (255,0,0);
	//显示由SVM给出的决定区域 （Show the decision regions given by the SVM）
	for (int i = 0; i < image.rows; ++i)
		for (int j = 0; j < image.cols; ++j)
		{
			Mat sampleMat = (Mat_<float>(1,2) << j,i);
			float response = svm->predict(sampleMat);

			if (response == 1)
				image.at<Vec3b>(i,j)  = green;
			else if (response == -1)
				image.at<Vec3b>(i,j)  = blue;
		}

		//显示训练数据 （Show the training data）
		int thickness = -1;
		int lineType = 8;
		circle( image, Point(501,  10), 5, Scalar(  0,   0,   0), thickness, lineType);
		circle( image, Point(255,  10), 5, Scalar(255, 255, 255), thickness, lineType);
		circle( image, Point(501, 255), 5, Scalar(255, 255, 255), thickness, lineType);
		circle( image, Point( 10, 501), 5, Scalar(255, 255, 255), thickness, lineType);

		//显示支持向量 （Show support vectors）
		thickness = 2;
		lineType  = 8;
		Mat sv = svm->getSupportVectors();

		for (int i = 0; i < sv.rows; ++i)
		{
			const float* v = sv.ptr<float>(i);
			circle(	image,  Point( (int) v[0], (int) v[1]),   6,  Scalar(128, 128, 128), thickness, lineType);
		}

		imwrite("result.png", image);        // 保存图像

		imshow("SVM Simple Example", image); // 显示图像
		waitKey(0);

}
