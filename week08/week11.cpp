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
std::vector<int> get(std::vector<int>vec1,std::vector<int>vec2)
{
    int size1 = vec1.size();
    int size2 = vec2.size();
    std::vector<int> vysledek={};

    if(size1>size2)
    {
        vec2.resize(size1,0);
    }
    else
    {
        vec1.resize(size2,0);
    }
    for(int i=0;i<vec1.size();i++)
    {
        vysledek.push_back(vec1[i]+vec2[i]);
    }
    return vysledek;
}
std::vector<std::vector<int>> pridej(std::vector<std::vector<int>>data_1,std::vector<std::vector<int>>data_2)
{
    std::vector<std::vector<int>>vysledek = {{}};
    int size1 = data_1.size();
    int size2 = data_2.size();

    if(size1>size2)
    {
        data_2.resize(size1);
    }
    else
    {
        data_1.resize(size2);
    }
    vysledek.resize(size2);
    std::cout<<vysledek.size()<<std::endl;
    for(int i = 0;i < data_1.size();i++)
    {
       vysledek[i] = get(data_1[i],data_2[i]);
       //print(get(data_1[i],data_2[i]));
    }
    return vysledek;
}
std::vector<std::vector<int>> split(std::vector<int>data,int group_size)
{
    std::vector<std::vector<int>>vysledek = {{}};
    vysledek.resize(data.size()/group_size);
    if(data.size()%group_size >0)
    {
        std::cout<<"vector can not be divided with tis number"<<std::endl;
        return vysledek ={{0}};
    }
    //print_mat(vysledek);
    int last =0;
    for(int i = 0; i<data.size()/group_size;i++)
    {
        for(int y = last; y<group_size+last;y++)
        {
            //std::cout<<data[y]<<std::endl;
            vysledek[i].push_back(data[y]);
        }
        //print(vysledek[i]);
        //std::cout<<"-------------------"<<std::endl;
        last += group_size;
    }
    return vysledek;
}
// aby se sečetly se stejným místě čísla -> 1 +1 a 5+2 a 4+5 a 6+9
int main(){
    std::vector<std::vector<int>> data_2 = {{1,2,3,4},
                                            {5,6,7},
                                            {8,9}};

    std::vector<std::vector<int>> data_1 = {{1,5},
                                            {4,6}};
    std::vector<int> data_3 = {1,2,3,4,5,6};
    std::vector<std::vector<int>> vysledek = pridej(data_1,data_2);
    //print(vysledek[0]);
    //print_mat(vysledek);
    print_mat(split(data_3,4));    
    //print(get(data_2[0],data_1[0]));
    //print(data_1[0]);

    return 0;
            
}