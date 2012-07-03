/* ============================================================================
 * Copyright (c) 2012 Michael A. Jackson (BlueQuartz Software)
 * Copyright (c) 2012 Dr. Michael A. Groeber (US Air Force Research Laboratories)
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
#ifndef _QFILTERWIDGET_H_
#define _QFILTERWIDGET_H_

#include <QtCore/QSettings>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QSpinBox>
#include <QtGui/QLabel>
#include <QtGui/QCheckBox>
#include <QtGui/QLineEdit>
#include <QtGui/QIntValidator>
#include <QtGui/QDoubleValidator>
#include <QtGui/QComboBox>

#include "DREAM3DLib/Common/AbstractFilter.h"

#include "QtSupport/QFSDropLineEdit.h"

#include "PipelineBuilderDLLExport.h"

#if 1
/**
* @brief Creates a "setter" method to set the property.
*/
#define QFILTERWIDGET_SET_PROPERTY(type, prpty) \
  void set##prpty(type value) { this->m_##prpty = value; emit parametersChanged(); }

/**
* @brief Creates a "getter" method to retrieve the value of the property.
*/
#define QFILTERWIDGET_GET_PROPERTY(type, prpty) \
  type get##prpty() { return m_##prpty; }

#define QFILTERWIDGET_INSTANCE_PROPERTY(type, prpty)\
  private:\
      type   m_##prpty;\
  public:\
    QFILTERWIDGET_SET_PROPERTY(type, prpty)\
    QFILTERWIDGET_GET_PROPERTY(type, prpty)

#endif



// This needs to be defined
class QMouseEvent;

/**
 * @class QFilterWidget QFilterWidget.h FilterWidgets/QFilterWidget.h
 * @brief  This class is a subclass of the QGroupBox class and is used to display
 * Filter Options that the user can set. This class is capable of constructing a
 * default GUI widget set for each type of Filter Option that is available. If
 * the programmer needs more specialized widgets then they can simply subclass
 * this class and over ride or implement their custom code.
 * @author Michael A. Jackson for BlueQuartz Software
 * @date Jan 6, 2012
 * @version 1.0
 */
class PipelineBuilderLib_EXPORT QFilterWidget : public QGroupBox
{
    Q_OBJECT
  public:
    QFilterWidget(QWidget* parent = NULL);
    virtual ~QFilterWidget();

    virtual void setupGui();

    virtual AbstractFilter::Pointer getFilter();

    virtual void writeOptions(QSettings &prefs);
    virtual void readOptions(QSettings &prefs);
    virtual void setBorderColorStyle(QString s);
    virtual QString getBorderColorStyle();
    virtual bool isSelected();

    virtual void emitParametersChanged();

    virtual QFilterWidget* createDeepCopy();

  signals:
    void dragStarted(QFilterWidget* widget);
    void parametersChanged();

  public slots:

     virtual void updateFilterValues();
     virtual void updateQLineEditDoubleValue();
     virtual void updateQLineEditIntValue();
     virtual void selectInputFile();
     virtual void selectOutputFile();
     virtual void updateComboBoxValue(int v);
     virtual void updateQSpinBoxValue(int v);
     virtual void updateQDoubleSpinBoxValue(double v);
     virtual void updateQCheckBoxValue(int v);
     virtual void updateQLineEditStringValue(const QString &v);

     virtual void updateLineEdit(const QString &v);

     virtual void setIsSelected(bool b);


     /**
      * @brief Sets the style of the Widget to indicate a selected or non-selected
      * state
      * @param selected Is the widget selected or not.
      */
     void changeStyle();

     /**
      *@brief
      */
     void updateWidgetStyle();

     /**
      * @brief Slot for a QTime to call to update the border of the wiget in a
      * pulsing fashing
      */
     void setHasPreflightErrors(bool hasErrors);

  signals:
    void widgetSelected(QFilterWidget* w);


  protected:
     virtual void mousePressEvent( QMouseEvent* event );
     virtual void mouseReleaseEvent( QMouseEvent* event );
//     virtual void mouseDoubleClickEvent( QMouseEvent* event );
     virtual void mouseMoveEvent( QMouseEvent* event );

  private:
     QRect      m_DeleteRect;
     QPoint     dragStartPosition;
     QTimer*    m_timer;
     unsigned char  m_CurrentBorderColorFactor;
     unsigned char        m_BorderIncrement;
     QString    m_BorderColorStyle;
     bool       m_IsSelected;
     bool       m_HasPreflightErrors;


    QFilterWidget(const QFilterWidget&); // Copy Constructor Not Implemented
    void operator=(const QFilterWidget&); // Operator '=' Not Implemented

};



#endif /* _QFILTERWIDGET_H_ */
