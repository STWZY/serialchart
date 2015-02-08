#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "common.h"
#include "portbase.h"
#include "decoderbase.h"
#include "displaybase.h"



namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *e);

private:
    Ui::MainWindow *ui;

    QSettings settings;
    QString documentFilePath;
    void updateDocumentFilePath(const QString& filePath);

    bool saveDocument(const QString& filePath);
    bool loadDocument(const QString& filePath);
    bool checkDocument();
    bool documentIsDirty;
    Configuration* config;

    PortBase* port;
    DecoderBase* decoder;
    DisplayBase* display;

    bool portValid;


private slots:
    void on_sendButton_clicked();
    void on_actionConfiguration_toggled(bool );
    void on_actionChart_toggled(bool );
    void on_actionToolbar_toggled(bool );
    void on_actionStop_triggered();
    void on_actionRun_triggered();
    void on_actionAbout_triggered();
    void on_configurationText_textChanged();
    void on_actionSaveAs_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionNew_triggered();

    void portStopped();
    void message(const QString& text,const QString& type);


};

#endif // MAINWINDOW_H
