#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HuffmanNode {
    char data;
    unsigned int frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

struct MinHeap {
    unsigned int size;
    unsigned int capacity;
    struct HuffmanNode** array;
};

void encodeCharacter(struct HuffmanNode* root, char character, char encodedMessage[], int* index);
char decodeCharacter(struct HuffmanNode* root, char encodedMessage[], int* index);
void buildHuffmanCodes(struct HuffmanNode* root, char* currentCode, char** huffmanCodes);

struct HuffmanNode* createNode(char data, unsigned int frequency) {
    struct HuffmanNode* newNode = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct HuffmanNode* createMinHeapNode(char data, unsigned int frequency) {
    return createNode(data, frequency);
}

struct MinHeap* createMinHeap(unsigned int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct HuffmanNode*)malloc(capacity * sizeof(struct HuffmanNode));
    return minHeap;
}

void swapMinHeapNodes(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return minHeap->size == 1;
}

struct HuffmanNode* extractMin(struct MinHeap* minHeap) {
    struct HuffmanNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct HuffmanNode* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

struct HuffmanNode* buildHuffmanTree(char data[], unsigned int frequency[], int size) {
    struct HuffmanNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, createMinHeapNode(data[i], frequency[i]));

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createMinHeapNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printHuffmanCodes(struct HuffmanNode* root, char* currentCode, char** huffmanCodes) {
    if (root->left) {
        strcat(currentCode, "0");
        printHuffmanCodes(root->left, currentCode, huffmanCodes);
        currentCode[strlen(currentCode) - 1] = '\0';
    }
    if (root->right) {
        strcat(currentCode, "1");
        printHuffmanCodes(root->right, currentCode, huffmanCodes);
        currentCode[strlen(currentCode) - 1] = '\0';
    }
    if (!root->left && !root->right) {
        printf("%c: %s\n", root->data, currentCode);
        huffmanCodes[root->data] = strdup(currentCode);
    }
}

void encodeMessage(char message[], char encodedMessage[], char* huffmanCodes[]) {
    int len = strlen(message);
    int j = 0;
    for (int i = 0; i < len; i++) {
        char character = message[i];
        char* code = huffmanCodes[character];
        if (code) {
            strcat(encodedMessage, code);
        }
    }
}

char decodeCharacter(struct HuffmanNode* root, char encodedMessage[], int* index) {
    if (root == NULL) {
        return '\0';
    }
    if (root->data != '$') {
        return root->data;
    }
    char bit = encodedMessage[*index];
    (*index)++;
    if (bit == '0') {
        return decodeCharacter(root->left, encodedMessage, index);
    } else {
        return decodeCharacter(root->right, encodedMessage, index);
    }
}

void decodeMessage(struct HuffmanNode* root, char encodedMessage[], char decodedMessage[]) {
    int len = strlen(encodedMessage);
    int i = 0, j = 0;
    while (i < len) {
        char character = decodeCharacter(root, encodedMessage, &i);
        if (character != '\0') {
            decodedMessage[j++] = character;
        }
    }
    decodedMessage[j] = '\0';
}

int main() {
    int numCharacters;
    
    scanf("%d", &numCharacters);
    
    char data[numCharacters];
    unsigned int frequency[numCharacters];
    
    for (int i = 0; i < numCharacters; ++i) {
        scanf(" %c", &data[i]);
        scanf("%u", &frequency[i]);
    }

    struct HuffmanNode* root = buildHuffmanTree(data, frequency, numCharacters);

    char* huffmanCodes[256] = {0};
    char currentCode[256] = {0};
    printHuffmanCodes(root, currentCode, huffmanCodes);

    char message[256];
    
    scanf(" %[^\n]", message);
    
    char encodedMessage[256] = {0};
    encodeMessage(message, encodedMessage, huffmanCodes);
    printf("%s\n", encodedMessage);

    char decodedMessage[256] = {0};
    decodeMessage(root, encodedMessage, decodedMessage);
    printf("%s\n", decodedMessage);

    return 0;
}