#  How to scan images, lookup tables and time measurement with OpenCV
## https://docs.opencv.org/master/db/da5/tutorial_how_to_scan_images.html

Goal

Answer following questions:

    -How to go through each and every pixel of an image?
    -How is OpenCV matrix values stored?
    -How to measure the performance of our algorithm?
    -What are lookup tables and why use them?

Test case: Color space reduction.

Better to use lookup table instead of performing division and multiplication operations on every pixel.
image scanning is performed with the three different available methods and the computational time needed for each one is printed.

Basic usage:

how_to_scan_images imageName.jpg intValeToReduce [G]

