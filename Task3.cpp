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

            case 5: {
                    int registerIndex1 = (operand >> 8) & 0xF;
                    int registerIndex2 = (operand >> 4) & 0xF;
                    int registerIndex3 = operand & 0xF;
                    int sum = registers[registerIndex2] + registers[registerIndex3];
                    registers[registerIndex1] = sum;
                    break;
                }
            case 6: {
                int registerIndex1 = (operand >> 8) & 0xF;
                int registerIndex2 = (operand >> 4) & 0xF;
                int registerIndex3 = operand & 0xF;
                float value1 = static_cast<float>(registers[registerIndex2]);
                float value2 = static_cast<float>(registers[registerIndex3]);
                float sum = value1 + value2;
                registers[registerIndex1] = static_cast<int>(sum);
                break;
            }
            case 11: {
                int registerIndex = (operand >> 8) & 0xF;
                int memoryAddress = operand & 0xFF; 
                if (registers[registerIndex] == registers[0]) {
                    pc = memoryAddress;
                }
                break;
            }
            case 12: {
                cout << "Halt instruction encountered. Program execution stopped." << endl;
                return;
            }
            default:
                cout << "Invalid opcode: " << opcode << endl;
                return;
        }
    }

    void displayStatus() const {
        cout << "Registers:" << endl;
        for (int i = 0; i < registers.size(); i++) {
            cout << "R" << i << ": " << registers[i] << endl;
        }

        cout << "Memory:" << endl;
        for (int i = 0; i < memory.size(); i++) {
            cout << "M[" << i << "]: " << memory[i] << endl;
        }

        cout << "Screen:" << endl;
        cout << screen << endl;
    }
};

int main() {
    Machine machine;
    machine.loadProgram("2000.txt");
    machine.executeStep();
    machine.displayStatus();

    return 0;
}
