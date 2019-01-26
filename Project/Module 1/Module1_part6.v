//Module1 part 6 started
module part6 (SW,LED,HEX5, HEX4, HEX3, HEX2, HEX1, HEX0);
input [9:0] SW;
output [9:0] LED;
output [6:0] HEX5,HEX4,HEX3,HEX2,HEX1,HEX0;
assign LED = SW;
wire [1:0] Ch1, Ch2, Ch3;
wire [2:0] Ch_Sel;
wire [1:0] H2_Ch, H1_Ch, H0_Ch;
assign Ch_Sel = SW[9:7];
assign Ch1 = SW[1:0];
assign Ch2 = SW[3:2];
assign Ch3 = SW[5:4];	
mux_2bit_3to1p6 M2 (0, Ch1, Ch3, Ch2, H2_Ch);
mux_2bit_3to1p6 M1 (0, Ch2, Ch1, Ch3, H1_Ch);
mux_2bit_3to1p6 M0 (0, Ch3, Ch2, Ch1, H0_Ch);
reg [1:0] H0,H1,H2,H3,H4,H5;
always @ (Ch_Sel)begin
if (Ch_Sel[2:0] == 0) begin
H0 = 3;
H1 = 3;
H2 = 3;
H3 = H2_Ch;
H4 = H1_Ch;
H5 = H0_Ch;
end
else if (Ch_Sel[2:0] == 1) begin
H0 = H0_Ch;
H1 = 3;
H2 = 3;
H3 = 3;
H4 = H2_Ch;
H5 = H1_Ch;
end
else if (Ch_Sel[2:0] == 2) begin
H0 = H1_Ch;
H1 = H0_Ch;
H2 = 3;
H3 = 3;
H4 = 3;
H5 = H2_Ch;
end
else if (Ch_Sel[2:0] == 3) begin
		H0 = H2_Ch;
		H1 = H1_Ch;
		H2 = H0_Ch;
		H3 = 3;
		H4 = 3;
		H5 = 3;
	end
	else if (Ch_Sel[2:0] == 4) begin
		H0 = 3;
		H1 = H2_Ch;
		H2 = H1_Ch;
		H3 = H0_Ch;
		H4 = 3;
		H5 = 3;
	end
	else if (Ch_Sel[2:0] == 5) begin
		H0 = 3;
		H1 = 3;
		H2 = H2_Ch;
		H3 = H1_Ch;
		H4 = H0_Ch;
		H5 = 3;
	end
	else begin
		H0 = 3;
		H1 = 3;
		H2 = 3;
		H3 = 3;
		H4 = 3;
		H5 = 3;
	end
	end
	
	char_7segp6 HI5 (H5, HEX5);
	char_7segp6 HI4 (H4, HEX4);
	char_7segp6 HI3 (H3, HEX3);
	char_7segp6 HI2 (H2, HEX2);
	char_7segp6 HI1 (H1, HEX1);
	char_7segp6 HI0 (H0, HEX0);
	
endmodule

// Implements a 2-bit wide 3-to-1 multiplexer
module mux_2bit_3to1p6 (S, U, V, W, M);
	input [1:0] S, U, V, W;
	output reg [1:0] M;
	
	always @ (S) begin
		if (S[1:0] == 0)
			M = U;
		else if(S[1:0] == 1)
			M = V;
		else if(S[1:0] == 2)
			M = W;
		else
			M = 3;
	end
	
endmodule	

module char_7segp6 (C, Display);
input [1:0] C;
output reg [6:0] Display;	
always @ (C) begin
		if ( C[1:0] == 0)
			Display = ~94;
		else if ( C[1:0] == 1)
			Display = ~121;	
		else if ( C[1:0] == 2)
			Display = ~6;
		else
			Display = ~0;	
	end
endmodule

