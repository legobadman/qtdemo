#pragma once

namespace Ui
{
    class Dialog;
}

#include <QtWidgets>

class TestDialog : public QDialog
{
    Q_OBJECT
public:
    TestDialog(QWidget* parent = nullptr);

private:
    Ui::Dialog* m_ui;
};