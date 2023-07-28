// Wellyton Ribeiro Gomes

#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// insere nó na arvore
Node* insertNode(Node* root, int value)
{
    // verifica se a arvore vazia
    if (root == nullptr) {
        return new Node(value);
    }
    else
    {
        if (value <= root->data)
        {
            root->left = insertNode(root->left, value);
        } else
        {
            root->right = insertNode(root->right, value);
        }
        return root;
    }
}

// Percorrer a árvore em ordem (in order) diferente
void InOrder(Node* root) {
    if (root != nullptr) {
        InOrder(root->left);
        std::cout << root->data << " ";
        InOrder(root->right);
    }
}

// Percorrer a árvore em pré-ordem (pre order)
void PreOrder(Node* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

// Percorrer a árvore em pós-ordem (post order)
void PostOrder(Node* root) {
    if (root != nullptr) {
        PostOrder(root->left);
        PostOrder(root->right);
        std::cout << root->data << " ";
    }
}

// Função para encontrar a profundidade da árvore
int treeDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
        return std::max(leftDepth, rightDepth) + 1;
    }
}

int main()
{
    Node* root = nullptr;

    // Incluir nós na árvore
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Retornar a profundidade da árvore
    int depth = treeDepth(root);
    std::cout << "Tree depth: " << depth << std::endl;

    // Percorrer a árvore em ordem
    std::cout << "Tree in order: ";
    InOrder(root);
    std::cout << std::endl;

    // Percorrer a árvore em pré-ordem
    std::cout << "Preorder tree: ";
    PreOrder(root);
    std::cout << std::endl;

    // Percorrer a árvore em pós-ordem
    std::cout << "Post-order tree: ";
    PostOrder(root);
    std::cout << std::endl;

    return 0;
}
