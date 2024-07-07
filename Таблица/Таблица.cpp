#include <iostream>
#include <windows.h>
#include <vector>

template<typename T>
class Table {
public:
    Table(int rows, int cols)
        : data(rows, std::vector<T>(cols)) {}

    std::vector<T>& operator[](int row) {
        return data[row];
    }

    const std::vector<T>& operator[](int row) const {
        return data[row];
    }

    std::pair<int, int> Size() const {
        return { data.size(), data[0].size() };
    }

private:
    std::vector<std::vector<T>> data;
};

int main() {
    SetConsoleOutputCP(65001);
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;

    auto size = test.Size();
    std::cout << "Строки: " << size.first << ", Столбы: " << size.second << std::endl;

    return 0;
}