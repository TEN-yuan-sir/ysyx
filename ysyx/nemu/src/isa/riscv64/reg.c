#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

// gpr() is declared in reg.h
void isa_reg_display() {
	int i;
	for(i = 0; i<16; i+=1 ){
		printf("%4s %12lx\t",regs[i],gpr(i));
		printf("%4s %12lx \n",regs[i+16],gpr(i+16));
	}
}

word_t isa_reg_str2val(const char *s, bool *success) {
  return 0;
}
