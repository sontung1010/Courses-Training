`timescale 1ns / 1ps

//counter based
module clockdivider16(
    input wire clk,      // 100MHz
    output reg divided_clk = 0  // 16MHz 
);


localparam div_value = 2;    // 16MHz
// division_value = 100MHz/(2*desired Frequency) - 1 => 16MHz => 2

// counter 
integer counter_value = 0;  // 32 bit wide reg bus

always @ (posedge clk)     // sensitivity list  // rising edge 0-1
    begin
        // keep counting until 1000
        if (counter_value == div_value)
            counter_value = 0;      // reset value
        else
            counter_value <= counter_value + 1;   // count up
    end

// divide clock
always @ (posedge clk)
    begin
        if (counter_value == div_value)
            divided_clk <= ~divided_clk;    // flip the signal
        else 
            divided_clk <= divided_clk;     // store value
    end
endmodule