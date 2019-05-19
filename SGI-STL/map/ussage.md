# map usage

- `#include <map>`

- 常用构造

```cpp

template<class _T1, class _T2>
map<_T1, _T2> M;            //默认构造函数，创建一个空的 map
map<_T1, _T2> OBJECT(M)     //拷贝构造函数，创建一个新的 object 作为 M 的副本
map<_T1, _T2> OBJECT = M；  //赋值函数，创建一个新的 object 作为 M 的副本
map<_T1, _T2> OBJECT(M.begin(), end.end()); //区间范围构造

```

- map 添加和删除

```cpp

M.inset(value);             //插入一个 value 的副本，不论成功与否都返回返回新元素位置
M.insert(pos, value);       //具体的某个位置插入 value
M.insert(begin, end);       //范围插入

//对于删除而言，与插入类似

```

- map 查找元素

```cpp

M.count(key);           //返回键值为 key 的元素个数
M.find(key);            //返回第一个键值为 key 的位置，没找到返回 end
M.lower_bround(key);    //返回第一个 键值为 key 的可插入位置，也就是键值 >= key的第一个元素的位置
M.upper_bround(key);    //返回最后一个 键值为 key 的可插入位置，也就是键值 > key的第一个元素的位置

```

- map 迭代器

```cpp

M.begin(); M.end();     //返回一个双向迭代器，指向第一个元素 or 最后一个元素
M.cbegin() M.cend();    //返回一个双向常迭代器，指向第一个元素 or 最后一个元素
M.rbegin() M.rend();    //返回一个逆向迭代器，指向逆向迭代的第一个元素 or 最后一个
M.crbegin() M.crend();  //返回一个逆向常迭代器，指向逆向迭代的第一个元素 or 最后一个

```
