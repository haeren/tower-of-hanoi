#include <stdio.h>
#include <conio.h>
int i, aGuncel = -1, bGuncel = -1, cGuncel = -1, hamleNo = 0;
int yiginA[10], yiginB[10], yiginC[10];

void diskiTasi(int n, char baslangic, char yedek, char hedef);
void yiginiHazirla(int n);
void yiginaEkle(char yigin, int eklenecek);
int yigindanCikar(char yigin);
void yiginlariGoster();

int main() {
	int n;
	while (1 == 1) {
		printf("3-10 arasinda disk sayisi girin veya cikmak icin '0' girin: ");
		scanf_s("%d", &n);
		if (n>2 && n<11) {
			yiginiHazirla(n);
			printf("--------------------Baslangic gorunumu--------------------\n");
			yiginlariGoster();
			diskiTasi(n, 'A', 'B', 'C');
			printf("\n");
		}
		else if (n == 0) {
			return 0;
		}
		else {
			printf("Hatali deger girdiniz...\n");
		}
	}
}

void yiginiHazirla(int n) {
	aGuncel = -1;
	bGuncel = -1;
	cGuncel = -1;
	hamleNo = 0;
	for (i = n; i >= 1; i--) {
		yiginA[n - i] = i;
		aGuncel++;
	}
}

void yiginlariGoster() {
	printf("A cubugu -> ");
	printf("[  ");
	for (i = 0; i <= aGuncel; i++) {
		printf("%d, ", yiginA[i]);
	}
	printf("\b\b  ]");

	printf("\nB cubugu -> ");
	printf("[  ");
	for (i = 0; i <= bGuncel; i++) {
		printf("%d, ", yiginB[i]);
	}
	printf("\b\b  ]");

	printf("\nC cubugu -> ");
	printf("[  ");
	for (i = 0; i <= cGuncel; i++) {
		printf("%d, ", yiginC[i]);
	}
	printf("\b\b  ]");

	printf("\n_________________________________________________________\n");
}

void yiginaEkle(char yigin, int eklenecek) {
	switch (yigin)
	{
	case 'A':
		aGuncel++;
		yiginA[aGuncel] = eklenecek;
		break;

	case 'B':
		bGuncel++;
		yiginB[bGuncel] = eklenecek;
		break;

	case 'C':
		cGuncel++;
		yiginC[cGuncel] = eklenecek;
		break;
	}
}

int yigindanCikar(char yigin) {
	if (yigin == 'A')
	{
		aGuncel--;
		return yiginA[aGuncel + 1];
	}

	else if (yigin == 'B')
	{
		bGuncel--;
		return yiginB[bGuncel + 1];
	}

	else
	{
		cGuncel--;
		return yiginC[cGuncel + 1];
	}
}

void diskiTasi(int n, char baslangic, char yedek, char hedef) {
	if (n == 1) {
		printf("%d. disk %c cubugundan %c cubuguna tasiniyor ->Hamle No = %d\n", n, baslangic, hedef, ++hamleNo);
		yiginaEkle(hedef, yigindanCikar(baslangic));
		yiginlariGoster();
	}
	else {
		diskiTasi(n - 1, baslangic, hedef, yedek);
		printf("%d. disk %c cubugundan %c cubuguna tasiniyor ->Hamle No = %d\n", n, baslangic, hedef, ++hamleNo);
		yiginaEkle(hedef, yigindanCikar(baslangic));
		yiginlariGoster();
		diskiTasi(n - 1, yedek, baslangic, hedef);
	}
}