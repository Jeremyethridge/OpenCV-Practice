#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int Main()
{
	string path = "Resources/shapes.png";
	Mat img = imread(path);

	imshow("Image", img);
}