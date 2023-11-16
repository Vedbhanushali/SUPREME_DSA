#include <iostream>
#include<queue>
#include<limits.h>
using namespace std;

class Node {
        public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
                this->data = data;
                this->left = NULL;
                this->right = NULL;
        }
};

class NodeData {
	public:
	int size;
	int minVal;
	int maxVal;
	bool validBST;

	NodeData() {
		
	}
	NodeData(int size, int max, int min, bool valid) {
		this->size = size;
		minVal = min;
		maxVal = max;
		validBST = valid;
	}

};


Node* insertIntoBST(Node* root, int data) {

        if(root == NULL) {
                //this is the first node we have to create
                root = new Node(data);
                return root;
        }

        //no the first node 

        if(root-> data > data) {
                //insert in left
                root->left = insertIntoBST(root->left, data);
        }
        else {
                //insert into right
                root->right = insertIntoBST(root->right, data);
        }
        return root;
}

void takeInput(Node* &root) {
        int data;
        cin >> data;

        while(data != -1) {
                root = insertIntoBST(root, data);
                cin >> data;
        }
}
void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
		
		
	}
}

void preOrderTraversal(Node* root) {
	//NLR
	if(root == NULL)
		return;

	cout << root->data << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) {
	//LNR
	if(root == NULL)
		return;

	inOrderTraversal(root->left);
	cout << root->data << " ";
	inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	//LRN
	if(root == NULL)
		return;

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data << " ";
}

//assuming there are only unique values in tree
Node* findNodeInBST(Node* root, int target) {
	///base case
	if(root == NULL) {
		return NULL;
	}

	if(root->data == target) 
		return root;
//assuming there are only unique values in tree
	// Node* leftAns = false;
	// Node* rightAns = false;
	
	if(target > root->data) {
		//right subtree me search karo
		return findNodeInBST(root->right,  target);
	}
	else {
		return findNodeInBST(root->left,  target);
	}
}

int minVal(Node* root) {
	Node* temp = root;
	if(temp == NULL) {
		return -1;
	}

	while(temp -> left != NULL) {
		temp = temp ->left;
	}
	return temp -> data;
}

int maxVal(Node* root) {
	Node* temp = root;
	if(temp == NULL) {
		return -1;
	}

	while(temp -> right != NULL) {
		temp = temp ->right;
	}
	return temp -> data;
}

Node* deleteNodeInBST(Node* root, int target) {
	
	//base cae
	if(root == NULL ) {
		return NULL;
	}
//cout << "Request recieved for " >> root->data << " with target" << target << endl;
	if(root->data == target) {
		//isi ko delete krna h 
		//4 cases 
		if(root->left == NULL && root->right == NULL) {
			//leaf node
			//delete root;
			return NULL;
		}
		else if(root->left == NULL && root->right != NULL) {
			Node* child = root->right;
			//delete root;
			return child;
		}
		else if(root->left != NULL && root->right == NULL) {
			Node* child  = root->left;
			//delete root;
			return child;
		}
		else {
			//both child
			//find inorder predecessor inb left subtree
			int inorderPre = maxVal(root->left);
			//replace root->data value with inorder predecessor
			root->data = inorderPre;
			//delete inorder predecessor from left subtree
			root->left = deleteNodeInBST(root->left,inorderPre);
			return root;
			
		}
		
	}
	else if(target > root -> data) {
		//right jana chahiye
		root->right =  deleteNodeInBST(root->right, target);
	}
	else if(target < root->data) {
		//left jana chahioye
		root->left = deleteNodeInBST(root->left, target);
	}
	return root;
}


Node* bstUsingInorder(int inorder[], int s, int e) {
	//base case
	if(s > e) {
		return NULL;
	}

	int mid = (s+e)/2;
	int element = inorder[mid];
	Node* root = new Node(element);

	root->left = bstUsingInorder(inorder, s, mid-1);
	root->right = bstUsingInorder(inorder, mid+1, e);

	return root;
	
}


