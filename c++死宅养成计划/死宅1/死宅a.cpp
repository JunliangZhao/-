
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include <mmsystem.h> 
#pragma comment(lib,"Winmm.lib")
# pragma comment(lib, "msimg32.lib")
int tiku_[50];
int xuanti;
IMAGE tiku[50];
int suiji=0;
void jiazaitimu();
int fangchongfu[10]={0};
int fangchong=0;
int dati();
void zuoti();
void kaoshizhong();
void jiemian();
void caozuo();
void shangdian();
void tufashijian();
void anpaimian();
int hongbao1=340,hongbao2=0,hongbao3,	hongbaokaishi=3;
double hongbao4=6;
void hongbao_huitu();
void hongbao_kongzhi();
void hongbao_xuanhuan();
void beijing();
int snm[50][2]={{300,250},{310,250},{320,250},{330,250}};
int snn=4;
int snw=0,snd=0,sna=1,sns=0;
int snp=300,snq=300;

void dian(int ,int);
void dian_(int ,int);
int snfenshu=0;
char snfenshu_[20];
void tanlianai(int n);
void tanlianaixuanhuan();
void xiangqin();
struct xiaojiejie
{
	IMAGE xiaojiejietu;
	char *xiaojiejieming;
	char *xiaojiejiejieshao;
	int success_;
	
	
};

int success;
int chuqianguan=0;

void shiwu()
{
	setbkmode(TRANSPARENT);
	dian(snp,snq);
	settextstyle(30,0,_T("����"));
	sprintf(snfenshu_,"%d",snfenshu);
	outtextxy(0,0,snfenshu_);
	srand(unsigned (time(NULL)));
	if((snm[0][0]-snp)*(snm[0][0]-snp)+(snm[0][1]-snq)*(snm[0][1]-snq)<100)
	{
		snfenshu+=10;
		int b[2];
		snn++;
		dian_(snp,snq);
		for(int i=0;i<2;i++)
		{
			b[i]=10*(rand()%19+1)+200;
		}
		snp=b[0];
		snq=b[1];
	}
}



void dian(int x,int y)
{
	setcolor(GREEN);
	setfillcolor(GREEN);
	fillrectangle(x-5,y-5,x+5,y+5);
}
void dian_(int x,int y)
{
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillrectangle(x-5,y-5,x+5,y+5);
}
void snkongzhi()
{
	char c;
	if(kbhit())
	{
		
		c=getch();
		
		if((c=='w'||c=='W') && sns==0)
		{
			snw=1;
			snd=0;
			sns=0;
			sna=0;
		}
		if((c=='s'||c=='S')&& snw==0)
		{
			snw=0;
			snd=0;
			sns=1;
			sna=0;
		}
		if((c=='A'||c=='a') && snd==0)
		{
			snw=0;
			snd=0;
			sns=0;
			sna=1;
		}
		if((c=='D'||c=='d') && sna==0)
		{
			snw=0;
			snd=1;
			sns=0;
			sna=0;
		}
	}
	
}
void snxuanhuan()
{
	IMAGE background1;
	loadimage(&background1,_T("ͼƬ//��լ����.jpg"),690,532,true);
	putimage(0,0,&background1);
	setcolor(WHITE);
	setfillcolor(BLACK);
	fillrectangle(200,200,400,400);
	for(int l=0;l<snn;l++)
	{
		dian(snm[l][0],snm[l][1]);
	}
	Sleep(1000);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	
	int sng=1;
	
	while (snm[0][1]<=395 &&snm[0][1]>=205 &&snm[0][0]<=395 &&snm[0][0]>=205 && sng)
	{
		if(snn>=14)
		{
			break;
		}
		for(int i=0;i<snn;i++)
		{
			snm[snn-i][0]=snm[snn-i-1][0];
			snm[snn-i][1]=snm[snn-i-1][1];
			
		}
		
		
		
		snkongzhi();
		
		
		
		if(snw==1)
		{
			snm[0][1]=snm[0][1]-10;
		}
		if(sns==1)
		{
			snm[0][1]=snm[0][1]+10;
		}
		if(sna==1)
		{
			snm[0][0]=snm[0][0]-10;
		}
		if(snd==1)
		{
			snm[0][0]=snm[0][0]+10;
		}
		
		for(int sno=1;sno<snn;sno++)
		{
			
			int snt;
			snt=(snm[0][0]-snm[sno][0])*(snm[0][0]-snm[sno][0])+(snm[0][1]-snm[sno][1])*(snm[0][1]-snm[sno][1]);
			if(snt<100)
			{
				sng=0;
				break;
				
				
				
			}
		}
		
		
		
        BeginBatchDraw();
		putimage(0,0,&background1);
		setcolor(WHITE);
		setfillcolor(BLACK);
		fillrectangle(200,200,400,400);
		
		
		
		
		shiwu();
		
		
		for(int k=0;k<snn;k++)
		{
			dian(snm[k][0],snm[k][1]);
		}
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		Sleep(100);
		FlushBatchDraw();
		
		cleardevice();
		
		
		
	}
	EndBatchDraw();
	
	
	
}
void rputimage(int x0, int y0, IMAGE* img)
{
	//���ͼƬ�ߴ�
	int qwidth, qheight;
	qwidth = img->getwidth();
	qheight = img->getheight();
	
	
	//PͼΪ����ͼ,RSΪĿ��ͼƬ
	IMAGE RS(qwidth, qheight);
	
	
	//��ȡָ�룬��Ϊ͸���ȼ���
	DWORD* M = GetImageBuffer(img);
	DWORD* R = GetImageBuffer(&RS);
	
	
	// ����������ͼģʽ�������˸����
	
	
	//�����븳ֵ
	int i, j;
	for (i = 0; i < qheight; i++) {
		for (j = 0; j < qwidth; j++) {
			int r, g, b;
			int ij;
			//����
			ij = i*qwidth + j;
			if((int)GetRValue(M[ij])==255 && (int)GetGValue(M[ij])==255 && (int)GetBValue(M[ij])==255)
			{
				r=0;
				g=0;
				b=0;
			}
			else
			{
				r=255;
				b=255;
				g=255;
			}
			R[ij] = RGB(r, g, b);
		}
	}
	
	
	//����ͼƬ���ͷ��ڴ�
	putimage(x0, y0, &RS,SRCPAINT);
	putimage(x0,y0,img,SRCAND);
}

void myputimage(int x0, int y0, IMAGE* img, double f)
{
	//���ͼƬ�ߴ�
	int qwidth, qheight;
	qwidth = img->getwidth();
	qheight = img->getheight();
	
	
	//PͼΪ����ͼ,RSΪĿ��ͼƬ
	IMAGE RS(qwidth, qheight);
	IMAGE P(qwidth, qheight);
	
	
	//����ͼ�Ļ���
	getimage(&P, x0, y0, qwidth, qheight);
	
	
	//��ȡָ�룬��Ϊ͸���ȼ���
	DWORD* M = GetImageBuffer(&P);
	DWORD* N = GetImageBuffer(img);
	DWORD* R = GetImageBuffer(&RS);
	
	
	// ����������ͼģʽ�������˸����
	
	
	//�����븳ֵ
	int i, j;
	for (i = 0; i < qheight; i++) {
		for (j = 0; j < qwidth; j++) {
			int r, g, b;
			int ij;
			//����
			ij = i*qwidth + j;
			r = (int)((GetRValue(N[ij])) * (1 - f) + GetRValue(M[ij]) * f);
			g = (int)((GetGValue(N[ij])) * (1 - f) + GetGValue(M[ij]) * f);
			b = (int)((GetBValue(N[ij])) * (1 - f) + GetBValue(M[ij]) * f);
			R[ij] = RGB(r, g, b);
		}
	}
	
	
	//����ͼƬ���ͷ��ڴ�
	putimage(x0, y0, &RS);
	
}
void zimu(char *p,char *q)
{
	setcolor(WHITE);
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	setfillcolor(RGB(210,105,30));
	fillrectangle(50,320,200,360);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	settextstyle(30,0,_T("����"));
	outtextxy(60,325,q);
	
	char a[200];
	strcpy(a,p);
	int x=100,y=370;
	settextstyle(20,0,_T("����"));
	settextcolor(BLACK);
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
		if(x>550)
		{
			x=100;
			y=y+30;
		}
		Sleep(100);
		if(kbhit())
		{
			break;
		}
		
	}
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	setfillcolor(RGB(210,105,30));
	fillrectangle(50,320,200,360);
	settextcolor(WHITE);
	settextstyle(30,0,_T("����"));
	outtextxy(60,325,q);
	x=100,y=370;
	settextstyle(20,0,_T("����"));
	settextcolor(BLACK);
	for( i=0;i<strlen(a);i++)
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
		if(x>550)
		{
			x=100;
			y=y+30;
		}
	}
	
	
}
void zimu3(char *p,char *q)
{
		setcolor(WHITE);
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	setfillcolor(RGB(210,105,30));
	fillrectangle(50,320,200,360);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	settextstyle(30,0,_T("����"));
	outtextxy(60,325,q);
	
	char a[200];
	strcpy(a,p);
	int x=100,y=370;
	settextstyle(20,0,_T("����"));
	settextcolor(BLACK);
	for(unsigned i=0;i<strlen(a);i++)
	{
		char b[3]={0};
		b[0]=a[i];
		i++;
		b[1]=a[i];
		outtextxy(x,y,b);
		x=x+25;
		if(b[0]=='.'&&b[1]=='.')
		{
			x=x-30;
		}
		else if(b[0]=='.'||b[1]=='.')
		{
			x=x-15;
		}
		if(x>550)
		{
			x=100;
			y=y+30;
		}
		Sleep(100);
		if(kbhit())
		{
			break;
		}
		
	}
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	setfillcolor(RGB(210,105,30));
	fillrectangle(50,320,200,360);
	settextcolor(WHITE);
	settextstyle(30,0,_T("����"));
	outtextxy(60,325,q);
	x=100,y=370;
	settextstyle(20,0,_T("����"));
	settextcolor(BLACK);
	for( i=0;i<strlen(a);i++)
	{
		char b[3]={0};
		b[0]=a[i];
		i++;
		b[1]=a[i];
		outtextxy(x,y,b);
		x=x+25;
		if(b[0]=='.'&&b[1]=='.')
		{
			x=x-30;
		}
		else if(b[0]=='.'||b[1]=='.')
		{
			x=x-15;
		}
		if(x>550)
		{
			x=100;
			y=y+30;
		}
	}
	
	
}
void zimu1(char *p)
{
		setcolor(WHITE);
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	
	setbkmode(TRANSPARENT);
	
	char a[200];
	strcpy(a,p);
	int x=100,y=370;
	settextstyle(20,0,_T("����"));
	settextcolor(BLACK);
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
		if(x>550)
		{
			x=100;
			y=y+30;
		}
		Sleep(100);
		if(kbhit())
		{
			break;
		}
		
	}
	x=100,y=370;
	
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	settextstyle(20,0,_T("����"));
	settextcolor(BLACK);
	for( i=0;i<strlen(a);i++)
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
		if(x>550)
		{
			x=100;
			y=y+30;
		}
	}
	
	
	
	
}
void zimu2(char *p,char *q)
{
		setcolor(WHITE);
	setfillcolor(RGB(255,228,196));
	fillrectangle(50,350,620,500);
	setfillcolor(RGB(210,105,30));
	fillrectangle(50,320,200,360);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	settextstyle(30,0,_T("����"));
	outtextxy(60,325,q);
	
	char a[200];
	strcpy(a,p);
	int x=100,y=370;
	settextstyle(20,0,_T("����"));
	settextcolor(BLACK);
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
		if(x>550)
		{
			x=100;
			y=y+30;
		}
		Sleep(100);
		
		
	}
	
	
}
int randrange(int n)
{
	srand(unsigned(time(0)));
	return rand()%n;
}

int key(char anjian)
{
	char anjianzhi;
	if(kbhit())
	{
		anjianzhi=getch();
		if(anjianzhi==anjian)
		{
			return 1;
		}
		else return 0;
		
	}
	else return 0;
}



int h=30;
int timushu=1;
int kaoshifenshu=0;

class sizhai
{
	char name[20];
	
public:
	int tui,zhai,qing,ya,srtp,money;
	sizhai(int a=0,int b=0,int c=0,int d=0,int e=0,int f=500)
	{
		tui=a;
		zhai=b;
		qing=c;
		ya=d;
        srtp=e;
		money=f;
	}
	void getname(char*Name)
	{
		strcpy(name,Name);
	}
	char *returnname()
	{
		return name;
	}
	
	
};
class jineng
{	
	char gaoshu[20];
	char yingyu[20];
	char cyuyan[20];
public:
	int gaoshudengji,gaoshushu;
	int cyuyandengji,cyuyanshu;
    int yingyudengji,yingyushu;
	jineng()
	{
		gaoshudengji=0;
		gaoshushu=0;
		cyuyandengji=0;
		cyuyanshu=0;
		yingyudengji=0;
		yingyushu=0;
	}
	void anpaimian();
	void shengji();
	char *returngaoshu()//����
	{
		return gaoshu;
	}
	void getgaoshu(char *gaoshu_1)
	{
		strcpy(gaoshu,gaoshu_1);
	}
	char *returncyuyan()//c����
	{
		return cyuyan;
	}
	void getcyuyan(char *cyuyan_1)
	{
		strcpy(cyuyan,cyuyan_1);
	}
	char *returnyingyu()//Ӣ��
	{
		return yingyu;
	}
	void getyingyu(char *yingyu_1)
	{
		strcpy(yingyu,yingyu_1);
	}
	
};
class dashangdian
{
public:
	int wupin[12];
	dashangdian()
	{
		for(int i=0;i<12;i++)
		{
			wupin[i]=1;
		}
	}
	
	void	shangdianchushihua()
	{
		for(int i=0;i<12;i++)
		{
			wupin[i]=1;
		}
	}
	void huizhihang(int a)
	{
		IMAGE dashangdian,dashangdian1,dashangdian2,dashangdian3;
		loadimage(&dashangdian,_T("ͼƬ//���̵�.jpg"),690,532,true);
		loadimage(&dashangdian1,_T("ͼƬ//���̵�1.jpg"),690,532,true);
		loadimage(&dashangdian2,_T("ͼƬ//���̵�2.jpg"),690,532,true);
		loadimage(&dashangdian3,_T("ͼƬ//���̵�3.jpg"),690,532,true);
		if(a==0)
		{
			putimage(0,0,&dashangdian);
		}
		if(a==1)
		{
			putimage(0,0,&dashangdian1);
		}
        if(a==2)
		{
			putimage(0,0,&dashangdian2);
		}
		if(a==3)
		{
			putimage(0,0,&dashangdian3);
		}
		
	}
	void shoukong()
	{
		setbkmode(OPAQUE);
		setcolor(RED);
		settextstyle(20,0,_T("����"));
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
		
	}
	void shuoming(char *p)
	{
		char a[200]={'0'};
		strcpy(a,p);
		setbkmode(TRANSPARENT);
		
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
	}
	
};


