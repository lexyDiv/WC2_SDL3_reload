#include "in.h"

using namespace std;

class Cell;

struct MinData
{
    int index = 0;
    double min = 0;
    int i = 0;
    int k = 0;
    // double dis = 0;
    Cell *cell = nullptr;
};

template <typename T>
class Array
{
public:
    Array();
    ~Array();
    //  T &operator[] (int i) { return this->vec[i]; }
    T getItem(int i);
    T getItem(int i, string str);
    T getItem2(int i);
    T &getItem3(int i);

    void push(T el);
    void unshift(T el);
    T pop();
    T &pop2();
    T shift();
    void changeEl(T item, int i);
    void forEachDel(function<bool(T item, int index, vector<T> vec)> fn);
    void forEach(function<void(T item, int index, vector<T> vec)> fn);
    void forEach(function<void(T item, int index)> fn);
    void forEach(function<void(T item)> fn);
    int indexOf(T el);
    int indexOf2(function<bool(T item)> fn);
    T find(function<bool(T item)> fn);
    void splice(int index, int count, T el);
    void splice(int index, int count);
    void filterSelf(function<bool(T item)> fn);
    void sort(function<bool(T a, T b)> fn);
   // ProtoObj *getMin(function<double(ProtoObj *item)> fn);
   // MinData getMinData(function<double(ProtoObj *item)> fn);
   // ProtoObj *getMAx(function<double(ProtoObj *item)> fn);
   // Array<ProtoObj *> map(function<ProtoObj *(T item)> fn);
    void copy(Array<T> arr);

    void clear();

    int length = 0;

private:
    vector<T> vec;
};

template <typename T>
inline Array<T>::Array()
{
}

template <typename T>
inline Array<T>::~Array()
{
    // delete vec;
    // vec = nullptr;
}

template <typename T>
inline T Array<T>::getItem(int i)
{
    return this->vec.at(i);
}

template <typename T>
inline T Array<T>::getItem(int i, string str)
{
    if (i >= this->vec.size() || i < 0)
    {
        std::cout << str << std::endl;
    }
    return this->vec.at(i);
}

template <typename T>
inline T Array<T>::getItem2(int i)
{
    return this->vec[i];
}

template <typename T>
inline T &Array<T>::getItem3(int i)
{
    return *&this->vec[i];
}

template <typename T>
inline void Array<T>::push(T el)
{
    this->vec.push_back(el);
    this->length = vec.size();
}

template <typename T>
inline void Array<T>::unshift(T el)
{
    this->vec.insert(this->vec.begin(), el);
    this->length = vec.size();
}

template <typename T>
inline T Array<T>::pop()
{
    if (this->length)
    {
        int lastIndex = vec.size() - 1;
        T el = vec.at(lastIndex);
        vec.erase(vec.begin() + lastIndex);
        this->length = vec.size();
        return el;
    }
    return T();
}

template <typename T>
inline T &Array<T>::pop2()
{
    //  if (this->length)
    //  {

    int lastIndex = vec.size() - 1;
    T &el = vec[lastIndex];
    vec.erase(vec.begin() + lastIndex);
    this->length = vec.size();
    return *&el;
    //  }
    //  return T();
}

template <typename T>
inline T Array<T>::shift()
{
    if (this->length)
    {
        int lastIndex = 0;
        T el = vec.at(lastIndex);
        vec.erase(vec.begin() + lastIndex);
        this->length = vec.size();
        return el;
    }
    return T();
}

template <typename T>
inline void Array<T>::changeEl(T item, int i)
{
    this->vec[i] = item;
}

template <typename T>
inline void Array<T>::forEachDel(function<bool(T item, int index, vector<T> vec)> fn)
{
    int size = this->vec.size();
    for (int i = 0; i < size; i++)
    {
        T item = this->vec[i];
        bool del = fn(item, i, this->vec);
        if (del)
        {
            vec.erase(vec.begin() + i);
            i--;
            size--;
        }
    }
    this->length = vec.size();
}

template <typename T>
inline void Array<T>::forEach(function<void(T item, int index, vector<T> vec)> fn)
{

    // for (int i = 0; i < this->vec.size(); i++)
    // {
    //     T item = this->vec[i];
    //     fn(item, i, this->vec);
    // }
    int i = 0;
    for (auto it = this->vec.begin(); it != this->vec.end(); ++it)
    {
        // cout << *it << " ";
        T item = *it;
        fn(item, i, this->vec);
        i++;
    }
}

