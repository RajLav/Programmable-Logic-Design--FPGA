#include <stdio.h>
#include <unistd.h>
#include<string.h>
#include <fcntl.h> 
#include <sys/mman.h> 
#include "hwlib.h" 
#include "soc_cv_av/socal/socal.h"
#include "soc_cv_av/socal/hps.h" 
#include "soc_cv_av/socal/alt_gpio.h"
#include "hps_0.h"


#define REG_BASE 0xFF200000
#define REG_SPAN 0x00200000


#define black 0x00
#define blue 0x03
#define red 0xe0
#define orange 0xec
#define green 0x1c
#define cyan 0x1f
#define white 0xff


void *h2p_lw_vga_addr;
void *h2p_lw_vga_we_addr;
void *h2p_lw_vga_data_addr;

void* virtual_base;
void* led_addr;
void* sw_addr;
void* key_addr;
int fd;
int switches;
int switches1;
int key;

typedef struct game_board{
    char board[3][3];
}game_board;

typedef struct player{
    //game_board board1;
    int player_no;
    int win_count;
}player;

void clear_game_board(game_board *board_t)
{
    int i, j;
    char count = '0';
    for(i=0;i<3;i++){
       for(j=0;j<3;j++){
           board_t->board[i][j] = ++count ;
        }
    }
}


void VGA_draw_point(int x1, int y1, short color)
{
    *(uint32_t *)h2p_lw_vga_addr = (x1 << 9) + y1;  
    *(uint32_t *)h2p_lw_vga_data_addr = color; 
    //Enable for memory to write 
    *(uint32_t *)h2p_lw_vga_we_addr = 1; 
    
    //disable to stop writing memory
    *(uint32_t *)h2p_lw_vga_we_addr = 0; 

}

void VGA_clean_up()
{
  *(uint32_t *)h2p_lw_vga_we_addr = 0; 
  *(uint32_t *)h2p_lw_vga_data_addr = 0; 
}

