#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <windows.h>

using namespace std;

class Minesweeper
{
private:
    int rows;
    int columns;
    int max_size;
    int bomb_count;
    vector<vector<int>> table; //main table of the game
    vector<int> bombs; //the vector that contains bombs' locations
    
    int find_column(int);
    int find_row(int,int);
    
    void create_table();
    void add_bombs();
    void add_numbers();
    
    void show_table();
    
public:
    Minesweeper(int columns_get=9, int rows_get=9, int bomb_count_get=10);
    ~Minesweeper();

};

