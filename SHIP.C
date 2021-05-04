#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include"shape.c"
int x,y,l,points[8],xa,ya,b1,b2,r1,r2,p,i,count=0,dead;
int coloer();
int bullet();
int ani();
int raygun();
int isthere();
int background();
struct bulle
{
int b11,b22;
}b[20];
int main()
{
int gd=DETECT,gm,n;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
x=25;y=95;l=13;b1=x+36;b2=y+5;r1=250;r2=95,p=10,dead=0,xa=0,ya=30;
b[i].b11=b1;
b[i].b22=b2;
ship(x,y,l);
coloer();
background();
ani();
//fillpoly(4,points);
getch();
closegraph();
return 0;
}
int coloer()
{
points[0]=x;
points[1]=y;
points[2]=x;
points[3]=y+10;
points[4]=x+35;
points[5]=y+10;
points[6]=x+35;
points[7]=y;
fillpoly(4,points);
return 0;
}
int ani()
{
char cc;
clrscr();
background();
bullet();
rock();
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
b1=x+36;
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
b1=x+36;
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
}
}
}
if(cc=='s')
{
if(getpixel(x,y+11)==getpixel(0,0))
{
if((y+11)<getmaxy()/2)
y+=2;
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
coloer();
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
line(x+35,y+5,getmaxx(),y+5);
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
if(dead==0)
{
circle(r1,r2,7);
line(r1-20,r2-7,r1-20,r2+7);
r1--;
for(i=0;i<=14;i++)
{
if(getpixel(r1-20,r2-i+7)==getpixel(r1-19,r2-i+7))
dead=1;
}
return 1;
}
else
{
outtextxy(getmaxx()/2,getmaxy()/2,"OVER");
delay(120);
getch();
exit(1);
}
r1=250;
return 0;
}

