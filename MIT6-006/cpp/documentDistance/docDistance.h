#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <unordered_map>

using WordVector = std::unordered_map<std::string, int>

class FileReader
{
public:
    FileReader(std::string_view filePath);
    int getTotalWords();
    int getUniqueWords();
    const std::string&  name();
    const std::unordered_map<std::string, int>& getWordFrequency();

private:
    int mCountwords = 0;
    int mCountUniquewords = 0;
    std::string mName;
    std::unordered_map<std::string, int> mWordFreq;

    std::vector<std::string> readFile(std::string_view filePath);
    std::unordered_map<std::string, int> countWordFreq(const std::vector<std::string>& words);
};

int innnerProduct(const WordVector& wordVectA, const WordVector& wordVectB);
double norm(const WordVector& D);
double angle(const WordVector& A, const WordVector B);
