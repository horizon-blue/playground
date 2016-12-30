// Exercise 13.37
// Add members to the Message class to insert or remove a given Folder* into
// folders. These members are analogous to Folder's addMsg and remMsg
// operations.
// Written based on 13.36.h
// Xiaoyan Wang 12/29/2016
#ifndef __13_37_H__
#define __13_37_H__
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

    void addFolder(const Folder*);
    void remFolder(const Folder*);

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