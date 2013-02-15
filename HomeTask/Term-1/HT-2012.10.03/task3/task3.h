struct ListElement
{
	int value;
	ListElement *next;
	ListElement *prev;
};
struct List
{
	ListElement *head;
	int size;
};
List *createList();
bool isEmpty(List *list);
void add(List *list, int value);
void deleteValue(List *list, int value);
void printList(List *list);
void deleteList(List* list);