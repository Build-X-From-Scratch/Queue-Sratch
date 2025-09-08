/**
 * @brief program untuk mengimplementasikan double ended queue(dequeue) full scratch dengan linked list
 * dequeue adalah versi umum dari queue,yang memunkinkan insert dan pop bisa dilakukan di rear dan head
 * 
 * @author yusuf
 * @date 7 september  2025
 * 
 * @details basic operation double ended queue antar lain
 * - setter
* insert at front -> memunkinkan insertion dari front atau dari depan
* insert at rear  ->memunkinkan insertion dari rear atau dari belakang
* delete rear -> menghapus element pada rear
* delete front -> menghapus element pada front
 * - getter
 * is_full ->array based implementation
 * is_empty -> check if queue is empty or not
 * get_size -> count element on queue
 */
#include <iostream>
#include <stdexcept>
static int cnt = 0; 
template <typename type>
class Linked_List{
    private:
        struct Node{
            type data;
            Node* next;
            Node* prev;
            //constructor Node
            Node(const type& data){
                this->data = data;
                this->next = nullptr;
                this->prev = nullptr;
            }
        };
    private:
        Node* front;
        Node* rear;
        int size;
    public:
        //default constructor
        Linked_List(){
            this->front = nullptr;
            this->rear = nullptr;
            this->size = 0;
        }
        Linked_List(const Linked_List& others){
            size = others.size;
            front = others.front;
            rear = others.rear;
            if(others.front == nullptr){
                return;
            }
            front = new Node(others.front->data);
            Node* curr = front;
            Node* temp = others.front->next;
            while(temp != nullptr){
                Node* new_node = new Node(temp->data); //buat node baru
                curr->next = new_node; //ponter next adalah new_node
                new_node->prev = curr; //prev adalah curr saat ini
                curr = new_node; //majukan pointer curr
                temp = temp->next; //majukan pointer temp
                
            }
            rear = curr;
        }
        Linked_List& operator=(const Linked_List& others){
            if(this == &others){
                return *this;
            }
            clear();
            if(!others.front){ //linked list is empty
                return nullptr;
            }
            front = others.front;
            rear = others.rear;
            size = others.size;
            front = new Node(others.front->data);
            Node* curr = front;
            Node* temp = others.front->next;
            while(temp != nullptr){
                //buat node baru di heap
                Node* new_node = new Node(temp->data);
                //node setelah curr sekarang adalah new_node
                curr->next = new_node;
                //node sebelum prev adalah curr
                new_node->prev = curr;
                //majukan pointer curr,sekarang curr menunjuk new_node
                curr = new_node;
                // majukan pointer next temp
                temp = temp->next;
            }
            rear = curr;
            return *this;
        }
        ~Linked_List(){
            clear();
        }
    public: //abstraksi getter
        type get_rear()const noexcept{
            return rear;
        }
        type get_front()const noexcept{
            return front;
        }
        int get_size()const noexcept{
            return size;
        }
        bool is_empty(){ //refactor
            if(size == 0){
                return true;
            }
            return false;
        }
    public://abstraksi setter
        void push_back(const type& data){
            Node* new_node = new Node(data);
            if(is_empty()){
                front = rear = new_node;
                front->prev = nullptr; //update     prev ->opsional 
                size++;
            }else{
                rear->next = new_node; //hubunngkan new node dengan rear
                new_node->prev = rear; //prev new_node skrg adalah rear
                rear = new_node; //rear sekarang adalah new node
                size++; //increment size
            }
        }
    public:
        void swap(Linked_List& others){
           //swap head
           Node* tempFront = front;
           front = others.front;
           others.front = tempFront;
           //swap tail
           Node* tempRear = rear; 
           rear = others.rear;
           others.rear = tempRear;
           //swap size
           int tempSize = size;
           size = others.size;
           others.size = tempSize;
        }
        void push_front(const type& data){
            if(is_empty()){
                Node* new_node = new Node(data);
                front = rear = new_node;
                size++;
            }else{
                Node* new_node = new Node(data);
                new_node->next = front;
                new_node->prev = nullptr;
                front = new_node;
                size++;
            }
        }
        void pop_back(){
            if(is_empty()){
                throw std::runtime_error("Queue is empty");
            }
            if(front == nullptr){
                front = rear = nullptr;
            }else{
                Node* temp = front;
                front = front->next;
                front->prev = nullptr;
                delete temp;
            }
        }
        void pop_front(){
            if(is_empty()){
                throw std::runtime_error("Queue is empty");
            }
            if(rear == nullptr){
                return;
            }else{
                Node* temp = rear;
                rear = rear->prev;
                rear->next = nullptr;
                delete temp; 
            }
        }
    public:
        void clear(){
            while(front != nullptr){
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }
        void print(){
            cnt++;
           // std::cout << "operasi ke " << cnt << std::endl;
           // std::cout << "Object yang memanggil: " << this << std::endl;
            Node* temp = front;
            while(temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
};
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    Linked_List<int>dequeu;
    dequeu.push_back(1);
    dequeu.push_back(2);
    dequeu.push_back(3);
    dequeu.push_back(4);
    dequeu.push_back(5); 
    dequeu.print(); // 1 2 3 4 5
    dequeu.push_front(6);
    dequeu.print();//6 1 2 3 4 5
    Linked_List<int>dequeue_temp = dequeu;
    dequeue_temp.print();
    Linked_List<int>dequeu1;
    dequeu1.push_front(10);
    dequeu1.push_front(12);
    dequeu1.push_front(13);
    std::cout << "sebelum swap" << std::endl;
     dequeu1.print();
    dequeu1.swap(dequeue_temp);
    std::cout << "sesudah swap" << std::endl;
    dequeu1.print();
    dequeue_temp.print();
    // Your code here
    return 0;
}