#include <stdio.h>

int main(void)
{
    // 다차원 배열 Multidimensional Array
    //int i; 
    //int arr[5];
    // 
    //int arr2[2][5];
    //[0,0] [0,1] [0,2] [0,3] [0,4]      >> j[0,1] = arr2[0][1]
    // arr2[0][0] arr2[0][1] arr2[0][2] arr2[0][3] arr2[0][4] 
    // arr2[1][0] arr2[1][1] arr2[1][2] arr2[1][3] arr2[1][4]
    //int arr[5] = {1 , 2 , 3 , 4, 5};
    // int arr1[2][5] ={
    //     {1 , 2 , 3 , 4, 5},
    //     {1 , 2 , 3 , 4, 5} 
    //     };
    // int arr2[4][2] = { 
    //     {1,2},
    //     {3,4},
    //     {5,6},
    //     {7,8} 
    //     };
    //     for(int i = 0 ; i < 4; i++)
    //     {
    //         for(int j = 0; j < 2; j++)
    //         {
    //             printf("2차원배열 (%d, %d)의 값 : %d\n", i, j, arr2[i][j]);
    //         }
    //         printf("\n");
    //     }
    int arr3[3][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9} 
        },
        {
            {11, 12, 13},
            {14, 15, 16},
            {17, 18, 19} 
        }, 
        {
            {21, 22, 23},
            {24, 25, 26},
            {27, 28, 29}  
        } 
    };
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j <3; j++)
            {
                for(int k = 0; k <3; k++)
                {
                    printf(" 3차원 배열 (%d, %d, %d)의 값: %d\n ",i , j, k, arr3[i][j][k]);
                }
                printf("\n");
            }
             printf("\n");
        }


    




    return 0;
}