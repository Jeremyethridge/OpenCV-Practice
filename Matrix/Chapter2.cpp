#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

float w = 250, h = 350;
Mat matrix, imgWarp, imgWarp2, imgWarp3, imgWarp4;


void main()
{
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	Point2f src[4] = { {65, 322}, {338, 276}, {91, 636}, {401, 575} };
	Point2f src2[4] = { {529, 142}, {771, 190}, {405, 395}, {674, 457} };
	Point2f src3[4] = { {774, 106}, {1015, 83}, {844, 361}, {1119, 327} };
	Point2f src4[4] = { {738, 384}, {1025, 439}, {647, 712}, {967, 782} };
	Point2f dst[4] = { {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	matrix = getPerspectiveTransform(src2, dst);
	warpPerspective(img, imgWarp2, matrix, Point(w, h));

	matrix = getPerspectiveTransform(src3, dst);
	warpPerspective(img, imgWarp3, matrix, Point(w, h));

	matrix = getPerspectiveTransform(src4, dst);
	warpPerspective(img, imgWarp4, matrix, Point(w, h));


	imshow("Image", img);
	imshow("Image Warped", imgWarp);
	imshow("Image Warped2", imgWarp2);
	imshow("Image Warped3", imgWarp3);
	imshow("Image Warped4", imgWarp4);

	waitKey(0);
	
	}