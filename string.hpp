
String::String() {
    
    m_capacity = 10;
    m_size = 0;
    m_string = new char[m_capacity];
    m_string[m_size] = '\0';

}

String::String (const char* str) {
        
    const char* t_str = str;
    while(*t_str) {
        m_size++, t_str++;
    }

    m_capacity = m_size * 2;
    m_string = new char[m_capacity];

    for(int i = 0; i < m_size; i++) {
        m_string[i] = str[i];
        
    }

    m_string[m_size++] = '\0';


}

String::String(const String& other) {
    m_capacity = other.capacity();
    m_size = other.size();
    m_string = new char[m_capacity];
    
    for(int i = 0; i < m_size; i++) {
        m_string[i] = other.at(i);
    }

    m_string[m_size] = '\0';
}

String::~String() {
    delete[] m_string;
    m_string = nullptr;
}

void String::print() const {
    
    for(int i = 0; i < m_size; i++) {
        std::cout << m_string[i];
    }

    std::cout << '\n';

}

const char String::at(const int index) const {

    if(index < 0 || index >= m_size - 1) {
        
        throw std::out_of_range("Index out of range");
    }

    return m_string[index];
}

const char* String::front() const {
    return (m_size == 1) ? nullptr : m_string;
}

const char* String::back() const {
    return (m_size == 1) ? nullptr : (m_string + m_size - 2);
}

const char* String::c_str() const {
    char* c_string = new char[m_size];
    int index = 0;
    while(m_string[index] != '\0') {
        c_string[index++] = m_string[index];
    }

    c_string[m_size] = '\0';

    return c_string;
}

bool String::empty() const {
    return (m_size == 0);
}

const int String::length() const {
    return (m_size - 1);
}

const int String::size() const {
    return (m_size - 1);
}

const int String::capacity() const {
    return m_capacity;
}

void String::reserve(const int len) {

    if(m_capacity - m_size >= len) {
        return;
    }

    m_capacity += len;
    char* temp = new char[m_capacity];

    for(int i = 0; i <= m_size; ++i) {
        temp[i] = m_string[i];
    }

    delete[] m_string;
    m_string = temp;
}

void String::shrink_to_fit() {
    
    m_capacity = m_size;
    char* temp = new char[m_capacity];

    for(int i = 0; i <= m_size; ++i) {
        temp[i] = m_string[i];
    }

    delete[] m_string;
    m_string = temp;
}

void String::clear() {
    for(int i = 0; i < m_capacity; ++i) {
        m_string[i] = '\0';
    }
}

void String::insert(const int index, const char* target) {

    if(index < 0 || index > m_size) {
        
        throw std::out_of_range("Index out of range");
    }

    const char* t_target = target;
    int target_length = 0;

    while(*t_target) {
        target_length++, t_target++;
    }
    
    while(m_size + target_length >= m_capacity) {
        resize();
    }

    m_size += target_length;
    
    char* temp = new char[m_capacity];

    for(int i = 0, j = 0, k = 0; i < m_size; i++) {

        if((i >= index) && (k < target_length)) {

            temp[i] = target[k++];

        }

        else {
            temp[i] = m_string[j++];
        }

    }

    temp[m_size] = '\0';

    delete[] m_string;
    m_string = temp;

}

void String::insert(int index, const char element) {

    if(index < 0 || index >= m_size) {
        
        throw std::out_of_range("Index out of range");
    }

    ++m_size;
    char* temp = new char[m_capacity];

    for(int i = 0, j = 0; i < m_size; i++) {

        if(i == index) {
            temp[index] = element;
        }

        else {
            temp[i] = m_string[j++];
        }

    }

    delete[] m_string;
    m_string = temp;

}

void String::erase(const int index, const int quantity) {

    if(index < 0 || index >= m_size || quantity == 0) {
        return;
    }


    for(int i = 0 ; i < m_size - quantity; i++) {

        if(i < index || i > quantity) {continue;}

        m_string[i] = m_string[i + quantity];

    }

    m_size -= quantity;  

    m_string[m_size] = '\0';

}

void String::erase(const int index) {

    if(index < 0 || index > m_size - 1) {
        return;
    }

    for(int i = index; i < m_size - 1; i++) {
    
        m_string[i] = m_string[i + 1];

    }

    m_string[m_size--] = '\0';
    

}

void String::push_back(const char element) {

    if(m_size == m_capacity) {
        resize();
    }


    m_string[m_size++] = element;

    return;
}

void String::pop_back() {
    m_string[--m_size] = '\0';
}

void String::append(const char* str) {

    const char* t_str = str;
    int str_length = 0;

    while(*t_str) {
        str_length++, t_str++;
    }

    while(m_size + str_length >= m_capacity) {
        resize();
    }

    for(int i = m_size - 1; i < m_size + str_length; i++) {

        m_string[i] = str[i - m_size + 1];
    }

    m_size += str_length;

    m_string[m_size] = '\0';
}

const char* String::find(const char* target) const {
    
    for(int i = 0; i < m_size; ) {
        int j = 0;
        int i_backup = i;
        while(i < m_size && m_string[i] == target[j]) {
            j++, i++;
            if(target[j] == '\0') {
                return (m_string + i - j);
            }
        }
        i = ++i_backup;
    }
    return nullptr;
}

String& String::operator= (const String& other) {
    
    m_capacity = other.capacity();
    m_size = other.size();

    delete[] m_string;
    m_string = new char[m_capacity];

    for(int i = 0; i < m_size; i++) {
        m_string[i] = other[i];
    }

    m_string[m_size++] = '\0';

    return *this;
}

void String::swap(String& other) {

    String temp = other;
    other = *this; 
    *this = temp;       
    
}

String& String::operator= (const char* other) {
    
    const char* t_str = other;

    while(*t_str) {
        m_size++, t_str++;
    }

    m_capacity = m_size * 2;
    m_string = new char[m_capacity];

    for(int i = 0; i < m_size; i++) {
        this->push_back(other[i]);
        
    }

    m_string[m_size++] = '\0';

    return *this;
    
}

const char& String::operator[] (const int index) const {

    if(index < 0 || index >= m_size - 1) {
        
        throw std::out_of_range("Index out of range");
    }

    return m_string[index];

}

const char* to_string(int num) {
    
    String ret;

    while(num > 0) {
        ret.push_front(((num % 10) + '0'));
        num /= 10;
    }

    return ret.m_string;  
}

const String String::substr(const int start, const int end) const {

    String res;

    for(int i = start; i < end; i++) {
        
        res.push_back(this->at(i));

    }

    return res;
}

size_t String::copy(char* dest, size_t count, size_t pos) const {

    size_t index = pos;

    while(index < count) {

        *dest = this->at(index);

        index++, dest++;
    }

    *dest = '\0';

    return index;

}









// private:


void String::resize() {

    m_capacity *= 2;
    
    char* temp = new char[m_capacity];

    for(int i = 0; i <= m_size; ++i) {
        temp[i] = m_string[i];
    }

    delete[] m_string;
    m_string = temp;

}

void String::push_front(const char element) {

    if(++m_size >= m_capacity) {
        resize();
    }

    for(int i = m_size; i >= 0; --i) {
        m_string[i + 1] = m_string[i];    
    }

    m_string[0] = element;
    m_string[m_size] = '\0';


    return;
}
