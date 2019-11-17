#include<stdio.h>

#define pole 1000








int main() {

	char znak = 0;
	int dlzka = 0;

	char load[pole];
	char change[pole];

	FILE* fr;
	FILE* fr2;

	fr = fopen("sifra.txt", "r");
	fr2 = fopen("sifra.txt", "r");






	while (znak != 'k') {
		scanf("%c", &znak);
		getchar();



		if (znak == 'n') {
			dlzka = 0;
			int d;

			while ((d = getc(fr)) != EOF && dlzka < 1000) {
				load[dlzka] = d;
				dlzka++;

			}
			if (dlzka == 0) {
				printf("Spravu sa nepodarilo nacitat.");
			}
			else {
				rewind(fr);
			}
		}

		if (znak == 'v') {
			if (dlzka == 0) {
				printf("Sprava nieje nacitana.");
			}

			else {
				for (int a = 0; a < dlzka; a++) {
					printf("%c", load[a]);
				}
			}



			printf("\n");
		}



		if (znak == 'u') {
			int b = 0;;
			if (dlzka == 0) {
				printf("Sprava nieje nacitana.\n");
			}



			else {
				for (int a = 0; a < dlzka; a++) {
					if (load[a] >= 'a' && load[a] <= 'z') {
						change[b] = load[a] - 32;
						b++;
					}
					else if (load[a] >= 'A' && load[a] <= 'Z') {
						change[b] = load[a];
						b++;
					}



				}
			}



		}


		if (znak == 's') {




		}

	}




	return 0;

}