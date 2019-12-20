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

#include "SIMPLib/SIMPLib.h"
#include "SIMPLib/Filtering/AbstractFilter.h"
#include "SIMPLib/DataArrays/DataArray.hpp"

class IDataArray;
using IDataArrayWkPtrType = std::weak_ptr<IDataArray>;

#include "Processing/ProcessingDLLExport.h"

/**
 * @brief The FindProjectedImageStatistics class. See [Filter documentation](@ref findprojectedimagestatistics) for details.
 */
class Processing_EXPORT FindProjectedImageStatistics : public AbstractFilter
{
  Q_OBJECT

#ifdef SIMPL_ENABLE_PYTHON
  PYB11_CREATE_BINDINGS(FindProjectedImageStatistics SUPERCLASS AbstractFilter)
  PYB11_SHARED_POINTERS(FindProjectedImageStatistics)
  PYB11_FILTER_NEW_MACRO(FindProjectedImageStatistics)
  PYB11_FILTER_PARAMETER(DataArrayPath, SelectedArrayPath)
  PYB11_FILTER_PARAMETER(unsigned int, Plane)
  PYB11_FILTER_PARAMETER(QString, ProjectedImageMinArrayName)
  PYB11_FILTER_PARAMETER(QString, ProjectedImageMaxArrayName)
  PYB11_FILTER_PARAMETER(QString, ProjectedImageAvgArrayName)
  PYB11_FILTER_PARAMETER(QString, ProjectedImageStdArrayName)
  PYB11_FILTER_PARAMETER(QString, ProjectedImageVarArrayName)
  PYB11_PROPERTY(DataArrayPath SelectedArrayPath READ getSelectedArrayPath WRITE setSelectedArrayPath)
  PYB11_PROPERTY(unsigned int Plane READ getPlane WRITE setPlane)
  PYB11_PROPERTY(QString ProjectedImageMinArrayName READ getProjectedImageMinArrayName WRITE setProjectedImageMinArrayName)
  PYB11_PROPERTY(QString ProjectedImageMaxArrayName READ getProjectedImageMaxArrayName WRITE setProjectedImageMaxArrayName)
  PYB11_PROPERTY(QString ProjectedImageAvgArrayName READ getProjectedImageAvgArrayName WRITE setProjectedImageAvgArrayName)
  PYB11_PROPERTY(QString ProjectedImageStdArrayName READ getProjectedImageStdArrayName WRITE setProjectedImageStdArrayName)
  PYB11_PROPERTY(QString ProjectedImageVarArrayName READ getProjectedImageVarArrayName WRITE setProjectedImageVarArrayName)
#endif

public:
  using Self = FindProjectedImageStatistics;
  using Pointer = std::shared_ptr<Self>;
  using ConstPointer = std::shared_ptr<const Self>;
  using WeakPointer = std::weak_ptr<Self>;
  using ConstWeakPointer = std::weak_ptr<const Self>;
  
  /**
   * @brief Returns a NullPointer wrapped by a shared_ptr<>
   * @return
   */
  static Pointer NullPointer();

  /**
   * @brief Creates a new object wrapped in a shared_ptr<>
   * @return
   */
  static Pointer New();

  /**
   * @brief Returns the name of the class for FindProjectedImageStatistics
   */
  QString getNameOfClass() const override;
  /**
   * @brief Returns the name of the class for FindProjectedImageStatistics
   */
  static QString ClassName();

  ~FindProjectedImageStatistics() override;

  /**
   * @brief Setter property for SelectedArrayPath
   */
  void setSelectedArrayPath(const DataArrayPath& value);
  /**
   * @brief Getter property for SelectedArrayPath
   * @return Value of SelectedArrayPath
   */
  DataArrayPath getSelectedArrayPath() const;

  Q_PROPERTY(DataArrayPath SelectedArrayPath READ getSelectedArrayPath WRITE setSelectedArrayPath)

  /**
   * @brief Setter property for Plane
   */
  void setPlane(unsigned int value);
  /**
   * @brief Getter property for Plane
   * @return Value of Plane
   */
  unsigned int getPlane() const;

  Q_PROPERTY(unsigned int Plane READ getPlane WRITE setPlane)

  /**
   * @brief Setter property for ProjectedImageMinArrayName
   */
  void setProjectedImageMinArrayName(const QString& value);
  /**
   * @brief Getter property for ProjectedImageMinArrayName
   * @return Value of ProjectedImageMinArrayName
   */
  QString getProjectedImageMinArrayName() const;

  Q_PROPERTY(QString ProjectedImageMinArrayName READ getProjectedImageMinArrayName WRITE setProjectedImageMinArrayName)

  /**
   * @brief Setter property for ProjectedImageMaxArrayName
   */
  void setProjectedImageMaxArrayName(const QString& value);
  /**
   * @brief Getter property for ProjectedImageMaxArrayName
   * @return Value of ProjectedImageMaxArrayName
   */
  QString getProjectedImageMaxArrayName() const;

  Q_PROPERTY(QString ProjectedImageMaxArrayName READ getProjectedImageMaxArrayName WRITE setProjectedImageMaxArrayName)

