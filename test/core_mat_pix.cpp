#include "core_mat_pix.h"
#include "opencv2/opencv.hpp"

using namespace cv;

void colorReduce(Mat &inputImage, Mat &outputImage, int div);

void test_core_mat_pix()
{
    Mat srcImage = imread("timg.jpeg");
    imshow("src", srcImage);

    Mat dstImage;
    dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());

    double time0 = static_cast<double>(getTickCount());

    colorReduce(srcImage, dstImage, 32);

    time0 = ((double)getTickCount() - time0) / getTickFrequency();
    std::cout << "time : " << time0 << "s" << std::endl;

    imshow("dst", dstImage);
    waitKey(0);
}

void colorReduce(Mat &inputImage, Mat &outputImage, int div)
{
    outputImage = inputImage.clone();
    int rowNumber = outputImage.rows;
    int colNumber = outputImage.cols * outputImage.channels();

    for(int i = 0; i < rowNumber; i++) {

        uchar *data = outputImage.ptr<uchar>(i);

        for(int j = 0; j < colNumber; j++) {
            data[j] = data[j] / div * div + div / 2;
        }
    }

}
