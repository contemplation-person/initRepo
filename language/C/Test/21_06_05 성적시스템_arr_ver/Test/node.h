#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct Student {
	char name[10];
	int age;
	int s_num;
	int score;
	student* nextStudent;
}student;

student* createStudent(char* name, int age, int s_num, int score) {
	struct Student* header;
	strcpy_s(header->name, sizeof(header->name), name);
	header->age = age;
	header->s_num = s_num;
	header->score = score;
	header->nextStudent = NULL;
	return header;
}

student * newStudent(struct Student* pre, char* name, int age, int s_num, int score) {
	struct Student* new;
	new->nextStudent = pre->nextStudent;
	strcpy_s(new->name, sizeof(new->name), name);
	new->age = age;
	new->s_num = s_num;
	new->score = score;
	struct Student* nextStudent = NULL;
	return new;
}
struct Student* nextStudent(struct Student* first) {
	struct Student* last = first;
	while (last->nextStudent == NULL) {
		last = first->nextStudent;
	}
	return last;
}
