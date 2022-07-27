#include <fstream>
#include <cctype>
#include "docDistance.h"

std::vector<std::string> readFile(std::string_view filePath)
{
    std::vector<std::string> words;
    std::ifstream file(std::string{filePath});

    std::string word;
    while(file)
    {
        char c = file.get();
        if(!std::isalpha(c))
        {
            if(word != "")
                words.push_back(word);

            word = "";
        }
        else
        {
            word += std::tolower(c);
        }
    }

    return words;
}

std::unordered_map<std::string, int> countWordFreq(const std::vector<std::string>& words)
{
    std::unordered_map<std::string, int> wordVector;
    for(const auto& w: words)
    {
        if(wordVector.find(w) != wordVector.end())
        {
            wordVector[w]+=1;
        }
        else
        {
            wordVector[w] = 1;
        }
    }

    return wordVector;
}
