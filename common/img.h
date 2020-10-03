#ifndef COMMON_IMG_H_
#define COMMON_IMG_H_
#include "types.h"

namespace MIL{
    class Img{
            public:
                Img();
                Img(int width, int height, int nchannels);
                Img(int width, int height, int nchannels,unsigned char * data);

                //TODO
                Img(int width,int height, enum ColorImageFormats);
                ~Img();
                inline int getWidth(){return width;};
                inline int getHeight(){return height;};
                inline int getChannels(){return nchannels;};
                inline unsigned char * getData(){return data;};  
                int getMaxValue();
                int getMinValue();  
            private:
                unsigned char * data;
                int nchannels;
                int height;
                int width;
    };
};

#endif