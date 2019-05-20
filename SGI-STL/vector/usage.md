# vector 的使用

- vector 的常用构造函数

```cpp

vector<int> v;  //默认构造函数，创建一个空的 vector
vector<int> OBJECT(v);  //拷贝构造函数，创建一个新的 OBJECT 当作 v 的副本
vector<int> OBJECT = v; //复制构造函数，创建一个新的 OBJECT 当作 v 的副本
vector<int> OBJECT(n, elem);    //创建一个 vector，并使用 n 个 elem 进行初始化
vector<int> OBJECT(begin, end); //范围构造 vector 对象
vector<int> OBJECT = initlist;  //创建一个 vector，并用初始化列表进行初始化

```

- vector 插入和删除

```cpp

v.push_back(elem);  v.pop_back();   //尾部插入元素 elem
v.insert(pos, elem);    //在迭代器位置前面插入一个 elem 副本，并返回新元素的位置
v.insert(pos, n, elem); //插入 n 个副本
v.erase(pos);   //移除迭代器位置的元素，并返回下个元素的位置

```

- vector 元素存取

```cpp

v[index]    //返回索引 index 所指示的下标，不进行范围检查
v.at(index) //返回索引 index 所指示的下标，进行范围检查

```
