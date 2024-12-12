// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.a0 = vlSelfRef.top__DOT__registers__DOT__rf
        [0xaU];
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
    vlSelfRef.top__DOT____Vcellinp__pc_counter__PCTargetE 
        = (vlSelfRef.top__DOT__ImmExtE + vlSelfRef.top__DOT__pcE);
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
    vlSelfRef.top__DOT__hazard_unit___DOT__lwStall 
        = ((IData)(vlSelfRef.top__DOT__ResultSrcE) 
           & (((0x1fU & (vlSelfRef.top__DOT__instrD 
                         >> 0xfU)) == (IData)(vlSelfRef.top__DOT__RdE)) 
              | ((0x1fU & (vlSelfRef.top__DOT__instrD 
                           >> 0x14U)) == (IData)(vlSelfRef.top__DOT__RdE))));
    vlSelfRef.top__DOT__StallF = vlSelfRef.top__DOT__hazard_unit___DOT__lwStall;
    vlSelfRef.top__DOT__StallD = vlSelfRef.top__DOT__hazard_unit___DOT__lwStall;
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
    if ((0U == (IData)(vlSelfRef.top__DOT__ResultSrcW))) {
        vlSelfRef.top__DOT__ResultW = vlSelfRef.top__DOT__ALUResultW;
    } else if ((1U == (IData)(vlSelfRef.top__DOT__ResultSrcW))) {
        vlSelfRef.top__DOT__ResultW = vlSelfRef.top__DOT__ReadDataW;
    } else if (VL_LIKELY((2U == (IData)(vlSelfRef.top__DOT__ResultSrcW)))) {
        vlSelfRef.top__DOT__ResultW = vlSelfRef.top__DOT__PCPlus4W;
    } else {
        VL_WRITEF_NX("Invalid ResultSrc\n",0);
    }
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
}
