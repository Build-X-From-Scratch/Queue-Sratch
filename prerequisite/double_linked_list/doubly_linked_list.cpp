#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int data)noexcept{
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
void print(Node* head){
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
}
int main(){
    Node* head = new Node(1);//node pertama

    head->next = new Node(2);//node ke 2
    head->next->prev = head; //prev node kedua adalah node pertama

    head->next->next = new Node(3); //node ke 3
    head->next->next->prev = head->next; //prev node ketiga adalah node kedua

    head->next->next->next = new Node(4); //node ke 4
    head->next->next->next->prev = head->next->next; //prev node keempat adalah node ketiga
    print(head);
    //std::cin.get();
    return 0;
}