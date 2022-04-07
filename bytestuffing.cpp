#include<bits/stdc++.h> 
using namespace std;  
bool checkFlagorEscape(string input){
   if(input=="01111110"||input=="00011011")
   return true;
  return false;
}
int main() 
{ 
     string data;
     cout<<"Enter data:";
     cin>>data;
     string f="01111110";
     string esc="00011011"; 
     for(int i=0;i<data.length()-7;i+=8){
         if(checkFlagorEscape(data.substr(i,8))){
           data=data.substr(0,i)+"00011011"+data.substr(i); 
           i+=8;
         }
     } 
     cout<<"Stuffed data:"<<data;
     return 0; 
}  
