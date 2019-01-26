//Module3 part 3 started
module Module3_part3 (LED,SW);
//Inputs and outputs are declared
input [9:0] SW;
output reg [9:0] LED;

always @ (SW) begin

if( SW[9]==1) //switch is 1 then light up certain lEDS
begin
LED[1:0]=SW[1:0];
end
else if(SW[9]==0&SW[8]==1)
begin
LED[1:0] = SW[3:2]; //led 1 , 2 with respect to switches 3 4
end
else
begin
LED[1:0] = SW[5:4];
LED[9] = SW[9]; //9,9
LED[8] = SW[8]; //8,8
end
end

endmodule