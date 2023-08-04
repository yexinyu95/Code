#include <iostream>
#include <vector>

int main() {
    std::string num;
    std::cin >> num;

    std::vector<char> dup;
    int step = 0;
    int tempnum = 0;
    for (int i = num.length(); i > 0; --i) {
        tempnum = (int)(num[i] - 48);

        if (tempnum * 2 > 10) {
            step = 1;
            if (step) {
                char tempchar = (char) (tempnum * 2 - 10 + 1);
                dup.push_back(tempchar);
            } else {
                char tempchar = (char) (tempnum * 2 - 10);
                dup.push_back(tempchar);
            }
        }
        else{
            step = 0;
            if (step){
                char tempchar = (char)(tempnum * 2 + 1);
                dup.push_back(tempchar);
            }
            else{
                char tempchar = (char)(tempnum * 2);
                dup.push_back(tempchar);
            }
        }
    }

    std::cout << num << std::endl;
    return 0;
}
