#include<termios.h>
#include<unistd.h>
#include<stdio.h>
#include<graphics.h>
int mod(int);
int sign(int);
int main()
{
	 
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");


	int x1,y1,x2,y2,nod_x,nod_y,length,i=1;
	float ru_x,ru_y,x,y;
	/* Here x1,y1 and x2,y2 are the coordinates of line
	 * nod denotes number of difflections
	 * length denotes length of the line
	 * ru denotes raster unit or difflection voltage
	 * x any y are plotting pixels
	 */

	system("tput clear");
	grprintf("Enter the coordinates of point 1 (x1,y1) : ");
	grscanf("%d %d",&x1,&y1);
	fflush(stdin);
	grprintf("Enter the coordinates of point 2 (x2,y2) : ");
	grscanf("%d %d",&x2,&y2);
	nod_x=mod(x2-x1);
	nod_y=mod(y2-y1);
	if (nod_x>=nod_y)
		length=nod_x;
	else
		length=nod_y;
	ru_x=(float)(x2-x1)/length;
	ru_y=(float)(y2-y1)/length;
	x=x1+0.5*sign(ru_x);
	y=y1+0.5*sign(ru_y);

	while(i<=length)
	{
		putpixel((int)x,(int)y,BLACK);
		x=x+ru_x;
		y=y+ru_y;
		i++;
	}
	grgetch();
	getch();
	return 0;
}

int mod(int num)
{
	if(num<0)
		return (-num);
	else
		return num;
}

int sign(int num)
{
	if(num<0)
		return -1;
	else
		return 1;
}
