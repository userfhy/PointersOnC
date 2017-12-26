#include <stdio.h>
#define SIZE 8
static int board[SIZE][SIZE];
void insertQueue(int row);
void displayQueue();
int checkConflict(int row,int col);
int main(void)
{
    insertQueue(0);
    return 0;
}
//将皇后插入棋盘内
void insertQueue(int row)
{
    int coli;
    for (coli=0;coli<SIZE;coli++)
    {
        board[row][coli] = 1;
        if(checkConflict(row,coli))
        {
            if(row ==(SIZE-1))
            {
                displayQueue();
            } else
            {
                insertQueue(row+1);
            }
        }
        board[row][coli] = 0;
    }
}
//检查新插入皇后是否已现有的皇后有冲突
int checkConflict(int row,int col)
{
    int rowi,coli;
    //检查与左上方的皇后是否有冲突
    if(row>0 && col>0)
    {
        for (rowi=row-1,coli=col-1; rowi>=0 && coli>=0; rowi--,coli--)
        {
            if(board[rowi][coli] == 1)
            {
                return 0;
            }
        }
    }
    //检查与正上方的皇后是否有冲突
    if(row > 0)
    {
        for (rowi=row-1;rowi>=0;rowi--)
        {
            if(board[rowi][col] == 1)
            {
                return 0;
            }
        }
    }
    //检查与右上方的皇后是否有冲突
    if(row>0 && col<(SIZE-1))
    {
        for (rowi=row-1,coli=col+1; rowi>=0 && coli<SIZE; rowi--,coli++)
        {
            if(board[rowi][coli] == 1)
            {
                return 0;
            }
        }
    }
    return 1;
}
//将结果进行打印
void displayQueue()
{
    static count=1;
    printf("%d\n",count++);
    int i,j;
    for (i=0;i<SIZE;i++)
    {
        for (j=0;j<SIZE;j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
