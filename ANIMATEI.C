#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void animate(int x , int y);

int main(){
  int gd = DETECT , gm , x = 60 , y = 25;
  initgraph(&gd , &gm , "C:\\TURBOC3\\BGI");
  animate( x , y);
  getch();
  closegraph();
  return 1;
}

void animate(int x , int y){
  clrscr();
  circle(x , y , 15);
  return;
}