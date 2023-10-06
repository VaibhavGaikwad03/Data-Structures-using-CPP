#include <iostream>
#include "Server_Array_ADT.h"
using std::cout;
using std::endl;
#define MAX 5

Array::Array()
{
    Arr = new int[MAX];
    len = 0;
    size = MAX;
}

Array::Array(int size)
{
    Arr = new int[size];
    len = 0;
    this->size = size;
}

Array::~Array()
{
    delete[] Arr;
    Arr = NULL;
    len = 0;
    size = 0;
}

void Array::swap(int &p1, int &p2)
{
    p1 = p1 + p2;
    p2 = p1 - p2;
    p1 = p1 - p2;
}

void Array::display()
{
    int i;

    cout << "\nArray is: \n";
    for (i = 0; i < len; i++)
        cout << Arr[i] << "  ";
    cout << endl;
}

void Array::copy(int *src)
{
    int i;

    for (i = 0; i < len; i++)
        Arr[i] = src[i];
}

void Array::copy(Array &refObj)
{
    int i;

    for (i = 0; i < refObj.len; i++)
        Arr[i] = refObj.Arr[i];
}

int Array::length()
{
    return len;
}

void Array::add_element(int x)
{
    int *temp = NULL;

    if (len == size)
    {
        temp = Arr;
        Arr = new int[size + 5];
        if (Arr == NULL)
            return;
        copy(temp);
        size += 5;
        delete[] temp;
        temp = NULL;
    }
    Arr[len++] = x;
}

void Array::insert_element(int index, int x)
{
    int i;
    int *temp = NULL;

    if (index > len || index < 0)
        return;

    if (len == size)
    {
        temp = Arr;
        Arr = new int[size + 5];
        if (Arr == NULL)
            return;
        copy(temp);
        size += 5;
        delete[] temp;
        temp = NULL;
    }

    for (i = len; i >= index; i--)
        Arr[i + 1] = Arr[i];
    Arr[i + 1] = x;
    len++;
}

void Array::delete_element(int index)
{
    int i;

    if (index < 0 || index >= len)
        return;

    for (i = index; i < len; i++)
        Arr[i] = Arr[i + 1];
    len--;
}

int Array::search_element(int key)
{
    int i;

    for (i = 0; i < len; i++)
    {
        if (Arr[i] == key)
        {
            swap(Arr[i], Arr[0]);
            return i;
        }
    }
    return -1;
}

int Array::get(int index)
{
    if (index < 0 || index >= len)
        return -1;

    return Arr[index];
}

void Array::set(int index, int x)
{
    if (index < 0 || index >= len)
        return;
    Arr[index] = x;
}

int Array::max()
{
    int i;
    int max_element = Arr[0];

    for (i = 1; i < len; i++)
    {
        if (max_element < Arr[i])
            max_element = Arr[i];
    }
    return max_element;
}

int Array::min()
{
    int i;
    int min_element = Arr[0];

    for (i = 1; i < len; i++)
    {
        if (min_element > Arr[i])
            min_element = Arr[i];
    }
    return min_element;
}

int Array::sum()
{
    int i;
    int s = 0;

    for (i = 0; i < len; i++)
        s += Arr[i];
    return s;
}

float Array::avg()
{
    return (float)sum() / len;
}

void Array::reverse()
{
    int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--)
        swap(Arr[i], Arr[j]);
}

void Array::insert_sort(int x)
{
    int *temp = NULL;
    int i = len - 1;

    if (len == size)
    {
        temp = Arr;
        Arr = new int[size + 5];
        if (Arr == NULL)
            return;
        copy(temp);
        size += 5;
        delete[] temp;
        temp = NULL;
    }

    while (x < Arr[i] && i >= 0)
    {
        Arr[i + 1] = Arr[i];
        i--;
    }

    Arr[i + 1] = x;
    len++;
}

bool Array::is_sorted()
{
    int i;

    for (i = 0; i < len - 1; i++)
    {
        if (Arr[i] > Arr[i + 1])
            return false;
    }
    return true;
}

void Array::rearrange()
{
    int i = 0, j = len - 1;

    while (i < j)
    {
        while (Arr[i] < 0)
            i++;
        while (Arr[j] >= 0)
            j--;
        if (i < j)
            swap(Arr[i], Arr[j]);
    }
}

Array *Array::merge(Array &refObj)
{
    int i, j, k;

    Array *p = new Array(len + refObj.len);

    if (p == NULL)
        return NULL;

    for (i = 0, j = 0, k = 0; i < len && j < refObj.len; k++)
    {
        if (Arr[i] < refObj.Arr[j])
            p->Arr[k] = Arr[i++];
        else
            p->Arr[k] = refObj.Arr[j++];
    }

    while (i < len)
        p->Arr[k++] = Arr[i++];
    while (j < refObj.len)
        p->Arr[k++] = refObj.Arr[j++];
    p->len = len + refObj.len;

    return p;
}

Array *Array::union_merge(Array &refObj)
{
    int i, j, k;

    Array *p = new Array(len + refObj.len);

    if (p == NULL)
        return NULL;

    if (is_sorted() && refObj.is_sorted()) // for sorted arrays
    {
        for (i = 0, j = 0, k = 0; i < len && j < refObj.len; k++)
        {
            if (Arr[i] < refObj.Arr[j])
                p->Arr[k] = Arr[i++];
            else if (Arr[i] > refObj.Arr[j])
                p->Arr[k] = refObj.Arr[j++];
            else
            {
                p->Arr[k] = Arr[i];
                i++;
                j++;
            }
        }

        while (i < len)
            p->Arr[k++] = Arr[i++];
        while (j < refObj.len)
            p->Arr[k++] = refObj.Arr[j++];
        p->len = k;
    }
    else // for unsorted arrays
    {
        p->copy(*this);
        p->len = len;

        for (i = 0; i < refObj.len; i++)
        {
            for (j = 0; j < p->len; j++)
            {
                if (refObj.Arr[i] == p->Arr[j])
                    break;
            }
            if (j == p->len)
                p->Arr[p->len++] = refObj.Arr[i];
        }
    }

    return p;
}

Array *Array::intersection(Array &refObj)
{
    int i, j, k;

    Array *p = new Array(len + refObj.len);

    if (p == NULL)
        return NULL;

    for (i = 0, j = 0, k = 0; i < len && j < refObj.len;)
    {
        if (Arr[i] < refObj.Arr[j])
            i++;
        else if (Arr[i] > refObj.Arr[j])
            j++;
        else
        {
            p->Arr[k++] = Arr[i];
            i++;
            j++;
        }
    }

    p->len = k;

    return p;
}

//Array* Array::intersection(Array& refObj)
//{
//    int i, j, k = 0;
//
//    Array* p = new Array(length + refObj.length);
//
//    if (p == NULL)
//        return NULL;
//
//    for (i = 0; i < length; i++)
//    {
//        for (j = 0; j < refObj.length; j++)
//        {
//            if (Arr[i] == refObj.Arr[j])
//                p->Arr[k++] = Arr[i];
//        }
//    }
//
//    p->length = k;
//
//    return p;
//}

Array *Array::difference(Array &refObj)
{
    int i, j, k;

    Array *p = new Array(len + refObj.len);

    if (p == NULL)
        return NULL;

    for (i = 0, j = 0, k = 0; i < len && j < refObj.len;)
    {
        if (Arr[i] < refObj.Arr[j])
            p->Arr[k++] = Arr[i++];
        else if (Arr[i] > refObj.Arr[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    while (i < len)
        p->Arr[k++] = Arr[i++];

    p->len = k;

    return p;
}