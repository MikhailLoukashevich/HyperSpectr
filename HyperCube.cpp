#include "HyperCube.h"

HyperCube::HyperCube()
{
    m_bands = 0;
}
HyperCube::~HyperCube()
{

}
void HyperCube::SetBands(const int bands)
{
    m_bands = bands;
}

int HyperCube::GetBands() const
{
    return m_bands;
}
void HyperCube::SetSamples(const int samples)
{
    m_samples = samples;
}
int HyperCube::GetSamples() const
{
    return m_samples;
}
void HyperCube::SetLines(const int lines)
{
    m_lines = lines;
}
int HyperCube::GetLines() const
{
    return m_lines;
}
void HyperCube::SetHeaderOffset(const int headeroffset)
{
    m_header_offset = headeroffset;
}
int HyperCube::GetHeaderOffset() const
{
    return m_header_offset;
}
void HyperCube::SetDataType(const int datatype)
{
    m_data_type = datatype;
}
int HyperCube::GetDataType() const
{
    return m_data_type;
}
void HyperCube::SetByteOrder(const int byteorder)
{
    m_byte_order = byteorder;
}
int HyperCube::GetByteOrder() const
{
    return m_byte_order;
}


void HyperCube::SetWavelength(const double wavelength)
{
    m_wavelengths.append(wavelength);
}

void HyperCube::ClearListOfWavelength()
{
    m_wavelengths.clear();
}
QList<double> HyperCube::GetListOfWavelength()
{
    return m_wavelengths;
}

void HyperCube::SetDataCube(char** dataCube)
{
    m_datacube = dataCube;
}



