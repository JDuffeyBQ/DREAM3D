/* ============================================================================
 * Copyright (c) 2011 Michael A. Jackson (BlueQuartz Software)
 * Copyright (c) 2011 Dr. Michael A. Groeber (US Air Force Research Laboratories)
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

#ifndef CLEANUPGRAINS_H_
#define CLEANUPGRAINS_H_

#include <vector>
#include <string>

#include <boost/shared_array.hpp>

#include "DREAM3DLib/Common/DREAM3DSetGetMacros.h"
#include "DREAM3DLib/Common/Observable.h"
#include "DREAM3DLib/Common/DataContainer.h"
#include "DREAM3DLib/Common/OrientationMath.h"


/**
 * @class PackGrainsGen2 PackGrainsGen2.h GrainGenerator/Algorithms/PackGrainsGen2.h
 * @brief
 * @author
 * @date Nov 19, 2011
 * @version 1.0
 */
class CleanupGrains : public Observable
{
  public:
    DREAM3D_SHARED_POINTERS(CleanupGrains);
    DREAM3D_STATIC_NEW_MACRO(CleanupGrains);
    DREAM3D_TYPE_MACRO_SUPER(CleanupGrains, Observable);

    virtual ~CleanupGrains();

    typedef boost::shared_array<float> SharedFloatArray;
    typedef boost::shared_array<int> SharedIntArray;

    DREAM3D_INSTANCE_PROPERTY(int, minallowedgrainsize);
    DREAM3D_INSTANCE_PROPERTY(float, misorientationtolerance);
    DREAM3D_INSTANCE_PROPERTY(int, ErrorCondition);
    DREAM3D_INSTANCE_STRING_PROPERTY(ErrorMessage);
    void setGrainGenFunc(DataContainer* gg) { m = gg; }
    DataContainer*getGrainGenFunc() { return m; }

    unsigned long long int Seed;

	virtual void execute();
    void remove_smallgrains();
    void assign_badpoints();
    void merge_containedgrains();
    void reorder_grains();

    std::vector<OrientationMath*> m_OrientationOps;

  protected:
    CleanupGrains();
    DataContainer* m;

  private:

    OrientationMath::Pointer m_CubicOps;
    OrientationMath::Pointer m_HexOps;
    OrientationMath::Pointer m_OrthoOps;

	CleanupGrains(const CleanupGrains&); // Copy Constructor Not Implemented
    void operator=(const CleanupGrains&); // Operator '=' Not Implemented
};

#endif /* CLEANUPGRAINS_H_ */
