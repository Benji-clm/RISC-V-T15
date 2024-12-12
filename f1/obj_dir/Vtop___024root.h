// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_IN8(trigger,0,0);
        CData/*0:0*/ top__DOT__eq;
        CData/*0:0*/ top__DOT__RegWriteD;
        CData/*1:0*/ top__DOT__ResultSrcD;
        CData/*0:0*/ top__DOT__MemWriteD;
        CData/*2:0*/ top__DOT__PCsrcD;
        CData/*3:0*/ top__DOT__ALUControlD;
        CData/*0:0*/ top__DOT__ALUsrcD;
        CData/*2:0*/ top__DOT__ImmSrcD;
        CData/*2:0*/ top__DOT__LS_modeD;
        CData/*0:0*/ top__DOT__RegWriteE;
        CData/*1:0*/ top__DOT__ResultSrcE;
        CData/*0:0*/ top__DOT__MemWriteE;
        CData/*2:0*/ top__DOT__PCsrcE;
        CData/*3:0*/ top__DOT__ALUControlE;
        CData/*0:0*/ top__DOT__ALUsrcE;
        CData/*4:0*/ top__DOT__Rs1E;
        CData/*4:0*/ top__DOT__Rs2E;
        CData/*4:0*/ top__DOT__RdE;
        CData/*2:0*/ top__DOT__LS_modeE;
        CData/*0:0*/ top__DOT__RegWriteM;
        CData/*1:0*/ top__DOT__ResultSrcM;
        CData/*0:0*/ top__DOT__MemWriteM;
        CData/*4:0*/ top__DOT__RdM;
        CData/*2:0*/ top__DOT__LS_modeM;
        CData/*0:0*/ top__DOT__RegWriteW;
        CData/*1:0*/ top__DOT__ResultSrcW;
        CData/*4:0*/ top__DOT__RdW;
        CData/*0:0*/ top__DOT__Hazard_PCsrc;
        CData/*0:0*/ top__DOT__StallF;
        CData/*0:0*/ top__DOT__StallD;
        CData/*1:0*/ top__DOT__ForwardAE;
        CData/*1:0*/ top__DOT__ForwardBE;
        CData/*0:0*/ top__DOT__MemReadD;
        CData/*0:0*/ top__DOT__MemReadE;
        CData/*0:0*/ top__DOT__MemReadM;
        CData/*0:0*/ top__DOT__cache__DOT__hit;
        CData/*1:0*/ top__DOT__cache__DOT__hit_way;
        CData/*0:0*/ top__DOT__cache__DOT__unnamedblk6__DOT__lru_way;
        CData/*0:0*/ top__DOT__cache__DOT____Vlvbound_hbe650bd0__0;
        CData/*7:0*/ top__DOT__top_memory_inst__DOT__byte3;
        CData/*7:0*/ top__DOT__top_memory_inst__DOT__byte2;
        CData/*7:0*/ top__DOT__top_memory_inst__DOT__byte1;
        CData/*7:0*/ top__DOT__top_memory_inst__DOT__byte0;
        CData/*2:0*/ top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
        CData/*0:0*/ top__DOT__hazard_unit___DOT__lwStall;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT(a0,31,0);
        IData/*31:0*/ top__DOT__next_pc;
        IData/*31:0*/ top__DOT__instr;
        IData/*31:0*/ top__DOT__SrcAE;
        IData/*31:0*/ top__DOT__WriteDataE;
        IData/*31:0*/ top__DOT__SrcBE;
        IData/*31:0*/ top__DOT__ALUResult;
        IData/*31:0*/ top__DOT__pcF;
        IData/*31:0*/ top__DOT__instrD;
        IData/*31:0*/ top__DOT__pcD;
        IData/*31:0*/ top__DOT__ImmExtD;
        IData/*31:0*/ top__DOT__PCPlus4D;
        IData/*31:0*/ top__DOT__rd1E;
    };
    struct {
        IData/*31:0*/ top__DOT__rd2E;
        IData/*31:0*/ top__DOT__pcE;
        IData/*31:0*/ top__DOT__ImmExtE;
        IData/*31:0*/ top__DOT__PCPlus4E;
        IData/*31:0*/ top__DOT__ALUResultM;
        IData/*31:0*/ top__DOT__WriteDataM;
        IData/*31:0*/ top__DOT__PCPlus4M;
        IData/*31:0*/ top__DOT__ALUResultW;
        IData/*31:0*/ top__DOT__ReadDataW;
        IData/*31:0*/ top__DOT__PCPlus4W;
        IData/*31:0*/ top__DOT__ResultW;
        IData/*31:0*/ top__DOT__rd;
        IData/*31:0*/ top__DOT____Vcellinp__pc_counter__PCTargetE;
        IData/*31:0*/ top__DOT__cache__DOT__mem_instr;
        IData/*31:0*/ top__DOT__cache__DOT__unnamedblk3__DOT__i;
        IData/*31:0*/ top__DOT__cache__DOT__unnamedblk4__DOT__i;
        IData/*31:0*/ top__DOT__cache__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j;
        IData/*31:0*/ top__DOT__cache__DOT__unnamedblk6__DOT__unnamedblk7__DOT__i;
        IData/*31:0*/ top__DOT__cache__DOT__unnamedblk6__DOT__unnamedblk8__DOT__i;
        VlWide<4>/*127:0*/ top__DOT__cache__DOT____Vlvbound_h4b79c829__0;
        IData/*21:0*/ top__DOT__cache__DOT____Vlvbound_ha2ec015c__0;
        IData/*31:0*/ top__DOT__top_memory_inst__DOT__rd_cache;
        IData/*31:0*/ top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd;
        IData/*26:0*/ top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__address_tag;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<VlWide<10>/*303:0*/, 256> top__DOT__cache__DOT__cache_mem;
        VlUnpacked<CData/*7:0*/, 4096> top__DOT__cache__DOT__mem_inst__DOT__array;
        VlUnpacked<IData/*31:0*/, 32> top__DOT__registers__DOT__rf;
        VlUnpacked<QData/*59:0*/, 8> top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem;
        VlUnpacked<CData/*7:0*/, 131072> top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlNBACommitQueue<VlUnpacked<VlWide<10>/*303:0*/, 256>, true, VlWide<10>/*303:0*/, 1> __VdlyCommitQueuetop__DOT__cache__DOT__cache_mem;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
