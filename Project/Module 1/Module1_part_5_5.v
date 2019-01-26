//Module 1 part 5 5
module Module1_part5(Clock,rst,Q,TC);
parameter abc = 8, def = 20;
//inputs and outputs are declared
input Clock, rst;
output [abc-1:0] Q;
reg [abc-1:0] Q = 0;
output reg TC;

always@(posedge Clock or negedge rst)begin 
if(!rst)
begin
Q<= 0; //everything is set to reset
end
else 
begin
Q <= Q + 1;
TC <= 0; //TC = 0 when Q+1
if(Q==def) 
begin
Q <= 0;
TC <= 1;
end
end
end
endmodule
