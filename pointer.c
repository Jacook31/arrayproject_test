#include <stdio.h>
#include <time.h>

void swap(int a, int b);
void swap_addr(int * a, int * b);
void changeArray(int * ptr);
int level;
int arrayFish[6];
int * cursor;
void initData();
void printfFishes();
void decreaseWater(long elapsedTime);

int main(void)
{
    //포인터
    //chulsu : 101호
    //yonghee : 201호
    //minsu : 301호
    // int chulsu  = 1;    //암호
    // int yonghee = 2;
    // int minsu = 3;
    // printf("철수네 주소 : %d, 암호 : %d\n", &chulsu, chulsu); 
    // printf("영희네 주소 : %d, 암호 : %d\n", &yonghee, yonghee);
    // printf("민수네 주소 : %d, 암호 : %d\n", &minsu, minsu); //메모리공간의 주소를 나타내려면 &를 해주면됨    
    //미션
    //첫번째 미션 : 아파트의 각 집에 방문하여 문에 적힌 암호 확인
    // int *mission; //pointer variable
    // mission = &chulsu;
    // printf("미션 주소 : %d, 암호 : %d\n", mission, *mission);
    //  mission = &yonghee;
    // printf("미션 주소 : %d, 암호 : %d\n", mission, *mission);
    // mission = &minsu;
    // printf("미션 주소 : %d, 암호 : %d\n", mission, *mission);
    // //second mission : 각 암호에 3을 곱해라
    // mission = &chulsu;
    // *mission = *mission * 3;
    //  printf("미션 암호를 바꾼곳 주소 : %d, 암호 : %d\n", mission, *mission);
    // mission = &yonghee;
    // *mission = *mission * 3;
    // printf("미션 주소 : %d, 암호 : %d\n", mission, *mission);
    // mission = &minsu;
    // *mission = *mission * 3;
    // printf("미션 주소 : %d, 암호 : %d\n", mission, *mission);
    // //spy
    // //미션이 바꾼 암호에서 2를 빼라
    // int *spy = mission;     
    // printf("\n ... spy가 미션 수행하는중 ...\n\n");
    // spy = &chulsu; 
    // *spy = *spy - 2; 
    // printf("spy가 방문하는곳 주소 : %d, 암호 %d\n",spy, *spy);
    //  spy = &yonghee;
    // *spy = *spy - 2; 
    // printf("spy가 방문하는곳 주소 : %d, 암호 %d\n",spy, *spy);
    //  spy = &minsu;
    // *spy = *spy - 2; 
    // printf("spy가 방문하는곳 주소 : %d, 암호 %d\n",spy, *spy);
    // printf(" \n... 암호가 바뀌었다.\n");
    // printf("철수네 주소 : %d, 암호 : %d\n", &chulsu, chulsu); 
    // printf("영희네 주소 : %d, 암호 : %d\n", &yonghee, yonghee);
    // printf("민수네 주소 : %d, 암호 : %d\n", &minsu, minsu);
    // //mision 주소는 &mission으로 확인
    // printf("mission address : %d\n", &mission);
    // printf("spy address : %d\n", &spy);  

   //배열 
    //    int arr[3] = {5 , 10 , 15};
    //    int * ptr = arr;
    //    for (int i = 0; i < 3; i++)
    //    {
    //        printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
    //    }
    //    for (int i = 0; i < 3; i++)
    //    {
    //        printf("포인터 ptr[%d]의 값 : %d\n", i,  ptr[i]);
    //    }
    //     ptr[0] = 100;
    //     ptr[1] = 200;
    //     ptr[2] = 300;
    //     for (int i = 0; i < 3; i++)
    //    {
    //        //printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
    //        printf("배열 arr[%d]의 값 : %d\n", i, *(arr + i)); //윗줄과 같은 결과값이 나온다.
    //    }
    //    for (int i = 0; i < 3; i++)
    //    {
//        //printf("포인터 ptr[%d]의 값 : %d\n", i,  ptr[i]);
    //        printf("포인터 ptr[%d]의 값 : %d\n", i, *(ptr + i));
    //    }
    //     //*(arr + i) == arr[i] 똑같은 표현이다.
    //     //arr == arr 배열의 첫번째 값의 주소와 동일 == &arr[0] // 주소= '&' 로 표현한다
    //     printf(" arr 자체의 값  : %d\n",arr);
    //     printf(" arr[0]의 주소 : %d\n", &arr[0]);
    //     //
    //     printf(" arr 자체의 값이 가지는 주소의 실제 값 : %d \n", *arr);
    //     printf(" arr[0] 의 실제 값 : %d\n", *&arr[0]);
    //     //
    //     // *& 는 아무것도 없는 것과 같다. &는 주소이며, *는 그 주소의 값이기 때문에
    //     // *&는 서로 상쇄가 된다.
    //     printf("arr[0]의 실제 값 : %d\n",*&*&*&*&*&*&*&*&*&*&*&arr[0]);
    //      printf("arr[0]의 실제 값 : %d\n", arr[0]);

    //SWAP
    // int a = 10;
    // int b = 20;
    // printf("a의 주소 : %d\n", &a);
    // printf("b의 주소 : %d\n", &b);
    // // a 와 b의 값을 바꾼다
    // printf("Swap 함수 전 => a : %d, b = %d\n",a,b);
    // swap(a,b);
    // printf("Swap 함수 후 => a : %d, b = %d\n",a,b);
    // //값에 의한 복사 (Call by Value) -> 값만 복사한다는 의미
    // //
    // // 주소값을 넘기면? 메모리 공간에 있는 주소값 자체를 넘기면.. 철수네 처럼
    // printf("(주소값전달)swap 함수 전 => a : %d, b = %d\n",a,b);
    // swap_addr(&a,&b);
    // printf("(주소값전달)Swap 함수 후 => a : %d, b = %d\n",a,b);

    //배열일 때, arr2 ->주소
    // int arr2[3] = {10, 20, 30};
    //changeArray(arr2);
    // changeArray(&arr2[0]);
    // for( int i = 0; i < 3; i++)
    // {
    //     printf("%d\n", arr2[i]);
    // }
    //
    // scanf 에서 &num 과 같이 & 를 사용하는이유

    //프로젝트(포인터)
    //
    long startTime = 0; //게임 시작 시간
    long totalElapsedTime = 0; //총 경화 시간
    long prevElapsedTime = 0; //직전 경과 시간  (최근에 물을 준 시간 간격)

    int num;    //몇 번 어항에 물을 채울것인지, 사용자 입력
    initData();

    cursor = arrayFish; //cursor[0] .. cursor[1]

    startTime = clock(); //현재 시간을 millisecond (1000분의 1초)단위로 반환
    while(1)
    {
        printfFishes();
        printf("몇 번 어항에 물을 주시겠어요?");
        scanf("%d", &num);

        // 입력값 체크
        if (num < 1 || num >6)
        {
            printf("\n입력값이 잘못되었습니다.\n");
            continue;
        }

        //총 경과 시간
        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
        printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

        // 직전 물 준 시간 (마지막으로 물 준 시간) 이후로 흐른 시간
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

        // 어항의 물을 가소 (증발)
        decreaseWater(prevElapsedTime);

        // 사용자가 입력한 어항에 물을 넣는다
        // 1. 어항의 물이 0이면? 물을 주지 않는다
        if(cursor[num - 1] <=0)
        {
            printf("%d 번 물고기는 이미 죽었습니다.. 물을 주지 않습니다.\n", num);
        }
        // 2. 어항의 물이 0 이 아닌 경우 물을 준다 100을 넘지 않는지 체크
        else if (cursor[num - 1] + 1 <= 100)
        {
            // 물을 준다.
            printf("%d 번 어항에 물을 줍니다. \n", num);
            cursor[num - 1] += 1;
        }

        //레벨업을 할 것인지 (레벨업을 20초마다 한번씩 수행)
        if (totalElapsedTime / 20 > level - 1)
        {
            // 레벨업
            level++; // level 1 -> lelve 2
            printf(" *** 레벨업 기존 %d 레벨에서 %d레벨로 올랐습니다. *** \n", level -1, level);

            //최종 레벨 : 5
            if (level == 5)
            {
                printf("\n\n축하합니다. 최고 레벨을 달성하였습니다. 게임을 종료합니다.\n");
                exit(0);
            }
        }

        //모든 물고기가 죽었는지 확인
        if (checkFishAlive() == 0)
        {
            //물고기가 모두 죽었다
            printf(" 모든 물고기가 죽었습니다. \n");
            exit(0);
        }
        else
        {
            //최소 한마리 이상의 물고기는 살아있음
            printf("살아있는 물고기가 있습니다.\n");
        }
        prevElapsedTime = totalElapsedTime;
        // 10초 -> 15초 (5초 : prevElapsedTime ->15초) -> 25초 (10초 )

    }
    
    return 0;
}

