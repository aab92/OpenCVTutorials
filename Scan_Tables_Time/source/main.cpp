#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "scanReduce.hpp"

using namespace cv;
using namespace std;

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
   
   
   // To measure time
   double t = (double)getTickCount();
   // do something
   
   // first get the image
   Mat image = imread(argv[1], IMREAD_COLOR);
   // now call the eficient way
   image = ScanImageAndReduceC(image, table);
   
   // /do something
   t = ((double)getTickCount() - t)/getTickFrequency();
   cout << "Times passed in seconds: " << t << endl;
	
	waitKey(0);

	return 0;
}