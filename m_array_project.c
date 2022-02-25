#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//10개의 서로 다른 카드 찾기 (각 카드 2개 찾아서 맞추는것)
// 사용자로 부터 2개의 입력값을 받아서 -> 같은 카드 찾으면 카드 뒤집기
// 모든 카드를 맞추면 게임종료
// 총 실패 횟수 알려주기 (같은짝을 찾지 못한 횟수)
int arrayCard[4][5];    //카드 지도 (20장의 카드)
int checkCard[4][5];    // 뒤집혔는지 여부 확인 
int getEmptyPosition();
char * strCard[10];
int conv_pos_x(int x);
int conv_pos_y(int y);
int foundAllCard();

void initCardArray();
void initCardName();
void shuffleCard();
void printCards();   
void printfQuestion();

int main(void)
{
    srand(time(NULL));

    initCardArray();
    initCardName();

    shuffleCard();

    int failCount = 0; //실패 횟수

    while (1)
    {
        int select1 = 0;    // 사용자가 선택한 처음 수
        int select2 = 0;    // 사용자가 선택한 두번째 수

        printCards();       //카드 위치 출력
        printfQuestion();   //문제 출력 (카드 지도)
        printf("뒤집을 카드를 2개 고르세요 : ");
        scanf("%d %d", &select1, &select2);

        if(select1 == select2) //같은 카드 선택시 무효
            continue;
        
        
        // 좌표에 해당하는 카드를 뒤집어 보고 같은지 확인
        // 정수 좌표를 (x,y)로 변환
        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);

        // 같은 카드인 경우
        if ((checkCard[firstSelect_x][firstSelect_y] == 0 
            && checkCard[secondSelect_x][secondSelect_y] == 0)
            &&
            (arrayCard[firstSelect_x][firstSelect_y] 
            == arrayCard[secondSelect_x][secondSelect_y]))
         // 두 알파벳이 같은지
         {
             printf("\n\n 맞았습니다 : %s 발견 \n\n", strCard[arrayCard[firstSelect_x][firstSelect_y]]);
             checkCard[firstSelect_x][firstSelect_y] = 1;
             checkCard[secondSelect_x][secondSelect_y] = 1;
         }
         // 다른 알파벳인 경우
         else
         {
             printf("\n\n 틀렸거나, 이미 뒤집힌 카드입니다. \n");
             printf("%d : %s\n", select1, strCard[arrayCard[firstSelect_x][firstSelect_y]]);
             printf("%d : %s\n", select2, strCard[arrayCard[secondSelect_x][secondSelect_y]]);
             printf("\n\n");

             failCount++;
         }
        
        // 모든 카드를 찾았는지 여부, 1 : 참 , 0 : 거짓
        if (foundAllCard() == 1)
        {
            printf(" \n\n 모든카드를 잘 찾았습니다. \n");
            printf("지금까지 총 %d번 실수 하였습니다.\n",failCount);
            break;
        }


    }


    return 0;
}

void initCardArray()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arrayCard[i][j] = -1;
        }
    }
}
void initCardName()
{
    strCard[0] = "원숭이";
    strCard[1] = "강아지";
    strCard[2] = "코끼리";
    strCard[3] = "타조";
    strCard[4] = "하마";

    strCard[5] = "오리";
    strCard[6] = "고양이";
    strCard[7] = "호랑이";
    strCard[8] = "사자";
    strCard[9] = "기린";

}

void shuffleCard()
{
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayCard[x][y] = i;
        }
    }
}

//좌표에서 빈 공간 찾기
int getEmptyPosition() //반복작업을 줄이기위해 int형 대신 구조체 사용할수 있음.
{
        //ㅁㅁㅁㅁㅁ 0  1  2  3  4  ->5로 나눈다면 0 0 0 0 0
        //ㅁㅁㅁㅁㅁ 5  6  7  8  9  -> 1 1 1 1 1
        //ㅁㅁㅁㅁㅁ 10 11 12 13 14  -> 2 2 2 2 2
        //ㅁㅁㅁㅁㅁ 15 16 17 18 19 -> 3 3 3 3 3
    while(1)
    {
        int randPos = rand() % 20; //0~19 사이의 숫자 반환
        // 19 -> (3,4)
        int x = conv_pos_x(randPos);    
        int y = conv_pos_y(randPos);

        if(arrayCard[x][y] == -1)
        {
            return randPos;
        }
    }
    return 0;
}

int conv_pos_x(int x)
{
     // 19 -> (3,4)
     return x / 5;
}
int conv_pos_y (int y)
{
        // 19 -> 19 / 5 = 몫은 3, 나머지 4
    return y % 5;   // y를 5로 나눈 나머지 값
}

void printCards() 
{
    printf("\n============== 확인하기용 =================\n");
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%8s", strCard[arrayCard[i][j]]);
        }
        printf("\n");
    }
    printf("\n=========================================\n");
}    
void printfQuestion()
{
    printf("\n\n(문제)\n");
    int seq = 0;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            // 카드를 뒤집어서 정답을 맞췄으면 '카드 숫자'
            if(checkCard[i][j] != 0)
            {
                printf("%8s", strCard[arrayCard[i][j]]);
            }
            // 아직 뒤집지 못했으면 (정답을 못맞혔으면) 뒷면 -> 위치를 나타내는 숫자
            else
            {
                printf("%8d",seq);
            }
            seq++;
        }
         printf("\n");
    }
}

int foundAllCard()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if (checkCard[i][j] == 0)
            {
            return 0;
            }
        }
    }
    return 1; // 모두 다 찾음
}