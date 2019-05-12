**#Subject : Programmable-Logic-Design--FPGA  
#Term : Fall 18  
#Project : Tic - Tac- Toe , Quiz, Hangman Game  
#Author : Raj Lavingia, Sanju, Srinath**    

**Description**  
This project was intended to make three games using Altera DE-1 SoC Board and use its peripherals.

For this project first of all we made a Tic Tac Toe game and interfaced the VGA monitor with the DE-1 Soc board. We divided the screen into 9 parts and then using the matrix system and grid system we coloured each pixel of the VGA monitor in order to play the game. It was a 2 player game where each player has to enter coordinates in order to select their rectangle.
(Pictures attached)

Similaryly we made a quiz game where a user has to answer 3 correct questions. If he answers all the correct questions then the screen will display a green colour or else a red. 

For a hangman game, the master gives a word and the user has to guess it. For every wrong answer on the screen a man was being hanged.

While playing the game the user can also listen to the music.

We have interfaced the audio jack with the FPGA fabric and thus the user was able to store the music into the FPGA fabric and listen to it while 
playing the game.

**PLatform Used :**  
DE-1 SoC Board

**Peripherals Used :**  
Audio, Video(VGA Output)

**Fabric Utilization :**  
Approx 4%

**Languages Used**  
C, Verilog


