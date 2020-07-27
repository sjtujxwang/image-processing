
#include <vector>
#include <stdio.h>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void createAlphaMat(Mat &mat)
{
	for(int i = 0; i < mat.rows; ++i) {
		for(int j = 0; j < mat.cols; ++j) {
			Vec4b&rgba = mat.at<Vec4b>(i, j);
			rgba[0]= UCHAR_MAX;
			rgba[1]= saturate_cast<uchar>((float (mat.cols - j)) / ((float)mat.cols) *UCHAR_MAX);
			rgba[2]= saturate_cast<uchar>((float (mat.rows - i)) / ((float)mat.rows) *UCHAR_MAX);
			rgba[3]= saturate_cast<uchar>(0.5 * (rgba[1] + rgba[2]));
		}
	}
}

void ShowHelpText()
{
	//输出欢迎信息和OpenCV版本
	printf("\n\n\t\t\t\n");
	printf("\n\n\t\t\t\n");
	printf("\n\n\t\t\t   当前使用的OpenCV版本为：" CV_VERSION );
	printf("\n\n  ----------------------------------------------------------------------------\n");
}



int main( )
{
	//创建带alpha通道的Mat
	Mat mat(480, 640, CV_8UC4);
	createAlphaMat(mat);

	//ShowHelpText();

	vector<int>compression_params;
	//此句代码的OpenCV2版为：
	//compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	//此句代码的OpenCV3版为：
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	//显示图片
	try{
		imwrite("Alpha.png", mat, compression_params);
		imshow("png",mat);
		fprintf(stdout,"PNG saved~\n");
		waitKey(0);
	}
	catch(runtime_error& ex) {
		fprintf(stderr,"PNG mistake：%s\n", ex.what());
		return 1;
	}

	return 0;
}
