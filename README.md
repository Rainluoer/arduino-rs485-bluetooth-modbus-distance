# Arduino RS485 蓝牙 Modbus 测距项目

## 项目介绍

本项目使用 Arduino UNO、MAX485 RS485 模块和 HC-06 蓝牙模块，读取 Modbus RTU 测距传感器的数据，并通过 USB 串口和蓝牙发送距离值。

## 使用硬件

* Arduino UNO R3
* MAX485 RS485 模块
* HC-06 蓝牙模块
* Modbus RTU 测距传感器
* 24V 电源

## 接线说明

| Arduino 引脚 | 连接模块                 |
| ---------- | -------------------- |
| D2         | MAX485 RE + DE       |
| D10        | MAX485 RO            |
| D11        | MAX485 DI            |
| D4         | HC-06 TX             |
| D5         | HC-06 RX             |
| 5V         | HC-06 VCC、MAX485 VCC |
| GND        | 所有模块共地               |

## 软件环境

需要安装以下 Arduino 库：

* SoftwareSerial
* ModbusMaster

可以在 Arduino IDE 的库管理器中搜索并安装。

## 参数配置

```cpp
#define SLAVE_ID 0x16
#define MAX485_RE_DE 2
#define MAX485_RO 10
#define MAX485_DI 11
#define BT_RX 4
#define BT_TX 5
```

默认通信波特率：

* RS485：9600
* 蓝牙：9600

## 功能

* 通过 RS485 读取 Modbus RTU 传感器数据
* 在串口监视器显示距离值
* 通过 HC-06 蓝牙发送距离值
* 适合 Arduino 初学者学习 Modbus 和蓝牙通信

## 输出示例

```text
Distance: 1250 mm
Distance: 1248 mm
Distance: 1251 mm
```

## 电路图

把电路图保存到仓库的 `hardware` 文件夹中，然后在 README 中使用：

```md
![电路图](hardware/wiring-diagram.png)
```

## 许可证

MIT License

