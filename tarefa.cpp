#include <iostream>
#include <common/common.h>
#include <imgproc/img_proc.h>
#include <io/io.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

void * Normalize(void* obj)
{
    
    MIL::Img  img =  *((MIL::Img *) obj);


    MIL::imwrite(MIL::img_proc::Normalize(img),"imagem_normalizada.pgm");

}

void * Equalize(void* obj)
{
    MIL::Img  img =  *(MIL::Img *) obj;
    MIL::imwrite(MIL::img_proc::ImageEqualization(img),"imagem_equalizada.pgm");
}

int main(int argc, char **argv)
{
    if(argc!=3)
    {
        std::cout<<"./test_load_save_image <loaded_image> <writed_image>\n";
        exit(0);
    }

   
    MIL::Img imagem = MIL::imread(argv[1]); 

    
    pthread_t t[2];


    pthread_create(&t[0],NULL,Normalize,&(imagem));
    pthread_create(&t[1],NULL,Equalize,&(imagem));

    pthread_join(t[0],NULL);
    pthread_join(t[1],NULL);
        
    return 0;
}
