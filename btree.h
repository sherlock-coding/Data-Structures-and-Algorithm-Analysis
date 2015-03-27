/*
 * =====================================================================================
 *
 *       Filename:  btree.h
 *
 *    Description:  二叉树
 *
 *        Version:  1.0
 *        Created:  2015年03月27日 19时54分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

template <typename T>
class BTNode 
{
public:
    BTNode():
        data(T()), left(nullptr), right(nullptr)
    {}
    BTNode(const T& initdata):
        data(initdata), left(nullptr), right(nullptr)
    {}

    T data;
    BTNode* left,right;
};

template <typename T>
class BTree 
{
public:
    BTree();
    BTree(const T& initdata);
    ~BTree();

    BTNode<T>* GetRoot() const;
    BTNode<T>* GetLeftChild(const BTNode<T>* p) const;
    BTNode<T>* GetRightChild(const BTNode<T>* p) const;
    int IsEmpty() const;
    void Destroy();
    void PreOrderTraverse(void (*visit)(const T& data)) const;
    void InOrderTraverse(void (*visit)(const T& data)) const;
    void PostOrderTraverse(void (*visit)(const T& data)) const;
    unsigned int GetNodesCount() const;
    unsigned int GetLeafCount() const;
    unsigned int GetDepth() const;
    
private:
    void DestroyNode(BTNode<T> *p);
    void PreOrderTraverse(const BTNode<T> *p, void (*visit)(const T& data)) const;
    void InOrderTraverse(const BTNode<T> *p, void (*visit)(const T& data)) const;
    void PostOrderTraverse(const BTNode<T> *p, void (*visit)(const T& data)) const;
    void GetNodesCount(const BTNode<T> *p, unsigned int &count) const;
    void GetLeafCount(const BTNode<T> *p, unsigned int &count) const;
    void GetDepth(const BTNode<T> *p, unsigned int &depth) const;

    BTNode<T> *m_pRoot;
};

#endif

