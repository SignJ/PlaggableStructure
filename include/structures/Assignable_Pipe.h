//
// Created by gregdong on 3/27/20.
//

#ifndef EXO_STRUCT_ASSIGNABLE_PIPE_H
#define EXO_STRUCT_ASSIGNABLE_PIPE_H

#include "plaggable_class.h"
//#include "../../exe/Structure.h"
#include "Shared_Data.h"
#include <iostream>
namespace Pipe{
    /**
     * 可指定链接(在配置文件中)的可插拔PIPE类,主要用于系统的附属操作
     * 现有的如文件记录数据;屏幕输出等
     *
     * 特有功能包括自主通过config文件来生成联系关系
     */
    class Assignable_pipe:public Plaggable_Class{
    protected:
        Shared_Data* searchRelation(std::vector<Shared_Data*> &_Registered_SD_Relations, int _id, int _id2);
        std::string S_Assigned_SD; // 记录指配的SD
        std::vector<Shared_Data*> vector_Registered_Sd;
        std::vector<Shared_Data*> * p_vector_SD_Path;
        void InitialRegisteredSD();



    public:

        Assignable_pipe(const Class_State &state, const std::string &name, const std::string &configPath,
                        int inputCount, int outputCount,std::vector<Shared_Data*>* _p_sd_path);

        void UpdateConfig() ;


    };
}

#endif //EXO_STRUCT_ASSIGNABLE_PIPE_H
