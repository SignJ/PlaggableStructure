//
// Created by gregdong on 4/2/20.
//

#include "SharedResource.h"


SharedResource::SharedResource_Base::SharedResource_Base(
        std::map<std::string, SharedResource_Base *> *_p_SharedResourceSpace) {
    Count=0;
    SR_Name="";
    p_SharedResourceSpace=_p_SharedResourceSpace;
    p_Shared_Resource = NULL;
}

void SharedResource::SharedResource_Base::Register() {
    std::map<std::string,SharedResource_Base*>::iterator iter;
    iter =p_SharedResourceSpace->find(SR_Name);
    if (iter==p_SharedResourceSpace->end())
    {
        //没有实体需要创建
        p_Shared_Resource =  CreateResource();
        Count++;
        p_vector_RegisterdPCName = new std::vector<std::string>;
        p_vector_RegisterdPCName->push_back(PC_Name);
        p_SharedResourceSpace->insert(std::pair<std::string,SharedResource_Base*>(SR_Name, this));
        printf("共享SR的%s创建了对象, 地址是%p\n",PC_Name.c_str(),p_Shared_Resource);
        for (iter=p_SharedResourceSpace->begin(); iter!= p_SharedResourceSpace->end(); ++iter) {
            for (int i = 0; i < iter->second->Count; ++i) {

                printf("%s,%s\n",iter->first.c_str(),p_vector_RegisterdPCName->at(i).c_str());
            }

        }

    }else
    {
        //有实体 获取并更新 有实体的操作都要在实体里更新了

        RealizeResource(iter->second->p_Shared_Resource);
        //p_SerialCom= static_cast<SerialCom *>(iter->second->p_Shared_Resource);
        iter->second->Count++;

        this->p_vector_RegisterdPCName=iter->second->p_vector_RegisterdPCName;
        this->p_vector_RegisterdPCName->push_back(PC_Name);
        printf("共享SR的%s注册了自己\n",PC_Name.c_str());
        for (iter=p_SharedResourceSpace->begin(); iter!= p_SharedResourceSpace->end(); ++iter) {
            for (int i = 0; i < iter->second->Count; ++i) {

                printf("%s,%s\n",iter->first.c_str(),p_vector_RegisterdPCName->at(i).c_str());
            }

        }

    }

}

void SharedResource::SharedResource_Base::Logout() {

    std::map<std::string,SharedResource_Base*>::iterator iter;
    iter =p_SharedResourceSpace->find(SR_Name);
    if (iter==p_SharedResourceSpace->end())
    {
        //当前空间没有自己的点了不操作
    }
    else{
        if (iter->second->Count==1)
        {
            //最后一个实例了 需要释放所有
//            p_SerialCom->Disconnect();
//            delete p_SerialCom;
            freeSResource();
            iter->second->p_vector_RegisterdPCName->clear();
            p_SharedResourceSpace->erase(SR_Name);
            iter->second->Count--;

            printf("共享SR的%s清空了对象, 地址是%p\n",PC_Name.c_str(),p_Shared_Resource);
            for (iter=p_SharedResourceSpace->begin(); iter!= p_SharedResourceSpace->end(); ++iter) {
                for (int i = 0; i < iter->second->Count; ++i) {

                    printf("%s,%s\n",iter->first.c_str(),p_vector_RegisterdPCName->at(i).c_str());
                }

            }
        }//iter_secont_count==1
        else
        {
            //还有其他实例,只注销自己就行了
            for (int i = 0; i < iter->second->p_vector_RegisterdPCName->size(); ++i) {
                if (PC_Name==iter->second->p_vector_RegisterdPCName->at(i))
                {
                    iter->second->p_vector_RegisterdPCName->erase(iter->second->p_vector_RegisterdPCName->begin()+i);
                }
            }
            iter->second->Count--;
            printf("共享SR的%s注销了自己, 地址是%p\n",PC_Name.c_str(),p_Shared_Resource);
            for (iter=p_SharedResourceSpace->begin(); iter!= p_SharedResourceSpace->end(); ++iter) {
                for (int i = 0; i < iter->second->Count; ++i) {

                    printf("%s,%s\n",iter->first.c_str(),p_vector_RegisterdPCName->at(i).c_str());
                }

            }
        }
    }

}

