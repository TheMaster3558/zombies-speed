#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdio>
using namespace std;


const char RIGHT = '>';
const char LEFT = '<';
const char INCREASE = '+';
const char DECREASE = '-';
const char INPUT = ',';
const char OUTPUT = '.';
const char START_OF_WHILE = '[';
const char END_OF_WHILE = ']';



class BF {
    public:
        vector<int> cells;
        long index;

        void run(string code) {
            size_t code_len = code.size();

            char currentChar;
            char inputChar;
            char outputChar;

            unsigned long end;
            char next_char;

            int i;
            for (i = 0; i < code_len; i++) {
                currentChar = code[i];
                if (currentChar == RIGHT) {
                    index++;
                    while (index > cells.size()) {
                        cells.push_back(0);
                    }
                }
                else if (currentChar == LEFT){
                    if (index <= 0) {
                        while (index <= 0) {
                            cells.insert(cells.begin(), 0);
                        }
                    }
                    else {
                        index--;
                    }
                }
                else if (currentChar == INCREASE) {
                    cells[index]++;
                }
                else if (currentChar == DECREASE) {
                    cells[index]--;
                }
                else if (currentChar == INPUT) {
                    inputChar = getchar();
                    cells[index] = inputChar;
                }
                else if (currentChar == OUTPUT) {
                    outputChar = cells[index];
                    putchar(outputChar);
                }
                else if (currentChar == START_OF_WHILE) {
                    end = -1;
                    for (int j = i; j < code_len; j++) {
                        if (code[j] == END_OF_WHILE) {
                            end = i + j;
                            break;
                        }
                    }
                    if (end == -1) {
                        throw runtime_error("Unclosed bracket");
                    }

                    i++;
                    while (cells[index] != 0) {
                        run(code.substr(i, end - i));
                    }

                    if (end >= code_len) {
                        return;
                    }
                    else {
                        while (i < end) {
                            i++;
                        }
                    }
                }
            }
        }
};
