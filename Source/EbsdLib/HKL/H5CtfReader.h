/* ============================================================================
 * Copyright (c) 2010, Michael A. Jackson (BlueQuartz Software)
 * Copyright (c) 2010, Dr. Michael A. Groeber (US Air Force Research Laboratories
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * Neither the name of Michael A. Groeber, Michael A. Jackson, the US Air Force,
 * BlueQuartz Software nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  This code was written under United States Air Force Contract number
 *                           FA8650-07-D-5800
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




#ifndef H5CTFREADER_H_
#define H5CTFREADER_H_

#include <hdf5.h>

#include <vector>

#include "EbsdLib/EbsdLib.h"
#include "EbsdLib/EbsdSetGetMacros.h"
#include "EbsdLib/HKL/CtfReader.h"
#include "EbsdLib/HKL/CtfPhase.h"

/**
 * @class H5CtfReader H5CtfReader EbsdLib/HKL/H5CtfReader.h
 * @brief
 * @author Michael A. Jackson for BlueQuartz Software
 * @date Aug 2, 2011
 * @version 1.0
 *
 * HKL OIM Scans are stored in the HDF5 file into a heirarchy of folders where
 * each folder stores an individual .ctf file. The folder has a simple index as
 * its name, for example if the index of the .ctf file was 11 then the HDF folder
 * that contains that .ctf file's data has an HDF Group name of "11". Within this
 * folder there are 2 more folders: <b>Data</b> and <b>Header</b>.\n
 *   The <b>Data</b> folder contains all the columner data from the .ang file where
 * each column is its own HDF data set. The <b>Header</b> folder contains the complete
 * header data from the .ctf file as either data sets or as subfolders. The dataset
 * with the name <b>OriginalFile</b> contains the unchanged complete header from
 * the .ctf file in a single string HDF data set. Each of the header keys has been
 * also saved to its own HDF data set which can be seen with any HDF5 data viewer
 * application. For the Phase data inside the header a new HDF group is created
 * called <b>Phases</b> which contains each of the phase data. Again each phase
 * has an HDF5 group where its data is collected with a simple numerical index
 * as its name. Within each Phase's HDF Group folder are the various data sets
 * that make up the Phase data.
 *
 * After reading the HDF5 file one can use the various methods to extract the phases
 * or other header information or all the columnar data.
 */
class EbsdLib_EXPORT H5CtfReader : public CtfReader
{
  public:
    EBSD_SHARED_POINTERS(H5CtfReader)
    EBSD_STATIC_NEW_MACRO(H5CtfReader)
    EBSD_TYPE_MACRO(H5CtfReader)
    virtual ~H5CtfReader();

    /**
     * @brief The HDF5 path to find the EBSD data
     */
    EBSD_INSTANCE_STRING_PROPERTY(HDF5Path)

    /**
     * @brief Reads the file
     * @return error condition
     */
    virtual int readFile();

    /**
     * @brief Reads the header section of the file
     * @param Valid HDF5 Group ID
     * @return error condition
     */
    int readHeader(hid_t parId);

    /**
     * @brief Returns a vector of AngPhase objects corresponding to the phases
     * present in the file
     */
    std::vector<CtfPhase::Pointer> getPhases() { return m_Phases; }

  protected:
    H5CtfReader();


    /**
     * @brief Reads the data section of the file
     * @param Valid HDF5 Group ID
     * @return error condition
     */
    int readData(hid_t parId);

  private:
    std::vector<CtfPhase::Pointer> m_Phases;

    H5CtfReader(const H5CtfReader&); // Copy Constructor Not Implemented
    void operator=(const H5CtfReader&); // Operator '=' Not Implemented
};

#endif /* H5CTFREADER_H_ */
