#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<windows.h>
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


void main()
{
	
	IMAGE a,b;
	loadimage(&a,_T("ͼƬ//����.jpg"),150,200,true);
	loadimage(&b,_T("ͼƬ//����ͼ3.jpg"),690,532,true);
	initgraph(690,532);
	putimage(0,0,&b);
	myputimage(0,300,&a,0.5);
	getch();
}
