// JSON simple example
// This example does not handle errors.

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;


std::string Json(){
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    
    writer.StartObject();               // Between StartObject()/EndObject(), 
    
    writer.Key("hello");                // output a key,
    writer.String("world");             // follow by a value.

    writer.Key("t");
    writer.Bool(true);

    writer.Key("f");
    writer.Bool(false);

    writer.Key("n");
    writer.Null();

    writer.Key("i");
    writer.Uint(123);

    writer.Key("pi");
    writer.Double(3.1416);

    writer.Key("a");
    writer.StartArray();                // Between StartArray()/EndArray(),
    for (unsigned i = 0; i < 4; i++){
        writer.Uint(i);                 // all values are elements of the array.
    }
    writer.EndArray();

    writer.EndObject();

    // {"hello":"world","t":true,"f":false,"n":null,"i":123,"pi":3.1416,"a":[0,1,2,3]}
    return s.GetString();
}


std::string clone(){
    Document doc;
    Document::AllocatorType& alloc = doc.GetAllocator();

    Value v1("foo");
    Value v2("good");
    
    doc.SetArray();
    doc.PushBack(v1, alloc);
    doc.PushBack(v2, alloc);

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);

    // ["foo","foo",{"array":["foo","foo"]}]
    return buffer.GetString();
}

std::string JsonResult(){
    
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    
    writer.StartObject();               // Between StartObject()/EndObject(), 
    
    writer.Key("result");
    
    writer.StartObject();
    writer.String("hello");
    writer.String("world");             // follow by a value.
    writer.Key("data");
    writer.StartArray();                // Between StartArray()/EndArray(),
    for (unsigned i = 0; i < 4; i++){
        writer.Uint(i);                 // all values are elements of the array.
    }
    writer.EndArray();
    writer.EndObject();

    writer.EndObject();
    return s.GetString();
}

int main() {
    std::cout<< Json()<< std::endl;
    std::cout<< clone()<< std::endl;
    std::cout<< JsonResult()<< std::endl;
    return 0;
}
