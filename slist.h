/*
 * =====================================================================================
 *
 *       Filename:  slist.h
 *
 *    Description:  单链表
 *
 *        Version:  1.0
 *        Created:  2015年03月19日 19时37分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  sherlock-coding 
 *   Organization:  njust
 *
 * =====================================================================================
 */

#ifndef _SINGLE_LIST_H_
#define _SINGLE_LIST_H_

template <typename T>
class Node {
public:       
    Node():data(T()), next(nullptr){}
    Node(const T &initdata):data(initdata), next(nullptr) {}
    Node(const T &initdata, Node<T> *pNode):data(initdata), next(nullptr) {}
    ~Node() {}

    T data;
    Node<T> *next;
};

template <typename T>
class SList {
public:
    SList();
    SList(const T& initdata);
    ~SList();
    
    int      IsEmpty();
    int      GetCount() const;
    T&       GetTail();
    const T& GetTail() const;
    T&       GetHead();
    const T& GetHead() const;
    T&       GetAt(const int pos);
    const T& GetAt(const int pos) const;
    void     SetAt(const int pos, const T& data);
    int      Find(const T& data);

    int      AddHead(const T& data);
    int      AddTail(const T& data);
    int      InsertBefore(const T& data, const int pos);
    int      InsertAfter(const T& data, const int pos);
    void     RemoveAt(const int pos, T& ret);
    void     RemoveHead(T& ret);
    void     RemoveTail(T& ret);
    void     RemoveAll();

protected:
    int     m_nCount;
    Node<T> *m_pNodeHead;
};

#endif

