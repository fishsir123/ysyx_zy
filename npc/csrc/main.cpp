#include "verilated_vcd_c.h" // for vcd wave
#include "verilated.h"
#include "Vtop.h"
#include <stdio.h>

VerilatedContext *contextp;
VerilatedVcdC *tfp;
Vtop *top;
vluint64_t main_time = 0;

double sc_time_stamp() {
	return main_time;
}

void init_verilator(int argc, char **argv) {
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  
  top = new Vtop{contextp};
  
  Verilated::traceEverOn(true);
  tfp = new VerilatedVcdC;
  top->trace(tfp, 0);
  tfp->open("wave.vcd");
}

void free() {
  if (tfp != nullptr)
    delete tfp;
  if (top != nullptr)
    delete top;
  if (contextp != nullptr)
    delete contextp; 
}


int main(int argc, char *argv[]) {

  init_verilator(argc, argv);
  int a, b, c;
  for (size_t i = 0; i < 10; i++)
  {
    a = rand() % 10;
    b = rand() % 10;
    c = a + b;
    top->a = a;
    top->b = b;
    top->eval();
    tfp->dump(main_time++);
    printf("a = %d, b = %d, c = %d\n", a, b, top->c);
  }
  

  free();
  
  return 0;
}