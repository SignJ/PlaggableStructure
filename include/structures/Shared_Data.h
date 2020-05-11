//
// Created by gregdong on 1/19/20.
//

#ifndef PLAGGABLE_SHARED_DATA_H
#define PLAGGABLE_SHARED_DATA_H

#include <iosfwd>
#include "vector"
#include <string>
#include "plaggable_class.h"
#include <string.h>
#include "SD_Format.h"
class Shared_Data_Class;


/**
 * SD的描述记录类;
 *
 * 包含SD的识别信息,其中有1级ID(记录该SD的类别名称)与2级ID(记录该SD的个数名称);
 * 还有SD的路径层数
 * 还包括该SD在相应链接时的指向操作(流动管道),该管道在指定输入输出关系时加入,同时时需要复制该SDD
 */
class Shared_Data_Description{
public:
    int SD_ID;
    int SD_ID2;
    std::string Name;
    //在记录path时的路径层数记录
    int path_level;
    //指向管道操作的指针
    Plaggable_Class* p_Pipe;
    SD_Format* p_SDF;
    Shared_Data_Description(const Shared_Data_Description& scd)
    {
        SD_ID = scd.SD_ID;
        SD_ID2 = scd.SD_ID2;
        p_Pipe = scd.p_Pipe;
        memcpy(&Name,&scd.Name,scd.Name.capacity());
        path_level = scd.path_level;
        printf("调用拷贝构造函数SCD\n");

    }
    void operator=(const Shared_Data_Description& scd){
        printf("调用重载操作符SCD\n");
    }
    Shared_Data_Description(int _sd_id, int _sd_id_2, std::string _name,SD_Format* _sd_format){
        SD_ID = _sd_id;
        SD_ID2 = _sd_id_2;
        Name = std::move(_name);
        p_SDF = _sd_format;
        path_level = 0;
    };
    //向该SD的数据流向加入流动管道.
    Shared_Data_Description AssignPipe(Plaggable_Class* _pipe);
};
/**
 * 描述SD之间的联系:指定输入输出的SD
 * 描述当前SD: 定义数据结构,数据的生成和释放char_array
 */
class Shared_Data {
public:


    Shared_Data_Description* description;

    //数据区 当运行时生成 非运行时销毁
    //初始时为空指针,仅指定类型,当需要运行,如Path生成后实体化;
    //在取消时和析构时都删除
    char *SD_Data;
    int SD_Data_Size;//初始化后固定

    //输入SD的个数
    int Input_SD_Count;
    //输入SD的类型指针
    //Shared_Data ** p_Input_SD_Type;
    std::vector<Shared_Data_Description **> v_p_InputSD;
    //每个输入的与&输入个数
    std::vector<int>  in_count;
    //记录该SD的选择的输入的位置,-1为没有选择输入
    int Selected_Input_Pos;
    //输出SD的个数
    int Output_SD_Count;
    std::vector<Shared_Data_Description **> v_p_OutputSD;
    //输出SD的类型指针
    //Shared_Data ** p_Output_SD_Type;
    std::vector<int>  out_count;

    Shared_Data(Shared_Data_Description& _des);
    /**
     * 初始化SD的数据长度
     * @param _des
     * @param _data_size
     */
    Shared_Data(Shared_Data_Description& _des, int _data_size);
    Shared_Data();
    void createSDArea();
    void destorySDArea();
    void AddInputSDR(int _count, Shared_Data_Description** _p);
    void AddOutputSDR(int _count, Shared_Data_Description ** _p);
    void pubInitialize();
    void printID(Shared_Data& _s);
    void printAllParents();
    void printAllSons();

    ~Shared_Data(){
        if (SD_Data!= NULL)
        {
            delete   SD_Data;
            SD_Data= NULL;
        }
//        for (int i = 0; i < Input_SD_Count; ++i) {
//            delete [] p_Input_SD_Type[i];
//        }
//        for (int i = 0; i < Output_SD_Count; ++i) {
//            delete [] p_Output_SD_Type[i];
//        }
//        delete [] p_Input_SD_Type;
//        delete [] p_Output_SD_Type;

    }

};

#endif //PLAGGABLE_SHARED_DATA_H
