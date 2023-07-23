//
//  directory.hpp
//  Project1
//
//  Created by Jared Bumgardner on 9/19/19.
//  Copyright © 2019 Jared Bumgardner. All rights reserved.
//

#ifndef directory_hpp
#define directory_hpp

#include <string>

class Node{
  //access
  public:
    std:: string name;
    Node* left;
    Node* right;
};

class Directory{
  //access
  public:
    Node head;
    Node curr;
};

#endif /* directory_hpp */
