#include "grid.h"


Grid::Grid(Xwindow *a): xw{a}{}


Grid::~Grid(){
    clearGrid();
}

void Grid::clearGrid(){
    int i_max = theGrid.size();
    
    for(int i = 0; i < i_max; i++){
        theGrid.at(i).clear();
    }
    theGrid.clear();
}




// Sets up an n x n grid.  Clears old grid, if necessary.
// Initializes every cell in the grid, and tells each
// cell who its neighbours are.
void Grid::init(int n){
   clearGrid();
    for(int i = 0; i < n; i++){
        std::vector <Cell> row;
        for(int j = 0; j < n; j++){
            Cell c{xw};
            row.push_back(c);
        }
        theGrid.push_back(row);
    }
    
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            
            for(int dx=-1; dx<=1; dx++){
                for(int dy=-1; dy<=1; dy++){
                    if(x + dx < n && 0 <= x + dx && y+dy < n && 0 <= y+dy){
                        if(!(dx == 0 && dy == 0)){
                            theGrid.at(x).at(y).addNeighbour(&theGrid.at(x+dx).at(y+dy));
                        }
                    }
                }
            }
        }
    }

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            int scale = 500/n;
            int y_pos = x*scale;
            int x_pos = y*scale;
            theGrid.at(x).at(y).setCoords(x_pos, y_pos, scale, scale);
        }
    }
    
}


// Runs one iteration of the simulation.
// Tells each cell to alert its neighbours, and then
// tells each cell to recalculate.
void Grid::tick(){
    int n = theGrid.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            theGrid.at(i).at(j).alertNeighbours();
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            theGrid.at(i).at(j).recalculate();
        }
    }
    
    
}

// Sets cell at i, j to living.
void Grid::turnOn(int i, int j){
    theGrid.at(j).at(i).setLiving();
}

std::ostream& operator<<(std::ostream &out, const Grid &g){
    
    int n = g.theGrid.size();
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < n; j++){
            out << g.theGrid.at(i).at(j);
        }
        out << std::endl;
    }
    return out;
}
