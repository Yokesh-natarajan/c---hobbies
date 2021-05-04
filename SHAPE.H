#include<graphics.h>
#include<conio.h>
int shape(int x,int y,int l,int b)
{
rectangle(x,y,x+l,y+b);
return 1;
}
int shapec(int x,int y,int r)
{
circle(x,y,r);
return 1;
}
int shapet(int x,int y,int l)
{
line(x,y,x+l,y);
line(x,y,x,y-l);
line(x+l,y,x,y-l);
//floodfill(x+1,y+1,CYAN);
return 1;
}
int shapecomp(int x,int y,int l,int b)
{
rectangle(x,y,x+b,y+3*l);
rectangle(x+b,y+3*l,x+2*b,y+3*l-b);
return 1;
}
int reverse(int x,int y,int l,int b)
{
rectangle(x,y,x+b,y+3*l);
rectangle(x,y+3*l,x-2*b,y+3*l-b);
return 1;
}
int rod(int x,int y,int l,int b)
{
rectangle(x,y,x+b,y+3*l);
return 1;
}
int inverserod(int x,int y,int l,int b)
{
rectangle(x,y,x+3*l,y+b);
return 1;
}
int ship(int x,int y,int l)
{
shapet(x,y,l);
rectangle(x,y,x+35,y+10);
circle(x+35,y+10/2,10/2);
line(x+15,y+10/2,x+25,y+10/2);
return 1;
}
int boundary(int xa,int ya)
{
for(;xa<getmaxx();)
{
line(xa,ya,xa+30,(ya+30)%70);
line(xa+30,(ya+30)%70,xa+45,(ya+30)%70-15);
xa=xa+45;
ya=(ya+30)%70-15;
}
return 0;
}
int target(int x , int y , int r)
{

}
int bow(int x,int y,int r)
{
 int y1,r1,i;
 y1 = y-300;
 r1 = r-30;
 setcolor(RED);
 circle(x,y-300,r-30);
 line(x-r1,y1,x+r1,y1);
 line(x,y1+r1,x,y1-r1);
 setcolor(BROWN);
 for(i=6;i>0;i--)
 ellipse(x,y+i,0,180,150,60);
 ellipse(x,y,0,180,150,60);
// string(x,y,150);
// setcolor(WHITE);
// line(x-150,y,x+150,y);
 return 0;
}
int arrow(int x,int y,int l,int b)
{
 line(x , y , x , y - 45);
 return 0;
}
int string(int x,int y,int l,int b)
{
 setcolor(WHITE);
 line(x-135,y,x+135,y);
 return 0;
}