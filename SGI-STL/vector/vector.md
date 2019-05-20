# vector

### 前言

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
为什么存在，基本原理，使用场景，和其他技术相比

### 怎么用 or 为什么存在

- [usage]()

### vector 是什么

- vector 维护的是一个连续的线性空间，
相当于动态数组，支持随机读改：O(1)，尾部插入：O(1)，头部删除 O(n)

- vector 维护的是一个连续的线性空间，所以不论其元素类型为何，普通指针都可作为
 vector 的迭代器而满足所有必要条件

- 增加新元素时，如果超出当时的容量，则会扩容至原先的两倍

### vector 底层

- vector 的数据结构

```cpp

template<class T, class Alloc = alloc>
class vector
{
    typedef T value_type;
    typedef value_type* iterator;   //vector迭代器是普通指针
protected:
    iterator start; //目前使用空间的头部
    iterator finish;    //目前使用空间的尾部
    iterator end_of_storage;    //目前可用空间的尾部
};

vector 底层实现的记录

template<class ForwardIt, class Size, class T>
ForwardIt uninitialized_fill_n(ForwardIt first, Size count, const T& value);
函数功能：从 first 开始，将 value 值复制 count 个

template<class ForwardIt, class T>
void uninitialized_fill(ForwardIt first, ForwardIt last, const T& value);
uninitialized_copy 功能区间复制

```

- vector 的动态扩容增长依赖 M_insert_aux 函数

所谓动态增长大小，并不是在原空间之后拼接新空间（因为无法保证原空间后面上有可供配置的空间），
而是以原大小的两倍配置一块较大的空间，然后将原内容拷贝而来，然后再在原内容后面构造新元素，
并释放原先空间，一旦引起空间重新配置，指向原 vector 迭代器就都失效了

- vector 的析构

销毁容器对象就是先销毁已存在的元素，然后释放所有内存，这将在每个包含的元素上调用
`allocator_traits::destroy`，并使其分配器释放由矢量分配的所有存储容量

- vector 的 resize

调整容器的大小，使其包含 n 个元素

如果 n 小于当前容器 size，内容将被缩小到前 n 个元素

如果 n 大于当前容器的 size，则通过在末尾插入尽可能多的元素以达到大小 n 来扩展内容，
如果指定了 val，则新元素将初始化为 val 的副本，否则将进行值初始化

如果 n 也大于当前容器的 capacity，分配的存储空间将自动重新分配

- vector 的 reserve

请求 vector 容量至少足以包含 n 个元素

如果 n 大于当前 vector 容量，则该函数使容器重新分配其存储容量，从而将其容量增加到 n

在所有的情况下，含糊调用不会导致重新分配，并且 vector 容量不受影响

这个对 vector 的大小没影响，也不能改变它的元素

### vector 使用场景

- 

### vector 和 list 相比

- [vector 和 list 的区别与对比]()

### 总结

- vector 扩容只能在尾端进行添加新空间，
  - 配置一块更大的空间
  - 拷贝原内容至新空间
  - 释放原空间（引起迭代器失效）
