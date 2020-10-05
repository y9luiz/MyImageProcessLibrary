#include <io.h>
#include <iostream>
#include <decoder/decoder.h>
#include <cstring>
#include <common/common.h>
using std::cout;
MIL::Img MIL::imread(const char* filename)
{
    std::ifstream file(filename);
    if(!file.is_open())
    { 
        std::string str = "could not open the target file" + std::string(filename);

        std::cout<<(str)<<std::endl;
        exit(-1);
    }
    bool valid_format = false;
    if(MIL::Decoder::isPGM(file))
    {   
        valid_format = true;
        file.close();
        std::ifstream a(filename);
        return MIL::Decoder::Decoder::decodePGM(a);
        a.close();
        
    }

    if(!valid_format)
    {
        std::cout<<"invalid format file " +std::string(filename)<<"\n" ;
        exit(-1);
    }
    std::cout<<"we got an valid format file\n";

}

void MIL::imwrite(MIL::Img  image,const char* filename,MIL::ColorImageFormats code)
{
    std::ofstream file(filename);
    if(!file.is_open())
    {
        std::cout<<"could not create the file"<<filename<<"check your permissions\n";
        exit(-1);
    }
    if(code == MIL::GRAY_PGM || code == MIL::PGM)
    {

        imwrite_ppm(image,file);
    }
    else{
        std::cout<<"invalid code "<<code<<"\n:"<<MIL::PGM;
    }
    file.close();

}
void MIL::imwrite_ppm(MIL::Img & image, std::ofstream & file)
{
    int w = image.getWidth();
    int h = image.getHeight();
    file<<"P2\n";
    file<<"#Criado por Luiz Felipe Maciel Correia\n";
    file<<w<<" "<<h<<"\n";
    file<<255<<"\n";
    //unsigned char  pdata[w*h*1*sizeof(u_char)];
	
    //memcpy(pdata,image.getData(),w*h*1*sizeof(u_char));;

    
    int cont_ =0;
    for(int i=0;i<h*w;i++)
    {
       if(i>0 && i%w==0)
       {
           file<<(int)image.getData()[i]<<"\n";
       }
       else{
           file<<(int)image.getData()[i]<<" ";
       }
        
    }

    
    

}
