`timescale 1ns / 1ps

module mux2to1(out, A, B, sel);
    output out;
    input A;
    input B;
    input sel;
    
    reg out;
    always @ (sel)
        begin
            if (sel)
                out <= B;
            else 
                out <= A;
        end
endmodule
