#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstring>

using namespace cv;
using namespace std;

Mat dst;

int hmin = 120, hmax = 255, smin = 0, smax = 179, vmin = 194, vmax = 130;
int op = 9, cl = 3, er = 3, di = 3;

void nothing(int, void *) {}

void create_all_trackbar(string name_color = "nuller", string name_mor = "nuller")
{

    createTrackbar("hmin", name_color, &hmin, 255, nothing);
    createTrackbar("hmax", name_color, &hmax, 255, nothing);
    createTrackbar("smin", name_color, &smin, 255, nothing);
    createTrackbar("smax", name_color, &smax, 255, nothing);
    createTrackbar("vmin", name_color, &vmin, 255, nothing);
    createTrackbar("vmax", name_color, &vmax, 255, nothing);

    createTrackbar("open", name_mor, &op, 30, nothing);
    createTrackbar("close", name_mor, &cl, 30, nothing);
    createTrackbar("erode", name_mor, &er, 30, nothing);
    createTrackbar("dilate", name_mor, &di, 30, nothing);
}
Mat do_mask_color(Mat color_adjust_resized)
{
    // GaussianBlur(color_adjust_resized, color_adjust_resized, Size(3, 3), 3, 3);
    Mat lower_hsv = (Mat_<uchar>(1, 3) << hmin, smin, vmin);
    Mat upper_hsv = (Mat_<uchar>(1, 3) << hmax, smax, vmax);
    inRange(color_adjust_resized, lower_hsv, upper_hsv, dst);
    return dst;
}

Mat open_binary(Mat binary, int x, int y)
{
    Mat kernel = getStructuringElement(MORPH_RECT, Size(x, y));
    morphologyEx(binary, dst, MORPH_OPEN, kernel);
    return dst;
}
Mat close_binary(Mat binary, int x, int y)
{
    Mat kernel = getStructuringElement(MORPH_RECT, Size(x, y));
    morphologyEx(binary, dst, MORPH_CLOSE, kernel);
    return dst;
}
Mat erode_binary(Mat binary, int x, int y)
{
    Mat kernel = getStructuringElement(MORPH_RECT, Size(x, y));
    erode(binary, dst, kernel);
    return dst;
}
Mat dilate_binary(Mat binary, int x, int y)
{
    Mat kernel = getStructuringElement(MORPH_RECT, Size(x, y));
    dilate(binary, dst, kernel);
    return dst;
}
Mat do_mask_mor(Mat binary, int o = 1, int c = 1, int e = 1, int d = 1)
{
    if (o == 1)
    {
        open_binary(binary, op, op);
    }

    if (c == 1)
    {
        close_binary(binary, cl, cl);
    }

    if (e == 1)
    {
        erode_binary(binary, er, er);
    }

    if (d == 1)
    {
        dilate_binary(binary, di, di);
    }

    return dst;
}