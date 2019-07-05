#ifndef SCANREDUCE_H
#define SCANREDUCE_H

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat& ScanImageAndReduceC(Mat& I, const uchar* const table);
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table);
Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const table);

#endif
