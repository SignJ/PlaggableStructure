//
// Created by gregdong on 1/15/20.
//

#include "plaggable_class.h"
#include "Shared_Data.h"


Plaggable_Class::Plaggable_Class(const Plaggable_Class::Class_State &_state, std::string _name,
                                 std::string _config_path,
                                 int _input_count, int _output_count) {


    pubInitializer(_state, _name, _config_path, _input_count, _output_count);

}

Plaggable_Class::~Plaggable_Class() {
    if (p_SD_Input!= NULL)
    {
        delete[](p_SD_Input);
        p_SD_Input = NULL;
    }
    if (p_SD_Output!= NULL)
    {
        delete[](p_SD_Output);
        p_SD_Output = NULL;
    }
};

Plaggable_Class::Plaggable_Class(const Plaggable_Class &_class) {
    classState = _class.classState;
    if (classState == Class_State::ENABLED)
    {
        p_null_func_void_actual_init = ((p_null_func_void)&::Plaggable_Class::initialize);
        p_null_func_void_actual_input = ((p_null_func_void)&::Plaggable_Class::analyseInput);
        p_null_func_void_actual_update = ((p_null_func_void)&::Plaggable_Class::update);
        p_null_func_void_actual_output = ((p_null_func_void)&::Plaggable_Class::refreshOutput);
        p_null_func_void_actual_selffree = ((p_null_func_void)&::Plaggable_Class::selfFree);
    }else{
        p_null_func_void_actual_init = ((p_null_func_void)&Plaggable_Class::blankIniFunc);
        p_null_func_void_actual_input = ((p_null_func_void)&Plaggable_Class::blankAnaFunc);
        p_null_func_void_actual_update = ((p_null_func_void)&Plaggable_Class::blankUpFunc);
        p_null_func_void_actual_output = ((p_null_func_void)&Plaggable_Class::blankRefFunc);
        p_null_func_void_actual_selffree = ((p_null_func_void)&Plaggable_Class::blankSelfFree);

    }

}

void Plaggable_Class::exeInitialize() {
    (this->*p_null_func_void_actual_init)();
}


void Plaggable_Class::exeAnalyse() {
    (this->*p_null_func_void_actual_input)();

}

void Plaggable_Class::exeUpdate() {
    (this->*p_null_func_void_actual_update)();
}

void Plaggable_Class::exeRefreshOutput() {
    (this->*p_null_func_void_actual_output)();
}

void Plaggable_Class::blankAnaFunc() {

}

void Plaggable_Class::blankUpFunc() {

}

void Plaggable_Class::blankRefFunc() {

}

void Plaggable_Class::blankIniFunc() {

}

void Plaggable_Class::DynaAnalyseInput() {
    exeAnalyse();

}

void Plaggable_Class::DynaUpdate() {
    //更新时间的判定
    if (classState==ENABLED)
    {
        gettimeofday(&TVal,NULL);
        CurrTime = TVal.tv_sec + (double) (TVal.tv_usec)/1000000;
        RealTimeDiff = CurrTime - LastTime;
        if (RealTimeDiff>=TimeDiff)
        {
            //计算实际的频率
            RealUpdateHz = 1/RealTimeDiff;
            printf("%s 的实际更新频率为:%f.\n",this->PC_Name.c_str(),RealUpdateHz);
            //执行并更新LastTime
            LastTime = CurrTime;
            exeUpdate();
        }
        gettimeofday(&TVal,NULL);
        EndTime = TVal.tv_sec + (double) (TVal.tv_usec)/1000000;
        RunningTime+= EndTime - CurrTime;

    }


}

void Plaggable_Class::DynaRefreshOutput() {
    exeRefreshOutput();
}

void Plaggable_Class::DynaInitialize() {
    exeInitialize();

}



void Plaggable_Class::SDDehock() {
    p_SD_Input = NULL;
    p_SD_Output = NULL;
    SD_Input_Count = 0;
    SD_Output_Count = 0;

}

void Plaggable_Class::AddInputHock(Shared_Data *_inputSD, int _number) {

    p_SD_Input[_number] = _inputSD;
    printf("%s接入输入SD:%s,地址是:%p\n",this->PC_Name.c_str(),_inputSD->description->Name.c_str(),_inputSD->SD_Data);
}

void Plaggable_Class::AddOutputHock(Shared_Data *_outputSD, int _number) {
    p_SD_Output[_number] = _outputSD;
    printf("%s接入输出SD:%s,地址是:%p\n",this->PC_Name.c_str(),_outputSD->description->Name.c_str(),_outputSD->SD_Data);
}

