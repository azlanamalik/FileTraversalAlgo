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
    void addToChildFolder(node* const child){
        //we need to pass in a folder here so has to be a node as thats the purpose of the program
        if (!child){
            std::cout << "null pointer" << std::flush;
            return;
        }//cant traverse a null pointer
        this->ChildFolders.push_back(child);
    }
    void addToNonFolder(std::string nonFolderName){
        if (nonFolderName.empty()){
            std::cerr << "we cant push no name" << std::flush;
            return;
        }
        this->nonFolders.push_back(nonFolderName);
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
        std::stack <node> stackOfFolders;
        stackOfFolders.push(this->startAddressTraversal);
        std::vector <node> returnNodes{};
        //okay so directory iterator allows you to iterate 1 layer at a time
        //no extension (folder) add them to a queue BFS or stack DFS to traverse them individually
        try{
            while(!stackOfFolders.empty()){
            node currentDir = stackOfFolders.top();
            stackOfFolders.pop();
            for(auto const &file: std::filesystem::directory_iterator(currentDir.getFolderName())){
                std::cout << file.path() << "\n" << std::flush;
                if (file.is_directory()){
                    currentDir.addToChildFolder(new node(file.path().string()));
                    stackOfFolders.push(file.path().string());
                }
                if (!(file.path().empty())){
                    currentDir.addToNonFolder(file.path().string());
                }
            }            
        }
        }catch(const std::exception &err){
            //this is just a traversal catch as can be dangerous traversing a foreign environment without a fallback
            std::cerr << err.what() << "\n" << std::flush;
        }
               
        return returnNodes;
    }
};

int main (){
    PathToGraph path;
    return 0;
}