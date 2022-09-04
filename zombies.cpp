#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdio>

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
        std::vector<long> cells;
        long index;

        void print_cells() {
            std::cout << "[";
            for (int i = 0; i < cells.size(); i++) {
                std::cout << cells.at(i) << ", ";
            }
            std::cout << "]" << std::endl;
        }

        void run(std::string code) {
            size_t code_len = code.size();
            unsigned long end;

            char currentChar;
            size_t i;

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
                    cells[index] = getchar();
                }
                else if (currentChar == OUTPUT) {
                    putchar(cells[index]);
                }
                else if (currentChar == START_OF_WHILE) {
                    end = -1;
                    for (size_t j; j < code_len; j++) {
                        if (code[long(j)] == END_OF_WHILE) {
                            end = long(i + j);
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
};


PYBIND11_MODULE(zombies, m) {
    py::class_<BF>(m, "BF")
        .def(py::init<>())
        .def("print_cells", &BF::print_cells)
        .def("run", &BF::run);
}
