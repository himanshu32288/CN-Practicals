#include <bits/stdc++.h>
using namespace std;
unordered_map<string, string> mask;
string findclass(string ip)
{
    string first_octet;
    int i = 0;
    while (ip[i] != '.')
      {
       first_octet += ip[i];
        i++;
        }
    int value = stoi(first_octet);
    if (value <= 126)
       return "A";
    if (value == 127)
       return "No class";
    if (value <= 191)
       return "B";
    if (value <= 223)
       return "C";    
    if (value <= 239)
       return "D";
    return "E";
} 

void find__id_host(string ip, string classs)
{
    vector<int> posofdot(3);
    int dot = 0;
    
    for (int i = 0; i < ip.length(); i++)
    { 
      if (ip[i] == '.')
       {
          posofdot[dot] = i;
          dot++;
       }
    }
   if (classs == "A")
     {
       cout << "Network id:" << ip.substr(0, posofdot[0])+".0.0.0";
       cout << "\n";
       cout << "Host id:" << ip.substr(posofdot[0] + 1);
       cout << "\nBroadcast adress:" << ip.substr(0, posofdot[0])+".255.255.255";
       return;
    }
    if (classs == "B")
     {
       cout << "Network id:" << ip.substr(0, posofdot[1])+".0.0";
       cout << "\n";
       cout << "Host id:" << ip.substr(posofdot[1] + 1);
       cout << "\nBroadcast adress:" << ip.substr(0, posofdot[1]) +".255.255";
       return;
    }
   if (classs == "C")
    {
       cout << "Network id:" << ip.substr(0, posofdot[2])+".0";
       cout << "\n";
       cout << "Host id:" << ip.substr(posofdot[2] + 1);
       cout << "\nBroadcast adress:" << ip.substr(0, posofdot[2]) +".255";
    return;
    }
   cout << "In this Class, IP address is not divided into Network and Host ID\n";
} 

int main()
{
mask["A"] = "255.0.0.0";
mask["B"] = "255.255.0.0";
mask["C"] = "255.255.255.0";
string ip;
cout << "Enter IPV4 adress: ";
cin >> ip;
string cla_ss = findclass(ip);
cout << "Class: " << cla_ss;
// if (cla_ss != "A" || cla_ss != "B" || cla_ss != "C")
// exit(0);
cout << "\nDefault mask=" << mask[cla_ss] << "\n";
find__id_host(ip, cla_ss);
}