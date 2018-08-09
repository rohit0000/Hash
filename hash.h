#include<iostream>
#define MAX 10
using namespace std;

struct node{
    int val;
    struct node* next;
};

struct nodeArr{
    struct node* head;
};

class hash{
private:
    struct nodeArr* nodesArray;
public:
    hash();
    int add(int key_i);
    int remove(int key_i);
    void printContents();
};


hash::hash()
{
    nodesArray = new nodeArr[MAX];
    for(int i = 0; i < MAX; i++){
        nodesArray[i].head = NULL;
    }

}

node* newListNode(int val)
        {
            node* newNode = new node;
            newNode->val = val;
            newNode->next = NULL;
            return newNode;
        }

int hash::add(int key_i)
{
        node* newNode = newListNode(key_i);
        int hashVal = key_i%10;
        newNode->next = nodesArray[hashVal].head;
        nodesArray[hashVal].head = newNode;
        return 0;
}

int hash::remove(int key_i)
{
    int hashVal = key_i % 10;
    if(nodesArray[hashVal].head == NULL){
        return -1;
    }
    node* temp = nodesArray[hashVal].head->next;
    node* prev = nodesArray[hashVal].head;
    while(prev != NULL){
        if(temp==NULL && prev->val == key_i){
            nodesArray[hashVal].head = NULL;
            return 0;
        }
        else if (temp!=NULL && prev->val == key_i){
            prev->next = temp->next;
            return 0;
        }
    }
    return -1;
}

void printNode(){

}

void hash::printContents()
{
    cout << "Hash Val \tKeys" << endl;
    for(int i = 0; i < MAX; i++){
        node *temp = nodesArray[i].head;
        cout << i;
        if(nodesArray[i].head != NULL){
            cout << "\t\t";
            while(temp != NULL){
                cout << " " << temp->val;
                temp = temp->next;
            }
            cout << endl;
        }
        else{
            cout << "\t\t -" << endl;
        }
    }
}



//heap::heap(){
//    size = 0;
//    int i =0;
//    for(; i < 15; i++){
//        arr[i] = new node();
//        arr[i]->value_i = 0;
//    }
//}
//
//void swap(int *x, int *y)
//{
//    int temp = *x;
//    *x = *y;
//    *y = temp;
//}
//
//
//int parent(int i){
//    i = (i-1)/2;
//    return i;
//}
//
//int leftChild(int i){
//    return 2*i+1;
//}
//int rightChild(int i){
//    return 2*i+2;
//}
//
//int heap::insert(int item_i){
//    if(size == 0){
//        root_p = arr[0];
//        arr[0]->value_i = item_i;
//        size++;
//        return 0;
//    }
//    else if (size < MAX){
//        arr[size]->value_i = item_i;
//        size++;
//        int i = size - 1;
//
//        while (i != 0 && arr[parent(i)]->value_i < arr[i]->value_i)
//        {
//           swap(&arr[i]->value_i, &arr[parent(i)]->value_i);
//           i = parent(i);
//        }
//    }
//
//}
////void deleteNode(int i, int new_val)
////{
////    heap::arr[i]->value_i = new_val;
////    while (i != 0 && harr[parent(i)] > harr[i])
////    {
////       swap(&harr[i], &harr[parent(i)]);
////       i = parent(i);
////    }
////}
//
//int heap::remove(int item_i){
//    int left, right, i, temp, prevnode;
//
//    for (i = 0; i < MAX; i++) {
//        if (item_i == arr[i]->value_i)
//            break;
//    }
//    if (item_i != arr[i]->value_i)
//    {
//        return -1;
//    }
//    arr[i]->value_i = arr[size - 1]->value_i;
//    size = size - 1;
//    prevnode =(i - 1) / 2;
//    if (arr[i]->value_i > arr[prevnode]->value_i)
//    {
//        insert(arr[i]->value_i);
//        return 0;
//    }
//    left = 2 * i + 1; /*left child of i*/
//    right = 2 * i + 2; /* right child of i*/
//    while (right < size)
//    {
//        if (arr[i]->value_i >= arr[left]->value_i && arr[i]->value_i >= arr[right]->value_i)
//            return 0;
//        if (arr[right]->value_i <= arr[left]->value_i)
//        {
//            temp = arr[i]->value_i;
//            arr[i]->value_i = arr[left]->value_i;
//            arr[left]->value_i = temp;
//            i = left;
//        }
//        else
//        {
//            temp = arr[i]->value_i;
//            arr[i]->value_i = arr[right]->value_i;
//            arr[right]->value_i = temp;
//            i = right;
//        }
//        left = 2 * i + 1;
//        right = 2 * i + 2;
//    }/*End of while*/
//    if (left == size - 1 && arr[i]->value_i)    {
//        temp = arr[i]->value_i;
//        arr[i]->value_i = arr[left]->value_i;
//        arr[left]->value_i = temp;
//    }
//    return 0;
//}
//
//void heap::levelOrder(){
//    int i;
//    for (i=0; i < size; i++)
//    {
//        cout<< arr[i]->value_i << " ";
//    }
//}
//
//int heap::maximum(){
//    if(root_p != NULL)
//        return root_p->value_i;
//    return -1;
//}


