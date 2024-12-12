// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSelfRef.clk)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

extern const VlWide<10>/*319:0*/ Vtop__ConstPool__CONST_h7c08bc10_0;
extern const VlWide<10>/*319:0*/ Vtop__ConstPool__CONST_hd22f7c10_0;
extern const VlWide<10>/*319:0*/ Vtop__ConstPool__CONST_h6dedb645_0;
extern const VlWide<10>/*319:0*/ Vtop__ConstPool__CONST_h2c6a6e39_0;
extern const VlWide<10>/*319:0*/ Vtop__ConstPool__CONST_h7c083c10_0;
extern const VlWide<10>/*319:0*/ Vtop__ConstPool__CONST_hfe883c11_0;
extern const VlWide<10>/*319:0*/ Vtop__ConstPool__CONST_hff8d9a12_0;
extern const VlWide<10>/*319:0*/ Vtop__ConstPool__CONST_h2dc653e5_0;
extern const VlWide<10>/*319:0*/ Vtop__ConstPool__CONST_he1e3be2a_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __VdlyDim0__top__DOT__cache__DOT__cache_mem__v0;
    __VdlyDim0__top__DOT__cache__DOT__cache_mem__v0 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__cache__DOT__cache_mem__v1;
    __VdlyDim0__top__DOT__cache__DOT__cache_mem__v1 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__cache__DOT__cache_mem__v2;
    __VdlyDim0__top__DOT__cache__DOT__cache_mem__v2 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__cache__DOT__cache_mem__v3;
    __VdlyDim0__top__DOT__cache__DOT__cache_mem__v3 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__cache__DOT__cache_mem__v4;
    __VdlyDim0__top__DOT__cache__DOT__cache_mem__v4 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__cache__DOT__cache_mem__v5;
    __VdlyDim0__top__DOT__cache__DOT__cache_mem__v5 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__top__DOT__cache__DOT__cache_mem__v6;
    VL_ZERO_W(128, __VdlyVal__top__DOT__cache__DOT__cache_mem__v6);
    IData/*31:0*/ __VdlyLsb__top__DOT__cache__DOT__cache_mem__v6;
    __VdlyLsb__top__DOT__cache__DOT__cache_mem__v6 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__cache__DOT__cache_mem__v6;
    __VdlyDim0__top__DOT__cache__DOT__cache_mem__v6 = 0;
    VlWide<10>/*303:0*/ __VdlyMask__top__DOT__cache__DOT__cache_mem__v6;
    VL_ZERO_W(304, __VdlyMask__top__DOT__cache__DOT__cache_mem__v6);
    VlWide<10>/*303:0*/ __VdlyElem__top__DOT__cache__DOT__cache_mem__v6;
    VL_ZERO_W(304, __VdlyElem__top__DOT__cache__DOT__cache_mem__v6);
    IData/*21:0*/ __VdlyVal__top__DOT__cache__DOT__cache_mem__v7;
    __VdlyVal__top__DOT__cache__DOT__cache_mem__v7 = 0;
    IData/*31:0*/ __VdlyLsb__top__DOT__cache__DOT__cache_mem__v7;
    __VdlyLsb__top__DOT__cache__DOT__cache_mem__v7 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__cache__DOT__cache_mem__v7;
    __VdlyDim0__top__DOT__cache__DOT__cache_mem__v7 = 0;
    VlWide<10>/*303:0*/ __VdlyMask__top__DOT__cache__DOT__cache_mem__v7;
    VL_ZERO_W(304, __VdlyMask__top__DOT__cache__DOT__cache_mem__v7);
    VlWide<10>/*303:0*/ __VdlyElem__top__DOT__cache__DOT__cache_mem__v7;
    VL_ZERO_W(304, __VdlyElem__top__DOT__cache__DOT__cache_mem__v7);
    CData/*0:0*/ __VdlyVal__top__DOT__cache__DOT__cache_mem__v8;
    __VdlyVal__top__DOT__cache__DOT__cache_mem__v8 = 0;
    IData/*31:0*/ __VdlyLsb__top__DOT__cache__DOT__cache_mem__v8;
    __VdlyLsb__top__DOT__cache__DOT__cache_mem__v8 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__cache__DOT__cache_mem__v8;
    __VdlyDim0__top__DOT__cache__DOT__cache_mem__v8 = 0;
    VlWide<10>/*303:0*/ __VdlyMask__top__DOT__cache__DOT__cache_mem__v8;
    VL_ZERO_W(304, __VdlyMask__top__DOT__cache__DOT__cache_mem__v8);
    VlWide<10>/*303:0*/ __VdlyElem__top__DOT__cache__DOT__cache_mem__v8;
    VL_ZERO_W(304, __VdlyElem__top__DOT__cache__DOT__cache_mem__v8);
    CData/*0:0*/ __VdlyVal__top__DOT__cache__DOT__cache_mem__v9;
    __VdlyVal__top__DOT__cache__DOT__cache_mem__v9 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__cache__DOT__cache_mem__v9;
    __VdlyDim0__top__DOT__cache__DOT__cache_mem__v9 = 0;
    VlWide<10>/*303:0*/ __VdlyElem__top__DOT__cache__DOT__cache_mem__v9;
    VL_ZERO_W(304, __VdlyElem__top__DOT__cache__DOT__cache_mem__v9);
    CData/*0:0*/ __VdlyVal__top__DOT__cache__DOT__cache_mem__v10;
    __VdlyVal__top__DOT__cache__DOT__cache_mem__v10 = 0;
    CData/*7:0*/ __VdlyDim0__top__DOT__cache__DOT__cache_mem__v10;
    __VdlyDim0__top__DOT__cache__DOT__cache_mem__v10 = 0;
    VlWide<10>/*303:0*/ __VdlyElem__top__DOT__cache__DOT__cache_mem__v10;
    VL_ZERO_W(304, __VdlyElem__top__DOT__cache__DOT__cache_mem__v10);
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v0;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v0;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v0 = 0;
    IData/*26:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v1;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v1 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v1;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v3;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v3 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v3;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v3 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v5;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v5 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v5;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v5 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v11;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v11 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v11;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v11 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v12;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v12 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v12;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v12 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v13;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v13 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v13;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v13 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v14;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v14 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v14;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v14 = 0;
    IData/*26:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v15;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v15 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v15;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v15 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v16;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v16 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v16;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v16 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v17;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v17 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v17;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v17 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v18;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v18 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v18;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v18 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v19;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v19 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v19;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v19 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v21;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v21 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v21;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v21 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v22;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v22 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v22;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v22 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v24;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v24 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v24;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v24 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v25;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v25 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v25;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v25 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v27;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v27 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v27;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v27 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v28;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v28 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v28;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v28 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v30;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v30 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v30;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v30 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v31;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v31 = 0;
    CData/*2:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v31;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v31 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v2;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v2 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v2;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v2 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v3;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v3 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v3;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v3 = 0;
    CData/*7:0*/ __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v4;
    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v4 = 0;
    IData/*16:0*/ __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v4;
    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v4 = 0;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v0 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v14 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26 = 0U;
    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.rst)))) {
        if ((1U & (~ (IData)(vlSelfRef.top__DOT__cache__DOT__hit)))) {
            vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__unnamedblk7__DOT__i = 2U;
            vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__unnamedblk8__DOT__i = 2U;
        }
    }
    if (vlSelfRef.rst) {
        vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__i = 0U;
        while (VL_GTS_III(32, 0x100U, vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__i)) {
            __VdlyDim0__top__DOT__cache__DOT__cache_mem__v0 
                = (0xffU & vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__i);
            vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.enqueue(Vtop__ConstPool__CONST_h7c08bc10_0, Vtop__ConstPool__CONST_hd22f7c10_0, (IData)(__VdlyDim0__top__DOT__cache__DOT__cache_mem__v0));
            __VdlyDim0__top__DOT__cache__DOT__cache_mem__v1 
                = (0xffU & vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__i);
            vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.enqueue(Vtop__ConstPool__CONST_h7c08bc10_0, Vtop__ConstPool__CONST_h6dedb645_0, (IData)(__VdlyDim0__top__DOT__cache__DOT__cache_mem__v1));
            __VdlyDim0__top__DOT__cache__DOT__cache_mem__v2 
                = (0xffU & vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__i);
            vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.enqueue(Vtop__ConstPool__CONST_h7c08bc10_0, Vtop__ConstPool__CONST_h2c6a6e39_0, (IData)(__VdlyDim0__top__DOT__cache__DOT__cache_mem__v2));
            __VdlyDim0__top__DOT__cache__DOT__cache_mem__v3 
                = (0xffU & vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__i);
            vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.enqueue(Vtop__ConstPool__CONST_h7c08bc10_0, Vtop__ConstPool__CONST_h7c083c10_0, (IData)(__VdlyDim0__top__DOT__cache__DOT__cache_mem__v3));
            __VdlyDim0__top__DOT__cache__DOT__cache_mem__v4 
                = (0xffU & vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__i);
            vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.enqueue(Vtop__ConstPool__CONST_h7c08bc10_0, Vtop__ConstPool__CONST_hfe883c11_0, (IData)(__VdlyDim0__top__DOT__cache__DOT__cache_mem__v4));
            __VdlyDim0__top__DOT__cache__DOT__cache_mem__v5 
                = (0xffU & vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__i);
            vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.enqueue(Vtop__ConstPool__CONST_h7c08bc10_0, Vtop__ConstPool__CONST_hff8d9a12_0, (IData)(__VdlyDim0__top__DOT__cache__DOT__cache_mem__v5));
            vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j = 2U;
            vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__i 
                = ((IData)(1U) + vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__i);
        }
    } else if ((1U & (~ (IData)(vlSelfRef.top__DOT__cache__DOT__hit)))) {
        vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__lru_way = 0U;
        if (((1U & (vlSelfRef.top__DOT__cache__DOT__cache_mem
                    [(0xffU & vlSelfRef.top__DOT__pcF)][0U] 
                    >> 1U)) > (1U & vlSelfRef.top__DOT__cache__DOT__cache_mem
                               [(0xffU & vlSelfRef.top__DOT__pcF)][0U]))) {
            vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__lru_way = 1U;
        }
        vlSelfRef.top__DOT__cache__DOT____Vlvbound_h4b79c829__0[0U] 
            = vlSelfRef.top__DOT__cache__DOT__mem_instr;
        vlSelfRef.top__DOT__cache__DOT____Vlvbound_h4b79c829__0[1U] 
            = vlSelfRef.top__DOT__cache__DOT__mem_instr;
        vlSelfRef.top__DOT__cache__DOT____Vlvbound_h4b79c829__0[2U] 
            = vlSelfRef.top__DOT__cache__DOT__mem_instr;
        vlSelfRef.top__DOT__cache__DOT____Vlvbound_h4b79c829__0[3U] 
            = vlSelfRef.top__DOT__cache__DOT__mem_instr;
        if ((0x12fU >= ((IData)(2U) + (0x1ffU & ((IData)(0x97U) 
                                                 * (IData)(vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__lru_way)))))) {
            __VdlyVal__top__DOT__cache__DOT__cache_mem__v6[0U] 
                = vlSelfRef.top__DOT__cache__DOT____Vlvbound_h4b79c829__0[0U];
            __VdlyVal__top__DOT__cache__DOT__cache_mem__v6[1U] 
                = vlSelfRef.top__DOT__cache__DOT____Vlvbound_h4b79c829__0[1U];
            __VdlyVal__top__DOT__cache__DOT__cache_mem__v6[2U] 
                = vlSelfRef.top__DOT__cache__DOT____Vlvbound_h4b79c829__0[2U];
            __VdlyVal__top__DOT__cache__DOT__cache_mem__v6[3U] 
                = vlSelfRef.top__DOT__cache__DOT____Vlvbound_h4b79c829__0[3U];
            __VdlyLsb__top__DOT__cache__DOT__cache_mem__v6 
                = ((IData)(2U) + (0x1ffU & ((IData)(0x97U) 
                                            * (IData)(vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__lru_way))));
            __VdlyDim0__top__DOT__cache__DOT__cache_mem__v6 
                = (0xffU & vlSelfRef.top__DOT__pcF);
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v6[0U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[0U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v6[1U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[1U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v6[2U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[2U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v6[3U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[3U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v6[4U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[4U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v6[5U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[5U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v6[6U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[6U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v6[7U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[7U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v6[8U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[8U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v6[9U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[9U];
            __Vtemp_2[0U] = 0xffffffffU;
            __Vtemp_2[1U] = 0xffffffffU;
            __Vtemp_2[2U] = 0xffffffffU;
            __Vtemp_2[3U] = 0xffffffffU;
            VL_ASSIGNSEL_WW(304,128,__VdlyLsb__top__DOT__cache__DOT__cache_mem__v6, __VdlyMask__top__DOT__cache__DOT__cache_mem__v6, __Vtemp_2);
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v6[0U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[0U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v6[1U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[1U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v6[2U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[2U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v6[3U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[3U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v6[4U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[4U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v6[5U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[5U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v6[6U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[6U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v6[7U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[7U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v6[8U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[8U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v6[9U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[9U];
            VL_ASSIGNSEL_WW(304,128,__VdlyLsb__top__DOT__cache__DOT__cache_mem__v6, __VdlyElem__top__DOT__cache__DOT__cache_mem__v6, __VdlyVal__top__DOT__cache__DOT__cache_mem__v6);
            vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.enqueue(__VdlyElem__top__DOT__cache__DOT__cache_mem__v6, __VdlyMask__top__DOT__cache__DOT__cache_mem__v6, (IData)(__VdlyDim0__top__DOT__cache__DOT__cache_mem__v6));
        }
        vlSelfRef.top__DOT__cache__DOT____Vlvbound_ha2ec015c__0 
            = (vlSelfRef.top__DOT__pcF >> 0xaU);
        if ((0x12fU >= ((IData)(0x82U) + (0x1ffU & 
                                          ((IData)(0x97U) 
                                           * (IData)(vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__lru_way)))))) {
            __VdlyVal__top__DOT__cache__DOT__cache_mem__v7 
                = vlSelfRef.top__DOT__cache__DOT____Vlvbound_ha2ec015c__0;
            __VdlyLsb__top__DOT__cache__DOT__cache_mem__v7 
                = ((IData)(0x82U) + (0x1ffU & ((IData)(0x97U) 
                                               * (IData)(vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__lru_way))));
            __VdlyDim0__top__DOT__cache__DOT__cache_mem__v7 
                = (0xffU & vlSelfRef.top__DOT__pcF);
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v7[0U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[0U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v7[1U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[1U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v7[2U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[2U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v7[3U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[3U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v7[4U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[4U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v7[5U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[5U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v7[6U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[6U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v7[7U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[7U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v7[8U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[8U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v7[9U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[9U];
            VL_ASSIGNSEL_WI(304,22,__VdlyLsb__top__DOT__cache__DOT__cache_mem__v7, __VdlyMask__top__DOT__cache__DOT__cache_mem__v7, 0x3fffffU);
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v7[0U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[0U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v7[1U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[1U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v7[2U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[2U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v7[3U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[3U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v7[4U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[4U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v7[5U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[5U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v7[6U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[6U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v7[7U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[7U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v7[8U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[8U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v7[9U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[9U];
            VL_ASSIGNSEL_WI(304,22,__VdlyLsb__top__DOT__cache__DOT__cache_mem__v7, __VdlyElem__top__DOT__cache__DOT__cache_mem__v7, __VdlyVal__top__DOT__cache__DOT__cache_mem__v7);
            vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.enqueue(__VdlyElem__top__DOT__cache__DOT__cache_mem__v7, __VdlyMask__top__DOT__cache__DOT__cache_mem__v7, (IData)(__VdlyDim0__top__DOT__cache__DOT__cache_mem__v7));
        }
        vlSelfRef.top__DOT__cache__DOT____Vlvbound_hbe650bd0__0 = 1U;
        if ((0x12fU >= ((IData)(0x98U) + (0x1ffU & 
                                          ((IData)(0x97U) 
                                           * (IData)(vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__lru_way)))))) {
            __VdlyVal__top__DOT__cache__DOT__cache_mem__v8 
                = vlSelfRef.top__DOT__cache__DOT____Vlvbound_hbe650bd0__0;
            __VdlyLsb__top__DOT__cache__DOT__cache_mem__v8 
                = ((IData)(0x98U) + (0x1ffU & ((IData)(0x97U) 
                                               * (IData)(vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__lru_way))));
            __VdlyDim0__top__DOT__cache__DOT__cache_mem__v8 
                = (0xffU & vlSelfRef.top__DOT__pcF);
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v8[0U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[0U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v8[1U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[1U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v8[2U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[2U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v8[3U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[3U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v8[4U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[4U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v8[5U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[5U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v8[6U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[6U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v8[7U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[7U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v8[8U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[8U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v8[9U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[9U];
            __VdlyMask__top__DOT__cache__DOT__cache_mem__v8[(__VdlyLsb__top__DOT__cache__DOT__cache_mem__v8 
                                                             >> 5U)] 
                = (__VdlyMask__top__DOT__cache__DOT__cache_mem__v8[
                   (__VdlyLsb__top__DOT__cache__DOT__cache_mem__v8 
                    >> 5U)] | ((IData)(1U) << (0x1fU 
                                               & __VdlyLsb__top__DOT__cache__DOT__cache_mem__v8)));
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[0U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[0U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[1U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[1U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[2U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[2U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[3U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[3U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[4U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[4U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[5U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[5U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[6U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[6U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[7U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[7U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[8U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[8U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[9U] 
                = Vtop__ConstPool__CONST_h7c08bc10_0[9U];
            __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[(__VdlyLsb__top__DOT__cache__DOT__cache_mem__v8 
                                                             >> 5U)] 
                = (((~ ((IData)(1U) << (0x1fU & __VdlyLsb__top__DOT__cache__DOT__cache_mem__v8))) 
                    & __VdlyElem__top__DOT__cache__DOT__cache_mem__v8[
                    (__VdlyLsb__top__DOT__cache__DOT__cache_mem__v8 
                     >> 5U)]) | ((IData)(__VdlyVal__top__DOT__cache__DOT__cache_mem__v8) 
                                 << (0x1fU & __VdlyLsb__top__DOT__cache__DOT__cache_mem__v8)));
            vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.enqueue(__VdlyElem__top__DOT__cache__DOT__cache_mem__v8, __VdlyMask__top__DOT__cache__DOT__cache_mem__v8, (IData)(__VdlyDim0__top__DOT__cache__DOT__cache_mem__v8));
        }
        __VdlyDim0__top__DOT__cache__DOT__cache_mem__v9 
            = (0xffU & vlSelfRef.top__DOT__pcF);
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[0U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[0U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[1U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[1U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[2U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[2U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[3U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[3U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[4U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[4U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[5U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[5U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[6U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[6U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[7U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[7U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[8U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[8U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[9U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[9U];
        __VdlyVal__top__DOT__cache__DOT__cache_mem__v9 
            = ((IData)(vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__lru_way)
                ? (1U & ((IData)(1U) + (1U & vlSelfRef.top__DOT__cache__DOT__cache_mem
                                        [(0xffU & vlSelfRef.top__DOT__pcF)][0U])))
                : 0U);
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[0U] 
            = ((0xfffffffeU & __VdlyElem__top__DOT__cache__DOT__cache_mem__v9[0U]) 
               | (IData)(__VdlyVal__top__DOT__cache__DOT__cache_mem__v9));
        vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.enqueue(__VdlyElem__top__DOT__cache__DOT__cache_mem__v9, Vtop__ConstPool__CONST_h2dc653e5_0, (IData)(__VdlyDim0__top__DOT__cache__DOT__cache_mem__v9));
        __VdlyVal__top__DOT__cache__DOT__cache_mem__v10 
            = ((IData)(vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__lru_way)
                ? 0U : (1U & ((IData)(1U) + (1U & (
                                                   vlSelfRef.top__DOT__cache__DOT__cache_mem
                                                   [
                                                   (0xffU 
                                                    & vlSelfRef.top__DOT__pcF)][0U] 
                                                   >> 1U)))));
        __VdlyDim0__top__DOT__cache__DOT__cache_mem__v10 
            = (0xffU & vlSelfRef.top__DOT__pcF);
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[0U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[0U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[1U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[1U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[2U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[2U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[3U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[3U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[4U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[4U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[5U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[5U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[6U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[6U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[7U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[7U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[8U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[8U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[9U] 
            = Vtop__ConstPool__CONST_h7c08bc10_0[9U];
        __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[0U] 
            = ((0xfffffffdU & __VdlyElem__top__DOT__cache__DOT__cache_mem__v10[0U]) 
               | ((IData)(__VdlyVal__top__DOT__cache__DOT__cache_mem__v10) 
                  << 1U));
        vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.enqueue(__VdlyElem__top__DOT__cache__DOT__cache_mem__v10, Vtop__ConstPool__CONST_he1e3be2a_0, (IData)(__VdlyDim0__top__DOT__cache__DOT__cache_mem__v10));
    }
    if (((IData)(vlSelfRef.top__DOT__MemWriteM) & (2U 
                                                   == (IData)(vlSelfRef.top__DOT__LS_modeM)))) {
        __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0 
            = (0xffU & vlSelfRef.top__DOT__WriteDataM);
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0 
            = (0x1ffffU & vlSelfRef.top__DOT__ALUResultM);
        __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0 = 1U;
    } else if (vlSelfRef.top__DOT__MemWriteM) {
        __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1 
            = (0xffU & vlSelfRef.top__DOT__WriteDataM);
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1 
            = (0x1fffcU & vlSelfRef.top__DOT__ALUResultM);
        __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1 = 1U;
        __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v2 
            = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                        >> 8U));
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v2 
            = (1U | (0x1fffcU & vlSelfRef.top__DOT__ALUResultM));
        __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v3 
            = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                        >> 0x10U));
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v3 
            = (2U | (0x1fffcU & vlSelfRef.top__DOT__ALUResultM));
        __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v4 
            = (vlSelfRef.top__DOT__WriteDataM >> 0x18U);
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v4 
            = (3U | (0x1fffcU & vlSelfRef.top__DOT__ALUResultM));
    }
    if (vlSelfRef.top__DOT__MemWriteM) {
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v0 
            = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
        __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v0 = 1U;
        __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v1 
            = (vlSelfRef.top__DOT__ALUResultM >> 5U);
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v1 
            = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
        if ((4U & (IData)(vlSelfRef.top__DOT__LS_modeM))) {
            if (VL_UNLIKELY((2U & (IData)(vlSelfRef.top__DOT__LS_modeM)))) {
                VL_WRITEF_NX("WARNING: Unrecognized LS_mode in cache\n",0);
            } else if ((0U == (3U & vlSelfRef.top__DOT__ALUResultM))) {
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2 
                    = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                                >> 8U));
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
                __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2 = 1U;
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v3 
                    = (0xffU & vlSelfRef.top__DOT__WriteDataM);
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v3 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
            } else if (VL_LIKELY((2U == (3U & vlSelfRef.top__DOT__ALUResultM)))) {
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4 
                    = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                                >> 8U));
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
                __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4 = 1U;
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v5 
                    = (0xffU & vlSelfRef.top__DOT__WriteDataM);
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v5 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
            } else {
                VL_WRITEF_NX("[%0t] %%Error: DataCache.sv:89: Assertion failed in %Ntop.top_memory_inst.data_cache_inst: Misaligned halfword write detected!\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("/home/benja/Documents/iac/lab0-devtools/autumn/workspace/cpu/RISC-V-T15/repo/rtl/DataCache.sv", 89, "");
            }
        } else if ((2U & (IData)(vlSelfRef.top__DOT__LS_modeM))) {
            if ((2U & vlSelfRef.top__DOT__ALUResultM)) {
                if ((1U & vlSelfRef.top__DOT__ALUResultM)) {
                    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6 
                        = (0xffU & vlSelfRef.top__DOT__WriteDataM);
                    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6 
                        = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
                    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6 = 1U;
                } else {
                    __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7 
                        = (0xffU & vlSelfRef.top__DOT__WriteDataM);
                    __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7 
                        = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
                    __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7 = 1U;
                }
            } else if ((1U & vlSelfRef.top__DOT__ALUResultM)) {
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8 
                    = (0xffU & vlSelfRef.top__DOT__WriteDataM);
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
                __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8 = 1U;
            } else {
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9 
                    = (0xffU & vlSelfRef.top__DOT__WriteDataM);
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
                __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9 = 1U;
            }
        } else if (VL_UNLIKELY((1U & (IData)(vlSelfRef.top__DOT__LS_modeM)))) {
            VL_WRITEF_NX("WARNING: Unrecognized LS_mode in cache\n",0);
        } else {
            __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10 
                = (vlSelfRef.top__DOT__WriteDataM >> 0x18U);
            __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10 
                = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
            __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10 = 1U;
            __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v11 
                = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                            >> 0x10U));
            __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v11 
                = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
            __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v12 
                = (0xffU & (vlSelfRef.top__DOT__WriteDataM 
                            >> 8U));
            __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v12 
                = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
            __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v13 
                = (0xffU & vlSelfRef.top__DOT__WriteDataM);
            __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v13 
                = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
        }
    } else if (((IData)(vlSelfRef.top__DOT__MemReadM) 
                & ((~ (IData)((vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                               [vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index] 
                               >> 0x3bU))) | ((0x7ffffffU 
                                               & (IData)(
                                                         (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                                                          [vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index] 
                                                          >> 0x20U))) 
                                              != vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__address_tag)))) {
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v14 
            = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
        __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v14 = 1U;
        __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v15 
            = (vlSelfRef.top__DOT__ALUResultM >> 5U);
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v15 
            = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
        __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v16 
            = (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
               >> 0x18U);
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v16 
            = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
        __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v17 
            = (0xffU & (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
                        >> 0x10U));
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v17 
            = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
        __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v18 
            = (0xffU & (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
                        >> 8U));
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v18 
            = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
        __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v19 
            = (0xffU & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd);
        __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v19 
            = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
    }
    if ((((IData)(vlSelfRef.top__DOT__MemWriteM) & 
          (2U == (6U & (IData)(vlSelfRef.top__DOT__LS_modeM)))) 
         & ((0x7ffffffU & (IData)((vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                                   [vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index] 
                                   >> 0x20U))) != vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__address_tag))) {
        if ((2U & vlSelfRef.top__DOT__ALUResultM)) {
            if ((1U & vlSelfRef.top__DOT__ALUResultM)) {
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20 
                    = (0xffU & (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
                                >> 0x10U));
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
                __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20 = 1U;
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v21 
                    = (0xffU & (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
                                >> 8U));
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v21 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v22 
                    = (0xffU & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd);
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v22 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
            } else {
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23 
                    = (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
                       >> 0x18U);
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
                __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23 = 1U;
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v24 
                    = (0xffU & (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
                                >> 8U));
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v24 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
                __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v25 
                    = (0xffU & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd);
                __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v25 
                    = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
            }
        } else if ((1U & vlSelfRef.top__DOT__ALUResultM)) {
            __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26 
                = (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
                   >> 0x18U);
            __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26 
                = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
            __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26 = 1U;
            __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v27 
                = (0xffU & (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
                            >> 0x10U));
            __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v27 
                = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
            __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v28 
                = (0xffU & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd);
            __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v28 
                = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
        } else {
            __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29 
                = (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
                   >> 0x18U);
            __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29 
                = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
            __VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29 = 1U;
            __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v30 
                = (0xffU & (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
                            >> 0x10U));
            __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v30 
                = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
            __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v31 
                = (0xffU & (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
                            >> 8U));
            __VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v31 
                = vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index;
        }
    }
    vlSelfRef.top__DOT__ALUControlE = vlSelfRef.top__DOT__ALUControlD;
    vlSelfRef.top__DOT__ALUsrcE = vlSelfRef.top__DOT__ALUsrcD;
    vlSelfRef.top__DOT__ImmExtE = vlSelfRef.top__DOT__ImmExtD;
    vlSelfRef.top__DOT__ReadDataW = vlSelfRef.top__DOT__rd;
    vlSelfRef.top__DOT__ResultSrcW = vlSelfRef.top__DOT__ResultSrcM;
    vlSelfRef.top__DOT__pcE = vlSelfRef.top__DOT__pcD;
    vlSelfRef.top__DOT__rd1E = vlSelfRef.top__DOT__registers__DOT__rf
        [(0x1fU & (vlSelfRef.top__DOT__instrD >> 0xfU))];
    vlSelfRef.top__DOT__Rs1E = (0x1fU & (vlSelfRef.top__DOT__instrD 
                                         >> 0xfU));
    vlSelfRef.top__DOT__rd2E = vlSelfRef.top__DOT__registers__DOT__rf
        [(0x1fU & (vlSelfRef.top__DOT__instrD >> 0x14U))];
    vlSelfRef.top__DOT__Rs2E = (0x1fU & (vlSelfRef.top__DOT__instrD 
                                         >> 0x14U));
    vlSelfRef.top__DOT__PCPlus4W = vlSelfRef.top__DOT__PCPlus4M;
    vlSelfRef.top__DOT__PCsrcE = ((IData)(vlSelfRef.top__DOT__Hazard_PCsrc)
                                   ? 0U : (IData)(vlSelfRef.top__DOT__PCsrcD));
    vlSelfRef.__VdlyCommitQueuetop__DOT__cache__DOT__cache_mem.commit(vlSelfRef.top__DOT__cache__DOT__cache_mem);
    vlSelfRef.top__DOT__ALUResultW = vlSelfRef.top__DOT__ALUResultM;
    vlSelfRef.top__DOT__RegWriteW = vlSelfRef.top__DOT__RegWriteM;
    vlSelfRef.top__DOT__RdW = vlSelfRef.top__DOT__RdM;
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0] 
            = __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v0;
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1] 
            = __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v1;
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v2] 
            = __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v2;
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v3] 
            = __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v3;
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v4] 
            = __VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array__v4;
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v0) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v0] 
            = (0x800000000000000ULL | vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
               [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v0]);
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v1] 
            = ((0x8000000ffffffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v1]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v1)) 
                  << 0x20U));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2] 
            = ((0xfffffffffff00ffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v2)) 
                  << 8U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v3] 
            = ((0xfffffffffffff00ULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v3]) 
               | (IData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v3)));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4] 
            = ((0xfffffff00ffffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v4)) 
                  << 0x18U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v5] 
            = ((0xfffffffff00ffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v5]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v5)) 
                  << 0x10U));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6] 
            = ((0xfffffff00ffffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v6)) 
                  << 0x18U));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7] 
            = ((0xfffffffff00ffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v7)) 
                  << 0x10U));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8] 
            = ((0xfffffffffff00ffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v8)) 
                  << 8U));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9] 
            = ((0xfffffffffffff00ULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9]) 
               | (IData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v9)));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10] 
            = ((0xfffffff00ffffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v10)) 
                  << 0x18U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v11] 
            = ((0xfffffffff00ffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v11]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v11)) 
                  << 0x10U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v12] 
            = ((0xfffffffffff00ffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v12]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v12)) 
                  << 8U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v13] 
            = ((0xfffffffffffff00ULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v13]) 
               | (IData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v13)));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v14) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v14] 
            = (0x800000000000000ULL | vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
               [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v14]);
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v15] 
            = ((0x8000000ffffffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v15]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v15)) 
                  << 0x20U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v16] 
            = ((0xfffffff00ffffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v16]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v16)) 
                  << 0x18U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v17] 
            = ((0xfffffffff00ffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v17]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v17)) 
                  << 0x10U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v18] 
            = ((0xfffffffffff00ffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v18]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v18)) 
                  << 8U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v19] 
            = ((0xfffffffffffff00ULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v19]) 
               | (IData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v19)));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20] 
            = ((0xfffffffff00ffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v20)) 
                  << 0x10U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v21] 
            = ((0xfffffffffff00ffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v21]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v21)) 
                  << 8U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v22] 
            = ((0xfffffffffffff00ULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v22]) 
               | (IData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v22)));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23] 
            = ((0xfffffff00ffffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v23)) 
                  << 0x18U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v24] 
            = ((0xfffffffffff00ffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v24]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v24)) 
                  << 8U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v25] 
            = ((0xfffffffffffff00ULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v25]) 
               | (IData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v25)));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26] 
            = ((0xfffffff00ffffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v26)) 
                  << 0x18U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v27] 
            = ((0xfffffffff00ffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v27]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v27)) 
                  << 0x10U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v28] 
            = ((0xfffffffffffff00ULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v28]) 
               | (IData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v28)));
    }
    if (__VdlySet__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29) {
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29] 
            = ((0xfffffff00ffffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v29)) 
                  << 0x18U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v30] 
            = ((0xfffffffff00ffffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v30]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v30)) 
                  << 0x10U));
        vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem[__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v31] 
            = ((0xfffffffffff00ffULL & vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                [__VdlyDim0__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v31]) 
               | ((QData)((IData)(__VdlyVal__top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem__v31)) 
                  << 8U));
    }
    vlSelfRef.top__DOT__WriteDataM = vlSelfRef.top__DOT__WriteDataE;
    vlSelfRef.top__DOT__MemReadM = vlSelfRef.top__DOT__MemReadE;
    vlSelfRef.top__DOT__MemWriteM = vlSelfRef.top__DOT__MemWriteE;
    vlSelfRef.top__DOT__LS_modeM = vlSelfRef.top__DOT__LS_modeE;
    vlSelfRef.top__DOT__ResultSrcM = vlSelfRef.top__DOT__ResultSrcE;
    vlSelfRef.top__DOT____Vcellinp__pc_counter__PCTargetE 
        = (vlSelfRef.top__DOT__ImmExtE + vlSelfRef.top__DOT__pcE);
    vlSelfRef.top__DOT__PCPlus4M = vlSelfRef.top__DOT__PCPlus4E;
    if ((1U & (~ (IData)(vlSelfRef.top__DOT__StallD)))) {
        vlSelfRef.top__DOT__pcD = vlSelfRef.top__DOT__pcF;
    }
    if ((0U == (IData)(vlSelfRef.top__DOT__ResultSrcW))) {
        vlSelfRef.top__DOT__ResultW = vlSelfRef.top__DOT__ALUResultW;
    } else if ((1U == (IData)(vlSelfRef.top__DOT__ResultSrcW))) {
        vlSelfRef.top__DOT__ResultW = vlSelfRef.top__DOT__ReadDataW;
    } else if (VL_LIKELY((2U == (IData)(vlSelfRef.top__DOT__ResultSrcW)))) {
        vlSelfRef.top__DOT__ResultW = vlSelfRef.top__DOT__PCPlus4W;
    } else {
        VL_WRITEF_NX("Invalid ResultSrc\n",0);
    }
    vlSelfRef.top__DOT__ALUResultM = vlSelfRef.top__DOT__ALUResult;
    vlSelfRef.top__DOT__RegWriteM = vlSelfRef.top__DOT__RegWriteE;
    vlSelfRef.top__DOT__RdM = vlSelfRef.top__DOT__RdE;
    vlSelfRef.top__DOT__MemReadE = vlSelfRef.top__DOT__MemReadD;
    vlSelfRef.top__DOT__MemWriteE = ((1U & (~ (IData)(vlSelfRef.top__DOT__Hazard_PCsrc))) 
                                     && (IData)(vlSelfRef.top__DOT__MemWriteD));
    vlSelfRef.top__DOT__LS_modeE = vlSelfRef.top__DOT__LS_modeD;
    vlSelfRef.top__DOT__ResultSrcE = vlSelfRef.top__DOT__ResultSrcD;
    vlSelfRef.top__DOT__PCPlus4E = vlSelfRef.top__DOT__PCPlus4D;
    vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd 
        = (((vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array
             [(3U | (0x1fffcU & vlSelfRef.top__DOT__ALUResultM))] 
             << 0x18U) | (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array
                          [(2U | (0x1fffcU & vlSelfRef.top__DOT__ALUResultM))] 
                          << 0x10U)) | ((vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array
                                         [(1U | (0x1fffcU 
                                                 & vlSelfRef.top__DOT__ALUResultM))] 
                                         << 8U) | vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__data_memory__DOT__array
                                        [(0x1fffcU 
                                          & vlSelfRef.top__DOT__ALUResultM)]));
    vlSelfRef.top__DOT__RegWriteE = ((1U & (~ (IData)(vlSelfRef.top__DOT__Hazard_PCsrc))) 
                                     && (IData)(vlSelfRef.top__DOT__RegWriteD));
    vlSelfRef.top__DOT__ForwardAE = (((((IData)(vlSelfRef.top__DOT__Rs1E) 
                                        == (IData)(vlSelfRef.top__DOT__RdM)) 
                                       & (IData)(vlSelfRef.top__DOT__RegWriteM)) 
                                      & (0U != (IData)(vlSelfRef.top__DOT__Rs1E)))
                                      ? 2U : (((((IData)(vlSelfRef.top__DOT__Rs1E) 
                                                 == (IData)(vlSelfRef.top__DOT__RdW)) 
                                                & (IData)(vlSelfRef.top__DOT__RegWriteW)) 
                                               & (0U 
                                                  != (IData)(vlSelfRef.top__DOT__Rs1E)))
                                               ? 1U
                                               : 0U));
    vlSelfRef.top__DOT__ForwardBE = (((((IData)(vlSelfRef.top__DOT__Rs2E) 
                                        == (IData)(vlSelfRef.top__DOT__RdM)) 
                                       & (IData)(vlSelfRef.top__DOT__RegWriteM)) 
                                      & (0U != (IData)(vlSelfRef.top__DOT__Rs2E)))
                                      ? 2U : (((((IData)(vlSelfRef.top__DOT__Rs2E) 
                                                 == (IData)(vlSelfRef.top__DOT__RdW)) 
                                                & (IData)(vlSelfRef.top__DOT__RegWriteW)) 
                                               & (0U 
                                                  != (IData)(vlSelfRef.top__DOT__Rs2E)))
                                               ? 1U
                                               : 0U));
    vlSelfRef.top__DOT__RdE = (0x1fU & (vlSelfRef.top__DOT__instrD 
                                        >> 7U));
    vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__address_tag 
        = (vlSelfRef.top__DOT__ALUResultM >> 5U);
    vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index 
        = (7U & (vlSelfRef.top__DOT__ALUResultM >> 2U));
    vlSelfRef.top__DOT__top_memory_inst__DOT__rd_cache 
        = (((IData)((vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                     [vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index] 
                     >> 0x3bU)) & ((0x7ffffffU & (IData)(
                                                         (vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                                                          [vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index] 
                                                          >> 0x20U))) 
                                   == vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__address_tag))
            ? (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                      [vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index])
            : vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd);
    if ((0U == (IData)(vlSelfRef.top__DOT__ForwardAE))) {
        vlSelfRef.top__DOT__SrcAE = vlSelfRef.top__DOT__rd1E;
    } else if ((1U == (IData)(vlSelfRef.top__DOT__ForwardAE))) {
        vlSelfRef.top__DOT__SrcAE = vlSelfRef.top__DOT__ResultW;
    } else if (VL_LIKELY((2U == (IData)(vlSelfRef.top__DOT__ForwardAE)))) {
        vlSelfRef.top__DOT__SrcAE = vlSelfRef.top__DOT__ALUResultM;
    } else {
        VL_WRITEF_NX("Invalid ResultSrc\n",0);
    }
    if ((0U == (IData)(vlSelfRef.top__DOT__ForwardBE))) {
        vlSelfRef.top__DOT__WriteDataE = vlSelfRef.top__DOT__rd2E;
    } else if ((1U == (IData)(vlSelfRef.top__DOT__ForwardBE))) {
        vlSelfRef.top__DOT__WriteDataE = vlSelfRef.top__DOT__ResultW;
    } else if (VL_LIKELY((2U == (IData)(vlSelfRef.top__DOT__ForwardBE)))) {
        vlSelfRef.top__DOT__WriteDataE = vlSelfRef.top__DOT__ALUResultM;
    } else {
        VL_WRITEF_NX("Invalid ResultSrc\n",0);
    }
    vlSelfRef.top__DOT__top_memory_inst__DOT__byte3 
        = (vlSelfRef.top__DOT__top_memory_inst__DOT__rd_cache 
           >> 0x18U);
    vlSelfRef.top__DOT__top_memory_inst__DOT__byte2 
        = (0xffU & (vlSelfRef.top__DOT__top_memory_inst__DOT__rd_cache 
                    >> 0x10U));
    vlSelfRef.top__DOT__top_memory_inst__DOT__byte1 
        = (0xffU & (vlSelfRef.top__DOT__top_memory_inst__DOT__rd_cache 
                    >> 8U));
    vlSelfRef.top__DOT__top_memory_inst__DOT__byte0 
        = (0xffU & vlSelfRef.top__DOT__top_memory_inst__DOT__rd_cache);
    if ((1U & (~ (IData)(vlSelfRef.top__DOT__StallD)))) {
        vlSelfRef.top__DOT__PCPlus4D = ((IData)(4U) 
                                        + vlSelfRef.top__DOT__pcF);
    }
    if ((4U & (IData)(vlSelfRef.top__DOT__LS_modeM))) {
        if (VL_UNLIKELY((2U & (IData)(vlSelfRef.top__DOT__LS_modeM)))) {
            VL_WRITEF_NX("WARNING: unrecognised LS_mode in cached_memory\n",0);
        } else if ((1U & (IData)(vlSelfRef.top__DOT__LS_modeM))) {
            if ((0U == (3U & vlSelfRef.top__DOT__ALUResultM))) {
                vlSelfRef.top__DOT__rd = (((- (IData)(
                                                      (1U 
                                                       & (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte1)))) 
                                           << 0x10U) 
                                          | (((IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte1) 
                                              << 8U) 
                                             | (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte0)));
            } else if (VL_LIKELY((2U == (3U & vlSelfRef.top__DOT__ALUResultM)))) {
                vlSelfRef.top__DOT__rd = (((IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte3) 
                                           << 8U) | (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte2));
            } else {
                VL_WRITEF_NX("[%0t] %%Error: top_mem.sv:87: Assertion failed in %Ntop.top_memory_inst: WARNING: Misaligned halfword write detected\n",0,
                             64,VL_TIME_UNITED_Q(1),
                             -12,vlSymsp->name());
                VL_STOP_MT("/home/benja/Documents/iac/lab0-devtools/autumn/workspace/cpu/RISC-V-T15/repo/rtl/top_mem.sv", 87, "");
            }
        } else if ((0U == (3U & vlSelfRef.top__DOT__ALUResultM))) {
            vlSelfRef.top__DOT__rd = (((- (IData)((1U 
                                                   & ((IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte1) 
                                                      >> 7U)))) 
                                       << 0x10U) | 
                                      (((IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte1) 
                                        << 8U) | (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte0)));
        } else if (VL_LIKELY((2U == (3U & vlSelfRef.top__DOT__ALUResultM)))) {
            vlSelfRef.top__DOT__rd = (((- (IData)((1U 
                                                   & ((IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte3) 
                                                      >> 7U)))) 
                                       << 0x10U) | 
                                      (((IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte3) 
                                        << 8U) | (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte2)));
        } else {
            VL_WRITEF_NX("[%0t] %%Error: top_mem.sv:56: Assertion failed in %Ntop.top_memory_inst: Misaligned halfword write detected!\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name());
            VL_STOP_MT("/home/benja/Documents/iac/lab0-devtools/autumn/workspace/cpu/RISC-V-T15/repo/rtl/top_mem.sv", 56, "");
        }
    } else if ((2U & (IData)(vlSelfRef.top__DOT__LS_modeM))) {
        vlSelfRef.top__DOT__rd = ((1U & (IData)(vlSelfRef.top__DOT__LS_modeM))
                                   ? ((2U & vlSelfRef.top__DOT__ALUResultM)
                                       ? ((1U & vlSelfRef.top__DOT__ALUResultM)
                                           ? (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte3)
                                           : (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte2))
                                       : ((1U & vlSelfRef.top__DOT__ALUResultM)
                                           ? (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte1)
                                           : (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte0)))
                                   : ((2U & vlSelfRef.top__DOT__ALUResultM)
                                       ? ((1U & vlSelfRef.top__DOT__ALUResultM)
                                           ? (((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte3) 
                                                              >> 7U)))) 
                                               << 8U) 
                                              | (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte3))
                                           : (((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte2) 
                                                              >> 7U)))) 
                                               << 8U) 
                                              | (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte2)))
                                       : ((1U & vlSelfRef.top__DOT__ALUResultM)
                                           ? (((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte1) 
                                                              >> 7U)))) 
                                               << 8U) 
                                              | (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte1))
                                           : (((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte0) 
                                                              >> 7U)))) 
                                               << 8U) 
                                              | (IData)(vlSelfRef.top__DOT__top_memory_inst__DOT__byte0)))));
    } else if (VL_UNLIKELY((1U & (IData)(vlSelfRef.top__DOT__LS_modeM)))) {
        VL_WRITEF_NX("WARNING: unrecognised LS_mode in cached_memory\n",0);
    } else {
        vlSelfRef.top__DOT__rd = vlSelfRef.top__DOT__top_memory_inst__DOT__rd_cache;
    }
    if ((1U & (~ (IData)(vlSelfRef.top__DOT__StallD)))) {
        vlSelfRef.top__DOT__instrD = vlSelfRef.top__DOT__instr;
    }
    if (vlSelfRef.top__DOT__Hazard_PCsrc) {
        vlSelfRef.top__DOT__instrD = 0x13U;
    }
    vlSelfRef.top__DOT__SrcBE = ((IData)(vlSelfRef.top__DOT__ALUsrcE)
                                  ? vlSelfRef.top__DOT__ImmExtE
                                  : vlSelfRef.top__DOT__WriteDataE);
    vlSelfRef.top__DOT__ALUResult = ((8U & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                      ? ((4U & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                          ? 0U : ((2U 
                                                   & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                    ? 0U
                                                    : vlSelfRef.top__DOT__SrcBE)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                    ? 
                                                   ((vlSelfRef.top__DOT__SrcAE 
                                                     < vlSelfRef.top__DOT__SrcBE)
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   (VL_LTS_III(32, vlSelfRef.top__DOT__SrcAE, vlSelfRef.top__DOT__SrcBE)
                                                     ? 1U
                                                     : 0U))))
                                      : ((4U & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                          ? ((2U & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                              ? ((1U 
                                                  & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                  ? 
                                                 VL_SHIFTRS_III(32,32,32, vlSelfRef.top__DOT__SrcAE, vlSelfRef.top__DOT__SrcBE)
                                                  : 
                                                 VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__SrcAE, vlSelfRef.top__DOT__SrcBE))
                                              : ((1U 
                                                  & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                  ? 
                                                 VL_SHIFTL_III(32,32,32, vlSelfRef.top__DOT__SrcAE, vlSelfRef.top__DOT__SrcBE)
                                                  : 
                                                 (vlSelfRef.top__DOT__SrcAE 
                                                  ^ vlSelfRef.top__DOT__SrcBE)))
                                          : ((2U & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                              ? ((1U 
                                                  & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                  ? 
                                                 (vlSelfRef.top__DOT__SrcAE 
                                                  | vlSelfRef.top__DOT__SrcBE)
                                                  : 
                                                 (vlSelfRef.top__DOT__SrcAE 
                                                  & vlSelfRef.top__DOT__SrcBE))
                                              : ((1U 
                                                  & (IData)(vlSelfRef.top__DOT__ALUControlE))
                                                  ? 
                                                 (vlSelfRef.top__DOT__SrcAE 
                                                  - vlSelfRef.top__DOT__SrcBE)
                                                  : 
                                                 (vlSelfRef.top__DOT__SrcAE 
                                                  + vlSelfRef.top__DOT__SrcBE)))));
    vlSelfRef.top__DOT__eq = ((0U == vlSelfRef.top__DOT__ALUResult)
                               ? 1U : 0U);
    if ((1U & (~ (IData)(vlSelfRef.top__DOT__StallF)))) {
        vlSelfRef.top__DOT__pcF = ((IData)(vlSelfRef.rst)
                                    ? 0U : vlSelfRef.top__DOT__next_pc);
    }
    vlSelfRef.top__DOT__hazard_unit___DOT__lwStall 
        = ((IData)(vlSelfRef.top__DOT__ResultSrcE) 
           & (((0x1fU & (vlSelfRef.top__DOT__instrD 
                         >> 0xfU)) == (IData)(vlSelfRef.top__DOT__RdE)) 
              | ((0x1fU & (vlSelfRef.top__DOT__instrD 
                           >> 0x14U)) == (IData)(vlSelfRef.top__DOT__RdE))));
    vlSelfRef.top__DOT__StallF = vlSelfRef.top__DOT__hazard_unit___DOT__lwStall;
    vlSelfRef.top__DOT__StallD = vlSelfRef.top__DOT__hazard_unit___DOT__lwStall;
    vlSelfRef.top__DOT__PCsrcD = 0U;
    vlSelfRef.top__DOT__ResultSrcD = 0U;
    vlSelfRef.top__DOT__MemWriteD = 0U;
    vlSelfRef.top__DOT__ALUControlD = 0U;
    vlSelfRef.top__DOT__ALUsrcD = 0U;
    vlSelfRef.top__DOT__ImmSrcD = 0U;
    vlSelfRef.top__DOT__RegWriteD = 0U;
    vlSelfRef.top__DOT__LS_modeD = 0U;
    vlSelfRef.top__DOT__MemReadD = 0U;
    if ((0x40U & vlSelfRef.top__DOT__instrD)) {
        if ((0x20U & vlSelfRef.top__DOT__instrD)) {
            if ((0x10U & vlSelfRef.top__DOT__instrD)) {
                vlSelfRef.top__DOT__PCsrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUControlD = 0U;
                vlSelfRef.top__DOT__ALUsrcD = 0U;
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 0U;
                vlSelfRef.top__DOT__LS_modeD = 0U;
            } else if ((8U & vlSelfRef.top__DOT__instrD)) {
                if ((4U & vlSelfRef.top__DOT__instrD)) {
                    if ((2U & vlSelfRef.top__DOT__instrD)) {
                        if ((1U & vlSelfRef.top__DOT__instrD)) {
                            vlSelfRef.top__DOT__ImmSrcD = 4U;
                            vlSelfRef.top__DOT__PCsrcD = 3U;
                            vlSelfRef.top__DOT__ALUsrcD = 1U;
                            vlSelfRef.top__DOT__RegWriteD = 1U;
                            vlSelfRef.top__DOT__ResultSrcD = 2U;
                        } else {
                            vlSelfRef.top__DOT__PCsrcD = 0U;
                            vlSelfRef.top__DOT__ResultSrcD = 0U;
                            vlSelfRef.top__DOT__MemWriteD = 0U;
                            vlSelfRef.top__DOT__ALUControlD = 0U;
                            vlSelfRef.top__DOT__ALUsrcD = 0U;
                            vlSelfRef.top__DOT__ImmSrcD = 0U;
                            vlSelfRef.top__DOT__RegWriteD = 0U;
                            vlSelfRef.top__DOT__LS_modeD = 0U;
                        }
                    } else {
                        vlSelfRef.top__DOT__PCsrcD = 0U;
                        vlSelfRef.top__DOT__ResultSrcD = 0U;
                        vlSelfRef.top__DOT__MemWriteD = 0U;
                        vlSelfRef.top__DOT__ALUControlD = 0U;
                        vlSelfRef.top__DOT__ALUsrcD = 0U;
                        vlSelfRef.top__DOT__ImmSrcD = 0U;
                        vlSelfRef.top__DOT__RegWriteD = 0U;
                        vlSelfRef.top__DOT__LS_modeD = 0U;
                    }
                } else {
                    vlSelfRef.top__DOT__PCsrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUControlD = 0U;
                    vlSelfRef.top__DOT__ALUsrcD = 0U;
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__LS_modeD = 0U;
                }
            } else if ((4U & vlSelfRef.top__DOT__instrD)) {
                if ((2U & vlSelfRef.top__DOT__instrD)) {
                    if ((1U & vlSelfRef.top__DOT__instrD)) {
                        vlSelfRef.top__DOT__ImmSrcD = 0U;
                        vlSelfRef.top__DOT__ALUControlD = 0U;
                        vlSelfRef.top__DOT__PCsrcD = 4U;
                        vlSelfRef.top__DOT__ALUsrcD = 1U;
                        vlSelfRef.top__DOT__RegWriteD = 1U;
                        vlSelfRef.top__DOT__ResultSrcD = 2U;
                    } else {
                        vlSelfRef.top__DOT__PCsrcD = 0U;
                        vlSelfRef.top__DOT__ResultSrcD = 0U;
                        vlSelfRef.top__DOT__MemWriteD = 0U;
                        vlSelfRef.top__DOT__ALUControlD = 0U;
                        vlSelfRef.top__DOT__ALUsrcD = 0U;
                        vlSelfRef.top__DOT__ImmSrcD = 0U;
                        vlSelfRef.top__DOT__RegWriteD = 0U;
                        vlSelfRef.top__DOT__LS_modeD = 0U;
                    }
                } else {
                    vlSelfRef.top__DOT__PCsrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUControlD = 0U;
                    vlSelfRef.top__DOT__ALUsrcD = 0U;
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__LS_modeD = 0U;
                }
            } else if ((2U & vlSelfRef.top__DOT__instrD)) {
                if ((1U & vlSelfRef.top__DOT__instrD)) {
                    vlSelfRef.top__DOT__ImmSrcD = 2U;
                    vlSelfRef.top__DOT__ALUsrcD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    if ((0x4000U & vlSelfRef.top__DOT__instrD)) {
                        if ((0x2000U & vlSelfRef.top__DOT__instrD)) {
                            if ((0x1000U & vlSelfRef.top__DOT__instrD)) {
                                vlSelfRef.top__DOT__ALUControlD = 9U;
                                vlSelfRef.top__DOT__PCsrcD = 1U;
                            } else {
                                vlSelfRef.top__DOT__ALUControlD = 9U;
                                vlSelfRef.top__DOT__PCsrcD = 2U;
                            }
                        } else if ((0x1000U & vlSelfRef.top__DOT__instrD)) {
                            vlSelfRef.top__DOT__ALUControlD = 8U;
                            vlSelfRef.top__DOT__PCsrcD = 1U;
                        } else {
                            vlSelfRef.top__DOT__ALUControlD = 8U;
                            vlSelfRef.top__DOT__PCsrcD = 2U;
                        }
                    } else if (VL_UNLIKELY((0x2000U 
                                            & vlSelfRef.top__DOT__instrD))) {
                        VL_WRITEF_NX("Warning: Unrecognized B-type instruction\n",0);
                    } else if ((0x1000U & vlSelfRef.top__DOT__instrD)) {
                        vlSelfRef.top__DOT__ALUControlD = 1U;
                        vlSelfRef.top__DOT__PCsrcD = 2U;
                    } else {
                        vlSelfRef.top__DOT__ALUControlD = 1U;
                        vlSelfRef.top__DOT__PCsrcD = 1U;
                    }
                } else {
                    vlSelfRef.top__DOT__PCsrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUControlD = 0U;
                    vlSelfRef.top__DOT__ALUsrcD = 0U;
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__LS_modeD = 0U;
                }
            } else {
                vlSelfRef.top__DOT__PCsrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUControlD = 0U;
                vlSelfRef.top__DOT__ALUsrcD = 0U;
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 0U;
                vlSelfRef.top__DOT__LS_modeD = 0U;
            }
        } else {
            vlSelfRef.top__DOT__PCsrcD = 0U;
            vlSelfRef.top__DOT__ResultSrcD = 0U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__ALUControlD = 0U;
            vlSelfRef.top__DOT__ALUsrcD = 0U;
            vlSelfRef.top__DOT__ImmSrcD = 0U;
            vlSelfRef.top__DOT__RegWriteD = 0U;
            vlSelfRef.top__DOT__LS_modeD = 0U;
        }
    } else if ((0x20U & vlSelfRef.top__DOT__instrD)) {
        if ((0x10U & vlSelfRef.top__DOT__instrD)) {
            if ((8U & vlSelfRef.top__DOT__instrD)) {
                vlSelfRef.top__DOT__PCsrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUControlD = 0U;
                vlSelfRef.top__DOT__ALUsrcD = 0U;
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 0U;
                vlSelfRef.top__DOT__LS_modeD = 0U;
            } else if ((4U & vlSelfRef.top__DOT__instrD)) {
                if ((2U & vlSelfRef.top__DOT__instrD)) {
                    if ((1U & vlSelfRef.top__DOT__instrD)) {
                        vlSelfRef.top__DOT__ImmSrcD = 3U;
                        vlSelfRef.top__DOT__ALUControlD = 0xaU;
                        vlSelfRef.top__DOT__RegWriteD = 1U;
                        vlSelfRef.top__DOT__ALUsrcD = 1U;
                    } else {
                        vlSelfRef.top__DOT__PCsrcD = 0U;
                        vlSelfRef.top__DOT__ResultSrcD = 0U;
                        vlSelfRef.top__DOT__MemWriteD = 0U;
                        vlSelfRef.top__DOT__ALUControlD = 0U;
                        vlSelfRef.top__DOT__ALUsrcD = 0U;
                        vlSelfRef.top__DOT__ImmSrcD = 0U;
                        vlSelfRef.top__DOT__RegWriteD = 0U;
                        vlSelfRef.top__DOT__LS_modeD = 0U;
                    }
                } else {
                    vlSelfRef.top__DOT__PCsrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUControlD = 0U;
                    vlSelfRef.top__DOT__ALUsrcD = 0U;
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__LS_modeD = 0U;
                }
            } else if ((2U & vlSelfRef.top__DOT__instrD)) {
                if ((1U & vlSelfRef.top__DOT__instrD)) {
                    vlSelfRef.top__DOT__ALUsrcD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 1U;
                    if ((0x4000U & vlSelfRef.top__DOT__instrD)) {
                        if ((0x2000U & vlSelfRef.top__DOT__instrD)) {
                            vlSelfRef.top__DOT__ALUControlD 
                                = ((0x1000U & vlSelfRef.top__DOT__instrD)
                                    ? 2U : 3U);
                        } else if ((0x1000U & vlSelfRef.top__DOT__instrD)) {
                            if ((0U == (vlSelfRef.top__DOT__instrD 
                                        >> 0x19U))) {
                                vlSelfRef.top__DOT__ALUControlD = 6U;
                            } else if (VL_LIKELY((0x20U 
                                                  == 
                                                  (vlSelfRef.top__DOT__instrD 
                                                   >> 0x19U)))) {
                                vlSelfRef.top__DOT__ALUControlD = 7U;
                            } else {
                                VL_WRITEF_NX("Warning: Undefined R-Type right shift instruction\n",0);
                            }
                        } else {
                            vlSelfRef.top__DOT__ALUControlD = 4U;
                        }
                    } else if ((0x2000U & vlSelfRef.top__DOT__instrD)) {
                        vlSelfRef.top__DOT__ALUControlD 
                            = ((0x1000U & vlSelfRef.top__DOT__instrD)
                                ? 9U : 8U);
                    } else if ((0x1000U & vlSelfRef.top__DOT__instrD)) {
                        vlSelfRef.top__DOT__ALUControlD = 5U;
                    } else if ((0U == (vlSelfRef.top__DOT__instrD 
                                       >> 0x19U))) {
                        vlSelfRef.top__DOT__ALUControlD = 0U;
                    } else if (VL_LIKELY((0x20U == 
                                          (vlSelfRef.top__DOT__instrD 
                                           >> 0x19U)))) {
                        vlSelfRef.top__DOT__ALUControlD = 1U;
                    } else {
                        VL_WRITEF_NX("Warning: Undefined R-Type instruction\n",0);
                    }
                } else {
                    vlSelfRef.top__DOT__PCsrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUControlD = 0U;
                    vlSelfRef.top__DOT__ALUsrcD = 0U;
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__LS_modeD = 0U;
                }
            } else {
                vlSelfRef.top__DOT__PCsrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUControlD = 0U;
                vlSelfRef.top__DOT__ALUsrcD = 0U;
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 0U;
                vlSelfRef.top__DOT__LS_modeD = 0U;
            }
        } else if ((8U & vlSelfRef.top__DOT__instrD)) {
            vlSelfRef.top__DOT__PCsrcD = 0U;
            vlSelfRef.top__DOT__ResultSrcD = 0U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__ALUControlD = 0U;
            vlSelfRef.top__DOT__ALUsrcD = 0U;
            vlSelfRef.top__DOT__ImmSrcD = 0U;
            vlSelfRef.top__DOT__RegWriteD = 0U;
            vlSelfRef.top__DOT__LS_modeD = 0U;
        } else if ((4U & vlSelfRef.top__DOT__instrD)) {
            vlSelfRef.top__DOT__PCsrcD = 0U;
            vlSelfRef.top__DOT__ResultSrcD = 0U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__ALUControlD = 0U;
            vlSelfRef.top__DOT__ALUsrcD = 0U;
            vlSelfRef.top__DOT__ImmSrcD = 0U;
            vlSelfRef.top__DOT__RegWriteD = 0U;
            vlSelfRef.top__DOT__LS_modeD = 0U;
        } else if ((2U & vlSelfRef.top__DOT__instrD)) {
            if ((1U & vlSelfRef.top__DOT__instrD)) {
                vlSelfRef.top__DOT__ALUControlD = 0U;
                vlSelfRef.top__DOT__ImmSrcD = 1U;
                vlSelfRef.top__DOT__ALUsrcD = 1U;
                vlSelfRef.top__DOT__RegWriteD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 1U;
                vlSelfRef.top__DOT__MemReadD = 0U;
                if ((0U == (7U & (vlSelfRef.top__DOT__instrD 
                                  >> 0xcU)))) {
                    vlSelfRef.top__DOT__LS_modeD = 2U;
                } else if ((1U == (7U & (vlSelfRef.top__DOT__instrD 
                                         >> 0xcU)))) {
                    vlSelfRef.top__DOT__LS_modeD = 4U;
                } else if (VL_LIKELY((2U == (7U & (vlSelfRef.top__DOT__instrD 
                                                   >> 0xcU))))) {
                    vlSelfRef.top__DOT__LS_modeD = 0U;
                } else {
                    VL_WRITEF_NX("Warning: Unrecognized S-type instruction\n",0);
                }
            } else {
                vlSelfRef.top__DOT__PCsrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUControlD = 0U;
                vlSelfRef.top__DOT__ALUsrcD = 0U;
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 0U;
                vlSelfRef.top__DOT__LS_modeD = 0U;
            }
        } else {
            vlSelfRef.top__DOT__PCsrcD = 0U;
            vlSelfRef.top__DOT__ResultSrcD = 0U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__ALUControlD = 0U;
            vlSelfRef.top__DOT__ALUsrcD = 0U;
            vlSelfRef.top__DOT__ImmSrcD = 0U;
            vlSelfRef.top__DOT__RegWriteD = 0U;
            vlSelfRef.top__DOT__LS_modeD = 0U;
        }
    } else if ((0x10U & vlSelfRef.top__DOT__instrD)) {
        if ((8U & vlSelfRef.top__DOT__instrD)) {
            vlSelfRef.top__DOT__PCsrcD = 0U;
            vlSelfRef.top__DOT__ResultSrcD = 0U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__ALUControlD = 0U;
            vlSelfRef.top__DOT__ALUsrcD = 0U;
            vlSelfRef.top__DOT__ImmSrcD = 0U;
            vlSelfRef.top__DOT__RegWriteD = 0U;
            vlSelfRef.top__DOT__LS_modeD = 0U;
        } else if ((4U & vlSelfRef.top__DOT__instrD)) {
            if ((2U & vlSelfRef.top__DOT__instrD)) {
                if ((1U & vlSelfRef.top__DOT__instrD)) {
                    vlSelfRef.top__DOT__ImmSrcD = 3U;
                    vlSelfRef.top__DOT__RegWriteD = 1U;
                    vlSelfRef.top__DOT__ALUsrcD = 1U;
                } else {
                    vlSelfRef.top__DOT__PCsrcD = 0U;
                    vlSelfRef.top__DOT__ResultSrcD = 0U;
                    vlSelfRef.top__DOT__MemWriteD = 0U;
                    vlSelfRef.top__DOT__ALUControlD = 0U;
                    vlSelfRef.top__DOT__ALUsrcD = 0U;
                    vlSelfRef.top__DOT__ImmSrcD = 0U;
                    vlSelfRef.top__DOT__RegWriteD = 0U;
                    vlSelfRef.top__DOT__LS_modeD = 0U;
                }
            } else {
                vlSelfRef.top__DOT__PCsrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUControlD = 0U;
                vlSelfRef.top__DOT__ALUsrcD = 0U;
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 0U;
                vlSelfRef.top__DOT__LS_modeD = 0U;
            }
        } else if ((2U & vlSelfRef.top__DOT__instrD)) {
            if ((1U & vlSelfRef.top__DOT__instrD)) {
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 1U;
                vlSelfRef.top__DOT__ALUsrcD = 1U;
                if ((0x4000U & vlSelfRef.top__DOT__instrD)) {
                    if ((0x2000U & vlSelfRef.top__DOT__instrD)) {
                        vlSelfRef.top__DOT__ALUControlD 
                            = ((0x1000U & vlSelfRef.top__DOT__instrD)
                                ? 2U : 3U);
                    } else if ((0x1000U & vlSelfRef.top__DOT__instrD)) {
                        vlSelfRef.top__DOT__ImmSrcD = 5U;
                        if ((0U == (vlSelfRef.top__DOT__instrD 
                                    >> 0x19U))) {
                            vlSelfRef.top__DOT__ALUControlD = 6U;
                        } else if (VL_LIKELY((0x20U 
                                              == (vlSelfRef.top__DOT__instrD 
                                                  >> 0x19U)))) {
                            vlSelfRef.top__DOT__ALUControlD = 7U;
                        } else {
                            VL_WRITEF_NX("Warning: Unrecognized Right-Shift type\n",0);
                        }
                    } else {
                        vlSelfRef.top__DOT__ALUControlD = 4U;
                    }
                } else if ((0x2000U & vlSelfRef.top__DOT__instrD)) {
                    vlSelfRef.top__DOT__ALUControlD 
                        = ((0x1000U & vlSelfRef.top__DOT__instrD)
                            ? 9U : 8U);
                } else if ((0x1000U & vlSelfRef.top__DOT__instrD)) {
                    vlSelfRef.top__DOT__ImmSrcD = 5U;
                    vlSelfRef.top__DOT__ALUControlD = 5U;
                } else {
                    vlSelfRef.top__DOT__ALUControlD = 0U;
                }
            } else {
                vlSelfRef.top__DOT__PCsrcD = 0U;
                vlSelfRef.top__DOT__ResultSrcD = 0U;
                vlSelfRef.top__DOT__MemWriteD = 0U;
                vlSelfRef.top__DOT__ALUControlD = 0U;
                vlSelfRef.top__DOT__ALUsrcD = 0U;
                vlSelfRef.top__DOT__ImmSrcD = 0U;
                vlSelfRef.top__DOT__RegWriteD = 0U;
                vlSelfRef.top__DOT__LS_modeD = 0U;
            }
        } else {
            vlSelfRef.top__DOT__PCsrcD = 0U;
            vlSelfRef.top__DOT__ResultSrcD = 0U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__ALUControlD = 0U;
            vlSelfRef.top__DOT__ALUsrcD = 0U;
            vlSelfRef.top__DOT__ImmSrcD = 0U;
            vlSelfRef.top__DOT__RegWriteD = 0U;
            vlSelfRef.top__DOT__LS_modeD = 0U;
        }
    } else if ((8U & vlSelfRef.top__DOT__instrD)) {
        vlSelfRef.top__DOT__PCsrcD = 0U;
        vlSelfRef.top__DOT__ResultSrcD = 0U;
        vlSelfRef.top__DOT__MemWriteD = 0U;
        vlSelfRef.top__DOT__ALUControlD = 0U;
        vlSelfRef.top__DOT__ALUsrcD = 0U;
        vlSelfRef.top__DOT__ImmSrcD = 0U;
        vlSelfRef.top__DOT__RegWriteD = 0U;
        vlSelfRef.top__DOT__LS_modeD = 0U;
    } else if ((4U & vlSelfRef.top__DOT__instrD)) {
        vlSelfRef.top__DOT__PCsrcD = 0U;
        vlSelfRef.top__DOT__ResultSrcD = 0U;
        vlSelfRef.top__DOT__MemWriteD = 0U;
        vlSelfRef.top__DOT__ALUControlD = 0U;
        vlSelfRef.top__DOT__ALUsrcD = 0U;
        vlSelfRef.top__DOT__ImmSrcD = 0U;
        vlSelfRef.top__DOT__RegWriteD = 0U;
        vlSelfRef.top__DOT__LS_modeD = 0U;
    } else if ((2U & vlSelfRef.top__DOT__instrD)) {
        if ((1U & vlSelfRef.top__DOT__instrD)) {
            vlSelfRef.top__DOT__ALUControlD = 0U;
            vlSelfRef.top__DOT__ImmSrcD = 0U;
            vlSelfRef.top__DOT__ALUsrcD = 1U;
            vlSelfRef.top__DOT__ResultSrcD = 1U;
            vlSelfRef.top__DOT__RegWriteD = 1U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__MemReadD = 1U;
            if ((0x4000U & vlSelfRef.top__DOT__instrD)) {
                if (VL_UNLIKELY((0x2000U & vlSelfRef.top__DOT__instrD))) {
                    VL_WRITEF_NX("Warning: Unrecognized Load I-type instruction\n",0);
                } else {
                    vlSelfRef.top__DOT__LS_modeD = 
                        ((0x1000U & vlSelfRef.top__DOT__instrD)
                          ? 5U : 3U);
                }
            } else if ((0x2000U & vlSelfRef.top__DOT__instrD)) {
                if (VL_UNLIKELY((0x1000U & vlSelfRef.top__DOT__instrD))) {
                    VL_WRITEF_NX("Warning: Unrecognized Load I-type instruction\n",0);
                } else {
                    vlSelfRef.top__DOT__LS_modeD = 0U;
                }
            } else {
                vlSelfRef.top__DOT__LS_modeD = ((0x1000U 
                                                 & vlSelfRef.top__DOT__instrD)
                                                 ? 4U
                                                 : 2U);
            }
        } else {
            vlSelfRef.top__DOT__PCsrcD = 0U;
            vlSelfRef.top__DOT__ResultSrcD = 0U;
            vlSelfRef.top__DOT__MemWriteD = 0U;
            vlSelfRef.top__DOT__ALUControlD = 0U;
            vlSelfRef.top__DOT__ALUsrcD = 0U;
            vlSelfRef.top__DOT__ImmSrcD = 0U;
            vlSelfRef.top__DOT__RegWriteD = 0U;
            vlSelfRef.top__DOT__LS_modeD = 0U;
        }
    } else {
        vlSelfRef.top__DOT__PCsrcD = 0U;
        vlSelfRef.top__DOT__ResultSrcD = 0U;
        vlSelfRef.top__DOT__MemWriteD = 0U;
        vlSelfRef.top__DOT__ALUControlD = 0U;
        vlSelfRef.top__DOT__ALUsrcD = 0U;
        vlSelfRef.top__DOT__ImmSrcD = 0U;
        vlSelfRef.top__DOT__RegWriteD = 0U;
        vlSelfRef.top__DOT__LS_modeD = 0U;
    }
    if (vlSelfRef.top__DOT__StallD) {
        vlSelfRef.top__DOT__MemWriteD = 0U;
        vlSelfRef.top__DOT__RegWriteD = 0U;
    }
    if ((4U & (IData)(vlSelfRef.top__DOT__PCsrcE))) {
        if (VL_UNLIKELY((2U & (IData)(vlSelfRef.top__DOT__PCsrcE)))) {
            vlSelfRef.top__DOT__next_pc = 0U;
            vlSelfRef.top__DOT__Hazard_PCsrc = 0U;
            VL_WRITEF_NX("Unrecognized PCsrcE\n",0);
        } else if (VL_UNLIKELY((1U & (IData)(vlSelfRef.top__DOT__PCsrcE)))) {
            VL_WRITEF_NX("Unrecognized PCsrcE\n",0);
            vlSelfRef.top__DOT__next_pc = 0U;
            vlSelfRef.top__DOT__Hazard_PCsrc = 0U;
        } else {
            vlSelfRef.top__DOT__next_pc = vlSelfRef.top__DOT__ALUResult;
            vlSelfRef.top__DOT__Hazard_PCsrc = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.top__DOT__PCsrcE))) {
        if ((1U & (IData)(vlSelfRef.top__DOT__PCsrcE))) {
            vlSelfRef.top__DOT__next_pc = vlSelfRef.top__DOT____Vcellinp__pc_counter__PCTargetE;
            vlSelfRef.top__DOT__Hazard_PCsrc = 1U;
        } else if (vlSelfRef.top__DOT__eq) {
            vlSelfRef.top__DOT__next_pc = ((IData)(4U) 
                                           + vlSelfRef.top__DOT__pcF);
            vlSelfRef.top__DOT__Hazard_PCsrc = 0U;
        } else {
            vlSelfRef.top__DOT__next_pc = vlSelfRef.top__DOT____Vcellinp__pc_counter__PCTargetE;
            vlSelfRef.top__DOT__Hazard_PCsrc = 1U;
        }
    } else if ((1U & (IData)(vlSelfRef.top__DOT__PCsrcE))) {
        if (vlSelfRef.top__DOT__eq) {
            vlSelfRef.top__DOT__next_pc = vlSelfRef.top__DOT____Vcellinp__pc_counter__PCTargetE;
            vlSelfRef.top__DOT__Hazard_PCsrc = 1U;
        } else {
            vlSelfRef.top__DOT__next_pc = ((IData)(4U) 
                                           + vlSelfRef.top__DOT__pcF);
            vlSelfRef.top__DOT__Hazard_PCsrc = 0U;
        }
    } else {
        vlSelfRef.top__DOT__next_pc = ((IData)(4U) 
                                       + vlSelfRef.top__DOT__pcF);
        vlSelfRef.top__DOT__Hazard_PCsrc = 0U;
    }
    vlSelfRef.top__DOT__cache__DOT__hit_way = 0U;
    if (((vlSelfRef.top__DOT__cache__DOT__cache_mem
          [(0xffU & vlSelfRef.top__DOT__pcF)][4U] >> 0x18U) 
         & ((0x3fffffU & (vlSelfRef.top__DOT__cache__DOT__cache_mem
                          [(0xffU & vlSelfRef.top__DOT__pcF)][4U] 
                          >> 2U)) == (vlSelfRef.top__DOT__pcF 
                                      >> 0xaU)))) {
        vlSelfRef.top__DOT__cache__DOT__hit_way = (1U 
                                                   | (IData)(vlSelfRef.top__DOT__cache__DOT__hit_way));
    }
    vlSelfRef.top__DOT__cache__DOT__mem_instr = (((
                                                   vlSelfRef.top__DOT__cache__DOT__mem_inst__DOT__array
                                                   [
                                                   (0xfffU 
                                                    & ((IData)(3U) 
                                                       + 
                                                       (0xffeU 
                                                        & vlSelfRef.top__DOT__pcF)))] 
                                                   << 0x18U) 
                                                  | (vlSelfRef.top__DOT__cache__DOT__mem_inst__DOT__array
                                                     [
                                                     (0xfffU 
                                                      & ((IData)(2U) 
                                                         + 
                                                         (0xffeU 
                                                          & vlSelfRef.top__DOT__pcF)))] 
                                                     << 0x10U)) 
                                                 | ((vlSelfRef.top__DOT__cache__DOT__mem_inst__DOT__array
                                                     [
                                                     (0xfffU 
                                                      & ((IData)(1U) 
                                                         + 
                                                         (0xffeU 
                                                          & vlSelfRef.top__DOT__pcF)))] 
                                                     << 8U) 
                                                    | vlSelfRef.top__DOT__cache__DOT__mem_inst__DOT__array
                                                    [
                                                    (0xffeU 
                                                     & vlSelfRef.top__DOT__pcF)]));
    vlSelfRef.top__DOT__cache__DOT__hit = 0U;
    if (((vlSelfRef.top__DOT__cache__DOT__cache_mem
          [(0xffU & vlSelfRef.top__DOT__pcF)][4U] >> 0x18U) 
         & ((0x3fffffU & (vlSelfRef.top__DOT__cache__DOT__cache_mem
                          [(0xffU & vlSelfRef.top__DOT__pcF)][4U] 
                          >> 2U)) == (vlSelfRef.top__DOT__pcF 
                                      >> 0xaU)))) {
        vlSelfRef.top__DOT__cache__DOT__hit = 1U;
    }
    if (((vlSelfRef.top__DOT__cache__DOT__cache_mem
          [(0xffU & vlSelfRef.top__DOT__pcF)][9U] >> 0xfU) 
         & ((0x3fffffU & ((vlSelfRef.top__DOT__cache__DOT__cache_mem
                           [(0xffU & vlSelfRef.top__DOT__pcF)][9U] 
                           << 7U) | (vlSelfRef.top__DOT__cache__DOT__cache_mem
                                     [(0xffU & vlSelfRef.top__DOT__pcF)][8U] 
                                     >> 0x19U))) == 
            (vlSelfRef.top__DOT__pcF >> 0xaU)))) {
        vlSelfRef.top__DOT__cache__DOT__hit_way = (2U 
                                                   | (IData)(vlSelfRef.top__DOT__cache__DOT__hit_way));
        vlSelfRef.top__DOT__cache__DOT__hit = 1U;
    }
    vlSelfRef.top__DOT__ImmExtD = ((4U & (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                    ? ((2U & (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                        ? 0U : ((1U 
                                                 & (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                                 ? 
                                                (0x1fU 
                                                 & (vlSelfRef.top__DOT__instrD 
                                                    >> 0x14U))
                                                 : 
                                                (((- (IData)(
                                                             (vlSelfRef.top__DOT__instrD 
                                                              >> 0x1fU))) 
                                                  << 0x14U) 
                                                 | (((0xff000U 
                                                      & vlSelfRef.top__DOT__instrD) 
                                                     | (0x800U 
                                                        & (vlSelfRef.top__DOT__instrD 
                                                           >> 9U))) 
                                                    | ((0x7e0U 
                                                        & (vlSelfRef.top__DOT__instrD 
                                                           >> 0x14U)) 
                                                       | (0x1eU 
                                                          & (vlSelfRef.top__DOT__instrD 
                                                             >> 0x14U)))))))
                                    : ((2U & (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                        ? ((1U & (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                            ? (0xfffff000U 
                                               & vlSelfRef.top__DOT__instrD)
                                            : (((- (IData)(
                                                           (vlSelfRef.top__DOT__instrD 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | ((0x800U 
                                                   & (vlSelfRef.top__DOT__instrD 
                                                      << 4U)) 
                                                  | ((0x7e0U 
                                                      & (vlSelfRef.top__DOT__instrD 
                                                         >> 0x14U)) 
                                                     | (0x1eU 
                                                        & (vlSelfRef.top__DOT__instrD 
                                                           >> 7U))))))
                                        : ((1U & (IData)(vlSelfRef.top__DOT__ImmSrcD))
                                            ? (((- (IData)(
                                                           (vlSelfRef.top__DOT__instrD 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | ((0xfe0U 
                                                   & (vlSelfRef.top__DOT__instrD 
                                                      >> 0x14U)) 
                                                  | (0x1fU 
                                                     & (vlSelfRef.top__DOT__instrD 
                                                        >> 7U))))
                                            : (((- (IData)(
                                                           (vlSelfRef.top__DOT__instrD 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelfRef.top__DOT__instrD 
                                                  >> 0x14U)))));
    vlSelfRef.top__DOT__instr = vlSelfRef.top__DOT__cache__DOT__mem_instr;
    if (vlSelfRef.top__DOT__cache__DOT__hit) {
        vlSelfRef.top__DOT__cache__DOT__unnamedblk3__DOT__i = 2U;
        if ((1U & (IData)(vlSelfRef.top__DOT__cache__DOT__hit_way))) {
            vlSelfRef.top__DOT__instr = ((0x12fU >= 
                                          ((IData)(2U) 
                                           + (0x7fU 
                                              & VL_SHIFTL_III(7,32,32, 
                                                              (3U 
                                                               & vlSelfRef.top__DOT__pcF), 5U))))
                                          ? (((0U == 
                                               (0x1fU 
                                                & ((IData)(2U) 
                                                   + 
                                                   (0x7fU 
                                                    & VL_SHIFTL_III(7,32,32, 
                                                                    (3U 
                                                                     & vlSelfRef.top__DOT__pcF), 5U)))))
                                               ? 0U
                                               : (vlSelfRef.top__DOT__cache__DOT__cache_mem
                                                  [
                                                  (0xffU 
                                                   & vlSelfRef.top__DOT__pcF)][
                                                  (((IData)(0x21U) 
                                                    + 
                                                    (0x7fU 
                                                     & VL_SHIFTL_III(7,32,32, 
                                                                     (3U 
                                                                      & vlSelfRef.top__DOT__pcF), 5U))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(2U) 
                                                       + 
                                                       (0x7fU 
                                                        & VL_SHIFTL_III(7,32,32, 
                                                                        (3U 
                                                                         & vlSelfRef.top__DOT__pcF), 5U))))))) 
                                             | (vlSelfRef.top__DOT__cache__DOT__cache_mem
                                                [(0xffU 
                                                  & vlSelfRef.top__DOT__pcF)][
                                                (((IData)(2U) 
                                                  + 
                                                  (0x7fU 
                                                   & VL_SHIFTL_III(7,32,32, 
                                                                   (3U 
                                                                    & vlSelfRef.top__DOT__pcF), 5U))) 
                                                 >> 5U)] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(2U) 
                                                    + 
                                                    (0x7fU 
                                                     & VL_SHIFTL_III(7,32,32, 
                                                                     (3U 
                                                                      & vlSelfRef.top__DOT__pcF), 5U))))))
                                          : 0U);
        }
        if ((2U & (IData)(vlSelfRef.top__DOT__cache__DOT__hit_way))) {
            vlSelfRef.top__DOT__instr = ((0x12fU >= 
                                          ((IData)(0x99U) 
                                           + (0x7fU 
                                              & VL_SHIFTL_III(7,32,32, 
                                                              (3U 
                                                               & vlSelfRef.top__DOT__pcF), 5U))))
                                          ? (((0U == 
                                               (0x1fU 
                                                & ((IData)(0x99U) 
                                                   + 
                                                   (0x7fU 
                                                    & VL_SHIFTL_III(7,32,32, 
                                                                    (3U 
                                                                     & vlSelfRef.top__DOT__pcF), 5U)))))
                                               ? 0U
                                               : (vlSelfRef.top__DOT__cache__DOT__cache_mem
                                                  [
                                                  (0xffU 
                                                   & vlSelfRef.top__DOT__pcF)][
                                                  (((IData)(0xb8U) 
                                                    + 
                                                    (0x7fU 
                                                     & VL_SHIFTL_III(7,32,32, 
                                                                     (3U 
                                                                      & vlSelfRef.top__DOT__pcF), 5U))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x99U) 
                                                       + 
                                                       (0x7fU 
                                                        & VL_SHIFTL_III(7,32,32, 
                                                                        (3U 
                                                                         & vlSelfRef.top__DOT__pcF), 5U))))))) 
                                             | (vlSelfRef.top__DOT__cache__DOT__cache_mem
                                                [(0xffU 
                                                  & vlSelfRef.top__DOT__pcF)][
                                                (((IData)(0x99U) 
                                                  + 
                                                  (0x7fU 
                                                   & VL_SHIFTL_III(7,32,32, 
                                                                   (3U 
                                                                    & vlSelfRef.top__DOT__pcF), 5U))) 
                                                 >> 5U)] 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(0x99U) 
                                                    + 
                                                    (0x7fU 
                                                     & VL_SHIFTL_III(7,32,32, 
                                                                     (3U 
                                                                      & vlSelfRef.top__DOT__pcF), 5U))))))
                                          : 0U);
        }
    }
}
