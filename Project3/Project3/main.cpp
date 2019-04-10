#include "Spatial_Filtering.h"
#include<opencv2/opencv.hpp>

int main()
{
	//读入灰度图
	Mat image = imread("G:\\Code\\Digital_image_processing\\images\\2.jpg", 0);
	imshow("source_image", image);

	Spafilt spt;

	//-----------------------------[1] 实验3 --------------------------------

	//利用均值模板平滑灰度图像


	//线性低通滤波器
	float filter[9];
	for (int counter = 0; counter < 9; counter++)
		filter[counter] = (float)1 / 9;
	imshow("linearFilter", spt.linearFilter(image, filter, 3));

	//中值滤波器
	Mat image_noise = spt.addSaltAndPepperNoise(image, 0.2);
	imshow("beforeMedaiFiltering", image_noise);
	imshow("afterMedaiFiltering", spt.medianFilter(image_noise, 3));

	//最大值滤波器
	imshow("maxFilter", spt.maxFilter(image, 3));

	//最小值滤波器
	imshow("mixFilter", spt.minFilter(image, 3));

	//基本高通滤波器
	float highFilter[9] = { 1,  1, 1,  1, -8, 1, 1, 1, 1 };
	imshow("BasicHighPassFilter", spt.basicHighPassFilter(image, highFilter, 3));

	//Roberts交叉算子
	imshow("Roberts", spt.roberts(image));

	//prewitt算子
	imshow("Prewitt", spt.prewitt(image));

	//Sobel算子
	imshow("Sobel", spt.sobel(image));

	//Laplacian锐化处理
	imshow("Laplacian", spt.laplacian(image, 3));

	//高频补偿滤波器
	imshow("highBoost", spt.highBoostFilter(image, 1));

	waitKey(0);
	return 0;
}