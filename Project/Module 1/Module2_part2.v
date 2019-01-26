module Module2_part2(LED,SW);
//Inputs and outputs defined by LED and Switch
input [9:0]SW;
output reg [9:0]LED;
//always block generated
always@(SW) 
begin
if(SW[9]==0) //comapre if all the switches are 0
begin
LED[7:0]={"0000",SW[3:0]}; //all leds and switches are at 0 position
end
else
begin
LED[7:0]={"0000",SW[7:4]};
LED[9]=SW[9];//10th led and switch
end
end
endmodule