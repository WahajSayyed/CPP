#include <iostream>
#include "word.h"


int main(){
    std::string text = "Hellow, World! C++ is amazing and very powerful.";
    std::cout << "Word count: " << count_words(text) << std::endl;
    auto result = count_char(text);

    for (const auto& [ch, count] : result){
        std::cout << ch << " : " << count << " | " ;
    }
    std::cout << std::endl;
}