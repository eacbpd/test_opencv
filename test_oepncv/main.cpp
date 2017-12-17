#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(){
	//给矩阵加载资源
	Mat imgb = imread("imgb.jpg");
	Mat imgs = imread("imgs.jpg");
	if(imgs.empty()||imgb.empty())
		perror("imread");

	//合并矩阵
	Mat combine;
	//方法1
	//combine.push_back(img);combine.push_back(img);
	//方法2
	//Size size(img.cols+img.cols,MAX(img.rows,img.rows));
	Size size(imgb.cols+imgb.cols,imgb.rows+imgb.rows);
	combine.create(size,CV_MAKETYPE(imgb.depth(),3));
	combine = Scalar::all(0);
	Mat outImg_lt,outImg_rt,outImg_lb,outImg_rb;
	outImg_lt = combine(Rect(0,0,imgb.cols,imgb.rows));
	outImg_rt = combine(Rect(imgb.cols,0,imgs.cols,imgs.rows));
	outImg_lb = combine(Rect(0,imgb.rows,imgs.cols,imgs.rows));
	outImg_rb = combine(Rect(imgb.cols,imgb.rows,imgb.cols,imgb.rows));
	//将待拷贝图像拷贝到目的区域中
	imgb.copyTo(outImg_lt);imgb.copyTo(outImg_rb);
	imgs.copyTo(outImg_rt);imgs.copyTo(outImg_lb);

	//
	//namedWindow("合并后的图像");
	//cvNamedWindow("title");

	//显示图像
	imshow("graph",combine);

	//不带等待时间的waitKey
	waitKey();
	return 0;
}










