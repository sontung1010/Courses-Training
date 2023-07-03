`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    
// Design Name: 
// Module Name:    FourBitAdder 
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
module FourBitAdder( RCOSum, RCOCarryOut, RCOAddX, RCOAddY, RCOCarryIn);

    output [3:0]  RCOSum;
    output 		  RCOCarryOut;
    input [3:0]   RCOAddX;
    input [3:0]   RCOAddY;
	input		  RCOCarryIn;


// create wires for intermediate carries

wire C1;
wire C2;
wire C3;


// instantiate the set of full adders 
FullAdder	RCO_FA0(RCOSum[0],C1,RCOAddX[0],RCOAddY[0],RCOCarryIn),
			RCO_FA1(RCOSum[1],C2,RCOAddX[1],RCOAddY[1],C1),
			RCO_FA2(RCOSum[2],C3,RCOAddX[2],RCOAddY[2],C2),
			RCO_FA3(RCOSum[3],RCOCarryOut,RCOAddX[3],RCOAddY[3], C3);
				

endmodule

