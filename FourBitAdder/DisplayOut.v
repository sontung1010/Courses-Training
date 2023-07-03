//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    
// Design Name: 
// Module Name:    DisplayOut 
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
module DispOut(DataOut,DataIn);

	output [4:0]	DataOut; 
	input  [4:0] 	DataIn;


// create the output as negative logic to assert the LEDS 
// Later this can become more elaborate to use 7-segments, LCDs, etc...

not(DataOut[0],DataIn[0]);
not(DataOut[1],DataIn[1]);
not(DataOut[2],DataIn[2]);
not(DataOut[3],DataIn[3]);
not(DataOut[4],DataIn[4]);


endmodule
