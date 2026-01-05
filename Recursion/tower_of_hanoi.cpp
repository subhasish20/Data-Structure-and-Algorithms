#include<iostream>
using namespace std;

class Tower_of_hanoi
{
    public: 
    void TOH(int n, int A, int B, int C)
    {
        if (n == 0) 
        {
            return;
        }
        TOH(n-1, A, C, B);
        cout<<"\t"<<A<<"\t"<<C<<endl;
        TOH(n-1, B, A, C);
        return ;
    }
};

int main()
{
    Tower_of_hanoi toh;
    toh.TOH(4,1,2,3);

    return 0;
}