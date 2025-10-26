#include "f_desc.h"

int myGenerateRandomNum () {
	return rand()%RAND_LIM;
}

void myPushListRight (Node** head, int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("\nNepavyko prideti naujo Node.");
        return; 
    }
    newNode->data = number;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}


void myPrintListCMD (Node *head) {
	Node* current = head;
	if (head == NULL) {  
        printf("\nListas tuscias.");  
        return; 
    }  
	while (current != NULL) { 
		printf("%d ", current->data);  
		current = current->next;  
	}
}


void myPrintListFile (FILE **file_ptr, char *file_name, Node *head) {
	if (head == NULL) {  
        printf("\nListas tuscias.");  
        return; 
    }  
	*file_ptr = fopen(file_name, "r");
	if (*file_ptr == NULL) {
		printf("\nIvyko problema atidarinejant rezultatu faila.");
		return; 
	}
	if (!feof(*file_ptr)) {
		printf("\nFailas nera tuscias.");
		printf("\nAr tikrai norite overwritinti faila \"%s\"?", file_name);
		printf("\ntaip - \"t\", ne - \"n\"\nPasirinkimas: ");
		char user_input;
		if ((scanf(" %c", &user_input)) == 1 && (getchar() == '\n')) {
			switch (user_input) {
				case 't':
					break;
				case 'n':
					printf("\nPasirinkta nespausdinti faile \"%s\".", file_name);
					return;
				default:
					printf("\nNetinkama ivestis.");
					return;
					
			}
		} else {
			while(getchar() != '\n')
				;
		}
	}
	*file_ptr = fopen(file_name, "w+");
	Node* current = head;
	while (current != NULL) { 
		fprintf(*file_ptr, "%d ", current->data);  
		current = current->next;  
	}
	fclose(*file_ptr);
	printf("\nListas issaugotas faile \"%s\".", file_name);
}

int myCheckFileForUnwantedSymbols (FILE **file_ptr, char *file_name) {
	*file_ptr = fopen(file_name, "r");
	if (*file_ptr == NULL) {
		printf("\nDuomenu failas \"%s\" nerastas. ", file_name);
		fclose(*file_ptr);
		return 0; 
	}
	char temp;
	while ((temp = fgetc(*file_ptr)) != EOF) {
		if (!(temp == 13 || temp == 10 || temp == 32 ||(temp >= 48 && temp <= 57))) {
			printf("\nDuomenu failas \"%s\" turi nepriimtinu simboliu.", file_name);
			fclose(*file_ptr);
			return 0; 
		}
	}
	return 1;
}

int myPutFileContentIntoList (FILE *file_ptr, char *file_name, Node **head) {
    int temp = myCheckFileForUnwantedSymbols(&file_ptr, file_name);
    if (temp == 0) {
        return 0;
    } else {
		fseek(file_ptr, 0, SEEK_SET);
		char *next_field;
		char line[MAX_LINE_SIZE+1];
		while (1) {
			fgets(line, MAX_LINE_SIZE, file_ptr);
			if (feof(file_ptr))  
				return 1;
			next_field = strtok(line, " \n");
			
			while (next_field != NULL) {
				temp = atoi(next_field);
				myPushListRight(head, temp);
				next_field = strtok(NULL, " \n");
			}
		}
		fclose(file_ptr);
    }
}

//BE REKURSIJOS
void myDestroyList (Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

//SU REKURSIJA
void myDestroyListREC (Node** head) {
    Node* temp;
    if (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
		myDestroyListREC(head);
    } else 
		return;
}

void mySortList (Node* head) {
	if (head == NULL) {  
        printf("\nTuscias sarasas.");  
        return; 
    } 
	Node * current_i = head;
	Node * temp = (Node*)malloc(sizeof(Node));
 	if (head == NULL) {  
        printf("\nNepavyko isskirti atminties laikinui Node.");  
        return; 
    }
	while (current_i != NULL) {
		Node * current_j = current_i->next;
		while (current_j != NULL) {
			if (current_i->data > current_j->data) {
				temp->data = current_i->data;
				current_i->data = current_j->data;
				current_j->data = temp->data;
			}
			current_j = current_j->next;
		}
		current_i = current_i->next;
	}
	free(temp);
}


void myPrintMenu() {
	printf("\n--------------------------------------MENU------------------------------------------\n");
	printf("\n( 0 )\tSukuriamas tuscias doubly linked list\'as");
	printf("\n( 1 )\tNuskaitomi duomenys is nurodyto failo ir idedami i lista");
	printf("\n( 2 )\tListo spausdinimas");
	printf("\n( 3 )\tListo elementu surikiavimas didejimo tvarka");
	printf("\n( 4 )\tIterpiamas i lista is DESINES atsitiktinis skaicius(intervalas [0;%d])", RAND_LIM);
	printf("\n( 5 )\tList'o istrinimas");
	printf("\n( 6 )\tAtspausdinamas programos menu");
	printf("\n( 7 )\tIseinama is programos");
}

