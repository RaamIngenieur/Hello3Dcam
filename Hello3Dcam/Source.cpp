#include "opencv2/opencv.hpp"

using namespace cv;


int main(int, char**)
{
	VideoCapture cap(1),cap2(2); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;

	namedWindow("Camera 1", 1);
	namedWindow("Camera 2", 1);

	unsigned char *x, *y;

	Mat frame,gray;
	for (;;)
	{
		cap >> frame; // get a new frame from camera
		cvtColor(frame, gray, CV_BGR2GRAY);
		imshow("Camera 1", gray);

		x = gray.data;

		cap2 >> frame; // get a new frame from camera
		cvtColor(frame, gray, CV_BGR2GRAY);
		imshow("Camera 2", gray);

		y = gray.data;

		if (waitKey(30) >= 0) break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}