#include "video_display.h"
#include "opencv2/opencv.hpp"

using namespace cv;

void test_video_file_display()
{

    VideoCapture capture(0);
    Mat edges;

    while (1) {
        Mat frame;
        capture >> frame;
        imshow("pic", frame);

        cvtColor(frame, edges, CV_BGR2GRAY);

        blur(edges, edges, Size(7, 7));

        Canny(edges, edges, 0, 30, 3);

        imshow("edges", edges);

        waitKey(30);
    }

    waitKey(0);
}
