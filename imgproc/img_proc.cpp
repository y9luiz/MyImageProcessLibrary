#include "img_proc.h"
#include <iostream>
#include <cstring>
#include <math.h> 
#ifndef uchar
#define u_char unsigned char
#endif
MIL::Img MIL::img_proc::Normalize(MIL::Img &input){
    u_char max = input.getMaxValue();
    u_char min = input.getMinValue();
    int w= input.getWidth();
    int h = input.getHeight();
    
    u_char * pdata = input.getData();
    u_char pdata2  [w*h*1]; 
    
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            pdata2[i*h+j] = 255/(max-min) * (pdata[i*h+j] - min);
        }
    }

    memcpy(pdata,pdata2,w*h*input.getChannels());
    MIL::Img output(w,h,1,pdata);
    return output;
}

MIL::Img MIL::img_proc::ImageEqualization(MIL::Img input)
{
    unsigned int H[256]={};
    int w=input.getWidth();
    int h=input.getHeight();

    for(int i=0;i<w*h;i++)
    {
        H[input.getData()[i]]++;
        
    }
    float P[256] ={};
    for(int i=0;i<255;i++)
    {
        P[i] = H[i]/float(w*h);
    }
    float P_A[256] = {};
    for(int i=0;i<255;i++)
    {
        float cont =0;
        for(int j=0;j<i;j++)
        {
            cont += P[j];
        }
        P_A[i] = cont;

    }
    u_char   data[w*h*input.getChannels()*sizeof(char)];
    
    for(int i=0;i<h*w;i++)
    {
        

            data[i] = round(255*P_A[input.getData()[i]]);
        

    }
    return MIL::Img(w,h,input.getChannels(),data);

}
