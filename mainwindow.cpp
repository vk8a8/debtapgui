#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <QProcess>
#include <QStringList>
#include <fmt/core.h>

std::string popenToStr(const char* cmd) { // stackoverflow 478898
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	process = new QProcess(this);
	connect(process, &QProcess::readyReadStandardOutput, this, &MainWindow::onReadyReadStandardOutput);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::onReadyReadStandardOutput()
{
	QByteArray output = process->readAllStandardOutput();
	ui->outBrowser->append(output);
}

void MainWindow::on_startBtn_clicked()
{
	std::string command = "sh /usr/share/debtapgui/debtapgui.sh " + filePath;
	std::cout << filePath << std::endl;
	process->start(QString::fromStdString(command));
}


void MainWindow::on_chooseDeb_clicked()
{
	std::string user = popenToStr("whoami");
	QString homedirQ = "/home/" + QString::fromStdString(user.substr(0,user.size()-1));
	QString chosenDeb = QFileDialog::getOpenFileName(this, tr("Open File"), homedirQ, tr("Debian packages (*.deb)"));
	filePath = chosenDeb.toStdString();
	ui->pickedLabel->setText(chosenDeb);
}
