#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>

void drawBox();
void initGame();
void initMarker(int x , int y);
int evaluateWinCondition();

int x , y , xb , yb , player1 = 1 , player2 = 0 , i = 0 , j = 0 , index = 0;
int xos[3][3] = {0,0,0,0,0,0,0,0,0};

int main()
{
  int gd = DETECT , gm;
  initgraph(&gd , &gm , "C:\\TURBOC3\\BGI");
  x = getmaxx()/4;
  y = getmaxy()/4;
  xb = x;
  yb = y;
  initGame();
  getch();
  closegraph();
  return 1;
}

void drawBox()
{
  rectangle(xb , yb , xb + 90 , yb + 90);
  line(xb , yb + 30 , xb + 90 , yb + 30);
  line(xb , yb + 60 , xb + 90 , yb + 60);
  line(xb + 30 , yb , xb + 30 , yb + 90);
  line(xb + 60 , yb , xb + 60 , yb + 90);
}

void initGame()
{
  drawBox();
  initMarker(x , y);
  setcolor(WHITE);
  if(kbhit())
  {
    char ch = getch();
    if(ch == 'w')
    {
      if(y != getmaxy()/4)
      {
	y = y - 30;
	i--;
	//printf("%d %d\n" , i , j);
      }
    }
    if(ch == 'a')
    {
      if(x != getmaxx()/4)
      {
	x = x - 30;
	j--;
	//printf("%d %d\n" , i , j);
      }
    }
    if(ch == 's')
    {
      if(y != getmaxy()/4 + 60)
      {
	y = y + 30;
	i++;
       //printf("%d %d\n" , i , j);
      }
    }
    if(ch == 'd')
    {
      if(x != getmaxx()/4 + 60)
      {
	x = x + 30;
	j++;
	//printf("%d %d\n" , i , j);
      }
    }
    int mark = ch;
    if(mark == 13)
    {
      if(player1 == 1)
      {
	if(xos[j][i] == 0)
	{
	player1 = 0;
	player2 = 1;
	outtextxy(x + 10 , y + 10 , "X");
	xos[j][i] = 1;
	}
      }
      else
      {
	if(xos[j][i] == 0)
	{
	player1 = 1;
	player2 = 0;
	outtextxy(x + 10 , y + 10 , "O");
	xos[j][i] = 2;
	}
      }
    }
    if(ch == 'e')
    {
    return;
    }
  }
  delay(30);
  int game = evaluateWinCondition();
  if(game == 0)
  {
    initGame();
  }
  return ;
}

void initMarker(int x , int y)
{
  setcolor(RED);
  rectangle(x , y , x + 30 , y + 30);
  delay(30);
}

int evaluateWinCondition()
{
  int w1 = 0 , w2 = 0;
  for(int i1 = 0 ; i1 < 3 ; i1++)
  {
    for(int j1 = 0 ; j1 < 3 ; j1++)
    {
      if(xos[i1][j1] != 0)
      {
	if(xos[i1][j1] == 1)
	w1++;
	else
	w2++;
      }
      if(w1 == 3)
      {
      outtextxy(150 , 50 ,"Player 1 wins");
      return 1;
      }
      if(w2 == 3)
      {
      outtextxy(150 , 50 , "Player 2 wins");
      return 2;
      }
    }
    w1 = 0 ;
    w2 = 0;
  }
  w1 = 0 ;
  w2 = 0;
  for(i1 = 0 ; i1 < 3 ; i1++)
  {
    for(int j1 = 0 ; j1 < 3 ; j1++)
    {
      if(xos[j1][i1] != 0)
      {
		if(xos[j1][i1] == 1)
		{
			w1++;
		}
		else
		{
			w2++;
		}
      }

	   if(w1 == 3)
		{
			outtextxy(150 , 50 , "P1ayer 1 wins");
			return 1;
		}
		if(w2 == 3)
		{
			outtextxy(150 , 50 , "Player 2 wins");
			return 2;
		}
    }
    w1 = 0;
    w2 = 0;
  }

  if((xos[0][0] == xos[1][1]) && (xos[1][1] == xos[2][2]))
  {
    if(xos[0][0] == 1)
    {
      outtextxy(150 , 50 , "Player 1 wins");
      return 1;
    }
    else if(xos[0][0] == 2)
    {
      outtextxy(150 , 50 , "Player 2 wins");
      return 2;
    }
  }

  if(xos[0][2] == xos[1][1] && xos[1][1] == xos[2][0])
  {
    if(xos[1][1] == 1)
    {
      outtextxy(150 , 50 , "Player 1 wins");
      return 1;
    }
    else if(xos[1][1] == 2)
    {
      outtextxy(150 , 50 , "Player 2 wins");
      return 2;
    }
  }
  return 0;
}