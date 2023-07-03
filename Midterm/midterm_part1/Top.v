`timescale 1ns / 1ps

module Top(Sw, hexdisp, AN, Btn1, CLK100MHZ);
    output [6:0] hexdisp;
    output [7:0] AN;
    input [3:0] Sw;
    input Btn1;
    input CLK100MHZ;
    
    wire [3:0] InN;
    wire rst_n;
    wire clk16;
    
    assign AN[0] = 0;
    assign AN[1] = 1;
    assign AN[2] = 1;
    assign AN[3] = 1;
    assign AN[4] = 1;
    assign AN[5] = 1;
    assign AN[6] = 1;
    assign AN[7] = 1;
    
    InputRead Inverter(Sw, InN, rst_n, Btn1);
    
    clockdivider16 CLK16(CLK100MHZ, clk16);
    
    SevenSegments SS(hexdisp, InN, rst_n, clk16);
endmodule
