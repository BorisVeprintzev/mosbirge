#include "iostream"
#include "vector"
#include "cstdlib"

int main() {
    std::cout << "Input size of matrix:";
    int size = 0, min = 1000000, sum = 0, ndiang;
    std::cin >> size;
    std::vector<std::vector<int>> mass (size, std::vector<int> (size));
    for (auto i = 0; i < size; ++i) {
        for (auto j = 0; j < size; ++j) {
            std::cin >> mass[i][j];
        }
    }
    for (auto i = 0; i < size; ++i) {
        int help = i;
        for (auto j = 0; j < i+1; ++j) {
            sum += mass[help][j];
            --help;
        }
        if (sum <= min) {
            min = sum;
            ndiang = i;
        }
        sum = 0;
    }
    int num = size;
    bool IsNeedCheck = true;
    for (auto j = 1; j < size; ++j) {
        int help = j;
        --num;
        for (auto i = size - 1; i >= size - num; --i) {
            sum += mass[i][help];
            ++help;
        }
        if (IsNeedCheck) {
            if (sum <= min && ndiang < j) {
            min = sum;
            ndiang = j + size - 1;
            IsNeedCheck = false;
            }
        } else {
            if (sum < min) {
                min = sum;
                ndiang = j + size - 1;
            }
        }
        sum = 0;
    }

    //std::cout << ndiang << " " << min << std::endl; 
    
    if (ndiang < size) {
        size_t j = 0;
        for (auto i = ndiang; i >= 0; i--) {
            std::cout << mass[i][j] << " ";
            ++j;
        }
    } else {
        size_t i = size - 1;
        size_t j = ndiang - size + 1;
        for (auto count = 2*size-1-ndiang; count > 0; count--) {
            std::cout << mass[i][j] << " ";
            --i;
            ++j;
        }

    }
    std::cout << std::endl;
    return 0;
}