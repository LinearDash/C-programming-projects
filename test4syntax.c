#include<stdio.h>
#include <stdlib.h> 
#include<time.h>


int main(){
    srand(time(NULL));
    int player_vlaue, computer_value;
    printf("For rock(0) \nFor paper(1) \nFor sissor(2 \nPick One:)");
    scanf("%d",&player_vlaue);

    computer_value = rand()% 3;
     if (computer_value==player_vlaue)
     {printf("It,s a tie\n");}
     else if (computer_value==0 && player_vlaue==1 ||
              computer_value==1 && player_vlaue==2  ||
             computer_value==2 && player_vlaue==0 )
     {
       printf("You WON\n");}
     else
     printf("You LOST\n");
     
     

    
    return 0;

}