#pragma once
#include "struct.h"
#include "nodePrint.h"
#include <string.h>

void searchNode(student* first, char* name) {
	student* next = first;
	
	if(!!strcmp(first->name, name)) {
		do{

			next = next->nextNode;
		} while (!strcmp(first->name, name));
		nodePrint(next);
	}
	else nodePrint(next);
}