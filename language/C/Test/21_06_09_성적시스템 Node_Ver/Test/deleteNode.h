#pragma once
#include "struct.h"
#include <string.h>
#include <stdlib.h>
#include "nodePrint.h"
student* deleteNode(student* first,char* name) {

		student* temp = first;
		student* after=NULL;
		if (!!strcmp(first->name, name)) {
			do {
				after = temp;
				temp = temp->nextNode;
			} while (!strcmp(first->name, name));
		}
		nodePrint(temp);
		after = temp->nextNode;
		free(temp);
		return after;
}
