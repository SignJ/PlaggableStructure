//
// Created by gregdong on 3/27/20.
//

#include "Assignable_Pipe.h"


Pipe::Assignable_pipe::Assignable_pipe(const Plaggable_Class::Class_State &state, const std::string &name,
                                       const std::string &configPath, int inputCount, int outputCount,std::vector<Shared_Data*>* _p_sd_path)
        : Plaggable_Class(state, name, configPath, inputCount, outputCount, 0) {
    p_vector_SD_Path = _p_sd_path;
}

void Pipe::Assignable_pipe::UpdateConfig() {
    Plaggable_Class::UpdateConfig();
    {
        if (!p_Config_Path.empty())
        {
            p_Parameters = new Parameters::Parameters(p_Config_Path);
            p_Parameters->get("Common/S_Assigned_SD",S_Assigned_SD);

        }
        else
        {
            p_Parameters = NULL;
        }
    }

}

Shared_Data* Pipe::Assignable_pipe::searchRelation(std::vector<Shared_Data*> &_Registered_SD_Relations, int _id, int _id2){
    for (auto & _Registered_SD_Relation : _Registered_SD_Relations) {
        if (_id == _Registered_SD_Relation->description->SD_ID&& _id2 == _Registered_SD_Relation->description->SD_ID2)
        {
            return _Registered_SD_Relation;
        }
    }
    return NULL;

}

void Pipe::Assignable_pipe::InitialRegisteredSD() {
    // "1-1,2-1,5-1"
    int ID,ID2= 0 ;
    std::string t ;
    char * temp;
    temp= strtok((char *)S_Assigned_SD.c_str(),",");
    t=temp;
    while (temp)
    {
        int pos = (t.find('-'));
        ID = std::stoi(t.substr(0,pos));

        ID2 = std::stoi(t.substr(pos+1,t.length()-pos-1));
        if (ID==0&&ID2==0)
        {
            //不需要写入文件
            this->changeState(Plaggable_Class::Class_State::DISABLED);
            return ;
        }
        vector_Registered_Sd.push_back(searchRelation(*p_vector_SD_Path,ID,ID2));
        printf("添加: %s\n",vector_Registered_Sd[vector_Registered_Sd.size()-1]->description->Name.c_str());
//        printf("ID %d,ID2 %d,pos %d\n",ID,ID2,pos);
//        printf("%s\n",t.c_str());
        temp= strtok(NULL,",");
        if (temp!=NULL)
        {
            t=temp;
        }

    }

}


