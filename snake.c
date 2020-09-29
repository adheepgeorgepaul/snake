#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int Nx = 20, Ny = 20, GameOver;
int SnakeX, SnakeY, FruitX, FruitY, Score, flag; 



void setup()
{   
    int Label1, Label2;
    GameOver = 0;
    SnakeX = Nx/2;
    SnakeY = Ny/2;

    Label1:
    FruitX = rand() % 20;
    if(FruitX == 0 )
        goto Label1;

    Label2:
    FruitY = rand() % 20;
    if(FruitY == 0)
        goto Label2;

    Score = 0;
}

void draw(){
        int i, j;
        system("cls");
        for(i = 0; i < Nx; i++)
        {
            for(j = 0; j < Ny; j++)
            {
                if(i == 0 || i == (Nx-1) || j == 0 || j ==  (Ny-1))
                {
                    printf("*");
                }
                else
                {
                    if((i == SnakeX) && (j == SnakeY))
                        printf("o");

                    else if( (i == FruitX) && (j == FruitY))
                        printf("F");
                    
                    else
                    printf(" ");
                }
                
            }
            printf("\n");
        }
}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a': flag = 1;
                      break;
            
            case 's': flag = 2;
                      break;

            case 'w': flag = 3;
                      break;
                    
            case 'd': flag = 4;
                      break;
           case 'x': GameOver = 1;
                      break;
        }   
    }
}

void makelogic()
{
    switch(flag)
    {
        case 1: SnakeY--;
                break;
        case 2: SnakeX++;
                break;
        case 3: SnakeX--;
                break;
        case 4: SnakeY++;
                break;
        default: break;

    }
}
int main()
{   
    setup();
    while(1)
    {
        draw();
        input();
        makelogic();    
      
    }
    
    return 0;

}
