module counter #(
    parameter WIDTH=8
)(
    //interface signals
    input                    clk,   //clock
    input                    rst,   //reset
    input                    en,    //counter enable
    input logic [WIDTH-1:0]  incr,  // <-- ADDED: increment value port
    output logic [WIDTH-1:0] count  //count output
);

always_ff @(posedge clk or posedge rst) 
    if(rst) 
        count <= {WIDTH{1'b0}};
    else if (en) 
        count <= count + incr;
    // if not enabled, count holds its previous value

endmodule 

