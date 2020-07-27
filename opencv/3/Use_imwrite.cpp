
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
	//�����ӭ��Ϣ��OpenCV�汾
	printf("\n\n\t\t\t\n");
	printf("\n\n\t\t\t\n");
	printf("\n\n\t\t\t   ��ǰʹ�õ�OpenCV�汾Ϊ��" CV_VERSION );
	printf("\n\n  ----------------------------------------------------------------------------\n");
}



int main( )
{
	//������alphaͨ����Mat
	Mat mat(480, 640, CV_8UC4);
	createAlphaMat(mat);

	//ShowHelpText();

	vector<int>compression_params;
	//�˾�����OpenCV2��Ϊ��
	//compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	//�˾�����OpenCV3��Ϊ��
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	//��ʾͼƬ
	try{
		imwrite("Alpha.png", mat, compression_params);
		imshow("png",mat);
		fprintf(stdout,"PNG saved~\n");
		waitKey(0);
	}
	catch(runtime_error& ex) {
		fprintf(stderr,"PNG mistake��%s\n", ex.what());
		return 1;
	}

	return 0;
}
