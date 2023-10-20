class String
{

public:

    String();
    String (const char* str);
    String(const String& other);
    ~String();

public:

    friend const char* to_string(int num);
    void print() const;
    const char at(const int index) const;   
    const char* front() const;
    const char* back() const;
    const char* c_str() const;
    bool empty() const;
    const int length() const;
    const int size() const;
    const int capacity() const;
    void reserve(const int len);
    void shrink_to_fit();
    void clear();
    void insert(const int index, const char* target);
    void insert(int index, const char element);
    void erase(const int index, const int quantity);
    void erase(const int index);
    void push_back(const char element);
    void pop_back();
    void append(const char* str);
    const char* find(const char* target) const;
    String& operator= (const String& other);
    String& operator= (const char* other);
    const char& operator[] (const int index) const;
    void swap(String& other);


private:

    int m_capacity;
    int m_size;
    char* m_string;

    void resize();

    void push_front(const char element);


};



#include "string.hpp"

