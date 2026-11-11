#include <iostream>
#include <vector>
#include <filesystem>
#include <stack>
class node{
    private:
    std::vector <node*> ChildFolders {}; //traversable objects
    std::string folderName {};
    std::vector <std::string> nonFolders{};//non traversable objects
    public:
    node(std::string folderName){
        this->folderName = folderName;
    }
    void addToChild(node* const child){
        if (!child){
            std::cout << "null pointer" << std::flush;
            return;
        }
        this->ChildFolders.push_back(child);
    }

    std::string getFolderName(){
        return this->folderName;
    }
    void prettyPrint(){
        std::vector <std::string> prettyPrintChild {};
        for (auto const &childPointer: this->ChildFolders)
            prettyPrintChild.push_back(childPointer->getFolderName());
        for (auto const &printChild : prettyPrintChild)
            std::cout << printChild;
    }
};
class PathToGraph{
    private:
    std::string startAddressTraversal;
    public:
    PathToGraph(std::string const address){
        this->startAddressTraversal = address;
        this->doTraversal();
    }
    PathToGraph(){
        this->startAddressTraversal = '.';
        this->doTraversal();
    }
    std::vector <node> doTraversal(){
        std::stack <std::string> stackOfFolders;
        stackOfFolders.push(this->startAddressTraversal);
        std::vector <node> returnNodes{};
        //okay so directory iterator allows you to iterate 1 layer at a time
        //no extension (folder) add them to a queue BFS or stack DFS to traverse them individually
        try{
            while(!stackOfFolders.empty()){
            std::string currentDir = stackOfFolders.top();
            stackOfFolders.pop();
            for(auto const &file: std::filesystem::directory_iterator(currentDir)){
                std::cout << file.path() << "\n" << std::flush;
                if (file.path().extension().empty()){
                    stackOfFolders.push(file.path().string());
                }
            }
        }
        }catch(const std::exception &err){
            std::cerr << err.what() << "\n" << std::flush;
        }
               
        return returnNodes;
    }
};

int main (){
    PathToGraph path;
    return 0;
}