#include "../include/copy.h"

int Copy (char**argv )
{
    std::string outputpath, inputpath, nameOfFile, line  ;
    outputpath = inputpath = nameOfFile  = line = "" ;
    for(int i = 0 ; argv[1][i] != '\0' ; i++ )
    {
        if(argv[1][i] =='\\' )
        {
            nameOfFile = "" ;
            inputpath+="\\\\" ;
        }
        else
        {
            nameOfFile+=argv[1][i] ;
            inputpath +=argv[1][i] ;
        }
    }
    bool haveName = 0 ;
    for(int i = 0 ; argv[2][i] != '\0' ; i++ )
    {
        if(argv[2][i] == '.')
        {
            haveName = 1 ;
        }
        if(argv[2][i] =='\\' )
        {
            outputpath +="\\\\" ;
        }
        else
        {
            outputpath +=argv[2][i] ;
        }
    }
    if(haveName == 0)
    {
        outputpath += ( "\\\\" + nameOfFile ) ;
    }
    std::ifstream inFile(inputpath) ;
    std::ofstream outFile(outputpath) ;
    if (inFile.is_open())
    {
        while ( getline (inFile,line) )
        {
            outFile << line << '\n';
        }
        inFile.close();
    }
    else
    {
        return 2 ;
    }
    outFile.close() ;
    return 0 ;
}
