<h1 align="center"> Calculator for Raspberry Pi </h1>

A light weight calculator app for raspberry pi.

## Demo
| ***Origin calculator*** | ***Full calculator***|
| -------------- | --------------- |
| ![orign calculator](https://raw.githubusercontent.com/ledangquangdangquang/Caculator-qt-linux/refs/heads/main/assets/origin-calculator.png) | ![full calculator](https://raw.githubusercontent.com/ledangquangdangquang/Caculator-qt-linux/refs/heads/main/assets/full-calculator.png)|


## Installation Guide

### 1. Prepare directories and environment variables

```bash
sudo mkdir -p /usr/local/qt6/lib /usr/local/qt6/plugins/platforms
sudo chmod 755 /usr/local/bin

# Add Qt6 libraries path to LD_LIBRARY_PATH
echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/qt6/lib/' >> ~/.bashrc

# Set Qt platform plugins path
echo 'export QT_QPA_PLATFORM_PLUGIN_PATH=/usr/local/qt6/plugins/platforms' >> ~/.bashrc

# Apply changes immediately
source ~/.bashrc
```

---

### 2. Switch display server (if needed)

Open Raspberry Pi configuration tool:

```bash
sudo raspi-config
```

Navigate to:

```
Advanced Options -> Wayland -> X11
```

Choose the appropriate display server according to your setup.

---

### 3. Download and install required Qt libraries

```bash
wget https://github.com/ledangquangdangquang/Caculator-qt-Raspberry-Pi/releases/download/v0.0.0/libforpi.tar.xz
tar -xf libforpi.tar.xz
sudo cp -r libforpi/* /usr/local/qt6/lib/
sudo chmod -R 755 /usr/local/qt6/lib
```

---

### 4. Download and install Qt platform plugins

```bash
wget https://github.com/ledangquangdangquang/Caculator-qt-Raspberry-Pi/releases/download/v0.0.0/platforms.tar.xz
tar -xf platforms.tar.xz
sudo cp -r platforms /usr/local/qt6/plugins
sudo chmod -R 755 /usr/local/qt6/plugins
```

---

### 5. Download and install the CalculatorRPI application

```bash
wget https://github.com/ledangquangdangquang/Caculator-qt-Raspberry-Pi/releases/download/v0.0.0/CalculatorRPI
sudo cp CalculatorRPI /usr/local/bin/
sudo chmod 755 /usr/local/bin/CalculatorRPI
```

---

### 6. Run the application

```bash
/usr/local/bin/CalculatorRPI
```

---

## Notes

* Using `chmod 755` is safer than `chmod 777`.
* Make sure the environment variables are loaded by opening a new terminal or running `source ~/.bashrc`.
* Adjust display server (Wayland/X11) depending on your Raspberry Pi configuration and Qt support.
* If you encounter issues running the app, verify that the libraries and plugins are correctly installed in the paths above.





