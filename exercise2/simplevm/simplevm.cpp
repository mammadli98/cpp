#include "simplevm/simplevm.hpp"
#include <iostream>
#include <sstream>
#include <string>
//---------------------------------------------------------------------------
namespace simplevm {
//---------------------------------------------------------------------------

int32_t A = 0, B = 0, C = 0, D = 0;
float X = 0.0f, Y = 0.0f;

int32_t runVM()
// Run the VM. Return the value from register A when the execution finished.
{
    setRegistersToZero();
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        int opcode;
        iss >> opcode;

        switch (opcode) {
            case 0:  //halt
                return A;
            case 10: {     //movi
                char reg;
                int32_t value;
                iss >> reg >> value;
                movi(reg, value);
                break;
            }
            case 11: {   //movf
                char reg;
                float value;
                iss >> reg >> value;
                movf(reg, value);
                break;
            }
            case 20: {   //loada
                char reg;
                iss >> reg;
                loada(reg);
                break;
            }
            case 21: {  //storea
                char reg;
                iss >> reg;
                storea(reg);
                break;
            }
            case 22:   //swapab
                swap();
                break;
            case 30: {   //loadx
                char reg;
                iss >> reg;
                loadx(reg);
                break;
            }
            case 31: {  //storex
                char reg;
                iss >> reg;
                storex(reg);
                break;
            }
            case 32:   //swapxy
                swapxy();
                break;
            case 40:  //itof
                itof();
                break;
            case 41:  //ftoi
                ftoi();
                break;
            case 50: //addi
                addi();
                break;
            case 51:   //subi
                subi();
                break;
            case 52:   //rsubi
                rsubi();
                break;
            case 53: //muli
                muli();
                break;
            case 54:  //divi
                if(!divi()){
                    std::cout << "division by 0" << std::endl;
                    return A;
                }
                break;
            case 60:   //addf
                addf();
                break;
            case 61:   //subf
                subf();
                break;
            case 62:  //mulf
                mulf();
                break;
            case 63: {  //divf
                if(!divf()){
                    std::cout << "division by 0" << std::endl;
                    return A;
                }
                break;
            }
            default:
                // Ignore unknown opcodes
                break;
        }
    }

    return A;
}
//---------------------------------------------------------------------------

void setRegistersToZero(){
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    X = 0.0f;
    Y = 0.0f;
}

void swap(){
    int32_t keepValue = A;
    A = B;
    B = keepValue;
}

void swapxy(){
    float keepValue = X;
    X = Y;
    Y = keepValue;
}

void storea(char reg) {
    switch (reg) {
        case 'A':
            A = A;
            break;
        case 'B':
            B = A;
            break;
        case 'C':
            C = A;
            break;
        case 'D':
            D = A;
            break;
        default:
            // Ignore unknown registers
            break;
    }
}

void addi(){
    A = A + B;
}

void subi(){
    A = A - B;
}

void rsubi(){
    A = B - A;
}

void muli(){
    A = A * B;
}

bool divi(){
    if(B == 0){
        return false;
    }
    int32_t quotient = A / B;
    int32_t remainder = A % B;
    A = quotient;
    B = remainder;
    return true;
}

void addf(){
    X = X + Y;
}

void subf(){
    X = X - Y;
}

void mulf(){
    X = X * Y;
}

bool divf(){
    if(Y == 0){
        return false;
    }
    X = X / Y;
    return true;
}

void movi(char reg, int32_t value) {
    switch (reg) {
        case 'A':
            A = value;
            break;
        case 'B':
            B = value;
            break;
        case 'C':
            C = value;
            break;
        case 'D':
            D = value;
            break;
        default:
            // Ignore unknown registers
            break;
    }
}

void movf(char reg, float value) {
    switch (reg) {
        case 'X':
            X = value;
            break;
        case 'Y':
            Y = value;
            break;
        default:
            // Ignore unknown registers
            break;
    }
}

void storex(char reg) {
    switch (reg) {
        case 'X':
            X = X;
            break;
        case 'Y':
            Y = X;
            break;
        default:
            // Ignore unknown registers
            break;
    }
}

void ftoi(){
    int32_t convertedValue = X;
    A = convertedValue;
}

void itof(){
    float convertedValue = A;
    X = convertedValue;
}

void loada(char reg) {
    switch (reg) {
        case 'A':
            A = A;
            break;
        case 'B':
            A = B;
            break;
        case 'C':
            A = C;
            break;
        case 'D':
            A = D;
            break;
        default:
            // Ignore unknown registers
            break;
    }
}

void loadx(char reg) {
    switch (reg) {
        case 'X':
            X = X;
            break;
        case 'Y':
            X = Y;
            break;
        default:
            // Ignore unknown registers
            break;
    }
}


void fibonacciProgram(unsigned n)
// Print a VM program that calculates the nth fibonacci number.
{
    if(n == 0){
        std::cout << "0";
        return;
    }
    if(n == 1){
        std::cout << "10 A 1";
        return;
    }

    std::cout << "10 B 1\n";
    // Print instructions to calculate Fibonacci sequence up to the nth number
    for (unsigned i = 2; i <= n; ++i) {
        std::cout << "50\n";  // Add A and B (store result in A)
        std::cout << "22\n";  // Swap the values of A and B
    }

    std::cout << "22\n0";

}
//---------------------------------------------------------------------------
} // namespace simplevm
//---------------------------------------------------------------------------
