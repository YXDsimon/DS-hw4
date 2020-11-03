#include <iostream>
#include <string>
using namespace std;
int main()
{
string b="abcdefg";
for (string::iterator Ib = b.begin(); Ib != b.end(); Ib++)
        {
            cout<<*(b.begin()+1)<<endl;
        }
}