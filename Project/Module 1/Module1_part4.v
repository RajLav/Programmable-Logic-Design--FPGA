//Module 1 part 4 started
module Module1_part4(LED,SW, hexadecimal,temp,temp1,temp2,temp3);
//Inputs and outputs are declared
input [9:0]SW;
output reg [9:0] LED;
output reg [6:0] hexadecimal;
output reg [6:0] temp; //temp values are declared for not of value
output reg [6:0] temp1;
output reg [6:0] temp2;
output reg [6:0] temp3;

always @ (SW) begin
if(SW[1:0]==0)
begin
temp = ~94;
hexadecimal= temp; //hexa values cases
end
else if(SW[1:0]==1)
begin
temp1 = ~121;
hexadecimal=temp1;
end
else if (SW[1:0] == 2)
begin
temp2 = ~6;
hexadecimal = temp2;
end
else
begin
temp3 = ~0;
hexadecimal = temp3;	
LED = SW;
end
end

endmodule