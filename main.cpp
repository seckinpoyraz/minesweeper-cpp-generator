#include "Minesweeper.hpp"

int main(){
    
    while(true){
        Minesweeper *app = new Minesweeper(30,16,55);
        delete app;
        cout << endl;
        Sleep( 3000 );
    }
    
    return 0;
}