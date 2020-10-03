#include <decoder.h>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
MIL::Decoder::Decoder()
{
        
}
bool isDecimalNumber(std::string data)
{
    char *p;
    std::strtol(data.c_str(), &p, 10);
    return *p == 0;
}

bool MIL::Decoder::isPGM(std::ifstream& file)
{   
    std::string data;
    //for default the header of PGM image has 4 values
    //all theses datas are
    int cont =0; 
    while(cont<4)
    {
        file>>data;
        //the first value of the header of an PGM image has 2 possible values P2 or P5
        if(cont == 0 && data.compare("P2")!=0 && data.compare("P5")!=0){
            return false;
        }
        //ignore comments
        if(data.find("#")==0)
        {
            char buffer[1024];
            file.getline(buffer,1024*sizeof(char));
            continue;
        }
        else if(cont>0 && !isDecimalNumber(data))
        {
            return false;
        }
        cont ++;
    }
    file.clear();
    file.seekg(0);
    return true;
}
//i'm not using this
int extractDigit(int & decimal_number)
{
    decimal_number/=10;
    return decimal_number%10;
}

MIL::Img MIL::Decoder::decodePGM(std::ifstream  &file)
{
    std::string data;
     //for default the header of PGM image has 4 values
    //all theses datas are
    int cont =-1;
    MIL::Img image;
    int height=-1;
    int width=-1;
    while(cont<3)
    {
        file>>data;
        cont++;
        if(cont==0)
        {
            continue;
        }
         //ignore comments
        if(data.find("#")==0)
        {
            char buffer[1024];
            file.getline(buffer,1024*sizeof(char));
            cont--;
            continue;
        }
        if(cont == 1)
        {
            width = atoi(data.c_str());
            
        }
        else if(cont == 2)
        {
            height = atoi(data.c_str());
        }
    }
    //because we are deal with PGM images we dont need to worry about number of channels   
    //pdata = (unsigned char*)  malloc(width*height*sizeof(int));
    unsigned char pdata[width*height*1*sizeof(unsigned char)];
    int n=0;    
    int cont_linhas =0;
    std::string line;
    /*while(getline(file,line))
    {
        if(cont_linhas==0)
        {
            line = "\n"+line;
        }
        memcpy(pdata+n,line.c_str(),line.size());
        cont_linhas++;
        n+=line.size();
        //line.clear();
    }*/
    int i =0;
    while(!file.eof())
    {
        file>>data;
        pdata[i] = atoi(data.c_str());
        i++;
    }
    file.close();
    Img img(width,height,1,pdata) ;
    
    return img;
}
