`timescale 1ns / 1ps

module Top(Output, Btn1, Btn2, CLK100MHZ, DC);
    output Output;
    input Btn1;
    input Btn2;
    input CLK100MHZ;
    input [7:0] DC;
    
    wire clkout;
    wire clk32;
    wire clk16;
    wire pwmout;
    
    assign Output = pwmout;
    
    clockdivider32 CLK32(CLK100MHZ, clk32);
    clockdivider16 CLK16(CLK100MHZ, clk16);
    
    mux2to1 muxclk(clkout, clk32, clk16, Btn1);
    
    PWMGEN pwmgen(DC, pwmout, clkout, Btn2);
endmodule
