#include<stdio.h>

#define pole 1000




void nacitaj(char* load, FILE* fr, int* dlzka) {
	*dlzka = 0;
	int d;

	if (fr == NULL) {
		printf("Spravu sa nepodarilo nacitat.\n");
	}

	else {

		while ((d = getc(fr)) != EOF && *dlzka < 1000) {
			*load = d;
			load++;
			(*dlzka)++;
		}

		if (*dlzka == 0) {
			printf("Spravu sa nepodarilo nacitat.\n");
		}
		else {
			rewind(fr);
		}

	}
}

void vypis(char* vypisat, int dlzka) {

	if (dlzka == 0) {
		printf("Sprava nieje nacitana.\n");

	}


	else {
		for (int a = 0; a < dlzka; a++) {
			printf("%c", vypisat[a]);

		}
		printf("\n");
	}




}

void uprav(char* load, char* change, int dlzka, int* u_dlzka) {


	if (dlzka == 0) {
		printf("Sprava nieje nacitana.\n");
	}

	else {
		*u_dlzka = 0;
		for (int a = 0; a < dlzka; a++) {
			if (load[a] >= 'a' && load[a] <= 'z') {
				change[*u_dlzka] = load[a] - 32;
				(*u_dlzka)++;
			}

			else if (load[a] >= 'A' && load[a] <= 'Z') {
				change[*u_dlzka] = load[a];
				(*u_dlzka)++;
			}
		}




	}
}

void vypis_uprav(char change[], int u_dlzka) {
	if (u_dlzka == 0) {
		printf("Upravena sprava nieje nacitana.\n");
	}
	else {
		for (int a = 0; a < u_dlzka; a++) {
			printf("%c", change[a]);
		}
		printf("\n");
	}

}

void dlzka_slova(char load[], int dlzka) {

	char znaky[pole];
	int pomoc = 0;
	int k;



	if (dlzka == 0) {
		printf("Sprava nieje nacitana.\n");
	}

	else {
		scanf("%d", &k);
		getchar();

		for (int b = 0; b < dlzka; b++) {



			if (load[b] != '\n' && load[b] != ' ') {
				znaky[pomoc] = load[b];
				pomoc++;
			}


			if (((pomoc) == k) && (load[b] == '\n' || load[b] == ' ')) {

				for (int a = 0; a < pomoc; a++) {
					printf("%c", znaky[a]);
				}
				printf("\n");
				for (int a = 0; a < pomoc; a++) {
					znaky[a] = 0;
				}
				pomoc = 0;

			}



			if (pomoc != k && (load[b] == '\n' || load[b] == ' ')) {
				for (int a = 0; a < pomoc; a++) {
					znaky[a] = 0;
				}

				pomoc = 0;
			}


		}

		if (pomoc == k) {
			for (int a = 0; a < pomoc; a++) {
				printf("%c", znaky[a]);
			}
			printf("\n");
		}

	}

}

void histogram(char change[], int u_dlzka) {

	char znaky[26];
	float pomoc = 0;
	if (u_dlzka == 0) {
		printf("Nieje k dispozicii upravena sprava.\n");
	}
	else {
		for (int a = 0; a < 26; a++) {
			znaky[a] = 0;
		}

		for (int b = 0; b < u_dlzka; b++) {
			pomoc++;
			if (change[b] >= 'A' && change[b] <= 'Z') {
				znaky[change[b] - 'A']++;
			}
			else {
				znaky[b] = 0;
			}


		}



		int pomoc2 = 0;
		for (float b = 0; b < 100; b = b + 10) {
			for (int a = 0; a < 26; a++) {
				if (znaky[a] != 0) {
					if (((znaky[a]) > ((pomoc / 100) * b))) {
						printf("*");
						pomoc2++;
					}
				}
					
			

				if (znaky[a] == 0|| (znaky[a]) < ((pomoc / 100) * b)|| (znaky[a]) == ((pomoc / 100) * b))   {
					printf(" ");

				}
			}
			if (pomoc2 != 0) {
				printf("\n");
				pomoc2 = 0;
			}
		}
		printf("\n");
		for (int a = 0; a < 26; a++) {
			printf("%c", 'A' + a);
		}
		printf("\n");
	}
}

void cezarova_sifra(char* change, int u_dlzka) {



	if (u_dlzka > 0) {
		int n;
		scanf("%d", &n);
		getchar();

		if (n >= 1 && n <= 25) {
			for (int a = 0; a < u_dlzka; a++) {
				if ((change[a] - n) < 65) {
					change[a] = change[a] + 26 - n;
					printf("%c", change[a]);
				}
				else {
					change[a] = change[a] - n;
					printf("%c", change[a]);
				}

			}
			printf("\n");

		}

	}

	else {
		printf("Nieje k dispozicii upravena sprava.\n");
	}

}




int main() {


	char znak = 0;
	char load[pole];
	char change[pole];
	FILE* fr;
	fr = fopen("sifra.txt", "r");
	int dlzka = 0;
	int u_dlzka = 0;

	while (znak != 'k') {
		scanf("%c", &znak);
		getchar();


		switch (znak) {

		case 'n':
			nacitaj(load, fr, &dlzka);
			break;

		case 'v':
			vypis(load, dlzka);
			break;

		case 'u':
			uprav(load, change, dlzka, &u_dlzka);
			break;

		case 's':
			vypis_uprav(change, u_dlzka);
			break;

		case 'd':
			dlzka_slova(load, dlzka);
			break;

		case 'h':
			histogram(change, u_dlzka);
			break;

		case 'c':
			cezarova_sifra(change, u_dlzka);
			break;
		}

	}
	if (znak == 'k') {
		if (fclose(fr) == EOF) {
			printf("Subor nebol spravne zatvoreny.\n");
		}
	}
	return 0;

}