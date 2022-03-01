#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 비밀번호를 입력받는다.
// 비밀번호가 맞는경우 텍스트를 작성할수 있게 한다.
// 틀린경우 경고메세지 표시하고 종료한다.

#define MAX 10000
int main(void)
{

    //fgets, fputs 활용
    char line[MAX];     // 파일에서 불러온 내용을 저장할 변수
    char contents[MAX]; // 입력할 내용
    char password[20];  // 비밀번호 입력
    char c;             // 비밀번호 입력 할 때 키값 확인용 (마스킹)

    printf(" 비밀번호를 입력하세요. : ");

    // getchar() / getch()의 차이는
    // getchar() : 엔터를 입력받아야 동작을 한다
    // getch()   : 키 입력시 바로바로 동작을 한다.
    int i = 0;
    while (1)
    {
        c = getch();
        if (c == 13) //Enter -> 비밀번호 입력 종료
        {
            password[i] = '\0';
            break;
        }
        else // 비밀번호 입력중
        {
            printf("*");
            password[i] = c;
        }
        i++;
    }

    // 비밀번호 : umm
    printf("\n\n=== 비밀번호 확인 중 ... ===\n\n");
    if (strcmp(password, "umm") == 0) // 비밀번호 일치
    {

        printf(" === 비밀번호 확인 완료 === \n\n");
        char * fileName = "c:\\noway01.txt";
        FILE * file = fopen(fileName, "a+b");   
        // "a+b" = 파일이 없으면 생성, 파일이 있으면 append 를 한다 (뒤에서 내용을 추가한다)
        if (file == NULL)
        {
            printf(" 파일 열기 실패 \n");
            return 1;
        }

        while (fgets(line, MAX, file) != NULL)
        {
            printf("%s", line);
        }

        printf("\n\n 내용을 계속 작성하세요 ! 종료하시려면 EXIT 를 입력하세요\n\n");
        
        while(1)
        {
            scanf("%[^\n]", contents);  // 새 줄 (\n)줄바꿈 이 나오기 전까지 읽어들임(한 문장씩)
            getchar(); //Enter 입력 (\n) Flush 처리 (줄바꿈을 없애는 처리)
            
            if(strcmp(contents, "EXIT") == 0)
            {
                printf("입력을 종료합니다\n\n");
                break;
            }
            fputs(contents, file);
            fputs("\n", file); //Enter 를 위에서 무시 처리 하였으므로 임의로 추가

        }
         fclose(file);

    }
    else // 비밀번호가 틀린 경우
    {
        printf(" === 비밀번호가 틀렸습니다 ===\n\n");
    }



    return 0;
}