#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    map<int, int> t;
    t[1] = 4;
    t[1] = 3;
    t[3] = 1;
    for (auto i=t.begin(); i!=t.end(); i++) {
        cout<<i->second<<endl;
    }
    return 0;
}
