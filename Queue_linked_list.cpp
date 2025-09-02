#include <iostream>
#include <stdexcept>
#include <cstdlib>
template <typename type>
class Linked_list{
    private: //abstraksi linked list
        struct Node{
            type data;
            Node* next;
            //constructor
            Node(const type& data){
                this->data = data;
                this->next = nullptr;
            }
        };
    private: //abstraksi data member Queue
        int size;
        Node* front;
        Node* rear;
    public:
        //default constructor
        Linked_list(){
            this->size = 0;
            this->front = nullptr;
            this->rear = nullptr;
        }
        //copy constructor
        Linked_list(const Linked_list& obj){
            if(is_first()){
                return;
            }
            front = new Node(obj.front->data);
            Node* curr = front;
            Node* temp = obj.front->next;
            while(temp != nullptr){
                curr->next = new Node(temp->data);
                curr = curr->next;
                temp = temp->next;
            }
            //curr = new Node(obj.rear->data);
        }
        //copy assignment
        Linked_list& operator=(const Linked_list &obj){
            if(this == &obj){
                return *this;//return objeck saat ini
            }
            clear(); //hapus semua isi object saat ini
            if(!obj.front){ //jika object yang ingin di copy is empty
                return nullptr;
            }
            front = new Node(obj.front->data);
            Node* curr = front;
            Node* temp = obj.front->next;
            while(temp != nullptr){
                curr->next = new Node(temp->data);
                curr = curr->next;
                temp = temp->next;
            }
            return *this;
        }
        ~Linked_list(){
            clear();
        }
    public: //abstraksi getter
        int get_size()const noexcept{
            return this->size;
        }
        type get_front()const{
            if(is_empty()){
                throw std::runtime_error("Queue is empty"); 
            }
            return front->data;
        }
        bool is_last()const noexcept{
            if(front->next == nullptr && rear->next == nullptr){
                return true;
            }
            return false;
        }
        bool is_first()const noexcept{
            if(front == nullptr && rear == nullptr){
                return true;
            }
            return false;
        }
        bool is_empty()const noexcept{
            if(size == 0){
                return true;
            }
            return false;
        }
        type get_peek()const{
            if(is_empty()){
                throw std::runtime_error("Queue is empty"); ;
            }
            return rear->data;
        }
    public:
        void enqueue(const type& data){
            if(is_first()){
                //buat pdecrementointer penunjuk yang menunjuk node baru
                Node* baru = new Node(data);
                //hubungkan pointer penunjuk dengan head
                front = rear = baru;
                //increment size
                size++;  
            }else{
                //buat pointer penunjuk yang menunjuk node baru
                Node* baru = new Node(data);
                //hubungkan pointer penunjuk dengan head
                rear = rear->next = baru;
                //increment size
                size++;
            }
        }
        void dequeue(){
            if(is_empty()){
                throw std::runtime_error("Queue is empty");
            }
            if(is_last()){
                Node* temp = front;
                front = rear = nullptr;
                delete temp;
                size--;
            }else{
                //buat pointer penunjuk curr
                Node* temp = front;
                //gerakakn pointer head sehingga menunjuk node selanjut nya
                front = front->next;
                //hapus node lama
                delete temp;
                //decrement size
                size--;
            }
        }
    public: //abstraksi print dan clear
        void clear()noexcept{
            while(front != nullptr){
                Node* temp = front;
                front = front->next;
                delete temp; //hapus node
            }
            size = 0;
        }
        void print()const noexcept{
            if(is_empty()){
                std::cout << "Queue is empty" << std::endl;
                EXIT_SUCCESS;
            }else{
                Node* curr = front;
                while(curr != nullptr){
                    std::cout << curr->data << " ";
                    curr = curr->next;
                }
                std::cout << std::endl; 
            }
        }
};
int main(){
    Linked_list<int>Queue1;
    Queue1.enqueue(1);
    Queue1.enqueue(2);
    Queue1.enqueue(3);
    Queue1.enqueue(4);
    Queue1.enqueue(5);
    Queue1.print();
    std::cout << "ini front: " << Queue1.get_front() << std::endl;
    std::cout << "ini rear: " << Queue1.get_peek() << std::endl;
    std::cout << "ini size: " << Queue1.get_size() << std::endl;
    std::cout << "ini proses dequeue "<< std::endl;
    Queue1.dequeue();
    Queue1.dequeue();
    // Queue1.dequeue();
    Queue1.print();
    std::cout << "proses copy constructor" << std::endl;
    Linked_list<int>Queue2 = Queue1; //copy constructor
    Queue2.print();
    std::cout << "Proses Copy Assinment" << std::endl;
    Linked_list<int>Queue3 = Queue2;
    Queue3.print();
    // Your code here
    std::cin.get();
    return 0;
}