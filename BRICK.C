#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include"shape.c"
//#include"interfac.c"
void boundary();
int ani();
int isdone();
void remember();
int isthere();
int forever();
int xa,xb,ya,yb;
int x,y,x1,y1;
int count;
struct brick
{
int pos[4];
}b[100];
int main()
{
int gd=DETECT,gm;
count=0;
//area=0;          mainarea=0;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
xa=(getmaxx()/2)-100,ya=(getmaxy()/2),xb=(getmaxx()/2)+100,yb=(getmaxy()/2);
line(xa,ya,xb,yb);
//interface();
x=xa,y=50,x1=xa+40,y1=100;
//rectangle(x,y,x1,y1);
rectangle(x,y,x1,y1);
ani();
getch();
closegraph();
return 0;
}
void boundary()
{
line(xa,ya,xb,yb);
}
int ani()
{
 char cc;
 int a;
 clrscr();
 boundary();
 forever();
 if(kbhit())
 {
 cc = getch();
 if(cc=='a')
 {
 if(x>=xa)
 {
 x-=2;x1-=2;   }
 }
 if(cc=='d')
 {
 if(x1<=xb)
 {
 x+=2;x1+=2; }
 }
 }
 if(y1<=ya)
 {
 if(isthere()==0)
 {
 rectangle(x,y++,x1,y1++);
 delay(30);
 ani();
 }
 else
 {
 remember();
 isdone();
 return 1;
 }
 }
 else
 {
 remember();
 isdone();
 }
 return 1;
}
int isdone()
{
if(count<=2)
{
//printf("%d",count);delay(100);
ani();
}
else
{
outtextxy(20,20,"OVER");  // exit(0);
//return 1;
}
return 1;
}
void remember()
{
b[count].pos[0]=x;
b[count].pos[1]=y;
b[count].pos[2]=x1;
b[count].pos[3]=y1;
count++;
x=xa;y=50;y1=100;x1=x+40;
}
int isthere()
{
int c;
c=getpixel(0,0);
if(c==getpixel(x,y1+1))
return 0;
else
return 1;
/*for(i=y1+1;i<(y1+1);i++)
{
if(c==getpixel(x1+1,i)==0)
{
l=0;
}
else
{
l=1;
return l;
}
}
return l;   */
}
int forever()
{
int i;
if(count==0)
{
//return 0;
}
else
{
for(i=0;i<count;i++)
{
rectangle(b[i].pos[0],b[i].pos[1],b[i].pos[2],b[i].pos[3]);
}
}
return 0;
}