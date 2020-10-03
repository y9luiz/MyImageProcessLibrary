#ifndef DECODER_H_
#define DECODER_H_
#include <fstream>
#include <common/img.h>
namespace MIL{
    class Decoder{
        public:
            Decoder();
            static bool isPGM(std::ifstream  &file);
            static Img decodePGM(std::ifstream  &file);
        private:

    };

}


#endif