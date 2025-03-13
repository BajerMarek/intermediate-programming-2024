#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>

struct Board {
    std::vector<bool> cells;
    std::size_t width;
    std::size_t height;
};

void print_board(const Board& board) {
    for(int i =0; i < board.width * board.height;i++)
    {
        if(i == 45)
        {
            std::cout<<"🟥";
        }
        else if(board.cells[i])
        {
            std::cout<<"⬜";
        }
        else{
            std::cout<<"⬛";
        }
        if((i%board.width)==0)
        {
            std::cout<<" "<<std::endl;
        }
    }
}
int stav_na_souradnici(const Board& board, std::size_t x, std::size_t y)
{
    if(board.cells[x+y*10]) return true;
    else return false;
}
int neighbour_count_s_vizualem(const Board& board, std::size_t x, std::size_t y) {
    std::cout<<" "<<std::endl;
    int sum =0;
    int souradnice = (x-1)+(y*10)-10-1;
    for(int i =1; i<10;i++)
    {
        souradnice++;
        if (souradnice == (x+y*10)) //continue
        {

            std::cout<<"X | ";
            continue;
        }
        
        if((i%3)==0)
        {
            if(board.cells[souradnice])sum++;
            std::cout<<board.cells[souradnice]<<" | ";
            souradnice +=7;
            std::cout<<" "<<std::endl;
            continue;
        }
        if(board.cells[souradnice])sum++;
        std::cout<<board.cells[souradnice]<<" | ";
        //std::cout<<souradnice<<" | ";
    }
    std::cout<<" "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"suma je : "<<sum<<std::endl;
    return sum;
}
int main()
{
    Board board;
    board.height = 10;
    board.width = 10;
    board.cells ={
        true, false, true, true, false, false, true, false, true, true,
        false, true, false, false, true, false, true, true, false, false,
        true, false, true, false, true, true, false, true, false, true,
        false, false, true, false, true, true, false, true, false, false,
        true, false, true, false, true, true, false, true, true, false,
        false, true, false, true, true, false, true, false, false, true,
        false, true, false, true, true, false, true, false, true, false,
        false, true, false, true, true, false, true, true, false, false,
        true, false, true, false, true, true, false, true, false, true,
        false, false, true, false, true, true, false, true, true, false
    };
    print_board(board);
    neighbour_count_s_vizualem(board,6,4);
}