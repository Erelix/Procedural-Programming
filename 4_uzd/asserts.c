#include <assert.h>
#include "f_desc.h"

int main(){
	
	struct Node * head = NULL;

    myPushListRight(&head, 1000);
    myPushListRight(&head, 45);
	myPushListRight(&head, 544);
    myPushListRight(&head, 688);
    myPushListRight(&head, 0);

    assert(head->data == 1000);
    assert(head->next->data == 45);
	assert(head->next->next->data == 544);
    assert(head->next->next->next->data == 688);
    assert(head->next->next->next->next->data == 0);
	
	
	mySortList(head);
	assert(head->data == 0);
    assert(head->next->data == 45);
	assert(head->next->next->data == 544);
    assert(head->next->next->next->data == 688);
    assert(head->next->next->next->next->data == 1000);
	assert(head->next->next->next->next->next == NULL);
	
	head = head->next->next->next->next;
	
	assert(head->data == 1000);
    assert(head->prev->data == 688);
	assert(head->prev->prev->data == 544);
    assert(head->prev->prev->prev->data == 45);
    assert(head->prev->prev->prev->prev->data == 0);
	assert(head->prev->prev->prev->prev->prev == NULL);
	
	myDestroyListREC(&head);
	assert(head == NULL);
	
	char ok;
	scanf("%c", &ok);
	
	
	return 0;
}