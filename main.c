#include <stdio.h>
#include <stdlib.h>

int M,N,num=0;

void overnight(int mat[M][N]);

void Wall(int mat[M][N])
{
    int count[M][N];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            count[i][j] = mat[i][j];
    }
    // TO COUNT MAXIMUM NUMBER OF CONSECUTIVELY INFECTED HOUSES IN A ROW
    for (int i = 0; i < M; i++)
    {
        for (int j = (N - 2); j >= 0; j--)
        {
            if ((count[i][j] == 1) && (count[i][j + 1] >= 0))
            {
                count[i][j] = count[i][j + 1] + 1;
            }
        }
    }
    // TO COUNT MAXIMUM NUMBER OF CONSECUTIVELY INFECTED HOUSES IN A COLUMN
    for (int j = 0; j < N; j++)
    {
        for (int i = M - 2; i >= 0; i--)
        {
            if ((mat[i][j] == 1) && (mat[i][j + 1] >= 0))
            {
                mat[i][j] = mat[i + 1][j] + 1;
            }
        }
    }
    // GETS THEIR NUMBER OF INFECTED HOUSES -->TOP LEFT OF THE BLOCK
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(mat[i][j]>0){
            //MANAGES CORNER CASES-->BLOCK TOUCHING BOTH BOUNDARIES
            if ((i == 0) && (j == 0))
                mat[i][j] += count[i][j]+1;
            else if ((i == 0) && (j == (N - count[i][j])))
                mat[i][j] += count[i][j]+1;
            else if ((i == (M - mat[i][j])) && (j == (N - count[i][j])))
                mat[i][j] += count[i][j]+1;
            else if ((i == (M - mat[i][j])) && (j == 0))
                mat[i][j] += count[i][j]+1;
            //NORMAL CASES
            else if ((i != 0) && (i != (M - mat[i][j])) && (j != 0) && (j != (N - count[i][j])))
            {
                mat[i][j] += count[i][j];
                mat[i][j] *= 2;
                mat[i][j] +=4;
            }
            //MANAGES THOSE CASES IN WHICH BLOCK TOUCHES ONLY ONE BOUNDARY

            else if (((i == 0) || (i == (M - mat[i][j]))))
            {
                mat[i][j] *= 2;
                mat[i][j] += count[i][j]+2;
            }
            else if ((j == 0 || (j == (N - count[i][j]))))
            {
                mat[i][j] += (2 * count[i][j])+2;
            }
            }
        }
    }
    /*
        5 X Y      5 5 5
        A B C  --> 5 5 5
        W R T      5 5 5
    */
    for (int i = 0; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if ((mat[i][j] != 0) && (mat[i][j - 1] != 0))
                mat[i][j] = mat[i][j - 1];
        }
    }
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((mat[i][j] != 0) && (mat[i - 1][j] != 0))
                mat[i][j] = mat[i - 1][j];
        }
    }
    // FINDING THE MAX INFECTED BLOCK
    int maxInfected = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (maxInfected < mat[i][j])
                maxInfected = mat[i][j];
        }
    }
    //     // MARKS THE HOUSES OF BLOCK HAVING MOST PERIMETER AS 2.....IF HOUSE DOESN'T COME UNDER MAX INFECTED BLOCK AND ISN'T MARKED AS 0 OR 1--> IT IS MARKED 1
    int no = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(mat[i][j]>=0)
            {
                if ((mat[i][j] != maxInfected) && (mat[i][j] != 0))
                    mat[i][j] = 1;
                else if (mat[i][j] == maxInfected)
                    mat[i][j] = 2;
            }
            else
            {
                mat[i][j]=-1;
            }
        }
    }
    num++;
    overnight(mat);
}


void overnight(int mat[M][N])
{
    int count = 0;
    for (int a = 0; a < M; a++)
    {
        for (int b = 0; b < N; b++)
        {
            if (mat[a][b] == 1)
            {
                count = 1;
                //To spread the virus horizontally and vertically.
                if (((a + 1) < M) && (mat[a + 1][b] == 0))
                {
                    mat[a + 1][b] = 4;
                }
                if (((a - 1) >= 0) && (mat[a - 1][b] == 0))
                {
                    mat[a - 1][b] = 4;
                }
                if (((b + 1) < N) && (mat[a][b + 1] == 0))
                {
                    mat[a][b + 1] = 4;
                }
                if (((b - 1) >= 0) && (mat[a][b - 1] == 0))
                {
                    mat[a][b - 1] = 4;
                }
                // To spread the virus diagonally
                if (mat[a + 1][b + 1] == 0 && (a+1)<N && (b+1)<M)
                {
                    mat[a + 1][b + 1] = 4;
                }
                if (mat[a + 1][b - 1] == 0&& (a+1)<N && (b-1)>=0)
                {
                    mat[a + 1][b - 1] = 4;
                }
                if (mat[a - 1][b + 1] == 0&& (a-1)>=0 && (b+1)<N)
                {
                    mat[a - 1][b + 1] = 4;
                }
                if (mat[a - 1][b - 1] == 0 && (a-1)>=0 && (b-1)>=0)
                {
                    mat[a - 1][b - 1] = 4;
                }
            }
            // To change the value of the houses to be quarantined
            else if (mat[a][b] == 2)
            {
                mat[a][b] = -1;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] == 4)
            {
                mat[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(mat[i][j]<0)
            {
                mat[i][j]=-1;
            }
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    if (count == 1)
    {
        Wall(mat);
    }
}

int main(void)
{
    printf("Enter the number of rows in the village: ");
    scanf("%d",&M);
    printf("Enter the number of columns in the village: ");
    scanf("%d",&N);
    int mat[M][N];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
           scanf("%d",&mat[i][j]);
        }
    }
    printf("\n");
    Wall(mat);
    int count = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] < 0)
            {
                count++;
            }
        }
    }
    printf("Total number of houses : %d", M*N);
    printf("\n");
    printf("Total number of houses quarantined: %d", count);
    printf("\n");
    printf("Total number of houses saved: %d", (M*N - count));
    printf("\n");
    printf("Number of nights to stop the virus: %d",num);
    return 0;
}
