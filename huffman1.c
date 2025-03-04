#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    int freq;
    struct Node * left;
    struct Node * right;
    
};
struct Node* root, *newnode;

struct MinHeap {
    int size;
    struct Node* arr[100]; // Assuming max 100 elements
};
//this is the min heap in which the lemnts will be stored. (size will be increasing with addition of nodes)

struct Node* buildNode(char data, int freq){
    struct Node*newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->freq=freq;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void swap(struct Node** a, struct Node**b){
    struct Node*temp = *a;
    *a = *b;
    *b=temp;
}

void minHeapify(struct MinHeap* heapnode, int indx){
    int small = indx; // store value of small , to check at last.
    int left = (indx*2)+1;
    int right = (indx*2)+2;
    
    if(left<heapnode->size && heapnode->arr[left]->freq < heapnode->arr[small]->freq){
        small=left;
    }
    if(right<heapnode->size && heapnode->arr[right]->freq < heapnode->arr[small]->freq){
        small=right;
    }
    if(small!=indx){
        //swap indx and smallest
        struct Node*temp = heapnode->arr[indx];
        heapnode->arr[indx]=heapnode->arr[small];
        heapnode->arr[small]=temp;
        //again looop untill it reaches the correct postionn:
        minHeapify(heapnode, small);
    }
}

struct Node* mini(struct MinHeap*heapnode){
    struct Node* temp = heapnode->arr[0];
    heapnode->arr[0] = heapnode->arr[heapnode->size-1];
    heapnode->size--;
    minHeapify(heapnode,0);
    return temp;
}

void insertMinHeap(struct MinHeap* heapnode, struct Node*node){
    int i=heapnode->size;
    heapnode->arr[i]=node;//insert the node created in Heap.
    heapnode->size++; //increase the heap size.
    while(i>0 && heapnode->arr[(i-1)/2]->freq > heapnode->arr[i]->freq){
        struct Node*temp = heapnode->arr[i];//temp = child
        heapnode->arr[i] = heapnode->arr[(i-1)/2];//child=parent
        heapnode->arr[i]=temp;
        //basically, value of parent and child were swapped.
        i=(i-1)/2; //traversing to the parentof parent.
    }//traverse up , till the parentsfreq>childs, and do swapping.
}

struct Node* merging(char letter[], int freq[], int n){
    struct MinHeap* heapnode = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heapnode->size=0;

    for(int i=0;i<n;i++){
        heapnode->arr[i]=buildNode(letter[i],freq[i]);
        minHeapify(heapnode, i);
    }
    heapnode->size=n;

    while(heapnode->size>1){
        struct Node*left=mini(heapnode);
        struct Node*right=mini(heapnode);
        struct Node*merged = buildNode('0', left->freq+right->freq);
        merged->left=left;
        merged->right=right;

        //innsert the above merged node to our heap
        insertMinHeap(heapnode,merged);
    }
    return heapnode->arr[0];
}




 //finally print:
void printCode(struct Node*root, char code[], int top){
    if(root->left){
        code[top]='0';
        printCode(root->left,code,top+1);
    }
    if(root->right){
        code[top]='1';
        printCode(root->right,code,top+1);
    }
    if(!root->left && !root->right){
        code[top]='\0';
        printf("%c: %s\n",root->data, code);
    }
}

int main() {
    char chars[] = {'w','r','p','a','u','d'};//insert in sorted order.
    int freq[] = {3,6,7,10,10,13};
    int n = sizeof(chars) / sizeof(chars[0]);

    struct Node* root = merging(chars, freq, n);

    char code[100];
    int top = 0;
    printf("Huffman Codes:\n");
    printCode(root, code, top);

    return 0;
}
