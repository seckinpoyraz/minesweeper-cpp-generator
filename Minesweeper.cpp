#include "Minesweeper.hpp"

Minesweeper::Minesweeper(int columns_get, int rows_get, int bomb_count_get):
    rows{rows_get}, columns{columns_get}, max_size{rows*columns}, bomb_count{bomb_count_get}
{
    create_table(); // create table;
    add_bombs(); // add bombs;
    add_numbers(); // add numbers;
    show_table(); // show table;
}

Minesweeper::~Minesweeper()
{
   
}

void Minesweeper::create_table(){
    table.resize(rows,vector<int>(columns, 0)); // we resized the table
}

void Minesweeper::add_bombs(){
        
    for(int i{1}; i<=max_size; ++i){
        bombs.push_back(i);
    }
    
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle(bombs.begin(), bombs.end(), default_random_engine(seed));
    
    bombs.reserve(bomb_count);
    bombs.resize(bomb_count); // ilk bomba sayısı kadarki kareyi al
    
}

int Minesweeper::find_column(int a){
    int column_of_it{0};
    if(a%columns==0){
        column_of_it = columns;
    }else{
        column_of_it = a % columns;
    }
    return column_of_it;
}

int Minesweeper::find_row(int a, int column){
    int row_of_it { ((a-column)/columns)+1 };
    return row_of_it;
}

void Minesweeper::add_numbers(){
    // add numbers
    int column_of_the_bomba{};
    int row_of_the_bomba{};
    int column_of_the_bomb{}; //for array starting at 0
    int row_of_the_bomb{}; //for array starting at 0
    
    for(auto bomb: bombs){
        //for each of the bombs
        column_of_the_bomba = find_column(bomb);
        row_of_the_bomba = find_row(bomb, column_of_the_bomba);
        column_of_the_bomb = column_of_the_bomba-1; //for array starting at 0
        row_of_the_bomb = row_of_the_bomba-1; //for array starting at 0
        
        
        if(row_of_the_bomb != 0 && column_of_the_bomb != 0)
            table[row_of_the_bomb-1][column_of_the_bomb-1] += 1;
        
        if(row_of_the_bomb != 0)
            table[row_of_the_bomb-1][column_of_the_bomb] += 1;
        
        if(row_of_the_bomb != 0 && column_of_the_bomb != columns-1)
            table[row_of_the_bomb-1][column_of_the_bomb+1] += 1;
        
        if(column_of_the_bomb != 0)
            table[row_of_the_bomb][column_of_the_bomb-1] += 1;
        
        if(column_of_the_bomb != columns-1)
            table[row_of_the_bomb][column_of_the_bomb+1] += 1;
            
        if(row_of_the_bomb != rows-1 && column_of_the_bomb != 0)
            table[row_of_the_bomb+1][column_of_the_bomb-1] += 1;
        
        if(row_of_the_bomb != rows-1)
            table[row_of_the_bomb+1][column_of_the_bomb] += 1;
        
        if(row_of_the_bomb != rows-1 && column_of_the_bomb != columns-1)
            table[row_of_the_bomb+1][column_of_the_bomb+1] += 1;
        
    }
        
    
}

void Minesweeper::show_table(){
    for (int r = 1; r <= rows; r++) {
        for (int c = 1; c <= columns; c++){
            if( find(bombs.begin(), bombs.end(), ((r-1)*columns)+c ) != bombs.end() ){
                cout << "*" << " "; 
            }else if(table[r-1][c-1] == 0){
                cout << "  ";
            }else{
                cout << table[r-1][c-1] << " ";
            }
        }
        cout << endl; 
    }
    
    cout << endl << "[ ";
    for(auto a:bombs)
        cout << a << ", ";
    cout << "]" <<endl;
    
}

