#include "docDistance.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    const int minimalArgs = 2;
    if(argc - 1 < minimalArgs)
    {
        println("USAGE: docDistace documen1 document2");
        return -1;
    }
    std::string document1{argv[1]};
    std::string document2{argv[2]};

    auto docInfo1{FileReader(document1)};
    std::cout   << "File "      << docInfo1.name()   << " : "   <<  docInfo1.getTotalWords()   
                << " words, "   <<  docInfo1.getUniqueWords()   << " distinct words " 
                << std::endl;


    auto docInfo2{FileReader(document2)};
    std::cout   << "File "      << docInfo2.name()   << " : "  <<  docInfo2.getTotalWords()   
                << " words, "   <<  docInfo2.getUniqueWords()  << " distinct words " 
                << std::endl;

    auto docVector1 = docInfo1.getWordFrequency();
    auto docVector2 = docInfo2.getWordFrequency();

    return 0;
}
