// Exercise 13.36
// Design and implement the corresponding Folder class. That class should hold a
// set that points to the Message in that Folder.
// Written based on 13.34.h
// Xiaoyan Wang 12/29/2016
#ifndef __13_36_H__
#define __13_36_H__
#include <set>
#include <string>

class Folder;
class Message {
    friend class Folder;

public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string& str = "") : contents(str) {}

    // copy control to manage pointers to this message
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    // add/remove this Message from the specified Folder's set of messages
    void save(Folder&);
    void remove(Folder&);

private:
    std::string contents;
    std::set<Folder*> folders;

    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message&);
    // remove this Message from every Folder in folders
    void remove_from_Folders();
};

class Folder {
public:
    Folder(const std::string& str = "") : name(str) {}
    Folder(const Folder&);
    ~Folder();
    Folder& operator=(const Folder&);

    void addMsg(const Message*);
    void remMsg(const Message*);

private:
    std::string name;
    std::set<Message*> messages;
};

#endif