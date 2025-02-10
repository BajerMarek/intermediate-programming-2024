#include <iostream>
#include <string>
#include <vector>

int sum(int a, int b) {
    return a+b;
}

std::string sum(std::string a, std::string b) {
    for(int i = 0; i<a.size();i++)
    {
        if(a[i]==',')
        {
            a = a.substr(0,i);
            a.push_back(' ');
        }
    }
    b.pop_back();
    //std::cout<<a<<std::endl;
    return a+b;
}

int sum(std::vector<int> xs) {
    int save =0;
    for(int i :xs)
    {
        save +=i;
    }
    return save;
}

std::string sum(std::vector<std::string> xs) {
    std::string out;
    for(std::string i : xs)
    {
        out +=i;
    }
    return out;
}

int mul(int a, int b) {
    return a*b;
}

std::string mul(int a, std::string b) {
    std::string out;
    for(int i = 0;i<a;i++)
    {
        out +=b; 
    }
    return out;
}

int main() {
    std::cout << "sum(3, 4): " << sum(3, 4) << "\n"; // 7
    std::cout << R"(sum("Hello, ", "World!"): )" << sum("Hello, ", "World!") << "\n"; // Hello World
    std::cout << "sum({1, 2, 3, 4, 5}): " << sum(std::vector<int>{1, 2, 3, 4, 5}) << "\n"; // 15
    std::cout << R"(sum({"abc", "def", "ghi"}): )" << sum(std::vector<std::string>{"abc", "def", "ghi"}) << "\n"; // abcdefghi

    std::cout << "mul(3, 5): " << mul(3, 5) << "\n"; // 15
    std::cout << R"(mul(3, "Hi"): )" << mul(3, "Hi") << "\n"; // HiHiHi

    return 0;
}

