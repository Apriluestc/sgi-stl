# map

### 前言

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
为什么存在，基本原理，使用场景，和其他技术相比

### 怎么用 or 为什么存在

### map 是什么

- 首先，map 是一个 STL 的关联式容器，其作用是提供了一对一的元素映射
- map 元素是键值对 pair，同时拥有键值和实值
- map 不允许元素键值相同，必须唯一 
- map 所有元素按照元素的键值自动排序

### map 的基本原理

- map 的底层是一颗红黑树，插入、删除、查找的时间复杂度都是 O(logn)

```cpp

template<class _Key, class _Tp, class _Compare, class _Alloc>
class map {
public:
    typedef _Key                  key_type;         // 键值类型
    typedef _Tp                   data_type;        // 实值类型
    typedef _Tp                   mapped_type;
    typedef pair<const _Key, _Tp> value_type;       // 元素类型(键值/实值)
    typedef _Compare              key_compare;      // 键值比较函数

private:
    typedef _Rb_tree<key_type, value_type, 
            _Selectlst<value_type>, key_compare, 
            _Alloc> _Rep_type;                      // 以红黑树表现 (RB_Tree) map
    _Rep_type _M_t;

public:
    typedef typename _Rep_type::iterator iterator;  // map 迭代器
};

```

- pair 键值对的底层实现

```cpp

template<class _T1, class _T2>
struct pair {
    typedef _T1 first_type;
    typedef _T2 second_type;

    _T1 first;
    _T2 second;
    pair()
        :first(_T!())
        ,second(_T2())
    {}
    pair(const _T1& __a, const _T2& __b)
        :first(__a)
        ,second(__b)
    {}

#ifdef __STL_MEMBER_TEMPLATES
    template<class _U1, class _U2>
    pair(const pair<_U1, _U2>& __p)
        :first(__p.first)
        ,second(__p.second)
    {}
#endif
};

```

- 二叉搜索树的元素插入操作：插入新元素，可以从根节点开始，遇到键值比插入元素大
就向左，否则就向右，一直到尾端，即为插入点
- 二叉搜索树的元素删除操作：删除节点 A，当 A 只有一个子节点，就直接将 A 的
子节点连接到 A 的父节点，并将 A 删除，当 A 有两个子节点，将其右子树内的最小节点取代 A

### map 使用场景

- map 适合存储键值对的数据，它是 key 到 value 的映射，可以通过 key 查找 value

### map 和其它关联式容器相比，比如 set、multimap、hash_map 等

- 

### 总结

- map 的结构是键值对 <key, value>，其中 key 唯一
- 键值有序
