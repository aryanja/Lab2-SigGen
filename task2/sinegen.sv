module sinegen #(
    parameter A_WIDTH = 8,
    parameter D_WIDTH = 8
)(
    //interface signals
    input logic               clk, //clock
    input logic               rst, //reset
    input logic               en,  //enable
    input logic [D_WIDTH-1:0] incr,//increment for addr counter
    output logic [D_WIDTH-1:0] dout1, //output data (sin)
    output logic [D_WIDTH-1:0] dout2 //output data (cos)
);

    logic [A_WIDTH-1:0] address; // interconnect wire 1
    //logic [A_WIDTH-1:0] address2;

counter addrcounter (
    .clk(clk),
    .rst(rst),
    .en(en),
    .incr(incr),
    .count(address)
);


rom #(
    .ADDRESS_WIDTH(A_WIDTH),
    .DATA_WIDTH(D_WIDTH)
) sineRom(
    .clk(clk),
    .addr1(address),
    .addr2(address+incr),
    .dout1(dout1),
    .dout2(dout2)

);

endmodule


