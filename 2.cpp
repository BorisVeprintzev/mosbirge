#include "iostream"
#include "vector"
#include "cstdlib"


int main(){
    std::vector<int> ans(1001, 0);
    std::cout << "Input count of numbers:";
    int count, max_count = 0, tmp;
    std::cin >> count;
    for (auto i = 0; i < count; i++) {
        std::cin >> tmp;
        ++ans[tmp];
        if (ans[tmp] >= max_count) {
            max_count = tmp;
        }
    }
    
    std::cout << max_count << std::endl;
    return 0;
}