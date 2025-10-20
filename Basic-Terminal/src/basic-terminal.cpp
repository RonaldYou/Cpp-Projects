#include "basic-terminal.h"
#include <sstream>

BasicTerminal::BasicTerminal(){
    root = new Node();
    root->name = "/";
    root->isDirectory = true;
    root->parent = nullptr;

    cwd = root;
}

int BasicTerminal::binarySearch(const std::vector<Node*>& arr, const std::string& target){
    int l = 0;
    int r = arr.size() - 1;

    if(arr.size() == 0){
        return 0;
    }

    while(l <= r){
        int mid = (r + l) / 2;
        if(mid >= 1 && target < arr[mid]->name && target > arr[mid-1]->name){
            return mid;
        }
        else if(mid == arr.size() - 1 && target > arr[mid]->name){
            return mid + 1;
        }

        if(target < arr[mid]->name){
            if(mid == 0){
                return 0;
            }
            r = mid - 1;
        }
        else{
            if(mid == 0){
                return 1;
            }
            l = mid + 1;
        }
    }

    return -1;
}

std::vector<std::string> BasicTerminal::splitPath(const std::string& path){
    std::vector<std::string>pathParts;
    std::stringstream ss(path);
    std::string tmp;

    while(std::getline(ss, tmp, '/')){
        if(!tmp.empty()){
            pathParts.push_back(tmp);
        }
    }

    return pathParts;
}


void BasicTerminal::pathTraverser(const std::string& path, bool removeFile){
    if(path[0] == '/'){
        cwd = root;
    }
    std::vector<std::string>pathComponents = splitPath(path);
    if(removeFile){
        pathComponents.pop_back(); //remove file if applicable
    }
    
    for(auto& component: pathComponents){
        if(component == "."){
            continue;
        }
        else if(component == ".."){
            if(cwd == root){
                continue;
            }
            cwd = cwd->parent;
        }
        else{
            int index = -1;
            for(int i = 0; i < cwd->children.size(); i++){
                Node* child = cwd->children[i];
                if(child->isDirectory && child->name == "/" + component){
                    index = i;
                }
            }
            if(index == -1){
                std::cout<<"Path Does Not Exist\n";
                return;
            }

            cwd = cwd->children[index];
        }
    }
}


//return list of files in sorted order with directories first
void BasicTerminal::ls(){
    std::vector<std::string>tmp;

    for(auto& child: cwd->children){
        tmp.push_back(child->name);
    }

    for(auto& file: tmp){
        std::cout << file << " ";
    }
    std::cout << std::endl;
}

void BasicTerminal::mkdir(std::string path){
    Node* originalDir = cwd;
    pathTraverser(path, true);
    std::string dirName = splitPath(path).back();
    int insertIndex = binarySearch(cwd->children, "/" + dirName);

    if(insertIndex == -1){
        std::cout<<"Directory Already Exists"<<std::endl;
        return;
    }

    Node* newDir = new Node();
    newDir->name = "/" + dirName;
    newDir->isDirectory = true;
    newDir->parent = cwd;

    cwd->children.insert(cwd->children.begin() + insertIndex, newDir);
    cwd = originalDir;
}

void BasicTerminal::touch(std::string path){
    Node* originalDir = cwd;
    pathTraverser(path, true);
    std::string fileName = splitPath(path).back();
    int insertIndex = binarySearch(cwd->children, fileName);

    if(insertIndex == -1){
        std::cout<<"File Already Exists"<<std::endl;
        return;
    }

    Node* newDir = new Node();
    newDir->name = fileName;
    newDir->isDirectory = false;
    newDir->parent = cwd;

    cwd->children.insert(cwd->children.begin() + insertIndex, newDir);
    cwd = originalDir;
}

void BasicTerminal::pwd(){
    std::vector<std::string>reversePath;

    if(cwd == root){
        std::cout<<root->name;
        return;
    }

    while(cwd != root){
        reversePath.push_back(cwd->name);
        cwd = cwd -> parent;
    }


    for(int i = reversePath.size() - 1; i >= 0; i--){
        std::cout<<reversePath[i];
    }
    std::cout<<std::endl;
}

void BasicTerminal::cd(std::string path){
    pathTraverser(path, false);
}

void BasicTerminal::cat(std::string name){
    int index = -1;
    for(int i = 0; i < cwd->children.size(); i++){
        if(cwd->children[i]->name == name){
            index = i;
        }
    }

    for(auto& line: cwd->children[index]->data){
        std::cout<<line<<'\n';
    }
}



