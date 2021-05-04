#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int x,y,x1,y1,mines[50],pressed[400]={0};
int count=0;
int main()
{
 int gd = DETECT , gm,i,r;
 x=y=x1=y1=100;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 assignmines();
 r = frame();
 getch();
 closegraph();
 for(i=0;i<50;i++)
 {
 printf("%d ",mines[i]);
 }
 for(i=0;i<400;i++)
 printf("%d ",pressed[i]);
 getch();
 return 0;
}
int assignmines()
{
int i,x,j;
for(i=0;i<50;i++)
{
/*x=(rand()*1000)%400;
for(j=0;j<i;j++)
{
if(mines[j]==x)
{
i--;
l=1;
}
}
if(l==0)
mines[i]=x;
l=0;*/
mines[i]=rand()%400;
}
return 0;
}
int frame()
{
 char ch;
 int i,j,r;
// clrscr();
 setcolor(WHITE);
 rectangle(x,y,x+200,y+200);
 for(i=x;i<x+200;i+=10)
 {
 for(j=y;j<y+200;j+=10)
 {
 rectangle(i,j,i+10,j+10);
 }
 }
 if(kbhit())
 {
 ch = getch();
 if(ch=='a')
 {
 if(x1-10>=x)
 x1-=10;
 }
 if(ch=='d')
 {
 if(x1+10<x+200)
 x1+=10;
 }
 if(ch=='s')
 {
 if(y1+10<y+200)
 y1+=10;
 }
 if(ch=='w')
 {
 if(y1-10>=y)
 y1-=10;
 }
 if(ch=='e')
 return 0;
 if(ch=='j')
 r=press(x1,y1);
 }
 marker();
 delay(40);
 frame();
 return r;
}
int marker()
{
 setcolor(RED);
 rectangle(x1,y1,x1+10,y1+10);
 return 0;
}
int press(int x1,int y1)
{
 int i,t1,t2,r;
 static int c=0;
 t1=(x1-100)/10;
 t2=(y1-100)/10;
 r=t1+(t2*20);
 pressed[r]=1;
 for(i=0;i<50;i++)
 {
 if(r==mines[i])
 {
 circle(x1+5,y1+5,5);
 showmines();
 outtextxy(50,50,"GAMEOVER");
 gotoxy(50,53);
 printf("%d %d",count,r);
 getch();
 exit(1);
 }
 }
 count++;
 for(i=0;i<50;i++)
 {
// if((r-1) == mines[i] || (r+1) == mines[i] || (r+20) == mines[i] || (r-20) == mines[i])
// {
  if((r-1) == mines[i])
  {
  if(x1 > 100 && y1 > 100)
  c++;
  }
  if(r+1 == mines[i])
  {
  if(r+1 < 400)
  c++;
  }
  if(r+20 == mines[i])
  {
  if(r+20 < 400 && x1 < x+200 && y1+10 < y+200)
  c++;
  }
  if(r-20 == mines[i])
  {
  if(r-20 >0 && x1 >= x && y1-10 >= y)
  c++;
  }
// outtextxy(x1+3,y1+3,"1");
// circle(x1+5,y1+5,5);
// getch();
// exit();
// }
 }
 if(c==0)
 outtextxy(x1+3,y1+3,"0");
 else
 {
 if(c==1)
 outtextxy(x1+3,y1+3,"1");
 else if(c==2)
 outtextxy(x1+3,y1+3,"2");
 else if(c==3)
 outtextxy(x1+3,y1+3,"3");
 else
 outtextxy(x1+3,y1+3,"4");

 c=0;
 }
 return r;
}
int showmines()
{
 int t1,t2,i;
 for(i=0;i<50;i++)
 {
 t1 = mines[i]%20;
 t2 = mines[i]/20;
 t1=t1*10+100;
 t2=t2*10+100;
 setcolor(YELLOW);
 circle(t1+5,t2+5,5);
 }
 return 0;
}