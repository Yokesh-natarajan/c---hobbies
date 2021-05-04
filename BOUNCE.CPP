#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

//directions = 5 still , 6 = right , 4 = left
// r = bounce size

int xBase , yBase , x , y , velocity = 0 , r = 15 , dflag = 4;
int direction = 5 , velocityLimit = 10 , jumph = 0 , jump = 0;

int drawBase(int x , int y);
int initGame(int x  , int y);
void drawBall(int x , int y);
int increaseVelocity();
int decreaseVelocity();

int main()
{
  int gd = DETECT , gm;
  initgraph(&gd , &gm , "C:\\TURBOC3\\BGI");
  yBase = (getmaxy()/4)* 3;
  drawBase(xBase , yBase);
  x = xBase + r;
  y = yBase - r;
  initGame(x , y);
  getch();
  closegraph();
  return 1;
}

int drawBase(int x , int y)
{
  line(x , y , getmaxx() , y);
  return 1;
}

int initGame(int x , int y)
{
  clrscr();
  drawBase(xBase , yBase);
  drawBall(x + velocity, y);
  decreaseVelocity();
  if(kbhit())
  {
  char ch = getch();
  if(ch == 'd')
  {
    if(direction == 4)
    {
      if(velocity == 0)
      {
	direction = 5;
      }
      else{
	dflag = 6;
	increaseVelocity();
	x-= 1 + velocity;
      }
    }
    else if(x + r < getmaxx() && direction != 8)
    {
      direction = 6;
      dflag = 6;
      x+= 1 + velocity;
      increaseVelocity();
    }
    else if(direction == 8)
    {
      dflag = 6;
      x+= 2;
    }
  }
  if(ch == 'a')
  {
    if(direction == 6)
    {
      if(velocity == 0)
      {
	direction = 5;
      }
      else{
	decreaseVelocity();
	x+= 1 + velocity;
	dflag = 4;
      }
    }
    else if(x - r > 0 && direction != 8)
    {
      direction = 4;
      dflag = 4;
      x-= 1 + velocity;
      increaseVelocity();
    }
    else if(direction == 8)
    {
      x-= 2;
      dflag = 4;
    }
  }
  if(ch == 'w')
  {
    if(direction != 8)
    {
      direction = 8;
      jump = 1;
      jumph = 1;
      y-= jumph;
    }
  }
  if(ch == 'e')
  {
    return 1;
  }
  if(direction == 8)
  {
    if(jumph < 20 && jump == 1)
    {
      jumph+= 1;
      y-= jumph;
    }
    else
    {
      jump = 0;
      if(jumph > 0)
      {
	y+= jumph;
	jumph-= 1;
      }
    }
  }
  delay(60);
  initGame(x , y);
  }
  else
  {
    delay(60);
    if(direction == 6)
    {
      initGame(x + velocity , y);
    }
    else if(direction == 4)
    {
      initGame(x - velocity , y);
    }
    else if(direction == 8)
    {
      if(jump == 1 && jumph < 10)
      {
	jumph+= 1;
	y-= jumph;
	if(dflag == 4)
	{
	initGame(x - velocity , y);
	}
	else
	{
	initGame(x + velocity , y);
	}
	increaseVelocity();
      }
      else
      {
	jump = 0;
	if(jumph > 0)
	{
	  y+= jumph;
	  jumph-= 1;
	}
	else
	{
	  direction = 5;
	  y = yBase - r;
	}
	if(dflag == 4)
	{
	initGame(x - velocity , y);
	}
	else
	{
	initGame(x + velocity , y);
	}
	increaseVelocity();
      }
    }
    else
    {
      initGame(x , y);
    }
  }
  return 0;
}

void drawBall(int x , int y)
{
  circle(x , y , r);
}

int decreaseVelocity()
{
  if(velocity > 0)
  {
    velocity--;
  }
  return velocity;
}

int increaseVelocity()
{
  if(velocity < velocityLimit)
  {
    velocity+= 5;
  }
  return velocity;
}