void convertIntoSortedDLL(Node* root, Node* &head) {
	//base case
	if(root == NULL ) {
		return;
	}

	//right subtree into LL
	convertIntoSortedDLL(root->right, head);

	//atach root node
	root->right = head;

	if(head != NULL)
		head -> left = root;

	//update head
	head = root;

	//left subtree linked List
	convertIntoSortedDLL(root->left, head);
}

void printLinkedList(Node* head) {
	Node* temp = head;
    cout << endl;
	while(temp != NULL ) {
		cout << temp -> data << " ";
		temp = temp -> right;
	}
	cout << endl;
}

Node* sortedLinkedListIntoBST(Node* &head, int n) {
	//base case
	if(n <= 0 || head == NULL)
		return NULL;

	Node* leftSubtree = sortedLinkedListIntoBST(head, n/2);

	Node* root = head;
	root->left = leftSubtree;

	head = head -> right;
	
	//right part solve karna h 
	root->right = sortedLinkedListIntoBST(head,n-1-n/2);
	return root;
}


NodeData* findLargestBST(Node* root, int &ans) {
	//base case
	if(root == NULL) {
		NodeData* temp  = new NodeData(0, INT_MIN, INT_MAX, true);
		return temp;
	}

	NodeData* leftKaAns = findLargestBST(root->left, ans);
	NodeData* rightKaAns = findLargestBST(root->right,ans);

	//checking starts here
	NodeData* currNodeKaAns = new NodeData();

	currNodeKaAns->size = leftKaAns->size + rightKaAns->size + 1;
	currNodeKaAns->maxVal = max(root->data, rightKaAns->maxVal);
	currNodeKaAns->minVal = min(root->data, leftKaAns->minVal);

	if(leftKaAns->validBST && rightKaAns->validBST && (root->data > leftKaAns->maxVal && root->data < rightKaAns->minVal) ) {
		currNodeKaAns->validBST = true;
	}
	else {
		currNodeKaAns->validBST = false;
	}

	if(currNodeKaAns->validBST) {
		ans = max(ans, currNodeKaAns->size);
	}
	return currNodeKaAns;
}

int main() {

	// int inorder[] = {1,2,3,4,5,6,7,8,9};
	// int s = 0;
	// int e = 8;

	// Node* root = bstUsingInorder(inorder, s,e);
	// levelOrderTraversal(root);

	// cout << "printing sorted linked list:" << endl;
	// Node* head = NULL;
	// convertIntoSortedDLL(root, head);
	// printLinkedList(head);

	// Node* root1 = NULL;
	// root1 =	sortedLinkedListIntoBST(head, 9);
	// cout << "Doping level order traversal for root 1" << endl;
	// levelOrderTraversal(root1);

	
	  // Node* root = NULL;
	  // cout << "Enter the data for Node " << endl;
	  // takeInput(root);


		Node* root = new Node(50);
		Node* first = new Node(30);
		Node* second = new Node(60);
		Node* third = new Node(5);
		Node* fourth = new Node(20);
		Node* fifth = new Node(45);
		Node* sixth = new Node(70);
		Node* seventh = new Node(65);
		Node* eight = new Node(80);

		root->left = first;
		root->right = second;
		first->left = third;
		first -> right = fourth;
		second->left = fifth;
		second->right = sixth;
		sixth->left = seventh;
		sixth->right= eight;



	
	  cout << "Printing the tree" << endl;
	  levelOrderTraversal(root);


	  int ans = 0;
	  findLargestBST(root,ans);
	  cout << "Largest BSK ka Size:  "<< ans << endl;
		  

	
	  // cout << endl;
	//   cout << "Printing Inorder: " << endl;
	//   inOrderTraversal(root);
	//   cout << endl;
	//   cout << "Printing Preorder: " << endl;
	//   preOrderTraversal(root);
	//   cout << endl;
	//   cout << "Printing Postorder: " << endl;
	//   postOrderTraversal(root);

	// bool ans  = findNodeInBST(root,155);
	// cout << "present or not : " << ans << endl;
	// cout << endl <<" Minimum value: " << minVal(root) << endl;
	// cout << endl << "Maximum value: " << maxVal(root) << endl;

	// root = deleteNodeInBST(root, 100);
	// levelOrderTraversal(root);
	
  return 0;
}