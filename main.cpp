#include "Minesweeper.hpp"

int main(){
    
    while(true){
        //create random tables continiously on the heap
        Minesweeper *app = new Minesweeper(30,16,55);
        delete app;
        cout << endl;
        Sleep( 3000 ); //wait for 3 sec
    }
    
    return 0;
}
