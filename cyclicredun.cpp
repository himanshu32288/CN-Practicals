#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
  cout << "Hello ";
  cout.flush();
  sleep(10);
  cout << "World";
  cout << endl;
   
  return 0;
}