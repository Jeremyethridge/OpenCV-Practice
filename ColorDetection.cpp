#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace cv;
using namespace std;

Mat imgHSV, mask;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

void main ()
{


	string path = "Resources/shapes.png";
	Mat img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Saturation Min", "Trackbars", &smin, 179);
	createTrackbar("Saturation Max", "Trackbars", &smax, 179);
	createTrackbar("Value Min", "Trackbars", &vmin, 179);
	createTrackbar("Value Max", "Trackbars", &vmax, 179);


	while (true)
	{
	// Hue, Saturation, and Value minimum and maximum values
	Scalar lower(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
	inRange(imgHSV, lower, upper, mask);

	imshow("Image", img);
	//imshow("ImageHSV", imgHSV);
	imshow("Mask", mask);
	waitKey(0);
	};
}