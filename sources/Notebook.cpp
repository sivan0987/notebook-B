#include "Notebook.hpp"
#include <string>
#include "Direction.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;


void ariel::Notebook::write(int page, int row, int col, Direction direction, string str) {
    const int len_max = 100;
    const int min = 32;
    const int max = 125;
    int len = str.length();
    //errors
    if (col < 0 || col > len_max-1|| row < 0 || page < 0 || str.length() < 0) {
        throw runtime_error("negative variables");
    }
    
    for (int i = 0; i < len; ++i) {
        if (str[(unsigned int)i] < min || str[(unsigned int)i] > max) {
            throw runtime_error("The character is invalid");
        }
    }
  
    if (direction == Direction::Horizontal) {
        if ((len + col) > len_max) {
            throw runtime_error("out of line!");
        }
        for (int i = col; i < len + col; i++) {
            if (_map[page][row][i] == '~') {
                throw runtime_error("We have already deleted this line!");}

            if(_map[page][row][i] >= min && _map[page][row][i] < max){

                if(_map[page][row][i]=='_'){
                    _map[page][row][i] = str[(unsigned int)(i-col)];
                }
                else
                {
                    throw runtime_error("We have already written!");
                }

            }
            else{
                _map[page][row][i] = str[(unsigned int)(i-col)];
               
            }
        }
    }
    if (direction == Direction::Vertical) {
        for (int i = row; i < len + row; i++) {
            if (_map[page][i][col] == '~') {
                throw runtime_error("We have already deleted this line!");
            }
            if(_map[page][i][col] >= min && _map[page][i][col] <= max ){
                if(_map[page][i][col]=='_'){
                    _map[page][i][col] = str[(unsigned int)(i-row)];
                }
                else
                {
                    throw runtime_error("We have already written this line!");
                }
            }
            else{
                _map[page][i][col] = str[(unsigned int)(i-row)];
            }
        }
    }
}

string ariel::Notebook::read(int page, int row, int col, Direction direction, int numOfChars) {
    const int len_max = 100;
    const int min = 32;
    const int max = 125;
    string s;

    if (numOfChars < 0 || col < 0 || col > len_max-1|| row < 0 || page < 0) {
        throw invalid_argument(" negative variables!");
    }
    if(Direction::Horizontal == direction && numOfChars + col > len_max) {
            throw invalid_argument(" negative variables!");
    }
    
    
    if (direction == Direction::Horizontal) {
        if ((numOfChars + col) > len_max) {
            throw runtime_error(" out of line!");
        }
        for (int i = col; i < numOfChars + col; i++) {
            if(_map[page][row][i] >= min && _map[page][row][i] <= max+1) {
                s += _map[page][row][i];
            } else {
                s += '_';
            }
        }
    }
    if (direction == Direction::Vertical) {
        for (int i = row; i < numOfChars + row; i++) {
            if (_map[page][i][col] >= min && _map[page][i][col] <= max+1) {
                s += _map[page][i][col];
            } else {
                s += '_';
            }
        }
    }

    return s;
}


void ariel::Notebook::erase(int page, int row, int col, ariel::Direction direction, int chars) {
    const int len_max = 100;
    if (chars < 0 || col < 0 || col > len_max-1|| row < 0 || page < 0) {
        throw invalid_argument(" negative variables!");
    }
    if(Direction::Horizontal == direction && chars + col > len_max) {
            throw invalid_argument(" negative variables!");
    }
    if(direction== Direction::Horizontal){
        if ((chars + col) > len_max) {
            throw runtime_error(" out of line!");
        }
        for (int i = col; i < chars + col; i++) {
            _map[page][row][i] = '~';
        }
    }
    else{
        for (int i = row; i < chars + row; i++) {
            _map[page][i][col] = '~';
        }
    }}

void ariel::Notebook::show(int page) {
    {
        if (page < 0)
        {
            throw runtime_error("negtive number");
        }
        cout << _map[page][0][0] << "\nshow func\n";
    }

}