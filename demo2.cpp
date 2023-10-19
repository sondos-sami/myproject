/*name :mariam Eid mohamed  >>ID:20220330  >>Email:mariameid210@gmail.com
  name :Sondos Smami Rabi   >>ID:20220156  >>Email:samysnds99@gmail.com
  name:Dina  Ibrahim Hassan >>ID:20220541  >> dinaelrubii12@icloud.com


*/

#include <cmath>
#include<vector>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];


void loadImage () {
   char imageFileName[100];

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
    }
void BW () {
    int avg = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            avg += image[i][j];
        }
    }
    avg /= (SIZE*SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (image[i][j] > avg)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}

void invert(){
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            image[i][j]=255-image[i][j];//black inverses into white and vice versa
        }
    }
}

void Flip(){
    cout<<"Do you want to flip vertically (1) or horizontally (2) ? " ;
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j <SIZE ; ++j) {
            flipped_image[i][j] = 255;
        }
    }
    int s;
    cin>>s;
    if(s==2){
        for(int j=0;j<SIZE;++j){
            for(int i=0;i<SIZE;++i){
                flipped_image[i][j]=image[256-i][j];
            }
        }
    }
    else{
        for(int j=0;j<SIZE;++j){
            for(int i=0;i<SIZE;++i){
                flipped_image[i][j]=image[i][256-j];
            }
        }
    }
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j <SIZE ; ++j) {
            image[i][j] = flipped_image[i][j];
        }
    }
}

void merge(){
    unsigned char merge[SIZE][SIZE];
    char mergeImage[100];
    cout << "Enter the name of image file to merge with: " << endl;
    cin >> mergeImage;

    strcat(mergeImage , ".bmp");
    readGSBMP(mergeImage , merge);

    for (int i = 0; i < SIZE ; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = (image[i][j] + merge[i][j])/2;
        }
    }
}

void darken_or_brighten(){
    cout<<"Do you want to darken (1) or lighten (2) ? ";
    int n;
    cin>>n;

    if(n == 2){

        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                image[i][j] += (256 - image[i][j])/2;
            }
        }

    }else{
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                image[i][j] -= (image[i][j]/2);
            }
        }

    }
}
void ROTATE_ForImage() {
    int degree;
    cout<<"Please enter degree:";
    cin>>degree;
    if(degree==90){
        for (int i = 0; i < SIZE; i++) {
            for (int j = i; j < SIZE; j++) {
                int temp=image[i][j];
                image[i][j]=image[j][i];//to transpose
                image[j][i]=temp;
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE/2; j++) {
                int temp=image[i][j];
                image[i][j]=image[i][SIZE-1-j];//to swap columns
                image[i][SIZE-1-j]=temp;
            }
        }
    }
    else if(degree==180){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j < SIZE; j++){
                swap(image[i][j],image[SIZE-1-i][j]);}}//to swap rows
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE/2; j++){
                swap(image[i][j],image[i][SIZE-1-j]);}}//to swap columns
    }
    else{
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE/2; j++){
                swap(image[i][j],image[i][SIZE-1-j]);}}//to  swap rows
        for (int i = 0; i < SIZE; i++) {
            for (int j = i; j < SIZE; j++){
                swap(image[i][j],image[j][i]);}}//to transpose


    }

}

void Detect_edges(){
    int avg=0;
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            avg+=image[i][j];
        }
    }  avg /= (SIZE*SIZE);//average represent the average of gray level of the pixels of the image
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            if((image[i][j]>avg and image[i][j+1]<=avg )||(image[i][j]<=avg and image[i+1][j]>avg ) ||( image[i][j]<=avg and image[i][j+1]>avg )|| (image[i][j]>avg and image[i+1][j]<=avg )||(image[i][j]>avg and image[i+1][j+1]<=avg )||(image[i][j]<=avg and image[i+1][j+1]>avg )){
                image[i][j]=0;//we copmpare between( image pixel and average) and( the right pixel of it and average)if any of them is greater than average and the other is less yhan it then we consider it an edge and turn the pixel into black
            } else{
                image[i][j]=255;
            }
        }
    }

}
void  enlarge(){
    unsigned char enlarged_image [SIZE][SIZE];

    cout<<"Which quarter to enlarge 1,2,3 or 4 ?";
    int num;
    cin>>num;
    if(num==1){
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                enlarged_image[i][j]=255;
            }
        }
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                enlarged_image[i][j]=image[i/2][j/2];//each pixel of the main image  is duplicated in the enlarged image
            }
        }
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                image[i][j] = enlarged_image[i][j];
            }
        }



    }else if(num==2){
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                enlarged_image[i][j]=255;
            }
        }
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                enlarged_image[i][j]=image[i/2][(j/2)+127];
            }
        }
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                image[i][j] = enlarged_image[i][j];
            }
        }}
    else if(num==3){
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                enlarged_image[i][j]=255;
            }
        }
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                enlarged_image[i][j]=image[(i/2)+127][j/2];
            }
        }
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                image[i][j] = enlarged_image[i][j];
            }
        }
    }
    else {
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                enlarged_image[i][j]=255;
            }
        }
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                enlarged_image[i][j]=image[(i/2)+127][(j/2)+127];
            }
        }
        for(int i=0;i<SIZE;++i){
            for(int j=0;j<SIZE;++j){
                image[i][j] = enlarged_image[i][j];
            }
        }}}

