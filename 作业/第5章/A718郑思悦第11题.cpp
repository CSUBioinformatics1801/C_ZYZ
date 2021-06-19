#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.1415926535
double getgfromlatitude(){
	char deg[] = { 0xa1,0xe3,0 };//This is "��"��str end as \0
	printf_s("Input current latitude(for example \"30%s04'25.93\"):", deg);
	int getlat; int getd; double getdd;
	scanf_s("%d��%d'%lf''", &getlat, &getd, &getdd);
	double latitude = getlat + getd / 60.0 + getdd / 60.0;
	return 9.7803* (1 + 0.0053024 * pow(sin(latitude * PI / 180), 2) - 0.000005 * pow(sin(latitude / 180 * PI), 2));
}
void cartoon() {
	getchar();
	initgraph(1000, 800);
	for (int q = 0; q < 200; q++) {
		cleardevice(); solidcircle(200, 100 + 3 * q, 50); Sleep(50);}
	for (int n = 1; n < 19; n++) {
		for (int m = 0; m < 200 / pow(2, int((n + 1) / 2)); m++) {
			cleardevice();
			if (n % 2) {
				solidcircle(200 + 40 * n, 700 - 3 * m, 50);
				Sleep(50);}
			else {
				solidcircle(200 + 40 * n, 700 - 600 / pow(2, int((n + 1) / 2)) + 3 * m, 50);
				Sleep(50);}}}
	Sleep(6000); closegraph();
}
int main()
{
	printf("��һ��С���100m�����䣬ÿ�η�����ԭ���ĸ߶ȵ�һ��,������10��\n�����һ���˶����̣���ۿ�\n");
	cartoon();
    again:
	printf("���˶������밴1\n��߶��밴2\n��ʱ���밴3\n");
	int calcu; scanf_s("%d", &calcu); int s = 100;
	double t, tlati;
	switch (calcu) {
	case 1:
		printf("��������Ҫ����Ĵ���\n");
		int n1; scanf_s("%d", &n1);
        for (int m1 = 0; m1 < n1; m1++) {
			s = 2 * (100 / pow(2, m1)) + s;
			if (m1 == n1 - 1)
				printf("��%d���½�����ʱ��С�����߹��ľ���Ϊ%d", n1, s);}
		break;
	case 2:
		printf("�����������Ĵ���\n");
		int n2; scanf_s("%d", &n2);
		printf("С���%d�η�����ﵽ����߸߶�Ϊ%lf��\n", n2, 100 / pow(2, n2));
		break;
	case 3:
		printf("�����������Ĵ���\n");
		int n3; scanf_s("%d", &n3); 
		tlati = getgfromlatitude();
		t = sqrt(2 * 100 / tlati);
		for (int m3 = 1; m3 < n3; m3++) {
			t = t + sqrt(4 * 100 / pow(2, m3) / tlati);}
		printf("��%d�δ���ʱ����ʱ��Ϊ%lf��\n", n3, t);
		break;
	default:
		printf("������ˣ����������һ�εĻ��밴0\n");
		int def; scanf_s("%d", &def);
		if (def)printf("���ź�û�ܰﵽ��\n");
		else goto again;}
		Sleep(10000);
		return 0;
}