void VGA_write_lose()
{
  int i, j;

  /*Y*/
  //for (i= 299,j=232;i<307,j<240;i++,j++)
  for (i= 279,j=232;i<287,j<240;i++,j++)
    VGA_draw_point(i,j,black);
  for (i=286,j=239;j<248;j++)
    VGA_draw_point(i,j,black);
  for (i= 286,j=239;i<294,j>231;i++,j--)
    VGA_draw_point(i,j,black);

  /*O*/
  for(i=296,j=232; j<248; j++)
    VGA_draw_point(i,j,black);
  for(i=296,j=232; i<304; i++)
    VGA_draw_point(i,j,black);
  for(i=296,j=247; i<304; i++)
    VGA_draw_point(i,j,black);  
  for(i=303,j=232;j<248;j++)
    VGA_draw_point(i,j,black);

  /*U*/
  for(i=306,j=232; j<248; j++)
    VGA_draw_point(i,j,black);
  for(i=306,j=247; i<314; i++)
    VGA_draw_point(i,j,black);  
  for(i=313,j=232;j<248;j++)
    VGA_draw_point(i,j,black);

  /*L*/
  for(i=326,j=232; j<248;j++)
    VGA_draw_point(i,j,black);
  for(i=326,j=247;i<335;i++)
     VGA_draw_point(i,j,black);

   /*O*/
  for(i=337,j=232; j<248; j++)
    VGA_draw_point(i,j,black);
  for(i=337,j=232; i<345; i++)
    VGA_draw_point(i,j,black);
  for(i=337,j=247; i<345; i++)
    VGA_draw_point(i,j,black);  
  for(i=344,j=232;j<248;j++)
    VGA_draw_point(i,j,black);

  /*S*/
  for(i=347,j=232; i<355; i++)
    VGA_draw_point(i,j,black);
  for(i=347,j=232; j<240; j++)
    VGA_draw_point(i,j,black);
  for(i=347,j=240; i<355; i++)
    VGA_draw_point(i,j,black);
  for(i=355,j=240; j<247; j++)
    VGA_draw_point(i,j,black);
  for(i=355,j=247; i>347; i--)
    VGA_draw_point(i,j,black);

  /*E*/
  for(i=358,j=232;i<365;i++)
    VGA_draw_point(i,j,black);
  for(i=358,j=232;j<248;j++)
    VGA_draw_point(i,j,black);
  for(i=358,j=247;i<365;i++)
    VGA_draw_point(i,j,black);
  for(i=358,j=240;i<365;i++)
    VGA_draw_point(i,j,black);


}
void VGA_write_win()
{
  
   int i, j;
   /*Y*/
  //for (i= 299,j=232;i<307,j<240;i++,j++)
  for (i= 279,j=232;i<287,j<240;i++,j++)
    VGA_draw_point(i,j,blue);
  for (i=286,j=239;j<248;j++)
    VGA_draw_point(i,j,blue);
  for (i= 286,j=239;i<294,j>231;i++,j--)
    VGA_draw_point(i,j,blue);

  /*O*/
  for(i=296,j=232; j<248; j++)
    VGA_draw_point(i,j,blue);
  for(i=296,j=232; i<304; i++)
    VGA_draw_point(i,j,blue);
  for(i=296,j=247; i<304; i++)
    VGA_draw_point(i,j,blue);  
  for(i=303,j=232;j<248;j++)
    VGA_draw_point(i,j,blue);

  /*U*/
  for(i=306,j=232; j<248; j++)
    VGA_draw_point(i,j,blue);
  for(i=306,j=247; i<314; i++)
    VGA_draw_point(i,j,blue);  
  for(i=313,j=232;j<248;j++)
    VGA_draw_point(i,j,blue);

  /*W*/
  for(i=326,j=232; j<248;j++)
    VGA_draw_point(i,j,blue);
  for(i=326,j=247; i<334;i++)
    VGA_draw_point(i,j,blue);
  for(i=333,j=232;j<248;j++)
    VGA_draw_point(i,j,blue);
  for(i=330,j=247;j>240;j--)
    VGA_draw_point(i,j,blue);

  /*I*/
  for(i=336,j=232;i<344;i++)
    VGA_draw_point(i,j,blue);
  for(i=340,j=232;j<248;j++)
    VGA_draw_point(i,j,blue);
  for(i=336,j=247;i<344;i++)
    VGA_draw_point(i,j,blue);

  /*N*/
  for(i=346,j=232;j<248;j++)
  VGA_draw_point(i,j,blue);
  for(i=346,j=232;i<354;i++,j+=2)
    VGA_draw_point(i,j,blue);
  for(i=353,j=232;j<248;j++)
    VGA_draw_point(i,j,blue);
}

VGA_game_board()
{
	int i =0, j =0;

	for(j=0,i=213;j<480;j++)
	{
		VGA_draw_point(i,j,black);
	}

	for(j=0,i=416;j<480;j++)
	{
		VGA_draw_point(i,j,black);
	}

	for(i=0,j=160;i<640;i++)
	{
		VGA_draw_point(i,j,black);
	}

	for(i=0,j=320;i<640;i++)
	{
		VGA_draw_point(i,j,black);
	}
}

