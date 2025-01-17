//Programer clock v1.04
//made by Admiral - 15/01/25
//last edited on: 17/01/25
#include <stdio.h>
#include <time.h>
#include <windows.h>
//variables---------------------------------------------------------------------
char mode;//stores user input
time_t rawtime;//variable for raw time data from time.h
struct tm*  time_;
//functions---------------------------------------------------------------------
void Clock(char mode){//mode is either c or w
  while(1){
      time(&rawtime);
      time_ = localtime(&rawtime);
      if(mode == 'c'){
	if(time_->tm_hour >= 21 || time_->tm_hour < 6){//night
	  printf("\033[1;96m");//sets color to cyan
	  printf("%i:%.2i:%.2i", time_->tm_hour, time_->tm_min, time_->tm_sec);
	  Sleep(1000);//waits 1s
	  system("cls");//refreshes the 'screen' (terminal)
	}
	else if((time_->tm_hour >= 6 || time_->tm_hour < 8)||(time_->tm_hour >= 19 || time_->tm_hour < 21)){//dusk/dawn
	  printf("\033[1;93m");//sets color to yellow
	  printf("%i:%.2i:%.2i", time_->tm_hour, time_->tm_min, time_->tm_sec);
	  Sleep(1000);//waits 1s
	  system("cls");//refreshes the 'screen' (terminal)
	}
	else{//day
	  printf("\033[1;97m");//sets color to white
	  printf("%i:%.2i:%.2i", time_->tm_hour, time_->tm_min, time_->tm_sec);
	  Sleep(1000);//waits 1s
	  system("cls");//refreshes the 'screen' (terminal)
	}
      }
      else{//mode is 'w'
	printf("%i:%.2i:%.2i", time_->tm_hour, time_->tm_min, time_->tm_sec);
	Sleep(1000);//waits 1s
	system("cls");//refreshes the 'screen' (terminal)
      }
  }
}//clock itself
//MAIN--------------------------------------------------------------------------
int main(void) {
  printf("Mode? (h/c/w): ");//asks user to input which mode of the clock they want to use
  scanf("%c", &mode);//receives user input
  getchar();//catches the user enter
  switch(mode){
  case 'h'://main help case was entered
  h://goto mark
    system("cls");//refreshes the 'screen' (terminal)
    printf("Did you call for help?\n   This is a clock application.\n   It literally just opens in your terminal and displays digital clock.\n   You can scale it however you want.\n  Modes:\n   h - Help: displays this dialog.\n   c - Cycle day/night: changes color depending on the hour of day.\n       Cannot be changed manually.\n       Set to Morning/Evening (6-8AM)/(7-9PM), Day (8AM - 7PM) and Night (9PM - 6AM).\n   w - White: displays clock normally, only in white color.\n\nPress Enter to continue...");
    getchar();//confirmation enter
    system("cls");//refreshes the 'screen' (terminal)
    printf("Mode? (h/c/w): ");//asks user to input which mode of the clock they want to use
    scanf("%c", &mode);//receives user input
    getchar();//catches the user enter
    switch(mode){//beginning of help switch
    case 'h'://help case was entered
      goto h;//goes to top of main help case
      break;//end of help case
    case 'c'://cycle case was entered
      goto c;//goes to top of main cycle case
      break;//end of cycle case
    case 'w'://white case was entered
      goto w;//goes to top of main white case
      break;//end of white case
    default://default case was entered - user error
      goto def;//goes to top of main default cases
      break;//end of default case
    }//end of help switch
    break;//end of main help case-----------------------------------------------
  case 'c'://main cycle case was entered
  c://goto mark
    system("cls");//refreshes the 'screen' (terminal)
    printf("Cycle mode was selected!\nStarting up");
    for(int i = 0; i<7;i++){
      Sleep(550);//waits 550 ms
      printf(".");
    }
    system("cls");//refreshes the 'screen' (terminal)
    Clock(mode);//clock itself
    break;//end of main cycle case----------------------------------------------
  case 'w'://main white cycle case was entered
  w://goto mark
    system("cls");//refreshes the 'screen' (terminal)
    printf("White mode was selected!\nStarting up");
    for(int i = 0; i<5;i++){
      Sleep(450);//waits 450 ms
      printf(".");
    }
    system("cls");//refreshes the 'screen' (terminal)
    Clock(mode);//clock itself
    break;//end of main white case----------------------------------------------
  default://main default case was entered
  def://goto mark
    printf("Invalid mode was entered!\nExiting...");
    getchar();//confirmation enter
    return 1;//end of main default case--------------------------------------------
  }
  return 0;
}
//Original clock mechanism
/* 
 while(1){
    time(&rawtime);
    time_ = localtime(&rawtime);
    //printf("%i:%i:%i %i %i %i\n", time_->tm_hour, time_->tm_min, time_->tm_sec, time_->tm_mday, time_->tm_mon+1, time_->tm_year+1900);
    printf("\033[1;32m");
    printf("%i:%.2i:%.2i", time_->tm_hour, time_->tm_min, time_->tm_sec);
    Sleep(1000);
    system("cls");//refreshes the 'screen' (terminal)
    }
  */