template <typename T>
inline void Array<T>::forEach(function<void(T item, int index)> fn)
{
    // int size = this->vec.size();
    // for (int i = 0; i < this->vec.size(); i++)
    // {
    //     T item = this->vec[i];
    //     fn(item, i);
    // }
    int i = 0;
    for (auto it = this->vec.begin(); it != this->vec.end(); ++it)
    {
        // cout << *it << " ";

        T item = *it;
        fn(item, i);
        i++;
    }
}

template <typename T>
inline void Array<T>::forEach(function<void(T item)> fn)
{
    // int size = this->vec.size();
    // for (int i = 0; i < this->vec.size(); i++)
    // {
    //     T item = this->vec[i];
    //     fn(item);
    // }

    // int i = 0;
    for (auto it = this->vec.begin(); it != this->vec.end(); ++it)
    {
        // cout << *it << " ";
        // i++;
        T item = *it;
        fn(item);
    }
}

template <typename T>
inline int Array<T>::indexOf(T el)
{
    auto begin = this->vec.begin();
    auto end = this->vec.end();
    auto it = std::find(begin, end, el);
    if (it != end)
    {
        int index = it - begin;
        return index;
    }
    return -1;
}

template <typename T>
inline int Array<T>::indexOf2(function<bool(T item)> fn)
{
    int len = this->vec.size();
    for (int i = 0; i < len; i++)
    {
        T el = this->vec[i];
        if (fn(el))
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
inline T Array<T>::find(function<bool(T item)> fn)
{
    int size = this->vec.size();
    for (int i = 0; i < size; i++)
    {
        T el = this->vec[i];
        if (fn(el))
        {
            return el;
        }
    }
    return nullptr;
}

template <typename T>
inline void Array<T>::splice(int index, int count, T el)
{
    if (count)
    {
        int finI = index + count;
        this->vec.erase(this->vec.begin() + index, this->vec.begin() + finI);
    }
    this->vec.insert(std::next(this->vec.begin(), index), std::move(el));
    this->length = this->vec.size();
}

template <typename T>
inline void Array<T>::splice(int index, int count)
{
    if (count)
    {
        int finI = index + count;
        this->vec.erase(this->vec.begin() + index, this->vec.begin() + finI);
    }
    this->length = this->vec.size();
}

template <typename T>
inline void Array<T>::filterSelf(function<bool(T item)> fn)
{
    this->vec.erase(remove_if(this->vec.begin(), this->vec.end(), [fn](T el)
                              { return fn(el); }),
                    this->vec.end());
    this->length = this->vec.size();
}

template <typename T>
inline void Array<T>::sort(function<bool(T a, T b)> fn)
{
    std::sort(this->vec.begin(), this->vec.end(), [fn](T a, T b)
              { return fn(a, b); });
}

// template <typename T>
// inline ProtoObj *Array<T>::getMin(function<double(ProtoObj *item)> fn)
// {
//     if (this->length)
//     {
//         ProtoObj *el = this->getItem(0);
//         double min = fn(el);
//         for (int i = 1; i < this->length; i++)
//         {
//             ProtoObj *e = this->vec[i];
//             double current = fn(e);
//             if (min > current)
//             {
//                 min = current;
//                 el = e;
//             }
//         }
//         return el;
//     }
//     return nullptr;
// }

// template <typename T>
// inline MinData Array<T>::getMinData(function<double(ProtoObj *item)> fn)
// {
//     MinData md;
//     if (this->length)
//     {
//         md.cell = this->getItem(0);
//         md.min = fn(md.cell);
//         for (int i = 1; i < this->length; i++)
//         {
//             ProtoObj *e = this->vec[i];
//             double current = fn(e);
//             if (md.min > current)
//             {
//                 md.index = i;
//                 md.min = current;
//                 md.cell = e;
//             }
//         }
//     }
//     return md;
// }

// template <typename T>
// inline ProtoObj *Array<T>::getMAx(function<double(ProtoObj *item)> fn)
// {
//     if (this->length)
//     {
//         ProtoObj *el = this->getItem(0);
//         double max = fn(el);
//         for (int i = 1; i < this->length; i++)
//         {
//             ProtoObj *e = this->vec[i];
//             double current = fn(e);
//             if (max < current)
//             {
//                 max = current;
//                 el = e;
//             }
//         }
//         return el;
//     }
//     return nullptr;
// }

// template <typename T>
// inline Array<ProtoObj *> Array<T>::map(function<ProtoObj *(T item)> fn)
// {
//     Array<ProtoObj *> newArr;
//     this->forEach([&newArr, fn](T item)
//                   { newArr.push(fn(item)); });
//     return *&newArr;
// }

template <typename T>
inline void Array<T>::copy(Array<T> arr)
{
    this->vec = arr.vec;
    this->length = this->vec.size();
}

template <typename T>
inline void Array<T>::clear()
{
    this->vec.clear();
    this->length = this->vec.size();
}
