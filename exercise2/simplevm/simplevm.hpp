#ifndef H_simplevm_simplevm
#define H_simplevm_simplevm
//---------------------------------------------------------------------------
#include <cstdint>
//---------------------------------------------------------------------------
namespace simplevm {
//---------------------------------------------------------------------------
/// Run the VM. Return the value from register A when the execution finished.
int32_t runVM();
void setRegistersToZero();
void swap();
void storea(char reg);
void movi(char reg, int32_t value);
void movf(char reg, float value);
void storex(char reg);
void swapxy();
void itof();
void ftoi();
void addi();
void subi();
void rsubi();
void muli();
bool divi();
void addf();
void subf();
void mulf();
bool divf();
void loada(char reg);
void loadx(char reg);

//---------------------------------------------------------------------------
/// Print a VM program that calculates the nth fibonacci number.
void fibonacciProgram(unsigned n);
//---------------------------------------------------------------------------
} // namespace simplevm
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
