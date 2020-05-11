//
// Created by gregdong on 1/19/20.
//

#include "Shared_Data.h"
#include "iostream"

#include <cstdarg>
Shared_Data::Shared_Data(Shared_Data_Description& _des) {
    description = &_des;
    Input_SD_Count = 0;
    Output_SD_Count = 0;
    SD_Data = NULL;
    pubInitialize();
}

void Shared_Data::AddInputSDR(int _count, Shared_Data_Description **_p) {
    v_p_InputSD.insert(v_p_InputSD.end(),_p);
    in_count.insert(in_count.end(),_count);
    Input_SD_Count++;

}

void Shared_Data::AddOutputSDR(int _count, Shared_Data_Description **_p) {
    v_p_OutputSD.insert(v_p_OutputSD.end(),_p);
    out_count.insert(out_count.end(),_count);
    Output_SD_Count++;
}

void Shared_Data::pubInitialize() {
//    v_p_InputSD.insert(v_p_InputSD.end(), NULL);
//    v_p_OutputSD.insert(v_p_OutputSD.end(), NULL);
    v_p_InputSD.clear();
    v_p_OutputSD.clear();
    SD_Data = NULL;
    Selected_Input_Pos=-1;

}

void Shared_Data::printID(Shared_Data& _s) {
//    printf("This is %d, 2nd id is %d.\n",_s.SD_ID,_s.SD_ID2);

}

void Shared_Data::printAllParents() {
    printf("parent: \n");
    for (int i = 0; i < Input_SD_Count; ++i) {
        for (int j = 0; j < (in_count[i]); ++j) {
            printf("This is %s.\n",v_p_InputSD[i][j]->Name.c_str());
        }

    }
}

void Shared_Data::printAllSons() {
    printf("son: \n");
    for (int i = 0; i < Output_SD_Count; ++i) {
        for (int j = 0; j < (out_count[i]); ++j) {
            printf("This is %s.\n",v_p_OutputSD[i][j]->Name.c_str());
        }

    }
}

Shared_Data::Shared_Data(Shared_Data_Description &_des, int _data_size) {

    description = &_des;
    Input_SD_Count = 0;
    Output_SD_Count = 0;
    SD_Data_Size = _data_size;
    pubInitialize();

}

void Shared_Data::createSDArea() {
    SD_Data = new char[SD_Data_Size];
    printf("创建SD实体: %s, 地址: %0xd\n",this->description->Name.c_str(),SD_Data);

}

void Shared_Data::destorySDArea() {
    if (SD_Data!= NULL)
    {
        delete[](SD_Data);
        SD_Data= NULL;
    }

}

Shared_Data_Description Shared_Data_Description::AssignPipe(Plaggable_Class *_pipe) {

    Shared_Data_Description scd(this->SD_ID, this->SD_ID2, this->Name,this->p_SDF);

    scd.p_Pipe = _pipe;
    return scd;
}
