#include<termios.h>
#include<unistd.h>
#include<stdio.h>
#include<graphics.h>
int main()
{
int i;
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
setcolor(GREEN);
setbkcolor(WHITE);
_dda(0,0,getmaxx(),getmaxy());
//circle(100,100,50);
//line(10,10,100,100);
for(i=0;i<900;i++){
	//setcolor(i%16);
//setlinestyle(133,133,200);	//setbkcolor(i+1);
//	circle(0,0,i+i+i);
//	circle(getmaxx(),0,i+i+i);
//	circle(getmaxx(),getmaxy(),i+i+i);
	setcolor(BLACK);
	circle(0+i,getmaxy()/2,100);
	floodfill(i,getmaxy()/2,BLACK);
	setcolor(WHITE);
	circle(0+i,getmaxy()/2,100);
	floodfill(i,getmaxy()/2,WHITE);
	delay(1);
	//delay();
//	circle(getmaxx()/2,getmaxy()/2,getmaxx()/2-i);
//	ellipse(getmaxx()/2,getmaxy()/2,360,360,,20);
//	ellipse(getmaxx()/2,getmaxy()/2,10,10,10,20);
	//rectangle(getmaxx()/2-i,getmaxy()/2-i,getmaxx()/2+i,getmaxy()/2+i);
	delay(100);
}
//setlinestyle(10,10,100);
//_dda(10,10,100,100);
while(!kbhit());
closegraph();
getch();
return 0;
}
