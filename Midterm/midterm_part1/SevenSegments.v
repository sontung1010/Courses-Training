`timescale 1ns / 1ps

module SevenSegments(disp, bits, rst_n, clk);
    input [3:0] bits;
    output [6:0] disp;
    input rst_n;
    input clk;
    
    reg [6:0] disp;
    
    always @ (posedge clk)
        begin
            if(rst_n)
                begin
                    disp <= 7'b1000000;
                end
            else
                begin
                    case (bits)
                        4'b0000: disp <= 7'b0000011;
                        4'b0001: disp <= 7'b0000011;
                        4'b0010: disp <= 7'b0000011;
                        4'b0011: disp <= 7'b0000011;
                        4'b0100: disp <= 7'b0011001;
                        4'b0101: disp <= 7'b0000011;
                        4'b0110: disp <= 7'b0000010;
                        4'b0111: disp <= 7'b0001100;
                        4'b1000: disp <= 7'b0001110;
                        4'b1001: disp <= 7'b0010000;
                        4'b1010: disp <= 7'b0001000;
                        4'b1011: disp <= 7'b0000011;
                        4'b1100: disp <= 7'b1000110;
                        4'b1101: disp <= 7'b0001100;
                        4'b1110: disp <= 7'b0000110;
                        4'b1111: disp <= 7'b0001110;
                        default: disp <= 7'b1111111;
                    endcase
                end
        end   
endmodule
