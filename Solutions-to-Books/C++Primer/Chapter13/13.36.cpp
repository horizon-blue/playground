// Exercise 13.36
// Design and implement the corresponding Folder class. That class should hold a
// set that points to the Message in that Folder.
// Written based on 13.34.cpp
// Xiaoyan Wang 12/29/2016
#include "13.36.h"

void Message::save(Folder& f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message& m) {
    for(auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message& m) : contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}

void Message::remove_from_Folders() {
    for(auto f : folders)
        f->remMsg(this);
}

Message::~Message() {
    remove_from_Folders();
}

Message& Message::operator=(const Message& rhs) {
    if(this == &rhs)
        return *this;
    remove_from_Folders();
    contents = rhs.contents;
    folders  = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message& lhs, Message& rhs) {
    if(&lhs == &rhs)
        return;
    using std::swap;
    for(auto f : lhs.folders)
        f->remMsg(&lhs);
    for(auto f : rhs.folders)
        f->remMsg(&rhs);

    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for(auto f : lhs.folders)
        f->addMsg(&lhs);
    for(auto f : rhs.folders)
        f->addMsg(&rhs);
}

Folder::Folder(const Folder& other) : name(str), messages(other.messages) {
    for(auto m : messages)
        m.folders.insert(this);
}

Folder::~Folder() {
    for(auto m : messages)
        m.folders.erase(this);
}

Folder& Folder::operator=(const Folder& other) {
    if(this == &other)
        return *this;
    for(auto m : messages)
        m.folders.erase(this);
    messages = other.messages;
    name     = other.name;
    for(auto m : messages)
        m.folders.insert(this);
    return *this;
}


inline void Folder::addMsg(const Message* m) {
    messages.insert(m);
}

inline void Folder::remMsg(const Message* m) {
    messages.erase(m);
}

void swap(Folder& lhs, Folder& rhs) {
    if(&lhs == &rhs)
        return;
    for(auto m : lhs.messages)
        m.folders.erase(this);
    for(auto m : rhs.messages)
        m.folders.erase(this);

    lhs.name     = rhs.name;
    lhs.messages = rhs.messages;

    for(auto m : lhs.messages)
        m.folders.insert(this);
    for(auto m : rhs.messages)
        m.folders.insert(this);
}