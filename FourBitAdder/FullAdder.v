`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    
// Design Name: 
// Module Name:    FullAdder 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module FullAdder( Sum, Cout, Xin, Yin, Cin);
    input Xin;
    input Yin;
    input Cin;
    output Sum;
    output Cout;

// create wires for interconnects
wire S1; // intermediate sum between the two half adders
wire C1; // internally generated carry from the two half adders
wire C2; // internally generated carry from the two half adders

// instantiate the half adder modules created above


HalfAdder HA1(S1,C1,Xin,Yin);
HalfAdder HA2(Sum,C2,S1,Cin);

// support when carries are generated
or G1(Cout,C2,C1);


endmodule





