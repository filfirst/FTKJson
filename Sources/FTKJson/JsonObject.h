//
//  JsonObject.h
//  FTKJson
//
//  Created by Alex Wang on 2013/12/15.
//  Copyright (c) 2013 FTK. All rights reserved.
//

#ifndef FTK_JSON_JSON_OBJECT_H_
#define FTK_JSON_JSON_OBJECT_H_


#include <utility>


namespace ftk {
namespace utility {


template <typename T>
class JsonObject {
public:
    JsonObject() = default;
    JsonObject(const T value) : value_(value) { }
    ~JsonObject() = default;

public:
    T&& get() {
        return std::forward<T>(value_);
    }

private:
    T value_;
};


} // namespace utility
} // namespace ftk


#endif // FTK_JSON_JSON_OBJECT_H_

