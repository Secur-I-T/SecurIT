
#include "core.h"

#include <opencv2/face.hpp>

using namespace cv;
using namespace cv::face;
using namespace std;

int trainedModel = 0;


static Mat norm_0_255(InputArray _src) {
    Mat src = _src.getMat();
    // Create and return normalized image:
    Mat dst;
    switch(src.channels()) {
    case 1:
        cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
        break;
    case 3:
        cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
        break;
    default:
        src.copyTo(dst);
        break;
    }
    return dst;
}

static void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file) {
        string error_message = "No valid input file was given, please check the given filename.";
        CV_Error(Error::StsBadArg, error_message);
    }
    string line, path, classlabel;
    while (getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        if(!path.empty() && !classlabel.empty()) {
            images.push_back(imread(path, 0));
            labels.push_back(atoi(classlabel.c_str()));
        }
    }
}

static vector<Mat> resizeDataset(vector<Mat>& images) {
    //String face_cascade_name = samples::findFile("/Users/emma/Documents/HEI/HEI4/ProjetS8/opencv-4.5.1/data/haarcascades/haarcascade_frontalface_alt.xml");
    String face_cascade_name = samples::findFile( "/home/pi/opencv/data/haarcascades/haarcascade_frontalface_alt.xml");
    CascadeClassifier face_cascade;
    if( !face_cascade.load( face_cascade_name ) )
    {
        cout << "--(!)Error loading face cascade\n";
    };
    std::vector<Rect> faces;
    vector<Mat> imagesVector;
    for(int i = 0; i<images.size(); i++) {
        //-- In each face, detect eyes
        face_cascade.detectMultiScale( images[i], faces );
        cv::Mat extract_raw(
            images[i], // Frame to copy
            cv::Range( faces[0].y, faces[0].y+faces[0].height ), // Range along Y axis
            cv::Range( faces[0].x, faces[0].x+faces[0].width) // Range along X axis
        );
        resize(extract_raw, extract_raw, Size(240,320));
        imagesVector.push_back(extract_raw);
    }
    return imagesVector;
    

}

void createModel() {
    // Get the path to your CSV.
    string fn_csv = "../database/data.csv";
    // These vectors hold the images and corresponding labels.
    vector<Mat> images;
    vector<int> labels;
    // Read in the data. This can fail if no valid
    // input filename is given.
    try {
        read_csv(fn_csv, images, labels);
        images = resizeDataset(images);
        /*for(int i = 0; i < images.size(); i++){
            stringstream s;
            s << i;
            imshow(s.str(), images[i]);
        }*/
    } catch (const cv::Exception& e) {
        cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl;
        // nothing more we can do
        exit(1);
    }
    // Quit if there are not enough images for this demo.
    if(images.size() <= 1) {
        string error_message = "This demo needs at least 2 images to work. Please add more images to your data set!";
        CV_Error(Error::StsError, error_message);
    }
    // Get the height from the first image. We'll need this
    // later in code to reshape the images to their original
    // size:
    int height = images[0].rows;

    Ptr<EigenFaceRecognizer> model = EigenFaceRecognizer::create();
    model->train(images, labels);

    model->save("/home/pi/SecurITCamera/SecurIT/database/model.xml");

}

void predictions(Mat testSample, int argc, const char *argv[]) {
    if(trainedModel == 0) {
        createModel();
        trainedModel++;
    }
    printf(" Value of trained model %d", trainedModel);
    // Check for valid command line arguments, print usage
    // if no arguments were given.
    
    Ptr<EigenFaceRecognizer> model = EigenFaceRecognizer::create();
    model->read("/home/pi/SecurITCamera/SecurIT/database/model.xml"); 

    // Get the image that we want to predict
    // this is the image previously taken by the camera
    /* -------------------------- PATH TO CHANGE ------------------------------------------------------------ */
    Mat testSample2 = imread("/home/pi/SecurITCamera/SecurIT/database/unknown/latestImage.pgm", IMREAD_GRAYSCALE);
    // we need to reshape the image
    
    /*!!!!!!!!!!!! change to testSample2-----------------------------------------------------*/
    Mat grayscale = norm_0_255(testSample2.reshape(1, 320));

    // The following lines create an Eigenfaces model for
    // face recognition and train it with the images and
    // labels read from the given CSV file.
    // This here is a full PCA

    
    // The following line predicts the label of a given
    // test image:
    int predictedLabel = model->predict(grayscale);
    //
    // To get the confidence of a prediction call the model with:
    //
          double confidence = 0.0;
          model->predict(grayscale, predictedLabel, confidence);
    //
    string result_message = format("Confidence = %lf / Predicted class = %d .", confidence, predictedLabel);
    cout << result_message << endl;

    
    /*
    // Here is how to get the eigenvalues of this Eigenfaces model:
    Mat eigenvalues = model->getEigenValues();
    // And we can do the same to display the Eigenvectors (read Eigenfaces):
    Mat W = model->getEigenVectors();
    // Get the sample mean from the training data
    Mat mean = model->getMean();
    // Display or save:
    if(argc == 2) {
        imshow("mean", norm_0_255(mean.reshape(1, images[0].rows)));
    } else {
        imwrite(format("%s/mean.png", output_folder.c_str()), norm_0_255(mean.reshape(1, images[0].rows)));
    }
    // Display or save the Eigenfaces:
    for (int i = 0; i < min(10, W.cols); i++) {
        string msg = format("Eigenvalue #%d = %.5f", i, eigenvalues.at<double>(i));
        cout << msg << endl;
        // get eigenvector #i
        Mat ev = W.col(i).clone();
        // Reshape to original size & normalize to [0...255] for imshow.
        Mat grayscale = norm_0_255(ev.reshape(1, height));
        // Show the image & apply a Jet colormap for better sensing.
        Mat cgrayscale;
        applyColorMap(grayscale, cgrayscale, COLORMAP_JET);
        // Display or save:
        if(argc == 2) {
            imshow(format("eigenface_%d", i), cgrayscale);
        } else {
            imwrite(format("%s/eigenface_%d.png", output_folder.c_str(), i), norm_0_255(cgrayscale));
        }
    }
    // Display or save the image reconstruction at some predefined steps:
    for(int num_components = min(W.cols, 10); num_components < min(W.cols, 300); num_components+=15) {
        // slice the eigenvectors from the model
        Mat evs = Mat(W, Range::all(), Range(0, num_components));
        Mat projection = LDA::subspaceProject(evs, mean, images[0].reshape(1,1));
        Mat reconstruction = LDA::subspaceReconstruct(evs, mean, projection);
        // Normalize the result:
        reconstruction = norm_0_255(reconstruction.reshape(1, images[0].rows));
        // Display or save:
        if(argc == 2) {
            imshow(format("eigenface_reconstruction_%d", num_components), reconstruction);
        } else {
            imwrite(format("%s/eigenface_reconstruction_%d.png", output_folder.c_str(), num_components), reconstruction);
        }
    }
    // Display if we are not writing to an output folder:
    if(argc == 2) {
        waitKey(0);
    }*/
    
}