void tictacktoe()
{
   int i,j;
   for (i = 0; i < 640; i++)
        for (j = 0; j < 480; j++)      
          VGA_draw_point(i,j,white);
   VGA_game_board();
   game_board game_board;
   player player[2];
   player[0].player_no = 1;
   player[1].player_no = 2; 
   player[0].win_count = 0;
   player[1].win_count = 0;
   int row,col;
   int turn;
   int prev_win_count[2] = {0};
   int previous_switch = 0;
   int previous_switch1 = 0;
   
   clear_game_board(&game_board);
    for(i=0;i<3;i++){
            for(j=0;j<3;j++){
            printf("%c\t", game_board.board[i][j]);
        }
        printf("\n");
        }
    
    do{
        for(turn = 0; turn<9; turn++){
            printf("Player number: %d\n", player[turn%2].player_no);
            
            do
            {
              key = *(uint32_t *)key_addr;
              switches = *(uint32_t *)sw_addr;
              //switches = switches - 1024;
              *(uint32_t *)led_addr=switches;
              usleep(1000000);
              //printf("SW = %u\n",switches);
              if(switches < 516)
              {
                previous_switch = switches;
              }
              //printf("Previous SW = %u\n",previous_switch);
              //printf("Key = %u\n", key);
            }while(switches<516);

            row = previous_switch - 512;
            printf("Selected row = %d\n",row);
            usleep(2000000);
            
            do
            {
              switches1 = *(uint32_t *)sw_addr;
              *(uint32_t *)led_addr=switches1;
              //switches1 = switches1 - 1024;
              usleep(1000000);
              //printf("SW1 = %u\n", switches1);
              if(switches1 < 516)
              {
                previous_switch1 = switches1;
              }
              //printf("Previous SW1 = %u\n",previous_switch1);
            }while(switches1<516);
         
            col = previous_switch1 - 512;
            printf("Selected column = %d\n",col);
            usleep(2000000);
            /*scanf("%d", &row);
            scanf("%d", &col);
            */
            if((row < 3 && row >=0) && (col < 3 && col >= 0))
            {
                if(game_board.board[row][col] != 'x' && game_board.board[row][col] !='o')
                {
                    game_board.board[row][col] = ((player[turn%2].player_no == 1)? 'x' : 'o'); 

                	if(row == 0 && col == 0)
                	{
                		for (i = 0; i < 213; i++)
                		{
				            for (j = 0; j < 160; j++)
				            {
				            	if(player[turn%2].player_no == 1)
				            		VGA_draw_point(i,j,blue);
				            	else
				            		VGA_draw_point(i,j,orange);
				            }      				              
                		}
                		VGA_game_board();
                	}

                	else if(row == 0 && col == 1)
                	{
                		for (i = 213; i < 416; i++)
                		{
				            for (j = 0; j < 160; j++)
				            {
				            	if(player[turn%2].player_no == 1)
				            		VGA_draw_point(i,j,blue);
				            	else
				            		VGA_draw_point(i,j,orange);
				            }      				              
                		}
                		VGA_game_board();
                	}


                	else if(row == 0 && col == 2)
                	{
                		for (i = 416; i < 640; i++)
                		{
				            for (j = 0; j < 160; j++)
				            {
				            	if(player[turn%2].player_no == 1)
				            		VGA_draw_point(i,j,blue);
				            	else
				            		VGA_draw_point(i,j,orange);
				            }      				              
                		}
                		VGA_game_board();
                	}


                	else if(row == 1 && col == 0)
                	{
                		for (i = 0; i < 213; i++)
                		{
				            for (j = 160; j < 320; j++)
				            {
				            	if(player[turn%2].player_no == 1)
				            		VGA_draw_point(i,j,blue);
				            	else
				            		VGA_draw_point(i,j,orange);
				            }      				              
                		}
                		VGA_game_board();
                	}

                	else if(row == 1 && col == 1)
                	{
                		for (i = 213; i < 416; i++)
                		{
				            for (j = 160; j < 320; j++)
				            {
				            	if(player[turn%2].player_no == 1)
				            		VGA_draw_point(i,j,blue);
				            	else
				            		VGA_draw_point(i,j,orange);
				            }      				              
                		}
                		VGA_game_board();
                	}


                	else if(row == 1 && col == 2)
                	{
                		for (i = 416; i < 640; i++)
                		{
				            for (j = 160; j < 320; j++)
				            {
				            	if(player[turn%2].player_no == 1)
				            		VGA_draw_point(i,j,blue);
				            	else
				            		VGA_draw_point(i,j,orange);
				            }      				              
                		}
                	}

                	else if(row == 2 && col == 0)
                	{
                		for (i = 0; i < 213; i++)
                		{
				            for (j = 320; j < 480; j++)
				            {
				            	if(player[turn%2].player_no == 1)
				            		VGA_draw_point(i,j,blue);
				            	else
				            		VGA_draw_point(i,j,orange);
				            }      				              
                		}
                	}

                	else if(row == 2 && col == 1)
                	{
                		for (i = 213; i < 416; i++)
                		{
				            for (j = 320; j < 480; j++)
				            {
				            	if(player[turn%2].player_no == 1)
				            		VGA_draw_point(i,j,blue);
				            	else
				            		VGA_draw_point(i,j,orange);
				            }      				              
                		}
                		VGA_game_board();
                	}


                	else if(row == 2 && col == 2)
                	{
                		for (i = 416; i < 640; i++)
                		{
				            for (j = 320; j < 480; j++)
				            {
				            	if(player[turn%2].player_no == 1)
				            		VGA_draw_point(i,j,blue);
				            	else
				            		VGA_draw_point(i,j,orange);
				            }      				              
                		}
                		VGA_game_board();
                	}

                }
                else{
                    printf("Space already filled, Try again xP\n");
                    turn--;
                }
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
                    printf("%c\t", game_board.board[i][j]);
                }
                printf("\n");
                }
                if((game_board.board[0][0] == game_board.board[1][1] && game_board.board[1][1] == game_board.board[2][2]) ||
                   (game_board.board[0][2] == game_board.board[1][1] && game_board.board[1][1] == game_board.board[2][0]))
                   {
                       printf("Player Number %d wins the round!!!\n", player[turn%2].player_no);
                       player[turn%2].win_count++;
                       //prev_win_count[turn%2] += prev_win_count[turn%2]; 
                       clear_game_board(&game_board);
                       break;
                   }
                else if(game_board.board[row][0] == game_board.board[row][1] && game_board.board[row][1] == game_board.board[row][2])
                {
                    printf("Player Number %d wins the round!!!\n", player[turn%2].player_no);
                    player[turn%2].win_count++;
                    //prev_win_count[turn%2] += prev_win_count[turn%2];
                    clear_game_board(&game_board);
                    break;
                }
                
                else if(game_board.board[0][col] == game_board.board[1][col] && game_board.board[1][col] == game_board.board[2][col])
                {
                    printf("Player Number %d wins the round!!!\n", player[turn%2].player_no);
                    player[turn%2].win_count++;
                    //prev_win_count[turn%2] += prev_win_count[turn%2];
                    clear_game_board(&game_board);
                    break;
                }
            }
            else
            {
                printf("Re enter a valid row and column number\n");
                turn--;
            }
        }
        if(player[0].win_count == prev_win_count[0] && player[1].win_count == prev_win_count[1])
        {
            printf("It's a draw!\n");
            clear_game_board(&game_board);
            printf("Player 1 : %d wins\t Player 2 : %d wins\n", player[0].win_count, player[1].win_count);
        }
        else
        {
            printf("Point tally :\n");
            printf("Player 1 : %d wins\t Player 2 : %d wins\n", player[0].win_count, player[1].win_count);
            prev_win_count[turn%2] += prev_win_count[turn%2];
        }
    }while(player[0].win_count <1 && player[1].win_count <1);
    
    if(player[0].win_count == 1)
    {
        printf("Player 1 Wins the game!\n");
    }
    else if(player[1].win_count == 1)
    {
        printf("Player 2 wins the game!\n");
    }
}

