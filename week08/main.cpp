#include <iostream>
#include <vector>

void print(std::vector<int> data) {
    if (data.size() == 0) {
        std::cout << "[]";
        return;
    }

    std::cout << "[ ";
    for (std::size_t i = 0; i < data.size() - 1; i++) {
        std::cout << data[i] << ", ";
    }

    std::cout << data.back() << " ]";
}

int sum(std::vector<int> data) {
    int sum =0;
    int velikost = data.size(); 
    for(int i=0;i<velikost;i++)
    {
        sum += data[i];
    }
    return sum;
}

float average(std::vector<int> data) {
    double suma = sum(data);
    return suma/data.size();
}

float median(std::vector<int> data) {
    if (data.size()%2)
    {
        int value_1 = (data.size()/2);
        return data[value_1];
    }
    else
    {
        int value_1 = data.size()/2;
        int value_2 = (data.size()/2)-1;
        return (data[value_1]+data[value_2])/2.0;
    }

}

std::vector<int> range(int start, int end) {
    std::vector<int> vysledek ={};
    if (start<end)
    {
        for(int i =start; i<end;i++)
        {
            vysledek.push_back(i);
        }
        return vysledek;
    }
    if (start>end)
    {
        for(int i =start; i>end;i--)
        {
            vysledek.push_back(i);
        }
        return vysledek;
    }
    return{};

}

std::vector<int> runningSum(std::vector<int> data) {
    std::vector<int> hodnota ={};
    int sum =0;
    int velikost = data.size();
    for(int i = 0; i<velikost;i++)
    {
        sum +=data[i];
        hodnota.push_back(sum);
    }
    return hodnota; 
}

std::vector<int> rotateRight(std::vector<int> data, int count) {
    std::vector<int> pomocnik ={};
    //pomocnik.resize(data.size()+count);
    int velikost = data.size();
    int idx =0;
    for(int i = 0; i < velikost; i++)
    {
        idx = (i+count) % velikost;
        pomocnik.push_back(data[idx]);
    }
    return pomocnik;
}

int main() {
    std::vector<int> vec1 = { 1, 9, 4, 8, 4, 0, 9, 2, 3, 5, 6 };
    std::vector<int> asc1 = { 0, 2, 4, 7, 8 };
    std::vector<int> asc2 = { 1, 3, 5, 6, 7, 9 };
    print(asc1);
    std::cout<<" "<<std::endl;
    print(rotateRight(asc1,2));
/*
    std::cout << "sum(vec1): " << sum(vec1) << std::endl;
    std::cout << "average(vec1): " << average(vec1) << std::endl;
    std::cout << "median(asc1): " << median(asc2) << std::endl;

    std::cout << "range(5, 10): ";
    print(range(5, 10));
    std::cout << std::endl;
    
    std::cout << "range(11, 4): ";
    print(range(11, 4));
    std::cout << std::endl;

    std::cout << "runningSum(vec1): ";
    print(runningSum(vec1));
    std::cout << std::endl;*/
}
