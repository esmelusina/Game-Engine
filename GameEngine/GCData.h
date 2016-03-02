#pragma once
#include <vector>
#include <queue>


template<typename T>
struct Handle
{
    int index;
    Handle() : index(-1) { }

    T *operator->()       { return &GCData<T>::at(index); }
    T *operator->() const { return &GCData<T>::at(index); }
    
    operator &int()       { return index; }
    operator  int() const { return index; }
};

// Global Homogoneous Contiguous Data
// POD
template<typename T>
class GCData
{
    int  index;
    bool isVacant;

    static std::queue<int> &getQueue() { static std::queue<int> q; return q; }
public:
    static std::vector<T>  &getData()  { static std::vector<T>  d; return d; }
    
    static T &at(int i)     { return getData()[i]; }

    static void free(int i)
    {
        if (!at(i).isVacant)
        {
            getQueue().push(i);
            at(i).isVacant = true;
            at(i).index = -1;
        }
    }

    static Handle<T> make()
    {
        int i = -1;

        if (getQueue().size() > 0)
        {
            i = getQueue().front();
            getQueue().pop();
        }
        else
        {
            i = getData().size();
            getData().emplace_back();
        }

        at(i).index = i;
        at(i).isVacant = false;
        return Handle<T>{ i };
    }

    int getIndex()   { return index;    }

    bool isValid()
    {
            return index < 0 && !isVacant && index < getData().size();
    }
};





//#pragma once
//#include <vector>
//#include <queue>
//
//template<typename T>
//struct Reference
//{
//    unsigned idx;
//    T &operator*() { return T::at(idx); }
//
//    operator unsigned() const { return idx; }
//    operator unsigned()       { return idx; }
//
//    T *operator->() const { return &T::at(idx); }
//    T *operator->()       { return &T::at(idx); }
//
//    
//};
//
//template<typename T>
//struct Component
//{
//private:
//    unsigned index;
//    bool  isActive;
//    static std::queue<unsigned> &getQueue() { static std::queue<unsigned> q; return q; }
//protected:
//    Component() {}
//public:
//    static std::vector<T>        &getData() { static std::vector<T> d; return d; }
//
//    static T            &at(unsigned i)     { return getData()[i]; }
//    static void          free(unsigned i)   { if (at[i].isActive) { at(i).isActive = false; getQueue().push(i); } }
//    static Reference<T>  make()
//    {
//        int i = -1;
//        if (getQueue().size())
//        {
//            i = getQueue().front();
//            getQueue().pop();
//        }
//        else
//        {
//            i = getData().size();
//            getData().emplace_back();
//        }
//
//        at(i).isActive = true;
//        at(i).index = i;
//
//        return{ (unsigned)i };
//    }
//
//    unsigned getID() const { return index; }
//    bool getActive() const { return isActive; }
//};
//
//
