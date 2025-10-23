// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "Vsigdelay__pch.h"
#include "Vsigdelay___024root.h"

VL_ATTR_COLD void Vsigdelay___024root___eval_static(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_static\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

VL_ATTR_COLD void Vsigdelay___024root___eval_initial(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_initial\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vsigdelay___024root___eval_final(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_final\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vsigdelay___024root___eval_settle(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_settle\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsigdelay___024root___dump_triggers__act(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___dump_triggers__act\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsigdelay___024root___dump_triggers__nba(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___dump_triggers__nba\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsigdelay___024root___ctor_var_reset(Vsigdelay___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___ctor_var_reset\n"); );
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10619988472972731121ull);
    vlSelf->rd = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10303652599525973633ull);
    vlSelf->offset = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 10670815542329643570ull);
    vlSelf->mic_signal = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 512805217010965749ull);
    vlSelf->delayed_signal = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16339064174763787571ull);
    vlSelf->sigdelay__DOT__wr_addr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 10316947102489514696ull);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->sigdelay__DOT__signal_ram__DOT__ram_array[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6498894174212532868ull);
    }
    vlSelf->__Vdly__sigdelay__DOT__wr_addr = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 3293678437569660903ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3495601893105415319ull);
}
