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
    int 
    // Error Handling
    if (image.empty()) {
        cout << "Image File "
            << "Not Found" << endl;

        // wait for any key press
        cin.get();
        return -1;
    }
    cout << "The image we will be working with is the Lenna reference image. Please make a selection of which type of image processing you would like to perform." << endl;
    cout << "1: Change Brightness\n 2: Change Contrast\n 3: Convert to black and white\n 4: Perform histogram equlization\n 5: Invert image\n 6: Blur image\n ";
        cin >> choice;
    switch (choice) {
    case 1:
        cout << "You have chosen to brighten your image. How much would you like to brighten it by?"
        cin << 
    }
    // Show Image inside a window with
    // the name provided
    //imshow("Window Name", image);

    // Wait for any keystroke
    waitKey(0);
    return 0;
}