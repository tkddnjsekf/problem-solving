#include <iostream>
using namespace std;

// 이진 트리 노드 클래스 정의
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    // 생성자
    TreeNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// 이진 트리 클래스 정의
class BinaryTree {
public:
    TreeNode* root;

    // 생성자
    BinaryTree() {
        root = nullptr;
    }

    // 노드 추가 함수
    void addNode(int val) {
        TreeNode* newNode = new TreeNode(val);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        TreeNode* current = root;
        while (true) {
            if (val < current->value) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            }
            else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }

    // 전위 순회(preorder traversal) 함수
    void preorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // 중위 순회(inorder traversal) 함수
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->value << " ";
        inorderTraversal(node->right);
    }

    // 후위 순회(postorder traversal) 함수
    void postorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->value << " ";
    }
};

// 테스트 코드
int main() {
    BinaryTree bt;

    bt.addNode(4);
    bt.addNode(2);
    bt.addNode(1);
    bt.addNode(3);
    bt.addNode(6);
    bt.addNode(5);
    bt.addNode(7);

    cout << "전위 순회: ";
    bt.preorderTraversal(bt.root);
    cout << endl;

    cout << "중위 순회: ";
    bt.inorderTraversal(bt.root);
    cout << endl;

    cout << "후위 순회: ";
    bt.postorderTraversal(bt.root);
    cout << endl;

    return 0;
}
