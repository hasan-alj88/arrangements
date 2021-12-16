#include <iostream>
#include "cmake-build-debug/tools.h"
#include "cmake-build-debug/permutation.h"
using namespace std;
int main() {
    arrangement::permutation p=arrangement::permutation::random(7);
    arrangement::permutation q=arrangement::permutation::random(7);
    cout << "p   = " << tools::to_sting(p.arrangement())<< endl;
    cout << "q   = " << tools::to_sting(q.arrangement())<< endl;
    cout << "p+q = " << tools::to_sting((p+q).arrangement())<< endl;
    cout << "p-q = " << tools::to_sting((p-q).arrangement())<< endl;
    arrangement::permutation r = p.inv();
    r = p + r;
    cout << "p+p.inv = " << tools::to_sting(r.arrangement())<< endl;
    return 0;
}
