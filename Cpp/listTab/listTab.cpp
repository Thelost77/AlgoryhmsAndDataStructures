#include <iostream>

template<typename T> class List {
    typedef int* iterator;

    private:
        T tab[100];
        int size = 0;
    
    public:

        int length() const {
            return size;
        }

        void add(T argument) {
            if(size < sizeof(tab)) {
                tab[size] = argument;
                size++;
            }
            else 
                std:: cout << "Exceeded tab size..." << std::endl;

        }
        void insert(T element, int index) {

        }

        iterator begin() {
            iterator it = tab;
            return it;
        }
        iterator last() {
            iterator it = tab + size;
            return it;
        }

        T& operator[](int index) {
            return tab[index];
        }
};

int main() {
    List<int> list{};

    list.add(1);
    list.add(2);

    for (int i = 0; i < list.length(); i++)
    {
        std::cout << list[4] << std::endl;
    }
    
}