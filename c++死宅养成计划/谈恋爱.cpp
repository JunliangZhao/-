#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
void tanlianai(int n);
void tanlianaixuanhuan();
void xiangxin();
struct xiaojiejie
{
	IMAGE xiaojiejietu;
	char *xiaojiejieming;
	char *xiaojiejiejieshao;
	int chenggong;


};

int success;
void xiangqinshuchu(char *p,int m,int n)
{
	settextstyle(20,0,_T("����"));
	char a[200];
	int x=m,y=n;
	strcpy(a,p);
	
	for( unsigned i=0;i<strlen(a);i++)
	{
		char b[3]={0};
		b[0]=a[i];
		i++;
		b[1]=a[i];
		outtextxy(x,y,b);
		x=x+20;
		if(b[0]==' '&&b[1]==' ')
		{
			x=x-30;
		}
		else if(b[0]==' '||b[1]==' ')
		{
			x=x-15;
		}
		if(x>=100+m)
		{
			x=m;
			y=y+30;
		}
	 }


}
int chachong(int b[3],int i)
{
	for(int k=0;k<i;k++)
	{
		if(b[k]==b[i])
		{
		
			break;
		}
	}
	if (k==i)
	{
		return 1;
	}
		return 0;

}
void xiangqin()
{
	setbkmode(TRANSPARENT);
	int b[3]={0};
	srand(unsigned (time(NULL)));
	int i=0;
	while(i<3)
	{
		b[i]=rand()%6;
		if(chachong(b,i))
		{
			i++;
		}
	}


	xiaojiejie a[6];
	IMAGE xiangqinbeijing,xiao1,xiao2,xiao3,xiao4,xiao5,xiao6;
	loadimage(&xiangqinbeijing,_T("ͼƬ\\���ױ���.jpg"),690,532,true);

	loadimage(&xiao1,_T("ͼƬ\\С���1.jpg"),100,330,true);
	loadimage(&xiao1,_T("ͼƬ\\С���2.jpg"),100,330,true);
	loadimage(&xiao1,_T("ͼƬ\\С���3.jpg"),100,330,true);
	loadimage(&xiao1,_T("ͼƬ\\С���4.jpg"),100,330,true);
	loadimage(&xiao1,_T("ͼƬ\\С���5.jpg"),100,330,true);
	loadimage(&xiao1,_T("ͼƬ\\С���6.jpg"),100,330,true);
	a[0].xiaojiejietu=xiao1;
	a[0].xiaojiejieming="��������";
	a[0].xiaojiejiejieshao="���С����ڴ�ѧʱ�ھ���ѧ����᳤����������ǿ�������е���䣬ֻ��SRTP���߲��гɹ��Ŀ�����";

	
	a[1].xiaojiejietu=xiao2;
	a[1].xiaojiejieming="";
	a[1].xiaojiejiejieshao="���С����ڴ�ѧʱ�ھ���ѧ����᳤����������ǿ�������е���䣬ֻ��SRTP���߲��гɹ��Ŀ�����";
	
	a[2].xiaojiejietu=xiao3;
	a[2].xiaojiejieming="��������";
	a[2].xiaojiejiejieshao="���С����ڴ�ѧʱ�ھ���ѧ����᳤����������ǿ�������е���䣬ֻ��SRTP���߲��гɹ��Ŀ�����";
	
	a[3].xiaojiejietu=xiao4;
	a[3].xiaojiejieming="��������";
	a[3].xiaojiejiejieshao="���С����ڴ�ѧʱ�ھ���ѧ����᳤����������ǿ�������е���䣬ֻ��SRTP���߲��гɹ��Ŀ�����";
	
	a[4].xiaojiejietu=xiao5;
	a[4].xiaojiejieming="��������";
	a[4].xiaojiejiejieshao="���С����ڴ�ѧʱ�ھ���ѧ����᳤����������ǿ�������е���䣬ֻ��SRTP���߲��гɹ��Ŀ�����";

	a[5].xiaojiejietu=xiao6;
	a[5].xiaojiejieming="��������";
	a[5].xiaojiejiejieshao="���С����ڴ�ѧʱ�ھ���ѧ����᳤����������ǿ�������е���䣬ֻ��SRTP���߲��гɹ��Ŀ�����";
	putimage(0,0,&xiangqinbeijing);
	setcolor(BLACK);
    setfillcolor(RGB(255,228,196));
	putimage(10,100,&a[b[0]].xiaojiejietu);
	fillrectangle(110,100,230,130);
	settextstyle(15,0,_T("����"));
	outtextxy(125,105,a[b[0]].xiaojiejieming);
	fillrectangle(110,130,230,430);
	xiangqinshuchu(a[b[0]].xiaojiejiejieshao,125,135);//
	 
	
	setfillcolor(RGB(255,228,196));
	putimage(240,100,&a[b[1]].xiaojiejietu);
	fillrectangle(340,100,470,130);
	settextstyle(15,0,_T("����"));
	outtextxy(345,105,a[b[1]].xiaojiejieming);
	fillrectangle(340,130,470,430);
	xiangqinshuchu(a[b[1]].xiaojiejiejieshao,345,135);//
		
	
	setfillcolor(RGB(255,228,196));
	putimage(480,100,&a[b[2]].xiaojiejietu);
	fillrectangle(580,100,690,130);
	settextstyle(15,0,_T("����"));
	outtextxy(585,105,a[b[2]].xiaojiejieming);
	fillrectangle(580,130,690,430);
	xiangqinshuchu(a[b[2]].xiaojiejiejieshao,585,135);//
	char c;
	while(true)
	{
		c=getch();
		if(c=='1')
		{
		}

	}








}





void tanlianai(int n)
{


	setcolor(BLACK);
	

	IMAGE tan1,tan2,tan3,tan4,tan5;
	loadimage(&tan1,_T("ͼƬ\\̸����1.jpg"),280,200,true);
	loadimage(&tan2,_T("ͼƬ\\̸����2.jpg"),280,200,true);
	loadimage(&tan3,_T("ͼƬ\\̸����3.jpg"),280,200,true);	
	loadimage(&tan4,_T("ͼƬ\\̸����4.jpg"),280,200,true);	
	loadimage(&tan5,_T("ͼƬ\\̸����5.jpg"),280,200,true);	
	
	
	setfillcolor(WHITE);
	if(n<=60 &&n>=0)
	{
		putimage(210,100,&tan1);
	}
	else if(n>60 && n<=120)
	{
		putimage(210,100,&tan2);
	}
	else if(n>120 && n<=180)
	{
		putimage(210,100,&tan3);
	}
	else if(n>180 && n<=240)
	{
		putimage(210,100,&tan4);
	}
	else if(n>240 && n<=300)
	{
		putimage(210,100,&tan5);
	}
	fillrectangle(200,350,500,360);
	setfillcolor(RGB(255,165,0));
	fillrectangle(200,350,n+200,360);
	settextstyle(30,0,_T("����"));
	settextcolor(RGB(255,165,0));
	outtextxy(280,380,"����������");

}
void tanlianaixuanhuan()
{
	int n=0;
	while(n<=300)
	{
		n++;
		tanlianai(n);
		Sleep(10);
	}
}
void main()
{
	initgraph(690,532);
	xiangqin();
	getch();


}