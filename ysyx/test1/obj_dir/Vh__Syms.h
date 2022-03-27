// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VH__SYMS_H_
#define VERILATED_VH__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vh.h"

// INCLUDE MODULE CLASSES
#include "Vh___024root.h"

// SYMS CLASS (contains all model state)
class Vh__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vh* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vh___024root                   TOP;

    // CONSTRUCTORS
    Vh__Syms(VerilatedContext* contextp, const char* namep, Vh* modelp);
    ~Vh__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
