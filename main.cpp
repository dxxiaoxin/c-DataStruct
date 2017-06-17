#include <iostream>
#include"myLinkList.h"
using namespace std;

int main()
{
    LinkList ls;
    INO val1,val2,val3,val4;
    val1.id =1,val1.name="Kevin",val2.id=2,val2.name="Cathy",val3.id=3,val3.name="Lucy",val4.id=4,val4.name="Gravin";
    ls.myinsert(val1,0);
    ls.myinsert( val1,1);
    ls.myinsert(val2,2);
    ls.myinsert(val3,3);
    ls.print();
    ls.mydelete(val3);
    ls.print();
    cout << "Hello world!" << endl;
    return 0;
}
