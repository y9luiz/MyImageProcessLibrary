#include <iostream>
#include <common.h>
#include <io.h>
#include <img_proc.h>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv)
{
    if(argc!=3)
    {
        std::cout<<"./test_load_save_image <loaded_image> <writed_image>\n";
        exit(0);
    }
    MIL::Img imagem = MIL::imread(argv[1]);
    MIL::Img normalized_img = MIL::img_proc::Normalize(imagem);
    MIL::imwrite(normalized_img,argv[2]);
    MIL::imwrite(MIL::img_proc::ImageEqualization(imagem),argv[2]);
    return 0;
}
