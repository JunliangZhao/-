#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
class jineng
{
public:
	void anpaimian();
	void xuanze();
	void gaoshu();
	void cyuyan();
	void yingyu();
};
void jineng::anpaimian()
{
	initgraph(690,532);
	IMAGE person2,person_2,background1;
	loadimage(&background1,"C:\\Users\\zjl\\Desktop\\�������\\c++��լ���ɼƻ�\\��լ����.jpg",0,0,true);
	loadimage(&person2,"C:\\Users\\zjl\\Desktop\\�������\\c++��լ���ɼƻ�\\��è��2.jpg",180,180,true);
    loadimage(&person_2,"C:\\Users\\zjl\\Desktop\\�������\\c++��լ���ɼƻ�\\��è��2����ͼ.jpg",180,180,true);
	putimage(0,0,&background1);
	putimage(20,350,&person_2,SRCPAINT);
	putimage(20,350,&person2,SRCAND);
	setcolor(RGB(238,197,145));
	setfillcolor(RGB(238,197,145));
	fillrectangle(250,10,650,520);
	char anpaimian[20]="ʱ�䲻����";
	char anpaimian1[20]="�찲��";
	setbkcolor(RGB(238,194,145));
	settextstyle(30, 15, _T("����"));    
	settextcolor(BLACK);
	outtextxy(350,20,anpaimian);
	outtextxy(375,50,anpaimian1);


}
void main()
{
	jineng B;
	B.anpaimian();
	getch();
}

	


