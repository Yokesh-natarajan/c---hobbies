#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

// objective - creating and moving the snake

int snakex = 25 , snakey = 40 , length = 35;
int borderx = 0 , bordery = 0 , direction = 0 , index = 0 , start = 0;

// direction values = 0 - right , 1 - up , 2 - down , 3 - left

int animate();

struct snake
{
	int x;
	int y;
	int length;
	int direction;
}snake[10];

int main()
{
int gd = DETECT , gm;
initgraph(&gd , &gm , "C:\\TURBOC3\\BGI");
snake[index].x = snakex;
snake[index].y = snakey;
snake[index].length = length;
snake[index].direction = direction;
index++;
animate();
getch();
closegraph();
return 0;
}

int animate()
{
clrscr();
char ch;
	if(kbhit())
	{
	ch = getch();
	if(ch == 'a')
	{
	if(direction != 0)
	{
	direction = 3;
	snake[index].x = snakex;
	snake[index].y = snakey;
	snake[index].length = length;
	snake[index].direction = direction;
	index++;
	}
	}
	if(ch == 'd')
	{
	if(direction != 3)
	{
	direction = 0;
	snake[index].x = snakex;
	snake[index].y = snakey;
	snake[index].length = length;
	snake[index].direction = direction;
	index++;
	}
	}
	if(ch == 'w')
	{
	if(direction != 1)
	{
	direction = 2;
	snake[index].x = snakex;
	snake[index].y = snakey;
	snake[index].length = length;
	snake[index].direction = direction;
	index++;
	}
	}
	if(ch == 's')
	{
	if(direction != 2)
	{
	direction = 1;
	snake[index].x = snakex;
	snake[index].y = snakey;
	snake[index].length = length;
	snake[index].direction = direction;
	index++;
	}
	}
	if(ch == 'q')
	{
	return 0;
	}
	}
	for(int j = start ; j < index ; j++)
	{
	if(snake[j].direction == 0)
	{
	for(int i = 0 ; i < length ; i++)
	{
	putpixel(snake[j].x + i , sin(snake[j].x + i) + snake[j].y , 5);
	putpixel(snake[j].x + i + 1 , sin(snake[j].x + i) + snake[j].y , 5);
	}
	snake[j].x += 3;
	snakex += 3;
	snake[j].length--;
	if(snake[j].length == 0)
	start++;
	}
	if(snake[j].direction == 3)
	{
	for(int i = 0 ; i < length ; i++)
	{
	putpixel(snake[j].x - i , sin(snake[j].x + i) + snake[j].y , 5);
	putpixel(snake[j].x - i + 1 , sin(snake[j].x + i) + snake[j].y , 5);
	}
	snake[j].x -= 3;
	snakex -= 3;
	snake[j].length--;
	if(snake[j].length == 0)
	start++;
	}
	if(snake[j].direction == 1)
	{
	 for(int i = 0 ; i < length ; i++)
	 {
	 putpixel(sin(snake[j].y + i) + snake[j].x , snake[j].y - i , 5);
	 putpixel(sin(snake[j].y + i) + snake[j].x , snake[j].y - i + 1 , 5);
	 }
	 snake[j].y += 3;
	 snakey += 3;
	 snake[j].length--;
	 if(snake[j].length == 0)
	 start++;
	}
	if(snake[j].direction == 2)
	{
	for(int i = 0 ; i < length ; i++)
	{
	putpixel(sin(snake[j].y + i) + snake[j].x , snake[j].y + i , 5);
	putpixel(sin(snake[j].y + i) + snake[j].x , snake[j].y + i + 1 , 5);
	}
	snake[j].y -= 3;
	snakey -= 3;
	snake[j].length--;
	if(snake[j].length == 0)
	start++;
	}
	}
	printf("%d      %d" , snakex , snakey);
	if(start == index)
	{
	start = index = 0;
	}
       //	rectangle(borderx , bordery , getMaxx() , getMaxy());

	delay(90);
	return animate();
}