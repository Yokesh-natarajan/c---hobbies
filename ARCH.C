   #include<stdio.h>
   #include<conio.h>
   #include<graphics.h>
   #include"shape.h"
   int x=200,y=350,r=40,b=0;
   int main()
   {
   int gd = DETECT , gm;
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   bow(200,350,40);
   string(x,y,r,b);
   frame();
   setbkcolor(BLACK);
   getch();
   closegraph();
   return 0;
   }
   int frame()
   {
   char ch;
   clrscr();
   setbkcolor(BLACK);
   bow(x,y,r);
   string(x,y,r,b);
   if(kbhit())
   {
   ch = getch();
   if(ch == 'a' && x > 0 && b == 0)
   x-=5;
   else
   b = 0;
   if(ch == 'd'&& x < getmaxx() && b == 0)
   x+=5;
   else
   b = 0;
   if(ch == 'e')
   return 0;
   if(ch == 'j')
   {
   arrow(x,y,r,b);
   b++;
   }
   }
   delay(30);
   frame();
   return 0;
   }