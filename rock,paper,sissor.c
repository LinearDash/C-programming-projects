#include<stdio.h>
#include <stdlib.h> 
#include<time.h>
#include<ctype.h>


int main(){
    srand(time(NULL));
    int player_vlaue, computer_value;
    char respond=' ';
    do
    {
       int player_vlaue, computer_value;
       printf("For rock(1) \nFor paper(2) \nFor sissor(3) \nPick One:");
       scanf("%d",&player_vlaue);
       player_vlaue = player_vlaue-1 ;

     computer_value = rand()% 3;
      if(computer_value==0){
         printf("Computer picked Rock\n");
         }else if(computer_value==1){
          printf("Computer picked paper\n");
         }else printf("Computer picked sissor\n");
          
     if (computer_value==player_vlaue)
     {printf("It,s a tie\n");}
     else if (computer_value==0 && player_vlaue==1 ||
              computer_value==1 && player_vlaue==2  ||
             computer_value==2 && player_vlaue==0 )
     {
       printf("You WON\n");}
     else
     printf("You LOST\n");
     printf("\n Do you want to play again (Y/N): \n");
     scanf("%c");
     scanf("%c",&respond);
     respond = toupper(respond);
     
    } while (respond == 'Y');
    printf("thanks for playing!");
     
    return 0;

}