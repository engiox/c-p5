#include <iostream>
#include <memory>
#include <string>

void p602()
{
    std::cout << "========== p602 ==========\n";

    size_t num = 0;
    std::cout << "Enter allocation size : ";
    std::cin >> num;

    std::allocator<std::string> stralloc;
    auto const p = stralloc.allocate(num);
    std::cout << "p : " << p << std::endl;

    auto q = p;
    stralloc.construct(q++);
    stralloc.construct(q++, 10, 'c');
    stralloc.construct(q++, "hi");

    //std::cout << "Constructed " << stralloc.max_size() << std::endl;

    std::string buf;
    for (size_t i = 0; i < num; ++i) {
        std::cout << p+i << " : " << p[i] << std::endl;
    }

    while (q != p) {
        stralloc.destroy(--q);
    }

    stralloc.deallocate(p, num);
}

void p604()
{
    std::cout << "========== p604 ==========\n";
}

class StrVec {
    std::string* elements;
    std::string* first_free;
    std::string* cap;
    std::allocator<std::string> alloc;
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();
    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; };
private:
};

int main()
{
    p602();
    p604();
}
