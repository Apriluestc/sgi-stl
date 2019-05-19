#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    map<string, float> stocks;

    stocks["BASF"] = 23.2;
    stocks["VW"] = 23.22;
    stocks["BAS"] = 123.2;
    stocks["Apriluestc"] = 3.2;
    stocks["shiny"] = 563.2;

    for_each(stocks.begin(), stocks.end(), [](const map<string, float>::value_type& elem) {
             cout << elem.first << "|" << elem.second << endl;
             });
    typedef map<string, float> StringFloatMap;
    StringFloatMap m;
    m["BASF"] = 23.2;
    m["VW"] = 23.22;
    m["BAS"] = 123.2;
    m["Apriluestc"] = 3.2;
    m["shiny"] = 563.2;

    //输出元素
    StringFloatMap::iterator pos;
    cout << left;
    for(pos = m.begin(); pos != m.end(); pos++) {
        cout << "m" << setw(12) << pos->first << "price:" << pos->second << endl;
    }
    cout << endl;

    //所有 price 翻一番
    for_each(m.begin(), m.end(), [](map<string, float>::value_type& el) {
             el.second *= 2;
             });
    //输出元素
    for_each(m.begin(), m.end(), [](const map<string, float>::value_type& el) {
             cout << el.first << "|" << el.second << endl;
             });

    cout << endl;

    //修改 VM 键为 Volkswagen 键
    m["BASFA"] = m["BASF"];
    m.erase("BASF");

    for_each(m.begin(), m.end(), [](const map<string, float>::value_type& el) {
             cout << el.first << "|" << el.second << endl;
             });
    std::cout << "Hello world" << std::endl;
    return 0;
}

