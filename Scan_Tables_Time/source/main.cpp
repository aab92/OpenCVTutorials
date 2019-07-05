#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "scanReduce.hpp"

using namespace cv;
using namespace std;

#define _TO_MILLI	1000

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("usage: how_to_scan_images <Image_Path> intValueToReduce [G] \n");
		return -1;
	}

	// First calculate the lookup table
  int divideWith = 0; // convert our input string to number - C++ style
  stringstream s;
  s << argv[2];
  s >> divideWith;
  if (!s || !divideWith)
  {
      cout << "Invalid number entered for dividing. " << endl;
      return -1;
  }
  uchar table[256];
  for (int i = 0; i < 256; ++i)
     table[i] = (uchar)(divideWith * (i/divideWith));

	// first get the image
	Mat or_image = imread(argv[1], IMREAD_COLOR);
	Mat image = or_image.clone();

  // To measure time
	// The eficient way
  double t = (double)getTickCount();
  Mat image1 = ScanImageAndReduceC(image, table);
  t = ((double)getTickCount() - t)/getTickFrequency();
  cout << "Time passed in milliseconds (efficient way): " << t*_TO_MILLI << endl;

	// The iterator way
	image = or_image.clone();
	t = (double)getTickCount();
	Mat image2 = ScanImageAndReduceIterator(image, table);
	t = ((double)getTickCount() - t)/getTickFrequency();
  cout << "Time passed in milliseconds (iterator way): " << t*_TO_MILLI << endl;

	// The on the fly way
	image = or_image.clone();
	t = (double)getTickCount();
	Mat image3 = ScanImageAndReduceRandomAccess(image, table);
	t = ((double)getTickCount() - t)/getTickFrequency();
  cout << "Time passed in milliseconds (On the fly way): " << t*_TO_MILLI << endl;

	// The Core function
	image = or_image.clone();
	Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();
	for( int i = 0; i < 256; ++i)
	    p[i] = table[i];
	Mat image4;
	t = (double)getTickCount();
	LUT(image, lookUpTable, image4);
	t = ((double)getTickCount() - t)/getTickFrequency();
  cout << "Time passed in milliseconds (On the fly way): " << t*_TO_MILLI << endl;

	// Show image before and after
	namedWindow( "Original Image", WINDOW_AUTOSIZE );
	imshow( "Original Image", or_image );

	namedWindow( "Modified Image", WINDOW_AUTOSIZE );
	imshow( "Modified Image", image4 );

	waitKey(0);

	return 0;
}
