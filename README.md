# MeoAssistance

A game assistance for Arknights

一款明日方舟的游戏辅助，供PC端安卓模拟器使用，龟速开发中……

![界面截图](images/gui.png)
![公招截图](images/openRecruit.png)

## 下载地址

[稳定版](https://github.com/MistEO/MeoAssistance/releases/latest)  
[测试版](https://github.com/MistEO/MeoAssistance/releases)

## 功能介绍

- 自动刷理智
    - 可设置是否吃完理智药
    - 可设置是否吃石头以及数量
    - 可设置刷的次数（可以用来刷剿灭）
    - 可设置刷完自动关机
    - 支持剿灭模式
    - 支持打完升级了的情况
    - 支持代理失败的情况，会自动放弃本次行动
    - 支持每次刷完自动截图
- 全自动公开招募
    - 自动识别当前招募页所有Tags
    - 自动计算可能出的干员组合并显示
    - 自动帮你点击最优解Tags
    - 自动帮你点击时间9小时
    - 出5、6星干员弹窗提示
    - 最新版本已支持夏活新增的`煌`、`灰喉`等干员
    - 不会帮你点击确定按钮！！！请自行检查辅助选择的是否正确，若出现识别错误，遗漏了高星干员，作者概不负责哦__(:з」∠)_
- 自动访问好友基建
    - 访问完了还会贴心的帮你点进信用商店~
- 其他优势
    - 所有点击操作，都是点击按钮内随机位置，并模拟泊松分布（按钮偏中间位置点的概率大，越往旁边点到的概率越小）
    - 刷理智及基建的点击操作，支持设置随机延时，没有封号风险~
    - 模拟器窗口可以被遮挡，即使全屏看视频、玩游戏，也不影响辅助运行（但模拟器窗口不能最小化）
- 支持多款主流模拟器
- 自适应分辨率及屏幕缩放
- 未来更多功能见[Todo](#Todo)

### 模拟器支持

#### 蓝叠模拟器

完美支持，作者绝大部分测试均在蓝叠上进行，稳定性最能保障

#### MuMu模拟器

完美支持，专门单独做了一套基于adb的控制逻辑。需要关闭模拟器的底部工具栏（快捷键Alt+T）

#### MuMu手游助手（星云引擎）  

不支持，MuMu不响应SendMessage鼠标消息，而且这个版本不支持adb控制，正在想办法……

#### 其他模拟器

其他模拟器已停止支持，若有需要，欢迎给我提[ISSUE](https://github.com/MistEO/MeoAssistance/issues)，会根据情况尽量适配~

## 使用说明

### 基本说明

1. 使用支持的模拟器打开明日方舟
2. 解压压缩包，**使用管理员权限**，打开"MeoAsstGui.exe"。**注意，请不要使用中文或有特殊符号的文件夹路径**
3. 运行期间，模拟器窗口可以被遮挡，全屏玩游戏、看视频等，完全不影响，但是模拟器不能最小化（其实也没事，辅助会帮你把模拟器窗口强行弹回来。。）
4. 若需要长时间挂机，请关闭电脑的息屏、睡眠等功能

### 刷理智

1. 明日方舟打开**蓝色开始按钮**的界面
2. 根据你的需要勾选"吃理智药"和"吃石头"
3. 点击"开始刷理智"，开始后上面的选项也可以随时修改
4. 刷完了会自动停止的

### 全自动公开招募

1. 明日方舟打开公开招募，有Tag选择的界面
2. 辅助勾选你需要的选项，点击"开始计算"
3. 请检查识别结果是否正确，自行判断是否确定开始招募

再次强调，本辅助仅会帮你选择最优Tags和时间，不会帮你点击确定按钮！！！请自行检查辅助选择的是否正确，若出现识别错误，遗漏了高星干员，作者概不负责哦__(:з」∠)_

### 访问好友基建

1. 明日方舟处于任意界面均可，会自动帮你点过去
2. 点击"访问基建"
3. 达到10次上限，或者所有可访问的好友都访问完了，就会自动停的
4. 然后会贴心的帮你跳转到信用商店，顺便收了当天信用~

### 设置操作延时

刷理智、访问基建时，每次点击之前，均随机延时一定的时间，降低封号风险  
该功能默认是关闭的，需要的话请手动打开：请手动修改`resource\config.json`文件中，`options`.`controlDelayRange`字段的值，格式为`[最小延时, 最大延时]`，单位为毫秒，例如想设置3~5秒的随机延时，即设置为`[ 3000, 5000]` 即可。文件保存后请重新打开程序。

![图例](images/controlDelayRange.png)

### 自动截图功能

每次刷完结算界面，会自动截一张图，保存在`screenshot`文件夹中  
该功能默认是打开的，不需要的话可以手动关掉：请手动修改`resource\config.json`文件中，`options`.`printWindow`字段的值，`true`是打开，`false`是关闭。文件保存后请重新打开程序。
![图例](images/printWindow.png)

## 致谢

### 开源库

- 图像识别库：[opencv](https://github.com/opencv/opencv.git)
- 文字识别库：[chineseocr_lite](https://github.com/DayBreak-u/chineseocr_lite.git)
- C++ JSON库：[meojson](https://github.com/MistEO/meojson.git)
- WPF MVVW框架：[Stylet](https://github.com/canton7/Stylet)
- WPF控件库：[HandyControl](https://github.com/HandyOrg/HandyControl)
- C# JSON库: [Newtonsoft.Json](https://github.com/JamesNK/Newtonsoft.Json)

### 贡献/参与者

- 非常感谢 [tcyh035](https://github.com/tcyh035) 帮忙设计重构图形界面
- 非常感谢 [GengGode](https://github.com/GengGode) 和 [DbgDebug](https://github.com/DbgDebug) 提供图像算法思路并协助验证
- 非常感谢 [LoveLoliii](https://github.com/LoveLoliii) 提供公开招募算法及数据、部分功能逻辑思路
- 感谢参与软件测试、提bug的小伙伴们~
- ~~感谢[B站直播间](https://live.bilibili.com/2808861)的小伙伴们陪我弹幕吹水~~

## 广告

[B站直播间](https://live.bilibili.com/2808861)：每晚直播敲代码，近期很长一段时间应该都是在写本辅助软件  
[QQ群](https://jq.qq.com/?_wv=1027&k=ypbzXcA2)：直播间关联Q群，欢迎加入~
