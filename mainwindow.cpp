#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::dealWithLinesAddSpaces(QString input)
{
    QString output="";


    QStringList list=input.split("\n");
    foreach(QString selectedLine, list)
    {
        QString hexadecimalWithSpaces= addSpaces(selectedLine);


        output.append(hexadecimalWithSpaces);
        output.append("\n");
    }
    return output;

}

QString MainWindow::dealWithLinesAscii(QString input)
{
    QString output="";


    QStringList list=input.split("\n");
    foreach(QString selectedLine, list)
    {
        QString hexadecimalWithSpaces= addSpaces(selectedLine);
        QString translatedAscii=lineToAscii(hexadecimalWithSpaces);

        output.append(translatedAscii);
        output.append("\n");
    }
    return output;

}


QString MainWindow::addSpaces(QString input)
{

    QString outputLine="";
    int charCounter=0;
    foreach(QChar selectedChar,input)
    {
        if(selectedChar==' ')
        {
           // qDebug()<<"mezera";
            //outputLine.append(" ");
            charCounter=0;
        }
        else
        {
            outputLine.append(selectedChar);
            if(charCounter<1)
            {

                charCounter++;
            }
            else
            {
                outputLine.append(" ");
                charCounter =0;
            }



        }
    }



    return outputLine;
}

void MainWindow::on_pushButton_spaces_clicked()
{
    ui->plainTextEdit_input->setPlainText(dealWithLinesAddSpaces(ui->plainTextEdit_input->toPlainText() ));
}

void MainWindow::on_pushButton_toAscii_clicked()
{
     ui->plainTextEdit_output->setPlainText(dealWithLinesAscii(ui->plainTextEdit_input->toPlainText() ));
}

QString MainWindow::hexQstringToAsciiChar(QString input)
{
    QString output="";
    bool conversionResult=true;
    QChar number=QChar(input.toUInt(&conversionResult,16));
    output+=number;
    qDebug()<<"char "<<input<<" output";
    return output;
}

QString MainWindow::lineToAscii(QString input)
{
    QString output="";
    QStringList listOfChars=input.split(" ");

    foreach(QString character, listOfChars)
    {
        if(character=="00")
        {
              output+="□";
        }
        else
        {
              output+=hexQstringToAsciiChar(character);
        }


    }

    return output;
}