int key_press()
{
    key = *(uint32_t *)key_addr;
    while(key == 15)
    {
      key = *(uint32_t *)key_addr;
      usleep(1000000);
      //printf("KEY = %u\n",key);
    
      if(key == 7)
        return 1;
      else if(key == 11)
        return 2;
      else if(key == 13)
        return 3;
    }   

}

void Quiz()
{
    char question [3] [100];
    char ans1 [4][50];
    char ans2 [4][50];
    char ans3 [4][50];
    //char ans4 [4][10];
    char response [3];
    char cont_response;
    int choice[3];
    int i,j;   
    int cont = 0;
    int key_status[3] = {0};

    int flag1 = 0;
    int flag2 = 0;
    int flag3 = 0;
    printf("Lets play QUIZ !");
    strcpy(question[0],"What type of device is an FPGA");
    strcpy (ans1[0], "1. PLD");
    strcpy (ans1[1], "2. EEPROM");
    strcpy (ans1[2], "3. SRAM");
    response [0] = 1;

    strcpy(question[1],"Which came first: the chicken or the egg?");
    strcpy (ans2[0], "1. Chicken");
    strcpy (ans2[1], "2. Egg");
    strcpy (ans2[2], "3. Cannot be determined");
    response [1] = 3;

    strcpy(question[2],"Which is the best HDL language?");
    strcpy (ans3[0], "1. VHDL");
    strcpy (ans3[1], "2. Verilog");
    strcpy (ans3[2], "3. Option 2");
    response [2] = 2;

    printf("\n %s \n", question[0]);
    for (i =0 ; i<3 ; i++)
        printf("%s \n", ans1[i]);

    printf("\n Enter your choice\n");
    while(!key_status[0])
    {
      key_status[0] = key_press();
    }
    ///scanf("%d", &choice[0]);
    printf (" The entered choice is %d\n\n", key_status[0]);
    usleep(1000000);

    if(key_status[0] == response[0])
    {
      flag1 =1;
      for (i = 0; i < 640; i++)
        for (j = 0; j < 480; j++)      
          VGA_draw_point(i,j,green);
    }

    else
    {
      //printf("\n Check 1");
      for (i = 0; i < 640; i++)
        for (j = 0; j < 480; j++)      
          VGA_draw_point(i,j,red);
    }

    usleep(3000000);
    for (i = 0; i < 640; i++)
        for (j = 0; j < 480; j++)      
          VGA_draw_point(i,j,white);

    if (flag1 == 1)
    {
        printf("\n %s \n", question[1]);
        for (i =0 ; i<3; i++)
            printf("%s \n", ans2[i]);

        printf("\n Enter your choice\n");
        //scanf("%d", &choice[1]);
        while(!key_status[1])
        {
          key_status[1] = key_press();
        }
        
        printf ("The entered choice is %d\n\n", key_status[1]);
        usleep(1000000);

        if(key_status[1] == response[1])
        {
           flag2 =1;
           for (i = 0; i < 640; i++)
            for (j = 0; j < 480; j++)      
              VGA_draw_point(i,j,green);
        }

        else
        {
          for (i = 0; i < 640; i++)
            for (j = 0; j < 480; j++)      
              VGA_draw_point(i,j,red);
        }

        usleep(3000000);
        for (i = 0; i < 640; i++)
            for (j = 0; j < 480; j++)      
              VGA_draw_point(i,j,white);
    }       

    if(flag2 == 1)
    {
        printf("\n %s \n", question[2]);
        for (i =0 ; i<3; i++)
            printf("%s \n", ans3[i]);

        printf("\n Enter your choice\n");
        //scanf("%d", &choice[2]);
        while(!key_status[2])
        {
        key_status[2] = key_press();
        }
        printf ("The entered choice is %d\n\n", key_status[2]);
        usleep(1000000);

        if(key_status[2] == response[2])
        {
          flag3 =1;
           for (i = 0; i < 640; i++)
            for (j = 0; j < 480; j++)      
              VGA_draw_point(i,j,green);
        }

        else
        {
          for (i = 0; i < 640; i++)
            for (j = 0; j < 480; j++)      
              VGA_draw_point(i,j,red);
        }

        usleep(3000000);
        for (i = 0; i < 640; i++)
            for (j = 0; j < 480; j++)      
              VGA_draw_point(i,j,white);
    } 
             
    if(flag3 ==1)
    {
        printf("\n \n Yay ! Congrats You Won!");
        for (i = 0; i < 640; i++)
            for (j = 0; j < 160; j++)      
              VGA_draw_point(i,j,orange);
        for (i = 0; i < 640; i++)
          for (j = 160; j < 320; j++)      
              VGA_draw_point(i,j,white);
        for (i = 0; i < 640; i++)
          for (j = 320; j < 480; j++)      
              VGA_draw_point(i,j,green);
        VGA_write_win();     
    }

    else 
    {
        printf("\n \n Sorry! YOU LOST");
        for (i = 0; i < 640; i++)
          for (j = 0; j < 160; j++)      
              VGA_draw_point(i,j,orange);
        for (i = 0; i < 640; i++)
          for (j = 160; j < 320; j++)      
              VGA_draw_point(i,j,white);
        for (i = 0; i < 640; i++)
          for (j = 320; j < 480; j++)      
              VGA_draw_point(i,j,green);
        VGA_write_lose();
    }

    
}

