#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

struct HuffmanNode {
    char data;
    unsigned int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, unsigned int frequency) 
        : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->frequency > right->frequency;
    }
};

void printHuffmanCodes(HuffmanNode* root, string currentCode, unordered_map<char, string>& huffmanCodes) {
    if (root->left) {
        printHuffmanCodes(root->left, currentCode + "0", huffmanCodes);
    }
    if (root->right) {
        printHuffmanCodes(root->right, currentCode + "1", huffmanCodes);
    }
    if (!root->left && !root->right) {
        cout << root->data << ": " << currentCode << endl;
        huffmanCodes[root->data] = currentCode;
    }
}

void encodeMessage(const string& message, string& encodedMessage, const unordered_map<char, string>& huffmanCodes) {
    for (char character : message) {
        encodedMessage += huffmanCodes.at(character);
    }
}

char decodeCharacter(HuffmanNode* root, const string& encodedMessage, int& index) {
    if (!root) {
        return '\0';
    }
    if (!root->left && !root->right) {
        return root->data;
    }
    char bit = encodedMessage[index++];
    if (bit == '0') {
        return decodeCharacter(root->left, encodedMessage, index);
    } else {
        return decodeCharacter(root->right, encodedMessage, index);
    }
}

void decodeMessage(HuffmanNode* root, const string& encodedMessage, string& decodedMessage) {
    int index = 0;
    while (index < encodedMessage.size()) {
        char character = decodeCharacter(root, encodedMessage, index);
        if (character != '\0') {
            decodedMessage += character;
        }
    }
}

HuffmanNode* buildHuffmanTree(const vector<char>& data, const vector<unsigned int>& frequency) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    for (size_t i = 0; i < data.size(); ++i) {
        minHeap.push(new HuffmanNode(data[i], frequency[i]));
    }

    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* top = new HuffmanNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    return minHeap.top();
}

int main() {
    int numCharacters;
    cin >> numCharacters;

    vector<char> data(numCharacters);
    vector<unsigned int> frequency(numCharacters);

    for (int i = 0; i < numCharacters; ++i) {
        cin >> data[i] >> frequency[i];
    }

    HuffmanNode* root = buildHuffmanTree(data, frequency);

    unordered_map<char, string> huffmanCodes;
    printHuffmanCodes(root, "", huffmanCodes);

    string message;
    cin.ignore();
    getline(cin, message);

    string encodedMessage;
    encodeMessage(message, encodedMessage, huffmanCodes);
    cout << encodedMessage << endl;

    string decodedMessage;
    decodeMessage(root, encodedMessage, decodedMessage);
    cout << decodedMessage << endl;

    return 0;
}
