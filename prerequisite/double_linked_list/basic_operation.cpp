#include <iostream>
static int cnt = 0;
class Doubly_Linked_List{
    private:
        struct Node{
            int data;
            Node* next;
            Node* prev;
            Node(int data){
                this->data = data;
                this->next = nullptr;
                this->prev = nullptr;
            }
        };
        Node* head;
        Node* tail;
    public:
        //default constructor
        Doubly_Linked_List(){
            this->head = nullptr;
            this->tail = nullptr;
        }
    public:
        void unlink(Node* head,Node* node){
            if(head == node){
                head = head->next;
            }
        }
    public:
        void insert_at_front(int data){
            Node* new_node = new Node(data);
            if(head == nullptr){
                head = tail = new_node;
            }else{
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }

        }
        void insert_at_back(int data){
            Node* new_node = new Node(data);
            if(head == nullptr){
                head = tail = new_node;
            }else{
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
        }
    public: //deletion use tail pointer
        void deleteHed(){ //deletion at head selalu pakai pointer head
            if(head == nullptr){
                return;
            }
            Node* temp = head;
            
            if(head == tail){ //deletion & insertion di head,prev selalu nullptr
                head = tail = nullptr;
            }else{
                head = head->next; 
                head->prev = nullptr;
            }
            delete temp;    
        }
        void delete_tail(){ //deletion at tail selalu pakai tail pointer
            if(tail == nullptr){
                return;
            }
            Node* temp = tail;
            if(head == nullptr){ //jika hanya satu node
                head = tail = nullptr;
            }
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    public:
    void print(){
            cnt++;
            std::cout << "operasi ke " << cnt << std::endl;
            Node* temp = head;
            while(temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
        void backward_iter(){
            Node* temp = head;
            while(temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->prev;
            }
        }
};
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    Doubly_Linked_List dll;
    dll.insert_at_front(1);//1
    dll.insert_at_back(2); //1,2
    dll.insert_at_front(3);//3,1,2
    dll.print();
    dll.deleteHed();// 1 2
    dll.print();
    dll.delete_tail();
    dll.print();
    // Your code here
    //std::cin.get();
    return 0;   
}