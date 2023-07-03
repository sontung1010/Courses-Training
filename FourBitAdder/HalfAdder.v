//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    
// Design Name: 
// Module Name:    HalfAdder 
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
module HalfAdder(SumHalf, CarryHalf,Xhalf, Yhalf);

    output SumHalf;
    output CarryHalf;
	input Xhalf;
    input Yhalf;							
// description of half adder.  Instantiate primitive gates
					
	xor(SumHalf,Xhalf,Yhalf); // xor Function (output, input1, input2)
	and(CarryHalf,Xhalf,Yhalf); // and Function (output, input1, input2)


endmodule
