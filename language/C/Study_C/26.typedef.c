#include <stdio.h>
struct HUMAN {
	int age;
	int height;
	int weight;
	int gender;
};
typedef struct HUMAN Human;// typedef (이름을 새로 부여하고자 하는 타입) (새로운 이름)

int Print_status(Human human);

void main() {
	Human Adam = { 31,180,75,0 };
	Human eve = { 27,166,48,1 };

	Print_status(Adam);
	Print_status(eve);

}
int Print_status(Human human) {
	if (human.gender == 0) {
		printf("Male\n");
	}
	else {
		printf("Female\n");
	}

	printf("age :%d \n / height : %d / weight : %d\n", human.age, human.height, human.weight);

	if (human.gender == 0 && human.height >= 180) {
		printf("he is a winner\n");
	}
	else if (human.gender == 0 && human.height < 180) {
		printf("he is a loser\n");
	}
	printf("--------------------------------\n");
	return 0;
}