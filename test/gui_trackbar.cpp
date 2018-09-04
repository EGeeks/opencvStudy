#include "gui_trackbar.h"
#include "opencv2/opencv.hpp"

using namespace cv;

#define WINDOW_NAME " [线性混合]"

const int g_nMaxAlphaValue = 100;
int g_nAlphaValueSlider;
double g_dAlphaValue;
double g_dBetaValue;

Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;

void on_Trackbar(int pos, void *)
{
    g_dAlphaValue = (double) g_nAlphaValueSlider / g_nMaxAlphaValue;
    g_dBetaValue = 1.0 - g_dAlphaValue;

    addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);

    imshow(WINDOW_NAME, g_dstImage);
}

void test_gui_trackbar()
{
    g_srcImage1 = imread("timg.jpeg");
    g_srcImage2 = imread("shuidi.jpeg");

    resize(g_srcImage2, g_srcImage2, Size(g_srcImage1.cols, g_srcImage1.rows));

    if(!g_srcImage1.data) {
        printf("not pic\n");
        return;
    }

    if(!g_srcImage2.data) {
        printf("not pic\n");
        return;
    }

    g_nAlphaValueSlider = 70;

    namedWindow(WINDOW_NAME, 1);

    char TrackbarName[50];
    sprintf(TrackbarName, "aplha:%d", g_nAlphaValueSlider);

    createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
    on_Trackbar(g_nAlphaValueSlider, 0);

    waitKey(0);

    return;
}
