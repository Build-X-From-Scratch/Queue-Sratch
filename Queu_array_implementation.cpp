#include <iostream>
#include <cstddef>
#include <queue>
std::queue<int>s;
/**
* @brief Queu mempunya beberapa operasi dasar yaitu:
*        -  enqueue adalah operasi untuk menambah element ke queue
*        -  dequeu adalah operasi untuk menghapus element dari queue
*        -  getFront/peek mengambil element paling depan tanpa menghapus
*        -  gerRear mengambil elemnt paling belakang tanpa menghapus
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
            arr = new type[capacity];
            for(int i = 0;i < size;i++){
                arr[i] = other.arr[i];
            }
        }
        //copy assignment / operator overloading
        Array& operator=(const Array& other){
            if(this != &other){ //objeck saat ini tidak sama dengan objek yg ingin copy
                size = other.size;
                arr = new type[capacity];
                for(size_t i = 0;i < size;i++){
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
        void back()const noexcept{
            return this->arr[size - 1];
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
            capacity *= 2;
            for(size_t i = 0;i < size;i++){
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        void shrink_array(){
            type* temp = new type[capacity/2];
            capacity /= 2;
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
            for(size_t i = 0;i < size;i++){
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
    Qeueu1.print();
    // Your code here
    return 0;
}