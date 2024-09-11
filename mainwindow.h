#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_startBtn_clicked();

	void on_chooseDeb_clicked();

	void onReadyReadStandardOutput();

private:
	Ui::MainWindow *ui;
	QProcess *process;
	std::string filePath;
};
#endif // MAINWINDOW_H
