#ifndef COMMON_IMG_H_
#define COMMON_IMG_H_
#include "types.h"
#include <cstring>
#include <iostream>
namespace MIL{
    class Img{
            public:
                Img();
                Img(int width, int height, int nchannels);
                Img(int width, int height, int nchannels,unsigned char * data);
		Img(const Img &img2) {

                	width = img2.width; 
                	height = img2.height; 
			this->data = new unsigned char [width*height*img2.nchannels*sizeof(char)];
			memcpy(this->data,img2.data,width*height*img2.nchannels*sizeof(char));
			              
			this->nchannels = img2.nchannels;
        
            	}   
                //TODO
                Img(int width,int height, enum ColorImageFormats);
                ~Img();
                inline int getWidth(){return width;};
                inline int getHeight(){return height;};
                inline int getChannels(){return nchannels;};
                inline unsigned char * getData(){return data;};  
                int getMaxValue();
                int getMinValue();

		inline Img & operator = (const Img & img){

                	this->width = img.width;
                	this->height = img.height;
                	this->nchannels = img.nchannels;
                	this->data = img.data;
                	return *this;

            	};
            
            private:
                unsigned char * data;
                int nchannels;
                int height;
                int width;
    };
};

#endif
