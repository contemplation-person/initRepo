#include <stdio.h>
int set_human(struct Test* a, int age, int gender,const char* name);
int copy_str(char* dest, const char* src);
struct Return_ re(int j);

struct Test {
	int age;
	int gender;
	char name[20];
};

struct Imployee {
	int age;
	int salary;
};

struct Company {
	struct Imployee data;
	char name[20];
};

struct Return_ {
	int i;
};

struct other {
	int a;
}o = { 2 };//o 는 구조체 변수 정의.

void main() {
	struct Test human;
	set_human(&human, 10, 1, "Lee");

	printf("%d,%d,%s\n", human.age, human.gender,human.name);

	printf("\n------------------------\n");

	struct Company kim;

	kim.data.age = 31;
	kim.data.salary = 3100;

	scanf_s("%s", kim.name,sizeof(kim.name));
	printf("%s, %d, %d\n", kim.name,kim.data.age, kim.data.salary);

	printf("\n------------------------\n");
	struct Return_ a;
	a = re(2);
	printf("%d\n", a.i);
	
	printf("\n------------------------\n");
	o.a = 1;
	printf("%d\n", o.a);
	
	struct Test x = { 20,180,"he" };
	printf("%d, %d, %s\n" , x.age,x.gender,x.name);
}

int set_human(struct Test* a, int age, int gender,const char *name) {
	a->age = age;
	a->gender = gender;
	copy_str(a->name,name);
	return 0;
}
int copy_str(char* dest, const char* src) {
	while (*src) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return 0;
}
struct Return_ re(int j) {
	struct Return_ a;
	a.i = j;

	return a;
}