#include "f_desc.h"

int main(){
	
	FILE * result_file_ptr = NULL;
	char result_file_name[MAX_FILE_NAME];
	
	FILE * data_file_ptr = NULL;
	char data_file_name[MAX_FILE_NAME];
	
	struct Node * head = NULL;
	
    srand(time(NULL));

	int program_end = 0;
	char user_input;
	
	
	myPrintMenu();
	while (program_end == 0) {
		
		printf("\n\n------------------------------------------------------------------------------------\nKomanda: ");
		if ((scanf(" %c", &user_input) == 1) && (getchar() == '\n')) {

			switch (user_input) {
				case '0':
					if (head != NULL) {
						printf("\nSarasas jau sukurtas. Jei bus kuriamas naujas, seno listo duomenys bus istrinti.");
						printf("\nAr tikrai norite istrinti seno saraso duomenis?");
						printf("\ntaip - \"t\", ne - \"n\"\nPasirinkimas: ");
						if ((scanf(" %c", &user_input)) == 1 && (getchar() == '\n')) {
							switch (user_input) {
								case 't':
									myDestroyListREC(&head);
									printf("\nSenas listas istrintas.");
									printf("\nSukurtas naujas tuscias doubly linked ist'as.");
									break;
								case 'n':
									printf("\nPasirinkta netrinti ir nekurti naujo listo.");
									break;
								default:
									printf("\nNetinkama ivestis.");
									break;
							}
						} else {
							while(getchar() != '\n')
								;
						}
					} else {
						printf("\nSukurtas naujas tuscias doubly linked list'as.");
						Node * head = NULL;
					}
					break;
					
				case '1':
					printf("\nPrasome ivesti duomenu failo pavadinima, is kurio bus nuskaitomi duomenys.\nPavadinimas: ");
					if ((scanf("%s", data_file_name)) == 1 && (getchar() == '\n')) {
						int zero_or_one = myPutFileContentIntoList(data_file_ptr, data_file_name, &head);
						if (zero_or_one == 0)
							;
						else if (zero_or_one == 1)
							printf("\nFailas sekmingai nuskaitytas, o sarasas uzpildytas/papildytas.");
					} else {
						while(getchar() != '\n')
							;
					}
					break;
						
				
				case '2':
					printf("\nPrasome pasirinkti, kur bus spausdinamas listas.\nfaile - \"f\", darbalaukyje - \"d\"\nListo isvedimas: ");
					if ((scanf(" %c", &user_input)) == 1 && (getchar() == '\n')) {
						switch (user_input) {
							case 'f':
								printf("\nPrasome ivesti rezultatu failo pavadinima, i kuri bus rasomi duomenys.\nPavadinimas: ");
								if ((scanf("%s", result_file_name)) == 1 && (getchar() == '\n')) {
									myPrintListFile(&result_file_ptr, result_file_name, head);
									
								} else {
									while(getchar() != '\n')
										;
								}
								break;
							
							case 'd':
								printf("\nListas:\n");
								myPrintListCMD(head);
								break;
							
							default:
								printf("\nNetinkama ivestis.");
								break;
						}
						
					}else {
						while(getchar() != '\n')
							;
					}
					break;
					
				case '3':
					mySortList(head);
					printf("\nListo elementai buvo surikiuoti didejimo tvarka.");
					break;	
					
				
				case '4':
					myPushListRight(&head, myGenerateRandomNum());
					printf("\nI lista buvo iterptas skaicius.");
					break;
				
				case '5':
					if(head != NULL)
				
					myDestroyList(&head);
					if (head == NULL)
						printf("\nListas buvo sekmingai istrintas.");
					else 
						printf("\nNepavyko istrinti listo.");
					break;
				
				case '6':
					myPrintMenu();
					break;
				
				case '7':
					myDestroyListREC(&head);
					++program_end;
					break;
					
				default :
					printf("\nNetinkama ivestis.");
					break;
			}
		} else {
			while(getchar() != '\n')
				;
		}
	}
  return 0;
}