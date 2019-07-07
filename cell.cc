#include "cell.h"

 // Default constructor
Cell::Cell(Xwindow *a){
    isAlive = false;
    numAlive = 0;
    numNeighbours = 0;
    xw = a;
}
// Destructor
Cell::~Cell(){
    
}

void Cell::draw(){
    
    xw->fillRectangle(x, y, height, width, Xwindow::Black);

}

void Cell::undraw(){

    xw->fillRectangle(x, y, height, width, Xwindow::White);

}

void Cell::setCoords(int x, int y, int w, int h){
    this->x = x;
    this->y = y;
    this->width = w;
    this->height = h;
}


// Explicitly sets me to living.
void Cell::setLiving(){
    isAlive = true;
    draw();
}


// Adds a pointer to one of my
// neighbours to my array.
void Cell::addNeighbour(Cell *neighbour){
    if(numNeighbours < maxNeighbours){
        this->neighbours[numNeighbours] = neighbour;
        numNeighbours++;
    }
    
}


// My neighbours will call this, to let me know
// they're alive.
void Cell::neighbourIsAlive(){
    numAlive++;
}


// Tell all of my neighbours that I am alive
// (if I'm alive).
void Cell::alertNeighbours(){
    if(isAlive){
        for(int i = 0; i < numNeighbours; i++){
            neighbours[i]->neighbourIsAlive();
        }
    }
}


// Reassess my living-or-dead status, based on
// info from neighbours.
void Cell::recalculate(){
    //std::cout << numAlive << std::endl;
    if(isAlive){
        if(numAlive == 3 || numAlive == 2){
            
            setLiving();
        }else{
            isAlive = false;
            undraw();
        }
    }else{
        if(numAlive == 3){
            setLiving();
        }
    }
    numAlive = 0;
}

std::ostream& operator<<(std::ostream &out, const Cell &c){
    
    if(c.isAlive){
        out << "x";
    }else{
        out << "_";
    }
    return out;
}
