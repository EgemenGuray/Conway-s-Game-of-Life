#include <iostream>
#include <sstream>
#include "window.h"
#include "grid.h"

int main() {

    Xwindow w;

    Grid g{&w};
    
    std::string s;
    
    while(std::cin >> s){
        if (s == "new") {
            std::string val;
            std::cin >> val;
            std::istringstream ss(val);
            int n;
            ss >> n;
            g.init(n);
        }else if (s == "init") {
            while(true){
                std::string val;
                std::cin >> val;
                std::istringstream a(val);
                int n;
                a >> n;
                std::string val2;
                std::cin >> val2;
                std::istringstream a2(val2);
                int n2;
                a2 >> n2;
                if(n == n2 && n == -1){
                    break;
                }
                g.turnOn(n, n2);
            }
        
        }else if (s == "step") {
            g.tick();
        }else if (s == "steps") {
            std::string val;
            std::cin >> val;
            std::istringstream ss(val);
            int n;
            ss >> n;
            for(int i = 0; i < n; i++){
                g.tick();
            }
        }else if (s == "print"){
            std::cout << g;
        }
        
    }
    
}
