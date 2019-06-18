// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VLCM_H_
#define _VLCM_H_

#include "verilated.h"
class VLCM__Syms;

//----------

VL_MODULE(VLCM) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(n1,0,0);
    VL_IN8(n2,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(result,0,0);
    //char	__VpadToAlign5[3];
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__minmultiple,0,0);
    //char	__VpadToAlign13[3];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    //char	__VpadToAlign21[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign28[4];
    VLCM__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VLCM& operator= (const VLCM&);	///< Copying not allowed
    VLCM(const VLCM&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    VLCM(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VLCM();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VLCM__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VLCM__Syms* symsp, bool first);
  private:
    static QData	_change_request(VLCM__Syms* __restrict vlSymsp);
  public:
    static void	_eval(VLCM__Syms* __restrict vlSymsp);
    static void	_eval_initial(VLCM__Syms* __restrict vlSymsp);
    static void	_eval_settle(VLCM__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(VLCM__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
