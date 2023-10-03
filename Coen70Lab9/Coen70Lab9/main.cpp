// Gabrielle Tordillos Yousef Zoumot
//  main.cpp
//  Coen70Lab9
//
//  Created by Yousef Zoumot on 3/1/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

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
    
    int count(){return _count;};
private:
    struct BinTree{
        T value;
        BinTree *child, *sibling;
        BinTree(T value, BinTree *child, BinTree *sibling);
        BinTree(BinTree &other);
        static void deletion(BinTree* rec);
    };
public:
    void printV(BinTree* rec);

    void printValues();
private:
    std::vector<BinTree*> trees;
    int _count;
    
    
    
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
        size_t max_order = std::max(lhs.size(), rhs.size());
        lhs.resize(max_order);
        rhs.resize(max_order);
        
        for(int order = 0; order < max_order; order++){
            
            std::vector<BinTree *> tmp;
            if(carry) tmp.push_back(carry);
            if(lhs[order]) tmp.push_back(lhs[order]);
            if(rhs[order]) tmp.push_back(rhs[order]);
            
            
            if(tmp.empty()){
                //Case 0: All trees are NULL (0 + 0 = 0)
                result.push_back(NULL);
            }else if(tmp.size() == 1){
                //Case 1: One tree is not NULL (1 + 0 = 0)
                result.push_back(tmp[0]);
                carry=NULL;
            }else if(tmp.size() == 2){
                //Case 2: Two trees are not NULL (1 + 1 = 0 carry 1)
                //Case 3: 3 trees are not NULL
                carry=mergeTrees(tmp[0], tmp[1] );
                result.push_back(NULL);
            }else if(tmp.size() == 3){
                //Case 4: Three trees are not NULL (1 + 1 with carry = 1 carry 1)
                carry=mergeTrees(tmp[0], tmp[1] );
                result.push_back(tmp[2]);
            }
        }
        if(carry)
            result.push_back(carry);
        
        rhs.clear();
        trees = result;
    }
};

template< class T >
BinomialHeap<T>::BinomialHeap(){
    _count=0;
}

template< class T >
BinomialHeap<T>:: ~BinomialHeap(){
    for(int i=0; i<trees.size(); i++){
        BinTree::deletion(trees[i]);
    }
    while(trees.size()!=0){
        trees.pop_back();
    }
    
}

template< class T >
void BinomialHeap< T >:: push(T value){
    vector< BinTree* > tmp;
    BinTree* temp= new BinTree(value, NULL, NULL);
    tmp.push_back(temp);
    mergeHeaps(trees, tmp);
}

template < class T >
T BinomialHeap<T>:: top() const{
    T result=NULL;
    for(int i=0; i<trees.size() ; i++){
        if(trees[i]!=NULL && (result==NULL || trees[i]<result))
            result=trees[i];
    }
    return result;
    
}

template< class T >
void BinomialHeap<T>:: pop(){
    BinTree* result=NULL;
    int order=0;
    for(int i=0; i<trees.size() ; i++){
        if(trees[i]!=NULL && (result==NULL || trees[i]<result)){
            result=trees[i];
            order=i;
        }
    }
    vector<BinTree* > temp;
    temp.resize(order);
    BinTree* p=result->child;
    while(p !=NULL){
        temp.push_back(p);
        p=p->sibling;
    }
    for(int h=0; h<temp.size(); h++){
        if(temp[h]!=NULL)
            temp[h]->sibling=NULL;
        
    }
    trees[order]=NULL;
    mergeHeaps(trees, temp);
}
template<class T >
void BinomialHeap<T>:: merge(BinomialHeap &other){
    mergeHeaps(&trees, &other.trees);
    _count= _count + other.count();
}

template< class T >
BinomialHeap<T>:: BinTree:: BinTree(BinTree &other){
    value=other.value;
    if(other.child==NULL)
        child=NULL;
    else{
        child=new BinTree(other.child);
    }
    if(other.sibling==NULL){
        sibling=NULL;
    }
    else{
        sibling=new BinTree(other.sibling);
    }
    
    
}

template< class T >
BinomialHeap<T>& BinomialHeap< T >:: operator=(const BinomialHeap<T>& other){
    vector<BinTree* > temp;
    for(int i=0; i<other.trees.size(); i++){
        temp.push_back(BinTree(other.trees[i]));
    }
    trees=temp;
    _count=other.count();
    return *this;
    
}

template< class T>
void BinomialHeap< T >:: BinTree:: deletion( BinTree* rec){
    if(rec==NULL)
        return;
    deletion(rec->sibling);
    deletion(rec->child);
    delete rec;
}

template<class T>
BinomialHeap<T>:: BinTree:: BinTree(T data, BinTree* c, BinTree* s){
    value=data;
    child =c;
    sibling = s;
}

template<class T>
void BinomialHeap<T>:: printV(BinTree* rec){
    if(rec==NULL)
        return;
    printV(rec->child);
    cout<< rec->value << "\n";
    printV(rec->sibling);
}

template<class T>
void BinomialHeap<T>:: printValues(){
    for(int i=0; i<trees.size(); i++){
        printV(trees[i]);
    }
    cout<<"\n";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    BinomialHeap<int> bh1, bh2;
    bh1.push(1);
    bh1.push(2);
    bh1.push(3);
    bh1.push(4);
    bh1.push(5);
    bh1.push(6);
    bh1.push(7);
    bh1.push(8);
    bh1.printValues();
    bh1.pop();
    bh1.printValues();
    bh1.pop();
    bh1.printValues();
    bh1.pop();
    bh1.printValues();
    
    
    
    return 0;
}
