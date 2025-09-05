#include <iostream>
#include <string>
#include <stdexcept>
class Bank{
    private:
        int size;
        int capacity;
        int* Queue;
        int front;
        int rear;
    private:
        struct Information{
            std::string nama;
            int pid = 100;
        };
    public:
        Bank(){
            this->size = 0;
            this->capacity = 10;
            this->Queue = new int[capacity];
        }
    public: //abstraksi getter
        int get_top_pid()const noexcept{
            Information res;
            return res.pid;
        }
        std::string get_top_nama()const noexcept{
            Information res;
            return res.nama;
        }
        Information get_top_patient()const noexcept{
            Information res;
            return {res.nama,res.pid};
        }
    public:
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
    public:
        void enqueue(){ //tambah antrian
            if(is_full()){
                throw std::runtime_error("Antrian sudah full");
            }
            rear = (rear + 1) % capacity;
            int data = get_top_pid();
            Queue[front] = data++;
        }   
        void dequeue(){ //hapus/proses antrian
            if(is_empty()){
                throw std::runtime_error("Antrian Kosong");
            }
            Queue[front] = 0;
            size--;
            front = (front + 1) % capacity;
        }
};
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // Your code here
    std::cin.get();
    return 0;
}   