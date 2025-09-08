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
#include <deque>
#include <stdexcept>
std::deque<int>s;
template <typename type>
class Linked_List{
    private:
        struct Node{
            type data;
            Node* next;
            //constructor Node
            Node(const type& data){
                this->data = data;
                this->next = nullptr;
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
        bool is_empty(){
            if(size == 0){
               return true; 
            }
            return false;
        }
    public://abstraksi setter
        void push_back(const type& data){
            if(is_empty()){
                Node* new_node = new Node(data);
                front = rear = new_node;
            }
            Node* new_node = new Node(data);
            rear = rear->next = new_node;
        }
        void push_front(const type& data){
            if(is_empty()){
                Node* new_node = new Node(data);
                front = rear = new_node;
            }
            Node* new_node = new Node(data);
            front = new_node->next = front;
        }
        void pop_back(){
            if(is_empty()){
                throw std::runtime_error("Queue is empty");
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

        }
};
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // Your code here
    std::cin.get();
    return 0;
}