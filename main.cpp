#include <iostream>
#include <ctime>
#include "grid.h"
#include "ab.h"
#include "sidewinder.h"
#include <iostream>
#include "distance.h"


int main()
{

    std::srand(std::time(nullptr));  // this is the random seed
    int size;
    std::cout<<"Enter the size of the maze you would like to create: ";
    std::cin>>size;

    Grid grid(size, size);   
    const int cellsize = 30;
    

int choice = 0;
std::cout<<"Choose one of the following Algorithms to create a Maze:\na)SideWinder Algorithm\nb)Aldous-Broder Algorithm\nEnter a choice: ";
std::cin>>choice;

switch(choice)
{
    case 1: 
        SideWinder::MazeGenerator(&grid);
        break;
    case 2:
        AldousBroder::MazeGenerator(&grid);
        break;
    default:
        std::cout<<"Number should be between 1 and 2 lol";
        return -1;
        break;   
}
std::cout<<grid.toString()<<std::endl;

std::cout<<"To find the solution of this "<<grid.returnRow()<<" x "<<grid.returnColumn()<<" maze enter the starting cell and the ending cell"<<std::endl;
int ro1, col1;
int ro2 , col2;
std::cout<<"Enter the starting cell (row, column): ";
std::cin>>ro1>>col1;
std::cout<<"Now, enter the ending cell: ";
std::cin>>ro2>>col2;

Cell *start = grid.getCell(ro1,col1);
Cell *end = grid.getCell(ro2, col2);

Distance *djiks = start->distances();
grid.setPath(djiks->shortestPathto(end));
std::cout << grid.toString();
delete djiks;
    

return 0;
}

