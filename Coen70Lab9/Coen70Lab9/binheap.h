#pragma once
#include <vector>
#include <iostream>

template<typename T>
class BinomialHeap{
public:
    BinomialHeap();
    ~BinomialHeap();
    
    BinomialHeap& operator=(const BinomialHeap&);
    
    void push(T value);
    
    T top() const;
    void pop();
    
    void merge(BinomialHeap &other);
    
    int count();
private:
    struct BinTree{
        T value;
        BinTree *child, *sibling;
        BinTree(T value, BinTree *child, BinTree *sibling);
    };
    
    BinTree* mergeTrees(BinTree *lhs, BinTree *rhs){
        if(lhs == NULL)
            return rhs;
        if(rhs == NULL)
            return lhs;
        
        if(rhs->value < lhs->value)
            std::swap(lhs, rhs);
        
        rhs->sibling = lhs->child;
        lhs->child = rhs;
        return lhs;
    }
    
    void mergeHeaps(std::vector<BinTree*> &lhs, std::vector<BinTree*> &rhs){
        std::vector<BinTree *> result;
        BinTree *carry = NULL;
        int max_order = std::max(lhs.size(), rhs.size());
        lhs.resize(max_order);
        rhs.resize(max_order);
        
        for(int order = 0; order < max_order; order++){
            
            std::vector<BinTree *> tmp;
            if(carry) tmp.push_back(carry);
            if(trees[order]) tmp.push_back(trees[order]);
            if(rhs[order]) tmp.push_back(rhs[order]);
            
            
            if(tmp.empty()){
                //Case 0: All trees are NULL (0 + 0 = 0)
            }else if(tmp.size() == 1){
                //Case 1: One tree is not NULL (1 + 0 = 0)
            }else if(tmp.size() == 2){
                //Case 2: Two trees are not NULL (1 + 1 = 0 carry 1)
                //Case 3: 3 trees are not NULL
            }else if(tmp.size() == 3){
                //Case 4: Three trees are not NULL (1 + 1 with carry = 1 carry 1)
            }
        }
        if(carry)
            result.push_back(carry);
        
        rhs.clear();
        trees = result;
    }
    
    std::vector<BinTree*> trees;
    int _count;
};