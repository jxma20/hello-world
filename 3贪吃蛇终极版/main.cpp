//本游戏由马家绪、江宗霖、黄慈瑶、胡迪共同完成，其中马家绪为组长。
//初始化部分为胡迪与黄慈瑶共同完成，操作部分由马家绪完成，江宗霖修改bug，调试程序，使其可正常操作，并做最后的完善工作。
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
void readstore(char maze[][40],char chushi);
void random(char maze[][40]);
void draw(char maze[][40]);
void JudgeGO(char maze[][40],int A[],int B[]);
void sw(char maze[][40],int A[30000],int B[30000]);
void start1(char chushi,char maze[][40]);
void fun1(char maze[][40] ,char chushi);
void fun2(char maze[][40], int A[30000],int B[30000]);
char ch,ch1;    //接收用户键盘输入的值
int a=0,b=0,c=0,d=0,e=0,f=0,speed=300;
//abcdef g分别是头、尾、食物的坐标，游戏速度变量，游戏设置调整变量，它们随这游戏的进行实时更新
int k=0;           //记录拐点
int z=0;             //记录拐点
int h=5;            //记录蛇的长度
int g=0;            //判断游戏是否结束
int w=0;             //选择模式
using namespace std;

//函数功能：主函数
int main()
{
    char maze[20][40];
    char chushi='0';
    clock_t start,timeover;        //用于判断时间的变量
    int A[30000]={0},B[30000]={0};//AB记录拐点的坐标。拐点：蛇在运行时拐弯，此时蛇头的坐标
    mciSendString(TEXT("open \"E:\\new3\\佐藤康夫 (き乃はち) - 夜明.mp3\" alias mysong"), NULL, 0, NULL);
    mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
    start1(chushi,maze);
    random(maze); //随机生成蛇和食物
    draw(maze);               //绘制游戏画面
    if(w==0)
    {
        speed=300;
        mciSendString(TEXT("close mysong"), NULL, 0, NULL);
        mciSendString(TEXT("open \"E:\\new3\\sans. - Toby Fox.mp3\" alias mysong"), NULL, 0, NULL);
        mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
    }
    if(w==1)
    {
        speed= 200;
        mciSendString(TEXT("close mysong"), NULL, 0, NULL);
        mciSendString(TEXT("open \"E:\\new3\\MEGALOVANIA - Toby Fox.mp3\" alias mysong"), NULL, 0, NULL);
        mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
    }
    if(w==2)
    {
        speed =100;
        mciSendString(TEXT("close mysong"), NULL, 0, NULL);
        mciSendString(TEXT("open \"E:\\new3\\Brand X Music - Helmet to Helmet.mp3\" alias mysong"), NULL, 0, NULL);
        mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
    }
    if(w==3||w==4)
    {
        speed =10;
        mciSendString(TEXT("close mysong"), NULL, 0, NULL);
        mciSendString(TEXT("open \"E:\\new3\\Audiomachine - Breath and Life.mp3\" alias mysong"), NULL, 0, NULL);
        mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
    }
    while(1)                        //蛇的移动，判断方向，清屏，重新绘制画面，判断吃到食物，判断游戏结束
                                       //（JudgeGo Move cls draw,JudgeEat JudgeOver)
        {
            if(h>=10&&speed>250)
            speed=250;
            if(h>=15&&speed>200)
            speed=200;
            if(h>=20&&speed>150)
            speed=150;
            if(h>=25&&speed>100)
            speed =100;
            if(h>=30&&speed>10)
            speed  = 10;
            start=clock();

            JudgeGO(maze,A,B);     //蛇位置数据更新：

            while((timeover=(clock()-start<=1))&&!kbhit())
          {
              system("cls");  //清屏
              draw(maze); //绘制画面
              cout<<"芜湖，目前蛇的长度为： "<<h<<endl;
              if(ch=='p'||ch=='P')
                {
                    system("pause");
                    ch =' ';
                }
                Sleep(speed);     //延时
          }
      if(a==0||a==19||b==0||b==39)
      g=1;
      if (g==1)
      break;//判断游戏结束
       }
      system("pause");
   return 0;
}
//初始游戏界面
void start1(char chushi,char maze[][40])
{
     //初始化
    readstore(maze,chushi); //游戏边框
    draw(maze);                      //绘制画面
    //开始操作
    while((chushi=getch()))
  {
    if((chushi=='s'||chushi=='S')&&w!=4)
     {
         w++;
    fun1(maze,chushi);
    }
    if((chushi=='w'||chushi=='W')&&w!=0)
     {
         w--;
     fun1(maze,chushi);
    }
    if(chushi==' '&&w!=4)
    {
    system("cls");
    ch1 = 'd';
    readstore(maze,chushi);
    break;
    }
   if(chushi==' '&&w==4)
    {
    fun1(maze,chushi);
    cout<<"按q回到原界面"<<endl;
    while((chushi=getch()))
 {
     if(chushi=='q'||chushi=='Q')
    {
    fun1(maze,chushi);
    break;
    }
    else
    continue;
}
continue;
    }
   }

}
//函数功能：输入游戏初始地图边框
void readstore(char maze[][40],char chushi)
{
     for(int i=0;i<=19;i++)
        for(int j=0;j<=39;j++)
        if(i==0||i==19||j==0||j==39)
        maze[i][j]='*';
    else
        maze[i][j]=' ';

    if(chushi!=' ')
      {
        strcpy(maze[4], "*             贪吃蛇游戏!        ");
        strcpy(maze[7], "*            选择一个难度!        ");
        strcpy(maze[8], "*          按w与s键切换难度!        ");
        strcpy(maze[9], "*    按空格开始游戏,游戏内按p键暂停!");
        if(w!=0)
        strcpy(maze[12], "*                简单        ");
        if(w!=1)
        strcpy(maze[13], "*                中等       ");
        if(w!=2)
        strcpy(maze[14], "*                困难        ");
        if(w!=3)
        strcpy(maze[15], "*                地狱        ");
        if(w!=4)
        strcpy(maze[16], "*                破解版        ");
        if(w==0)
        strcpy(maze[12], "*              ->简单        ");
        if(w==1)
        strcpy(maze[13], "*              ->中等       ");
        if(w==2)
        strcpy(maze[14], "*              ->困难        ");
        if(w==3)
        strcpy(maze[15], "*              ->地狱        ");
        if(w==4)
        strcpy(maze[16], "*              ->破解版        ");
      }
      if(w==4&&chushi==' ')
       {

        strcpy(maze[8],"*             加制作人微信");
        strcpy(maze[9],"*        微信id:wxid15938547646");
        strcpy(maze[10],"*          充值10元解锁破解版");
        strcpy(maze[11],"*          本月优惠！打8折奥！");
        strcpy(maze[11],"*         如此大的优惠还不心动?");
        }



}
//函数功能：随机生成蛇和实物
void random(char maze[][40])
{
    srand(time(0));
         while(a==0||a==39||b==19||b==0||b-4==19||b-4==0||e==0||e==39||f==0||f==19||b-3==19||b-3==0||b-2==19||b-2==0||
        b-1==19||b-1==0||((e==a)&&(f==b))||((e==a)&&(f==b-1))||((e==a)&&(f==b-2))||((e==a)&&(f==b-3))||((e==a)&&(f==b-4)))
        {
        a= rand()%13+5;
        b= rand()%37+1;
        e= rand()%17+1;
        f= rand()%37+1;

        }
        maze[a][b]='#';
        maze[a][b-1]='O';
        maze[a][b-2]='O';
        maze[a][b-3]='O';
        maze[a][b-4]='O';
        maze[e][f]='$';
        c=a;
        d=b-4;
}
//函数功能：绘制画面
void draw(char maze[][40])
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<40;j++)
        cout<<maze[i][j];
        cout<<endl;
    }
}
//蛇的移动
void JudgeGO(char maze[][40],int A[],int B[])
{
    maze[a][b]='O';
    if(kbhit())        //两个数组记录拐点
    {
       ch=getch();
       if(ch=='w'||ch=='a'||ch=='s'||ch=='d'||ch=='W'||ch=='A'||ch=='S'||ch=='D')
       ch1=ch;
       A[z]=a;
       B[z]=b;
       z++;
    }
    if(ch1=='w'||ch1=='W')
    {
        if(maze[(a-1)][b]=='O')
       g=1;                             //若蛇头撞到身子，结束游戏
       maze[--(a)][b]='#';//执行头的出现在前面的操作
       fun2(maze,A,B);
    }else
    if(ch1=='a'||ch1=='A')
    {
       if(maze[a][b-1]=='O')
       g=1;                             //若蛇头撞到身子，结束游戏
       maze[a][--(b)]='#';
       fun2(maze,A,B);
    }else
    if(ch1=='s'||ch1=='S')
    {
       if(maze[a+1][b]=='O')
       g=1;                        //若蛇头撞到身子，结束游戏
       maze[++(a)][b]='#';
       fun2(maze,A,B);
    }else
    if(ch1=='d'||ch1=='D')
    {
       if(maze[a][b+1]=='O')
       g=1;                //若蛇头撞到身子，结束游戏
       maze[a][++(b)]='#';
       fun2(maze,A,B);
    }
}
//函数功能：蛇尾的坐标更新
void sw(char maze[][40],int A[100],int B[100])
{
    if(A[k]!=0&&B[k]!=0)
   {
    if(A[k]==c&&B[k]<d)
    {maze[c][d]=' ';d=d-1;}
    else
    if(A[k]==c&&B[k]>d)
    {maze[c][d]=' ';d=d+1;}
    else
    if(A[k]>c&&B[k]==d)
    {maze[c][d]=' ';c=c+1;}
    else
    if(A[k]<c&&B[k]==d)
     {maze[c][d]=' ';c=c-1;}
    else
     if(A[k]==c&&B[k]==d)//蛇尾到达拐点的判断
     {
         if(A[k+1]!=0&&B[k+1]!=0)//蛇到达第一个拐点后如果下一个AB有拐点记录那么更新蛇尾的坐标
         {
            maze[c][d]=' ';
            k++;
            if(A[k]==c&&B[k]<d)
            {maze[c][d]=' ';d=d-1;}
            else
            if(A[k]==c&&B[k]>d)
            {maze[c][d]=' ';d=d+1;}
            else
            if(A[k]>c&&B[k]==d)
            {maze[c][d]=' ';c=c+1;}
            else
            if(A[k]<c&&B[k]==d)
            {maze[c][d]=' ';c=c-1;}
         }
         else //如果下一个没有拐点记录那么让蛇尾跟着蛇头，以此来判断更新蛇尾的坐标
         {
         maze[c][d]=' ';
         k++;
         if(a==c&&b>d) d=d+1;
         if(a==c&&b<d) d=d-1;
         if(a<c&&b==d) c=c-1;
         if(a>c&&b==d) c=c+1;
         }
     }
    }
    else//如果AB下一个没有拐点，那么就让蛇尾跟着蛇头走
    {
         maze[c][d]=' ';
         if(a==c&&b>d) d=d+1;
         if(a==c&&b<d) d=d-1;
         if(a<c&&b==d) c=c-1;
         if(a>c&&b==d) c=c+1;
    }
}
void fun1(char maze[][40],char chushi)
{
    system("cls");
    readstore(maze,chushi);
    draw(maze);
}
void fun2(char maze[][40],int A[30000] ,int B[30000])
{
    if(a==e&&b==f)//判断是否吃到食物
    {
        do//如果吃到食物就再次随机生成一个食物
        {
            h++;
            e= rand()%17+1;
            f= rand()%37+1;
        }
        while(maze[e][f]=='#'||maze[e][f]=='O');//如果食物生成在了蛇身，那么再次随机
                maze[e][f]='$';
    }else//吃到食物则不执行尾巴消失的操作，即长度加一
       sw(maze,A,B);//尾巴消失判断
}
