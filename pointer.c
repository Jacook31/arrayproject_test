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
    //������
    //chulsu : 101ȣ
    //yonghee : 201ȣ
    //minsu : 301ȣ
    // int chulsu  = 1;    //��ȣ
    // int yonghee = 2;
    // int minsu = 3;
    // printf("ö���� �ּ� : %d, ��ȣ : %d\n", &chulsu, chulsu); 
    // printf("����� �ּ� : %d, ��ȣ : %d\n", &yonghee, yonghee);
    // printf("�μ��� �ּ� : %d, ��ȣ : %d\n", &minsu, minsu); //�޸𸮰����� �ּҸ� ��Ÿ������ &�� ���ָ��    
    //�̼�
    //ù��° �̼� : ����Ʈ�� �� ���� �湮�Ͽ� ���� ���� ��ȣ Ȯ��
    // int *mission; //pointer variable
    // mission = &chulsu;
    // printf("�̼� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    //  mission = &yonghee;
    // printf("�̼� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    // mission = &minsu;
    // printf("�̼� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    // //second mission : �� ��ȣ�� 3�� ���ض�
    // mission = &chulsu;
    // *mission = *mission * 3;
    //  printf("�̼� ��ȣ�� �ٲ۰� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    // mission = &yonghee;
    // *mission = *mission * 3;
    // printf("�̼� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    // mission = &minsu;
    // *mission = *mission * 3;
    // printf("�̼� �ּ� : %d, ��ȣ : %d\n", mission, *mission);
    // //spy
    // //�̼��� �ٲ� ��ȣ���� 2�� ����
    // int *spy = mission;     
    // printf("\n ... spy�� �̼� �����ϴ��� ...\n\n");
    // spy = &chulsu; 
    // *spy = *spy - 2; 
    // printf("spy�� �湮�ϴ°� �ּ� : %d, ��ȣ %d\n",spy, *spy);
    //  spy = &yonghee;
    // *spy = *spy - 2; 
    // printf("spy�� �湮�ϴ°� �ּ� : %d, ��ȣ %d\n",spy, *spy);
    //  spy = &minsu;
    // *spy = *spy - 2; 
    // printf("spy�� �湮�ϴ°� �ּ� : %d, ��ȣ %d\n",spy, *spy);
    // printf(" \n... ��ȣ�� �ٲ����.\n");
    // printf("ö���� �ּ� : %d, ��ȣ : %d\n", &chulsu, chulsu); 
    // printf("����� �ּ� : %d, ��ȣ : %d\n", &yonghee, yonghee);
    // printf("�μ��� �ּ� : %d, ��ȣ : %d\n", &minsu, minsu);
    // //mision �ּҴ� &mission���� Ȯ��
    // printf("mission address : %d\n", &mission);
    // printf("spy address : %d\n", &spy);  

   //�迭 
    //    int arr[3] = {5 , 10 , 15};
    //    int * ptr = arr;
    //    for (int i = 0; i < 3; i++)
    //    {
    //        printf("�迭 arr[%d]�� �� : %d\n", i, arr[i]);
    //    }
    //    for (int i = 0; i < 3; i++)
    //    {
    //        printf("������ ptr[%d]�� �� : %d\n", i,  ptr[i]);
    //    }
    //     ptr[0] = 100;
    //     ptr[1] = 200;
    //     ptr[2] = 300;
    //     for (int i = 0; i < 3; i++)
    //    {
    //        //printf("�迭 arr[%d]�� �� : %d\n", i, arr[i]);
    //        printf("�迭 arr[%d]�� �� : %d\n", i, *(arr + i)); //���ٰ� ���� ������� ���´�.
    //    }
    //    for (int i = 0; i < 3; i++)
    //    {
