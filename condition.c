#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	//if문
	//int age;
	//	scanf_s("%d", &age);
	//	if (age >= 8 && age <= 13)//&&은 양쪽 모두 포함일때
	//	{ 
	// 
	//		printf("초등학생 입니다 \n");
	//	}

	//	else if (age >= 14 && age <= 16)
	//	{
	//		printf("중학생 입니다 \n");
	//	}

	//	else if (age >= 17 && age <= 19)
	//	{
	//		printf("고등학생 입니다 \n");
	//	}

	//	else
	//		printf("성인입니다.");


	//break / continue 문
	//int m, n;
	//printf("청소시킬사람 ");
	//scanf_s("%d %d", &n, &m);
	//
	//for (int i = 1; i <= 30; i++)
	//{
	//	if (i >= 6 && i <= 10)
	//	{
	//		if (i == 7)
	//		{
	//			printf("%d는 결석 \n", i);
	//			continue; //이 조건에 들어왔을때 컨티뉴를 만나면 그이후의 문장을 실행하지않는다
	//		}
	//		printf("%d 번 학생은 준비해\n", i);
	//	}
	//}

	// ||는 (a || b) a의 조건과 b의조건중 하나라도 맞다면 실행이된다.
	// 
	

	//랜덤
	//int num = rand() % 3+1; // 그냥 3만 하게되면 0~2 이며 +1을 해줘야 1~3 이 된다.


	
	//printf("난수 초기화 이전..\n");
	//for (int i = 0; i < 10; i++)
	//	printf(" %d ", rand() % 10);

	//srand(time(NULL)); //난수 초기화 
	//
	// 
	//printf("\n\n난수 초기화 이전..\n");
	//for (int i = 0; i < 10; i++)
	//	printf(" %d ", rand() % 10);

	//가위 0 바위 1 보 2
	/*srand(time(NULL));
	int i = rand() % 3;
	
	switch(i)
	{
	case 0:printf("가위\n");		break;
	case 1:printf("바위\n");		break;
	case 2:printf("보\n");		break;


	//default:printf("몰라요\n"*//*	break;*/
	//}
	//

	/*int age;
		scanf_s("%d", &age);
		switch (age)
		{
		case 8:			
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
			printf("초등학생 입니다 \n");
			break;
			
		case 16:
			printf("중학생 입니다 \n");	

		case 19:			
			printf("고등학생 입니다 \n");		


		default: printf("학생이 아닙니다");
	
		}
		*/

	//up and down

	//srand(time(NULL));
	//int num = rand() % 100 + 1; //1~100숫자
	//printf(" 숫자 : %d\n", num);
	//int answer = 0; //정답
	//int chance = 5; //기회
	//while (chance > 0) //1은 참 0은 거짓
	//{
	//	printf(" 남은기회 %d번 \n", chance--);
	//	printf(" 숫자를 맞춰보세요 (1~100) : \n");
	//	scanf_s(" %d", &answer);

	//	if (answer > num)
	//	{
	//		printf(" DOWN ↓ \n\n");
	//	}
	//	else if (answer < num)
	//	{
	//		printf(" UP ↑ \n\n");
	//	}
	//	else if(answer == num)
	//	{
	//		printf(" 정답입니다. \n");
	//		break;
	//	}
	//	else
	//	{
	//		printf(" 오류가 발생했습니다. \n");
	//	}
	//	
	//	if (chance == 0)
	//	{
	//		printf(" 실패 ! 모든 기회를 사용했습니다.");
	//		break;
	//	}
	//}
	

	return 0;
}