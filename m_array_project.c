#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//10鯵税 辞稽 陥献 朝球 達奄 (唖 朝球 2鯵 達焼辞 限蓄澗依)
// 紫遂切稽 採斗 2鯵税 脊径葵聖 閤焼辞 -> 旭精 朝球 達生檎 朝球 及増奄
// 乞窮 朝球研 限蓄檎 惟績曽戟
// 恥 叔鳶 判呪 硝形爽奄 (旭精側聖 達走 公廃 判呪)
int arrayCard[4][5];    //朝球 走亀 (20舌税 朝球)
int checkCard[4][5];    // 及増縛澗走 食採 溌昔 
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

    int failCount = 0; //叔鳶 判呪

    while (1)
    {
        int select1 = 0;    // 紫遂切亜 識澱廃 坦製 呪
        int select2 = 0;    // 紫遂切亜 識澱廃 砧腰属 呪

        printCards();       //朝球 是帖 窒径
        printfQuestion();   //庚薦 窒径 (朝球 走亀)
        printf("及増聖 朝球研 2鯵 壱牽室推 : ");
        scanf("%d %d", &select1, &select2);

        if(select1 == select2) //旭精 朝球 識澱獣 巷反
            continue;
        
        
        // 疎妊拭 背雁馬澗 朝球研 及増嬢 左壱 旭精走 溌昔
        // 舛呪 疎妊研 (x,y)稽 痕発
        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);

        // 旭精 朝球昔 井酔
        if ((checkCard[firstSelect_x][firstSelect_y] == 0 
            && checkCard[secondSelect_x][secondSelect_y] == 0)
            &&
            (arrayCard[firstSelect_x][firstSelect_y] 
            == arrayCard[secondSelect_x][secondSelect_y]))
         // 砧 硝督昏戚 旭精走
         {
             printf("\n\n 限紹柔艦陥 : %s 降胃 \n\n", strCard[arrayCard[firstSelect_x][firstSelect_y]]);
             checkCard[firstSelect_x][firstSelect_y] = 1;
             checkCard[secondSelect_x][secondSelect_y] = 1;
         }
         // 陥献 硝督昏昔 井酔
         else
         {
             printf("\n\n 堂携暗蟹, 戚耕 及増微 朝球脊艦陥. \n");
             printf("%d : %s\n", select1, strCard[arrayCard[firstSelect_x][firstSelect_y]]);
             printf("%d : %s\n", select2, strCard[arrayCard[secondSelect_x][secondSelect_y]]);
             printf("\n\n");

             failCount++;
         }
        
        // 乞窮 朝球研 達紹澗走 食採, 1 : 凧 , 0 : 暗憎
        if (foundAllCard() == 1)
        {
            printf(" \n\n 乞窮朝球研 設 達紹柔艦陥. \n");
            printf("走榎猿走 恥 %d腰 叔呪 馬心柔艦陥.\n",failCount);
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
    strCard[0] = "据周戚";
    strCard[1] = "悪焼走";
    strCard[2] = "坪晦軒";
    strCard[3] = "展繕";
    strCard[4] = "馬原";

    strCard[5] = "神軒";
    strCard[6] = "壱丞戚";
    strCard[7] = "硲櫛戚";
    strCard[8] = "紫切";
    strCard[9] = "奄鍵";

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

//疎妊拭辞 朔 因娃 達奄
int getEmptyPosition() //鋼差拙穣聖 匝戚奄是背 int莫 企重 姥繕端 紫遂拝呪 赤製.
{
        //けけけけけ 0  1  2  3  4  ->5稽 蟹勧陥檎 0 0 0 0 0
        //けけけけけ 5  6  7  8  9  -> 1 1 1 1 1
        //けけけけけ 10 11 12 13 14  -> 2 2 2 2 2
        //けけけけけ 15 16 17 18 19 -> 3 3 3 3 3
    while(1)
    {
        int randPos = rand() % 20; //0~19 紫戚税 収切 鋼発
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
        // 19 -> 19 / 5 = 交精 3, 蟹袴走 4
    return y % 5;   // y研 5稽 蟹勧 蟹袴走 葵
}

void printCards() 
{
    printf("\n============== 溌昔馬奄遂 =================\n");
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
    printf("\n\n(庚薦)\n");
    int seq = 0;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            // 朝球研 及増嬢辞 舛岩聖 限宙生檎 '朝球 収切'
            if(checkCard[i][j] != 0)
            {
                printf("%8s", strCard[arrayCard[i][j]]);
            }
            // 焼送 及増走 公梅生檎 (舛岩聖 公限縛生檎) 急檎 -> 是帖研 蟹展鎧澗 収切
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
    return 1; // 乞砧 陥 達製
}