#include <fstream>
#include <cctype>
#include <cmath>
#include "docDistance.h"


FileReader::FileReader(std::string_view filePath)
{
    const auto words = readFile(filePath);
    mCountwords = words.size();
    mWordFreq = countWordFreq(words);
}

int FileReader::getTotalWords()
{
    return mCountwords;
}

int FileReader::getUniqueWords()
{
    return mWordFreq.size();
}


const std::string& FileReader::name()
{
    return mName;
}

const WordVector& FileReader::getWordFrequency()
{
    return mWordFreq;
}

std::vector<std::string> FileReader::readFile(std::string_view filePath)
{
    std::vector<std::string> words;
    std::ifstream file(std::string{filePath});

    mName = filePath;

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


WordVector FileReader::countWordFreq(const std::vector<std::string>& words)
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



int innnerProduct(const WordVector& wordVectA, const WordVector& wordVectB)
{
    int dotProduct = 0; 
    for(const auto& [word, count] : wordVectA)
    {
        if(wordVectB.find(word)!= wordVectB.end())
        {
            dotProduct += wordVectA.at(word) * wordVectB.at(word);
        }
    }
    return dotProduct;
}

double norm(const WordVector& D)
{
    return std::sqrt((double)innnerProduct(D, D));
}

double angle(const WordVector& A, const WordVector B)
{
    return  std::acos( innnerProduct(A, B)  / ( norm(A) * norm(B) ) );
}