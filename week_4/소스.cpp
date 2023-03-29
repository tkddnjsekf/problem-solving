#include <iostream>
using namespace std;

// ���� Ʈ�� ��� Ŭ���� ����
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    // ������
    TreeNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// ���� Ʈ�� Ŭ���� ����
class BinaryTree {
public:
    TreeNode* root;

    // ������
    BinaryTree() {
        root = nullptr;
    }

    // ��� �߰� �Լ�
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

    // ���� ��ȸ(preorder traversal) �Լ�
    void preorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->value << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    // ���� ��ȸ(inorder traversal) �Լ�
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->value << " ";
        inorderTraversal(node->right);
    }

    // ���� ��ȸ(postorder traversal) �Լ�
    void postorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->value << " ";
    }
};

// �׽�Ʈ �ڵ�
int main() {
    BinaryTree bt;

    bt.addNode(4);
    bt.addNode(2);
    bt.addNode(1);
    bt.addNode(3);
    bt.addNode(6);
    bt.addNode(5);
    bt.addNode(7);

    cout << "���� ��ȸ: ";
    bt.preorderTraversal(bt.root);
    cout << endl;

    cout << "���� ��ȸ: ";
    bt.inorderTraversal(bt.root);
    cout << endl;

    cout << "���� ��ȸ: ";
    bt.postorderTraversal(bt.root);
    cout << endl;

    return 0;
}