void show_head()
{
	int i,j;
	 /*O*/
  for(i=310,j=150; j<170; j++)
    VGA_draw_point(i,j,black);
  for(i=310,j=150; i<330; i++)
    VGA_draw_point(i,j,black);
  for(i=310,j=169; i<330; i++)
    VGA_draw_point(i,j,black);  
  for(i=329,j=150;j<170;j++)
    VGA_draw_point(i,j,black);
}


void show_left_arm()
{
	int i,j;
	for(i=320,j=190;j>171;j--,i--)
		VGA_draw_point(i,j,black);	
}

void show_right_arm()
{
	int i,j;
	for(i=320,j=190;j>171;j--,i++)
		VGA_draw_point(i,j,black);
}

void show_body()
{
	int i,j;
	for(i=320,j=170;j<230;j++)
		VGA_draw_point(i,j,black);
}

void show_left_leg()
{
	int i,j;
	for(i=320,j=230;j<250;j++,i--)
		VGA_draw_point(i,j,black);		
}

void show_right_leg()
{
	int i,j;
	for(i=320,j=230;j<250;j++,i++)
		VGA_draw_point(i,j,black);		
}

void showHangman(int);

void hangman(void)
{
    char hangmanWord[100], tempWord[100];       /**hangmanWord[] array for the original word and tempWord[] array to get the alphabet from user and compare it with original word**/
    char hangmanOutput[100];                    /**This array will show the remaining blanks and correct inputs**/
    int wrongTry = 6 , matchFound = 0;          /**player will get 5 chance, so we use wrongTry as chance counter**/
                                                /**matchFound to search the alphabet, if the alphabet from user does not exist
                                                in the original word it will remain 0, upon finding the word, matchFound will
                                                be set as 1**/
    int counter = 0 , position = 0, winner, length , i;
    char alphabetFromUser;

    system("cls");                              /**for clearing the screen**/
    printf("\n\n Enter any word in small case and hit >>ENTER<<");
    printf("\n\n\t Enter HERE ==>  ");
    scanf("%s",hangmanWord);                    /**get the string from opponent**/
    printf("\n\n Now give the COMPUTER to your friend and see if he/she can CRACK it!!!");
    printf("\n\n\tHIT >>ENTER<<");
    getchar();                                  /**hold the computer screen**/
    length = strlen(hangmanWord);               /**get the length of the word**/

    system("cls");

    printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the HANGMAN GAME!!!!!!!!!!!!!!!!!\n\n\n");   /**Brief description of the game**/
    printf("\n\n You will get 6 chances to guess the right word");
    printf("\n\n So help the Man and get...set...GO..!!");

    getchar();

    printf("\n\n\tHIT >>ENTER<< ");

    getchar();

    system("cls");

        printf("\n\t||===== ");                 /**show the HANGMAN**/
	printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");

    printf("\n\n     The word has %d alphabets \n\n",length);  /**tell the user how many alphabets the word has**/
    for( i = 0; i < length ; i++)
    {
        hangmanOutput[i] = '_';
        hangmanOutput[length] = '\0';
    }

    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",hangmanOutput[i]);        /**Show the Word With n(length of the original word) number of underscores (_)**/

    }
    while(wrongTry != 0)                        /**while loop for exiting the program when no try left**/
    {
        matchFound = 0;
        printf("\n\n   enter any alphabet from a to z and please use small case!!");
        printf("\n\n\t Enter HERE ==> ");

	    fflush(stdin);

	    scanf("%c",&alphabetFromUser);            /**get alphabet from user**/
    if(alphabetFromUser < 'a' || alphabetFromUser > 'z') /**In case player gives input other than 'a' to 'z' the console will ask again**/
    {
        system("cls");
        printf("\n\n\t Wrong input TRY AGAIN ");
        matchFound = 2;
    }
    fflush(stdin);
    if (matchFound != 2)
    {
        for(counter=0;counter<length;counter++)    /**for loop to check whether player input alphabet exists or not in the word**/
	    {
		    if(alphabetFromUser==hangmanWord[counter])
		     {
		       matchFound = 1;
                     }//end of if()
            }//end of for()

	   if(matchFound == 0)                      /**in case of wrong guess**/
	    {
     	      printf("\n\t :( You have %d tries left ",--wrongTry);
	          getchar();
              showHangman(wrongTry);
              getchar();
	    }//end of if()

	   else
	   {
	     for(counter = 0; counter < length; counter++)
             {
     	         matchFound = 0;
                 if(alphabetFromUser == hangmanWord[counter])
	          {
     		     position = counter ;
     		     matchFound = 1;
	          }//end of if
    	      if(matchFound == 1)
	          {
                 for(i = 0 ; i < length ; i++)
                 {
                      if( i == position)
                  	  {
                          hangmanOutput[i] = alphabetFromUser; /**Put the alphabet at right position**/
                      }
                      else if( hangmanOutput[i] >= 'a' && hangmanOutput[i] <= 'z' ) /** If the position already occupied
                                                                                  by same alphabet then no need to
                                                                                  fill again EASY!! and continue */
                      {
                          continue;
                  	  }

                      else
                      {
                          hangmanOutput[i] = '_';            /** Put a blank at not guessed alphabet position **/
                      }
                }
                tempWord[position] = alphabetFromUser;      /**put the alphabet in another char array to check with the original word**/
                tempWord[length] = '\0';                    /**put the NULL character at the end of the temp string**/
                winner = strcmp(tempWord,hangmanWord);      /**upon True comparison it will return 0**/

                if(winner == 0)                             /**if the player guessed the whole word right then he/she is the WINNER**/
                {
                    printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
                    printf("\n\n\t The Word was %s ",hangmanWord);
                    printf("\n\n\n\n\t\tEASY HUH???\n\n");
                    getchar();
                    //return 0;
                }//end of inner if
	       }//end of outer if
	    }//end of for loop
      }//end of else
     }// end of if(matchFound != 2) condition

    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",hangmanOutput[i]);                /**Show the original Word With blanks and right Input alphabet**/
      }

    getchar();
    }//end of while loop

      if(wrongTry <= 0)                                 /**if the player can not guess the whole word in 5 chaces**/
      {
          printf("\n\n\t The Word was %s ",hangmanWord);
          printf("\n\n\t The man is dead!!!!!");
	      printf("\n\n\t Better luck next!!!");

      }
