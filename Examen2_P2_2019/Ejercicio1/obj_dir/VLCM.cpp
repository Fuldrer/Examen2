// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VLCM.h for the primary calling header

#include "VLCM.h"              // For This
#include "VLCM__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VLCM) {
    VLCM__Syms* __restrict vlSymsp = __VlSymsp = new VLCM__Syms(this, name());
    VLCM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    n1 = VL_RAND_RESET_I(1);
    n2 = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    result = VL_RAND_RESET_I(1);
    v__DOT__minmultiple = VL_RAND_RESET_I(1);
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
}

void VLCM::__Vconfigure(VLCM__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VLCM::~VLCM() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VLCM::eval() {
    VLCM__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    VLCM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate VLCM::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void VLCM::_eval_initial_loop(VLCM__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VLCM::_sequent__TOP__1(VLCM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VLCM::_sequent__TOP__1\n"); );
    VLCM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at LCM.v:13
    if (vlTOPp->rst) {
	vlTOPp->v__DOT__minmultiple = 0U;
    }
    if (((0U == VL_MODDIV_III(32, (IData)(vlTOPp->v__DOT__minmultiple), (IData)(vlTOPp->n1))) 
	 & (0U == VL_MODDIV_III(32, (IData)(vlTOPp->v__DOT__minmultiple), (IData)(vlTOPp->n2))))) {
	vlTOPp->result = vlTOPp->v__DOT__minmultiple;
    }
    vlTOPp->v__DOT__minmultiple = 0U;
}

void VLCM::_eval(VLCM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VLCM::_eval\n"); );
    VLCM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VLCM::_eval_initial(VLCM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VLCM::_eval_initial\n"); );
    VLCM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VLCM::final() {
    VL_DEBUG_IF(VL_PRINTF("    VLCM::final\n"); );
    // Variables
    VLCM__Syms* __restrict vlSymsp = this->__VlSymsp;
    VLCM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VLCM::_eval_settle(VLCM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VLCM::_eval_settle\n"); );
    VLCM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

VL_INLINE_OPT QData VLCM::_change_request(VLCM__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    VLCM::_change_request\n"); );
    VLCM* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}
