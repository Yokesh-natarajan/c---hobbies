#include<graphics.h>
#include<conio.h>
int shape(int x,int y,int x1,int y1)
{
rectangle(x,y,x1,y1);
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
line(x,y,x,y+l);
line(x+l,y,x,y+l);
return 1;
}
int shapecomp(int x,int y,int l,int b)
{
rectangle(x,y,x+b,y+3*l);
rectangle(x+b,y+3*l,x+2*b,y+3*l-b);
return 1;
}