  /**
   * @brief Setter property for ProjectedImageAvgArrayName
   */
  void setProjectedImageAvgArrayName(const QString& value);
  /**
   * @brief Getter property for ProjectedImageAvgArrayName
   * @return Value of ProjectedImageAvgArrayName
   */
  QString getProjectedImageAvgArrayName() const;

  Q_PROPERTY(QString ProjectedImageAvgArrayName READ getProjectedImageAvgArrayName WRITE setProjectedImageAvgArrayName)

  /**
   * @brief Setter property for ProjectedImageStdArrayName
   */
  void setProjectedImageStdArrayName(const QString& value);
  /**
   * @brief Getter property for ProjectedImageStdArrayName
   * @return Value of ProjectedImageStdArrayName
   */
  QString getProjectedImageStdArrayName() const;

  Q_PROPERTY(QString ProjectedImageStdArrayName READ getProjectedImageStdArrayName WRITE setProjectedImageStdArrayName)

  /**
   * @brief Setter property for ProjectedImageVarArrayName
   */
  void setProjectedImageVarArrayName(const QString& value);
  /**
   * @brief Getter property for ProjectedImageVarArrayName
   * @return Value of ProjectedImageVarArrayName
   */
  QString getProjectedImageVarArrayName() const;

  Q_PROPERTY(QString ProjectedImageVarArrayName READ getProjectedImageVarArrayName WRITE setProjectedImageVarArrayName)

  /**
   * @brief getCompiledLibraryName Reimplemented from @see AbstractFilter class
   */
  QString getCompiledLibraryName() const override;

  /**
   * @brief getBrandingString Returns the branding string for the filter, which is a tag
   * used to denote the filter's association with specific plugins
   * @return Branding string
  */
  QString getBrandingString() const override;

  /**
   * @brief getFilterVersion Returns a version string for this filter. Default
   * value is an empty string.
   * @return
   */
  QString getFilterVersion() const override;

  /**
   * @brief newFilterInstance Reimplemented from @see AbstractFilter class
   */
  AbstractFilter::Pointer newFilterInstance(bool copyFilterParameters) const override;

  /**
   * @brief getGroupName Reimplemented from @see AbstractFilter class
   */
  QString getGroupName() const override;

  /**
   * @brief getSubGroupName Reimplemented from @see AbstractFilter class
   */
  QString getSubGroupName() const override;

  /**
   * @brief getUuid Return the unique identifier for this filter.
   * @return A QUuid object.
   */
  QUuid getUuid() const override;

  /**
   * @brief getHumanLabel Reimplemented from @see AbstractFilter class
   */
  QString getHumanLabel() const override;

  /**
   * @brief setupFilterParameters Reimplemented from @see AbstractFilter class
   */
  void setupFilterParameters() override;

  /**
   * @brief readFilterParameters Reimplemented from @see AbstractFilter class
   */
  void readFilterParameters(AbstractFilterParametersReader* reader, int index) override;

  /**
   * @brief execute Reimplemented from @see AbstractFilter class
   */
  void execute() override;

  /**
  * @brief preflight Reimplemented from @see AbstractFilter class
  */
  void preflight() override;



protected:
  FindProjectedImageStatistics();
  /**
   * @brief dataCheck Checks for the appropriate parameter values and availability of arrays
   */
  void dataCheck();

  /**
   * @brief Initializes all the private instance variables.
   */
  void initialize();

private:
  IDataArrayWkPtrType m_InDataPtr;
  void* m_InData = nullptr;

  std::weak_ptr<DataArray<float>> m_ProjectedImageMinPtr;
  float* m_ProjectedImageMin = nullptr;
  std::weak_ptr<DataArray<float>> m_ProjectedImageMaxPtr;
  float* m_ProjectedImageMax = nullptr;
  std::weak_ptr<DataArray<float>> m_ProjectedImageAvgPtr;
  float* m_ProjectedImageAvg = nullptr;
  std::weak_ptr<DataArray<float>> m_ProjectedImageStdPtr;
  float* m_ProjectedImageStd = nullptr;
  std::weak_ptr<DataArray<float>> m_ProjectedImageVarPtr;
  float* m_ProjectedImageVar = nullptr;

  DataArrayPath m_SelectedArrayPath = {};
  unsigned int m_Plane = {};
  QString m_ProjectedImageMinArrayName = {};
  QString m_ProjectedImageMaxArrayName = {};
  QString m_ProjectedImageAvgArrayName = {};
  QString m_ProjectedImageStdArrayName = {};
  QString m_ProjectedImageVarArrayName = {};

public:
  FindProjectedImageStatistics(const FindProjectedImageStatistics&) = delete; // Copy Constructor Not Implemented
  FindProjectedImageStatistics(FindProjectedImageStatistics&&) = delete;      // Move Constructor Not Implemented
  FindProjectedImageStatistics& operator=(const FindProjectedImageStatistics&) = delete; // Copy Assignment Not Implemented
  FindProjectedImageStatistics& operator=(FindProjectedImageStatistics&&) = delete;      // Move Assignment Not Implemented
};

