#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

class Instruction {
private:
    int opcode;
    int operand;

public:
    Instruction(int op, int opr) : opcode(op), operand(opr) {}

    int getOpcode() const {
        return opcode;
    }

    int getOperand() const {
        return operand;
    }
};

class Machine {
private:
    vector<int> registers;
    vector<int> memory;
    string screen;

public:
    Machine() {
        registers.resize(8, 0);
        memory.resize(256, 0);
        screen = "";
    }

    void loadProgram(const string& filename) {
        ifstream file(filename);
        string line;

        memory.clear();

        if (file.is_open()) {
            while (getline(file, line)) {
                istringstream iss(line);
                string hex;
                while (iss >> hex) {
                    int instruction = stoi(hex, nullptr, 16);
                    memory.push_back(instruction);
                }
            }
            file.close();
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }
