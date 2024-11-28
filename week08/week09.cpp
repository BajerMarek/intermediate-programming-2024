#include <iostream>
#include <vector>
/*
//! napis filter tak aby se v novém poly vyskytoval hodnoty pouze vetsi jak mez
std::vector<int> filter_large(std::vector<int> original, int mez){
    std::vector<int> vysledek ={};
    for(int i =0; i<original.size();i++)
    {
        if(original[i]>mez)
        {
            vysledek.push_back(original[i]);
        }
    }
    return vysledek;
}
*/
//! urči zdayl je pole palindrom -> cte se z obou stran stejně
bool palindrom(std::vector<int> original){
    std::vector<int> vysledek ={};
    int velikost = original.size();
    for(int i =0;i<velikost ;i++)
    {
        if(original[i]!=original[(velikost-1)-i])
        {

            std::cout<<"original[velikost-i]: "<<original[(velikost-1)-i]<<std::endl;
            std::cout<<"original[i]: "<<original[i]<<std::endl;            
            
            return false;
        }
        
    }
    return true;
}
int main()
{
    std::cout<<palindrom({})<<std::endl;
}