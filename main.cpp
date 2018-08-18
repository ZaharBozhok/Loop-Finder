#include <iostream>
#include "SimpleList.h"
#include "Looping.h"

int main() {
    using namespace std;
    SimpleList<char> list;
    char ch = 0;
    char stopper = 0;
    cout<<"Enter stop sign : ";
    cin>>stopper;
    while(true){
        cin>>ch;
        if(ch == stopper)
            break;
        list.append(ch);
    }
    cout<<isLooping(list);
    return 0;
}
