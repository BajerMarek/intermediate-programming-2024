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
        if(board.cells[i])
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
int neighbour_count(const Board& board, std::size_t x, std::size_t y) {
    int sum =0;
    int souradnice = (x-1)+(y*10)-10-1;
    for(int i =1; i<10;i++)
    {
        souradnice++;
        if (souradnice == (x+y*10))continue;
        if((i%3)==0)
        {
            if(board.cells[souradnice])sum++;
            souradnice +=7;
            continue;
        }
        if(board.cells[souradnice])sum++;
    }
    return sum;
}

//! vyřeš
Board game_step(const Board& board) {
    Board Board = board;
    for(int y =0; y<board.height;y++)
    {
        for(int x =0; x<board.width;x++)
        {
            if(neighbour_count(board,x,y)>3)
            {
                Board.cells[x+y*board.width] = false;
            }
            if(neighbour_count(board,x,y)<2)
            {
                Board.cells[x+y*board.width] = false;
            }
        }
    }
    return Board;
}
//! nezajíma mě
void clear_screen() {
    std::cout << "\033[2J\033[1;1H";
}

Board parse_board(const std::string& path);
Board default_board();

int main(int argc, const char** argv) {
    using namespace std::chrono_literals;
    Board board;
    if (argc > 1) {
        board = parse_board(argv[1]);
    } else {
        board = default_board();
    }

    while (true) {
        board = game_step(board);
        clear_screen();
        print_board(board);
        std::this_thread::sleep_for(50ms);
    }
    
    return 0;
}

Board parse_board(const std::string& path) {
    Board board;
    // If a filename is provided, load board from file.
    std::ifstream infile(path);
    if (!infile) {
        std::cerr << "Error: Cannot open file " << path << std::endl;
        abort();
    }
    
    // Read board dimensions from the first two lines.
    infile >> board.width >> board.height;
    // Discard the rest of the line after reading numbers.
    std::string line;
    std::getline(infile, line);
    
    // Skip potential empty lines before board pattern.
    while (std::getline(infile, line) && line.empty()) {
        // continue skipping
    }
    
    // Allocate board cells (initialize to dead).
    board.cells.assign(board.width * board.height, false);
    
    // Process the first non-empty board line that was already read.
    std::size_t row = 0;
    if (!line.empty() && row < board.height) {
        for (std::size_t col = 0; col < line.size() && col < board.width; ++col) {
            if (line[col] == '#')
                board.cells[row * board.width + col] = true;
        }
        ++row;
    }
    
    // Continue reading remaining lines.
    while (row < board.height && std::getline(infile, line)) {
        if (line.empty())
            continue;
        for (std::size_t col = 0; col < line.size() && col < board.width; ++col) {
            if (line[col] == '#')
                board.cells[row * board.width + col] = true;
        }
        ++row;
    }
    return board;
}

Board default_board() {
    Board board;
    board.width = 200;
    board.height = 54;
    board.cells.assign(board.width * board.height, false);
    
    // Default board pattern as provided.
    std::vector<std::string> defaultPattern = {
        "                                      #",
        "                                    # #",
        "                          ##      ##            ##",
        "                         #   #    ##            ##",
        "              ##        #     #   ##",
        "              ##        #   # ##    # #",
        "                        #     #       #",
        "                         #   #    ",
        "                          ##      "
    };
    
    // Place the default pattern into the top rows of the board.
    for (std::size_t row = 0; row < defaultPattern.size() && row < board.height; ++row) {
        const std::string &line = defaultPattern[row];
        for (std::size_t col = 0; col < line.size() && col < board.width; ++col) {
            if (line[col] == '#')
                board.cells[row * board.width + col] = true;
        }
    }

    return board;
}
