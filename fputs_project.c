#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ��й�ȣ�� �Է¹޴´�.
// ��й�ȣ�� �´°�� �ؽ�Ʈ�� �ۼ��Ҽ� �ְ� �Ѵ�.
// Ʋ����� ���޼��� ǥ���ϰ� �����Ѵ�.

#define MAX 10000
int main(void)
{

    //fgets, fputs Ȱ��
    char line[MAX];     // ���Ͽ��� �ҷ��� ������ ������ ����
    char contents[MAX]; // �Է��� ����
    char password[20];  // ��й�ȣ �Է�
    char c;             // ��й�ȣ �Է� �� �� Ű�� Ȯ�ο� (����ŷ)

    printf(" ��й�ȣ�� �Է��ϼ���. : ");

    // getchar() / getch()�� ���̴�
    // getchar() : ���͸� �Է¹޾ƾ� ������ �Ѵ�
    // getch()   : Ű �Է½� �ٷιٷ� ������ �Ѵ�.
    int i = 0;
    while (1)
    {
        c = getch();
        if (c == 13) //Enter -> ��й�ȣ �Է� ����
        {
            password[i] = '\0';
            break;
        }
        else // ��й�ȣ �Է���
        {
            printf("*");
            password[i] = c;
        }
        i++;
    }

    // ��й�ȣ : umm
    printf("\n\n=== ��й�ȣ Ȯ�� �� ... ===\n\n");
    if (strcmp(password, "umm") == 0) // ��й�ȣ ��ġ
    {

        printf(" === ��й�ȣ Ȯ�� �Ϸ� === \n\n");
        char * fileName = "c:\\noway01.txt";
        FILE * file = fopen(fileName, "a+b");   
        // "a+b" = ������ ������ ����, ������ ������ append �� �Ѵ� (�ڿ��� ������ �߰��Ѵ�)
        if (file == NULL)
        {
            printf(" ���� ���� ���� \n");
            return 1;
        }

        while (fgets(line, MAX, file) != NULL)
        {
            printf("%s", line);
        }

        printf("\n\n ������ ��� �ۼ��ϼ��� ! �����Ͻ÷��� EXIT �� �Է��ϼ���\n\n");
        
        while(1)
        {
            scanf("%[^\n]", contents);  // �� �� (\n)�ٹٲ� �� ������ ������ �о����(�� ���徿)
            getchar(); //Enter �Է� (\n) Flush ó�� (�ٹٲ��� ���ִ� ó��)
            
            if(strcmp(contents, "EXIT") == 0)
            {
                printf("�Է��� �����մϴ�\n\n");
                break;
            }
            fputs(contents, file);
            fputs("\n", file); //Enter �� ������ ���� ó�� �Ͽ����Ƿ� ���Ƿ� �߰�

        }
         fclose(file);

    }
    else // ��й�ȣ�� Ʋ�� ���
    {
        printf(" === ��й�ȣ�� Ʋ�Ƚ��ϴ� ===\n\n");
    }



    return 0;
}