jineng B;

sizhai A;
dashangdian C;
void myshangdian()
{
	cleardevice();
	
	
	
	while(true)
	{
		C.huizhihang(0);
		C.shoukong();
		
		char c=0,c1=0,c2=0;
		c=getch();
		C.shoukong();
		C.shoukong();
		if(c==27)
		{
			break;
		}
		if(c=='1')
		{
			C.huizhihang(1);
			C.shoukong();
			C.shuoming("��ѡ��1 ��2 ��3 ��4");
			while(c1!=27)
			{
				c1=getch();
				if(c1=='1'&&C.wupin[0]==1)			
				{
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("��լ����ˮ��������ּ�ѹ����Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=5)
							{
								A.money-=5;
								C.wupin[0]=0;
								A.ya-=3;
								if(A.ya<0)
								{
									A.ya=0;
								}
								zimu1("ѹ��ֵ-3");
								
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='1'&&C.wupin[0]==0)
				{
					
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='2'&&C.wupin[1]==1)			
				{
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("����һʱˬ��һֱ����һֱˬ��ѹ��Ʒ����Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=8)
							{
								A.money-=8;
								C.wupin[1]=0;
								zimu1("ѹ��ֵ-4");
								A.ya-=4;
								if(A.ya<0)
								{
									A.ya=0;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='2'&&C.wupin[1]==0)
				{
					
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='3'&&C.wupin[2]==1)			
				{
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("��ҹͨ���ر���Ʒ������ʮ�ֿ��֣���Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=12)
							{
								A.money-=12;
								C.wupin[2]=0;
								zimu1("ѹ��ֵ-5");
								A.ya-=5;
								if(A.ya<0)
								{
									A.ya=0;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='3'&&C.wupin[2]==0)
				{
					
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='4'&&C.wupin[3]==1)			
				{
					
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("����ĸ���źؿ��ɣ����ǻ�ܿ��ĵģ���Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=15)
							{
								A.money-=15;
								C.wupin[3]=0;
								zimu1("����+2");
								A.qing+=2;
								if(A.qing>100)
								{
									A.qing=100;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='4'&&C.wupin[3]==0)
				{
					
					C.huizhihang(1);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				
				
				
				
			}
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		else	if(c=='2')
		{
			C.huizhihang(2);
			C.shoukong();
			C.shuoming("��ѡ��1 ��2 ��3 ��4");
			while(c1!=27)
			{
				c1=getch();
				if(c1=='1'&&C.wupin[4]==1)			
				{
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("������Ķ��������ʺã����������鶼�ã���Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=50)
							{
								A.money-=50;
								C.wupin[4]=0;
								A.ya-=10;
								if(A.ya<0)
								{
									A.ya=0;
								}
								zimu1("ѹ��ֵ-10");
								
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='1'&&C.wupin[4]==0)
				{
					
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='2'&&C.wupin[5]==1)			
				{
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("�����ְ��ܿ��ģ�����ͬʱҲ�����լֵ����Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=60)
							{
								A.money-=60;
								C.wupin[5]=0;
								zimu1("ѹ��ֵ-15 ����լֵ+10");
								A.ya-=15;
								if(A.ya<0)
								{
									A.ya=0;
								}
								if(A.zhai>100)
								{
									A.zhai=100;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='2'&&C.wupin[5]==0)
				{
					
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='3'&&C.wupin[6]==1)			
				{
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("������ѧϰ��Ʒ�����Լ�����ѧ�ʣ���Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=30)
							{
								A.money-=30;
								C.wupin[6]=0;
								zimu1("��ѧ��-7");
								A.ya-=5;
								if(A.tui<0)
								{
									A.tui=0;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='3'&&C.wupin[6]==0)
				{
					
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='4'&&C.wupin[7]==1)			
				{
					
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("����С���Ǳ��������飬���ǻ��е��ѣ���Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=60)
							{
								A.money-=60;
								C.wupin[7]=0;
								zimu1("��ѧ��-15 ��ѹ��+10");
								A.qing+=7;
								if(A.ya>100)
								{
									A.ya=100;
								}
								if(A.tui<0)
								{
									A.tui=0;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='4'&&C.wupin[7]==0)
				{
					
					C.huizhihang(2);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				
				
				
				
			}
		}
		
		
		
		
		
		
		
		
		
		
		else if(c=='3')
		{
			C.huizhihang(3);
			C.shoukong();
			C.shuoming("��ѡ��1 ��2 ��3 ��4");
			while(c1!=27)
			{
				c1=getch();
				if(c1=='1'&&C.wupin[8]==1)			
				{
					
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("һ��Լ����ƺ���������ѹ��Ҳ��������ѧ�ʣ����ã���Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=98)
							{
								A.money-=98;
								C.wupin[8]=0;
								A.ya-=25;
								A.tui+=15;
								if(A.ya<0)
								{
									A.ya=0;
								}
								if(A.tui>100)
								{
									A.tui=100;
								}
								zimu1("ѹ��ֵ-25 ����ѧ��+15");
								
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='1'&&C.wupin[8]==0)
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='2'&&C.wupin[9]==1)			
				{
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("�μ�У���������ݣ��ɻ�ô���SRTP����Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=300)
							{
								A.money-=300;
								C.wupin[9]=0;
								zimu1("SRTP+15");
								A.srtp+=15;
								
								if(A.srtp>100)
								{
									A.srtp=100;
								}
								
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='2'&&C.wupin[9]==0)
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='3'&&C.wupin[10]==1)			
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("˵������������ѧ��˵���㶮�ģ���Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=100)
							{
								A.money-=100;
								C.wupin[10]=0;
								zimu1("SRTP+3������+3");
								A.srtp+=3;
								A.qing+=3;
								if(A.qing>100)
								{
									A.qing=100;
								}
								if(A.srtp>100)
								{
									A.srtp=100;
								}
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='3'&&C.wupin[10]==0)
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				else if(c1=='4'&&C.wupin[11]==1)			
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("����������ӵ��ԴԴ���ϵ�����ѣ���Y ���򣬰�N ȡ����");
					while(true)
					{
						c2=getch();
						if(c2=='Y'||c2=='y')
						{
							if(A.money>=200)
							{
								A.money-=200;
								C.wupin[11]=0;
								zimu1("��Ǯ�޸���+1");
								chuqianguan++;
								
								
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								
								break;
							}
							else 
							{
								zimu1("Ǯ�������뼰ʱ��ֵ");
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
								getch();
								break;
							}
							
						}
						if(c2=='N'|| c2=='n'||c2==27)
						{
							break;
						}
					}
					
					break;
				}
				else if(c1=='4'&&C.wupin[11]==0)
				{
					
					C.huizhihang(3);
					C.shoukong();
					C.shuoming("���ۿ�");
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					break;
					
					
				}
				
				
				
				
			}
		}
		
		
		
	}
	
	
	
	
	
	cleardevice();
	jiemian();
	
	
}



void jiazaitimu()
{
	setbkmode(TRANSPARENT);
    
	
	IMAGE kaoshitu1,kaoshitu2,kaoshitu3;
	loadimage(&tiku[0],_T("���\\t1.jpg"),300,200,true);
	tiku_[0]=2;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[1],_T("���\\t2.jpg"),300,200,true);
	tiku_[1]=2;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[2],_T("���\\t3.jpg"),300,200,true);
	tiku_[2]=2;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[3],_T("���\\t4.jpg"),300,200,true);
	tiku_[3]=1;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[4],_T("���\\t5.jpg"),300,200,true);
	tiku_[4]=3;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[5],_T("���\\t6.jpg"),300,200,true);
	tiku_[5]=4;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[6],_T("���\\t7.jpg"),300,200,true);
	tiku_[6]=1;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[7],_T("���\\t8.jpg"),300,200,true);
	tiku_[7]=4;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[8],_T("���\\t9.jpg"),300,200,true);
	tiku_[8]=4;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[9],_T("���\\t10.jpg"),300,200,true);
	tiku_[9]=2;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[10],_T("���\\t11.jpg"),300,200,true);
	tiku_[10]=4;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[11],_T("���\\t12.jpg"),300,200,true);
	tiku_[11]=2;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[12],_T("���\\t13.jpg"),300,200,true);
	tiku_[12]=1;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[13],_T("���\\t14.jpg"),300,200,true);
	tiku_[13]=4;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[14],_T("���\\t15.jpg"),300,200,true);
	tiku_[14]=2;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[15],_T("���\\t16.jpg"),300,200,true);
	tiku_[15]=4;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[16],_T("���\\t17.jpg"),300,200,true);
	tiku_[16]=1;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[17],_T("���\\t18.jpg"),300,200,true);
	tiku_[17]=3;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[18],_T("���\\t19.jpg"),300,200,true);
	tiku_[18]=3;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[19],_T("���\\t20.jpg"),300,200,true);
	tiku_[19]=2;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[20],_T("���\\t21.jpg"),300,200,true);
	tiku_[20]=2;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[21],_T("���\\t22.jpg"),300,200,true);
	tiku_[21]=1;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[22],_T("���\\t23.jpg"),300,200,true);
	tiku_[22]=1;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[23],_T("���\\t24.jpg"),300,200,true);
	tiku_[23]=2;   //A��1��B��2, C��3, D��4
	
	loadimage(&tiku[24],_T("���\\t25.jpg"),300,200,true);
	tiku_[24]=2;   //A��1��B��2, C��3, D��4
	
label:xuanti=randrange(25);
	  for(int i=0;i<10;i++)
	  {
		  if(xuanti+1==fangchongfu[i]+1)
		  {
			  goto label;
		  }
		  
	  }
	  fangchongfu[fangchong]=xuanti;
	  fangchong++;
	  loadimage(&kaoshitu3,_T("ͼƬ\\����ͼ3.jpg"),690,532,true);
	  loadimage(&kaoshitu2,_T("ͼƬ\\����ͼ2.jpg"),250,300,true);
	  loadimage(&kaoshitu1,_T("ͼƬ\\����ͼ1.jpg"),380,300,true);
	  putimage(0,0,&kaoshitu3);
	  putimage(10,50,&kaoshitu1);
	  putimage(30,70,&tiku[xuanti]);
	  myputimage(400,50,&kaoshitu2,0.15);
	  char timushu_[20],kaoshifenshu_[20];
	  settextcolor(WHITE);
	  settextstyle(20,0,_T("����"));
	  sprintf(timushu_,"%d",timushu);
	  outtextxy(0,10,"������");
	  outtextxy(70,10,timushu_);
	  outtextxy(80,10,"/5");
	  outtextxy(120,10,"�÷�");
	  sprintf(kaoshifenshu_,"%d",kaoshifenshu);
	  outtextxy(170,10,kaoshifenshu_);
	  
	  
	  
	  
}
int dati()
{
	char c;
	while(true)
	{
		c=getch();
		if(c=='a' || c=='A')
		{
			return 1;
			break;
		}
		if(c=='b'||c=='B')
		{
			return 2;
			break;
		}
		if(c=='c'||c=='C')
		{
			return 3;
			break;
		}
		if(c=='d'||c=='D')
		{
			return 4;
			break;
		}
	}
}	


void zuoti()
{
	
	jiazaitimu();
	int m;
	m=dati();
    settextstyle(30,0,_T("����"));
	setbkmode(TRANSPARENT);
	if(m==1)
	{
		outtextxy(410,60,"��Ĵ���A");
	}
	if(m==2)
	{
		outtextxy(410,60,"��Ĵ���B");
	}
	if(m==3)
	{
		outtextxy(410,60,"��Ĵ���C");
	}
	if(m==4)
	{
		outtextxy(410,60,"��Ĵ���D");
	}
	Sleep(1000);
	if(m==tiku_[xuanti])
	{
		outtextxy(410,190,"��ϲ������");
		Sleep(1000);
		outtextxy(410,300,"���Ǹ�С�����");
		kaoshifenshu=kaoshifenshu+20;
	}
	else
	{
		outtextxy(410,190,"���ź������");
		Sleep(500);
		outtextxy(410,300,"��ȷ���ǣ�");
		Sleep(500);
		if(tiku_[xuanti]==1)
		{
			outtextxy(580,300,"A");
		}
		if(tiku_[xuanti]==2)
		{
			outtextxy(580,300,"B");
		}
		if(tiku_[xuanti]==3)
		{
			outtextxy(580,300,"C");
		}
		if(tiku_[xuanti]==4)
		{
			outtextxy(580,300,"D");
		}
	}
	outtextxy(200,500,"���ո����һ��");
}

void kaoshizhong()
{
	mciSendString(TEXT("stop mysong "),NULL,0,NULL);
	mciSendString(TEXT("open bgm\\��������.mp3 alias mysong1"),NULL,0,NULL);
	mciSendString(TEXT("play mysong1 repeat"),NULL,0,NULL);
	
	
	
	char c;
	zuoti();
	
	while(true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		c=getch();
		if(c==' ')
		{
			if(timushu==5)
			{
				
				break;
			}
			
			timushu++;
			zuoti();
		}
		
	}
	
	
	
	mciSendString(TEXT("close mysong1 "),NULL,0,NULL);
	mciSendString(TEXT("play mysong repeat"),NULL,0,NULL);
	IMAGE defen1,kaojuan;
	loadimage(&kaojuan,_T("ͼƬ\\����.jpg"),250,300,true);
	loadimage(&defen1,_T("ͼƬ\\����ͼ3.jpg"),690,532,true);
	putimage(0,0,&defen1);
	setbkmode(TRANSPARENT);
	char kaoshifenshu_1[20];
	sprintf(kaoshifenshu_1,"%d",kaoshifenshu);
	settextcolor(RED);
	settextstyle(30,0,_T("����"));
	putimage(100,180,&kaojuan);
	outtextxy(300,200,kaoshifenshu_1);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	mciSendString(TEXT("play mysong repeat"),NULL,0,NULL);
	
	
	
}
void qizhongkao()
{
	IMAGE kaoshitu3,person2,person_2;
	loadimage(&kaoshitu3,_T("ͼƬ\\����ͼ3.jpg"),690,532,true);
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
	loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	
	char a[]={"��ô���Ҫ���п�����"};
	char b[]={"����ûԤϰ�أ��ûŰ���"};
	char c[]={"Ҫ���̵����ԣ�����Y ��ʼ���ԣ���N �̵����ԣ�"};
	char d=0;
	char e[]={"��ѧ��+20 ��ѹ��ֵ+20"};
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(a,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(b,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(c,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	while(true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
		d=getch();
		if(d=='y'||d=='Y'||d=='n'||d=='N')
		{
			break;
		}
	}
	if(d=='y'||d=='Y')
				{
		kaoshizhong();
				}
	else 
				{
		putimage(0,0,&kaoshitu3);
		zimu1(e);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.tui+=20;
		A.ya+=20;
		if(A.tui>100)
		{
			A.tui=100;
		}
		if(A.ya>100)
		{
			A.ya=100;
		}
		kaoshifenshu--;
				}
	if(kaoshifenshu<60 && kaoshifenshu>=0)
	{
		putimage(0,0,&kaoshitu3);
		zimu1("��ѧ��+15 ��ѹ��ֵ+15");
		
		A.tui+=15;
		A.ya+=15;
	}
	if(A.tui>100)
	{
		A.tui=100;
	}
	if(A.ya>100)
	{
		A.ya=100;
	}
	if(kaoshifenshu==60)
	{
		putimage(0,0,&kaoshitu3);
		zimu1("��ѧ��-5��ѹ��ֵ-5");
		A.ya-=5;
		A.tui-=5;
	}
	if(kaoshifenshu==80)
	{
		putimage(0,0,&kaoshitu3);
		zimu1("��ѧ��-10 ��ѹ��ֵ-10");
		A.ya-=10;
		A.tui-=10;
	}
	if(kaoshifenshu==100)
	{
		putimage(0,0,&kaoshitu3);
		zimu1("��ѧ��-20 ��ѹ��ֵ-20");
		A.ya-=20;
		A.tui-=20;
	}
	if(A.tui<0)
	{
		A.tui=0;
	}
	if(A.ya<0)
	{
		A.ya=0;
		
	}
	
	timushu=1;
	kaoshifenshu=0;
				
				
				
}
void qimokao()
{
	IMAGE kaoshitu3,person2,person_2;
	loadimage(&kaoshitu3,_T("ͼƬ\\����ͼ3.jpg"),690,532,true);
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
	loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	char a[]={"Ҳ����һ�ο��꣬����Ҳ�ͽ�����"};
	char b[]={"�ÿ�ѽ��δ����·����ô�ߣ��һ���ʮ����ã"};
	char c[]={"����Ҳ��ø��Լ������꽻��һ������Ĵ����"};
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(a,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(b,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&kaoshitu3);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);	
	zimu(c,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	kaoshizhong();
				if(kaoshifenshu<60 && kaoshifenshu>=0)
				{
					putimage(0,0,&kaoshitu3);
					zimu1("��ѧ��+15 ��ѹ��ֵ+15");
					
					A.tui+=15;
					A.ya+=15;
				}
				if(A.tui>100)
				{
					A.tui=100;
				}
				if(A.ya>100)
				{
					A.ya=100;
				}
				if(kaoshifenshu==60)
				{
					putimage(0,0,&kaoshitu3);
					zimu1("��ѧ��-5��ѹ��ֵ-5");
					A.ya-=5;
					A.tui-=5;
				}
				if(kaoshifenshu==80)
				{
					putimage(0,0,&kaoshitu3);
					zimu1("��ѧ��-10 ��ѹ��ֵ-10");
					A.ya-=10;
					A.tui-=10;
				}
				if(kaoshifenshu==100)
				{
					putimage(0,0,&kaoshitu3);
					zimu1("��ѧ��-20 ��ѹ��ֵ-20");
					A.ya-=20;
					A.tui-=20;
				}
				if(A.tui<0)
				{
					A.tui=0;
				}
				if(A.ya<0)
				{
					A.ya=0;
					
				}
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				
				
}





void hongbao_kongzhi() 
{
	char c;
	if(kbhit())
	{
		c=getch();
		if(c==' ')
			hongbao2=20;
	}
	if(hongbao2>0 &&hongbaokaishi==-1)
	{
		hongbao1=hongbao1+hongbao2;
		hongbao2--;
	}
	hongbao1=hongbao1-10;
	hongbao3=(int)(hongbao1-125)/10;
}
void hongbao_huizhi()
{
	
	IMAGE hongbaobeijing,shou,shou_;
	loadimage(&hongbaobeijing,_T("ͼƬ\\���1.jpg"),600,450,true);
	loadimage(&shou,_T("ͼƬ\\���2.jpg"),690,200,true);
	loadimage(&shou_,_T("ͼƬ\\���3.jpg"),690,200,true);
    BeginBatchDraw();
	putimage(45,80,&hongbaobeijing);
	setfillcolor(BLACK);
	fillrectangle(120,450,580,500);
	setcolor(BLUE);
	setfillcolor(BLUE);
	fillrectangle(300,450,400,500);
	setcolor(GREEN);
	line(hongbao1,440,hongbao1,510);
	putimage(hongbao3,200,&shou,SRCAND);
	putimage(hongbao3,200,&shou_,SRCPAINT);
	setcolor(BLACK);
	setfillcolor(BLACK);
    fillrectangle(0,200,40,400);
    fillrectangle(645,200,690,400);
	char hongbao4_[20];
	sprintf(hongbao4_,"%.2f",hongbao4);
	setbkmode(TRANSPARENT);
	settextstyle(30, 15, _T("����"));
	outtextxy(320,100,hongbao4_);
	char a[]={"���°ɣ����ǰ��̹���"};
	char c[]={"��ú�ѧϰ��"};
	char b[]={"�������������Ҳ���Ҫ"};
	setcolor(WHITE);
	setfillcolor(WHITE);
	settextstyle(15,0, _T("����"));
	settextcolor(BLACK);
	fillellipse(50,170,220,270);
	fillellipse(450,170,620,270);
	outtextxy(60,220,b);
	outtextxy(460,200,a);
	outtextxy(470,240,c);
	
	setbkmode(OPAQUE);
    if(hongbao1>=125 && hongbao1<=575 && hongbao4>0.01)
	{
		FlushBatchDraw();
	}
	else EndBatchDraw();
	
	
}

void hongbao_xuanhuan()
{
	
	setbkcolor(BLACK);
	cleardevice();
	char hongbaokaishi_[20];
	
	for(int i=0;i<4;i++)
	{
		
		sprintf(hongbaokaishi_,"%d",hongbaokaishi);
		hongbao_huizhi();
		settextcolor(WHITE);
		settextstyle(60,0, _T("����"));
		outtextxy(320,0,hongbaokaishi_);
		Sleep(1000);
		
		hongbaokaishi--;
	}
	cleardevice();
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
	while(hongbao1>=125 && hongbao1<=575 && hongbao4>0 )
	{
		hongbao_kongzhi();
		hongbao_huizhi();
		Sleep(10);
		hongbao4=hongbao4-0.01;
	}
	mciSendString(TEXT("close mysong1 "),NULL,0,NULL);
	
	settextstyle(30,0,_T("����"));
	
	setbkcolor(BLACK);
	cleardevice();
	settextcolor(WHITE);
	if(hongbao1>=300 &&hongbao1<=400)
	{
		outtextxy(200,200,"���̣�����������");
		A.money=A.money+1000;
		outtextxy(200,450,"��ESC���˳�");
		
	}
	else
	{
		
		outtextxy(200,200,A.returnname());
		outtextxy(200,230,"�����ˣ�Ǯ�����ȱ�����");
		outtextxy(200,450,"��ESC���˳�");
	}
	
	char c=0;
	while(c!=27)
	{
		c=getch();
	}
	mciSendString(TEXT("open bgm\\��������.mp3 alias mysong"),NULL,0,NULL);
    mciSendString(TEXT("play mysong repeat"),NULL,0,NULL);
	
	jiemian();
}
void hongbaolai()
{
	
	IMAGE xiaoyuan,person2,person_2,ayi,ayi_;
	loadimage(&xiaoyuan,_T("ͼƬ\\У԰.jpg"),690,532,true);
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&ayi,_T("ͼƬ\\����.jpg"),180,180,true);
	loadimage(&ayi_,_T("ͼƬ\\��������ͼ.jpg"),180,180,true);
	char a[]={"�����������ˣ������ѧУ����Ӧ�𣬱��ֺò���"};
	char b[]={"ŶŶŶ�����̺ã��Ҵ��㵽ѧУ���"};
	char c[]={"�����̸��������ʲô"};
	putimage(0,0,&xiaoyuan);
	putimage(20,170,&ayi_,SRCPAINT);
	putimage(20,170,&ayi,SRCAND);
	zimu(A.returnname(),"����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&xiaoyuan);
	putimage(20,170,&ayi_,SRCPAINT);
	putimage(20,170,&ayi,SRCAND);
	zimu(a,"����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&xiaoyuan);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
	zimu(b,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&xiaoyuan);
	putimage(20,170,&ayi_,SRCPAINT);
	putimage(20,170,&ayi,SRCAND);
	zimu(c,"����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	mciSendString(TEXT("stop mysong "),NULL,0,NULL);
	mciSendString(TEXT("open bgm\\�����.mp3 alias mysong1"),NULL,0,NULL);
	mciSendString(TEXT("play mysong1 repeat"),NULL,0,NULL);
	
	hongbao_xuanhuan();
	
	
}

void wanyouxi()
{
	IMAGE background1,jiyou,person2,person_2;
	loadimage(&background1,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&jiyou,_T("ͼƬ\\����.jpg"),180,180,true);
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu("����ˣ��������ҹ���һ��","����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&background1);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
	zimu("������������������Y ���ܣ���N �ܾ���",A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	char c;
	while(true)
	{
		c=getch();
		if(c=='Y'||c=='y')
		{
			zimu1("���100 �ּ���");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
            getch();
			snxuanhuan();
			if(snn>=14)
			{
				putimage(0,0,&background1);
				rputimage(20,170,&jiyou);
				zimu("�治�����ҵĺ����ѣ�ţţ","����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&background1);
				zimu1("����+10 ��ѹ��-20");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				A.qing+=10;
				A.ya-=20;
				if(A.qing>100)
				{
					A.qing=100;
				}
				if(A.ya<0)
				{
					A.ya=0;
				}
				
			}
			else 
			{
				putimage(0,0,&background1);
				rputimage(20,170,&jiyou);
				zimu("ƽ�������ˣ��е�С��ѽ","����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				
			}
			break;
			
		}
		else if (c=='N'||c=='n')
		{
			putimage(0,0,&background1);
			rputimage(20,170,&jiyou);
			zimu("����͵��������","����");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background1);
			zimu1("����-10");
			
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.qing-=10;
			if(A.qing<0)
			{
				A.qing=0;
			}
			
			
			
		}
	}
	
	
	
}
void gaoshud(int n)
{	
	IMAGE kaoshitu3,background1,person2,person_2,person3,person_3,wenjingmeizi;
    loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&background1,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	loadimage(&kaoshitu3,_T("ͼƬ\\����ͼ3.jpg"),690,532,true);
	loadimage(&person3,_T("ͼƬ\\��è��3.jpg"),180,180,true);
	loadimage(&person_3,_T("ͼƬ\\��è��3����ͼ.jpg"),180,180,true);
	loadimage(&wenjingmeizi,_T("ͼƬ\\�ľ�����.jpg"),180,180,true);
	if(n==0)
	{
		char a[]={"ѧ��һ��ĸ����󣬷��������鶼��ѧ���ˣ�����ÿ������̫����"};
		char b[]={"���ߺ��ţ�̫���ˣ���Ҫ�����ˣ���˵�еĸ��������ˮƽ�𣿿�����ѹ������Ŀ��"};
		char c[]={"�¿�˯��ͷ���������"};
		char d[]={"��ѧ��+15 ��ѹ��ֵ+15"};
        putimage(0,0,&background1);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+15;
		A.tui=A.tui+15;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui>100)
		{
			A.tui=100;
		}
		
		
	}
	else if(n==1)
	{
		char a[]={"������ѧϰ��ʵ��һֱ���ֻ���ˮ����һ��"};
		char b[]={"��լֵ+5"};
		putimage(0,0,&background1);
		putimage(200,100,&person_3,SRCPAINT);
		putimage(200,100,&person3,SRCAND);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.zhai+=5;
		if(A.zhai>100)
		{
			A.zhai=100;
		}
	}
	else if(n==2)
	{
		char a[]={"ˢ��һ������ˣ�ÿ�ⶼ��10�ַ���������"};
		char b[]={"ѹ��ֵ+5����ѧ��-5"};
		putimage(0,0,&background1);
		putimage(200,100,&person_2,SRCPAINT);
		putimage(200,100,&person2,SRCAND);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=5;
		A.tui-=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	else 
	{
		char a[]={"С��磬С��磬�������ô��Ѽ"};
		char b[]={"����Ѽ����ѽ���ҽ���Ѽ"};
		char c[]={"������������"};
		char d[]={"������"};
		char e[]={"�������롣����������������"};
		char f[]={"����+15 ��ѹ��ֵ-5"};
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&wenjingmeizi);
		zimu(a,"������");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&wenjingmeizi);
		zimu(c,"������");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(d,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&wenjingmeizi);
		zimu(e,"������");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(f);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya-=5;
		A.qing+=15;
		if(A.ya<0)
		{
			A.ya=0;
		}
		if(A.qing>100)
		{
			A.qing=100;
		}
		
	}
	
}
void gaoshub(int n)
{
	IMAGE laoshi,kaoshitu3,person2,person_2,jimi,tushuguan,person3,person_3;
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&laoshi,_T("ͼƬ\\��ʦ.jpg"),180,180,true);
	loadimage(&kaoshitu3,_T("ͼƬ\\����ͼ3.jpg"),690,532,true);
	loadimage(&tushuguan,_T("ͼƬ\\ͼ���.jpg"),690,532,true);
	loadimage(&jimi,_T("ͼƬ\\���׶�ά��.jpg"),180,180,true);
	loadimage(&person3,_T("ͼƬ\\��è��3.jpg"),180,180,true);
	loadimage(&person_3,_T("ͼƬ\\��è��3����ͼ.jpg"),180,180,true);
	if(n==0)
	{
		char a[]={"�㿴�������Ķ���ʲô��ҵ������ʲô����"};
		char b[]={"���������ǲ�С��˯�Ż�����"};
		char c[]={"���Ʊ磬ƽʱ��û����"};
		char d[]={"������������������"};
		char e[]={"��ѧ��+5��ѹ��ֵ+15"};
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&laoshi);
		zimu(a,"��ʦ");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&laoshi);
		zimu(c,"��ʦ");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(d,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(e);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=15;
		A.tui+=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui>100)
		{
			A.tui=100;
		}
		
		
		
	}
	else if(n==1)
	{
		char a[]={"��ѧ���˸���B ������ȥˢ���׶�ά�棬ͻȻ�о��Լ��ò�"};
		char b[]={"ѹ��ֵ+15 ����ѧ��-10"};
		putimage(0,0,&tushuguan);
		putimage(20,170,&jimi);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&tushuguan);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=15;
		A.tui-=10;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	else if(n==2)
	{
		char a[]={"���п��쵽�ˣ������Լ����кö�û��Ԥϰ��֪ʶ��"};
		char b[]={"ѹ��ֵ+15 ����ѧ��-5"};
		putimage(0,0,&kaoshitu3);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=15;
		A.tui-=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
		
	}
	else 
	{
		char a[]={"�ڽ��Ҷ��飬������ѧϰ��ʵ��һֱ���ֻ���ˮ����һ��"};
		char b[]={"��լֵ+10"};
		putimage(0,0,&kaoshitu3);
		putimage(200,100,&person_3,SRCPAINT);
		putimage(200,100,&person3,SRCAND);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.zhai+=10;
		if(A.zhai>100)
		{
			A.zhai=100;
		}
		
		
		
	}
	
}
void gaoshua(int n)
{
	IMAGE tushuguan,fubian1,fubian,fubian2,fubian3,xueximeizi;
	loadimage(&tushuguan,_T("ͼƬ\\ͼ���.jpg"),690,532,true);
	loadimage(&fubian1,_T("ͼƬ\\���亯��1.jpg"),150,150,true);
	loadimage(&fubian,_T("ͼƬ\\���亯��.jpg"),150,150,true);
	loadimage(&fubian2,_T("ͼƬ\\����2.jpg"),150,150,true);
	loadimage(&fubian3,_T("ͼƬ\\����3.jpg"),150,150,true);
	loadimage(&xueximeizi,_T("ͼƬ\\ѧϰ����.jpg"),100,200,true);
	IMAGE laoshi,kaoshitu3,person2,person_2,jiyou;
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&laoshi,_T("ͼƬ\\��ʦ.jpg"),180,180,true);
	loadimage(&kaoshitu3,_T("ͼƬ\\����ͼ3.jpg"),690,532,true);
	loadimage(&jiyou,_T("ͼƬ\\����.jpg"),180,180,true);
	if(n==0)
	{
		char a[]={"�򿴲������亯������������Ա��ˣ��о��Լ�ͷ��������"};
		char b[]={"ѹ��ֵ+15 ����ѧ��-5"};
		putimage(0,0,&tushuguan);
		zimu1(a);
		putimage(200,150,&fubian);
		Sleep(1000);
		putimage(200,150,&fubian1);
		Sleep(1000);
		putimage(200,150,&fubian2);
		Sleep(1000);
		putimage(200,150,&fubian3);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&tushuguan);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=15;
		A.tui-=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		A.tui-=5;
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	if (n==1)
	{
		char a[100];
		strcpy(a,A.returnname());
		char b[]={"ͬѧ�������ǰ༶��һ�����Ҫ�ú�����ѧϰ"};
		strcat(a,b);
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&laoshi);
		zimu(a,"��ʦ");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu("�͵����͵�����ʵҲ���������ð���",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1("ѹ��ֵ-5����ѧ��-10");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.tui-=10;
		A.ya-=5;
		if(A.tui<0)
		{
			A.tui=0;
		}
		if(A.ya<0)
		{
			A.ya=0;
		}
	}
	else if(n==2)
	{
		
		putimage(0,0,&kaoshitu3);
		rputimage(20,170,&laoshi);
		zimu(A.returnname(),"��ʦ");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		
		rputimage(20,170,&laoshi);
		zimu("�����ش�һ���������","��ʦ");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu("����������������",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1("��Ȼ��ǿ�ش�����ģ�����Ϊû֮ǰûԤϰ�����ŵ��ˡ�ѹ��ֵ+10 ����ѧ��-5");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=10;
		A.tui-=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
		
	}
	else 
	{
        putimage(0,0,&tushuguan);
		rputimage(20,170,&jiyou);
		rputimage(300,100,&xueximeizi);
		zimu("��죬��̧ͷ�����Ǹ��Ǳߵ�����","����");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&tushuguan);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu("��������������������",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&tushuguan);
		rputimage(20,170,&jiyou);
		zimu("�����Ҫ��Ҫȥ��ڨ��ڨ����Y ǰȥ��ڨ����N ���ˣ�","����");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		char a=0;
		while(a!='Y'&&a!='y'&&a!='N'&&a!='n')
		{
			a=getch();
		}
		if(a=='Y'||a=='y')
		{
			putimage(0,0,&tushuguan);
			putimage(20,170,&person_2,SRCPAINT);
			putimage(20,170,&person2,SRCAND);
			zimu("ȥ��ȥ���ҿ��ǹ����Ϲ�",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&tushuguan);
			rputimage(560,170,&xueximeizi);
			putimage(20,170,&person_2,SRCPAINT);
			putimage(20,170,&person2,SRCAND);
			zimu("С��㣬С��㣬��Ҳϲ�����Ȿ��ѽ������ϲ���ĸ���ɫ��������������촩����ÿ�",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&tushuguan);
			rputimage(560,170,&xueximeizi);
			zimu("�����š�������������ʵ�����ڡ�����","С���");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&tushuguan);
			zimu1("���ڨ�ɹ���������ϲ��ѹ��ֵ-10 ����������д��ҵ��ѧ��+5������+10");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=10;
			A.tui+=5;
			A.qing+=10;
			if(A.ya<0)
			{
				A.ya=0;
			}
			if(A.tui>100)
			{
				A.tui=100;
			}
			if (A.qing>100)
			{
				A.qing=100;
			}
			
			
			
			
		}
		else 
		{
			putimage(0,0,&tushuguan);
			putimage(20,170,&person_2,SRCPAINT);
			putimage(20,170,&person2,SRCAND);
			zimu("�һ��Ǻú�д��ҵ��",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&tushuguan);
			rputimage(20,170,&jiyou);
			zimu("���ˡ�������������","����");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&tushuguan);
			zimu1("�����������ҵ�����Ǳ����Ѿ��ú��ˣ���ѧ��-10 ������-5");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.qing-=5;
			A.tui-=10;
			if(A.qing<0)
			{
				A.qing=0;
			}
			if(A.tui<0)
			{
				A.tui=0;
			}
			
			
		}
		
	}
	
	
}
void paocao()
{
	IMAGE background1,jiyou,person2,person_2,paocao;
	loadimage(&background1,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	loadimage(&paocao,_T("ͼƬ\\�ܲ�.jpg"),690,532,true);
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&jiyou,_T("ͼƬ\\����.jpg"),180,180,true);
	putimage(0,0,&background1);
	zimu("���������������ˣ������𴲣�������","����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&background1);
	
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
	
	zimu("�����ˣ��һ���˯�����������",A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu("Ҫ������˯������45�ζ��ѣ���Y �ܲ٣���N ����˯��","����");
	char c=0;
	while(c!='Y'&&c!='y'&&c!='N'&&c!='n')
	{
		c=getch();
	}
	if(c=='Y'||c=='y')
	{
		putimage(0,0,&paocao);
		zimu1("ѹ��ֵ+5");
		A.ya+=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		
	}
	else 
	{
		putimage(0,0,&background1);
		zimu1("��ѧ��+5");
		A.tui+=5;
		if(A.tui>100)
		{
			A.tui=100;
		}
	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	
}
void jiangzuo()
{
	IMAGE background1,jiyou,person2,person_2,paocao,kaoshitu3;
	loadimage(&background1,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	
	loadimage(&kaoshitu3,_T("ͼƬ\\����ͼ3.jpg"),690,532,true);
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&jiyou,_T("ͼƬ\\����.jpg"),180,180,true);
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu("��˵����н�����Ҫ��Ҫȥ������","����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&background1);
	
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
	
	zimu("����ʲô��ѽ",A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu("�����ģ�������SRTP�ã���������Ҫ�źܳ��Ķ��飨��Y ȥ����N ��ȥ��","����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	char c=0;
	while(c!='Y'&&c!='y'&&c!='N'&&c!='n')
	{
		c=getch();
	}
	if(c=='Y'||c=='y')
	{
		putimage(0,0,&background1);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		
		
		zimu("�ǸϽ�ȥ�Ŷ�ѽ",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu("��������Ĳ������",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		
		putimage(0,0,&kaoshitu3);
		
		
		zimu1("SRTP+5��ѹ��ֵ+10");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=10;
		A.srtp+=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.srtp>100)
		{
			A.srtp=100;
		}
		
	}
	else 
	{
		putimage(0,0,&background1);
		
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu("���˰ɣ��˶�Ļ����һ������������������",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		
	}
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	
	
	
	
	
	
	
}




void fcyuyan(int n)
{
	IMAGE background1,person1,person2,person3;
	loadimage(&background1,_T("ͼƬ\\����.jpg"),690,532,true);
    loadimage(&person1,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&person3,_T("ͼƬ\\�ľ�����.jpg"),180,180,true);
	char a[]={"ʲô��ʲôԹ, ��59��������"};
	char b[]={"��ѧ��+10 ��ѹ��ֵ+5"};
	char d[]={"c++6.0������"};
	char c[]={"#include<iostream.h> void main(){cout<<so easy��}"};
	putimage(0,0,&background1);
	putimage(20,170,&person2,SRCPAINT);
	putimage(20,170,&person1,SRCAND);
	zimu(d,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	if(n==0)
	{
		putimage(0,0,&background1);
		putimage(20,170,&person2,SRCPAINT); 
		putimage(20,170,&person1,SRCAND);
		zimu(a,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=5;
		A.tui+=10;
		if(A.tui>=100)A.tui=100;
		if(A.ya>100)
		{
			A.ya=100;
		}
	}
	if(n==1)
	{
		putimage(0,0,&background1);
		putimage(20,170,&person2,SRCPAINT); 
		putimage(20,170,&person1,SRCAND);
		zimu("һ�ÿ������������Լ�ͷ�����˲��٣����Ǻô���������",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1("ѹ��ֵ+10 ����ѧ��-5");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=10;
		A.tui-=5;
		if(A.tui<0)A.tui=0;
		if(A.ya>100)
		{
			A.ya=100;
		}
	}
	if(n==2||n==3&&A.qing<20&&A.srtp<30)
		
	{
		putimage(0,0,&background1);
		putimage(20,170,&person2,SRCPAINT); 
		putimage(20,170,&person1,SRCAND);
		zimu("�⡣�������ǿ�����Ԥϰһ�°ɡ�",A.returnname());
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1("ѹ��ֵ+5����ѧ��+5");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=5;
		A.tui+=5;
		if(A.tui>=100)A.tui=100;
		if(A.ya>100)
		{
			A.ya=100;
		}
	}
	if(A.qing>=20&&A.srtp>=30&&n==3)
	{
		putimage(0,0,&background1);
		rputimage(20,170,&person3);
		zimu("ͬѧ����c ++�������������Խ̽�������","Ůͬѧ");
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		putimage(20,170,&person2,SRCPAINT); 
		putimage(20,170,&person1,SRCAND);
		zimu("��ķ�����Ϸ򿴿�����������������������ֻҪ��������������������������",A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		rputimage(20,170,&person3);
		zimu("�ۣ����˶��ˣ�������������Ժ�������̡�","Ůͬѧ");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1("����+5��ѹ��-10 ����լֵ+5����ѧ��-10");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.zhai+=5;
		A.ya-=10;
		A.tui-=10;
		A.qing+=5;
		if(A.zhai>100)
		{
			A.zhai=100;
		}
		if(A.ya<0)
		{
			A.ya=0;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
		if(A.qing>100)
		{
			A.qing=100;
		}
		
	}
}
void dcyuyan(int n)
{
	IMAGE background1,person1,person2;
	loadimage(&background1,_T("ͼƬ\\�߼�����.jpg"),690,532,true);
	loadimage(&person1,_T("ͼƬ\\��è��2.jpg"),180,180,true);
	loadimage(&person2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	char a[]={"�ۣ�����������Ļ����𣬻���̫��"};
	char b[]={"����c++ Ҳ���������ַ��ӱ���"};
	char c[]={"һ�����Ҵ򿪷�ʽ�����⣬��Ȼ��ô��������ЩӢ��"};
	char d[]={"�Ҳ��������룬��ֻ�Ǵ���İ��˹�"};
   	putimage(0,0,&background1);
	putimage(20,170,&person2,SRCPAINT);
	putimage(20,170,&person1,SRCAND);
	zimu(a,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	if(A.tui<=50)
	{
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
        putimage(0,0,&background1);
		zimu1("ѹ��ֵ-10 , ��ѧ��-5");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya-=10;
		A.tui-=5;
		if(A.ya<0)
		{
			A.ya=0;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	else if(A.tui>50&&A.tui<=60)
	{
		zimu(d,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
        putimage(0,0,&background1);
		zimu1("ѹ��ֵ+5����ѧ��+5");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=5;
		A.tui+=5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui>100)
		{
			A.tui=100;
		}
	}
	else
	{
		zimu(c,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		zimu1("ѹ��ֵ+10 ����ѧ��+10");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=10;
		A.tui+=10;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui>100)
		{
			A.tui=100;
		}
	}
	
}

void shejiao()
{
	IMAGE person1,person2,person3,person4,person5,person6,person7,person8,b1,b2,b3,b4,b5,b6,kfc;
    loadimage(&b1,_T("ͼƬ\\��լ����.jpg"),690,532,true);
    loadimage(&person1,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
    loadimage(&b2,_T("ͼƬ\\����.jpg"),690,532,true);
    loadimage(&b3,_T("ͼƬ\\��ϰ��.jpg"),690,532,true);
    loadimage(&b4,_T("ͼƬ\\�㳡.jpg"),690,532,true);
	loadimage(&b5,_T("ͼƬ\\�����.jpg"),690,532,true);
	loadimage(&b6,_T("ͼƬ\\KTV.jpg"),690,532,true);
    loadimage(&person3,_T("ͼƬ\\�罻����1.jpg"),180,180,true);
	loadimage(&person4,_T("ͼƬ\\�罻����2.jpg"),180,180,true);
	loadimage(&person5,_T("ͼƬ\\�罻����3.jpg"),180,180,true);
	loadimage(&person6,_T("ͼƬ\\����2.jpg"),180,180,true);
	loadimage(&person7,_T("ͼƬ\\�罻����4.jpg"),180,180,true);
	loadimage(&person8,_T("ͼƬ\\����.jpg"),180,180,true);
	loadimage(&kfc,_T("ͼƬ\\kfc.jpg"),690,532,true);
	char a[]={"�����ߣ��������ѧ�磬�缸��ȥ����ˣһˣ��"};
	char b[]={"��Լ��Լ������ȥһ����ϰ��"};
	char c[]={"�ۣ������֡�"};
	char d[]={"��Լ��Լ����ȥ�����������û�гԵģ�û���緹���Ӷ���"};
	char e[]={"��Լ��Լ���ҰѶ������ڽ����ˣ���ȥ��һ�¡�"};
	char f[]={"��Լ��Լ����ȥһ�¹㳡���Ǳߺ����л��"};
	char g[]={"Լ��Լ��ȥ��K ��"};
	char h[]={"���������ã���������~~~~"};
	char i[]={"����̫��~~~~"};
	char j[]={"����������~~���㿴��������ִ���Բ��������������ִ���Բ~~"};
	char k[]={"ͬѧ���������λ��������"};
	char l[]={"û���أ�������"};
	char m[]={"С��㷽��Ӹ�΢�����´�һ��Լѧϰ����"};
	char n[]={"������u �̶����ˣ������������ض����ѧϰ���ϰ�"};
	char o[]={"ͬѧ�������������u �����Ҹո��ڽ��ҷ��ֵġ�"};
	char p[]={"emmm���ǵģ�лл��"};
	char q[]={"С��㡣����Ӹ�΢�����п�����Ը�����лһ�¡�"};
	char r[]={"�ð�������˳��������������㲻����ɡ�"};
	putimage(0,0,&b1);
	rputimage(20,170,&person6);
	zimu(a,"����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&b1);
	
	zimu1("1.ȥ��ϰ�ң�2.ȥ��ѧ¥��3.ȥ�㳡��4.ȥ������裬5.�����ѳ�ȥˣ");
	
	char s=0;
	while(s!='1'&&s!='2'&&s!='3'&&s!='4'&&s!='5')
	{
		
		s=getch();
		
		
		if(s=='1')
		{
			putimage(0,0,&b1);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(b,A.returnname());
			
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(k,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			rputimage(20,170,&person3);
			zimu(l,"������");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("( ���ϣ����С�����ÿ����ľ����ţ�ȥҪ����ϵ��ʽ) ",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(m,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			rputimage(20,170,&person3);
			zimu("Ŷ�������ˣ�û��","������");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("������������",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b3);
			zimu1("ѹ��ֵ-5������+5");
			A.ya-=5;
			A.qing+=5;
			if(A.ya<=0)A.ya=0;
			if(A.qing>=100)A.qing=100;
		}
		if(s=='2')
		{
			putimage(0,0,&b1);
			zimu(e,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(n,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			rputimage(20,170,&person7);
			zimu(o,"Ī��ҹ");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("( Ҫ�ǿ��Եõ����С������ϵ��ʽ���һ�Ҫʲôѧϰ���ϡ�) ",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(p,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(q,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			rputimage(20,170,&person7);
			zimu(r,"Ī��ҹ");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("������������",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b2);
			zimu1("ѹ��ֵ-7������+7");
			A.ya-=7;
			A.qing+=7;
			if(A.ya<=0)A.ya=0;
			if(A.qing>=100)A.qing=100;
		}
		if(s=='3')
		{
			putimage(0,0,&b1);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			
			zimu(f,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(c,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			rputimage(20,170,&person5);
			zimu("ͬѧ�������˽�һ��","è��С���");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("�����������������լҲŤ���������� ",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("��ѽ�����ǼӸ���ϵ��ʽ�ɣ���������ϵ��",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			rputimage(20,170,&person5);
			zimu("������ֻ�Ǹ��𷢴����ģ�����ֻ������Ա���㿴","è��С���");
			putimage(0,0,&kfc);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("������������",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b4);
			zimu1("ѹ��ֵ-5������+5");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=5;
			A.qing+=5;
			if(A.ya>=100)A.ya=100;
			if(A.qing<=0)A.qing=0;
		}
		if(s=='4')
		{
			putimage(0,0,&b1);
			zimu(d,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("������˲����ر���أ�����������ʲô���ء�����",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			rputimage(20,170,&person4);
			zimu("������������˼ͬѧ�����԰��Ҹ�һ�¿�����У԰��ûǮ�ˣ���ͷת����","��Ů");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("�����ò���ͦ�ɰ��ģ��ǾͰ�����ɣ�",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("�ðɡ�����������",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			rputimage(20,170,&person4);
			zimu("лл�㣬����΢��ת����","��Ů");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("�����Ǵ���Ҫ������С���΢�������ţ��ٺ١���",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			rputimage(20,170,&person4);
			zimu("���������������ˣ�darling~�������","��Ů");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("������������",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b5);
			zimu1("ѹ��-5������+5");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=5;
			A.qing+=5;
			if(A.ya<=0)A.ya=0;
			if(A.qing>=100)A.qing=100;
		}
		if(s=='5')
		{
			putimage(0,0,&b1);
			zimu(g,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b1);
			rputimage(20,170,&person6);
			zimu("�ã�����","����");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b6);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(h,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b6);
			rputimage(20,170,&person6);
			zimu(i,"����");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b6);
			rputimage(20,170,&person8);
			zimu(j,"����");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b6);
			zimu1("��˵���ˬ����������Ҳ�߰���");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&b6);
			zimu1("ѹ��ֵ-10 ������+5����Ǯ-200");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.money-=200;
			A.ya-=10;
			A.qing+=5;	
			if(A.ya<=0)A.ya=0;
			if(A.qing>=100)A.qing=100;
			if(A.money<=0)A.money=0;
		}
	}
}



void bilibili()
{
	IMAGE background1,person1,person2,background2,background3,background4,jiyou;
	loadimage(&background1,_T("ͼƬ\\bվ.jpg"),690,532,true);
	loadimage(&person1,_T("ͼƬ\\��è��2.jpg"),180,180,true);
	loadimage(&person2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&background2,_T("ͼƬ\\bվѧϰ.jpg"),690,532,true);
	loadimage(&background3,_T("ͼƬ\\����.jpg"),690,532,true);
	loadimage(&background4,_T("ͼƬ\\����.jpg"),690,532,true);
	loadimage(&jiyou,_T("ͼƬ\\����.jpg"),180,180,true);
	char a[]={"����һ��ѧ, ˢ���b վ����һ���, ���������󿴿�"};
	char b[]={"����Ҳ�����ţ���Ȼ��b վ�ҵ��������"};
	char c[]={"���ٺ�~~������������Ư�����ٶ࿴�����"};
	char d[]={"���ҿ���b վ�Ͻ�����ʲô������������"};
    putimage(0,0,&background1);
	putimage(20,170,&person2,SRCPAINT);
	putimage(20,170,&person1,SRCAND);
	zimu(d,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	 putimage(0,0,&background1);
	zimu1("1.�����Σ�2.������3.��С���");
	char e='0';
	while(e!='1'&&e!='2'&&e!='3')
	{
		e=getch();
		if(e=='1')
		{
			putimage(0,0,&background2);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(b,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background2);
			rputimage(20,170,&jiyou);
			zimu("�������Ȼ��͵͵ѧϰ����Ҳ̫�����ɡ�","����");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background1);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu("����û������û���ˡ�",A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background1);
			zimu1("ѹ��ֵ-5����ѧ��-10 ������-10");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=5;
			A.qing-=10;
			A.tui-=10;
			if(A.ya<0)
			{
				A.ya=0;
			}
			if(A.qing<0)
			{
				A.qing=0;
			}
			if(A.tui<0)
			{
				A.tui=0;
			}
			
		}
		if(e=='2')
		{ 
			putimage(0,0,&background4);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(a,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background4);
			zimu1("ѹ��ֵ-15 ����ѧ��+10 ����լֵ+10 ������-10");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=10;
			A.tui+=10;
			A.zhai+=10;
			if(A.ya<0)
			{
				A.ya=0;
			}
			if(A.qing<0)
			{
				A.qing=0;
			}
			if(A.tui>100)
			{
				A.tui=100;
			}
			if(A.zhai>100)
			{
				A.zhai=100;
				
			}
			
		}
		if(e=='3')
		{
			putimage(0,0,&background3);
			putimage(20,170,&person2,SRCPAINT);
			putimage(20,170,&person1,SRCAND);
			zimu(c,A.returnname());
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			putimage(0,0,&background3);
			zimu1("ѹ��ֵ-20 ����ѧ��+10 ����լֵ+15 ");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			A.ya-=20;
			A.tui+=10;
			A.zhai+=15;
			if(A.ya<0)
			{
				A.ya=0;
			}
			if(A.tui>100)
			{
				A.tui=100;
			}
			if(A.zhai>100)
			{
				A.zhai=100;
				
			}
			
		}
	}
	
}




void yingyu2(int n)
{
    IMAGE  kaoshitu3,background2,yingyu,background1,person2,person_2,person3,person_3,xueximeizi,dongda,wenlur,yingyuls,yingyujiao;
    loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&background1,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	loadimage(&background2,_T("ͼƬ\\��լ����4399.jpg"),690,532,true);
	loadimage(&kaoshitu3,_T("ͼƬ\\����ͼ3.jpg"),690,532,true);
	loadimage(&person3,_T("ͼƬ\\��è��3.jpg"),180,180,true);
	loadimage(&person_3,_T("ͼƬ\\��è��3����ͼ.jpg"),180,180,true);
	loadimage(&yingyu,_T("ͼƬ\\Ӣ���.jpg"),690,532,true);
	loadimage(&xueximeizi,_T("ͼƬ\\ѧϰ����.jpg"),180,180,true);
	loadimage(&dongda,_T("ͼƬ\\����.jpg"),690,532,true);
	loadimage(&wenlur,_T("ͼƬ\\��·��.jpg"),180,180,true);
	loadimage(&yingyuls,_T("ͼƬ\\Ӣ����ʦ.jpg"),180,180,true);
	if(n==0)
	{
		char a[]={"��Ϊ������Ӣ����Ϸ�����ö�Ŭ��ѧϰһ��ʱ���"};
		char b[]={"������Щ��Ϸ�ľ���������"};
		char c[]={"������Ϸ����������Ƿ�"};
		char d[]={"��ѧ��+15,ѹ��ֵ-5"};
		putimage(0,0,&yingyu);
		zimu1(a);
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background2);
		putimage(500,170,&person_2,SRCPAINT);
		putimage(500,170,&person2,SRCAND);
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background2);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		getch();
		putimage(0,0,&background2);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		getch();
		A.ya=A.ya-5;
		A.tui=A.tui+15;
		if(A.tui>100)
		{
			A.tui=100;
		}
		if(A.ya<0)
		{
			A.ya=0;
		}
	}
	else if(n==1)
	{
		char a[]={"Hello I am lost. Where is Gangju Gymnasium���־������ݣ�?"};
		char b[]={"Go straight along Nangong Road and turn right at the first crossing to see it.�����ⲻ�Ǳ����۾����ҵõ���"};
		char c[]={"Thanks for you help"};
		char d[]={"ѹ��ֵ-10 ����ѧ��-10"};
		putimage(0,0,&dongda);
		rputimage(20,170,&wenlur);
		zimu3(a,"·��");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&dongda);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu3(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&dongda);
		rputimage(20,170,&wenlur);
		zimu3(c,"·��");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&dongda);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya-10;
		A.tui =A.tui-10;
		if(A.ya<0)
		{
			A.ya=0;
		}
		if(A.tui<0)
		{
			A.tui =0;
		}
		
	}
	else if(n==2)
	{
		char a[]="��Ӣ���飬���˷���������ʲô����ѧϰ����˼������ʣ�����ͷ����������";
		char b[]="ʱ������ĥ��������ȥ�����ʲô��û�м�ס";
		char c[]="��ѧ��+10,  ѹ��ֵ+10";
		putimage(0,0,&kaoshitu3);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&kaoshitu3);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya =A.ya +10;
		A.tui=A.tui +10;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui>100)
		{
			A.tui=100;
		}
	}
	else
	{
		char a[]={"������������������ʦ����ҵ�����ڿ����ϻ������ۣ��ջ�ܶ�"};
		char b[]={"��ҵ��ɵĲ�����������Ŷ"};
		char c[]={"�����˺ܸ��ˣ����ڴ���ĩ����һ���óɼ�"};
		char d[]={"ѹ��ֵ+5����ѧ��-10"};
		putimage(0,0,&yingyu);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyu);
		rputimage(20,170,&yingyuls);
		zimu(b,"Ӣ����ʦ");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyu);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyujiao);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya+=5;
		A.tui-=10;
		if (A.ya >100)
		{
			A.ya=100;
		}
		if (A.tui<0)
		{
			A.tui=0;
		}
	}
}
void yingyu3(int n)
{
	IMAGE yingyu,background1,background2,yingyu2,yyztxx,yingyuls,person2,person_2,yingyuxs,kaoshitu3,person3,person_3;
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&background1,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	loadimage(&yingyu2,_T("ͼƬ\\Ӣ���2.jpg"),690,532,true);
	loadimage(&kaoshitu3,_T("ͼƬ\\����ͼ3.jpg"),690,532,true);
	loadimage(&person3,_T("ͼƬ\\��è��3.jpg"),180,180,true);
	loadimage(&person_3,_T("ͼƬ\\��è��3����ͼ.jpg"),180,180,true);
	loadimage(&yingyu,_T("ͼƬ\\Ӣ���.jpg"),690,532,true);
	loadimage(&yingyuxs,_T("ͼƬ\\Ӣ��ѧ��.jpg"),180,180,true);
	loadimage(&yingyuls,_T("ͼƬ\\Ӣ����ʦ.jpg"),180,180,true);
	loadimage(&yyztxx,_T("ͼƬ\\��Ҷ֮ͥѧϰͼ.jpg"),690,532,true);
	if(n==0)
	{
		char a[]={"��ð����Ͽ�ʱ��ķ��������"};
		char b[]={"����ѧ�Ļ����ǿ���һ����"};
		char c[]={"��һ��ѧϰ��ʱ������ջ���֪ʶ�����飬��Ҳ����Ҫ���������˵��ڴ���ѹ��"};
		char d[]={"��ѧ��-5, ѹ��ֵ+5"};
		putimage(0,0,&yingyu);
		rputimage(20,170,&yingyuxs);
		zimu(a,"����");
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyu);
		putimage(20,170,&person_2,SRCPAINT);
		putimage(20,170,&person2,SRCAND);
		zimu(b,A.returnname());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyu);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yingyu2);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+5;
		A.tui=A.tui-5;
		if(A.ya>0)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	if(n==1)
	{
		char a[]={"����������һ��ʲôʲô��Ҫȥ��ʲôʲô������"};
		char b[]={"���������߶��һЩ��֪��˼��Ӣ�ĵ��ʣ������ѷ���"};
		char c[]={"ѹ��ֵ+10,  ��ѧ��-5"};
		putimage(0,0,&background1);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+10;
		A.tui=A.tui-10;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	if(n==2)
	{
		char a[]={"��Ϊ�������ԭ�����Է��������ڿ�"};
		char b[]={"ѹ��ֵ+10,  ��ѧ��+5"};
		putimage(0,0,&yyztxx);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&yyztxx);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+10;
		A.tui=A.tui+5;
	}
}
void yingyu4(int n)
{
	IMAGE yingyu,background1,background2,yingyust,yingyu2,yingyuls,zhuijutu,person2,person_2,yingyuxs,kaoshitu3,person3,person_3;
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&background1,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	loadimage(&yingyu2,_T("ͼƬ\\Ӣ���2.jpg"),690,532,true);
	loadimage(&kaoshitu3,_T("ͼƬ\\����ͼ3.jpg"),690,532,true);
	loadimage(&person3,_T("ͼƬ\\��è��3.jpg"),180,180,true);
	loadimage(&person_3,_T("ͼƬ\\��è��3����ͼ.jpg"),180,180,true);
	loadimage(&yingyu,_T("ͼƬ\\Ӣ���.jpg"),690,532,true);
	loadimage(&yingyuxs,_T("ͼƬ\\Ӣ��ѧ��.jpg"),180,180,true);
	loadimage(&zhuijutu,_T("ͼƬ\\׷��ͼƬ.jpg"),690,532,true);
	loadimage(&yingyust,_T("ͼƬ\\Ӣ������.jpg"),180,180,true);
	
	if (n==0)
	{
		char a[]={"�ļ����ԾͿ쵽�ˣ������Լ����ܿ�����ʮ�ֽ���"};
		char b[]={"ѹ��ֵ+10,  ��ѧ��-5"};
		putimage(0,0,&background1);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
        A.ya=A.ya+10;
		A.tui=A.tui-5;
		if(A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
	if(n==1)
	{
		char a[]={"Ϊ������Ӣ��ˮƽ��ѡ��׷����"};
		char b[]={"Ȼ����׷��ʱֻ��ס�˾���"};
		char c[]={"��ѧ��+5, ѹ��ֵ+5"};
		putimage(0,0,&zhuijutu);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&zhuijutu);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&zhuijutu);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+5;
		A.tui=A.tui+5;
		if(A.tui>100)
		{
			A.tui=100;
		}
		if(A.ya>100)
		{
			A.ya=100;
		}
	}
	if(n==2)
	{
		char a[]={"�����ѧϰ��ˢ�˼����ļ�����"};
		char b[]={"ѹ��ֵ+10,  ��ѧ��-10"};
		putimage(0,0,&background1);
		putimage(20,170,&yingyust);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&background1);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		A.ya=A.ya+10;
		A.tui=A.tui-10;
		if (A.ya>100)
		{
			A.ya=100;
		}
		if(A.tui<0)
		{
			A.tui=0;
		}
	}
}
void dagong(int n)
{
	
	IMAGE dgxiwantu,dgrw,ss,p2,p_2,dgfuwuyuantu,dagongsyy,yaoqianr,jifei,dagongtx,lb,guke,baoli,laodongfa,bangongs;
	loadimage(&laodongfa,_T("ͼƬ\\�Ͷ���.jpg"),180,180,true);
	loadimage(&yaoqianr,_T("ͼƬ\\ҪǮ��.jpg"),180,180,true);
	loadimage(&jifei,_T("ͼƬ\\����ͼ.jpg"),690,532,true);
	loadimage(&bangongs,_T("ͼƬ\\�칫��.jpg"),690,532,true);
	loadimage(&p2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
	loadimage(&baoli,_T("ͼƬ\\�������.jpg"),690,532,true);
    loadimage(&p_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
    loadimage(&dgxiwantu,_T("ͼƬ\\��ϴ��ͼ.jpg"),690,532,true);
	loadimage(&dgfuwuyuantu,_T("ͼƬ\\�򹤷���Ա.jpg"),690,532,true);
	loadimage(&dgrw,_T("ͼƬ\\����.jpg"),180,180,true);
	loadimage(&dagongsyy,_T("ͼƬ\\����Ա.jpg"),690,532,true);
	loadimage(&lb,_T("ͼƬ\\�ϰ�ͼ.jpg"),180,180,true);
	loadimage(&dagongtx,_T("ͼƬ\\�򹤵�ͬѧ.jpg"),180,180,true);
	loadimage(&guke,_T("ͼƬ\\�˿�.jpg"),180,180,true);
	if(n==0)
	{
		char a[]={"�㵽��һ��С�͹���ϴ�빤�ļ�ְ"};
		char b[]={"����������ϴ��ʱ��ͻȻ�뵽��һ���µ�ϴ�뷽�����ƺ��ܸ�Ч������y �����ã���n ��������"};
		char c[]={"ϴˢˢ��ϴˢˢ������������µ�ϴ�뷽��ʱ������˳�ȥ"};
		char d[]={"���ò�˵����µķ�����ͦ��������Ч����߲���"};
        char e[]={"�����������뷨������������ϴ��"};
		char f[]={"�����+150, ��ѧ��+5"};
		char g[]={"ѹ��ֵ+1����ѧ��+5�������+80"};
		putimage(0,0,&dgxiwantu);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&dgxiwantu);
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		char i;
		while(true)
		{
			i=getch();
			if(i=='Y'||i=='y')
			{
				int a1;
				a1=randrange(2);
				if(a1==1)
				{
					putimage(0,0,&dgxiwantu);
					zimu1(c);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                    getch();
					putimage(0,0,&dgxiwantu);
					zimu1(g);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                    getch();
					
					A.money=A.money+80;
					A.ya=A.ya+1;
					A.tui=A.tui+5;
					if(A.ya>100)
					{
						A.ya=100;
					}
					if(A.tui>100)
					{
						A.tui=100;
					}
					
				}
				else if(a1==0)
				{
					putimage(0,0,&dgxiwantu);
					zimu1(d);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                    getch();
					putimage(0,0,&dgxiwantu);
					zimu1(f);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
					getch();
					
					A.money =A.money +150;
					A.tui =A.tui+5;
					if(A.tui>100)
					{
						A.tui =100;
					}
				}
				break;
				
			}
			else if (i=='N'||i=='n')
			{
				putimage(0,0,&dgxiwantu);
				zimu1(e);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&dgxiwantu);
				zimu1("�����+100����ѧ��+5");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				A.money =A.money+100;
				A.tui=A.tui+5;
				if (A.tui>100)
				{
					A.tui=100;
				}
				break;
			}
			
		}
	}
	else if(n==1)
	{
		char a[]={"������һ��С�굱��ӪԱ"};
		char b[]={"��������״���������ؼ۱㵱"};
		char c[]={"�õģ���ת��ȥȡ�˼��ݱ㵱"};
		char d[]={"�㿴�ű㵱���������ǲ���Ҫ������������ļһ�Ӱ�y,���Ӱ�n)"};
		char e[]={"��թ���������ˣ����������㱻һȭ����"};
		char f[]={"�����-50,  ��ѧ��+5"};
		char g[]={"������������˽���"};
		char h[]={"�����+100����ѧ��+5"};
		putimage(0,0,&dagongsyy);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&dagongsyy);
		rputimage(20,170,&guke);
        zimu(b,"������ʦ");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&dagongsyy);
		putimage(20,170,&p_2,SRCPAINT);
		putimage(20,170,&p2,SRCAND);
		zimu(c,A.returnname());
		putimage(0,0,&dagongsyy);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		char i;
		while(true)
		{
			i=getch();
			if(i=='Y'||i=='y')
			{
				putimage(0,0,&dagongsyy);
				zimu1(e);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&jifei);
				zimu1(f);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				A.money =A.money-50;
				A.tui =A.tui+5;
				if(A.tui>100)
				{
					A.tui=100;
				}
				break;
			}
			else if (i=='N'||i=='n')
			{
				putimage(0,0,&dagongsyy);
				zimu1(g);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&dagongsyy);
				zimu1(h);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				A.money=A.money+100;
				A.tui=A.tui+5;
				if(A.tui>100)
				{
					A.tui=100;
				}
				break;
			}
			
			
		}
	}
	else if(n==2)
	{
		char a[]={"�����У�գ���Ҳ����ĳ���ѧ����"};
		char b[]={"�ǵģ������ȻҲ��У��"};
		char c[]={"���������ģ������������˼"};
		char d[]={"�����㿴�˿�ʱ�䣬�ƺ�����Щ����û������������ȥ��Y,  ������N ��"};
		char e[]={"���Ǽ���������ȥ��ʱ�䲻֪������ȥ�ˡ�����"};
		char f[]={"����+10,  ��ѧ��+10"};
		char g[]={"����ٽ����˻��⣬��������"};
		char h[]={"�����+100����ѧ��+5"};
		putimage(0,0,&dgfuwuyuantu);
		rputimage(20,170,&dagongtx);
		zimu(a,"У��");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&dgfuwuyuantu);
		rputimage(20,170,&dgrw);
		zimu(b,A.returnname ());
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&dgfuwuyuantu);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&dgfuwuyuantu);
		zimu1(d);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		char i;
		while(true)
		{
			i=getch();
			if(i=='Y'||i=='y')
			{
				putimage(0,0,&dgfuwuyuantu);
				zimu1(e);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&dgfuwuyuantu);
				zimu1(f);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				A.qing=A.qing+10;
				A.tui =A.tui+10;
				if(A.qing >100)
				{
					A.qing=100;
				}
				break;
			}
			
			else if (i=='N'||i=='n')
			{
				putimage(0,0,&dgfuwuyuantu);
				zimu1(g);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&dgfuwuyuantu);
				zimu1(h);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				A.money=A.money+100;
				A.tui=A.tui+5;
				if(A.tui>100)
				{
					A.tui=100;
				}
				break;
			}
			
		}
	}
	else if(n==3)
	{
		char a[]={"�������һ��Ĺ������������ϰ�İ칫��"};
		char b[]={"������Ĺ��ʣ�����"};
		char c[]={"�㿴�˿����ʣ��ƺ���Ŀ���ԣ��������ɰ�Y,  ĬĬ�뿪�� N )"};
		char d1[]={"���������Ŀ���԰�"};
		char e1[]={"�����*&����%��#@��@#��%����&*��ò������������Щ��֣�"};
		char f[]={"�㿼����һ�£��Ƿ�Ҫ��������������Y,  �뿪�� N )"};
		char g1[]={"ȭͷ������Y ���Ͷ��������� N"};
		char h1[]={"����������һ�٣���Ҳ�������ˡ�����"};
		char h2[]={"��֧֧����˵����������ֻ���ó����ٸ��Ĺ���"};
		char g2[]={"�㱻��˵���ˣ�����ͷʱ�ܾ������ڲ��������Ц��"};
		char d2[]={"���벻����һ��Ĺ��ʶ��ѣ���ֵ�����ۣ������뿪��"};
		char zm1[]={"�����-100��ѹ��ֵ-5����ѧ��+10"};
		char zm2[]={"�����+200����ѧ��+5"};
		char zm3[]={"�����+70 ����ѧ��+10"};
		putimage(0,0,&bangongs);
		zimu1(a);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&bangongs);
		rputimage(20,170,&lb);
		zimu(b,"�ϰ�");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        getch();
		putimage(0,0,&bangongs);
		zimu1(c);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
        char i;
		while(true)
		{
			i=getch();
			if(i=='Y'||i=='y')
			{
				putimage(0,0,&bangongs);
				rputimage(20,170,&yaoqianr);
				zimu(d1,A.returnname ());
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&bangongs);
				rputimage(20,170,&lb);
				zimu(e1,"�ϰ�");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                getch();
				putimage(0,0,&bangongs);
				zimu1(f);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                char j=0;
				while(true)
				{
					j=getch();
					if(j=='Y'||j=='y')
					{
						putimage(0,0,&bangongs);
						zimu1(g1);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
						char z=0;
						while(true)
						{
							z=getch();
							if(z=='y'||z=='Y')
							{
								putimage(0,0,&baoli);
								zimu1(h1);
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
                                getch();
								putimage(0,0,&baoli);
								zimu1(zm1);
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
								getch();
								A.money=A.money-50;
								A.ya=A.ya-5;
								A.tui=A.tui+10;
								if(A.ya<0)
								{
									A.ya=0;
								}
								if(A.tui>100)
								{
									A.tui=100;
								}
								break;
								
								
							}
							else if(z=='n'||z=='N')
							{
								putimage(0,0,&bangongs);
								putimage(250,170,&laodongfa);
								zimu1(h2);
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
								getch();
								putimage(0,0,&bangongs);
								zimu1(zm2);
								FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
								getch();
								A.money=A.money+200;
								A.tui=A.tui +5;
								if(A.tui>100)
								{
									A.tui=100;
								}
								break;
								
							}
							
							
							
							
						}
						break;
						
					}
					else if(j=='n'||j=='N')
					{
						putimage(0,0,&bangongs);
						zimu1(g2);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						getch();
						putimage(0,0,&bangongs);
						zimu1(zm3);
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						getch();
						A.tui=A.tui+10;
						A.money=A.money+70;
						if(A.tui>100)
						{
							A.tui=100;
						}
						break;
					}
					
				}
				break;
				
				
				
			}
			else if(i=='n'||i=='N')
			{
				putimage(0,0,&bangongs);
				zimu1(d2);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				getch();
				zimu1(zm3);
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				getch();
				A.tui=A.tui+10;
				A.money=A.money+70;
				if(A.tui>100)
				{
					A.tui=100;
				}
				break;
			}
		}
		
		
	}
}







void jiewei()
{
	IMAGE background1,jiewei1,jiewei2,chengxuyuan,shangren,gongren,kexuejia,yingyulaoshi,fenxishi,chuguo,yishujia;
	loadimage(&background1,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	loadimage(&jiewei1,_T("ͼƬ\\��β1.jpg"),690,532,true);
	loadimage(&jiewei2,_T("ͼƬ\\��β2.jpg"),690,532,true);
	loadimage(&chengxuyuan,_T("ͼƬ\\����Ա.jpg"),690,532,true);
	loadimage(&shangren,_T("ͼƬ\\����.jpg"),690,532,true);
	loadimage(&fenxishi,_T("ͼƬ\\����ʦ.jpg"),690,532,true);
	loadimage(&gongren,_T("ͼƬ\\����.jpg"),690,532,true);
	loadimage(&kexuejia,_T("ͼƬ\\��ѧ��.jpg"),690,532,true);
	loadimage(&yingyulaoshi,_T("ͼƬ\\ְҵӢ����ʦ.jpg"),690,532,true);
	loadimage(&chuguo,_T("ͼƬ\\����.jpg"),690,532,true);
    loadimage(&yishujia,_T("ͼƬ\\������.jpg"),690,532,true);
	char a[]={"���������Ȼ���������Ϣ�������꣬�Һ���Ҳû����ʲô���£�����ô��ȥ�ˣ���������һ��裬һ���ֵ������Ѿ����У������ˣ������أ�"};
	char b[]={"��������뿪ʱ������ָ�����ǰ��ƽ����һ�ж���������û������һ������ҵ����Ҳ�Ѿ����ˣ���ʱ���Ϊδ������һ����"};
	char c[]={"�뿪���Ǹ�����������ĳ��У���������һ��û����ĳ��У������¥������Ȼ����������ҵļ�"};
	char d[]={"�ұ����ڴ��С�ΪѰ�ҹ�����ƣ����������ʱ������ոյ���ѧ����һ�죬�������ѧ����Ⱥ�ˡ�����������"};
	putimage(0,0,&background1);
	zimu2(a,"�����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	zimu2(b,"�����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&jiewei1);
	zimu2(c,"�����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&jiewei2);
	zimu2(d,"�����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	cleardevice();
	B.gaoshushu=B.gaoshushu+B.gaoshudengji*3;
	B.yingyushu=B.yingyushu+B.yingyudengji*3;
	B.cyuyanshu=B.cyuyanshu+B.cyuyandengji*3;
	if(A.srtp<30)
	{
		putimage(0,0,&gongren);
		zimu2("��Ȼ�����˺þã�����Ȼû�ҵ����ʵĹ�����û�취��Ϊ�����ƣ���ֻ�ý��빤����Ϊһ�����ˣ��������������","�����");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		putimage(0,0,&gongren);
		zimu2("ÿ���ظ��Ĺ����������ľ�ƣ�����������ȥ�����","�����");
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		getch();
		
		
	}
	else 
	{
		if(B.gaoshushu>B.yingyushu &&B.gaoshushu>B.cyuyanshu)
		{
			if(A.qing>70)
			{
				putimage(0,0,&shangren);
				zimu2("�ҽ�������ҵȦ����Ϊ�������㲻�����ְ�úܿ죬û����þ��Ѿ���һ�������ܾ�����","�����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&shangren);
				zimu2("Խ�ڸߴ�����Խ�о����¶����ƺ�ûʲô��������ң��Ҽ�������ɫɫ��Ů���ӣ�Ҳ����ʱ��Ϊ�Լ��Ҹ����ʵİ�����","�����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				A.money=A.money+10000;
				
			}
			else 
			{
				putimage(0,0,&fenxishi);
				zimu2("���Լ�ѧϰ�˹�ƱͶ�ʣ��������Ϻ�֤ȯ��������ҵ��Ҳ���У�����С���˰�","�����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&fenxishi);
				zimu2("�������ӻ���ͦƽ���� ����������ҪΪ�Լ��Ҹ�����","�����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				A.money+=8501;
			}
			
			
		}
		else 	if(B.cyuyanshu>B.yingyushu && B.cyuyanshu>B.yingyushu)
		{
			if(A.srtp>70)
			{
				putimage(0,0,&chengxuyuan);
				zimu2("���ڣ����ҵ������ˣ���һ������Ա����Ȼ��ͷ�����úܿ죬Ҳ��һ��996 �Ĺ��������ǹ��ʴ������㲻��","�����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&chengxuyuan);
				zimu2("Ψһ�ź����ǣ���ãã�˺��У����ܸ��ܹ¶��������һ���ͷ�����ҵøϽ���һ���������","�����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
			}
			else
			{
				putimage(0,0,&yishujia);
				zimu2("��Ȼ��û���ҵ������Ա��ô�߹��ʵĹ�������ƾ�����Լ����ԵĻ�������Ҳ������һ�Ҷ����������������ң����ӻ��㿪�ģ�û����ô���ѹ��","�����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&yishujia);
				zimu2("�Һ�ϣ�����ҵ�һ��ϲ��������С���","�����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				A.zhai=100;
				
			}
			
		}
		
		else	if(B.yingyushu>B.gaoshushu &&B.yingyushu>B.cyuyanshu)
		{
			if(A.srtp>70 && A.qing>60)
			{
				putimage(0,0,&chuguo);
				zimu2("��û�ҵ��������Ҿ���ȥ���죬��ѧ����˼������9 �֣�����Ӣ���Ľ��Ŵ�ѧ����������������������","�����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&chuguo);
				zimu2("����������ʶ�ˣ�һЩͬ����ѧ��С��㣬��Ӧ������ȥ�ദһ��","�����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				
			}
			else
			{
				putimage(0,0,&yingyulaoshi);
				zimu2("ƾ�����Լ�biu ׼���ļ���������ӦƸ�˸���Ӣ���ʦ�����ǻ������е�����ѽ","�����");
				
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
				putimage(0,0,&yingyulaoshi);
				zimu2("Ȼ�����������ڴ�����Ů���ѣ�Ҳ���ȥ����������","�����");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
				getch();
			}
			
		}
		else
		{
			putimage(0,0,&kexuejia);
			zimu2("���Ҳ����������Ҿ�����ȥ���죬���������Ŭ�����ҽ����п�Ժ�о�������Ҳͦ�Ȱ����ڵĹ�����","�����");
            FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			zimu2("Ȼ�����һ��ǵÿ���һ���ҵ�������£������������еģ�ֻ��ȥ������","�����");
			
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
			getch();
			
			
			
		}
		
		
		
	}
	
	
	
	
	
	cleardevice();
	xiangqin();
	
	
}
void tuixuele()
{
	IMAGE tuixue1;
	loadimage(&tuixue1,_T("ͼƬ\\��ѧ.jpg"),690,532,true);
	putimage(0,0,&tuixue1);
	zimu2("�ҳɼ����ߣ����˺ܶ�ƣ�����ʦ�ͼҳ���˫��ѹ���£������Ագ�����Ҿ����뿪ѧУ����������һ�ֽ��Ѱ�","�����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	putimage(0,0,&tuixue1);
	
	while(true)
	{
		
		
		
	}
	
	
}













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
			x=x-20;
		}
		else if(b[0]==' '||b[1]==' ')
		{
			x=x-10;
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
	loadimage(&xiao2,_T("ͼƬ\\С���2.jpg"),100,330,true);
	loadimage(&xiao3,_T("ͼƬ\\С���3.jpg"),100,330,true);
	loadimage(&xiao4,_T("ͼƬ\\С���4.jpg"),100,330,true);
	loadimage(&xiao5,_T("ͼƬ\\С���5.jpg"),100,330,true);
	loadimage(&xiao6,_T("ͼƬ\\С���6.jpg"),100,330,true);
	a[0].xiaojiejietu=xiao1;
	a[0].xiaojiejieming="���ӱ";
	a[0].xiaojiejiejieshao="���С����ڴ�ѧʱ�ھ���ѧ����᳤����������ǿ�������е���䣬ֻ��SRTP���߲��гɹ��Ŀ�����";
	if(A.srtp>=80 &&A.tui<=70)
	{
		a[0].success_=1;
	}
	else a[0].success_=0;
	
	
	a[1].xiaojiejietu=xiao2;
	a[1].xiaojiejieming="����ŵ";
	a[1].xiaojiejiejieshao="���С�����һ����ʿ�������ȣ�ʮ�ֿɰ���ϲ��cos �Ͷ���Ԫ����լֵ�㹻�ߵĻ��ɹ��ʸߵ�";
	if(A.zhai>=60 &&A.qing>=30)
	{
		a[1].success_=1;
		
	}
	else a[1].success_=0;
	
	a[2].xiaojiejietu=xiao3;
	a[2].xiaojiejieming="����ĭ";
	a[2].xiaojiejiejieshao="����һ���ǳ�����Ů�ĵ�С��㣬���������˧�����ָߵģ�����Ī��";
	if(A.qing>=60)
	{
		a[2].success_=1;
	}
	else a[2].success_=0;
	
	a[3].xiaojiejietu=xiao4;
	a[3].xiaojiejieming="������";
	a[3].xiaojiejiejieshao="����һ��������ǿ��С��㣬�ڴ������ææµµ��ϲ����ҵ��ǿ������";
	if(A.money>10000)
	{
		a[3].success_=1;
	}
	else a[3].success_=0;
	
	a[4].xiaojiejietu=xiao5;
	a[4].xiaojiejieming="������";
	a[4].xiaojiejiejieshao="����һ�����ŷ��С��㣬�е���䣬Ҳ������Ҫ���̸�һ��ſ���ȥ����";
	if(A.qing>=70)
	{
		a[4].success_=1;
	}
	else a[4].success_=0;
	
	a[5].xiaojiejietu=xiao6;
	a[5].xiaojiejieming="��Ψ��";
	a[5].xiaojiejiejieshao="����һ��ʮ�ֿɰ���С������ֻҪ�໨����˼�Ϳ����������ܵ���Ĺ���";
	if(A.qing>20)
	{
		a[5].success_=1;
	}
	else a[5].success_=0;
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
			success=a[b[0]].success_;
			break;
		}
		if(c=='2')
		{
			success=a[b[1]].success_;
			break;
		}
		if(c=='3')
		{
			success=a[b[1]].success_;
			break;
		}
		
		
	}
	setbkcolor(BLACK);
	cleardevice();
	tanlianaixuanhuan();
	
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
	
	IMAGE tan6,tan7;
	loadimage(&tan6,_T("ͼƬ\\̸����6.jpg"),450,350,true);	
	loadimage(&tan7,_T("ͼƬ\\̸����7.jpg"),450,350,true);	
	int n=0;
	while(n<=300)
	{
		n++;
		tanlianai(n);
		Sleep(10);
	}
	if(success==1)
	{
		cleardevice();
		putimage(100,100,&tan6);
		
	}
	else if(success==0)
	{
		cleardevice();
		putimage(100,100,&tan7);
		
	}
	while(true)
	{
	}
}





void beijing()
{
	
	IMAGE gushi2,gushi3,gushi1;
	suiji=randrange(4);	
	IMAGE background1,jiyou,person2,person_2,kaixue;
	loadimage(&kaixue,_T("ͼƬ\\��ѧ.jpg"),690,532,true);
	loadimage(&background1,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	loadimage(&jiyou,_T("ͼƬ\\����.jpg"),180,180,true);
	loadimage(&gushi2,_T("ͼƬ\\��������2.jpg"),690,532,true);
	loadimage(&gushi3,_T("ͼƬ\\��������3.jpg"),690,532,true);
	loadimage(&gushi1,_T("ͼƬ\\��������1.jpg"),690,532,true);
	putimage(0,0,&gushi2);
	getch();
    char name[20];
	InputBox(name, 10, "�Ǹ�С�к���������ͽ�","�ְְ���");
	putimage(0,0,&gushi3);
	A.getname (name);
	char s1[]="�߿�����";
	char ss1[]="һ�ж�����ôƽ��";
	char sss1[]="�ҵ�Ȼ���뿪�Ǹ������������У԰";
	char ssss1[]="��֪��δ����·������";
	settextstyle(30, 0, _T("����"));    
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(200,125,s1);
    Sleep(1000);
	outtextxy(50,80,ss1);
    Sleep(1000);
	outtextxy(150,200,sss1);
    Sleep(1000);
	outtextxy(100,250,ssss1);
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	settextstyle(20, 0, _T("����")); 
	setbkcolor(WHITE);
	cleardevice();
	settextcolor(BLACK);
	outtextxy(300,280,name);
	putimage(0,0,&gushi1,SRCAND);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
	getch();
	cleardevice();
	mciSendString(TEXT("open bgm\\��������.mp3 alias mysong"),NULL,0,NULL);
	mciSendString(TEXT("play mysong repeat"),NULL,0,NULL);
	putimage(0,0,&kaixue);
	Sleep(3000);
	
	
	char a[]={"�����ϴ�ѧ�ˣ����ڽ���ˣ���˵���ѧУ�����ӻ�ͦ��"};
	char b[]={"�������ˣ����Ҳ������ӵģ���ֻ�������ѣ����Ǻúö����"};
	char c[]={"��ʵ�ɣ����Ӿ��ǿ�������������氮"};
	char d[]={"˵���е����Ͻ���ʼ��Ĵ�ѧ�����"};
	putimage(0,0,&background1);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
	zimu(a,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
	getch();
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu(b,"����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
	getch();
	putimage(0,0,&background1);
	putimage(20,170,&person_2,SRCPAINT);
	putimage(20,170,&person2,SRCAND);
	zimu(c,A.returnname());
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
	getch();
	putimage(0,0,&background1);
	rputimage(20,170,&jiyou);
	zimu(d,"����");
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
	getch();
	
	jiemian();
	
	
}
void jiemian()
{
	if(A.tui==100)
	{
		cleardevice();
		mciSendString(TEXT("close mysong "),NULL,0,NULL);
		mciSendString(TEXT("open bgm\\��̭����.mp3 alias tmysong"),NULL,0,NULL);
		mciSendString(TEXT("play tmysong repeat"),NULL,0,NULL);
		
		
		
		tuixuele();
		
	}
	setbkcolor(BLACK);
	setbkmode(OPAQUE);
	cleardevice();
	IMAGE background1,person1,person_1,kaichong,shangdian,dudu;
	loadimage(&background1,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	loadimage(&person1,_T("ͼƬ\\��è��1.jpg"),0,0,true);	
    loadimage(&person_1,_T("ͼƬ\\��è��1����ͼ.jpg"),0,0,true);
	loadimage(&kaichong,_T("ͼƬ\\����.jpg"),180,60,true);
	loadimage(&shangdian,_T("ͼƬ\\�̵�.jpg"),120,45,true);
	loadimage(&dudu,_T("ͼƬ\\����.jpg"),120,45,true);
	setcolor(BLACK);
	putimage(0,0,&background1);
	putimage(0,0,&person_1,SRCPAINT);
	putimage(0,0,&person1,SRCAND);
    setbkmode(TRANSPARENT);
	putimage(0,450,&kaichong);
	putimage(550,470,&shangdian);
	putimage(550,410,&dudu);
    setfillcolor(RGB(227,168,105));
	fillrectangle(270,400,500,530);
	setfillcolor(WHITE);
	fillrectangle(300,515,400,525);
	setfillcolor(RGB(255,0,255));
	solidrectangle(300,515,A.qing+300,525);
	settextstyle(15, 10, _T("����"));
	settextcolor(WHITE);
	outtextxy(420,515,"����");
    setfillcolor(WHITE);
	fillrectangle(300,500,400,510);
	setfillcolor(RGB(160,32,240));
	solidrectangle(300,500,A.zhai+300,510);    
	outtextxy(420,500,"��լֵ");
    setfillcolor(WHITE);
	fillrectangle(300,485,400,495);
	setfillcolor(RED);
	solidrectangle(300,485,A.tui+300,495);    
	outtextxy(420,485,"��ѧ��");
	setfillcolor(WHITE);
	fillrectangle(300,470,400,480);
	setfillcolor(GREEN);
	solidrectangle(300,470,A.ya+300,480);    
	outtextxy(420,470,"ѹ��ֵ");
	setfillcolor(WHITE);
	fillrectangle(300,455,400,465);
	setfillcolor(BLUE);
	solidrectangle(300,455,A.srtp+300,465);
	outtextxy(420,455,"SRTP");
	char money_[20],huihe_[20];
	sprintf(money_,"%d",A.money);
	sprintf(huihe_,"%d",h);
	outtextxy(420,410,"�����");
	outtextxy(425,430,money_);
	setfillcolor(RGB(227,168,105));
	fillrectangle(10,410,140,440);
    setbkmode(TRANSPARENT);
	settextstyle(30,15, _T("����"));
	settextcolor(BLACK);
	outtextxy(300,410,A.returnname()); 
	settextstyle(15, 10, _T("����"));
	outtextxy(20,420,"��ʣ  �غ�");
	outtextxy(60,420,huihe_);
	setbkmode(OPAQUE);
	
	char c2=0;
	while (true)
	{
		c2=getch();
		if (c2=='W'||c2=='w')
		{
			B.anpaimian();
		}
		else if(c2=='l'||c2=='L')
		{
			
			B.shengji();
			
		}
		else if(c2=='s'||c2=='S')
		{
			myshangdian();
			
		}	
	}
	
	
	
	
	
}
void jineng::anpaimian()
{
    cleardevice();
	IMAGE person2,person_2,background2;
	loadimage(&background2,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	putimage(0,0,&background2);
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
	setbkmode(TRANSPARENT);
	settextcolor(RGB(102,51,0));
	outtextxy(260,90,B.returngaoshu());
	outtextxy(260,130,B.returncyuyan());
	outtextxy(260,170,B.returnyingyu());
	outtextxy(260,210,"Bվ  ��");
	outtextxy(260,250,"�罻  ��");
	outtextxy(260,290,"��  ��");
	char c2=0;
	while(true)
	{
		setbkcolor(WHITE);
		c2=getch();
		if(c2==27)
		{
			break;
			
		}
		
		else if(c2=='1'&&B.gaoshudengji==1)
		{
			if(A.ya>=70)
			{
				zimu1("�Բ�������ѹ��ֵ̫���ˣ����ʺϼ�������ѧϰ����ȥ����ѹ");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
				getch();
				break;
				
				
			}
			cleardevice();
			gaoshud((h+suiji)%4);
			B.gaoshushu++;
			h--;
			tufashijian();
			
			break;
			
		}
		else if(c2=='1'&&B.gaoshudengji==2)
		{
			
			if(A.ya>=70)
			{
				zimu1("�Բ�������ѹ��ֵ̫���ˣ����ʺϼ�������ѧϰ����ȥ����ѹ");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
				getch();
				break;
				
				
			}
			cleardevice();
			gaoshub((h+suiji)%4);
			B.gaoshushu++;
			h--;
			tufashijian();
			break;
		}
		else if(c2=='1'&&B.gaoshudengji==3)
		{
			
			if(A.ya>=70)
			{
				zimu1("�Բ�������ѹ��ֵ̫���ˣ����ʺϼ�������ѧϰ����ȥ����ѹ");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
				getch();
				break;
				
				
			}
			cleardevice();
			gaoshua((h+suiji)%4);
			B.gaoshushu++;
			h--;
			tufashijian();
			
			break;
		}
		else if(c2=='2'&&B.cyuyandengji==1)
		{
			if(A.ya>=70)
			{
				zimu1("�Բ�������ѹ��ֵ̫���ˣ����ʺϼ�������ѧϰ����ȥ����ѹ");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
				getch();
				break;
				
				
			}
			cleardevice();
			fcyuyan((h+suiji)%4);
			B.cyuyanshu++;
			h--;
			tufashijian();
			
			break;
			
		}
		else if(c2=='2'&&B.cyuyandengji==2)
		{
			if(A.ya>=70)
			{
				zimu1("�Բ�������ѹ��ֵ̫���ˣ����ʺϼ�������ѧϰ����ȥ����ѹ");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
				getch();
				break;
				
				
			}
			cleardevice();
			dcyuyan((h+suiji)%4);
			B.cyuyanshu++;
			h--;
			tufashijian();
			
			break;
			
		}
		else if(c2=='3'&&B.yingyudengji==1)
		{
			if(A.ya>=70)
			{
				zimu1("�Բ�������ѹ��ֵ̫���ˣ����ʺϼ�������ѧϰ����ȥ����ѹ");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
				getch();
				break;
				
				
			}
			cleardevice();
			yingyu2((h+suiji)%4);
			B.yingyushu++;
			h--;
			tufashijian();
			
			break;
			
		}
		else if(c2=='3'&&B.yingyudengji==2)
		{
			if(A.ya>=70)
			{
				zimu1("�Բ�������ѹ��ֵ̫���ˣ����ʺϼ�������ѧϰ����ȥ����ѹ");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
				getch();
				break;
				
				
			}
			cleardevice();
			yingyu3((h+suiji)%3);
			B.yingyushu++;
			h--;
			tufashijian();
			
			break;
			
		}
		else if(c2=='3'&&B.yingyudengji==3)
		{
			if(A.ya>=70)
			{
				zimu1("�Բ�������ѹ��ֵ̫���ˣ����ʺϼ�������ѧϰ����ȥ����ѹ");
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
				getch();
				break;
				
				
			}
			cleardevice();
			yingyu4((h+suiji)%3);
			B.yingyushu++;
			h--;
			tufashijian();
			
			break;
			
		}
		
		
		else if(c2=='4')
		{
			cleardevice();
			bilibili();
			h--;
			tufashijian();
			break;
		}
		else if(c2=='5' &&A.zhai<70)
		{
			cleardevice();
			shejiao();
			h--;
			tufashijian();
			break;
		}
		else if(c2=='5'&&A.zhai>=70)
		{
			zimu1("��լֵ̫���ˣ���������ᣬ�޷��罻");
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
			getch();
			break;
			
			
		}
		else if(c2=='6')
		{
			cleardevice();
			dagong((h+suiji)%4);
			h--;
			tufashijian();
			break;
			
			
		}
		
	}
	
	
	
	cleardevice();
	
	
	
	jiemian();
    
	
}
void jineng::shengji()
{
	cleardevice();
	IMAGE person2,person_2,background2;
	loadimage(&background2,_T("ͼƬ\\��լ����.jpg"),0,0,true);
	loadimage(&person2,_T("ͼƬ\\��è��2.jpg"),180,180,true);
    loadimage(&person_2,_T("ͼƬ\\��è��2����ͼ.jpg"),180,180,true);
	
	putimage(0,0,&background2);
	putimage(20,350,&person_2,SRCPAINT);
	putimage(20,350,&person2,SRCAND);
	setcolor(RGB(238,197,145));
	setfillcolor(RGB(238,197,145));
	fillrectangle(250,10,650,520);
	char shengji[20]="����͵��";
	setbkcolor(RGB(238,194,145));
	settextstyle(30, 15, _T("����"));    
	settextcolor(BLACK);
	outtextxy(350,20,shengji);
	char *gaodengshuxue[3]={"�ߵ���ѧD  ��","�ߵ���ѧB  ��","�ߵ���ѧA  ��"};
	char *ccyuyan[2]={"C++�ǵ���  ��","C++����  ��"};
	char *daxueyingyu[3]={"Ӣ�����  ��","Ӣ������  ��","Ӣ���ļ�  ��"};
	if(B.gaoshudengji<3)
	{
		outtextxy(300,50,gaodengshuxue[B.gaoshudengji]);
	}
	if(B.cyuyandengji<2)
	{
		outtextxy(300,90,ccyuyan[B.cyuyandengji]);
	}
	if(B.yingyudengji<3)
	{
		outtextxy(300,130,daxueyingyu[B.yingyudengji]);
	}
	char c3=0;
	while(true)
	{
		c3=getch();
		if(c3==27)
		{
			break;
		}
		else if(c3=='1'&&B.gaoshudengji<3)
		{
			char a[]={"�����ü�����Ҫ����200 Ԫ���Ƿ����������Y �ǣ���N ��"};
			char b[]={"�����ɹ���SRTP+7����ȥ���Ű�"};
			char c[]={"��Ҳ��㣬��ȥ׬Ǯ��"};
			char d=0;
			zimu1(a);
			
			while(true)
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
				d=getch();
				if(d=='y'||d=='Y'||d=='n'||d=='N')
				{
					break;
				}
			}
			if(d=='y'||d=='Y')
			{
				if(A.money>=200)
				{
					B.getgaoshu(gaodengshuxue[B.gaoshudengji]);
					B.gaoshudengji++;
					A.srtp+=7;
					A.money-=200;
					if(A.srtp>100)
					{
						A.srtp=100;
					}
					zimu1(b);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
					getch();
					break;
					
				}
				else 
				{
					zimu1(c);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
					getch();
					break;
					
				}
			}
			else 
			{
				B.shengji();
			}
		}
		else if(c3=='2'&&B.cyuyandengji<2)
		{
			char a[]={"�����ü�����Ҫ����200 Ԫ���Ƿ����������Y �ǣ���N ��"};
			char b[]={"�����ɹ���SRTP+7����ȥ���Ű�"};
			char c[]={"��Ҳ��㣬��ȥ׬Ǯ��"};
			char d=0;
			zimu1(a);
			
			while(true)
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
				d=getch();
				if(d=='y'||d=='Y'||d=='n'||d=='N')
				{
					break;
				}
			}
			if(d=='y'||d=='Y')
			{
				if(A.money>=200)
				{
					B.getcyuyan(ccyuyan[B.cyuyandengji]);
					B.cyuyandengji++;
					A.srtp+=7;
					A.money-=200;
					if(A.srtp>100)
					{
						A.srtp=100;
					}
					zimu1(b);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
					getch();
					break;
					
				}
				else 
				{
					zimu1(c);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
					getch();
					break;
					
				}
			}
			else 
			{
				B.shengji();
			}
			
			
		}
		else if(c3=='3'&&B.yingyudengji<3)
		{
			char a[]={"�����ü�����Ҫ����200 Ԫ���Ƿ����������Y �ǣ���N ��"};
			char b[]={"�����ɹ���SRTP+7����ȥ���Ű�"};
			char c[]={"��Ҳ��㣬��ȥ׬Ǯ��"};
			char d=0;
			zimu1(a);
			
			while(true)
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
				d=getch();
				if(d=='y'||d=='Y'||d=='n'||d=='N')
				{
					break;
				}
			}
			if(d=='y'||d=='Y')
			{
				if(A.money>=200)
				{
					B.getyingyu(daxueyingyu[B.yingyudengji]);
					B.yingyudengji++;
					A.srtp+=7;
					A.money-=200;
					if(A.srtp>100)
					{
						A.srtp=100;
					}
					zimu1(b);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
					getch();
					break;
					
				}
				else 
				{
					zimu1(c);
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
					getch();
					break;
					
				}
			}
			else 
			{
				B.shengji();
			}
			
			
		}
	}
	cleardevice();
	jiemian();
	
}
void tufashijian()
{
	C.shangdianchushihua();
	
	if(h==15)
	{
		cleardevice();
		qizhongkao();
	}
	if(h==20)
	{
		cleardevice();
		hongbaolai();
	}
	if(h==10)
	{
		cleardevice();
		wanyouxi();
		
		
	}
	if(h==5)
	{
		cleardevice();
		qimokao();
	}
	if(h%3==0)
	{
		cleardevice();
		paocao();
	}
	if(h==22)
	{
		cleardevice();
		jiangzuo();
	}
	if(h==13)
	{
		cleardevice();
		jiangzuo();
	}
	if(chuqianguan!=0)
	{
		A.money=(int)(A.money*(1+0.05*chuqianguan));
		int i=(int)(0.05*A.money*chuqianguan);
		char a[20]={0};
		sprintf(a,"%d",i);
		char b[]={"ӵ�д�Ǯ�ޣ������+ "};
		strcat(b,a);
		IMAGE background1;
		loadimage(&background1,_T("ͼƬ\\��լ����.jpg"),0,0,true);
		putimage(0,0,&background1);
		
		zimu1(b);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
		getch();
		
	}
	if(h==-1)
	{
		setbkcolor(WHITE);
		cleardevice();
		IMAGE kaixue;
		loadimage(&kaixue,_T("ͼƬ\\��ѧ.jpg"),690,532,true);
		
		mciSendString(TEXT("close mysong "),NULL,0,NULL);
		mciSendString(TEXT("open bgm\\��β����.mp3 alias jieweimusic"),NULL,0,NULL);
		mciSendString(TEXT("play jieweimusic repeat"),NULL,0,NULL);
		
		
		putimage(0,0,&kaixue);
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   //��ռ���������
		getch();
		
		jiewei();
		
	}
	cleardevice();
}



void main()
{
	initgraph(690,532);
	beijing();    
}








