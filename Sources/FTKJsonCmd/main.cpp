//
//  main.cpp
//  FTKJsonCmd
//
//  Created by Alex Wang on 2013/12/15.
//  Copyright (c) 2013 FTK. All rights reserved.
//

#include <FTKJson/JsonObject.h>

#include <iostream>


int main(int argc, const char * argv[]) {
    ftk::utility::JsonObject<int> jobj(2000);
    char i = jobj.get();
    std::cout << std::hex << i << std::endl;
    
    return 0;
}

