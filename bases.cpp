#include <iostream>
#include <string>

using namespace std;

string tentobase(int num, int tobase) {
    string numstr = to_string(num);
    int number = 0;
    int factor = 1;
    for (int i = numstr.size() - 1; i >= 0; i--) {
        number += (numstr[i] - '0') * factor;
        factor *= 10;
    }
    string s;
    char digit;
    while (number > 0) {
        digit = (number % tobase) + '0';
        number /= tobase;
        s = digit + s;
    }
    return s;
}
    

int main() {
    string result = tentobase(11,2);
    cout << result << endl;
    return 0;
}
