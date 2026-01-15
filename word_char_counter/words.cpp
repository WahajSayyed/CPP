#include <string>
#include <sstream>
#include <cctype>
#include <unordered_map>

std::unordered_map<char, int>
count_char(const std::string& text){
    std::unordered_map<char, int> counts;

    for (char c : text){
        auto cast_c = static_cast<unsigned char>(c);
        if (std::isalnum(cast_c)){
            char lower = std::tolower(cast_c);
            counts[lower]++;
        } 
    }
    return counts;
}

int count_words(const std::string& text){
    std::string cleaned;
    cleaned.reserve(text.size());

    for (char c : text){
        if (std::isalnum(static_cast<unsigned char>(c))){
            cleaned += c;
        } else {
            cleaned += ' ';
        }
    }

    std::istringstream iss(cleaned);

    int count = 0;
    std::string word;
    while (iss >> word){
        ++count;
    }

    return count;
}

