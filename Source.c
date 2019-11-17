#include<stdio.h>

#define pole 1000




void nacitaj(char *load, FILE*fr,int *dlzka ) {
	*dlzka = 0;
	int d;


	while ((d = getc(fr)) != EOF && *dlzka<1000) {
		*load = d;
		load++;
		(*dlzka)++;
	}
	
	if (*dlzka == 0) {
		printf("Spravu sa nepodarilo nacitat.\n");}
	else {
		rewind(fr);	
	}


}

void vypis(char *vypisat, int dlzka){
	
	if (dlzka == 0) {
		printf("Subor nieje nacitany.");
	
	}


	else {
		for (int a = 0; a < dlzka; a++) {
			printf("%c", vypisat[a]);

		}
	}
	printf("\n");



}


int main() {

	char znak = 0;

	char load[pole];
	char change[pole];

	FILE* fr;
	fr = fopen("sifra.txt", "r");






	

	int dlzka;

	while (znak != 'k') {
		scanf("%c", &znak);
		getchar();



		if (znak == 'n') {
			nacitaj(load, fr,&dlzka);
		}


		if (znak == 'v') {	
			vypis(load, dlzka);
		}



		/*
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




		}*/

	}




	return 0;

}