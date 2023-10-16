// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include<vector>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage ();

void  SHUFFLE_ForImage();
void saveImage ();

int main()
{
  loadImage();
 SHUFFLE_ForImage();
  saveImage();
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}
void Blur(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(i>1&&j>1&&i<254&&j<254)
                image[i][j]=(image[i][j]+image[i-1][j]+image[i-2][j]+image[i][j-1]+image[i][j-2]+image[i][j+2]+image[i][j+1]+image[i+1][j]+image[i+2][j])/9;
            else if(i==0&&j==0)
                image[i][j]=(image[i][j]+image[i+1][j]+image[i+2][j]+image[i][j+1]+image[i][j+2])/5;//corner
            else if(i==255&&j==255)
                image[i][j]=(image[i][j]+image[i-1][j]+image[i-2][j]+image[i][j-1]+image[i][j-2])/5;//corner
            else if(i==255&&j==0)
                image[i][j]=(image[i][j]+image[i-1][j]+image[i-2][j]+image[i][j+1]+image[i][j+2])/5;//corner
            else if(i==0&&j==255)
                image[i][j]=(image[i][j]+image[i+1][j]+image[i+2][j]+image[i][j-1]+image[i][j-2])/5;//corner
            else if(i==1&&j==0)
                image[i][j]=(image[i][j]+image[i+1][j]+image[i+2][j]+image[i][j+1]+image[i][j+2]+image[i-1])[j]/6;
            else if(i==254&&j==0)
                image[i][j]=(image[i][j]+image[i-1][j]+image[i-2][j]+image[i][j+1]+image[i][j+2]+image[i+1][j])/6;
            else if(i==255&&j>0&&j<255)
                image[i][j]=(image[i][j]+image[i-1][j]+image[i-2][j]+image[i][j+1]+image[i][j-1])/5;
            else if(i==0&&j>0&&j<255)
                image[i][j]=(image[i][j]+image[i+1][j]+image[i+2][j]+image[i][j+1]+image[i][j-1])/5;
            else if(i==1&&j>0&&j<255)
                image[i][j]=(image[i][j]+image[i+1][j]+image[i+2][j]+image[i][j+1]+image[i][j-1]+image[i-1])[j]/6;
            else if(i==254&&j==0&&j<255)
                image[i][j]=(image[i][j]+image[i-1][j]+image[i-2][j]+image[i][j+1]+image[i][j-1]+image[i+1][j])/6;
            else if(i==255&&j>0&&j<255)
                image[i][j]=(image[i][j]+image[i-1][j]+image[i-2][j]+image[i][j+1]+image[i][j-2])/5;



        }
    }
}

//_________________________________________
void Blur_ForImage() {
    Blur();
    Blur();
    Blur();
    Blur();
    Blur();
    }