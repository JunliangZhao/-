#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
void main()
{
IMAGE dashangdian;
int wupin[12]={0};
initgraph(690,532);
loadimage(&dashangdian,"ͼƬ\\���̵�.jpg",690,532,true);
putimage(0,0,&dashangdian);
setcolor(RED);
settextstyle(20,0,_T("����"));
wupin[4]=0;
if(wupin[0]==0)
{
outtextxy(360,120,"�ۿ�");
}
if(wupin[1]==0)
{
outtextxy(450,120,"�ۿ�");
}
if(wupin[2]==0)
{
outtextxy(540,120,"�ۿ�");
}
if(wupin[3]==0)
{
outtextxy(630,120,"�ۿ�");
}
if(wupin[4]==0)
{
outtextxy(360,250,"�ۿ�");
}
if(wupin[5]==0)
{
outtextxy(450,250,"�ۿ�");
}
if(wupin[6]==0)
{
outtextxy(540,250,"�ۿ�");
}
if(wupin[7]==0)
{
outtextxy(630,250,"�ۿ�");
}

if(wupin[8]==0)
{
outtextxy(270,420,"�ۿ�");
}
if(wupin[9]==0)
{
outtextxy(350,420,"�ۿ�");
}


if(wupin[10]==0)
{
outtextxy(470,420,"�ۿ�");
}
if(wupin[11]==0)
{
outtextxy(550,420,"�ۿ�");
}
setbkmode(TRANSPARENT);
char a[]={"���������"};

	int x=70,y=50;
	settextstyle(20,0,_T("����"));
	settextcolor(WHITE);
	for(unsigned i=0;i<strlen(a);i++)
	{
		char b[3]={0};
		b[0]=a[i];
		i++;
		b[1]=a[i];
		outtextxy(x,y,b);
		x=x+25;
		if(b[0]==' '&&b[1]==' ')
		{
			x=x-30;
		}
		else if(b[0]==' '||b[1]==' ')
		{
			x=x-15;
		}
		if(x>220)
		{
			x=70;
			y=y+30;
		}
	}
	clearrectangle(70,50,240,100);
getch();

}