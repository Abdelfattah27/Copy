#include <fstream>
#include "copy.cpp"
int main(int argc, char**argv)
{
    if(argc < 3)
    {
        return 1 ;
    }
    return Copy(argv) ;

}
