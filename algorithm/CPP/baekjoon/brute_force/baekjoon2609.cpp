/*
    문제
    두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

    입력
    첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

    출력
    첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

    예제 입력 1
    24 18
    예제 출력 1
    6
    72
*/
#include <iostream>
#include <vector>

using namespace std;

// 최대 공약수 구하는 공식
int get_gcd(int a, int b)
{
  while (b != 0)
  {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int main()
{
  int num[2];

  cin >> num[0];
  cin >> num[1];

  if (num[0] > num[1])
    swap(num[0], num[1]);

  int gcd = get_gcd(num[0], num[1]);
  int lcm = (num[0] * num[1]) / gcd; // 최소 공배수 구하는 공식

  cout << gcd << endl;
  cout << lcm << endl;

  return 0;
}