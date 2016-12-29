// Exercise 13.34
// Write the Message class as described in this section
// Xiaoyan Wang 12/29/2016
#include "13.34.h"

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