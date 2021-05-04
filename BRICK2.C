#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include"shape.c"
int x,y,ape,l,b,xa,ya,c=1,score=0,i=0;
xa=getmaxx()/3;
ya=2*getmaxy()/3;  x=xa-120;y=0;
int initialize();
int isthere();
int boundary();
int ani();
struct brick
{
int pos[2],l,b,p;
}b1[100];
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
ape=rand();
initialize();
ani();
getch();
closegraph();
return 1;
}
int initialize()
{
if((x<xa+120)&&(c==1))
{
x+=i;
}
else
{
c=0;i=1;
}
if(x>xa+120&&(c==0))
{
x-=i;
}
else
{
c=1;i=1;
}
return 0;
}
int boundary()
{
line(xa-120,ya,xa+120,ya);
return 0;
}
int ani()
{
char ch;
clrscr();
boundary();
if(kbhit())
{
ch=getch();
if(ch=='a')
{
if(x>xa-120)
x+=2;
}
if(ch=='d')
{
if(x<xa+120)
x-=2;
}
}
if(isthere()==0)
{
if((ape%2)==0)
shapecomp(x,y,l,b);
else
shape(x,y,l,b);
delay(27);
ani();
}
else
{
remember();
isdone();
ani();
}
return 0;
}
int remember()
{
b1[score].pos[0]=x;
b1[score].pos[1]=y;
b1[score].l1=l;
b1[score].b1=b;
i++;
ape=rand();
initialize();
return 0;
}
int isthere()
{
int j;
if((ape%2)==0)
{
for(j=0;j<2*b;j++)
{
if(getpixel(100,0)==getpixel(x+j,y+3*l+1))
{
return 0;
}
}
}
else
{
for(j=0;j<b;j++)
{
if(getpixel(100,0)==getpixel(x+j,y+1))
{
return 0;
}
}
}
}