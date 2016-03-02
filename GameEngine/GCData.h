#pragma once
#include <vector>
#include <queue>


template<typename T>
struct Handle
{
    int index;
    Handle(int i= -1) : index(i)  { }

    T *operator->()       { return &GCData<T>::at(index); }
    T *operator->() const { return &GCData<T>::at(index); }
    
    operator  int()       { return index; }
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
            at(i).onFree();  // Event to allow child classes to respond
            getQueue().push(i);
            at(i).isVacant = true;
            at(i).index = -1;
        }
    }

    static Handle<T> make()
    {
        int i = -1;

        // Recycle data if anything is free
        if (getQueue().size() > 0)
        {
            i = getQueue().front();
            getQueue().pop();
        }
        else //otherwise we have to allocate new data
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

    virtual void onFree() {}
};