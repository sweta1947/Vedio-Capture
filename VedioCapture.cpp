#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main()
{
	VideoCapture a(0);
	Mat img;
	a >> img;
	while (a.isOpened())
	{
		Mat gray, edge, draw;
		a >> img;
		imshow("image1", img);
		cvtColor(img, gray, CV_BGR2GRAY);
		Canny(gray, edge, 50, 150, 3);
		edge.convertTo(draw, CV_8U);
		namedWindow("image", CV_WINDOW_AUTOSIZE);
		imshow("image", draw);
		if (waitKey(10) == 'q')
		{
			//Mat a;
			imwrite("junk.jpg", img);
			break;
		}
		//waitKey(10);
	}
	//return 0;
}