Purpose:
get used to pointers in c++ and confident
learn how to create graphs in a real world solution
dont use any ai what so ever to code (only to read about specific documentation)
get used to the file system standard library import
outcomes:
create an algorithm that can traverse through a given path and find all the nodes

Potential issue:
DFS --> dont do resursive a huge file can cause a stack overflow
infinite traversal --> can a folder point to another folder??

approaches:
first we create a class that can represent its children and future nodes to traverse (this will be its pointers)
once traversing we put into a stack and can traverse through the FS where we can create nodes and children (differentiated by traversal and non traversable nodes)
each time we come across a NEW node we can add to the stack to traverse next
A new node should also be added to the parents node children list

SO we should be thinking about adding to the children list and stack to help create the graphical representation at the end
we could of done a hashmap approach but this approach was designed so i could get used to pointers, deferencing and also a list of pointers which is something i know but didnt have implimentation experience of. 
