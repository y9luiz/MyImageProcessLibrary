#include "img.h"
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
MIL::Img::Img()
{
    data = NULL;
    nchannels =0;
    width=0;
    height =0;
}
MIL::Img::Img(int width, int height, int nchannels)
{

    this->nchannels = nchannels;
    this->width = width;
    this->height = height;
    data = new unsigned char [width*height*nchannels*sizeof(int)];

}

MIL::Img::Img(int width, int height, int nchannels, unsigned char * data_)
{
    this->nchannels = nchannels;
    this->width = width;
    this->height = height;
    this->data = new unsigned char [width*height*nchannels*sizeof(unsigned char)];

    memcpy(this->data,data_,width*height*nchannels*sizeof(unsigned char));
}


int MIL::Img::getMaxValue()
{
    int w = getWidth();
    int h = getHeight();
    u_char max = 0;
    u_char *pdata = this->getData();
    for(int i=0;i<w*h;i++)
    {
        if(pdata[i]>max)
        {
            max = pdata[i];
        }
        if(max==255)
        {
            break;
        }
    }
    return max;
       
}

int MIL::Img::getMinValue()
{
    int w = getWidth();
    int h = getHeight();
    int min = 255;
    u_char *pdata = this->getData();
    for(int i=0;i<w*h;i++)
    {
        if(pdata[i]<min)
        {
            min = pdata[i];
        }
        if(min==0)
        {
            break;
        }
    }
    return min;   
}
MIL::Img::~Img()
{
    if(data!=NULL)
    {
        delete [] data;
    }
}
