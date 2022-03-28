// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vh.h"
#include "Vh__Syms.h"

//============================================================
// Constructors

Vh::Vh(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vh__Syms(_vcontextp__, _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
}

Vh::Vh(const char* _vcname__)
    : Vh(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vh::~Vh() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vh___024root___eval_initial(Vh___024root* vlSelf);
void Vh___024root___eval_settle(Vh___024root* vlSelf);
void Vh___024root___eval(Vh___024root* vlSelf);
#ifdef VL_DEBUG
void Vh___024root___eval_debug_assertions(Vh___024root* vlSelf);
#endif  // VL_DEBUG
void Vh___024root___final(Vh___024root* vlSelf);

static void _eval_initial_loop(Vh__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vh___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vh___024root___eval_settle(&(vlSymsp->TOP));
        Vh___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vh::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vh::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vh___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vh___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vh::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vh::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vh::final() {
    Vh___024root___final(&(vlSymsp->TOP));
}
