// Another name for 12.22.cpp - implementation part
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <exception>
#include "strblob.h"
void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data -> pop_back();
}

string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data -> front();
}

string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data -> back();
}

const string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data -> front();
}

const string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data -> back();
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

std::shared_ptr<vector<string>> StrBlobPtr::check(std::size_t pos, const string &msg) const {
	// test to see whether the vector pointed by the weak_ptr is still around
	auto ptr = dataptr.lock();
	if (!ptr)
		throw std::runtime_error("unbound StrBlobPtr");
	if (pos >= ptr->size())
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

std::shared_ptr<vector<string>> ConstStrBlobPtr::check(std::size_t pos, const string &msg) const {
	// test to see whether the vector pointed by the weak_ptr is still around
	auto ptr = dataptr.lock();
	if (!ptr)
		throw std::runtime_error("unbound ConstStrBlobPtr");
	if (pos >= ptr->size())
		throw std::out_of_range(msg);
	return ptr;
}

bool isequal(const StrBlobPtr &sbptr1, const StrBlobPtr &sbptr2) {
	auto ptr1 = sbptr1.dataptr.lock(), ptr2 = sbptr2.dataptr.lock();
	if(ptr1 == ptr2)
		return (!ptr1 || sbptr1.curr == sbptr2.curr);
	else
		return false;
}

bool isequal(const ConstStrBlobPtr &sbptr1, const ConstStrBlobPtr &sbptr2) {
	auto ptr1 = sbptr1.dataptr.lock(), ptr2 = sbptr2.dataptr.lock();
	if(ptr1 == ptr2)
		return (!ptr1 || sbptr1.curr == sbptr2.curr);
	else
		return false;
}