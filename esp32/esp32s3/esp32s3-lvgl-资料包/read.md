本资料库中包含了lvgl搭建的基本工程库，主控芯片是ESP32s3,编译环境为esp-idf5.0，
本文将介绍如何从零开始搭建lvgl的开发环境，并通过一个简单的示例程序来熟悉lvgl的基本使用方法。
可作为LVGL的入门学习材料和基本工程库，方便后续的开发。
## 1. 准备工作
一块esp32s3开发板，一根micro usb数据线，一台电脑。
### 1.1 安装esp-idf
首先，需要安装esp-idf，可以参考官方文档进行安装，CSDN和bilibili搜索esp-idf安装教程。都可以有效完成安装，祝你好运！
### 1.2 下载该工程
lvgl的源码托管在github上，可以直接下载源码，也可以通过git clone命令下载。
```bash
git clone https://github.com/lvgl/lvgl.git
```
工程中所使用的lvgl版本为v8.3.1，下载完成后，解压到工作目录下。
###1.3 修改相关配置
#### 1.3.1 打开工程
打开工程后，需要修改`sdkconfig`文件，使能相关组件。
#### 1.3.2 使能组件
打开`sdkconfig`文件，找到`CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9341`和`CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ST7789`这两个配置项，更多信息可参考配置页的详情酌情选择。
~~~有时间再修改~~~
