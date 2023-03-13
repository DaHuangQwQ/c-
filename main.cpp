#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int nx[4] = { 0,-1,0,1 }, ny[4] = { 1,0,-1,0 };//方向数组方便移动
int book[12][12];//book数组标记每一个点是否走过
int ans;//用于判断能否走出
void mazeGenerator(char (*map)[12], int sx, int sy, int ex, int ey)//利用数组指针模拟按引用传递
{
    printf("开始随机生成地图咯！\n");
    srand(time(NULL));//生成随机数种子
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (i == sx && j == sy)//起点标志
                map[i][j] = 'X';
            else if (i == ex && j == ey)//终点标志
                map[i][j] = '$';
            else
            {
                int k;
                k = rand()%2;//k随机生成0和1中的某个数
                if (k)
                    map[i][j] = '.';
                else
                    map[i][j] = '#';
            }
        }
    }
    return;
}
void print(char map[12][12])//打印地图的函数
{
    printf("现在地图的状态是：\n");
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    return;
}
void mazetraverse(char map[][12], int sx, int sy,int ex,int ey)
{
    if (sx==ex && sy==ey)//结束判断条件，已经走到了终点
    {
        print(map);//打印状态
        printf("成功走出迷宫啦！");
        ans = 1;
        return;
    }
    int flag = 0;//用于判断该点周围还能不能继续走
    print(map);//打印状态
    for (int i = 0; i < 4; i++)
    {
        int nex = sx+nx[i], ney = sy+ny[i];//下一个位置的坐标
        if (nex < 0 || nex>11 || ney < 0 || ney>11)//防止越界走出迷宫
            continue;
        if (!book[nex][ney] && map[nex][ney] != '#')//下一个位置没走过且可以走
        {
            flag = 1;
            book[nex][ney] = 1;
            map[sx][sy] = '.';//上一个位置的地图恢复成'.'
            map[nex][ney] = 'X';//现在的位置变成X
            printf("要走下一步啦！\n");
            mazetraverse(map, nex, ney,ex,ey);//搜索下一个位置
            if (ans==1)//若已经找到出口，直接return
                return;
            book[nex][ney] = 0;//book数组恢复没有走过的状态
            map[nex][ney] = '.';//map数组也恢复
            map[sx][sy] = 'X';
        }
    }
    if (ans==1)//已经找到出口，函数结束
        return;
    if (!flag)//该点已经没法继续往下走了
    {
        printf("这个点不能继续走了......\n");
        return;
    }
    return;
}


int main(){
    int sx, sy, ex, ey;
    printf("欢迎进入12X12的迷宫，请输入起始坐标和结束坐标，输入的数字应在0-11之间：\n");
    printf("起始坐标为：");
    scanf("%d%d", &sx, &sy);
    printf("\n结束坐标为:");
    scanf("%d%d", &ex, &ey);
    char map[12][12];
    char(*p)[12];//数组指针指向map
    p = map;
    mazeGenerator(p, sx, sy, ex, ey);
    printf("初始迷宫是这样的：\n");
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
            printf("%c ", map[i][j]);//打印初始的地图
        printf("\n");
    }
    printf("开始走迷宫了哦！\n");
    book[sx][sy] = 1;//起点已经走过了
    mazetraverse(map, sx, sy,ex,ey);
    if (ans == 0)
        printf("走不出迷宫了......");
    return 0;
}