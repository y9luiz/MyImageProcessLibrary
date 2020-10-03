#ifndef COMMON_TYPES_H_
#define COMMON_TYPES_H_
namespace MIL{
    enum ColorSpaces
    {
        GRAY = 0b0000,
        RGB  = 0b0001
    };
    enum ImageFormats
    {
        PNG = 0b0000,
        PGM = 0b0010
    };
    enum ColorImageFormats
    {
        GRAY_PNG = GRAY | PNG,
        RGB_PNG  = RGB  | PNG,
        GRAY_PGM = GRAY | PGM
    };
};

#endif