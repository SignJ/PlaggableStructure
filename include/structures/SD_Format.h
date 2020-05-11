//
// Created by gregdong on 3/12/20.
//

#ifndef PLAGGABLE_SD_DEFINITION_H
#define PLAGGABLE_SD_DEFINITION_H

#include "vector"
#include "iostream"
#include <string.h>
#include "utilities/config/parameters.h"

class SD_Format {
public:
    int SD_Size;

    std::vector<int> DataSpiltPos;
    //log文件相关
    int Record_Column_Count;
    std::string * p_names;



    virtual void cpydata(double *p_dest){};
    virtual void cpyname(std::string *p_dest){};
    virtual void Record_Initial_Name(){};


    /**
     * 根据输入区来更新输入输出的大小范围,Pos的位置向量
     */
    virtual void Initialize() = 0;
    virtual void analyseInput(char* _input) = 0;
    virtual void updateOutput(char* _output) = 0;

    void AddInitialArray(int _start_pos,int _cell_size,int _length){
        for (int i = 0; i < _length; ++i) {
            //记录开始的位置
            DataSpiltPos.push_back(_start_pos+i*_cell_size);
            SD_Size+=_cell_size;
        }
    }
    void AnalyseInputArray(int _cell_size,int _length, void* _source, void* _dest )
    {
        memcpy(_dest,_source,_cell_size*_length);

    }
    void RefreshOutputArray(int _cell_size,int _length, void* _source, void* _dest )
    {
        memcpy(_dest,_source,_cell_size*_length);

    }


};




#endif //PLAGGABLE_SD_DEFINITION_H
