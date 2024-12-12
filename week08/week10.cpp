#include <iostream>
#include <vector>

void print(std::vector<int> data)
{
    std::cout<<"{";
    for(std::size_t i =0; i<data.size()-1;i++)
    {
        std::cout<<data[i]<<", ";
    }
    std::cout<<data.back()<<"}"<<std::endl;
}

void print_mat (std::vector<std::vector<int>> mat)
{

    for(std::size_t y =0;y<mat.size();y++)
    {
        std::cout<<"{";
        for(std::size_t x =0;x<mat[y].size() -1; x++)
        {
            std::cout<<mat[y][x];
            std::cout<<", ";
        }
        std::cout<<mat[y].back()<<"},"<<std::endl;
    }
}

std::vector<int> sum(std::vector<std::vector<int>> vec) {
    // {{0, 1}, {2}, {}} -> {1, 2, 0}
    std::vector<int> vysledek = {};
    for(std::size_t y =0;y<vec.size();y++)
    {   
        int sum =0;
        for(int x  : vec[y])
        {
            sum +=x;
        }
        vysledek.push_back(sum);
    }
    print(vysledek);
    return vysledek;
}

std::vector<int> product(std::vector<std::vector<int>> vec) {
    // {{0, 1}, {2}, {}} -> {0, 2, 1}
    std::vector<int> vysledek = {};
    for(std::size_t y =0;y<vec.size();y++)
    {   
        int sum =1;
        for(int x  : vec[y])
        {
            sum *=x;
        }
        vysledek.push_back(sum);
    }
    print(vysledek);
    return vysledek;
}

std::vector<int> concat(std::vector<std::vector<int>> vec) {
    // {{0, 1}, {2}, {}} -> {0, 2, 1}
    std::vector<int> vysledek = {};
    for(std::size_t y =0;y<vec.size();y++)
    {   

        for(int x  : vec[y])
        {
            vysledek.push_back(x);
        }

    }
    print(vysledek);
    return vysledek;
}

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> vec) {
    // {
    //   {0, 1, 2},
    //   {3, 4, 5},
    //   {6, 7, 8},
    // } -> {
    //   {0, 3, 6},
    //   {1, 4, 7},
    //   {2, 5, 8},
    // }
    std::vector<std::vector<int>> vysledek = {};
    vysledek.resize(vec[0].size());
    for(std::size_t y =0;y<vec.size();y++)
    {
        for(std::size_t x =0;x<vec[y].size(); x++)
        {
            vysledek[x].push_back(vec[y][x]);
        }
    }
    print_mat(vysledek);
    return vysledek;
}
std::vector<std::vector<int>> cartesian_product(
    std::vector<int> a,
    std::vector<int> b) {
    std::vector<std::vector<int>> vysledek;
    // {0, 1} {2, 4} -> {{0, 2}, {0, 4}, {1, 2}, {1, 4}}
    // a1,b1 a1,b2 a2,b1 a2,b2
    // {0, 1} {} -> {} 
    for(int y :a)
    {
        for(int x :b)
        {
            vysledek.push_back({y,x});

        }

    }
    print_mat(vysledek);
    return vysledek;
}
//!#################################################################
int main(){
    std::vector<std::vector<int>> a = {{0,1,2},{3,4,5},{6,7,8}};
    std::vector<int> A = {0, 1};
    std::vector<int> B = {2, 4};
    //print_mat(a);
    cartesian_product(A,B);
}