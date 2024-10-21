#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//////////// Image ////////////

void main()
{
	string path = "Resources/WeddingPicture.jpg";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgSmaller, imgCanny, imgDil, imgErode;

	GaussianBlur(img, imgBlur, Size(5, 5), 5, 0);
	Canny(imgBlur, imgCanny, 25, 50);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);

	imshow("Image", img);
	imshow("imageDilation", imgDil);
	imshow("Image Erode", imgErode);
	imshow("ImageCanny", imgCanny);
	imshow("ImageBlur", imgBlur);

	waitKey(0);
}

////////////  Video Capturing ////////////

void main()
{
	string path = "Resources/test_video.mp4";
	VideoCapture capture(path);
	Mat img;

	while (true)
	{

		capture.read(img);
		imshow("Image", img);
		waitKey(100);
	}
}

//////////// WebCamera ////////////

void main()
{
		VideoCapture capture(0);
		Mat img;

		while (true)
		{
			capture.read(img);
			imshow("Image", img);
			waitKey(1);
		}
}