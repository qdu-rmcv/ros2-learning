#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include "color_mor.hpp"

using namespace cv;
using namespace std;

float WIDTH = 780, HEIGH = 540;
float WIDTH_HEIGHT_RATIO = 1.5;
float AREA = WIDTH * HEIGH;

float WIDTH_HEIGHT_RATIO_MAX = 10;
float WIDTH_HEIGHT_RATIO_MIN = 0.2;

float ANGLE = 90;
float ANGLE_ABS = 45;

float AREA_MAX = 0.01 * AREA;
float AREA_MIN = 0.0005 * AREA; // 210 < area < 421

float PLATE_WIDTH_HIGH_RATIO = 0.5;

Point2f auto_centre(string PIC_PATH)
{
    Mat frame = imread(PIC_PATH);
    // VideoCapture cap(0);
    // cap >> frame;
    flip(frame, frame, 1);
    // frame = imread(PIC_PATH + to_string(3) + ".jpg");/////////////////////////////
    resize(frame, frame, Size(WIDTH, HEIGH));

    Mat color_adjust_resized;
    Mat frame_copy(frame);
    cvtColor(frame_copy, color_adjust_resized, COLOR_BGR2HSV);
    do_mask_color(color_adjust_resized);
    do_mask_mor(dst);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    vector<Point2f> box_centers;
    findContours(dst, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    for (size_t i = 0; i < contours.size(); i++)
    {
        RotatedRect rect = minAreaRect(contours[i]);
        Point2f box_center = rect.center;
        float width = rect.size.width;
        float height = rect.size.height;
        float angle = rect.angle;
        float width_height_ratio = width / height;
        float area = width * height;

        if (WIDTH_HEIGHT_RATIO_MIN < width_height_ratio && width_height_ratio < WIDTH_HEIGHT_RATIO_MAX && (abs(angle - ANGLE) < 20 || abs(angle - ANGLE) > 70) && AREA_MIN < area && area < AREA_MAX)
        {
            box_centers.push_back(box_center);
        }
    }

    if (box_centers.size() == 2)
    {
        /***********打击中心***************/
        Point2f center;
        center.x = (box_centers[0].x + box_centers[1].x) / 2;
        center.y = (box_centers[0].y + box_centers[1].y) / 2;

        return center;
    }
    else
    {
        Point2f center;
        center.x = -1;
        center.y = -1;
        return center;
    }
}
