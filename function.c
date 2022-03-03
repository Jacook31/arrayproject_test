#include <stdio.h>

//메인함수 위쪽에서 선언을 하고 메인 아래쪾에 똑같이 써야함
void p(int num);

//void function_without_return();

int function_with_return();
void function_without_params();
void fuction_with_params(int num1, int num2, int num3);
int apple(int total, int ate); //전체 total 에서 ate개를 먹고 남은 수 를 반환.

int add(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);

int main(void)
{

	//function

	//계산기
	/*int num = 2;

	p(num);

	num = num + 3;
	p(num);

	num -= 1;
	p(num);

	num *= 3;
	p(num);

	num /= 6;
	p(num);*/

	/*함수 종류
	반환값이 없는 함수
	function_without_return();

	반환값이 있는 함수*/
	/*int ret = function_with_return();
	p(ret);*/

	//파라미터(전달값)가 없는 함수
	/*function_without_params();*/

	//파라미터 (전달값)가 있는 함수
	//fuction_with_params(15, 32, 53);

	//파라미터도 받고 반환값이 있는 함수
	//int ret = apple(5, 2); //5개의 사과중 2개를 먹었다
	//printf("사과 5개 중에 2개를 먹으면? %d개가 남아요",ret);
	//printf("사과 %d 개 중에 %d개 를 먹으면? %d 개가 남아요\n", 10, 4, apple(10, 4));

	//계산기 함수
	//printf("숫자와 연산기호를 쓰시오\n");
	//scanf_s(" %d %c %d",&num1,&dja1,&num2);
	int num = 2;
	num = add(num, 3);
	p(num);

	num = sub(num, 1);
	p(num);

	num = mul(num, 4);
	p(num);

	num = div(num, 2);
	p(num);

	return 0;
}
//정의
void p(int num)
{
	printf(" num 은 %d 입니다\n ", num);
}



//int 함수이름(int num1, int num2, char c )
//{
//	return num + 4;
//}
//
//void function_without_return()
//{
//	printf("반환값이 없는 함수 입니다");
//}

function_with_return()
{
	printf("반환값이 있는 함수 입니다\n");
	return 10;
}

void function_without_params()
{
	printf("전달값이 없는 함수 입니다\n");
}

void fuction_with_params(int num1, int num2, int num3)
{
	printf("전달값이 있는 함수 이며 값은 %d, %d, %d 입니다.\n",num1,num2,num3);
}

int apple(int total, int ate)
{
	printf("전달값과 반환값이 있는 함수 입니다.  \n");
	return total - ate;;
}
int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int mul(int num1, int num2)
{
	return num1 * num2;
}

int div(int num1, int num2)
{
	return num1 / num2;
}