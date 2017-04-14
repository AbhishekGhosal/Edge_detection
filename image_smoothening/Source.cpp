#include<opencv2\opencv.hpp>

int main(int argv, char * args[])
{
	cv::Mat imageIn = cv::imread("Image.jpg");
	if (imageIn.empty())
	{
		std::cout << "error loading input image" << std::endl;
		system("pause");
		return 0;
	}
	cv::Mat kernel = (cv::Mat_<double >(5, 5) << 2,4,5,4,2,4,9,12,9,4,5,12,15,12,5,4,9,12,9,4,2,4,5,4,2);
	kernel = kernel / 159;
	
	cv::Mat image_blur, image_gray;
	cv::filter2D(imageIn, image_blur, -1, kernel, cv::Point(-1, -1), 0);

	cv::cvtColor(image_blur, image_gray, CV_RGB2GRAY);
	
	cv::namedWindow("original image", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("Smoothed Image", CV_WINDOW_AUTOSIZE);
	cv::imshow("original image", imageIn);
	cv::imshow("Smoothed Image", image_gray);
	
	
	
	
	
	cv::waitKey(0);
	return 0;



}