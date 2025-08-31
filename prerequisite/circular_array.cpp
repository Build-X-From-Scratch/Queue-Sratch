#include <iostream>
/**
 * @brief circular array adalah sebuah array biasa dengan aturan aritmatika
 * dengan aturan aritmatika seolah-olah array melingkat tidak memiliki ujung
 * misal kita punya array dengan kapasitas 5,ketika sudah sampai index ke 4
 * maka index selanjut nya kembali ke 0,sehingga menciptakan sebuah siklus
 * 
 * @details aturan matematika index = (index + 1) % capacity;
 * ketika index + 1 > capacity maka hasil operasi tersebut kembali menjadi 0
 */
void circular_array(int (&arr)[5],int& size,int pos){
    int val = (pos + 1) % size;
    std::cout << val << std::endl;
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    circular_array(arr,size,5);
    // Your code here
    std::cin.get();
    return 0;
}