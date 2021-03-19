/*#include "opencv2/opencv.hpp"
#include "iostream"

using namespace cv;
int lowThreshold = 30; //% 
 
int main(int, char**) {
    // open the first webcam plugged in the computer
    cv::VideoCapture camera(0);
    
 
    // create a window to display the images from the webcam
   // cv::namedWindow("Webcam", WINDOW_AUTOSIZE);
 
    // this will contain the image from the webcam
    cv::Mat frame;
        
    // capture the next frame from the webcam
    camera >> frame;
    
    // display the frame until you press a key

    Mat frame_gray;
    Mat canny;

    while (1) {
        // show the image on the window
        camera>>frame;
        cvtColor(frame, frame_gray, COLOR_RGB2GRAY);
        Canny(frame_gray, canny, lowThreshold*255/100, lowThreshold*2*255/100, 3);
        cv::imshow("Webcam", canny);
        // wait (10ms) for a key to be pressed
        if (cv::waitKey(10) >= 0)
            break;
    }
    return 0;
}
*\
