#include <iostream>
#include<queue>
using namespace std;

pair<bool, int> solve(Node* root) {
        //base case
        if(root == NULL) {
                pair<bool,int> p = make_pair(true, INT_MIN);
                return p;
        }
        if(root->left == NULL && root->right == NULL)
        {
                //leaf node
                pair<bool,int> p = make_pair(true, root->data);
                return p;
        }

        pair<bool, int> leftAns = solve(root->left);
        pair<bool, int> rightAns = solve(root->right);

        if(leftAns.first == true &&
          rightAns.first == true &&
          root->data > leftAns.second &&
          root->data > rightAns.second) {
                  pair<bool, int> p =  make_pair(true, root->data);
                  return p;
          }
         
          else {
                  pair<bool, int> p =  make_pair(false, root->data);
                  return p;
          }
}

int main() {

        return 0;
}