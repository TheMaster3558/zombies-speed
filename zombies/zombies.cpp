#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;


const string RIGHT = ">";
const string LEFT = "<";
const string INCREASE = "+";
const string DECREASE = "-";
const string INPUT = ",";
const string OUTPUT = ".";
const string START_OF_WHILE = "[";
const string END_OF_WHILE = "]";


class BF {
    public:
        vector<int> cells;
        long index;

        void run(string code) {
            size_t code_len = strlen(code);

            char currentChar;
            char inputChar;
            char outputChar;

            unsigned long end;
            char next_char;

            for (int i = 0; i < code_len; i++) {
                currentChar = code[i];
                if (strcmp(currentChar, RIGHT) == 0) {
                    index++;
                    while (index > cells.size()) {
                        cells.push_back(0);
                    }
                }
                else if (strcmp(currentChar, LEFT) == 0) {
                    while (index <= 0) {
                        cells.insert(cells.begin(), 0);
                    }
                    else {
                        index--;
                    }
                }
                else if (strcmp(currentChar, INCREASE) == 0) {
                    cells[index]++;
                }
                else if (strcmp(currentChar, DECREASE) == 0) {
                    cells[index]--;
                }
                else if (strcmp(currentChar, INPUT) == 0) {
                    inputChar = getchar();
                    cells[index] = inputChar;
                }
                else if (strcmp(currentChar, OUTPUT) == 0) {
                    outputChar = cells[index];
                    putchar(outputChar);
                }
                else if (strcmp(currentChar, START_OF_WHILE) == 0) {
                    end = -1;
                    for (int j = i; next_pos < code_len; next_pos++) {
                        if (code[next_pos] == END_OF_WHILE) {
                            end = i + j;
                            break
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
                        return
                    }
                    else {
                        while (i < end) {
                            i++;
                        }
                    }
                }
            }
        }
}

