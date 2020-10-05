#ifndef IMAGE_PROC_H
#define IMAGE_PROC_H
#include <common/common.h>
namespace MIL{
    namespace img_proc{
        MIL::Img Normalize(MIL::Img & input);
        MIL::Img ImageEqualization(MIL::Img input);
    }

};

#endif
