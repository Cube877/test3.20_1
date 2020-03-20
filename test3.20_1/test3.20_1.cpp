// test3.20_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;


int main()
{
	Mat srcMat = imread("E:\\Picture\\coin.png");
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3,3));
	Mat grayMat;
	Mat srcMat_b;
	Mat dst_erode;
	Mat dst_dilate;
	Mat dst_open;
	Mat dst_close;
	cvtColor(srcMat, grayMat, COLOR_BGR2GRAY);
	threshold(grayMat, srcMat_b, 100, 255, THRESH_OTSU);
	erode(srcMat_b, dst_erode, kernel);
	dilate(srcMat_b, dst_dilate, kernel);
	morphologyEx(srcMat_b, dst_open, MORPH_OPEN, kernel);
	morphologyEx(srcMat_b, dst_close, MORPH_CLOSE, kernel);
	imshow("srcMat", srcMat);
	imshow("srcMat_b", srcMat_b);
	imshow("dst_erode", dst_erode);
	imshow("dst_dilate", dst_dilate);
	imshow("dst_open", dst_open);
	imshow("dst_close", dst_close);
	waitKey();
    return 0;
}

