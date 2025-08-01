#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QObject>
#include <QRegularExpression>
#include <QShortcut>
#include <cmath>
#include <QMessageBox>

#include "MyPlainTextEdit.h"
#include "operation/operationfactory.h"
#include "parser/tokenizer.h"
#include "parser/shuntingyard.h"
#include "parser/evaluator.h"
#include <QFileInfo>
#include <QProcess>
#include <QStringList>
#define VERSION "v0.0.5"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Key input handle (done)
    QStringList ops = {"0", "1", "2", "3", "4",
                       "5", "6", "7", "8", "9",
                       "sym9", "sym0", "mod", "pi",
                       "square_root", "x_squared", "percent", "dot",
                       "add", "sub", "mul", "div",
                        "sin","cos","tan",
                        "sinh","cosh","tanh",
                        "exp","ln","log",
                        "i","re","im",
                        "abs","conj","arg",
    };

    for (const QString& op : ops) {
        QString btnName = "key_" + op;
        QPushButton* btn = findChild<QPushButton*>(btnName);
        connect(btn, &QPushButton::clicked, this, &MainWindow::handleKeyClicked);
    }
    // Handle Enter key, Enter numpad key, Equal key (done)
    connect(ui->plainTextEdit, &MyPlainTextEdit::returnPressed,
            this, &MainWindow::on_key_equals_clicked);
    QShortcut* enterShortcut = new QShortcut(QKeySequence(Qt::Key_Return), this); // real enter
    connect(enterShortcut, &QShortcut::activated, this, &MainWindow::on_key_equals_clicked);
    QShortcut* numpadEnterShortcut = new QShortcut(QKeySequence(Qt::Key_Enter), this); // numpad enter
    connect(numpadEnterShortcut, &QShortcut::activated, this, &MainWindow::on_key_equals_clicked);
    QShortcut* equalShortcut = new QShortcut(QKeySequence(Qt::Key_Equal), this); // equal key
    connect(equalShortcut, &QShortcut::activated, this, &MainWindow::on_key_equals_clicked);

    // Comma and dot handle (done)
    connect(ui->plainTextEdit, &MyPlainTextEdit::dotPressed,
            this, &MainWindow::dotHandle);
    QShortcut* dotShortcut = new QShortcut(QKeySequence(Qt::Key_Period), this); // real enter
    connect(dotShortcut, &QShortcut::activated, this, &MainWindow::dotHandle);
    QShortcut* commaShortcut = new QShortcut(QKeySequence(Qt::Key_Comma), this); // real enter
    connect(commaShortcut, &QShortcut::activated, this, &MainWindow::dotHandle);

    // Menu clear history
    connect(ui->actionClear_history, &QAction::triggered, this, &MainWindow::handleClearHistory);
    // Menu update app
    connect(ui->actionUpdate, &QAction::triggered, this, &MainWindow::handleUpdate);
    // About...
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::handleAbout);

    // Hide button extend
    QStringList hideObjectNames = {
        "sin", "cos", "tan",
        "sinh", "cosh", "tanh",
        "exp", "ln", "log",
        "i", "re", "im",
        "abs", "conj", "arg"
    };
    for (const QString& hideObjectName : hideObjectNames) {
        QString objectName = "key_" + hideObjectName;
        QPushButton* objectHide = findChild<QPushButton*>(objectName);
        objectHide->hide();  // Ẩn nút nếu tìm thấy
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
// Update handle
void MainWindow::handleUpdate() {
    QString appPath = QCoreApplication::applicationFilePath();  // đường dẫn AppImage hiện tại
    QString dir = QFileInfo(appPath).absolutePath();             // thư mục đang chạy

    QString script = QString(R"(
        cd "%1"
        exec bash -c '
            echo "🛠 Đang cập nhật Calculator..."
            wget -O Calculator-x86_64.AppImage https://github.com/ledangquangdangquang/Caculator-qt-linux/releases/latest/download/Calculator-x86_64.AppImage
            chmod +x Calculator-x86_64.AppImage
            echo "✅ Cập nhật xong. Đang khởi chạy lại..."
            sleep 1
            ./Calculator-x86_64.AppImage
        '
    )").arg(dir);

    QProcess::startDetached("x-terminal-emulator", QStringList() << "-e" << script);
    QApplication::quit(); // đóng app hiện tại
}

// Hide or Show when resize (done)
void MainWindow::resizeEvent(QResizeEvent *event)
{
    QStringList hideObjectNames = {
        "sin", "cos", "tan",
        "sinh", "cosh", "tanh",
        "exp", "ln", "log",
        "i", "re", "im",
        "abs", "conj", "arg"
    };
    for (const QString& hideObjectName : hideObjectNames) {
        QString objectName = "key_" + hideObjectName;
        QPushButton* objectHide = findChild<QPushButton*>(objectName);
        if (width() > 708) { // Ngưỡng có thể thay đổi tuỳ ý
            objectHide->show();  // Ẩn nút nếu tìm thấy
        }else{
            objectHide->hide();  // Ẩn nút nếu tìm thấy
        }
    }


    QMainWindow::resizeEvent(event); // Gọi lại hàm gốc
}
// Show about (done)
void MainWindow::handleAbout() {
    QMessageBox::information(this, "Calculator about",
                             QString("Calculator %1\n(c) ledangquangdangquang").arg(VERSION));
}
// Clear history (done)
void MainWindow::handleClearHistory() {
    ui->plainHistory->clear();
}
// Fillter no a number (done)
// Event when buttoon "=" cliked (DONE)
void MainWindow::on_key_equals_clicked()
{
    if (ui->plainTextEdit->toPlainText().isEmpty()) {
        ui->plainTextEdit->setFocus();
        return;
    }
    QString expr = ui->plainTextEdit->toPlainText();
    qDebug() << "Entered:" << expr;

    // 1. Regex ký tự hợp lệ
    static const QRegularExpression re(R"([^0-9+\-*/%^().,\s𝛑√a-zA-Z×÷])");
    if (re.match(expr).hasMatch()) {
        ui->plainTextEdit->appendPlainText("ERROR: contains invalid characters");
        return;
    }

    // 2. Chỉ cho phép từ hop le
    static const QRegularExpression wordRe(R"(\b(?!(sin|pi|cos|i|tan|cot|asin|acos|atan|log|ln|sqrt|abs|mod|)\b)[a-zA-Z]+\b)");
    if (wordRe.match(expr).hasMatch()) {
        ui->plainTextEdit->appendPlainText("ERROR: unknown word");
        return;
    }

    // 3. Có ít nhất một chữ số
    static const QRegularExpression digitRe(R"(\d|𝛑|e|i)");
    if (!digitRe.match(expr).hasMatch()) {
        ui->plainTextEdit->appendPlainText("ERROR: expression must contain number(s)");
        return;
    }

    // 4. Kiểm tra dấu ngoặc
    int open = expr.count('(');
    int close = expr.count(')');
    if (open < close) {
        ui->plainTextEdit->appendPlainText("ERROR: unmatched parentheses");
        return;
    }
    // --------------------------------------------
    expr.replace(QChar(0x00D7), "*"); // × => *
    expr.replace(QChar(0x00F7), "/"); // ÷ => /
    // i handle (done)
    static const QRegularExpression addIMultiplier(R"((\d+)\s*i)");
    expr.replace(addIMultiplier, "\\1*i");

    // sqrt handle 6sqrt(6) (done)
    expr.replace(QChar(0x221A), "sqrt");

    // `%` handle (done)
//    static const QRegularExpression addMulPercent(R"((\d)(%))");
//    expr.replace(addMulPercent, R"(\1*\2)");
//    expr.replace("%", "0.01");
    static const QRegularExpression percentRe(R"((\d+(?:\.\d+)?)%)");
    expr.replace(percentRe, R"((\1*0.01))");


    // Pi handle (done)
    expr.replace("𝛑", "pi");
    static const QRegularExpression addMulPi(R"((\d)(pi))");
    expr.replace(addMulPi, R"(\1*\2)");

    // e handle (done)
    static const QRegularExpression addMulE(R"((\d)(e))");
    expr.replace(addMulE, R"(\1*\2)");

    // 1. Tokenize
    QVector<QString> tokens = Tokenizer::tokenize(expr);
    qDebug() << "Tokens:" << tokens;

    // 2. Chuyển sang postfix
    QVector<QString> postfix = ShuntingYard::toPostfix(tokens);
    qDebug() << "Postfix:" << postfix;

    // 3. Tính toán
    Complex result = Complex(0);
    bool ok = Evaluator::evaluate(postfix, result);
    if (!ok) {
        ui->plainTextEdit->appendPlainText("ERROR: Calculation failed");
        return;
    }

    // Hiển thị kết quả
    QString resultStr;
    if (result.imag() == 0) {
        resultStr = QString::number(result.real());
    } else if (result.real() == 0) {
        resultStr = QString("%1i").arg(result.imag());
    } else {
        resultStr = QString("%1 + %2i").arg(result.real()).arg(result.imag());
    }

    ui->plainHistory->appendPlainText(expr + " = " + resultStr);

    ui->plainTextEdit->clear();
    ui->plainTextEdit->insertPlainText(resultStr);
    ui->plainTextEdit->setFocus();

}


// Print name of object in plain text when each button cliked (done)
void MainWindow::handleKeyClicked()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;

    QString btnText = btn->text();
    QString objName = btn->objectName(); // Lấy objectName để xử lý các trường hợp đặc biệt

    if (objName == "key_square_root" ||objName == "key_sin"
            ||objName == "key_cos"||objName == "key_tan"
            ||objName == "key_sinh"||objName == "key_cosh"
            ||objName == "key_tanh"
            ||objName == "key_ln"||objName == "key_log"
            ||objName == "key_re"||objName == "key_im"
            ||objName == "key_conj"||objName == "key_arg"
        )
    {
        ui->plainTextEdit->insertPlainText(btnText + "(");
    } else if (objName == "key_x_squared") {
        ui->plainTextEdit->insertPlainText("^2"); // Dùng ký hiệu mũ
    } else if (objName == "key_exp") {
        ui->plainTextEdit->insertPlainText("e^"); // Dùng ký hiệu mũ
    } else if (objName == "key_abs") {
        ui->plainTextEdit->insertPlainText("abs(");
    } else if (objName == "key_dot") {
        ui->plainTextEdit->insertPlainText(".");
    } else {
        ui->plainTextEdit->insertPlainText(btnText);
    }

    ui->plainTextEdit->setFocus();
}
// Clear button clicked (done)
void MainWindow::on_key_clear_clicked()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setFocus();
}

void MainWindow::dotHandle()
{
    ui->plainTextEdit->insertPlainText(".");
}