//        //printf("������ ptr[%d]�� �� : %d\n", i,  ptr[i]);
    //        printf("������ ptr[%d]�� �� : %d\n", i, *(ptr + i));
    //    }
    //     //*(arr + i) == arr[i] �Ȱ��� ǥ���̴�.
    //     //arr == arr �迭�� ù��° ���� �ּҿ� ���� == &arr[0] // �ּ�= '&' �� ǥ���Ѵ�
    //     printf(" arr ��ü�� ��  : %d\n",arr);
    //     printf(" arr[0]�� �ּ� : %d\n", &arr[0]);
    //     //
    //     printf(" arr ��ü�� ���� ������ �ּ��� ���� �� : %d \n", *arr);
    //     printf(" arr[0] �� ���� �� : %d\n", *&arr[0]);
    //     //
    //     // *& �� �ƹ��͵� ���� �Ͱ� ����. &�� �ּ��̸�, *�� �� �ּ��� ���̱� ������
    //     // *&�� ���� ��Ⱑ �ȴ�.
    //     printf("arr[0]�� ���� �� : %d\n",*&*&*&*&*&*&*&*&*&*&*&arr[0]);
    //      printf("arr[0]�� ���� �� : %d\n", arr[0]);

    //SWAP
    // int a = 10;
    // int b = 20;
    // printf("a�� �ּ� : %d\n", &a);
    // printf("b�� �ּ� : %d\n", &b);
    // // a �� b�� ���� �ٲ۴�
    // printf("Swap �Լ� �� => a : %d, b = %d\n",a,b);
    // swap(a,b);
    // printf("Swap �Լ� �� => a : %d, b = %d\n",a,b);
    // //���� ���� ���� (Call by Value) -> ���� �����Ѵٴ� �ǹ�
    // //
    // // �ּҰ��� �ѱ��? �޸� ������ �ִ� �ּҰ� ��ü�� �ѱ��.. ö���� ó��
    // printf("(�ּҰ�����)swap �Լ� �� => a : %d, b = %d\n",a,b);
    // swap_addr(&a,&b);
    // printf("(�ּҰ�����)Swap �Լ� �� => a : %d, b = %d\n",a,b);

    //�迭�� ��, arr2 ->�ּ�
    // int arr2[3] = {10, 20, 30};
    //changeArray(arr2);
    // changeArray(&arr2[0]);
    // for( int i = 0; i < 3; i++)
    // {
    //     printf("%d\n", arr2[i]);
    // }
    //
    // scanf ���� &num �� ���� & �� ����ϴ�����

    //������Ʈ(������)
    //
    long startTime = 0; //���� ���� �ð�
    long totalElapsedTime = 0; //�� ��ȭ �ð�
    long prevElapsedTime = 0; //���� ��� �ð�  (�ֱٿ� ���� �� �ð� ����)

    int num;    //�� �� ���׿� ���� ä�������, ����� �Է�
    initData();

    cursor = arrayFish; //cursor[0] .. cursor[1]

    startTime = clock(); //���� �ð��� millisecond (1000���� 1��)������ ��ȯ
    while(1)
    {
        printfFishes();
        printf("�� �� ���׿� ���� �ֽðھ��?");
        scanf("%d", &num);

        // �Է°� üũ
        if (num < 1 || num >6)
        {
            printf("\n�Է°��� �߸��Ǿ����ϴ�.\n");
            continue;
        }

        //�� ��� �ð�
        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
        printf("�� ��� �ð� : %ld ��\n", totalElapsedTime);

        // ���� �� �� �ð� (���������� �� �� �ð�) ���ķ� �帥 �ð�
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("�ֱ� ��� �ð� : %ld ��\n", prevElapsedTime);

        // ������ ���� ���� (����)
        decreaseWater(prevElapsedTime);

        // ����ڰ� �Է��� ���׿� ���� �ִ´�
        // 1. ������ ���� 0�̸�? ���� ���� �ʴ´�
        if(cursor[num - 1] <=0)
        {
            printf("%d �� ������ �̹� �׾����ϴ�.. ���� ���� �ʽ��ϴ�.\n", num);
        }
        // 2. ������ ���� 0 �� �ƴ� ��� ���� �ش� 100�� ���� �ʴ��� üũ
        else if (cursor[num - 1] + 1 <= 100)
        {
            // ���� �ش�.
            printf("%d �� ���׿� ���� �ݴϴ�. \n", num);
            cursor[num - 1] += 1;
        }

        //�������� �� ������ (�������� 20�ʸ��� �ѹ��� ����)
        if (totalElapsedTime / 20 > level - 1)
        {
            // ������
            level++; // level 1 -> lelve 2
            printf(" *** ������ ���� %d �������� %d������ �ö����ϴ�. *** \n", level -1, level);

            //���� ���� : 5
            if (level == 5)
            {
                printf("\n\n�����մϴ�. �ְ� ������ �޼��Ͽ����ϴ�. ������ �����մϴ�.\n");
                exit(0);
            }
        }

        //��� ����Ⱑ �׾����� Ȯ��
        if (checkFishAlive() == 0)
        {
            //����Ⱑ ��� �׾���
            printf(" ��� ����Ⱑ �׾����ϴ�. \n");
            exit(0);
        }
        else
        {
            //�ּ� �Ѹ��� �̻��� ������ �������
            printf("����ִ� ����Ⱑ �ֽ��ϴ�.\n");
        }
        prevElapsedTime = totalElapsedTime;
        // 10�� -> 15�� (5�� : prevElapsedTime ->15��) -> 25�� (10�� )

    }
    
    return 0;
}

// void swap(int a, int b)
// {
//     printf("(swap �Լ� ��) a�� �ּ� : %d\n", &a);
//     printf("(swap �Լ� ��) b�� �ּ� : %d\n", &b);
//     int temp = a;
//     a = b;
//     b = temp;
//     printf("Swap �Լ� �� => a : %d, b = %d\n",a,b);
//
// }
// void swap_addr(int * a, int * b)
// {  
//     int temp = *a;
//     *a = *b;
//     *b = temp;
//     printf("(�ּҰ�����)Swap_addr �Լ� �� => a : %d, b = %d\n", *a, *b);
//
// }     
// void changeArray(int * ptr)
// {
//     ptr[2] = 50;
// }
void initData()
{
    level = 1; //���ӷ��� (1~5)
    for(int i = 0; i < 6; i++)
    {
        arrayFish[i] = 100; //������ �� ���� 0~100
    }
}

void  printfFishes()
{
    printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d�� \n", 1, 2, 3, 4, 5, 6);
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
        arrayFish[i] -= (level * 3 * (int)elapsedTime); // 3�� ���̵� ������ ���� ��
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
            return 1; //��
    }
    return 0;
}