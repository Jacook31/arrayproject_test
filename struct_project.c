#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 5������ ����̰� �ִ�.
// �ƹ� Ű�� ������ �������� �̴´�.
// 5���� ��� �����ϴ°� (�ߺ� ����)

// �����
// �̸�, ����, ����, Ű��³��̵�(����)

typedef struct{
    char * name;    //�̸�
    int age;        //����
    char * character; //����
    int level; //Ű��� ���̵� (1~5, 5�� �����)
} CAT;

//������� ������ �����
int collection[5] = { 0, 0, 0, 0, 0 };

// ��ü ����� ����Ʈ
CAT cats[5];


void initCats(); //����� ���� �ʱ�ȭ
void printCat(int selected);
int checkCollection();

int main(void)
{

    srand(time(NULL));

    initCats();
    while (1)
    {
        printf("����� �̱�! �ƹ�Ű�� ������ Ȯ���ϼ���\n");
        getchar();

        int selected = rand() % 5; // 0~4 ���� ��ȯ
        printCat(selected);         // ���� ����� ���� ���
        collection[selected] = 1;   // ����� �̱� ó��

        int collectAll = checkCollection();
        if (collectAll == 1)
        {
            break;
        }

         
    }



    return 0;
}
void initCats()
{
    cats[0].name = "ġ���";
    cats[0].age = 3;
    cats[0].character = "�¼�";
    cats[0].level = 1;

    cats[1].name = "���þȺ��";
    cats[1].age = 2;
    cats[1].character = "��ī�Ӵ�";
    cats[1].level = 4;

    cats[2].name = "�丣�þ�";
    cats[2].age = 5;
    cats[2].character = "���̸���";
    cats[2].level = 2;

    cats[3].name = "��";
    cats[3].age = 1;
    cats[3].character = "�¼�";
    cats[3].level = 1;

    cats[4].name = "��ٳ�";
    cats[4].age = 3;
    cats[4].character = "Ȱ��";
    cats[4].level = 3;  
}

void printCat(int selected)
{
    printf("\n\n=== �Ʒ��� ����̰� �ɷȾ��! ====\n\n");
    printf(" �̸� : %s\n", cats[selected].name);
    printf(" ���� : %d\n", cats[selected].age);
    printf(" ���� : %s\n", cats[selected].character);
       //printf(" ���� : %d\n", cats[selected].level);
       printf(" ���� : ");

       for(int i = 0; i < cats[selected].level; i++)
       {
           printf("%s  ", "��");
       }
       printf("\n\n");
}

int checkCollection()
{
    // ���� ������ ����� ��ϵ� ���, 
    // �� ��Ҵ��� ���θ� ��ȯ
    int collectAll = 1;


    printf("\n\n ========== ������ ����� ��� =========== \n\n");
    for (int i = 0; i < 5; i++)
    {
        if(collection[i] == 0)  // ����� ���� x
        {
            printf("%15s", "(�� �ڽ�)");
            collectAll = 0; // �� ������ ���� ����
        }
        else // ����� ���� O
        {
            printf("%15s", cats[i].name);
        } 
        
        
    }
    printf("\n==============================================\n\n");

    if (collectAll)//����̸� ��� ���� ���
        {
            printf("\n\n �����մϴ�! ��� ����̸� ��ҽ��ϴ�. \n\n");
        }    

      return collectAll;
}