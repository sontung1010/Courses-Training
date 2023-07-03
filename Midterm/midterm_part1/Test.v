`timescale 1ns / 1ps

module Test;
    reg [3:0] Sw;
    reg Btn1;
    wire [6:0] hexdisp;
    wire [7:0] AN;
    reg CLK100MHZ;
    
    Top uut (
        .Sw(Sw),
        .AN(AN),
        .Btn1(Btn1),
        .hexdisp(hexdisp),
        .CLK100MHZ(CLK100MHZ)
    );
    
    always @ (Btn1)
        begin 
            CLK100MHZ = ~CLK100MHZ;
        end
    
    initial begin
        Sw[0] = 0;
        Sw[1] = 0;
        Sw[2] = 0;
        Sw[3] = 0;
        Btn1 = 0;
        CLK100MHZ = 1'b0;
        
        #100;
        
        #1000;
        Sw[0] = 0;
        #1000;
        Sw[1] = 0;
        #1000;
        Sw[2] = 1;
        #1000;
        Sw[3] = 0;
        #1000;
    end
endmodule
