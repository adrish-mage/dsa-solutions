#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void printList(list<int> ll){
    list<int>::iterator itr;
    for (itr = ll.begin(); itr != ll.end(); itr++){
        cout << *itr << "->";
    }
    cout << "NULL" <<endl;
}

int main(){
    list<int> ll; // like vector<int>

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);

    printList(ll);
    cout << ll.size() <<endl; 
    cout << "head = " << ll.front() <<endl;
    cout << "tail =" << ll.back();
    return 0;
}