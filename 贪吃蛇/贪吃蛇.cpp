#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
int m[50][2]={{100,100},{110,100},{120,100},{130,100}};//��������
int n=4;
int w=0,d=0,a=1,s=0;
int p=300,q=300;

void dian(int ,int);
void dian_(int ,int);
int fenshu=0;
char fenshu_[20];

void shiwu()//�������ʳ��
{ds
	setbkmode(TRANSPARENT);//���ñ���ģʽΪ͸��
	dian(p,q);
	sprintf(fenshu_,"%d",fenshu);//��ӡ����
	outtextxy(0,0,fenshu_);//ȷ��������ʾ�ĵط�   ��ʱ��ĳ�ʱ��
	srand(unsigned (time(NULL)));//�������ʳ���
	if((m[0][0]-p)*(m[0][0]-p)+(m[0][1]-q)*(m[0][1]-q)<100)
	{
		fenshu+=10;
		int b[2];
		n++;
		dian_(p,q);
		for(int i=0;i<2;i++)
		{
			b[i]=10*(rand()%39+1);
		}
		p=b[0];
		q=b[1];
	}
}

		

void dian(int x,int y)//��ָ���ĵط�����һ��������
{
	setcolor(GREEN);//������ɫɫ
	setfillcolor(GREEN);//�������ɫ
	fillrectangle(x-5,y-5,x+5,y+5);//��һ������  �ĸ�����
}
void dian_(int x,int y)
{
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillrectangle(x-5,y-5,x+5,y+5);
}
void kongzhi()
{
	char c;
	if(kbhit())//���񰴼�
	{

		c=getch();
		
		if((c=='w'||c=='W') && s==0)
		{
			w=1;
			d=0;
			s=0;
			a=0;
		}
		 if((c=='s'||c=='S')&& w==0)
		{
			w=0;
			d=0;
			s=1;
			a=0;
		}
		if((c=='A'||c=='a') && d==0)
		{
			w=0;
			d=0;
			s=0;
			a=1;
		}
		 if((c=='D'||c=='d') && a==0)
		{
			w=0;
			d=1;
			s=0;
			a=0;
		}
	}
	
}
void xuanhuan()
{
	IMAGE A;
	loadimage(&A,_T("����.jpg"),400,400,true);

	int g=1,sudu=100;
	while (m[0][1]<=395 &&m[0][1]>=5 &&m[0][0]<=395 &&m[0][0]>=5 && g)//�ж�ײ��û��
	{
		if(n>=40)
		{
			n=4;
			sudu=sudu-20;
		}
			for(int i=0;i<n;i++)
		{
			m[n-i][0]=m[n-i-1][0];
			m[n-i][1]=m[n-i-1][1];
			
		}


	
		kongzhi();

		
		
		if(w==1)
		{
			m[0][1]=m[0][1]-10;
		}
		if(s==1)
		{
			m[0][1]=m[0][1]+10;
		}
		if(a==1)
		{
			m[0][0]=m[0][0]-10;
		}
		if(d==1)
		{
			m[0][0]=m[0][0]+10;
		}
	
			for(int o=1;o<n;o++)
			{
			
			int t;
			 t=(m[0][0]-m[o][0])*(m[0][0]-m[o][0])+(m[0][1]-m[o][1])*(m[0][1]-m[o][1]);
			 if(t<100)
			{
				 g=0;
				 break;
	

			
			}
			}

		
	   
        BeginBatchDraw();
		putimage(0,0,&A);
		shiwu();
		
		
		for(int k=0;k<n;k++)
		{
			dian(m[k][0],m[k][1]);
		}
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); //���л���  ��ʱˢ��
		Sleep(sudu);
		FlushBatchDraw();
	
		cleardevice();



	}
	
}
void main()
{

	initgraph(400,400);
	xuanhuan();


}
