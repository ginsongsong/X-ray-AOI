#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>
 
using namespace cv;
using namespace std;
 
Mat rotate(Mat src, double angle)
{
    Mat dst;
    Point2f pt(src.cols/2., src.rows/2.);    
    Mat r = getRotationMatrix2D(pt, angle, 1.0);
    warpAffine(src, dst, r, Size(src.cols, src.rows));
    return dst;
}
 
int main(int argc, char *argv[])
{

    Mat src = imread(argv[1]);
    Mat dst[4];
    for(int x=0;x<4;x++)
    {
	
	string s= argv[2]+to_string(x*90)+".png";
	dst[x] = rotate(src, x*90);
	imwrite(s,dst[x]);
    }    

 
    waitKey(0);
    return 0;
}
