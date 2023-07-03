`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   
// Design Name:   AdderTop
// Module Name:   
// Project Name:  
// Target Device:  
// Tool versions:  
// Description: 
//
//
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module AddTest_v;

	// Inputs
	reg Sw0;
	reg Sw1;
	reg Sw2;
	reg Sw3;
	reg Sw4;
	reg Sw5;
	reg Sw6;
	reg Sw7;
	reg Btn0;

	// Outputs
	wire [4:0] Output;

	// Instantiate the Unit Under Test (UUT)
	AdderTop uut (
		.Output(Output), 
		.Sw0(Sw0), 
		.Sw1(Sw1), 
		.Sw2(Sw2), 
		.Sw3(Sw3), 
		.Sw4(Sw4),
		.Sw5(Sw5),
		.Sw6(Sw6),
		.Sw7(Sw7),
		.Btn0(Btn0)
	);

	initial begin
    $dumpfile("sim.vcd");
    $dumpvars;
		// Initialize Inputs
		Sw0 = 0;
		Sw1 = 0;
		Sw2 = 0;
		Sw3 = 0;
		Sw4 = 0;
		Sw5 = 0;
		Sw6 = 0;
		Sw7 = 0;
		Btn0 = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		#1000; 
		Sw0=0;
		#1000; 
		Sw1=1;
		#1000; 
		Sw2=0;
		#1000; 
		Sw3=1;
		#1000; 
		Sw4=1;
		#1000;
		Sw5=0;
		#1000;
		Sw6=0;
		#1000;
		Sw7=1;
		#1000;
		Btn0=1;
	end
      
endmodule

