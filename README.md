# node-mechine-code
在Node.js应用中获取机器唯一识别码，根据机器的物理硬件序列号生成。

## 原理

（实现方法来源于网络）
- Windows平台：利用WMI查询出机器的硬件信息
- Linux平台：利用汇编以及一些命令实现
- Mac平台：待更新

## 支持平台

暂时只支持Windows

## 编译
```
node-gyp configure
node-gyp build
```
## 使用方法
```
const code = require('./index.js');
const mechineCode = code();
```