getchar();
}//end of main();



void showHangman(int choice)                            /**This function show the hangman after each wrong try**/
 {

     switch(choice)
     {

     case 0:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	show_left_leg();
	break;
     case 1:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	show_right_leg();
	break;
     case 2:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	show_body();
	break;
     case 3:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	show_right_arm();
	break;
     case 4:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO ",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	show_left_arm();
	break;
     case 5:
         system("cls");
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    O ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	show_head();
	break;
      }//end of switch-case
      return;
 }




int main()
{
   int option =0;
   int i = 0;
   int j = 0;
   fd=open("/dev/mem",(O_RDWR|O_SYNC));
   virtual_base=mmap(NULL,REG_SPAN,(PROT_READ|PROT_WRITE),MAP_SHARED,fd,REG_BASE);
   sw_addr=virtual_base+PIO_SW_BASE;
   led_addr=virtual_base+PIO_LED_BASE; 
   key_addr=virtual_base+PIO_KEY_BASE;
   h2p_lw_vga_addr      = virtual_base + PIO_VGA_ADDR_BASE;
   h2p_lw_vga_we_addr   = virtual_base + PIO_VGA_WE_BASE;
   h2p_lw_vga_data_addr = virtual_base + PIO_VGA_DATA_BASE;;
   *(uint32_t *)led_addr= 0;
  // *(uint32_t *)sw_addr = 0;

   printf("Select game to be played from the below list:\n");
   printf("1. Quiz\n");
   printf("2. Tic Tac Toe\n");
   printf("3. Hangman\n");
   for (i = 0; i < 640; i++)
            for (j = 0; j < 480; j++)      
              VGA_draw_point(i,j,cyan);

   scanf("%d", &option);

   if(option == 1)
   {
    Quiz();
   }

   else if(option == 2)
   {
    tictacktoe();
   }

   else if(option == 3)
   {
    hangman();
   }
  
    return 0;
}

