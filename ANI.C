#include<conio.h>
#include"shape.c"
#include<graphics.h>
//int xa=getmaxx()/2;
//int ya=2*getmaxy()/3;
int ani(int x,int y,int l,int b)
{
//clrscr();
char cc;
int xa=getmaxx()/2;
clrscr();
boundary();
if(kbhit())
{
cc=getch();
if(cc=='a')
{
if(x>=xa-120)
{
x+=2;
}
}
if(cc=='d')
{
if((x+b)<=xa+120)
{
x-=2;
}
}
}
if(getpixel(0,0)==getpixel(x+1,y+1+3*l))
{
y++;
shapecomp(x,y,l,b);
}
return (x,y);
}
int boundary()
{
int xa=getmaxx()/2;
int ya=2*getmaxy()/3;
line(xa-120,ya,xa+120,ya);
return 1;
}