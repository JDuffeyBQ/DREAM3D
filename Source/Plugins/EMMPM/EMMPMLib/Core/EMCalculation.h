/* ============================================================================
 * Copyright (c) 2009-2016 BlueQuartz Software, LLC
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
 * Neither the name of BlueQuartz Software, the US Air Force, nor the names of its
 * contributors may be used to endorse or promote products derived from this software
 * without specific prior written permission.
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
 * The code contained herein was partially funded by the followig contracts:
 *    United States Air Force Prime Contract FA8650-07-D-5800
 *    United States Air Force Prime Contract FA8650-10-D-5210
 *    United States Prime Contract Navy N00173-07-C-2068
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#pragma once

#include <memory>

#include <QtCore/QString>

#include "SIMPLib/Common/Observable.h"

#include "EMMPMLib/EMMPMLib.h"
#include "EMMPMLib/Core/EMMPM_Data.h"
#include "EMMPMLib/Core/EMMPM_Constants.h"
#include "EMMPMLib/Core/EMMPM.h"
#include "EMMPMLib/Common/StatsDelegate.h"

class EMCalculationMessageHandler;

/**
 * @class EMCalculation EMCalculation Common/CurvatureEM.h
 * @brief This class performs the EM Loops of the EM/MPM algorithm
 *
 * @date Sep 10, 2012
 * @version 1.0
 */
class EMMPMLib_EXPORT EMCalculation : public Observable
{
  Q_OBJECT

public:
  using Self = EMCalculation;
  using Pointer = std::shared_ptr<Self>;
  using ConstPointer = std::shared_ptr<const Self>;
  using WeakPointer = std::weak_ptr<Self>;
  using ConstWeakPointer = std::weak_ptr<const Self>;
  static Pointer NullPointer();

  static Pointer New();

  /**
   * @brief Returns the name of the class for EMCalculation
   */
  QString getNameOfClass() const override;
  /**
   * @brief Returns the name of the class for EMCalculation
   */
  static QString ClassName();

  virtual ~EMCalculation();

  friend EMCalculationMessageHandler;

  /**
   * @brief Setter property for Data
   */
  void setData(const EMMPM_Data::Pointer& value);
  /**
   * @brief Getter property for Data
   * @return Value of Data
   */
  EMMPM_Data::Pointer getData() const;

  /**
   * @brief Setter property for StatsDelegate
   */
  void setStatsDelegate(StatsDelegate* value);
  /**
   * @brief Getter property for StatsDelegate
   * @return Value of StatsDelegate
   */
  StatsDelegate* getStatsDelegate() const;

  /**
   * @brief Setter property for ErrorCode
   */
  void setErrorCode(int value);
  /**
   * @brief Getter property for ErrorCode
   * @return Value of ErrorCode
   */
  int getErrorCode() const;

  /**
   * @brief This returns a string that is displayed in the GUI. It should be readable
   * and understandable by humans.
   */
  virtual QString getHumanLabel() const;

  /**
   * @fn void EMMPM_CurvatureEMLoops(EMMPM_Data* data, EMMPM_CallbackFunctions* callbacks)
   * @brief Runs the EM portion of the EM/MPM Algorithm
   * @param data a non nullptr EMMPM_Data pointer
   * @param callbacks a non nullptr EMMPM_CallbackFunctions
   */
  void execute();

protected:
  EMCalculation();

public:
  EMCalculation(const EMCalculation&) = delete;            // Copy Constructor Not Implemented
  EMCalculation(EMCalculation&&) = delete;                 // Move Constructor Not Implemented
  EMCalculation& operator=(const EMCalculation&) = delete; // Copy Assignment Not Implemented
  EMCalculation& operator=(EMCalculation&&) = delete;      // Move Assignment Not Implemented

private:
  StatsDelegate* m_StatsDelegate = nullptr;

  EMMPM_Data::Pointer m_Data = {};
  int m_ErrorCode = {};
};
