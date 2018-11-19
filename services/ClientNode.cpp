//
//  ClientNode.cpp
//  NetDrive
//
//

#include "ClientNode.hpp"


vector<chunk> ClientNode::splitFile(string fileName, vector<chunk>& chunks)
{
    
    vector<chunk> ck;//TODOD
    
    int peek = 0, i = 0;
    string line;
    string buffer = "";
    
    //  reading file to buffer
    try
    {
        ifstream i_file(fileName);
        while (!i_file.eof())
        {
            getline(i_file, line);
            buffer+=line;
            buffer+="\n";
        }
        i_file.close();
    }
    catch (exception const& e)
    {
        cerr << "Error occured while reading file!\n" << e.what() << endl;
    }
    
    
    //  splitting file into chunks
    for(auto &size: sizes)
    {
        try
        {
            ofstream o_file(fileName+"-"+to_string(i++));
            o_file << buffer.substr(peek, size);
            o_file.close();
            peek+=size;
            cout << endl;
        }
        catch (exception const& e)
        {
            cerr << "Error ocurred while writing file!\n" << e.what() << endl;
        }
    }
    //TODO
    return chunks;
    
} 


bool ClientNode::transferFileToCloud(vector<chunk>& chunks){
    for(chunk c : chunks){
        transferChunkToStorageNode(c);
    }
    return true;
}

bool ClientNode::transferChunkToStorageNode(chunk chunk){
    //TODO;
    
    
    
    
    
    return true;
}
