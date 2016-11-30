#include <iostream>
#include <vector>

#include "highgui.h"  
#include "cv.h"  
#include "opencv/cxcore.hpp"  
#include "opencv.hpp"   
#include "opencv2/nonfree/features2d.hpp"

using namespace cv;
using namespace std;



int main(int argc, char *argv[]){
	VideoCapture cap(0);
	int index = 0;

	if (!cap.isOpened()) {
		std::cout << "Error: cannot open the webcam." << std::endl;
	}

	while (true) {
		Mat frame;
		cap >> frame;

		if (frame.empty()) break;
		
		imshow("Webcam", frame);

		int ret = waitKey(1);

		if (ret == 27) break; // Press 'Esc'
		else if (ret == 13) { // Press 'Enter'
			char buf[1024];
			sprintf_s(buf, "webcam%d.jpg", index++);
			imwrite(string(buf), frame);
		}
	}

	return 0;
}