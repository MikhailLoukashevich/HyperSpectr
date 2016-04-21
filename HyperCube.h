#ifndef HYPERCUBE_H
#define HYPERCUBE_H

#include <QList>

class HyperCube
{
public:
    HyperCube();
    virtual ~HyperCube();

    void SetBands(const int bands);
    int GetBands() const;
    void SetSamples(const int samples);
    int GetSamples() const;
    void SetLines(const int lines);
    int GetLines() const;
    void SetHeaderOffset(const int headeroffset);
    int GetHeaderOffset() const;
    void SetDataType(const int datatype);
    int GetDataType() const;
    void SetByteOrder(const int byteorder);
    int GetByteOrder() const;


    void SetWavelength(const double wavelength);   
    void ClearListOfWavelength();
    QList<double> GetListOfWavelength();

    void SetDataCube(char** dataCube);


private:
    int m_samples;
    int m_lines;
    int m_bands;
    int m_header_offset;
    int m_data_type;
    int m_byte_order;
    char** m_datacube;
    QList<double> m_wavelengths;
};

#endif
