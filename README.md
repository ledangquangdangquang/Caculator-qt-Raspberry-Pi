# Caculator-qt-linux
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
	wget ...
	cp ...
	```

Copy platforms     
	```
	wget ...
	cp ...
	```                             




## Demo
- ***Origin calculator:***

![orign calculator](https://raw.githubusercontent.com/ledangquangdangquang/Caculator-qt-linux/refs/heads/main/assets/origin-calculator.png) 

- ***Full calculator:***

![full calculator](https://raw.githubusercontent.com/ledangquangdangquang/Caculator-qt-linux/refs/heads/main/assets/full-calculator.png)

