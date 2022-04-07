#include<bits/stdc++.h>
using namespace std;

int main(){
    string input,output;
    cout<<"Enter data to send:"; 
    cin>>input;  
    int c=0; 
   for(int i=0;i<input.length();i++){
       if(input[i]=='1')
       c++;
       else 
       c=0;
       if(c==5){  
           input=input.substr(0,i+1)+"0"+input.substr(i+1); 
           c=0;
       }
   }
    cout<<"data after stuffing: "<<input<<"\n";  
    int u=0;
    for(int i=0;i<input.length();i++){
       if(input[i]=='1')
       c++;
       else 
       c=0;
       if(c==5){  
           input=input.substr(0,i+1)+input.substr(i+2); 
           c=0;  
       }
   } 
   cout<<"data after unstuffing: "<<input; 
}
