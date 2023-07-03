`timescale 1ns / 1ps

module counter(counter_out, clk, rst_n);
    output [7:0] counter_out;
    input clk;
    input rst_n;
    
    reg [7:0] counter_out;
    
    always @ (posedge clk)
        if (rst_n)
            counter_out <= 8'b0;
        else 
            counter_out <= counter_out + 1;
endmodule
