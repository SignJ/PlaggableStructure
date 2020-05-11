//
// Created by gregdong on 1/15/20.
//

#ifndef AD_READER_PLAGGABLE_CLASS_H
#define AD_READER_PLAGGABLE_CLASS_H

#include <string>

#include "SD_Format.h"
#include "SharedResource.h"
#include "sys/time.h"
class Shared_Data;


/**
 * 可插拔类的虚基类
 * 控制函数为analyseInput(),update(),refreshOutput().
 * 当置位为Enable时按正常子类情况运行
 * 当置位为Disable时都为空函数
 */
class Plaggable_Class {

public:
    /*
* 类的运行情况
*/
    enum Class_State {
        ENABLED, DISABLED
    };

    /**
     * 当前的启用情况
     */
    Class_State classState;

protected:

    //SharedResource 区
    std::map<std::string,SharedResource::SharedResource_Base* >* p_SharedResourceSpace;

    explicit Plaggable_Class(const Plaggable_Class::Class_State &_state, std::string _name, std::string _config_path,
                             int _input_count, int _output_count,
                             std::map<std::string, SharedResource::SharedResource_Base *> *_p_SharedResourceSpace);
    //endof SharedResource
    /**
     * 指向无参数无返回值的函数指针,用作调整选用类的执行与非执行情况
     */
    typedef void (Plaggable_Class::*p_null_func_void)();
    /**
 * 实际初始化的函数指针
 */
    p_null_func_void p_null_func_void_actual_init;

    /**
     * 实际执行的函数指针
     */
    p_null_func_void p_null_func_void_actual_input;
    /**
   * 实际执行的函数指针
    */
    p_null_func_void p_null_func_void_actual_update;
    /**
   * 实际执行的函数指针
    */
    p_null_func_void p_null_func_void_actual_output;
    /**
     *
     */
    p_null_func_void p_null_func_void_actual_selffree;

    /**
     * 更新频率控制部分
     *
     */
     double UpdateHz; // 更新操作的频率,hz为单位
     struct timeval TVal;//时间结构
     double TimeDiff; // 更新操作的时间差
     double LastTime; //上次更新的时间值
     double CurrTime; //当前获得到的时间值
     double RealUpdateHz;//实际的更新频率
     double RealTimeDiff;//实际的时间差值
     double EndTime;
     double RunningTime;//该Pipe运行的时间

public:

    //对设置部分的操作

    //更新设置相关
    std::string  p_Config_Path;
    Parameters::Parameters * p_Parameters;
    /**
     * 在该函数中特例化参数的读取.
     * EG
     * if (p_Parameters!=NULL)
     *   {
     *        p_Parameters->get("Common/Serial_Port_Name",Serial_Port_Name);
     *       p_Parameters->get("Common/Baudrate",Baudrate);
     *      }
     *
     *      UpdateHz = 45;
     *   SetUpdateHZ(UpdateHz);
     */
    virtual void UpdateConfig();

    /**
     * 链接数据SD的指针
     * 在生成SD后进行Hock
     * 在Disable后进行dehock
     *
     */
     //输入SD
     Shared_Data ** p_SD_Input;
     //输入的SD的个数
     int SD_Input_Count;


     //输出SD
     Shared_Data ** p_SD_Output;
     //输出的SD的个数
     int SD_Output_Count;


     /**
      * 对数据SD的操作
      */
      /**
       *
       * @param _inputSD  输入的sd的数据指针
       * @param _number 输入的sd为第几个sd
       */
      void AddInputHock(Shared_Data * _inputSD,int _number);
      void AddOutputHock(Shared_Data* _outputSD,int _number);
      void SDDehock();


      /**
       * 该PIPE的名字
       */
      std::string PC_Name;

      void SetUpdateHZ(double _hz);



private:
    /**
     * 初始化的公共部分
     */
    void pubInitializer(const Plaggable_Class::Class_State &_state, std::string _name, std::string _config_path,
                        int _input_count, int _output_count);

    /**
    * 初始化该类
     * 需要的任务
     * 1. 使用UpdateConfig
     * 2. 初始化分化pInput和pOutput指针
     * 3. new一些相关的量
    */
    virtual void initialize() = 0;
    /**
     * 分析该类的输入数据
     */
    virtual void analyseInput() = 0;

    /**
     * 根据分析后的输入数据来进行该类需要的数据处理操作
     */
    virtual void update() = 0;

    /**
     * 更新数据结果提供给后续的模块进行分析
     */
    virtual void refreshOutput() = 0;

    /**
     * 进行释放资源
     */
    virtual void selfFree();

    void blankIniFunc();

    /**
     * 空函数
     */
    void blankAnaFunc();
    /**
 * 空函数
 */
    void blankUpFunc();
    /**
 * 空函数
 */
    void blankRefFunc();
    void blankSelfFree();
/*    *//**
     * 公用初始化操作虚函数
     *//*
    virtual void pubInitialize() = 0;*/
     void printRunningTime();

protected:
    void exeInitialize();
    void exeAnalyse();
    void exeUpdate();
    void exeRefreshOutput();
    void exeSelfFree();
public:

    void DynaInitialize();
    void DynaAnalyseInput();
    void DynaUpdate();
    void DynaRefreshOutput();
    void DynaSelfFree();
    void changeState(const Plaggable_Class::Class_State &_state);
    /**
     * 可插拔的类别构造函数,控制函数为analyseInput(),update(),refreshOutput().
     * 当置位为Enable时按正常子类情况运行
     * 当置位为Disable时都为空函数
     * @param _state 枚举
     */
    explicit Plaggable_Class(const Plaggable_Class::Class_State &_state, std::string _name, std::string _config_path,
                             int _input_count, int _output_count);


    ~Plaggable_Class();

    /**
     * 拷贝构造函数
     * @param _class
     */
    Plaggable_Class(const Plaggable_Class &_class);

};

#endif //AD_READER_PLAGGABLE_CLASS_H
