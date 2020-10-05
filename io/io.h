#ifndef IO_H_
#define IO_H_
#include <common/common.h>
#include <fstream>
#include <cstdlib>

namespace MIL{
    MIL::Img imread(const char* filename);
    void imwrite(MIL::Img  image,const char * filename,ColorImageFormats code=GRAY_PGM);
    void imwrite_ppm(Img &image, std::ofstream & file);
};

#endif
