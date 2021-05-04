#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include"shape.c"
//#include"interfac.c"
int x,y,l,b,i=0;
//int xr,yr,r;
int xa,ya,score;
int ani();
int boundary();
int isthere();
int isdone();
int remember();
int forever();
struct brick
{
int pos[2],l1,b1,p;
}b11[100];
int main(int a)
{
 int gd=DETECT,gm,c;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 xa=getmaxx()/2;
 ya=2*getmaxy()/3;
 score=0;
 if(a==0)
 {
 forever();
 getch();
 exit(1);
 }
// c=interface();
// if(c==10)
// {
// exit(0);
// }
 line(xa-120,ya,xa+120,ya);
 x=xa-120;y=20; l=14;b=13;
 if((score%2)==0)
 shapecomp(x,y,l,b);
 else
 shape(x,y,l,b);
 ani();
// ani(x,y,14,13);
 forever();
 getch();
 closegraph();
 return 0;
}
int ani()
{
char cc;
//int i=0;
clrscr();
boundary();
forever();
if(kbhit())
{
cc=getch();
if(cc=='a')
{
if(x>=xa-120)
x--;
//if((score%2)!=0)
//y--;
}
if(cc=='d')
{
if(x<=xa+120)
x++;
if((score%2)!=0)
y++;
}
if(cc=='s')
{
if((score%2)==0)
{
//inverse(x,y,l,b);
i++;
}
else
{
int t;
t=l;
l=b;
b=t;
}
}
}
//if((y+(3*l))<=ya)
//{
if(isthere()==0)
{
y++;
if((score%2)==0)
{
if((i%2)==0)
{
shapecomp(x,y,l,b);
}
else
{
reverse(x,y,l,b);
}
}
else
{
shape(x,y,l,b);
}
delay(20);
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
int boundary()
{
line(xa-120,ya,xa+120,ya);
return 1;
}
int isthere()
{
int i1;
if((score%2)==0)
 {
for(i1=0;i1<(2*b);i1++)
  {
if((getpixel(0,0)==getpixel(x+i1,y+3*l+1)))
{}
else
   {
return 1;
   }
  }
 }
else
{
for(i1=0;i1<l;i1++)
{
if(getpixel(0,200)==getpixel(x+i1,y+1+b))
{}
else
{
return 1;
}
}
}
return 0;
}
int remember()
{
//for(i=0;i<2;i++)
b11[score].pos[0]=x;
b11[score].pos[1]=y;
b11[score].l1=l;
b11[score].b1=b;
//if((score%2)==0)
b11[score].p=i;
score++;
return 1;
}
int isdone()
{
if(score>3)
{
outtextxy(20,20,"score");
gotoxy(0,20);printf("%d",score);
forever();
getch();
main(0);
//exit(1);
//outtextxy(20,24,score);
}
else
{
x=xa-120;y=20;l=14;b=13;
}
return 0;
}
int forever()
{
if(score==0)
{}
else
{
int i1;
for(i1=0;i1<score;i1++)
{
if((i1%2)==0)
{
if((b11[i1].p%2)==0)
{
shapecomp(b11[i1].pos[0],b11[i1].pos[1],b11[i1].l1,b11[i1].b1);
}
else
{
reverse(b11[i1].pos[0],b11[i1].pos[1],b11[i1].l1,b11[i1].b1);
}
}
else
{
shape(b11[i].pos[0],b11[i1].pos[1],b11[i1].l1,b11[i1].b1);
}
}
}
return 1;
}