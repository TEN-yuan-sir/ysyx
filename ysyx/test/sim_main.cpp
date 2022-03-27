#include "Vour.h"
  #include "verilated.h"
  #include "verilated_vpi.h"  // Required to get definitions
vluint64_t main_time = 0;   // See comments in first example
double sc_time_stamp() { return main_time; }
void read_and_check() {
	      vpiHandle vh1 = vpi_handle_by_name((PLI_BYTE8*)"TOP.our.readme", NULL);
		       if (!vh1) vl_fatal(__FILE__, __LINE__, "sim_main", "No handle found");
			   const char* name = vpi_get_str(vpiName, vh1);
printf("Module name: %s\n", name);  // Prints "readme"

s_vpi_value v;
v.format = vpiIntVal;
vpi_get_value(vh1, &v);
printf("Value of v: %d\n", v.value.integer);  // Prints "readme"
  }


  int main(int argc, char** argv, char** env) {Verilated::commandArgs(argc, argv);
	  Vour* top = new Vour;
	  Verilated::internalsDump();  // See scopes to help debug
	  while (!Verilated::gotFinish()) {
		  top->eval();
		   VerilatedVpi::callValueCbs();  // For signal callbacks
			read_and_check();
      }
	  delete top;
	  return 0;
	}
