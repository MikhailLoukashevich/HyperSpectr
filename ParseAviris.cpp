#include "ParseAviris.h"

#include <QFile>
#include <QDebug>

ParseAviris::ParseAviris()
{

}

ParseAviris::~ParseAviris()
{

}

bool ParseAviris::Parse(QString fileName, HyperCube& cube)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QString *Text = new QString[10000]; int number_lines = 0;
        while (!file.atEnd()) {      //считывание текста в массив строк
            Text[number_lines] = file.readLine();
            number_lines++;
        }
    QString str_name[6];
        str_name[0] = "samples";
        str_name[1] = "lines";
        str_name[2] = "bands";
        str_name[3] = "header offset";
        str_name[4] = "data type";
        str_name[5] = "byte order";

        int samples = 0, lines = 0, bands = 0, header_offset = 0, data_type = 0, byte_order = 0;
        int array_name[6] = { samples, lines, bands, header_offset, data_type, byte_order };
        QString str_number;
        for (int n = 0, l = 0; n < 6; n++)
        {
        for (int k = 0; k < number_lines; k++) {
            QString  str_file(Text[k]); // создаем строку-копию из строки Text[k]
            bool search = str_file.contains(str_name[n],Qt::CaseInsensitive); //  поиск подстроки  в строке str с 0 позиции
            if (search){
                for (l = 0; l < str_file.length(); l++)
                {
                    if (str_file[l] >= '0' && str_file[l] <= '9') break; // если цифра найдена - то выходим из цикла

                }
                str_number = str_file.remove(0, l - 1); // str_number – подстрока str_file всех символов  с l позиции
                array_name[n] = str_number.toInt();
            }
        }
}       // запись значений параметров в куб
        cube.SetSamples(array_name[0]);
        cube.SetLines(array_name[1]);
        cube.SetBands(array_name[2]);
        cube.SetHeaderOffset(array_name[3]);
        cube.SetDataType(array_name[4]);
        cube.SetByteOrder(array_name[5]);
       // qDebug() << "";
        double wavelength[300];
        int	first_wavelength = 0; // номер строки "wavelength" в файле
        for(int n = 0; n < number_lines; n++)
        {
            QString  str_file(Text[n]); // создаем строку-копию из строки Text[k]
            bool search = str_file.contains("wavelength",Qt::CaseInsensitive); //  поиск подстроки  в строке str с 0 позиции
            if (search)
            { first_wavelength = n;
                break;
            }
        }
        for(int n = first_wavelength + 1, w = 0; n < first_wavelength + 225; n++)
        {
            QString  str_file(Text[n]); // создаем строку-копию из строки Text[k]
            int end_line = str_file.length(); // длина строки
            QString str_number;
            int first_digit = -1, comma = -1; // первая цифра, запятая
            for(int i = 0; i < end_line; i++)
            {
                if(i < end_line)
                {
                    if (str_file[i] >= '0' && str_file[i] <= '9')
                    {
                        first_digit = i; // поиск первой цифры
                        for(int c = first_digit; c < end_line; c++)
                        {
                            if(str_file[c] == ',' || str_file[c] == '}')
                            {
                                comma = c; break;
                            }
                            if(str_file[c] == ' ' )
                            {
                                comma = c; break;
                            }
                        }
                        QString str_number(str_file); // копия строки
                        str_number = str_file.remove(0, first_digit - 1);
                        str_number = str_file.remove(comma + 1, end_line + 1);
                       wavelength[w] = str_number.toDouble();
                      // qDebug() << wavelength[w];
                       w++;
                        str_file = str_file.remove(0, comma - 1);
                        end_line = str_file.length(); // длина строки
                    }
                }
            }
        }
        file.close(); // закрытие файла с параметрами
        char** dataCube = new char*[array_name[2]]; // bands
        int ChunkSize = array_name[0] * array_name[1] * array_name[4]; // samples*lines*datatype

        for (int i = 0; i < array_name[2]; i++)
        {
            dataCube[i] = new char[ChunkSize]; // samples*lines*datatype
        }

         int end_line_FileName = fileName.length(); // длина строки
         int point;
         for(int i = end_line_FileName; i > 0; i--)
         {
             if (i > 0)
             {
                 if (fileName[i] == '.')
                 {point = i; break;}
             }
         }
         fileName = fileName.remove(point, end_line_FileName);

        QFile dataFile(fileName); // открытие файла с данными
        if (!dataFile.open(QIODevice::ReadOnly))
        {
            return false;
        }
        for(int i = 0; i < array_name[2]; i++) // i < bands
        {
            //char* TempBuf = new char[ChunkSize];
            if(!dataFile.atEnd())
            {
                if(dataFile.read(dataCube[i], ChunkSize) != ChunkSize)
                {
                    return false;
                }
               // cube->DataCube(i, TempBuf, ChunkSize, 0);
            }
            //delete [] TempBuf;
        }
        dataFile.close();
        return true;
}

