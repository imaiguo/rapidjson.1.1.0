
#include <iostream>
#include <fstream>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/ostreamwrapper.h"
#include "rapidjson/istreamwrapper.h"

using namespace rapidjson;

void WriteJson(std::string json, std::string path){
    Document doc;
    doc.Parse(json.c_str());

    std::ofstream file(path, std::ios::out | std::ios::trunc);
    if(!file.is_open()){
        std::cout<< "create file:[" << path << "] error." << std::endl;
        return;
    }

    OStreamWrapper fileStrem(file);
    PrettyWriter<OStreamWrapper> writer(fileStrem);
    doc.Accept(writer);
    fileStrem.Flush();
    file.close();
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
    
    WriteJson(s.GetString(), "result.json");
    return s.GetString();
}

std::string ParseStringJosn(){
    // 1. Parse a JSON string into DOM.
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document doc;
    doc.Parse(json);

    // 2. Modify it by DOM.
    Value& s = doc["stars"];
    s.SetInt(s.GetInt() + 1);

    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);

    return buffer.GetString();
}

std::string ParseJosnFile(std::string path){

    std::ifstream config(path);
    if(!config.is_open()){
        std::cout<< "open file:[" << path << "] error." << std::endl;
        return;
    }

    IStreamWrapper stream(config);
    Document doc;
    doc.ParseStream(stream);

    // Value& s = doc["stars"];
    // s.SetInt(s.GetInt() + 1);

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);

    return buffer.GetString();
}

int main() {
    std::cout<< ParseStringJosn()<< std::endl;
    std::cout<< JsonResult()<< std::endl;
    return 0;
}
