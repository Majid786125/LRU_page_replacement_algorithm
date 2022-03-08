#include <iostream>
using namespace std;
void Print(int PL[],int FL[],int Fsize,int Psize)
{
    cout<<endl;
    cout<<"Current Frame is : ";
    for(int i=0;i<Fsize;i++)
    {
        cout<<FL[i];
        cout<<" ";
    }
    cout<<endl;
    for(int i=0;i<Psize;i++)
    {
        cout<<PL[i];
        cout<<" ";
    }
    cout<<endl;
}

bool same(int P[],int size,int V)
{
    bool flag= false;
    for (int i = 0; i < size; ++i) {
        if(V==P[i])
        {
            flag=true;
            break;
        }
    }
    return flag;
}

int Same(int P[],int size,int V)
{
    int Index=0;
    bool flag= false;
    for (int i = 0; i < size; ++i) {
        if(V==P[i])
        {
            flag=true;
            Index=i;
            break;
        }
    }
    return Index;
}

int Fault(int NP, int F)
{
    int count=0;
    int p;
    int PL[NP];
    int FL[F];
    int TFault=0;
    for(int i=0;i<F;i++)
    {
        FL[i]=-1;
    }
    for(int i=0;i<NP;i++) {
        cout << "Enter Page Number : ";
        cin >> p;
        PL[i] = p;
        if (!same(FL, F, p)) {
            if (count < F) {
                FL[count] = p;
                count++;
                TFault++;
            } else {
                count = 0;
                FL[count] = p;
                count++;
                TFault++;

            }

        }
        else {
           // int I= Same(FL,F,p);
            if(count>=F)
            {
                count=0;
            }
            if(FL[count]==p)
            {
                count++;
            }

        }
    }
    Print(PL,FL,F,NP);
    return TFault;
}


int main() {
    int NP,F;
    cout<<"Enter Number Of Pages : ";
    cin>>NP;
    cout<<"Enter Number of Frames : ";
    cin>>F;
    int TF= Fault(NP, F);
    cout<<"Total Number of Fault Pages : "<<TF<<endl;
    cout<<"Total Number of Hits : "<<NP-TF<<endl;
    cout<<"Page Fault Percentage : "<<(TF*100)/NP;
    return 0;
}