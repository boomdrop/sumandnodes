#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *right;
    node *left;
    node(int d){
        data=d;
        right=NULL;
        left=NULL;
    }
};
node *buildtree(){
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node *root=new node(d);
    root->left=buildtree();
    root->right=buildtree();

    return root;

}
void printPre(node *root){
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<< " ";
    printPre(root->left);
    printPre(root->right);
}
void printIn(node *root){
    if(root==NULL)
    {
        return;
    }
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}
void printPo(node *root){
    if(root==NULL)
    {
        return;
    }
    printPo(root->left);
    printPo(root->right);
    cout<<root->data<<" ";
}
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *f=q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }    
    }
}
int main() {
    node *root=buildtree();
    printPre(root);
    cout<<endl;
    printIn(root);
    cout<<endl;
    printPo(root);
    cout<<endl;
    bfs(root);
    return 0;
}
