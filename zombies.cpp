#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdio>
#include <cmath>

#include <pybind11/pybind11.h>
namespace py = pybind11;


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
        std::vector<long> cells = {0};
        unsigned long index;

        void print_cells() {
            std::string vectorContents = "[";
            unsigned long vectorEndIndex = cells.size() - 1;
            unsigned long spaces;

            for (unsigned long i = 0; i <= vectorEndIndex; i++) {
                if (i == index) {
                    spaces = vectorContents.size() + ceil(std::to_string(cells.at(i)).size() / 2);
                }
                vectorContents += std::to_string(cells.at(i));
                if (i != vectorEndIndex) {
                    vectorContents += ", ";
                }
            }
            vectorContents += "]\n";
            std::string caratString(spaces, ' ');
            caratString += "^\n";

            std::cout << vectorContents << caratString;
        }

        void run(std::string code) {
            size_t code_len = code.size();
            size_t end;

            char currentChar;
            size_t i;

            for (i = 0; i < code_len; i++) {
                currentChar = code[i];
                if (currentChar == RIGHT) {
                    index++;
                    if (index >= cells.size()) {
                        cells.push_back(0);
                    }
                }
                else if (currentChar == LEFT){
                    if (index <= 0) {
                        if (index <= 0) {
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
                    cells[index] = getchar();
                }
                else if (currentChar == OUTPUT) {
                    putchar(cells[index]);
                }
                else if (currentChar == START_OF_WHILE) {
                    end = -1;
                    for (size_t j = i; j < code_len; j++) {
                        if (code[j] == END_OF_WHILE) {
                            end = j;
                            break;
                        }
                    }
                    if (end == -1) {
                        throw std::runtime_error("Unclosed bracket");
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

        void run_file(std::string filename) {
            std::ifstream file(filename);
            std::string code (
                    (std::istreambuf_iterator<char>(file)),
                    (std::istreambuf_iterator<char>())
            );
            file.close();

            run(code);

        }
};


PYBIND11_MODULE(zombies, m) {
    py::class_<BF>(m, "BF")
        .def(py::init<>())
        .def("print_cells", &BF::print_cells)
        .def("run", &BF::run)
        .def("run_file", &BF::run_file);
}
