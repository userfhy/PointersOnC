/********************************************************* 
********************贪吃蛇（难道可选）******************** 
**************制作者：Xu Lizi      日期：2012/12/31******** 
********************部分函数有借鉴************************ 
**********************************************************/  
#include<stdio.h>  
#include<conio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<time.h>  
  
  
int snakey[100]={5,4,3,2,1};     /*定义蛇的横坐标*/  
int snakex[100]={1,1,1,1,1};     /*定义蛇的纵坐标，蛇头起始位置为（5，1）*/  
int life=0;    /*定义蛇的生命，0表示存活，1表示死亡*/  
int lenght=5;      /*定义蛇的长度，初始为5节*/  
  
  
char map[12][24]={"***********************",   /*y*/  
                  "*                     *",  
                  "*                     *",  
                  "*                     *",  
                  "*                     *",  
                  "*                     *",  
                  "*                     *",  
                  "*                     *",  
                  "*                     *",  
                  "*                     *",  
                  "*                     *",  
         /*x*/    "***********************"};  
  
  
void put_money(int i,int j)       /*放钱函数，使用随机数，随机出现食物*/  
{  
     int x=0,y=0;  
     srand(time(NULL));  
     while ( (map[y][x]==003) || (map[y][x]==002) || (map[y][x]=='*') || ((x==i)&&(y==j)) )  
     {  
           x=rand()%21+1;  
           y=rand()%10+1;  
     }  
     map[y][x]='$';  
     return;  
}  
  
  
void output()        /*输出*/  
{  
    system("cls");  
    int i,j;  
    for(i=0; i<12; i++)  
    {  
          for(j=0; j<23; j++) printf("%c", map[i][j]);  
          printf("\n");  
    }  
    return;  
}  
  
  
void gameover()        /*游戏结束*/  
{  
     life=1;  
     printf("笨蛋，输了吧!!!\n");  
     return;  
}  
  
  
void turn_up()       /*向上移动*/  
{  
     system("cls");  
     int i;  
     if ( (snakex[0]==1) || (map[snakex[0]-1][snakey[0]]==003) ) gameover(); else {  
     if (map[snakex[0]-1][snakey[0]]=='$')  
     {  
           put_money( snakey[0], snakex[0]-1 );  
           lenght++;  
           map[snakex[lenght-1]][snakey[lenght-1]]=003;  
     }  
     for(i=lenght; i>0; i--)  
     {  
          snakex[i]=snakex[i-1];  
          snakey[i]=snakey[i-1];  
     }  
     map[snakex[lenght]][snakey[lenght]]=' ';  
     snakex[0]--;  
     for(i=lenght-1; i>0; i--) map[snakex[i]][snakey[i]]=003;  
     map[snakex[0]][snakey[0]]=002;  
     output();  
     }  
     return;  
}  
  
  
void turn_down()         /*向下*/  
{  
     system("cls");  
     int i;  
     if ( (snakex[0]==10) || (map[snakex[0]+1][snakey[0]]==003) ) gameover();else {  
     if (map[snakex[0]+1][snakey[0]]=='$')  
     {  
           put_money(snakey[0],snakex[0]+1);  
           lenght++;  
           map[snakex[lenght-1]][snakey[lenght-1]]=003;  
     }  
     for(i=lenght; i>0; i--)  
     {  
          snakex[i]=snakex[i-1];  
          snakey[i]=snakey[i-1];  
     }  
     snakex[0]++;  
     map[snakex[lenght]][snakey[lenght]]=' ';  
     for(i=lenght-1; i>0; i--) map[snakex[i]][snakey[i]]=003;  
     map[snakex[0]][snakey[0]]=002;  
     output();  
     }  
     return;  
}  
  
  
void turn_left()     /*向左*/  
{  
     system("cls");  
     int i;  
     if ( (snakey[0]==1) || (map[snakex[0]][snakey[0]-1]==003) ) gameover();else {  
     if (map[snakex[0]][snakey[0]-1]=='$')  
     {  
           put_money(snakey[0]-1,snakex[0]);  
           lenght++;  
           map[snakex[lenght-1]][snakey[lenght-1]]=003;  
     }  
     for(i=lenght; i>0; i--)  
     {  
          snakex[i]=snakex[i-1];  
          snakey[i]=snakey[i-1];  
     }  
     map[snakex[lenght]][snakey[lenght]]=' ';  
     snakey[0]--;  
     for(i=lenght-1; i>0; i--) map[snakex[i]][snakey[i]]=003;  
     map[snakex[0]][snakey[0]]=002;  
     output();  
     }  
     return;  
}  
  
  
void turn_right()        /*向右*/  
{  
     system("cls");  
     int i;  
     if ( (snakey[0]==21) || (map[snakex[0]][snakey[0]+1]==003) ) gameover();else {  
     if (map[snakex[0]][snakey[0]+1]=='$')  
     {  
           put_money(snakey[0]+1,snakex[0]);  
           lenght++;  
           map[snakex[lenght-1]][snakey[lenght-1]]=003;  
     }  
     for(i=lenght; i>0; i--)  
     {  
          snakex[i]=snakex[i-1];  
          snakey[i]=snakey[i-1];  
     }  
     map[snakex[lenght]][snakey[lenght]]=' ';  
     snakey[0]++;  
     for(i=lenght-1; i>0; i--) map[snakex[i]][snakey[i]]=003;  
     map[snakex[0]][snakey[0]]=002;  
     output();  
     }  
     return;  
}  
  
  
int main()  
{  
    int i,timeover,hard;  
    long start;  
    char name , direcation;  
  
  
    printf("\n    向上移动：W  ；向下移动：S ; 向左移动：A ； 向右移动：D \n");  
    printf("\t请选择难度（数字）\n\t分1~5级,分别代表\n\t1难,2中上,3中,4中下5,易：\n");  
    scanf("%d",&hard);  
    system("cls");  
  
  
    for(i=1;i<5;i++) map[1][i]=003;      /*输出蛇身*/  
    map[1][5]=002;      /*输出蛇头*/  
  
  
    put_money(0,0);  
    output();  
  
  
    while(life!=1)    /*当蛇死亡时结束循环*/  
    {  
        /*让蛇自动运行的函数******有借鉴*/  
        timeover=1;  
        start=clock();  
        while((timeover=(clock()-start<=hard*100))&&!kbhit());        //难度设定  
        if(timeover)  
        {  
                    direcation=getch();  
        }  
        /*让蛇自动运行的函数******有借鉴*/  
  
  
  
  
        switch(direcation)  
        {  
               case 'w':turn_up();break;  
               case 's':turn_down();break;  
               case 'a':turn_left();break;  
               case 'd':turn_right();break;  
        }  
    }  
    return 0;  
}  
