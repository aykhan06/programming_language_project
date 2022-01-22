#include <iostream>
#include <string>
#include <sstream>
#include "values.h"

namespace Values {
    Number::Number(long long int value) {
        this->value = value;
    
    }

    Number::operator std::string const() {
    				std::stringstream ss;
    				ss<<value;
        return ss.str();
    }
/*
###################################################################
*/
    String::String(std::string value_) {
        this->value_ = value_;
    }


    String::operator std::string const() {
    			return value_;
    }

/*
###################################################################
*/

    void print_str(String& str) {
        std::cout << static_cast<std::string>(str) << "\n";
    }

    void print_number(Number& str) {
        std::cout << static_cast<std::string>(str) << "\n";
    }
}
