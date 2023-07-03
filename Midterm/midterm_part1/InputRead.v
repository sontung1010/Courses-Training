`timescale 1ns / 1ps

module InputRead(Sw, Input, rst_n, Btn1);
    input [3:0] Sw;
    output [3:0] Input;
    output rst_n;
    input Btn1;
    
    assign rst_n = Btn1;
    
    assign Input[0] = ~Sw[0],
           Input[1] = ~Sw[1],
           Input[2] = ~Sw[2],
           Input[3] = ~Sw[3];
endmodule
