#pragma once
#include "struct.h"
#include <string.h>
#include <stdlib.h>
#include "nodePrint.h"
student* insertNode(student* first, char* name, int age,int s_num,int score) {
	student* temp = first;
	
	if (!!strcmp(first->name, name)) {
		do {
			temp = temp->nextNode;
		} while (!strcmp(first->name, name));
	}

	strcpy_s(temp->name, sizeof(name), name);
	temp->age = age;
	temp->s_num = s_num;
	temp->score = score;

	nodePrint(temp);
	
	return temp;
}
