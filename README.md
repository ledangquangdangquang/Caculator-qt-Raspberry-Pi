<h1 align="center"> Calculator for Raspberry Pi </h1>

A light weight calculator app for raspberry pi.

## Demo
| ***Origin calculator*** | ***Full calculator***|
| -------------- | --------------- |
| ![orign calculator](https://raw.githubusercontent.com/ledangquangdangquang/Caculator-qt-linux/refs/heads/main/assets/origin-calculator.png) | ![full calculator](https://raw.githubusercontent.com/ledangquangdangquang/Caculator-qt-linux/refs/heads/main/assets/full-calculator.png)|

## Install
- Export $PATH
	```
	sudo mkdir /usr/local/qt6
	sudo chmod 777 /usr/local/bin
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/qt6/lib/
	export QT_QPA_PLATFORM_PLUGIN_PATH=/usr/local/qt6/platforms
	```
- Switch to wayland 
	```
	sudo raspi-config
	```
	and `Advance options` -> `Wayland` -> `X11`

- Copy library requirement
	```
	wget https://github.com/ledangquangdangquang/Caculator-qt-Raspberry-Pi/releases/download/v0.0.0/libforpi.tar.xz
	tar -xf libforpi.tar.xz
	mkdir /usr/local/qt6/lib/
	cp -r libforpi/* /usr/local/qt6/lib/
	```

- Copy platforms     
	```
	wget https://github.com/ledangquangdangquang/Caculator-qt-Raspberry-Pi/releases/download/v0.0.0/platforms.tar.xz
	tar -xf platforms.tar.xz
	cp -r platforms /usr/local/qt6
	```                             
- Copy binary app
	```
	wget https://github.com/ledangquangdangquang/Caculator-qt-Raspberry-Pi/releases/download/v0.0.0/CalculatorRPI
	cp CalculatorRPI /usr/local/bin
	```
	
- Run app
	```
	/usr/local/bin/CalculatorRPI
	```



