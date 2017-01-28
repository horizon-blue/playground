// Exercise 13.55
// Add an rvalue reference version of push_back to your StrBlob.
// written based on 13.26.cpp
// Xiaoyan Wang 01/28/2017
#ifndef EX_13_55_CPP
#define EX_13_55_CPP  // I usd .cpp instead of .h just for consistency of the
                      // names
#include <exception>
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>
using std::vector;
using std::string;

class StrBlobPtr;
class ConstStrBlobPtr;

// class StrBlob is mostly copied from 12.02.cpp
class StrBlob {
    friend StrBlobPtr;
    friend ConstStrBlobPtr;

public:
    typedef vector<string>::size_type size_type;

    // constructors
    StrBlob() : data(std::make_shared<vector<string>>()) {}
    StrBlob(std::initializer_list<string> il)
        : data(std::make_shared<vector<string>>(il)) {}
    // copy constructor
    StrBlob(const StrBlob& other)
        : data(std::make_shared<vector<string>>(*other.data)) {}

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    StrBlobPtr begin();
    StrBlobPtr end();
    // const begin and end operations
    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;

    // add and remove elements
    void push_back(const string& t) { data->push_back(t); }
    void pop_back();

    // new: rvalue push_back
    void push_back(const string&& t) { data->push_back(std::move(t)); }

    // element access
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;

    // copy-assignment operator
    StrBlob& operator=(const StrBlob& other);

private:
    std::shared_ptr<vector<string>> data;
    // throw msg if data[i] isn't valid
    void check(size_type i, const string& msg) const {
        if(i >= data->size())
            throw std::out_of_range(msg);
    }
};

class StrBlobPtr {
public:
    // constructors
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob& sb, std::size_t sz = 0) : dataptr(sb.data), curr(sz) {}

    string& deref() const;
    StrBlobPtr& incr();

    friend bool isequal(const StrBlobPtr& sbptr1, const StrBlobPtr& sbptr2);

private:
    // helper function
    std::shared_ptr<vector<string>> check(std::size_t pos,
                                          const string& msg) const;
    // data
    std::weak_ptr<vector<string>> dataptr;
    std::size_t curr;
};

class ConstStrBlobPtr {
public:
    // constructors
    ConstStrBlobPtr() : curr(0) {}
    // the first parameter should be of the type const StrBlob &
    ConstStrBlobPtr(const StrBlob& sb, std::size_t sz = 0)
        : dataptr(sb.data), curr(sz) {}

    string& deref() const;
    ConstStrBlobPtr& incr();

    friend bool isequal(const ConstStrBlobPtr& sbptr1,
                        const ConstStrBlobPtr& sbptr2);

private:
    // helper function
    std::shared_ptr<vector<string>> check(std::size_t pos,
                                          const string& msg) const;
    // data
    std::weak_ptr<vector<string>> dataptr;
    std::size_t curr;
};

StrBlob& StrBlob::operator=(const StrBlob& other) {
    if(this == &other)
        return *this;
    data = std::make_shared<vector<string>>(*other.data);
}


void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

inline StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

inline ConstStrBlobPtr StrBlob::cbegin() const {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const {
    return ConstStrBlobPtr(*this, data->size());
}

string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    auto p = check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

std::shared_ptr<vector<string>> StrBlobPtr::check(std::size_t pos,
                                                  const string& msg) const {
    // test to see whether the vector pointed by the weak_ptr is still around
    auto ptr = dataptr.lock();
    if(!ptr)
        throw std::runtime_error("unbound StrBlobPtr");
    if(pos >= ptr->size())
        throw std::out_of_range(msg);
    return ptr;
}

string& ConstStrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() {
    auto p = check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

std::shared_ptr<vector<string>> ConstStrBlobPtr::check(
    std::size_t pos, const string& msg) const {
    // test to see whether the vector pointed by the weak_ptr is still around
    auto ptr = dataptr.lock();
    if(!ptr)
        throw std::runtime_error("unbound ConstStrBlobPtr");
    if(pos >= ptr->size())
        throw std::out_of_range(msg);
    return ptr;
}

bool isequal(const StrBlobPtr& sbptr1, const StrBlobPtr& sbptr2) {
    auto ptr1 = sbptr1.dataptr.lock(), ptr2 = sbptr2.dataptr.lock();
    if(ptr1 == ptr2)
        return (!ptr1 || sbptr1.curr == sbptr2.curr);
    else
        return false;
}

bool isequal(const ConstStrBlobPtr& sbptr1, const ConstStrBlobPtr& sbptr2) {
    auto ptr1 = sbptr1.dataptr.lock(), ptr2 = sbptr2.dataptr.lock();
    if(ptr1 == ptr2)
        return (!ptr1 || sbptr1.curr == sbptr2.curr);
    else
        return false;
}

#endif