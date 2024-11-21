#include <iostream>
#include <vector>

void print(std::vector<int> a)
{

    std::cout<<"[";
    for(std::size_t i = 0; i<a.size();i++)
    {
        if (i==(a.size()-1))
        {
            std::cout<<a[i];
            continue;
        }
        else{
            std::cout<<a[i]<<", ";
        }
    }
    std::cout<<"]"<<std::endl;

}

std::vector<int> num = {1,2,3,4};
int main()
{
    print(num);
}