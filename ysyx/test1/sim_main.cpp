#include "Vh.h"    // Verilog模块会被编译成Vxxx
#include "verilated.h"
int main(int argc, char **argv, char **env){
	Verilated::commandArgs(argc, argv);
	Vh *top = new Vh;
	while(!Verilated::gotFinish()) {top -> eval(); }
	delete top;
	exit(0);

}
