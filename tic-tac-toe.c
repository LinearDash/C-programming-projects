/* This is tic tac toe 
This was made with the help of : https://www.youtube.com/watch?v=_889aB2D1KI&t=486s */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char Board [3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void ResetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
         {
             Board[i][j] = ' ';
         }
    }
    
}
void PrintBoard()
{
    printf(" %c | %c | %c ",Board[0][0],Board[0][1],Board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",Board[1][0],Board[1][1],Board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c \n",Board[2][0],Board[2][1],Board[2][2]);
    
}
void PlayerMove()
{
    int x;
    int y;
   
    do
    {
        printf("Enter the Row(1-3):");
        scanf("%d",&x);
        x--;
        printf("Enter the Columb(1-3):");
        scanf("%d",&y);
        y--;
        if(Board[x][y] == ' ')
        {
            Board[x][y] = PLAYER;
        }
        else
        {
            printf("Invalid move\n");
            PrintBoard();
            PlayerMove();
        }
       // printf("Row: %d \nColumb: %d",x,y);
    } while (Board[x][y] == ' ');
    
}


int CheckBoard()
{
 int freespace=9;
 for (int i = 0; i < 3; i++)
 {
    for (int j = 0; j < 3; j++)
     {
        if (Board[i][j] != ' ' )
        {
            freespace--;
        }
     }
 }
 return freespace;
}

char CheckWinner()
{
    for (int i = 0; i < 3; i++)
    {
      if ( Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2])
      {
        return Board[i][0];
      }

      if ( Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i])
      {
        return Board[0][i];
      }
    }
     if ( Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2])
      {
        return Board[0][0];
      }
     if ( Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0])
      {
        return Board[0][2];
      }
    return ' ';
    
}
void PrintWinner(char Winner){ 
    if(Winner == PLAYER)
    {
        printf("You Won!\n");
    }
    else if (Winner == COMPUTER)
    {
        printf("You Lost!\n");
    }
    else
    {
        printf("It's a Tie!\n");
    }
}
/*void TestScan(){
     for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
         {
            printf("enter the characters: ");
            scanf("%c",&Board[i][j]);
         }
    }
}

void TestPrint(){
     for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
         {
             printf("%c",Board[i][j]);
         }
    }
}
*/
void ComputerMove(){
    int x;
    int y;
    srand(time(NULL));
     if (CheckBoard > 0)
     {
        do
     {
       x = rand() %3;
       y = rand() %3;
       //printf("random x:%d \nrandom y:%d \n",x,y);
     } while (Board[x][y] != ' ');
     Board[x][y] = COMPUTER;
     }
     else
     {
        PrintWinner(' ');
     }
     
     
}

int main()
{
    char Winner = ' ';
    char response = ' ';
    
     do
    {
       ResetBoard();
       while (Winner == ' ' && CheckBoard() != 0)
       {
        PrintBoard();
        PlayerMove();
        
        Winner = CheckWinner();
        if (Winner != ' ' || CheckBoard() == 0)
        {
            break;
        }
        
        ComputerMove();
        Winner = CheckWinner();
        if (Winner != ' ' || CheckBoard() == 0)
        {
            break;
        }
        
        
        
       }
      PrintBoard();
      PrintWinner(Winner);
      Winner = ' ';
 
      printf("\n Do you want to play again (Y/N): \n");
      scanf("%c");
      scanf("%c",&response);
      response = toupper(response);
      
    } while (response == 'Y');
        

    printf("Thank You for Playing");
    return 0;
     
     
    //printf("The Free Space is %d",CheckBoard());

}