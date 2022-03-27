module our (input clk);
	reg readme   /*verilator public_flat_rd*/;
	reg writeme  /*verilator public_flat_rw @(posedge clk) */;
	initial $finish;
endmodule
