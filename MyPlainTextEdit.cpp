#include "MyPlainTextEdit.h"

void MyPlainTextEdit::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return
        || event->key() == Qt::Key_Enter
        || event->key()== Qt::Key_Equal) {
        emit returnPressed();
    }
    else if(event->key() == Qt::Key_Period
        ||event->key() == Qt::Key_Comma ){
        emit dotPressed();
    }
    else {
        QPlainTextEdit::keyPressEvent(event);
    }
}
