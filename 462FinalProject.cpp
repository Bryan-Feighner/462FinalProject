#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// Driver code
int main(int argc, char** argv)
{
    // Read the image file as
    // imread("default.jpg");
    Mat image = imread("D:/Downloads/Lenna.png");
    int choice, brightnessAmt, blur;
    double contrastAmt;
    Mat brighter, contrast, bw, hist, invert, blurry;
    String orgImg = "Original Image";
    String newImg = "New Image";
    // Error Handling
    if (image.empty()) {
        cout << "Image File "
            << "Not Found" << endl;

        // wait for any key press
        cin.get();
        return -1;
    }
    cout << "The image we will be working with is the Lenna reference image. Please make a selection of which type of image processing you would like to perform." << endl;
    cout << "1: Change Brightness\n2: Change Contrast\n3: Convert to black and white\n4: Perform histogram equlization\n5: Invert image\n6: Blur image\n ";
        cin >> choice;
    switch (choice) {
    case 1:
        cout << "You have chosen to brighten your image. How much would you like to brighten it by? Your input can be positive or negative.\nInput: ";
        cin >> brightnessAmt;
        image.convertTo(brighter, -1, 1, brightnessAmt);
        namedWindow(orgImg, WINDOW_NORMAL);
        namedWindow(newImg, WINDOW_NORMAL);
        imshow(orgImg, image);
        imshow(newImg, brighter);
        break;
    case 2:
        cout << "You have chosen to contrast your image. How much would you like to contrast it by? Please only input positive values. Values from 0-1 will reduce contrast and numbers >1 will increase contrast.\nInput: ";
        cin >> contrastAmt;
        image.convertTo(contrast, -1, contrastAmt, 0);
        namedWindow(orgImg, WINDOW_NORMAL);
        namedWindow(newImg, WINDOW_NORMAL);
        imshow(orgImg, image);
        imshow(newImg, contrast);
        break;
    case 3:
        cout << "You have chosen to convert your image to black and white.";
        cvtColor(image, bw, COLOR_BGR2GRAY);
        namedWindow(orgImg, WINDOW_NORMAL);
        namedWindow(newImg, WINDOW_NORMAL);
        imshow(orgImg, image);
        imshow(newImg, bw);
        break;
    case 4:
        cout << "You have chosen perform histogram equialization on your image.";
        break;
    case 5:
        cout << "You have chosen to invert your image.";
        break;
    case 6:
        cout << "You have chosen to blur your image. Would you like homogenous (1) or gaussian (2)?";
        cin >> blur;
        break;
    }
    // Show Image inside a window with
    // the name provided
    //imshow("Window Name", image);

    // Wait for any keystroke
    waitKey(0);
    return 0;
}