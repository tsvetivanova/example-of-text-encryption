
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include<vector>
#include <fstream>
using namespace std;

int c1, c2;
int c3, c4;
double a = -1.4, b = 1.6, c = 1.0, d = 0.7;
double e = -1.7, f = 1.8, g = -1.9, h = -0.4 ;
double x_next, y_next, x = 0.15192,y = 0.10043;
char ox;
double x_next1, y_next1, x1 = 0.9223,y12 = 0.980255;

unsigned char rand1() ///generator
{
        x_next = sin(a*y) + c*cos(a*x);
        y_next = sin(b*x) + d*cos(b*y);


        x_next1 = sin(e*y12) + c*cos(f*x1);
        y_next1 = sin(g*x1) + d*cos(h*y12);


        c1=((int)(abs(x_next*1000000)))%256;

        c2=((int)(abs(y_next*1000000)))%256;

        c3=((int)(abs(x_next1*1000000)))%256;

        c4=((int)(abs(y_next1*1000000)))%256;

      //  cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<" ";
        ox = c1^c2^c3^c4;//^c11^c22^c33^c44;

        //cout<<ox<<" ";
        x = x_next;
        y = y_next;
        x1 = x_next1;
        y12 = y_next1;
        return ox%256;
}

int main()
{
   /// std::ifstream input( "original.txt", std::ios::binary );
    ///std::ofstream output( "encr.txt", std::ios::binary );
    std::ifstream input( "ORGI-WIKIPEDIA.txt", std::ios::binary );
    std::ofstream output( "ENCR.txt", std::ios::binary );
    for (int t = 0; t <= 1280; t++)///razseivamae nachalnoto systoqnie
    {
        rand1();
    }
    cout<<"nachalnoto systoqnie e razseqno"<<endl;

    unsigned char ch;
    // copies all data into buffer
    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});
    for(int i=0;i<buffer.size();i++)
      {
         //cout<<buffer[i]<<" ";
         cout<<(int)buffer[i]<<" ";
         cout<<(int)rand1()<<" ";
         ch = buffer[i]^rand1();
         cout<<ch<<" ";
         output.write((char *)&ch, sizeof(ch));

      }
      cout<<"File is ready"<<endl;
        return 0;
}