void Plaggable_Class::changeState(const Plaggable_Class::Class_State &_state) {
    if (_state == Class_State::ENABLED)
    {
        classState = Class_State ::ENABLED;
        p_null_func_void_actual_init = ((p_null_func_void)&::Plaggable_Class::initialize);
        p_null_func_void_actual_input = ((p_null_func_void)&::Plaggable_Class::analyseInput);
        p_null_func_void_actual_update = ((p_null_func_void)&::Plaggable_Class::update);
        p_null_func_void_actual_output = ((p_null_func_void)&::Plaggable_Class::refreshOutput);
        p_null_func_void_actual_selffree = ((p_null_func_void)&::Plaggable_Class::selfFree);
    }else{
        classState = Class_State ::DISABLED;
        p_null_func_void_actual_init = ((p_null_func_void)&Plaggable_Class::blankIniFunc);
        p_null_func_void_actual_input = ((p_null_func_void)&Plaggable_Class::blankAnaFunc);
        p_null_func_void_actual_update = ((p_null_func_void)&Plaggable_Class::blankUpFunc);
        p_null_func_void_actual_output = ((p_null_func_void)&Plaggable_Class::blankRefFunc);
        p_null_func_void_actual_selffree = ((p_null_func_void)&Plaggable_Class::blankSelfFree);

    }

}

void Plaggable_Class::UpdateConfig(){
    {
        if (!p_Config_Path.empty())
        {
            p_Parameters = new Parameters::Parameters(p_Config_Path);
            /**
             * 在子类中添加各项数据
             */
        }
        else
        {
            p_Parameters = NULL;
        }
    }
}

Plaggable_Class::Plaggable_Class(const Plaggable_Class::Class_State &_state, std::string _name,
                                 std::string _config_path,
                                 int _input_count, int _output_count,
                                 std::map<std::string, SharedResource::SharedResource_Base *> *_p_SharedResourceSpace) {

    pubInitializer(_state, _name, _config_path, _input_count, _output_count);
    p_SharedResourceSpace = _p_SharedResourceSpace;

}

void Plaggable_Class::selfFree() {

}

void Plaggable_Class::blankSelfFree() {

}

void Plaggable_Class::exeSelfFree() {
    (this->*p_null_func_void_actual_selffree)();

}

void Plaggable_Class::DynaSelfFree() {
    printRunningTime();
    exeSelfFree();

}

void
Plaggable_Class::pubInitializer(const Plaggable_Class::Class_State &_state, std::string _name, std::string _config_path,
                                int _input_count, int _output_count) {
    if (_state == Class_State::ENABLED)
    {
        classState = Class_State ::ENABLED;
        p_null_func_void_actual_init = ((p_null_func_void)&::Plaggable_Class::initialize);
        p_null_func_void_actual_input = ((p_null_func_void)&::Plaggable_Class::analyseInput);
        p_null_func_void_actual_update = ((p_null_func_void)&::Plaggable_Class::update);
        p_null_func_void_actual_output = ((p_null_func_void)&::Plaggable_Class::refreshOutput);
        p_null_func_void_actual_selffree = ((p_null_func_void)&::Plaggable_Class::selfFree);
    }else{
        classState = Class_State ::DISABLED;
        p_null_func_void_actual_init = ((p_null_func_void)&Plaggable_Class::blankIniFunc);
        p_null_func_void_actual_input = ((p_null_func_void)&Plaggable_Class::blankAnaFunc);
        p_null_func_void_actual_update = ((p_null_func_void)&Plaggable_Class::blankUpFunc);
        p_null_func_void_actual_output = ((p_null_func_void)&Plaggable_Class::blankRefFunc);
        p_null_func_void_actual_selffree = ((p_null_func_void)&Plaggable_Class::blankSelfFree);

    }
    PC_Name = _name;
    SD_Input_Count = _input_count;
    SD_Output_Count = _output_count;
    p_SD_Input = new Shared_Data*[SD_Input_Count];
    p_SD_Output = new Shared_Data*[SD_Output_Count];
    if (_config_path.compare("")==0)
    {
        printf("Config is Null\n");
        p_Config_Path = "";
    } else{
        p_Config_Path =_config_path;
    }
    RunningTime = 0;



}

void Plaggable_Class::SetUpdateHZ(double _hz) {
    //Frequency
    UpdateHz = _hz;
    TimeDiff = 1/UpdateHz;
    gettimeofday(&TVal,NULL);
    LastTime = TVal.tv_sec + (double) (TVal.tv_usec)/1000000;

}

void Plaggable_Class::printRunningTime() {
    printf("%s consuming %f sec totally\n",PC_Name.c_str(),RunningTime);

};








