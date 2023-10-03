//  Yousef Zoumot   Kelly Wesley
//  main.cpp
//  Coen70Lab8
//
//  Created by Yousef Zoumot on 2/23/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

#include <iostream>
#include <string>//
#include <sstream>//
#include <stack>//


using namespace std;


class ExpTree{
    struct Node{
        int value;
        char op;
        Node *left, *right;
    };
    Node *root;
    void print_inorder(Node* node);
    void print_preorder(Node* node);
    void print_postorder(Node* node);
    int evaluateR(Node * node);
    void destroyT(Node* node);
public:
    ExpTree();
    ~ExpTree();
    void build(string expr);
    int evaluate();
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
    
};

ExpTree:: ExpTree(){
    root=new Node;
    root->left=NULL;
    root->right=NULL;
}
ExpTree:: ~ExpTree(){
    destroyT(root);
}

void ExpTree:: destroyT(Node* node){
    if(node==NULL)
        return;
    destroyT(node->left);
    destroyT(node->right);
    delete node;
}



void ExpTree:: build(string expr){
    istringstream stream(expr);
    string token;
    stack<Node*> nodes;
    while(stream>>token){
        if(token=="+" || token=="-" || token=="/" || token=="*"){
            Node* second= nodes.top();
            nodes.pop();
            Node* first=nodes.top();
            nodes.pop();
            Node* oper= new Node;
            oper->op=token[0];
            oper->left=first;
            oper->right=second;
            nodes.push(oper);
        }
        else{
            int temp=atoi(token.c_str());
            Node* tmp=new Node;
            tmp->value=temp;
            tmp->left=NULL;
            tmp->right=NULL;
            nodes.push(tmp);
        }
    }
    root=nodes.top();
}

int ExpTree:: evaluateR(Node* node){
    if(node->left==NULL && node->right==NULL){
        return node->value;
    }
    if(node->op== '+'){
        return evaluateR(node->left) + evaluateR(node->right);
    }
    if(node->op== '-'){
        return evaluateR(node->left) - evaluateR(node->right);
    }
    if(node->op== '/'){
        return evaluateR(node->left) / evaluateR(node->right);
    }
    if(node->op== '*'){
        return evaluateR(node->left) * evaluateR(node->right);
    }
    return 0;
}

int ExpTree:: evaluate(){
    return evaluateR(root);
    
}

void ExpTree:: printInOrder(){
    print_inorder(root);
}

void ExpTree::print_inorder(Node* node){
    if(node==NULL)
        return;
    print_inorder(node->left);
    if(node->op=='+' || node->op=='-' || node->op=='/' || node->op=='*')
        cout<< node->op<< " ";
    else
        cout<<node->value<< " ";
    print_inorder(node->right);
}

void ExpTree:: printPreOrder(){
    print_preorder(root);
}

void ExpTree::print_preorder(Node* node){
    if(node==NULL)
        return;
    if(node->op=='+' || node->op=='-' || node->op=='/' || node->op=='*')
        cout<< node->op<< " ";
    else
        cout<<node->value<< " ";
    print_preorder(node->left);
    print_preorder(node->right);
}

void ExpTree:: printPostOrder(){
    print_postorder(root);
}

void ExpTree::print_postorder(Node* node){
    if(node==NULL)
        return;
    print_postorder(node->left);
    print_postorder(node->right);
    if(node->op=='+' || node->op=='-' || node->op=='/' || node->op=='*')
        cout<< node->op<< " ";
    else
        cout<<node->value<< " ";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ExpTree t1;
    t1.build("5 3 + 2 5 * 9 3 / - +");
    cout<<t1.evaluate();
    cout<<"\n";
    t1.printInOrder();
    cout<<"\n";
    t1.printPostOrder();
    cout<<"\n";
    t1.printPreOrder();
    cout<<"\n";
    return 0;
}
