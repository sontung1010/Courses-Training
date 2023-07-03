`timescale 1ns / 1ps

module testbench;
   reg Btn1;
   reg Btn2;
   reg CLK100MHZ;
   reg [7:0] DC;
   
   wire Output;
   
   Top UUT(
    .Output(Output),
    .Btn1(Btn1),
    .Btn2(Btn2),
    .CLK100MHZ(CLK100MHZ),
    .DC(DC)
   );
   
   always @ (Btn2)
        begin
            CLK100MHZ = ~CLK100MHZ;
        end
   
   initial begin
        Btn1 = 0;
        Btn2 = 0;
        DC = 8'b0;
        CLK100MHZ = 1'b0;
        
        #100;
        
        #1000;
        DC = 8'b00100010;
        #1000;
        Btn1 = 1;
        #1000;
        Btn2 = 1;
        #1000;
   end

endmodule
