//����Ϸ��������������ء��ƴ��������Ϲ�ͬ��ɣ����������Ϊ�鳤��
//��ʼ������Ϊ������ƴ�����ͬ��ɣ������������������ɣ��������޸�bug�����Գ���ʹ������������������������ƹ�����
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
char ch,ch1;    //�����û����������ֵ
int a=0,b=0,c=0,d=0,e=0,f=0,speed=300;
//abcdef g�ֱ���ͷ��β��ʳ������꣬��Ϸ�ٶȱ�������Ϸ���õ�������������������Ϸ�Ľ���ʵʱ����
int k=0;           //��¼�յ�
int z=0;             //��¼�յ�
int h=5;            //��¼�ߵĳ���
int g=0;            //�ж���Ϸ�Ƿ����
int w=0;             //ѡ��ģʽ
using namespace std;

//�������ܣ�������
int main()
{
    char maze[20][40];
    char chushi='0';
    clock_t start,timeover;        //�����ж�ʱ��ı���
    int A[30000]={0},B[30000]={0};//AB��¼�յ�����ꡣ�յ㣺��������ʱ���䣬��ʱ��ͷ������
    mciSendString(TEXT("open \"E:\\new3\\���ٿ��� (���ˤϤ�) - ҹ��.mp3\" alias mysong"), NULL, 0, NULL);
    mciSendString(TEXT("play mysong repeat"), NULL, 0, NULL);
    start1(chushi,maze);
    random(maze); //��������ߺ�ʳ��
    draw(maze);               //������Ϸ����
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
    while(1)                        //�ߵ��ƶ����жϷ������������»��ƻ��棬�жϳԵ�ʳ��ж���Ϸ����
                                       //��JudgeGo Move cls draw,JudgeEat JudgeOver)
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

            JudgeGO(maze,A,B);     //��λ�����ݸ��£�

            while((timeover=(clock()-start<=1))&&!kbhit())
          {
              system("cls");  //����
              draw(maze); //���ƻ���
              cout<<"�ߺ���Ŀǰ�ߵĳ���Ϊ�� "<<h<<endl;
              if(ch=='p'||ch=='P')
                {
                    system("pause");
                    ch =' ';
                }
                Sleep(speed);     //��ʱ
          }
      if(a==0||a==19||b==0||b==39)
      g=1;
      if (g==1)
      break;//�ж���Ϸ����
       }
      system("pause");
   return 0;
}
//��ʼ��Ϸ����
void start1(char chushi,char maze[][40])
{
     //��ʼ��
    readstore(maze,chushi); //��Ϸ�߿�
    draw(maze);                      //���ƻ���
    //��ʼ����
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
    cout<<"��q�ص�ԭ����"<<endl;
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
//�������ܣ�������Ϸ��ʼ��ͼ�߿�
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
        strcpy(maze[4], "*             ̰������Ϸ!        ");
        strcpy(maze[7], "*            ѡ��һ���Ѷ�!        ");
        strcpy(maze[8], "*          ��w��s���л��Ѷ�!        ");
        strcpy(maze[9], "*    ���ո�ʼ��Ϸ,��Ϸ�ڰ�p����ͣ!");
        if(w!=0)
        strcpy(maze[12], "*                ��        ");
        if(w!=1)
        strcpy(maze[13], "*                �е�       ");
        if(w!=2)
        strcpy(maze[14], "*                ����        ");
        if(w!=3)
        strcpy(maze[15], "*                ����        ");
        if(w!=4)
        strcpy(maze[16], "*                �ƽ��        ");
        if(w==0)
        strcpy(maze[12], "*              ->��        ");
        if(w==1)
        strcpy(maze[13], "*              ->�е�       ");
        if(w==2)
        strcpy(maze[14], "*              ->����        ");
        if(w==3)
        strcpy(maze[15], "*              ->����        ");
        if(w==4)
        strcpy(maze[16], "*              ->�ƽ��        ");
      }
      if(w==4&&chushi==' ')
       {

        strcpy(maze[8],"*             ��������΢��");
        strcpy(maze[9],"*        ΢��id:wxid15938547646");
        strcpy(maze[10],"*          ��ֵ10Ԫ�����ƽ��");
        strcpy(maze[11],"*          �����Żݣ���8�۰£�");
        strcpy(maze[11],"*         ��˴���Żݻ����Ķ�?");
        }



}
//�������ܣ���������ߺ�ʵ��
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
//�������ܣ����ƻ���
void draw(char maze[][40])
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<40;j++)
        cout<<maze[i][j];
        cout<<endl;
    }
}
//�ߵ��ƶ�
void JudgeGO(char maze[][40],int A[],int B[])
{
    maze[a][b]='O';
    if(kbhit())        //���������¼�յ�
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
       g=1;                             //����ͷײ�����ӣ�������Ϸ
       maze[--(a)][b]='#';//ִ��ͷ�ĳ�����ǰ��Ĳ���
       fun2(maze,A,B);
    }else
    if(ch1=='a'||ch1=='A')
    {
       if(maze[a][b-1]=='O')
       g=1;                             //����ͷײ�����ӣ�������Ϸ
       maze[a][--(b)]='#';
       fun2(maze,A,B);
    }else
    if(ch1=='s'||ch1=='S')
    {
       if(maze[a+1][b]=='O')
       g=1;                        //����ͷײ�����ӣ�������Ϸ
       maze[++(a)][b]='#';
       fun2(maze,A,B);
    }else
    if(ch1=='d'||ch1=='D')
    {
       if(maze[a][b+1]=='O')
       g=1;                //����ͷײ�����ӣ�������Ϸ
       maze[a][++(b)]='#';
       fun2(maze,A,B);
    }
}
//�������ܣ���β���������
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
     if(A[k]==c&&B[k]==d)//��β����յ���ж�
     {
         if(A[k+1]!=0&&B[k+1]!=0)//�ߵ����һ���յ�������һ��AB�йյ��¼��ô������β������
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
         else //�����һ��û�йյ��¼��ô����β������ͷ���Դ����жϸ�����β������
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
    else//���AB��һ��û�йյ㣬��ô������β������ͷ��
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
    if(a==e&&b==f)//�ж��Ƿ�Ե�ʳ��
    {
        do//����Ե�ʳ����ٴ��������һ��ʳ��
        {
            h++;
            e= rand()%17+1;
            f= rand()%37+1;
        }
        while(maze[e][f]=='#'||maze[e][f]=='O');//���ʳ����������������ô�ٴ����
                maze[e][f]='$';
    }else//�Ե�ʳ����ִ��β����ʧ�Ĳ����������ȼ�һ
       sw(maze,A,B);//β����ʧ�ж�
}