void  shrink(){
    unsigned char shrinked_image [SIZE][SIZE];
    cout<<"Shrink to 1/2 <<enter (2), 1/3 <<  enter (3) or 1/4<<enter (4)?";

    float num;
    cin>>num;

    if(num==2) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                shrinked_image[i][j] = 255;
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                shrinked_image[i / 2][j / 2] = image[i][j];//each pixel in the shrinked image is originally 2 pixels in the main image
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = shrinked_image[i][j];
            }
        }

    }else if(num==3){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                shrinked_image[i][j] = 255;
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                shrinked_image[i / 3][j / 3] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = shrinked_image[i][j];
            }}
    }
    else
    { for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                shrinked_image[i][j] = 255;
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                shrinked_image[i / 4][j / 4] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = shrinked_image[i][j];
            }}

    }
}
void skew_horizontal(){
    unsigned char shrinked_image[SIZE][SIZE];
    unsigned char skewed_iamge[SIZE][SIZE];
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j <SIZE ; ++j) {
            shrinked_image[i][j] = 255;
            skewed_iamge[i][j] = 255;
        }
    }
    double degree;
    cout<<" Enter the angle  to skew with : ";
    cin>>degree;
    degree=(degree*22)/(180*7);//convert angle from degrees into radian
    int  x= 256/(1+(1/tan(degree)));

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            shrinked_image[i][(j * x)/SIZE] = image[i][j];//each pixel in the shrinked image is originally x pixels in the main image
        }//here we shrinked only the coulms wth percent of x
    }
    double step =SIZE-x;
    double move=step/SIZE;
    for(int i=0;i<SIZE;++i){
        for(int j=(int)step;j<(step+x);++j){
            skewed_iamge[i][j]=shrinked_image[i][j-(int)step];
        }
        step-=move;
    }
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            image[i][j]=skewed_iamge[i][j];
        }
    }
}
void skew_vertical(){
    unsigned char shrinked_image[SIZE][SIZE];
    unsigned char skewed_iamge[SIZE][SIZE];
    for (int i = 0; i <SIZE ; ++i) {
        for (int j = 0; j <SIZE ; ++j) {
            shrinked_image[i][j] = 255;
            skewed_iamge[i][j] = 255;
        }
    }
    double degree;
    cout<<" Enter the angle  to skew with : ";
    cin>>degree;
    degree=(degree*22)/(180*7);//convert angle from degrees into radian
    int  x= SIZE/(1+tan(degree));

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            shrinked_image[(i * x)/SIZE][j] = image[i][j];//each pixel in the shrinked image is originally x pixels in the main image
        }
    }
    double step =SIZE-x;
    double move=step/SIZE;
    for(int i=0;i<SIZE;++i){
        for(int j=(int)step;j<(step+x);++j){
            skewed_iamge[j][i]=shrinked_image[j-(int)step][i];
        }
        step-=move;
    }
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            image[i][j]=skewed_iamge[i][j];
        }
    }
}
void crop_image(){
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            croped_image[i][j]=255;// croped image is white
        }
    }
    int x,y,l,w;
    cout<<"enter the x and y postion respectively:  ";
    cin>>x>>y;
    cout<<"enter the l and w to keep respectively:  ";
    cin>>l>>w;
    for(int i=x;i<=l;++i){//we start from x dimension till length that we want to keep
        for(int j=y;j<=w;++j){//we start from y dimension till width that we want to keep

               croped_image[i][j]=image[i][j];

        }
    }
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            image[i][j]=croped_image[i][j];
        }
    }
}

int main()
{
  loadImage();
 SHUFFLE_ForImage();
  saveImage();
  return 0;
}
