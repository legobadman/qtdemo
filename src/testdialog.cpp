#include "testdialog.h"
#include "ui_testdialog.h"


TestDialog::TestDialog(QWidget* parent)
    : QDialog(parent)
{
    m_ui = new Ui::Dialog;
    m_ui->setupUi(this);
}