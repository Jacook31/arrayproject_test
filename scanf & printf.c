#include <stdio.h>

int main(void) 
{
	/*int age;
	printf("나이가 몇살인가요?");
	scanf(" %d", &age);
	printf("%d살 입니다", age);

	

	double one, two, three;
	printf("3개의 정수를 입력하세요 : ");
	scanf("%d %d %d", &one, &two, &three);
	printf("첫번째 값 : %d\n", one);
	printf("두번째 값 : %d\n", two);
	printf("세번째 값 : %d\n", three);

	char c = 'A';
	printf("%c\n", c);*/
	

	//프로젝트
	//이름? 나이? 몸무게? 키? 범죄명?
	char name[256];
	printf("이름이 무엇입니까?");
	scanf("%s", &name, sizeof(name));
	
	int age;
	printf("나이가 어떻게 됩니까?"); 
	scanf("%d", &age);

	float weight;
	printf("몸무게가 몇kg 됩니까?");
	scanf("%f", &weight);
	
	double height;
	printf("키는 몇cm 입니까?"); 
	scanf("%lf", &height);

	
	char crime[256];
	printf("범죄명이 무엇입니까?");
	scanf("%s", &crime, sizeof(crime));

	//출력
	printf("\n --- 범죄자 정보 ---\n\n");
	printf(" 이름    : %s \n", name);
	printf(" 나이    : %d \n", age);
	printf(" 몸무게  : %.1f \n", weight);
	printf(" 키      : %.2lf \n", height);
	printf(" 범죄    : %s \n", crime);

	

	
	
	


	return 0;
}