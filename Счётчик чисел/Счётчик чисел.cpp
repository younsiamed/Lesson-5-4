#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class DivisibleByThree {
public:
    DivisibleByThree() : sum(0), count(0) {}

    void operator()(int number) {
        if (number % 3 == 0) {
            sum += number;
            count++;
        }
    }

    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }

private:
    int sum;
    int count;
};

int main() {
    std::string input_line;
    std::cout << "[IN]: ";
    std::getline(std::cin, input_line);

    std::istringstream iss(input_line);
    std::vector<int> numbers;
    int number;
    while (iss >> number) {
        numbers.push_back(number);
    }

    DivisibleByThree functor;
    std::for_each(numbers.begin(), numbers.end(), std::ref(functor));

    std::cout << "[OUT]: get_sum() = " << functor.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << functor.get_count() << std::endl;

    return 0;
}