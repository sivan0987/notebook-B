#pragma once
#include <string>
using namespace std;
#include "Direction.hpp"
#include <unordered_map>
#include <array>

namespace ariel{
    
  

    class Notebook{
        private:
            
            unordered_map <int ,unordered_map <int , char[100]>> _map;
        public:
            void write(int page, int row, int col, Direction direction, string str);
            string read(int page, int row, int col, Direction direction, int chars);
            void erase(int page, int row, int col, Direction direction, int chars) ;
            void show(int page) ;

    };
    
     
    

}