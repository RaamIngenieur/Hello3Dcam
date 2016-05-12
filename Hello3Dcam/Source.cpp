#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char**)
{
	VideoCapture cap(4); // open the default camera
	double a, b;
	bool c;
	VideoCapture cap2(1);
	if (!cap.isOpened() || !cap2.isOpened())  // check if we succeeded
		return -1;

	a = cap.get(CAP_PROP_FRAME_WIDTH);
	b = cap2.get(CAP_PROP_FRAME_WIDTH);
	c = cap.set(CAP_PROP_FRAME_WIDTH, 160);
	c = cap2.set(CAP_PROP_FRAME_WIDTH, 160);
	a = cap.get(CAP_PROP_FRAME_HEIGHT);
	b = cap2.get(CAP_PROP_FRAME_HEIGHT);
	c = cap.set(CAP_PROP_FRAME_HEIGHT, 120); 
	c = cap2.set(CAP_PROP_FRAME_HEIGHT, 120);


	std::cout << "\n" << a << "\n" << b << "\n" << c << "\n";

	for (;;)
	{
		Mat frame;
		Mat frame2;
		cap2 >> frame2;
		imshow("Camera2", frame2);
		cap >> frame2; // get a new frame from camera
		imshow("Camera1", frame2);
		if (waitKey(30) >= 0) break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}