// void swap(int a, int b)
// {
//     printf("(swap 함수 내) a의 주소 : %d\n", &a);
//     printf("(swap 함수 내) b의 주소 : %d\n", &b);
//     int temp = a;
//     a = b;
//     b = temp;
//     printf("Swap 함수 내 => a : %d, b = %d\n",a,b);
//
// }
// void swap_addr(int * a, int * b)
// {  
//     int temp = *a;
//     *a = *b;
//     *b = temp;
//     printf("(주소값전달)Swap_addr 함수 내 => a : %d, b = %d\n", *a, *b);
//
// }     
// void changeArray(int * ptr)
// {
//     ptr[2] = 50;
// }
void initData()
{
    level = 1; //게임레벨 (1~5)
    for(int i = 0; i < 6; i++)
    {
        arrayFish[i] = 100; //어항의 물 높이 0~100
    }
}

void  printfFishes()
{
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번 \n", 1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 6; i++)
    {
        printf(" %4d ",arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater(long elapsedTime)
{
    for(int i = 0; i < 6; i++)
    {
        arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3은 난이도 조절을 위한 값
        if(arrayFish[i] < 0)
        {
            arrayFish[i] = 0;
        }
    }
}

int checkFishAlive()
{
    for(int i = 0; i < 6; i++)
    {
        if (arrayFish[i] > 0)
            return 1; //참
    }
    return 0;
}