#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include"ship1.c"
//#include<shape.h>
int main()
{
int gd=DETECT,gm,i;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
outtextxy(250,150,"1.PLAY");
outtextxy(250,165,"2.OPTIONS");
outtextxy(250,180,"3.EXIT");
i=getch();
//printf("%d",i);
if((i-48)==1)
{
//printf("%d",i);
lvl1();
ini();
main();
}
else if((i-48)==2)
{
clrscr();
setcolor(RED);
outtextxy(250,150,"wasd to move");
outtextxy(250,175,"j to shoot bullets and k for raygun");
getch();
main();
}
else
{
exit(0);
}
getch();
closegraph();
return 0;
}