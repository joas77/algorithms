#include "docDistance.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    const int minimalArgs = 1;
    if(argc - 1 < minimalArgs)
    {
        println("TODO: print usage...");
        return -1;
    }
    std::string document1{argv[1]};
    
    println("reading...");
    println(document1);

    auto DVect1 = countWordFreq(readFile(document1));
    printDict(DVect1);
    return 0;
}
