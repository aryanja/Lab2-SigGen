module sigdelay #(
    parameter ADDR_W = 9,
    parameter DATA_W = 8  
)(
    // --- Testbench Ports ---
    input logic             clk,
    input logic             rst,
    input logic             wr,             // Write enable for RAM/counter
    input logic             rd,             // Read enable for RAM
    input logic [ADDR_W-1:0]  offset,         // Delay offset
    input logic [DATA_W-1:0]  mic_signal,     // Input signal
    output logic [DATA_W-1:0] delayed_signal  // Delayed output signal
);

    
    // Wire for the write address, driven by the counter
    logic [ADDR_W-1:0] wr_addr;
    
    // Wire for the read address, calculated from wr_addr and offset
    logic [ADDR_W-1:0] rd_addr;

    // --- Combinational Logic ---

    // Calculate the read address for the circular buffer.
    // Unsigned subtraction automatically handles the wrap-around.
    assign rd_addr = wr_addr - offset;

    // --- Module Instantiations ---

    // 1. Write Address Counter
    // This counter generates the write address for the RAM.
    // Note: The provided counter module's logic ignores the 'incr' port
    // and just increments by 1, which is correct for this application.
    counter #(
        .WIDTH(ADDR_W)
    ) write_counter (
        .clk(clk),
        .rst(rst),
        .en(wr),                 // Enable counting when writing
        .incr( {ADDR_W{1'b1}} ),   // Tie 'incr' port (unused by module logic)
        .count(wr_addr)          // Output is the write address
    );

    // 2. Signal Storage RAM
    // This RAM implements the circular buffer.
    ram2ports #(
        .ADDRESS_WIDTH(ADDR_W),
        .DATA_WIDTH(DATA_W)
    ) signal_ram (
        .clk(clk),
        .wr_en(wr),              // Write enable from top
        .rd_en(rd),              // Read enable from top
        .wr_addr(wr_addr),       // Address from counter
        .rd_addr(rd_addr),       // Calculated read address
        .din(mic_signal),        // Input data from mic
        .dout(delayed_signal)    // Output data to testbench
    );

endmodule