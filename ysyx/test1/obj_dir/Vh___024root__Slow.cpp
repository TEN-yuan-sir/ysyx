// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vh.h for the primary calling header

#include "verilated.h"

#include "Vh__Syms.h"
#include "Vh___024root.h"

void Vh___024root___ctor_var_reset(Vh___024root* vlSelf);

Vh___024root::Vh___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vh___024root___ctor_var_reset(this);
}

void Vh___024root::__Vconfigure(Vh__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vh___024root::~Vh___024root() {
}
