#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include"shape.c"
int x,y,l,points[8],xa,ya,b1,b2,r1,r2,p,i,count=0,dead,score=0,timer,disable=0;
int coloer();
int bullet();
int ani();
int raygun();
int isthere();
int background();
//int script();
int destroy();
struct bulle
{
int b11,b22;
}b[20];
int lvl1()
{
/*int gd=DETECT,gm,n;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");*/
x=25;y=95;l=13;b1=x+36;b2=y+5;r1=250;r2=95,p=10,dead=0,xa=0,ya=30,timer=900;
b[i].b11=b1;
b[i].b22=b2;
ship(x,y,l);
background();
//script();
ani();
//fillpoly(4,points);
getch();
//closegraph();
return 0;
}
int ani()
{
char cc;
int t;
clrscr();
background();
bullet();
t=rock();
if(t==2)
return 1;
//script();
if(kbhit())
{
cc=getch();
if(cc=='a')
{
if(getpixel(x-1,y-13)==getpixel(0,0))
{
if(getpixel(x-1,y+10)==getpixel(0,0))
{
if(x>0)
{
x--;
if(b1==(x+36))
b2=y+5;
}
}
}
}
if(cc=='d')
{
if(getpixel(x+36,y)==getpixel(0,0))
{
if(getpixel(x+36,y+10)==getpixel(0,0))
{
if((x+40)<getmaxx()/2)
{
x+=2;
if(b1==x+36)
b2=x+5;
}
}
}
}
if(cc=='w')
{
if(getpixel(x,y-14)==getpixel(0,0))
{
if(getpixel(x+35,y-1)==getpixel(0,0))
{
if((y-14)>0)
y-=2;
if(b1==x+36)
b2=y+5;
}
}
}
if(cc=='s')
{
if(getpixel(x,y+11)==getpixel(0,0))
{
if((y+11)<getmaxy())
y+=2;
if(b1==x+36)
b2=y+5;
}
}
if(cc=='k')
raygun();
//if(cc=='sd')
//{
//y--;x++;
//}
if(cc=='j')
{
if(b1==x+36)
b1++;
//b[i].b11++;
//i++;
//count++;
bullet();
}
}
ship(x,y,l);
delay(70);
if(x<200)
ani();
else
return 0;
//ship(x,y,l);
//coloer();
return 5;
}
int raygun()
{
int k=0;
if(disable<=0)
{
line(x+35,y+5,getmaxx(),y+5);
disable=50;
for(k=0;k<14;k++)
{
if(y+5==r2+k-7)
{
dead=1;
disable=500;
return 0;
}
}
}
else
{
disable-=3;
}
return 0;
}
int background()
{
count++;
for(xa=0;xa<getmaxx();)
{
line(xa,ya,xa+30,(ya+30)%70);
line(xa+30,(ya+30)%70,xa+45,(ya+30)%70-15);
xa=xa+45;
ya=(ya+30)%70-15;
}
ya=ya-count;
if(count==20)
count=0;
/*if((ya>20)&&(count!=0))
{
ya=ya-1;
count--;
}
else
{
ya=ya+10;
count--;
} */
return 0;
}
int bullet()
{
if(b1==(x+36))
return 0;
else
{
if(b1<getmaxx())
{
line(b1,b2,b1+5,b2);
b1=b1+10;
return 1;
}
else
{
b1=x+36;
b2=y+5;
}
}
return 0;
/*int j;
if(b[i].b11==x+36)
{
return 0;
}
else
{
for(j=0;j<count;j++)
{
if(b[j].b11<getmaxx())
{
line(b[j].b11,b[j].b22,b[j].b11+5,b[j].b22);
b[j].b11+=10;
//b[i].b11=b1;
}
else
{
b[j].b11=x+36;
b[j].b22=y+5;
count--;
if(i>19)
i=0;
}
}
//b[i+1].b11=x+36;
} */
//return 0;
}
int rock()
{
int i;
if((dead==0)&&(score<6))
{
circle(r1,r2,7);
line(r1-20,r2-7,r1-20,r2+7);
r1--;
for(i=0;i<=14;i++)
{
if(getpixel(r1-20,r2-i+7)==getpixel(r1-19,r2-i+7))
dead=1;
if((r1-19)==(x+36))
{
dead=1;
outtextxy(250,100,"OVER");
delay(20);
getch();
exit(2);
}
//if(r2>x)
//r2--;
}
return 1;
}
else
{
//outtextxy(getmaxx()/2,getmaxy()/2,"OVER");
delay(120);
destroy();
//exit(1);
r1=250+r1;
r2=r2+100;
dead=0;
if(r1>=getmaxx())
{
r1=250;
return 0;
}
if(r2>=getmaxy())
{
r2=100;
return 0;
}
score++;
if(score==6)
return 2;
}
return 0;
}
/*int script()
{
if(score==0)
{
setcolor(BLACK);
outtextxy(50,350,"COMMANDER:Wake up cadett wake up......");
outtextxy(50,365,"YOU:uhhhh.....");
return 1;
}
else if(score==1)
{
setcolor(BLACK);
outtextxy(50,350,"COMMANDER:Good grief you are alive.We are currently in a space distortion unable to find a way");
outtextxy(50,365,"YOU:...");
outtextxy(50,380,"COMMANDER:I don't remember much.Well for now go through this distortion.");
return 1;
}
else if(score<=5)
{
outtextxy(50,350,"COMMANDER:I salvaged the ship and found our mechanisms destroyed.");
outtextxy(50,365,"It's so bad isuspect something from the inside.i've sealed all the doors.");
outtextxy(50,380,"Let's go through the distortion.Make sure you dont come in contact with those plasmas or ....");
return 1;
}
else
{}
return 0;
} */
int destroy()
{
int k,r=7;
for(k=0;k<7;k++)
{
clrscr();
ship(x,y,l);
background();
circle(r1,r2,r--);
delay(30);
}
return 0;
}
int ini()
{
score=0;
return 1;
}