/*
	하드웨어와 통신할 때 사용.
*/

#include <stdio.h>	

typedef struct SENSOR {
	/*감지안되면 0, 감지되면 1*/
	int sensor_flag;
	int data;
}SENSOR;//typedef struct SENSOR SENSOR;와 동일,

int main() {
	volatile SENSOR* sensor;// 컴파일러가 sensor의 최적화를 수행하지 않음.
	/*값이 감지 될 때까지 무한루프*/
	while (!(sensor->sensor_flag)) {

	}
	printf("Data : %d\n", sensor->data);
}