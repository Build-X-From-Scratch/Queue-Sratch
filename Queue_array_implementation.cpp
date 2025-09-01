#include <iostream>
#include <cstddef>
/**
* @brief Queu mempunya beberapa operasi dasar yaitu:
*        -  enqueue adalah operasi untuk menambah element ke queue
*        -  dequeu adalah operasi untuk menghapus element dari queue
*        -  getFront/peek mengambil element paling depan tanpa menghapus
*        -  gerRear mengambil elemnt paling belakang tanpa menghapus
*@details program ini memakai konsep circular array untuk mengimplementasikan
*Queue,dengan circular array kita tidak perlu lagi melakukan beberapa operasi
*seperti deleting at beginning yg membutuhkan O(n) time complexity.
*/
template <typename type>
class Array{
    private:
        std::size_t capacity;
        int size;
        type* arr;
        type front;
        type rear;
    public:
        //default constructor
        Array(){
            this->capacity = 1;
            this->size = 0;
            this->front = 0;
            this->rear = -1; 
            this->arr = new type[capacity];
        }
        //Constructor
        Array(std::size_t capacity){
            if(capacity <= 0){
                throw std::invalid_argument("capasitas harus lebih dari 0");
            }
            this->capacity = capacity;
            this->size = 0;
            this->front = 0;
            this->rear = -1;
            this->arr = new type[capacity];
        }
        //copy constructor
        Array(const Array& other){
            size = other.size;
            capacity = other.capacity;
            front = other.front;
            rear = other.rear;
            arr = new type[capacity]; //alokasi ulang array
            for(size_t i = front;i < rear + 1;i++){
                arr[i] = other.arr[i];
            }
        }
        //copy assignment / operator overloading
        Array& operator=(const Array& other){
            if(this != &other){ //objeck saat ini tidak sama dengan objek yg ingin copy
                size = other.size;
                arr = new type[capacity];
                front = other.front;
                rear = other.rear;
                for(size_t i = front;i < rear + 1;i++){
                    arr[i] = other.arr[i];
                }
            }
            return *this; //kembalikan objeck saat ini
        }
        //desctructor
        ~Array(){
            clear();
        }
    public: //abstraksi getter
        int get_size()const noexcept{
            return this->size;
        }
        int get_capacity()const noexcept{
            return this->capacity;
        }
        bool is_full()const noexcept{
            if(size == capacity){
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
        type get_back()const noexcept{
            return this->arr[rear];
        }
        type get_front()const noexcept{
            return this->arr[front];
        }
    public: //abstraksi setter
        void enqueu(const type& data){
            if(size == capacity){
                throw std::runtime_error("queue telah terisi penuh");
            }
            rear = (rear + 1) % capacity;
            arr[rear] = data;
            size++;
        }
        type dequeu(){
            if(is_empty()){
                throw std::runtime_error("Qeueu is full");
            }
            int val = arr[front];   
            front = (front + 1) % capacity; 
            size--;
            return val;
        }
    public: //abstraksi dynamic array
        void grow_array()noexcept{
            type* temp = new type[capacity * 2];
            capacity = capacity * 2;
            for(size_t i = 0;i < size;i++){
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        void shrink_array()noexcept{
            capacity = size;
            type* temp = new type[capacity];
            for(size_t i = 0;i < size;i++){
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
    public: // setter destructor & print
        void clear(){  
            int n_size = get_size();
            for(size_t i = 0;i < n_size;i++){
                arr[i] = 0;
            }
            size = 0;
        }
        void print()const noexcept{
            for(size_t i = front;i < rear + 1;i++){
                std::cout << arr[i] <<  " ";
            }
            std::cout << std::endl;
        }
};
int main(){
    Array<int>Qeueu1(100);  
    Qeueu1.enqueu(1);
    Qeueu1.enqueu(2);
    Qeueu1.enqueu(3);
    Qeueu1.enqueu(4);
    std::cout << "Proses enqueue" << std::endl;
    Qeueu1.print();
    std::cout << "proses Dequeue" << std::endl;
    Qeueu1.dequeu();
    Qeueu1.print();
    //copy constructor
     Array<int>Qeueu2 = Qeueu1;
     std::cout << "Proses Copy Constructor" << std::endl;
     Qeueu2.print();
     std::cout << "Proses Copy Assignment" << std::endl;
     Array<int>Queue3 = Qeueu2; //chaining
     Queue3.print();
     std::cout << "Testing getter" << std::endl;
     std::cout << "ini front: " << Qeueu1.get_front() << std::endl;
     std::cout << "ini rear: " << Qeueu1.get_back() << std::endl;
     std::cout << "ini capacity: " << Qeueu1.get_capacity() << std::endl;
     std::cout << "ini size: " << Qeueu1.get_size() << std::endl;
    // Your code here
    return 0;
}