#!/bin/bash
set -e  # Dừng script nếu có lỗi xảy ra

QT_BASE="/usr/local/qt6"
BIN_DIR="/usr/local/bin"

echo "Tạo thư mục cần thiết nếu chưa có..."
sudo mkdir -p "$QT_BASE/lib" "$QT_BASE/plugins/platforms" "$BIN_DIR"

echo "Đặt quyền cho thư mục..."
sudo chmod 755 "$BIN_DIR"
sudo chmod -R 755 "$QT_BASE/lib" "$QT_BASE/plugins"

echo "Cấu hình biến môi trường trong ~/.bashrc (nếu chưa có)..."
grep -qxF 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/qt6/lib/' ~/.bashrc || \
  echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/qt6/lib/' >> ~/.bashrc

grep -qxF 'export QT_QPA_PLATFORM_PLUGIN_PATH=/usr/local/qt6/plugins/platforms' ~/.bashrc || \
  echo 'export QT_QPA_PLATFORM_PLUGIN_PATH=/usr/local/qt6/plugins/platforms' >> ~/.bashrc

echo "Áp dụng biến môi trường..."
source ~/.bashrc

echo "Khởi động cấu hình Raspberry Pi (raspi-config)..."
sudo raspi-config

# Tải thư viện Qt cho Pi
echo "Tải và giải nén libforpi.tar.xz..."
wget -c https://github.com/ledangquangdangquang/Caculator-qt-Raspberry-Pi/releases/download/v0.0.0/libforpi.tar.xz
tar -xf libforpi.tar.xz
sudo cp -r libforpi/* "$QT_BASE/lib/"
sudo chmod -R 755 "$QT_BASE/lib"

# Tải platforms plugin
echo "Tải và giải nén platforms.tar.xz..."
wget -c https://github.com/ledangquangdangquang/Caculator-qt-Raspberry-Pi/releases/download/v0.0.0/platforms.tar.xz
tar -xf platforms.tar.xz
sudo cp -r platforms "$QT_BASE/plugins"
sudo chmod -R 755 "$QT_BASE/plugins"

# Tải ứng dụng CalculatorRPI
echo "Tải và cài đặt CalculatorRPI..."
wget -c https://github.com/ledangquangdangquang/Caculator-qt-Raspberry-Pi/releases/download/v0.0.0/CalculatorRPI
sudo cp CalculatorRPI "$BIN_DIR/"
sudo chmod 755 "$BIN_DIR/CalculatorRPI"

echo "Chạy ứng dụng CalculatorRPI..."
"$BIN_DIR/CalculatorRPI"
