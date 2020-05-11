//
// Created by gregdong on 4/2/20.
//

#ifndef EXO_STRUCT_SHAREDRESOURCE_H
#define EXO_STRUCT_SHAREDRESOURCE_H

#include "string"
#include "map"
#include <vector>
class Shared_Data_Description;
namespace SharedResource{
    /**
     * 共享资源的虚基类
     * 维护共享资源的一个共享空间
     * 主要功能有三:
     * 注册
     * 注销
     * 使用
     */
    class SharedResource_Base{
    public:

        std::vector<std::string  > * p_vector_RegisterdPCName;
        std::map<std::string,SharedResource_Base*> *p_SharedResourceSpace;
        std::string SR_Name;
        std::string PC_Name;
        int Count ;
    public:
        void * p_Shared_Resource;
        explicit SharedResource_Base(std::map<std::string, SharedResource_Base *> *_p_SharedResourceSpace);

        /**
         * 如果没有实体则创建实体;
         * 然后向共享资源空间注册自己.
         * 更新特型指针和泛型指针的值
         */
        virtual void Register();
        /**
         * 在共享资源空间中注销自己
         * 如果时最后一个实体则释放资源
         *
         */
        virtual void Logout();


        /*
         * 创建具体的资源函数
         */
        virtual void*  CreateResource() = 0;
        /**
         * 实例化Resource
         * @param _p_resource_base
         */
        virtual void RealizeResource(void* _p_resource_base) = 0;
        /**
         * 注销最后一个时释放Resource
         */
        virtual void freeSResource() = 0;

    };

}

#endif //EXO_STRUCT_SHAREDRESOURCE_H
