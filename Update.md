#                                           Update: Exo_Struct
#### Normal: 提高效率 v0.10.18
@20200506
Frequency=870+

#### Normal: 增加代码测试效率工具  v0.10.17
@20200430
1. 增加了一个Efficiency的测试工具,测试代码执行的效率.
#### Normal: 增加了每次开始时清空FileCache v0.10.16
@20200429
增加了每次开始时Struct会清空data/

#### Normal: 修改Button.sh增加nohup v0.10.15
@20200428
修改原脚本运行一段时间会崩溃的问题

#### Normal: 增加了不需要输出FileRecorder的情形 v0.10.14
@20200428
设置在SD.yaml中0-0为不需要进行FileRecorder输出
#### Normal: 更改了Button.sh v0.10.13
@20200428
更改了Button的开始路径

#### Normal: 修改了Motion的剧本 v0.10.12
@20200428
修改了剧本2,3,4


#### Normal: 实现了MPU6050的读取 v0.10.11
@20200428
实现了读取单个MPU的数据功能

#### Normal: Noting v0.10.10
@20200427
没有修改

#### Normal: 修改0.10.8中的Bug v0.10.9
@20200427
修改了时间测定中的bug
验证了git管理板子文件的功能
#### Normal: 增加了PIPE中的时间测定功能 v0.10.8
@20200427
增加了计算update中时间的消耗累计功能 在Free中输出
#### Normal: 增加HandOut测试分支 v0.10.7
@20200427 
增加测试分支HandOut(测试中)

#### Normal: 测试部分完成 v0.10.6
@20200426
测试了功能的完整性
存在的问题: 有可能会出现因为Socket占用无法启动的情况
			

#### Normal: 增加了LED相关 (未测试)v0.10.5
@20200426
增加了Pipe LEDIN(20)-->LEDOUT(21)


#### Normal: 修改了BUG(未测试) v0.10.4
@20200426
修改了static变量的bug
增加了两个不同的剧本

#### Normal: 增加了额Kill_Handler(未测试) v0.10.3
@20200426
增加了KillHandler 可以处理不同的系统信号量来完成资源的释放.
更改了Button.sh的kill指令 释放15信号量
还未测试
#### Normal : 增加了SignalHandler v0.10.2
@20200424
增加了程序对SIgnal处理的过程,在退出时适当释放资源

#### Normal : 增加了程序开始等待的部分 v0.10.1
@20200424
增加了等待的部分在ButtonEvent-->ButtonData的Initialize()中
增加了开始启动的脚本在Script中
## Main: 完成录播按钮切换功能 v0.10.0
@20200423
完成了按钮录播的验证功能
Target: 17-1
Resource: 23-1,16-1


#### Normal: 初步完成多剧本录播按钮切换功能 v0.9.4
@20200423
增加了CSVData23-1的实现
增加了Pipe CSVData+BtnData-->PosCommand的实现
需要测试运行情况


#### Normal: 增加了ButtonEvent-->ButtonData v0.9.3
@20200422
增加了ButtonEvent16/ButtonData24
Pipe ButtonEvent-->ButtonData
检测可以完成功能
#### Normal: 增加了数据的Join功能v0.9.2
@20200422
增加了Executable : JoinCSV 可以实现聚合之前写入的test.txt文件
配置同样在yaml中实现


#### Normal: 对长时间数据的处理完成v0.9.1
@20200421
可以处理长时间的数据变化,300k次.
将pipe Safe改为[4]

## Main: 完成了录播功能部分的开发 v0.9.0
@20200421
录播部分的开发完成 文件中的定义为0-6: h-k-h-k-a-a
选中的播放频率为45hz


#### Normal: 进行了根据FileRecorderLoopCount结束的方案 v0.8.14
@20200421
只要记录数据达到要求的最多行数即停止



#### Normal: 开发了UpdateHz功能 v0.8.13
@20200420
增加了更新的频率判定功能.在Pipe的Update()函数中会进行预先调用时刻的判定.
该功能效用需要后续考虑
#### Normal: 增加了Pipe18,19,17的联系实现 v0.8.12
@20200416
实现了17-1,18-1,19-1的联系并进行了无负载测试
TODO: 需要进行真机链接测试

#### Normal: 增加了PIPE PosCOmmand->RobotMotion v0.8.11
@20200416
实现了PIPE PosCommand->RobotMotion
实现了SHaredResource中的Socket.
 
#### Normal: 改变了SharedResourceBase的结构v0.8.10
@20200416
将SharedResource中的Register和Logout都上移至SharedResourceBase中.

