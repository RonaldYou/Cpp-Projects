#ifndef BASIC_TERMINAL_H
#define BASIC_TERMINAL_H

#include<cstdlib>
#include<vector>
#include <iostream>

class BasicTerminal{
    public:
        BasicTerminal();
        void ls();
        void mkdir(std::string dirName);
        void pwd();
        void cd(std::string path);
        void touch(std::string name);
        void cat(std::string name);

    private:
        struct Node{
            std::string name;
            Node* parent;
            std::vector<Node*> children;
            std::vector<std::string>data;
            bool isDirectory;
        };

        int binarySearch(const std::vector<Node*>& arr, const std::string& target);
        std::vector<std::string> splitPath(const std::string& path);
        void pathTraverser(const std::string& path, bool removeFile);

        Node* root;
        Node* cwd;
};





#endif //BASIC_TERMINAL_H