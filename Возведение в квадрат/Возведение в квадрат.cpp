#include <iostream>
#include <vector>
#include <sstream>
#include <windows.h>
#include <type_traits>

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
square(const T& value) {
    return value * value;
}

template<typename T>
std::vector<T> square(const std::vector<T>& vec) {
    std::vector<T> result;
    result.reserve(vec.size());
    for (const auto& elem : vec) {
        result.push_back(square(elem));
    }
    return result;
}

template<typename T>
void processInput(T input) {
    T result = square(input);
    std::cout << "[OUT]: " << result << std::endl;
}

template<typename T>
void processInput(const std::vector<T>& input) {
    std::vector<T> result = square(input);
    std::cout << "[OUT]: ";
    for (size_t i = 0; i < result.size(); ++i) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << result[i];
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleOutputCP(65001);
    std::string line;

    while (true) {
        std::cout << "[IN]: ";
        std::getline(std::cin, line);

        if (line == "0") {
            break;
        }

        std::stringstream ss(line);
        std::vector<int> vec;
        int number;
        bool isNumber = true;

        if (ss >> number && ss.eof()) {
            processInput(number);
        }
        else {
            ss.clear();
            ss.str(line);
            int value;
            while (ss >> value) {
                vec.push_back(value);
                if (ss.peek() == ',') {
                    ss.ignore();
                }
            }
            processInput(vec);
        }
    }

    return 0;
}