#### Normal: 增加了CSV_Data-->PosCommand功能v0.8.9
@20200415
增加了RobotControl中的18-19(CSV_Data->POSCOmmand的功能PIPE
增加了PosCOmmand的SDF

#### Normal: 增加了SAFE的相关记录功能v0.8.8
@20200415
PIPE_Safe可以进行针对lt_S/SMAX; st_S/SMAX;SortedSpace进行过程记录,并形成csv文件.
在主程序中结束时调用了各个PIPE的SelfFree()功能
#### Normal: 增加了对实际数据处理的过程v0.8.7
@20200414


#### Normal: 增加了AS计算的代码v0.8.6
@20200414
写出了AS计算的代码
使用实际数据的数据结果进行了测试


#### Normal: 修改BUG v0.8.5
@20200413
修改了BUG: 在EWAData中的FileRecorder相关代码中有一部分老代码没删除,因为该对象没有实例,导致运行一段时间(20000-30000)后崩溃.


#### Normal: 长期的EPS准备完成v0.8.4
@20200413
完成了ltsEPS的功能开发


#### Normal: 短期的EPS准备完成v0.8.3
@20200413
完成了StEPS的功能开发

#### Normal: 增加了stEPS的更新功能 v0.8.2
@20200413
增加了stEPS的初始化和增加数据功能.
建立了TestFunction的功能

#### Normal:增加了初始SAFE v0.8.1
@20200410
增加了SAFE的初始情况的建立结构.

## Main: 可以进行数据的读取 v0.8.0
@20200409
1. 在板上测试了数据(6000)
2. 板上有BUG,运行17000后会停止
3. 可以开始进行论文算法的开发
4. 与Dev合并

#### Normal: 可以进行测试 v0.7.3
@20200409
1. 增加了主函数的设置段
2. 增加了SD file的设置段
3. 增加了两个TOOLs ClearFileCache和AutoCmake

#### Normal:加入RectificatedDATA v0.7.2
@20200409
1. 增加了RectedData SD
2. 增加了Pipe Filtered-->Rectificated Data
3. 修改了原系统的连接关系


#### Normal:文档记录增加跳过开头功能v0.7.1
@20200408
1. 增加了开头跳过文档写入行数的功能JumpOverCount=800
2. 改掉了在Filter中的BUG


## Main:进行了真实数据的测试v0.7.0
@20200408
1. 完成真实数据的测试,更改了在板上运行不行的代码
2. 测试了增加的新文件输出的功能
3. 读取\滤波和AS计算功能模块完好,EWA可能会有问题,需要下午进行真实数据测试
#### Normal:对多个SD增加了文件记录的接口v0.6.6
@20200408
针对4,5,6,都增加了文件接口,需要在板子上尝试使用效果.

#### Normal: 增加完成了检查功能的实现v0.6.5
@20200403
检查Serial连接功能增加完成

#### Normal: 验证了SharedResource的功能实现v0.6.4
@20200403
增加了针对logout的实现
验证了该功能的初步注册与注销功能.

#### Normal: 增加了SharedResource针对于Pipe的实现v0.6.3
@20200403
增加了SR针对于Pipe的实现
该实现需要测试

#### Normal: 增加了SharedResource的实现v0.6.2
@20200402
增加了SharedResource的实现;
该实现是未测试


#### Normal: Update Function Serial Checkout v0.6.1
@20200401
更新了串口更新的功能;
使用了Utilities中的Serial的Definition的设定方式.
TODO: 需要增加SharedResource的功能.

## Main: finish Fucntion: 多点任务的PipeQue合并和整理情况v0.6.0
@20200401
更改了DFS和GeneratePipeQueue的实现方式,在SharedData中加入了SelectedInputPos项记录选择的Input种类.再根据该值进行PipeQueue的生成.

#### Normal: add IPC_Func v0.5.1
@20200401
增加了IPC的功能实现

## Main: finish function: 针对于多个Target的任务构建改造完成 v0.5.0
@20200331
修改了结构使得多个任务目标的结构现在可以自生成了. 分离Pipe分支不会影响其他分支的运行与否.

#### Normal: fix bug v0.4.1
@20200330
修改了不重要的小BUG

## Main: finish Human+SerialOutput Function v0.4.0
@20200330 
完成了Pipe-HumanData与SerialOutput部分的执行过程功能.

TODO: 
1. 对于多个TargetSD的PipeQueue的生成.
2. 所有需要的SD节点的输出文件功能完成.

#### Normal: add Func SeriaOutputData v0.3.1
@20200330
增加了串口输出的功能实现(未实测)

## Main: Change:File_Recorder增加为AssignablePipe类 v0.3.0
@20200327 
增加了基类AssignablePipe, 主要用于系统相关的需要依靠指定来建立联系的Pipe;
现有可能的实例为FileRecorder和ScreenDisplay. 需要在实现SD与PipeQueue后插入到PipiQueue中一同进行.

#### Normal: add FIleStartPos v0.2.1
@20200327
增加了文件的列数开始位置.

## Main: Finish Config Function v0.2.0
@20200327
完成基于PlaggableClass的配置读取功能;配置的分化在各PIPE子类的Initialize中进行分化.
## Main: Finish File_Recorder v0.1.0
@20200326完成文件记录功能

## Main: Initial v0.0.1
@20200320
新建git仓库,当前状态为:
完成CSVReader;RawData;FilteredData;ActiveScore;EWAData;RecoResult;StartInfo这些SD的构建和相关Pipe的链接.
在修改DFS2D的与节点的搜索关系.

#### Normal: Add Update.md v0.0.2
@20200320
增加Update.md文件

#### Normal: Fixed DFS v0.0.3
@20200320
修改完成了DFS搜索函数;修改了生成SD实体与链接的过程;更新了输入输出的连接方式;已可以完成所需要的内容并继续开发.

#### Normal: Fixed DFS & Pipe Generate v0.0.4
@20200325
修改了DFS中关于多次分裂的排除关系
修改了PipeGenerate中关于输出判定的最后一个节点缺失问题.
添加了G Sensor--> Position-->StartInfo 的关系

#### Normal: Add Recorder v0.0.5
@20200325
增加各个SD节点的记录功能

#### Normal: Construction of Recorder v0.0.6
@20200325
设计了FileRecorder的结构;需要捋顺FileWriter的结构