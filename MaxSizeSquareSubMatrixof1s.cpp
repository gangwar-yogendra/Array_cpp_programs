/*

Maximum size square sub-matrix with all 1s.
Given a binary matrix, find out the maximum size square sub-matrix with all 1s. 

*/

#include <iostream>

using namespace std;

#define R 6  
#define C 5  

void print2DMatrix(int arr[R][C])
{
    for (int i = 0;i < R;i++)
    {
        for (int j = 0;j < C;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int min(int a, int b)
{
    int x = (a < b) ? a : b;

    return (x);
}

void maxSizeSquareSubMatrix(int arr[R][C])
{
    int S[R][C];

    int i_Index = 0;
    int j_Index = 0;

    for (int i = 0; i < C; i++)
    {
        S[0][i] = arr[0][i];
    }

    for (int j = 0; j < R; j++)
    {
        S[j][0] = arr[j][0];
    }

    int max_value = S[0][0];

    for (int i = 1;i < R;i++)
    {
        for (int j = 1;j < C;j++)
        {
            if (arr[i][j] == 0)
            {
                S[i][j] = 0;
            }
            else
            {
                S[i][j] = min(S[i][j - 1], min(S[i - 1][j], S[i - 1][j - 1])) + 1;
            }
        }
    }

    print2DMatrix(S);
    cout << "\n";
    
    max_value = S[0][0]; i_Index = 0; j_Index = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (max_value < S[i][j])
            {
                max_value = S[i][j];
                i_Index = i;
                j_Index = j;
            }
        }
    }
    
    for (int i = i_Index; i > i_Index - max_value; i--)
    {
        for (int j = j_Index; j > j_Index - max_value;j--)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
	int arr[R][C] = { {0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}
				  };


    cout << "Given matrix: \n";
    print2DMatrix(arr);
    cout << "\n";

    maxSizeSquareSubMatrix(arr);
    
}
