#include <iostream>
#include <string>
#include <map>
using namespace std;
#include <algorithm>

int main()
{
    //map 构造，c++11 允许列表初始化
    map<string, double> coll {{"tim", 9.9}, {"struppi", 11.77}};

    //对每个元素的值进行平方
    for_each(coll.begin(), coll.end(), [](pair<const string, double>& elem) {
             elem.second *= elem.second;
             });
    //输出元素
    for_each(coll.begin(), coll.end(), [](const map<string, double>::value_type& elem) {
             cout << elem.first << "|" << elem.second << endl;
             });
    std::cout << "Hello world" << std::endl;
    return 0;
}

