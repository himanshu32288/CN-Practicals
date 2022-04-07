#include <iostream>

using namespace std;
void srq(int s[],int ack,int packets,int td,int pd,int rtt,int to)
{
    int x=0,delay_for_data=0,delay_for_ack=0;
    for(int i=0;i<packets;i++)
    {
        if(i%2==0)
        {
            ack=1;
        }
        else
            ack=0;
        //delay_for_data=0;
        //delay_for_ack=0;
        if(i==3)
            delay_for_data=delay_for_data+8;
        x=x+td+delay_for_data;
        if(td+delay_for_data<to)
        {
         cout<<"packet "<<i<<" is sent at "<<x<<"sec \n";
         x=x+rtt+delay_for_ack;
         if(rtt+delay_for_ack<to)
          cout<<"Acknowledgment "<<ack<<" is received at "<<x<<" sec\n";
         else
         {
          cout<<"Acknowledgment "<<ack<<" lost\n";
          i=i-1;
          delay_for_data=delay_for_data-16;
         }
        }
        else
        {
          cout<<"packet "<<i<<" lost \n";
          cout<<"Acknowledgment "<<ack<<" lost\n";
          i=i-1;
          delay_for_data=delay_for_data-16;
        }
    }
}
int main()
{
    int packets;
    cout<<"enter the no of packets";
    cin>>packets;
    int a[packets];//array of packets
    int ack=1;
    int td,pd,rtt,to;
    cout<<"Enter transmission & Propagation Delay";
    cin>>td>>pd;
    rtt=2*pd;
    to=2*rtt;
    srq(a,ack,packets,td,pd,rtt,to);
    return 0;
}