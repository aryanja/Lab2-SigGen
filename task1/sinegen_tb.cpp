#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"
#define MAX_SIM_CYC 1000000
#define ADDRESS_WIDTH 8
#define ROM_SZ 256 


int main(int argc, char **argv, char **env)
{
    int simcyc; //simulation clock count
    int tick; // each clk cycle has two ticks for two edges 

    Verilated::commandArgs(argc, argv);
    // init top verilog inqstance
    Vsinegen* top = new Vsinegen;
    // init Trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("sinegen.vcd");

    // init Vbuddy
    if (vbdOpen() != 1)
        return (-1);
    vbdHeader("L2T1: SigGen");

    // initialize simulation inputs
    top->clk = 1;
    top->rst = 0;
    top->en = 1;
    top->incr = 1;

    // run simulation for MAX_SIM_CYC clock cycles 
    for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) { 

        // --- Standard Verilator Loop Structure ---
        
        // --- Tick 0 (negedge) ---
        // Registers (like top->dout) update on the negedge 
        // (or just before) based on what was scheduled at the posedge
        top->clk = 0;
        top->eval();
        tfp->dump(simcyc*2 + 0);

        // --- Plot output ---
        // Plot the stable output value *after* the negedge eval
        vbdPlot(int (top->dout), 0, 255); 
        vbdCycle(simcyc);

        // --- Tick 1 (posedge) ---
        // Set inputs *just before* the posedge
        top->incr = vbdValue(); 
        
        top->clk = 1;
        top->eval();
        tfp->dump(simcyc*2 + 1);
        // (posedge eval() causes always_ff to schedule new values for next negedge)
        // ------------------------------------------

        // either simulation finished, or 'q' is pressed 
        if ((Verilated::gotFinish()) || (vbdGetkey()=='q'))  
            exit(0);
    }


    vbdClose();     // ++++ 
    tfp->close();  
    exit(0); 
} 

