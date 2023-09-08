#pragma once
#include <string.h>
#include <stdlib.h>
#include "nodePrint.h"

student* CreateNode(char* name, int age, int s_num, int score) {
	student* newNode = (student*)calloc(1,sizeof(student));

	strcpy_s(newNode->name, sizeof(name), name);
	newNode->age = age;
	newNode->s_num = s_num;
	newNode->score = score;
	newNode->nextNode = NULL;

	nodePrint(newNode);
	return newNode;
}

student* addNode(student* pre, char* name, int age, int s_num, int score) {	
	student* newNode = (student*)calloc(1, sizeof(student));
	
	strcpy_s(newNode->name, sizeof(name), name);
	newNode->age = age;
	newNode->s_num = s_num;
	newNode->score = score;
	pre->nextNode = newNode;

	nodePrint(newNode);
	return newNode;
}