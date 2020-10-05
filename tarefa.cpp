#include <iostream>
#include <common/common.h>
#include <imgproc/img_proc.h>
#include <io/io.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

char * filename1;
char * filename2;

void * Normalize(void* obj)
{
    
    MIL::Img  img =  *((MIL::Img *) obj);

    std::cout<<filename1<<"\n";
    MIL::imwrite(MIL::img_proc::Normalize(img),filename1);

}

void * Equalize(void* obj)
{
    MIL::Img  img =  *(MIL::Img *) obj;
    std::cout<<filename2<<"\n";
    MIL::imwrite(MIL::img_proc::ImageEqualization(img),filename2);
}

int main(int argc, char **argv)
{
    if(argc!=4)
    {
        std::cout<<"./test_load_save_image <loaded_image> <normalized_image_name> <equalized_image_name>\n";
        exit(0);
    }

   
    MIL::Img imagem = MIL::imread(argv[1]); 

    filename1=argv[2];
    filename2=argv[3];
    pthread_t t[2];


    pthread_create(&t[0],NULL,Normalize,&(imagem));
    pthread_create(&t[1],NULL,Equalize,&(imagem));

    pthread_join(t[0],NULL);
    pthread_join(t[1],NULL);
        
    return 0;
}
