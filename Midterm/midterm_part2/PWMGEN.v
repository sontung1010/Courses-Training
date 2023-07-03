`timescale 1ns / 1ps

module PWMGEN(DC, PWM_out, clk, rst_n);
    input clk;
    input rst_n;
    input [7:0] DC;     // 8 bit PWM input
    output reg PWM_out;     // 1 bit PWM output
    
    wire [7:0] counter_out;     // 8 bit counter output
    
    always @ (posedge clk)
        begin
            if (DC > counter_out)
                PWM_out <= 1;
            else 
                PWM_out <= 0;
        end
    
    counter counter_inst(
        .clk(clk),
        .counter_out(counter_out),
        .rst_n(rst_n)
    );
endmodule
