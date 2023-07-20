Claro! Aqui está uma implementação em C++ de uma árvore binária com métodos recursivos para incluir nós na árvore, percorrer a árvore em ordem (in order), pré-ordem (pre order) e pós-ordem (post order), e retornar a profundidade da árvore:

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

// Função para incluir um nó na árvore
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    } else {
        if (value <= root->data) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }
        return root;
    }
}

// Percorrer a árvore em ordem (in order)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Percorrer a árvore em pré-ordem (pre order)
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Percorrer a árvore em pós-ordem (post order)
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
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

int main() {
    Node* root = nullptr;

    // Incluir nós na árvore
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Percorrer a árvore em ordem
    std::cout << "Árvore em ordem: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Percorrer a árvore em pré-ordem
    std::cout << "Árvore em pré-ordem: ";
    preorderTraversal(root);
    std::cout << std::endl;

    // Percorrer a árvore em pós-ordem
    std::cout << "Árvore em pós-ordem: ";
    postorderTraversal(root);
    std::cout << std::endl;

    // Retornar a profundidade da árvore
    int depth = treeDepth(root);
    std::cout << "Profundidade da árvore: " << depth << std::endl;

    return 0;
}
Neste exemplo, a estrutura Node é a mesma que usamos antes. Os métodos insertNode, inorderTraversal, preorderTraversal e postorderTraversal são implementados de forma recursiva para inserir nós na árvore e percorrer a árvore em ordem, pré-ordem e pós-ordem, respectivamente. A função treeDepth calcula a profundidade da árvore recursivamente.

Espero que isso ajude! Se tiver mais perguntas, fique à vontade para fazer.

--------------------------------------------------

struct  BinaryTreeNode
{
    string dado;
    BinaryTreeNode;
};

struct NaryTreeNode{
    string dado;
    vector<NaryTreeNode*> filhos;
};

//percurso();
//pré ordem; faça algo no nó, vá pro nó a esquerda() 2x e dps vá pro nó a direita()


void preOrdem(BinaryTreeNode* tree) {
    if (tree == nullptr) {
        return;
    }
    cout << tree->dado << " ";
    preOrdem(tree->esquerda);
    preOrdem(tree->direita);
}


void posOrdem(BinaryTreeNode* tree) {
    if (tree == nullptr) {
        return;
    }
    preOrdem(tree->esquerda);
    preOrdem(tree->direita);
    cout << tree->dado << " ";
}

//criar uma árvore binária;
//implementar métodos: in order, pre order e pos order (recursivos);
//metodo parar inserir o nó;
//metodo pra verificar profundidade da árvore;

// sempre iniciar o nó pela esquerda
