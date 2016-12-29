// Exercise 13.34
// Write the Message class as described in this section
// Xiaoyan Wang 12/29/2016
#ifndef __13_34_H__
#define __13_34_H__
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

#endif