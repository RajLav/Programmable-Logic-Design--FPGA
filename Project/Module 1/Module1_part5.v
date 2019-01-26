//Module 5 part 5 started
module module5_part5(SW,LED,hexadecimal,hexadecimal1,hexadecimal2);
//input output declared
input [9:0] SW;
output [9:0] LED;			
output [6:0] hexadecimal, hexadecimal1, hexadecimal2;
assign LED = SW;
wire [1:0] selection, channel1, channel2, channel3;
wire [1:0] channel4, channel5, channel6;
assign selection=SW[9:8];
assign channel1=SW[5:4];
assign channel2=SW[3:2];
assign channel3=SW[1:0];
//Mux implementation	
mux_convert mux2(selection,channel1,channel3,channel2,channel4);
mux_convert mux1(selection,channel2,channel1,channel3,channel5);
mux_convert mux0(selection,channel3,channel2,channel1,channel6);
segment H2(channel4,hexadecimal);
segment H1(channel5,hexadecimal1);
segment H0(channel6,hexadecimal2);
endmodule
//mux convert from 2-1 to 3-1
module mux_convert (a,b,c,d,e);
input [1:0] a,b,c,d;
output reg [1:0] e;
always @ (a)
begin
if (a[1:0] == 0)
begin
e = b;
end
else if(a[1:0] == 1)
begin
e = c;
end
else if(a[1:0] == 2)
begin
e = d;
end
else
begin
e = 3;
end
end

endmodule	

module segment(C,Display,temp,temp1,temp2,temp3);
input [1:0] C;
output reg [6:0] Display;
output reg [6:0] temp;
output reg [6:0] temp1;
output reg [6:0] temp2;
output reg [6:0] temp3;
always@(C)
begin
if (C[1:0]==0)
begin
temp = ~94;
//Display1 = ~94
Display = temp;
end
else if(C[1:0]==1)
begin
temp1 = ~121;
//Display1 = ~121
Display = temp1;	
end
else if (C[1:0]==2)
begin
temp2 = ~6;
//Display1 = ~6
Display = temp2;
end
else
begin
//Display1 = ~0
temp3 = ~0;
Display = temp3;	
end
end
endmodule
