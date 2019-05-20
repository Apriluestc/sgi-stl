#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    vector<string> v;
    
    //把容器元素个数设置为 5 避免重新分配内存
    v.reserve(5);

    //添加元素
    v.push_back("1");
    v.push_back("hello");
    v.insert(v.end(), {"haw", "sdf", "sdf"});

    //输出元素
    copy(v.cbegin(), v.cend(), 
        ostream_iterator<string>(cout, " "));
    cout << endl;
    
    //输出属性
    cout << "max_size" << " " << v.max_size() << endl;
    cout << "size" << " " << v.size() << endl;
    cout << "capacity" << " " << v.capacity() << endl;

    std::cout << "Hello world" << std::endl;
    
    //交换元素的值
    swap(v[1], v[3]);

    //在 sdf 前面插入 !!!
    v.insert(find(v.begin(), v.end(), "!!!"), "sdf");

    //把末尾元素赋值
    v.back() = "1";
    
    //输出元素
    copy(v.cbegin(), v.cend(), ostream_iterator<string>(cout, " "));
    cout << endl;
    return 0;
}
