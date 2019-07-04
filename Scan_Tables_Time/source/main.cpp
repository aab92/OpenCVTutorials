#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("usage: TestMatClass <Image_Path>\n");
		return -1;
	}


	cv::waitKey(0);

	return 0;
}