//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    
// Design Name: 
// Module Name:    AdderTop 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional  This isthe top file for the design and contains the 
//
//////////////////////////////////////////////////////////////////////////////////
module AdderTop(Output,Sw0, Sw1, Sw2, Sw3, Sw4, Sw5, Sw6, Sw7, Btn0 );

    output [4:0]  Output;
    input 			Sw0;
    input 			Sw1;
    input 			Sw2;
    input 			Sw3;
    input           Sw4;
    input           Sw5;
    input           Sw6;
    input           Sw7;

	input			Btn0;
 
	 
// create wires
wire [3:0] OpX; // four bits from the 8 discrete inputs to apply to 4-bit adder
wire [3:0] OpY; // four bits from the 8 discrete inputs to apply to 4-bit adder

wire [3:0] Sum; // four sum bits from the RCO Adder
wire Cout; // adder carry out
wire Cin;  // adder carry in

wire [4:0] DispData;

assign DispData[4] = Cout;
assign DispData[3:0] = Sum;

InputRead In0(Sw0,Sw1,Sw2,Sw3,Sw4,Sw5,Sw6,Sw7,Btn0,OpX,OpY,Cin);  

FourBitAdder	Add1(Sum, Cout, OpX, OpY, Cin);

DispOut	DO(Output,DispData);

endmodule
