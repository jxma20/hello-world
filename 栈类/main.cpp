#include <iostream>
#include "assert.h"
using namespace std;

template<class T,int SIZE=50>
class Stack{
private:
    T list [SIZE];  //�������ڴ��ջ��Ԫ��
    int top;//ջ��λ��
public:
    Stack();  //���캯������ʼ��ջ
    void push(const T &item); //��Ԫ��ѹ��ջ
    T pop(); //��ջ��Ԫ�ص���ջ
    void clear();  //��ջ���
    const T &peek() const; //����ջ��Ԫ��
    bool isEmpty() const; //�ж��Ƿ�ջ��
    bool isFull() const; //�ж��Ƿ�ջ��
};
template<class T,int SIZE>
Stack<T,SIZE>::Stack():top(-1){} //���캯����ջ����ʼ��Ϊ-1

template<class T,int SIZE>
void Stack<T,SIZE>::push(const T& item){ //��Ԫ��itemѹ��ջ
    assert(!isFull()); //���ջ���ˣ��򱨴�
    list[++top]=item; //����Ԫ��ѹ��ջ��
}

template<class T,int SIZE>
T Stack<T,SIZE>::pop(){    //��ջ��Ԫ�ص���ջ
    assert(!isEmpty());  //���ջΪ�գ��򱨴�
    return list[top--];  //����ջ��Ԫ�أ������䵯��ջ��
}

template<class T,int SIZE>
const T &Stack<T,SIZE>::peek() const { //����ջ��Ԫ��
    assert(!isEmpty());    // ���ջΪ�գ��򱨴�
    return list[top];  // ����ջ��Ԫ��
}

template<class T,int SIZE>
bool Stack<T,SIZE>::isEmpty() const {
    return top==-1;         //����ջ�Ƿ�Ϊ��
}

template<class T,int SIZE>
bool Stack<T,SIZE>::isFull() const {
    return top==SIZE-1;                 //����ջ�Ƿ�Ϊ��
}

template<class T,int SIZE>
void Stack<T,SIZE>::clear(){
    top=-1;                             //���ջ
}
int main()
{
    Stack<int>A;
    Stack<char>B;
    int x,n;
    char ch;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        A.push(x);
    }
    while(!A.isEmpty())
    {
        x=A.pop();
        cout<<x<<" ";
    }
    cout<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        B.push(ch);
    }
    while(!B.isEmpty())
    {
        ch = B.pop();
        cout<<ch<<" ";
    }
    return 0;
}
