#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// Driver code
int main(int argc, char** argv){
    Mat image = imread("D:/Downloads/Lenna.png"); // Replace "D:/Downloads/Lenna.png" with the path to any image you would like to use.
    int choice, brightnessAmt, blurChoice, kernelx, kernely;
    double contrastAmt;
    Mat brighter, contrast, bw, hist, blurry1, blurry2;
    Mat inverter = Mat::ones(image.size(), image.type()) * 255;
    Mat invert = Mat::zeros(image.size(), image.type());
    String orgImg = "Original Image";
    String newImg = "New Image";
    if (image.empty()) {
        cout << "Image File Not Found\n";
        cin.get();
        return -1;
    }
    cout << "The image we will be working with is the Lenna reference image. If you would like to change the image being used, please refer to the comment in line 9. Please make a selection of which type of image processing you would like to perform.\n";
    cout <<"1: Change Brightness\n2: Change Contrast\n3: Convert to black and white\n4: Perform histogram equlization\n5: Invert image\n6: Blur image\n7: Rotate image\n";
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
            cout << "You have chosen perform histogram equialization on your image. This will be done on the grayscale version of the image.";
            cvtColor(image, image, COLOR_BGR2GRAY);
            equalizeHist(image, hist);
            namedWindow(orgImg, WINDOW_NORMAL);
            namedWindow(newImg, WINDOW_NORMAL);
            imshow(orgImg, image);
            imshow(newImg, hist);
            break;
        case 5:
            cout << "You have chosen to invert your image.";
            subtract(inverter, image, invert);
            namedWindow(orgImg, WINDOW_NORMAL);
            namedWindow(newImg, WINDOW_NORMAL);
            imshow(orgImg, image);
            imshow(newImg, invert);
            break;
        case 6:
            cout << "You have chosen to blur your image. Would you like homogenous (1) or gaussian (2)?\nInput: ";
            cin >> blurChoice;
            cout << "What size kernel would you like to use. Input your x value.\nInput: ";
            cin >> kernelx;
            cout << "Input your y value.\nInput: ";
            cin >> kernely;
            if (blurChoice == 1) {
                blur(image, blurry1, Size(kernelx, kernely));
                namedWindow(orgImg, WINDOW_NORMAL);
                namedWindow(newImg, WINDOW_NORMAL);
                imshow(orgImg, image);
                imshow(newImg, blurry1);
            }
            else if (blurChoice == 2) {
                GaussianBlur(image, blurry2, Size(kernelx, kernely), 0);
                namedWindow(orgImg, WINDOW_NORMAL);
                namedWindow(newImg, WINDOW_NORMAL);
                imshow(orgImg, image);
                imshow(newImg, blurry2);
            }
            break;
        case 7:
            cout << "You have chosen to rotate your image. Your image will have a slider above it to allow you to rotate it to your own liking. You will have 10 seconds to rotate the image.";
            namedWindow(orgImg, WINDOW_NORMAL);
            imshow(orgImg, image);
            const char* rotatedImage = "Rotated Image";
            namedWindow(rotatedImage);
            int angle = 180;
            createTrackbar("Angle", rotatedImage, &angle, 360);
            int imageHieght = image.rows / 2;
            int imageWidth = image.cols / 2;
            while (true)
            {
                Mat matRotation = getRotationMatrix2D(Point(imageWidth, imageHieght), (angle - 180), 1);
                Mat imgRotated;
                warpAffine(image, imgRotated, matRotation, image.size());
                imshow(rotatedImage, imgRotated);

                int iRet = waitKey(1);
                if (iRet == 27)
                {
                    break;
                }
            }
            break;
        }
    waitKey(0);
    destroyAllWindows();
    return 0;
}