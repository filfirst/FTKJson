//
//  main.cpp
//  FTKJsonCmd
//
//  Created by Alex Wang on 2013/12/15.
//  Copyright (c) 2013 FTK. All rights reserved.
//

#include <FTKJson/JsonObject.h>

#include <iostream>
#include <setjmp.h>

#include <pthread.h>


void* TaskThread(void *arg) {
    int *no = static_cast<int*>(arg);
    std::cout << "This is thread " << *no << "..." << std::endl;
    
    int *res = new int;
    *res = 333;
    
    return res;
}


int main(int argc, const char * argv[]) {
    pthread_t taskThread;
    int rc;
    
    int threadNo = 33;
    int *tres = nullptr;
    
    rc = pthread_create(&taskThread, NULL, TaskThread, &threadNo);
    
    pthread_join(taskThread, reinterpret_cast<void **>(&tres));
    
    std::cout << "Thread return: " << *tres << std::endl;
    
    for (auto i = 0; i < 1000; ++i) {
        rc = pthread_create(&taskThread, NULL, TaskThread, &threadNo);
    }
    
    for (auto i = 0; i < 1000; ++i) {
        tres = new int[1024];
    }
    
//    delete tres;
    
    jmp_buf env;
    int val;
    
    val = setjmp(env);
    
    if (val == 0)
        std::cout << "Initial run..." << val << std::endl;
    else
        std::cout << "Jump run..." << val << std::endl;
    
//    ftk::utility::JsonObject<int> jobj(2000);
//    char i = jobj.get();
//    std::cout << std::hex << i << std::endl;
    
    if (val == 0)
        longjmp(env, 100);

    if (val > 1)
        longjmp(env, val - 1);

    return 0;
}

