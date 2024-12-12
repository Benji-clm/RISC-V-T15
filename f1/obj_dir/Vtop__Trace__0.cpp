// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelfRef.top__DOT__next_pc),32);
        bufp->chgIData(oldp+1,(vlSelfRef.top__DOT__instr),32);
        bufp->chgIData(oldp+2,(vlSelfRef.top__DOT__SrcAE),32);
        bufp->chgIData(oldp+3,(vlSelfRef.top__DOT__WriteDataE),32);
        bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__SrcBE),32);
        bufp->chgBit(oldp+5,(vlSelfRef.top__DOT__eq));
        bufp->chgIData(oldp+6,(vlSelfRef.top__DOT__ALUResult),32);
        bufp->chgIData(oldp+7,(vlSelfRef.top__DOT__pcF),32);
        bufp->chgIData(oldp+8,(((IData)(4U) + vlSelfRef.top__DOT__pcF)),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__instrD),32);
        bufp->chgBit(oldp+10,(vlSelfRef.top__DOT__RegWriteD));
        bufp->chgCData(oldp+11,(vlSelfRef.top__DOT__ResultSrcD),2);
        bufp->chgBit(oldp+12,(vlSelfRef.top__DOT__MemWriteD));
        bufp->chgCData(oldp+13,(vlSelfRef.top__DOT__PCsrcD),3);
        bufp->chgCData(oldp+14,(vlSelfRef.top__DOT__ALUControlD),4);
        bufp->chgBit(oldp+15,(vlSelfRef.top__DOT__ALUsrcD));
        bufp->chgCData(oldp+16,(vlSelfRef.top__DOT__ImmSrcD),3);
        bufp->chgIData(oldp+17,(vlSelfRef.top__DOT__pcD),32);
        bufp->chgCData(oldp+18,((0x1fU & (vlSelfRef.top__DOT__instrD 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+19,((0x1fU & (vlSelfRef.top__DOT__instrD 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+20,((0x1fU & (vlSelfRef.top__DOT__instrD 
                                          >> 7U))),5);
        bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__ImmExtD),32);
        bufp->chgIData(oldp+22,(vlSelfRef.top__DOT__PCPlus4D),32);
        bufp->chgCData(oldp+23,(vlSelfRef.top__DOT__LS_modeD),3);
        bufp->chgBit(oldp+24,(vlSelfRef.top__DOT__RegWriteE));
        bufp->chgCData(oldp+25,(vlSelfRef.top__DOT__ResultSrcE),2);
        bufp->chgBit(oldp+26,(vlSelfRef.top__DOT__MemWriteE));
        bufp->chgCData(oldp+27,(vlSelfRef.top__DOT__PCsrcE),3);
        bufp->chgCData(oldp+28,(vlSelfRef.top__DOT__ALUControlE),4);
        bufp->chgBit(oldp+29,(vlSelfRef.top__DOT__ALUsrcE));
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__rd1E),32);
        bufp->chgIData(oldp+31,(vlSelfRef.top__DOT__rd2E),32);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__pcE),32);
        bufp->chgCData(oldp+33,(vlSelfRef.top__DOT__Rs1E),5);
        bufp->chgCData(oldp+34,(vlSelfRef.top__DOT__Rs2E),5);
        bufp->chgCData(oldp+35,(vlSelfRef.top__DOT__RdE),5);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__ImmExtE),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__PCPlus4E),32);
        bufp->chgCData(oldp+38,(vlSelfRef.top__DOT__LS_modeE),3);
        bufp->chgBit(oldp+39,(vlSelfRef.top__DOT__RegWriteM));
        bufp->chgCData(oldp+40,(vlSelfRef.top__DOT__ResultSrcM),2);
        bufp->chgBit(oldp+41,(vlSelfRef.top__DOT__MemWriteM));
        bufp->chgIData(oldp+42,(vlSelfRef.top__DOT__ALUResultM),32);
        bufp->chgIData(oldp+43,(vlSelfRef.top__DOT__WriteDataM),32);
        bufp->chgCData(oldp+44,(vlSelfRef.top__DOT__RdM),5);
        bufp->chgIData(oldp+45,(vlSelfRef.top__DOT__PCPlus4M),32);
        bufp->chgCData(oldp+46,(vlSelfRef.top__DOT__LS_modeM),3);
        bufp->chgBit(oldp+47,(vlSelfRef.top__DOT__RegWriteW));
        bufp->chgCData(oldp+48,(vlSelfRef.top__DOT__ResultSrcW),2);
        bufp->chgIData(oldp+49,(vlSelfRef.top__DOT__ALUResultW),32);
        bufp->chgIData(oldp+50,(vlSelfRef.top__DOT__ReadDataW),32);
        bufp->chgCData(oldp+51,(vlSelfRef.top__DOT__RdW),5);
        bufp->chgIData(oldp+52,(vlSelfRef.top__DOT__PCPlus4W),32);
        bufp->chgIData(oldp+53,(vlSelfRef.top__DOT__ResultW),32);
        bufp->chgIData(oldp+54,(vlSelfRef.top__DOT__rd),32);
        bufp->chgBit(oldp+55,(vlSelfRef.top__DOT__Hazard_PCsrc));
        bufp->chgBit(oldp+56,(vlSelfRef.top__DOT__StallF));
        bufp->chgBit(oldp+57,(vlSelfRef.top__DOT__StallD));
        bufp->chgCData(oldp+58,(vlSelfRef.top__DOT__ForwardAE),2);
        bufp->chgCData(oldp+59,(vlSelfRef.top__DOT__ForwardBE),2);
        bufp->chgBit(oldp+60,(vlSelfRef.top__DOT__MemReadD));
        bufp->chgBit(oldp+61,(vlSelfRef.top__DOT__MemReadE));
        bufp->chgBit(oldp+62,(vlSelfRef.top__DOT__MemReadM));
        bufp->chgCData(oldp+63,((0x7fU & vlSelfRef.top__DOT__instrD)),7);
        bufp->chgCData(oldp+64,((7U & (vlSelfRef.top__DOT__instrD 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+65,((vlSelfRef.top__DOT__instrD 
                                 >> 0x19U)),7);
        bufp->chgIData(oldp+66,((vlSelfRef.top__DOT__instrD 
                                 >> 7U)),25);
        bufp->chgIData(oldp+67,(vlSelfRef.top__DOT__cache__DOT__mem_instr),32);
        __Vtemp_1[0U] = vlSelfRef.top__DOT__cache__DOT__mem_instr;
        __Vtemp_1[1U] = vlSelfRef.top__DOT__cache__DOT__mem_instr;
        __Vtemp_1[2U] = vlSelfRef.top__DOT__cache__DOT__mem_instr;
        __Vtemp_1[3U] = vlSelfRef.top__DOT__cache__DOT__mem_instr;
        bufp->chgWData(oldp+68,(__Vtemp_1),128);
        bufp->chgIData(oldp+72,((0xfffffffeU & vlSelfRef.top__DOT__pcF)),32);
        bufp->chgCData(oldp+73,((0xffU & vlSelfRef.top__DOT__pcF)),8);
        bufp->chgIData(oldp+74,((vlSelfRef.top__DOT__pcF 
                                 >> 0xaU)),22);
        bufp->chgCData(oldp+75,((3U & vlSelfRef.top__DOT__pcF)),2);
        bufp->chgBit(oldp+76,(vlSelfRef.top__DOT__cache__DOT__hit));
        bufp->chgCData(oldp+77,(vlSelfRef.top__DOT__cache__DOT__hit_way),2);
        bufp->chgIData(oldp+78,(vlSelfRef.top__DOT__cache__DOT__unnamedblk3__DOT__i),32);
        bufp->chgIData(oldp+79,(vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__i),32);
        bufp->chgIData(oldp+80,(vlSelfRef.top__DOT__cache__DOT__unnamedblk4__DOT__unnamedblk5__DOT__j),32);
        bufp->chgBit(oldp+81,(vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__lru_way));
        bufp->chgIData(oldp+82,(vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__unnamedblk7__DOT__i),32);
        bufp->chgIData(oldp+83,(vlSelfRef.top__DOT__cache__DOT__unnamedblk6__DOT__unnamedblk8__DOT__i),32);
        bufp->chgBit(oldp+84,((1U & (IData)(vlSelfRef.top__DOT__ResultSrcE))));
        bufp->chgBit(oldp+85,(vlSelfRef.top__DOT__hazard_unit___DOT__lwStall));
        bufp->chgIData(oldp+86,(vlSelfRef.top__DOT____Vcellinp__pc_counter__PCTargetE),32);
        bufp->chgIData(oldp+87,(vlSelfRef.top__DOT__top_memory_inst__DOT__rd_cache),32);
        bufp->chgCData(oldp+88,(vlSelfRef.top__DOT__top_memory_inst__DOT__byte3),8);
        bufp->chgCData(oldp+89,(vlSelfRef.top__DOT__top_memory_inst__DOT__byte2),8);
        bufp->chgCData(oldp+90,(vlSelfRef.top__DOT__top_memory_inst__DOT__byte1),8);
        bufp->chgCData(oldp+91,(vlSelfRef.top__DOT__top_memory_inst__DOT__byte0),8);
        bufp->chgQData(oldp+92,(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                                [0U]),60);
        bufp->chgQData(oldp+94,(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                                [1U]),60);
        bufp->chgQData(oldp+96,(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                                [2U]),60);
        bufp->chgQData(oldp+98,(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                                [3U]),60);
        bufp->chgQData(oldp+100,(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                                 [4U]),60);
        bufp->chgQData(oldp+102,(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                                 [5U]),60);
        bufp->chgQData(oldp+104,(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                                 [6U]),60);
        bufp->chgQData(oldp+106,(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_mem
                                 [7U]),60);
        bufp->chgIData(oldp+108,(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__temp_rd),32);
        bufp->chgIData(oldp+109,(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__address_tag),27);
        bufp->chgCData(oldp+110,(vlSelfRef.top__DOT__top_memory_inst__DOT__data_cache_inst__DOT__cache_index),3);
        bufp->chgCData(oldp+111,((3U & vlSelfRef.top__DOT__ALUResultM)),2);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+112,(vlSelfRef.top__DOT__registers__DOT__rf[0]),32);
        bufp->chgIData(oldp+113,(vlSelfRef.top__DOT__registers__DOT__rf[1]),32);
        bufp->chgIData(oldp+114,(vlSelfRef.top__DOT__registers__DOT__rf[2]),32);
        bufp->chgIData(oldp+115,(vlSelfRef.top__DOT__registers__DOT__rf[3]),32);
        bufp->chgIData(oldp+116,(vlSelfRef.top__DOT__registers__DOT__rf[4]),32);
        bufp->chgIData(oldp+117,(vlSelfRef.top__DOT__registers__DOT__rf[5]),32);
        bufp->chgIData(oldp+118,(vlSelfRef.top__DOT__registers__DOT__rf[6]),32);
        bufp->chgIData(oldp+119,(vlSelfRef.top__DOT__registers__DOT__rf[7]),32);
        bufp->chgIData(oldp+120,(vlSelfRef.top__DOT__registers__DOT__rf[8]),32);
        bufp->chgIData(oldp+121,(vlSelfRef.top__DOT__registers__DOT__rf[9]),32);
        bufp->chgIData(oldp+122,(vlSelfRef.top__DOT__registers__DOT__rf[10]),32);
        bufp->chgIData(oldp+123,(vlSelfRef.top__DOT__registers__DOT__rf[11]),32);
        bufp->chgIData(oldp+124,(vlSelfRef.top__DOT__registers__DOT__rf[12]),32);
        bufp->chgIData(oldp+125,(vlSelfRef.top__DOT__registers__DOT__rf[13]),32);
        bufp->chgIData(oldp+126,(vlSelfRef.top__DOT__registers__DOT__rf[14]),32);
        bufp->chgIData(oldp+127,(vlSelfRef.top__DOT__registers__DOT__rf[15]),32);
        bufp->chgIData(oldp+128,(vlSelfRef.top__DOT__registers__DOT__rf[16]),32);
        bufp->chgIData(oldp+129,(vlSelfRef.top__DOT__registers__DOT__rf[17]),32);
        bufp->chgIData(oldp+130,(vlSelfRef.top__DOT__registers__DOT__rf[18]),32);
        bufp->chgIData(oldp+131,(vlSelfRef.top__DOT__registers__DOT__rf[19]),32);
        bufp->chgIData(oldp+132,(vlSelfRef.top__DOT__registers__DOT__rf[20]),32);
        bufp->chgIData(oldp+133,(vlSelfRef.top__DOT__registers__DOT__rf[21]),32);
        bufp->chgIData(oldp+134,(vlSelfRef.top__DOT__registers__DOT__rf[22]),32);
        bufp->chgIData(oldp+135,(vlSelfRef.top__DOT__registers__DOT__rf[23]),32);
        bufp->chgIData(oldp+136,(vlSelfRef.top__DOT__registers__DOT__rf[24]),32);
        bufp->chgIData(oldp+137,(vlSelfRef.top__DOT__registers__DOT__rf[25]),32);
        bufp->chgIData(oldp+138,(vlSelfRef.top__DOT__registers__DOT__rf[26]),32);
        bufp->chgIData(oldp+139,(vlSelfRef.top__DOT__registers__DOT__rf[27]),32);
        bufp->chgIData(oldp+140,(vlSelfRef.top__DOT__registers__DOT__rf[28]),32);
        bufp->chgIData(oldp+141,(vlSelfRef.top__DOT__registers__DOT__rf[29]),32);
        bufp->chgIData(oldp+142,(vlSelfRef.top__DOT__registers__DOT__rf[30]),32);
        bufp->chgIData(oldp+143,(vlSelfRef.top__DOT__registers__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+144,(vlSelfRef.clk));
    bufp->chgBit(oldp+145,(vlSelfRef.rst));
    bufp->chgBit(oldp+146,(vlSelfRef.trigger));
    bufp->chgIData(oldp+147,(vlSelfRef.a0),32);
    bufp->chgIData(oldp+148,(vlSelfRef.top__DOT__registers__DOT__rf
                             [(0x1fU & (vlSelfRef.top__DOT__instrD 
                                        >> 0xfU))]),32);
    bufp->chgIData(oldp+149,(vlSelfRef.top__DOT__registers__DOT__rf
                             [(0x1fU & (vlSelfRef.top__DOT__instrD 
                                        >> 0x14U))]),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
