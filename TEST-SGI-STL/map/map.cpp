#include <iostream>
#include <map>
using namespace std;

void testOne() {
    map<char, int> arr1;

    arr1['a'] = 10;
    arr1['b'] = 20;
    arr1['c'] = 30;
    arr1['d'] = 40;

    map<char, int> arr2(arr1.begin(), arr1.end());

    //map 的拷贝构造
    map<char, int> arr3(arr2);

    map<char, int>::iterator it;

    for (auto e : arr1) {
        cout << e.first << " " << e.second << endl;
    }

    cout << endl;
    for (size_t i = 0; i < arr2.size(); i++) {
        cout << i << " " << arr2[i] << endl;
    }
}

int main()
{
    testOne();

    /*
     * map 的构造形式及复制
     * */

    std::cout << "Hello world" << std::endl;
    return 0;
}

