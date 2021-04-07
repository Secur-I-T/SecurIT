/*#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/opencv.hpp"



#include <iostream>
#include <thread>
#include <unistd.h>

#include "core.h"

using namespace std;
using namespace cv;

void detectAndDisplay( Mat frame, int argc, const char** argv );

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

int main( int argc, const char** argv )
{
    /* -------------------------- PATH TO CHANGE ------------------------------------------------------------ */
    /*CommandLineParser parser(argc, argv,
                             "{help h||}"
                             "{face_cascade|/home/pi/opencv/data/haarcascades/haarcascade_frontalface_alt.xml|Path to face cascade.}"
                             "{eyes_cascade|/home/pi/opencv/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml|Path to eyes cascade.}"
                             "{camera|0|Camera device number.}");
    parser.about( "\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
                  "You can use Haar or LBP features.\n\n" );
    parser.printMessage();
    String face_cascade_name = samples::findFile( parser.get<String>("face_cascade") );
    String eyes_cascade_name = samples::findFile( parser.get<String>("eyes_cascade") );
    //-- 1. Load the cascades
    if( !face_cascade.load( face_cascade_name ) )
    {
        cout << "--(!)Error loading face cascade\n";
        return -1;
    };
    if( !eyes_cascade.load( eyes_cascade_name ) )
    {
        cout << "--(!)Error loading eyes cascade\n";
        return -1;
    };
    VideoCapture camera;
    // Allowable values: RASPICAM_FORMAT_GRAY,RASPICAM_FORMAT_RGB,RASPICAM_FORMAT_BGR,RASPICAM_FORMAT_YUV420
    //camera.setFormat(raspicam::RASPICAM_FORMAT_RGB);
    //camera.setCaptureSize(240,320);
    //VideoCapture capture;
    //-- 2. Read the video stream
    //capture.open( Camera );
    camera.open(0);
    if ( ! camera.isOpened() )
    {
        cout << "--(!)Error opening video capture\n";
        return -1;
    }
    Mat frame;
    camera >> frame;
    camera >> frame;
    camera >> frame;
    while ( camera.read(frame) )
    {
        if( frame.empty() )
        {
            cout << "--(!) No captured frame -- Break!\n";
            break;
        }
        //-- 3. Apply the classifier to the frame
        detectAndDisplay( frame, argc, argv );
        
        if( waitKey(10) == 27 )
        {
            break; // escape
        }
    }
    return 0;
    
}

void detectAndDisplay( Mat frame, int argc, const char** argv)
{
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    Mat frame_gray;
    Mat frame1;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );
    //-- Detect faces
    std::vector<Rect> faces;
    face_cascade.detectMultiScale( frame_gray, faces );
    //-- If we dectect faces --> resize;gray;capture --> predict
    if(faces.size() == 1) {
               
        resize(frame_gray, frame1, Size(240,320));
        /* -------------------------- PATH TO CHANGE ------------------------------------------------------------ */
        /*imwrite("/home/pi/SecurITCamera/SecurIT/database/unknown/latestImage.pgm", frame1);
        //predictions(argc, argv);
        
    }

    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4 );
        Mat faceROI = frame_gray( faces[i] );
        //-- In each face, detect eyes
        std::vector<Rect> eyes;
        eyes_cascade.detectMultiScale( faceROI, eyes );
        for ( size_t j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4 );
        }
    }
    //-- Show what you got
    imshow( "Capture - Face detection", frame );    
  
       
} */
