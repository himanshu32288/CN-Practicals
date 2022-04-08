#include<bits/stdc++.h>
using namespace std; 
string xorem(string input,string key){
    int key_len=key.length(); 
    int n=input.length();
    for(int i=0;i<n-key_len+1;i++){
        for(int j=0;j<key_len;j++){
            input[i+j]=input[i+j]==key[j]?'0':'1';
        } 
        for(;i<n&&input[i]!='1';i++);  
        if(input[i]=='1')
        i--;
    } 
    return input.substr(n-key_len+1);
}
int main(){
  string data,gen;
  cout<<"Enter data:";
  cin>>data;
  cout<<"Enter Key:";
  cin>>gen;
  string temp=data;
  for(int i=0;i<gen.length()-1;i++)
  temp+='0'; 
  string checksum;
  checksum=xorem(temp,gen); 
  cout<<"Encoded data:"; 
  cout<<data+checksum;
  cout<<"\nCheck Sum:";
  cout<<checksum; 
  cout<<"\n-------------------------------------Reciever Side---------------------------------------\n";
  cout<<"Enter data recieved:";
  string msg;
  cin>>msg;  

  string remainder;
  remainder=xorem(msg,gen);  
  for(auto x:remainder)
  if(x!='0'){
      cout<<"Error in communication";
      return 0;
  } 
  cout<<"No Error!\n";
} 
