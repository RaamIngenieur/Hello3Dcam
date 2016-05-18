#include "opencv\cv.h"
#include "opencv\highgui.h"

#include "videoInput.h"

using namespace cv;

int main(int argc, char ** argv)
{
	videoInput::listDevices();		// get list of devices
	videoInput * vi = new videoInput();   	//required class to manage all the cameras
	vi->setupDevice(0);			// choose first device (device 0)

	vi->setupDevice(3);

	static char * windowName = "videoInput Library Video Example"; // window name

	// if all is OK with device 0

	IplImage* img = cvCreateImage(cvSize(vi->getWidth(0), vi->getHeight(0)), 8, 3), *img2 = cvCreateImage(cvSize(vi->getWidth(3), vi->getHeight(3)), 8, 3);

	// create a window and an OpenCV image (assuming 8 bit, 3 channel image)

	cvNamedWindow("Camera 1", 1);
	cvNamedWindow("Camera 2", 1);

	if (vi->isDeviceSetup(0) && vi->isDeviceSetup(3))
	{


		// loop forever (or until we press "x" to break the loop)

		while (1)
		{
			// if we have a new frame on the camera buffer

			if (vi->isFrameNew(0))
			{
				// get the pixels from the image to the "imageData" of the OpenCV
				// image (here we assign it's an 8-bit 3 channel image

				// BGR order, flipped (=> do not requrie flipping or origin fixes)

				// N.B. This is a data "copy", see getPixels() doc. for info.

				vi->getPixels(0, (unsigned char*)img->imageData, false, true);


				// !!! DO ALL OpenCV IMAGE PROCESSING HERE USING img AS INPUT
				// !!!
				// !!!

				// display the image in an OpenCV window

				cvShowImage("Camera 1", img);
				char key = cvWaitKey(1); // wait only for 1ms because we will 
				// only refresh when we have a new frame

				// if the user presses "x" then break the loop and exit

				if (key == 'x')
				{
					break;
				}
			}

			if (vi->isFrameNew(3))
			{
				// get the pixels from the image to the "imageData" of the OpenCV
				// image (here we assign it's an 8-bit 3 channel image

				// BGR order, flipped (=> do not requrie flipping or origin fixes)

				// N.B. This is a data "copy", see getPixels() doc. for info.

				vi->getPixels(3, (unsigned char*)img2->imageData, false, true);


				// !!! DO ALL OpenCV IMAGE PROCESSING HERE USING img AS INPUT
				// !!!
				// !!!

				// display the image in an OpenCV window

				cvShowImage("Camera 2", img2);
				char key = cvWaitKey(1); // wait only for 1ms because we will 
				// only refresh when we have a new frame

				// if the user presses "x" then break the loop and exit

				if (key == 'x')
				{
					break;
				}
			}
		}

		// release the allocated image (N.B. it is not deallocated by the video device)

		cvReleaseImage(&img);
		cvReleaseImage(&img2);
	}

	// stop the video device

	vi->stopDevice(0);
	vi->stopDevice(3);

	system("pause");

	return 0;

}

