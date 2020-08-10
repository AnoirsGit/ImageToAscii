
#include<iostream>
#include<fstream>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;


string setr (int num){
    if (num >=230 ){
        return " ";
    }
    else if (230>num && num >200){
        return ".";
    }
 

    else if (num>= 215 && 200< num ){
        return "^";
    }
    else if (num> 200 && 160<num ){
        return "+";
    }

    else if (num>= 160 && 130< num ){
        return "/";
    }
    else if (num>= 160 && 130< num ){
        return "7";
    }

    else if (num>= 110 && 90< num ){
        return "&";
    }
    else if (num>= 90 && 70< num ){
        return "M";
    }
 
        return "@";

}
// string setrVec(int x){
//     int num = x/28;
//     vector<string> character= {" ", "." , "^","+","/","7","&","M","@" };
//     return character[num];
// }
void makeSomething(int a, function<string(int)> f){
    Mat image;
    image = imread( "C:/Users/flux_/Desktop/cv test/img1.jpeg");
    Mat grey_image;
    cvtColor(image, grey_image ,COLOR_BGR2GRAY);
    Mat outp;
    resize(grey_image,outp, Size(grey_image.cols*0.5, grey_image.rows*0.25), 0, 0);
    ofstream fout("ex2.txt");
    imshow("image",grey_image);

    for( int x = 0 ; x<outp.rows; x++ ){
        for(int y = 0 ;  y<outp.cols; y++){     
            fout<< f((int)outp.at<uchar>(x, y));
            }
        fout<<"\n";
    }
    waitKey();
}

int main(int argc, char** argv) {

    
    function<string(int)> f;
    f=setr;
    makeSomething(1,f );
  
    
    
       
}
