#include <iostream>
#include <string>
#include <stdexcept>
class Bank{
    private:
        int size;
        int capacity;
        int* Queue;
        std::string* arr;
        int front;
        int rear;
    private:
        struct Information{
            std::string nama;
            int pid = 100;
        };
    public:
        Bank(){
            front = 0;
            rear = -1;
            this->size = 0;
            this->capacity = 10;
            this->Queue = new int[capacity];
            this->arr = new std::string[capacity];
        }
    private: //abstraksi getter
        int get_top_pid()const noexcept{
            return Queue[rear];
        }
        std::string get_top_nama()const noexcept{
            return arr[rear];
        }
        int get_back_pid()const noexcept{
            return Queue[front];
        }
        std::string get_back_nama()const noexcept{
            return arr[front];
        }
        std::pair<int,std::string> get_top_patient()const noexcept{
            return {Queue[rear],arr[rear]};
        }
        std::pair<int,std::string> get_back_patient()const noexcept{
            return {Queue[front],arr[front]};
        }
    private:
        int get_capacity()const noexcept{
            return capacity;
        }
        int get_size()const noexcept{
            return size;
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
    private:
        Information enqueue(std::string nama){ //tambah antrian
            if(is_full()){
                throw std::runtime_error("Antrian sudah full");
            }
            Information res;
            rear = (rear + 1) % capacity;
            static int data = res.pid;
            Queue[rear] = data;
            arr[rear] = nama;
            data++;
            size++;
            return {get_top_nama(),get_top_pid()};
        }   
        Information dequeue(){ //hapus/proses antrian
            if(is_empty()){
                throw std::runtime_error("Antrian Kosong");
            }
            int pid = Queue[front];
            std::string val_nama = get_back_nama();
            int val_pid = get_back_pid();
            std::string name = arr[front];
            Information res;
            front = (front + 1) % capacity;
            size--;
           return {val_nama,val_pid};  
        }   
    public:
        void tambah_antrian(const std::string nama){
            // enqueue(nama);
            Information res = enqueue(nama);;
            std::cout << "Antrian sedang di tambahkan dengan nama: " << res.nama << " dan id antrian: " << res.pid << std::endl;
        }
        void proses_antrian(){
            dequeue();
            Information res = dequeue();
            std::cout << "Proses selesai dengan:" << std::endl;
            std::cout << "nama: " << res.nama << std::endl;
            std::cout << "pid: " << res.pid << std::endl; 
        }
};
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    Bank proses;
    proses.tambah_antrian("yusuf");
    proses.tambah_antrian("diana");
    proses.tambah_antrian("asky");
    proses.tambah_antrian("ali");
    proses.proses_antrian();
    // Your code here
    std::cin.get();
    return 0;
}   