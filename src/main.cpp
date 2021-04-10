#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/opencv.hpp"

#include <iostream>
#include <thread>
#include <unistd.h>
#include <time.h>

#include "core.h"

using namespace std;
using namespace cv;

void detectAndDisplay( Mat frame, int argc, const char** argv );

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

int main( int argc, const char** argv )
{
    trainedModel = 0;
    float temps;
    clock_t t1, t2;
 
    
 
    // Ton programme
     
    
    
    
    /* -------------------------- PATH TO CHANGE ------------------------------------------------------------ */
    CommandLineParser parser(argc, argv,
                             "{help h||}"
                             "{face_cascade|/home/pi/opencv/data/haarcascades/haarcascade_frontalface_alt.xml|Path to face cascade.}"
                             "{eyes_cascade|/home/pi/opencv/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml|Path to eyes cascade.}"
                             "{camera|0|Camera device number.}");
    parser.about( "\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
                  "You can use Haar or LBP features.\n\n" );
    parser.printMessage();
    String face_cascade_name = samples::findFile( parser.get<String>("face_cascade") );
    //-- 1. Load the cascades
    if( !face_cascade.load( face_cascade_name ) )
    {
        cout << "--(!)Error loading face cascade\n";
        return -1;
    };
    int camera_device = parser.get<int>("camera");
    VideoCapture capture;
    //-- 2. Read the video stream
    capture.open( 0 );
    
    if ( ! capture.isOpened() )
    {
        cout << "--(!)Error opening video capture\n";
        return -1;
    }
    Mat frame;
    //capture >> frame;
    //detectAndDisplay( frame, argc, argv );
    //cout << capture.read(frame);
    while ( capture.isOpened() )
    {
        capture >> frame;
        //printf("in loop");
        if( frame.empty() )
        {
            cout << "--(!) No captured frame -- Break!\n";
            break;
        }
        
        //-- 3. Apply the classifier to the frame

        t1 = clock();
        detectAndDisplay( frame, argc, argv );
        t2 = clock();
        temps = (float)(t2-t1)/CLOCKS_PER_SEC;
        printf("temps = %f\n", temps);
        
        printf(" after detect and display ");
        
        /*if( waitKey(10) == 27 )
        {
            break; // escape
        }*/
    }
    printf(" out of the loop ");
    return 0;
    
}

void detectAndDisplay( Mat frame, int argc, const char** argv)
{
    printf(" in detect and display ");
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
    cout << faces.size();
    //for ( size_t i = 0; i < faces.size(); i++ )
    //{
    if(faces.size() == 1) {
        Point center( faces[0].x + faces[0].width/2, faces[0].y + faces[0].height/2 );
        ellipse( frame, center, Size( faces[0].width/2, faces[0].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4 );
        Mat faceROI = frame_gray( faces[0] );
        //-- In each face, detect eyes
        cv::Mat extract_raw(
            frame_gray, // Frame to copy
            cv::Range( faces[0].y, faces[0].y+faces[0].height ), // Range along Y axis
            cv::Range( faces[0].x, faces[0].x+faces[0].width) // Range along X axis
        );
        resize(extract_raw, frame1, Size(240,320));
        
        /*stringstream s;
        s << i;
        imshow(s.str(), frame1);*/
        imwrite("/home/pi/SecurITCamera/SecurIT/database/unknown/latestImage.pgm", frame1);
        printf(" Image written ");
        predictions(frame1, argc, argv);
    }  
    //}
    printf(" Out of display and predict ");
    //-- Show what you got
    //imshow( "Capture - Face detection", frame ); 
               
       
} 
