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

#include "OrthoRhombicOps.h"
// Include this FIRST because there is a needed define for some compiles
// to expose some of the constants needed below
#include "DREAM3DLib/Common/DREAM3DMath.h"

const static float m_pi = (float)M_PI;
const static float two_pi = 2.0f * m_pi;
const static float recip_pi = 1.0f/m_pi;
const static float pi_over_180 = m_pi/180.0f;
const static float m_OnePointThree = 1.33333333333f;
const float threesixty_over_pi = 360.0f/m_pi;
const float oneeighty_over_pi = 180.0f/m_pi;
const float sqrt_two = powf(2.0f, 0.5f);

static const float OrthoDim1InitValue = powf((0.75f*((m_pi/2.0f)-sinf((m_pi/2.0f)))),(1.0f/3.0f));
static const float OrthoDim2InitValue = powf((0.75f*((m_pi/2.0f)-sinf((m_pi/2.0f)))),(1.0f/3.0f));
static const float OrthoDim3InitValue = powf((0.75f*((m_pi/2.0f)-sinf((m_pi/2.0f)))),(1.0f/3.0f));
static const float OrthoDim1StepValue = OrthoDim1InitValue/18.0f;
static const float OrthoDim2StepValue = OrthoDim2InitValue/18.0f;
static const float OrthoDim3StepValue = OrthoDim3InitValue/18.0f;


static const float OrthoQuatSym[4][5] = {{0.000000000f,0.000000000f,0.000000000f,0.000000000f,1.000000000f},
                   {0.000000000f,1.000000000f,0.000000000f,0.000000000f,0.000000000f},
                   {0.000000000f,0.000000000f,1.000000000f,0.000000000f,0.000000000f},
                   {0.000000000f,0.000000000f,0.000000000f,1.000000000f,0.000000000}};

static const float OrthoRodSym[4][3] = {{0.0f,0.0f,0.0f},
                  {10000000000.0f,0.0f,0.0f},
                  {0.0f,10000000000.0f,0.0f},
                  {0.0f,0.0f,10000000000.0}};




OrthoRhombicOps::OrthoRhombicOps()
{
  // TODO Auto-generated constructor stub

}

OrthoRhombicOps::~OrthoRhombicOps()
{
  // TODO Auto-generated destructor stub
}

float OrthoRhombicOps::_calcMisoQuat(const float quatsym[24][5], int numsym,
                                      float q1[5], float q2[5],
                                      float &n1, float &n2, float &n3)
{
  float wmin = 9999999.0f; //,na,nb,nc;
  float w = 0;
    float n1min = 0.0f;
    float n2min = 0.0f;
    float n3min = 0.0f;
  float qr[5];
  float qc[5];
// float temp;

  qr[1] = -q1[1] * q2[4] + q1[4] * q2[1] - q1[2] * q2[3] + q1[3] * q2[2];
  qr[2] = -q1[2] * q2[4] + q1[4] * q2[2] - q1[3] * q2[1] + q1[1] * q2[3];
  qr[3] = -q1[3] * q2[4] + q1[4] * q2[3] - q1[1] * q2[2] + q1[2] * q2[1];
  qr[4] = -q1[4] * q2[4] - q1[1] * q2[1] - q1[2] * q2[2] - q1[3] * q2[3];
  for (int i = 0; i < numsym; i++)
  {
	//  OrientationMath::multiplyQuaternions(qr, quatsym[i], qc);
	  MULT_QUAT(qr, quatsym[i], qc)
    if (qc[4] < -1) {
      qc[4] = -1;
    }
    else if (qc[4] > 1) {
      qc[4] = 1;
    }

	QuattoAxisAngle(qc, w, n1, n2, n3);

	if (w > m_pi) {
      w = two_pi - w;
    }
    if (w < wmin)
    {
      wmin = w;
      n1min = n1;
      n2min = n2;
      n3min = n3;
    }
  }
  float denom = sqrt((n1*n1+n2*n2+n3*n3));
  n1 = n1/denom;
  n2 = n2/denom;
  n3 = n3/denom;
  wmin = oneeighty_over_pi * wmin;
  return wmin;
}

float OrthoRhombicOps::getMisoQuat( float q1[5],float q2[5],float &n1,float &n2,float &n3)
{
  int numsym = 4;

  return _calcMisoQuat(OrthoQuatSym, numsym, q1, q2, n1, n2, n3);
}


void OrthoRhombicOps::getODFFZRod(float &r1,float &r2, float &r3)
{
  int  numsym = 4;

  _calcRodNearestOrigin(OrthoRodSym, numsym, r1, r2, r3);
}

void OrthoRhombicOps::getMDFFZRod(float &r1,float &r2, float &r3)
{
	float w, n1, n2, n3;
	float FZn1, FZn2, FZn3;

	_calcRodNearestOrigin(OrthoRodSym, 4, r1, r2, r3);
	RodtoAxisAngle(r1, r2, r3, w, n1, n2, n3);

	w = w * oneeighty_over_pi;
	FZn1 = fabs(n1);
	FZn2 = fabs(n2);
	FZn3 = fabs(n3);

	axisAngletoRod(w, FZn1, FZn2, FZn3, r1, r2, r3);
}

void OrthoRhombicOps::getNearestQuat( float *q1, float *q2)
{
  int numsym = 4;

  _calcNearestQuat(OrthoQuatSym, numsym, q1, q2);
}

void OrthoRhombicOps::getFZQuat(float *qr)
{
  int numsym = 4;

    _calcQuatNearestOrigin(OrthoQuatSym, numsym, qr);

}

int OrthoRhombicOps::getMisoBin(float r1, float r2, float r3)
{
  float dim[3];
  float bins[3];
  float step[3];

  RodtoHomochoric(r1, r2, r3);

  dim[0] = OrthoDim1InitValue;
  dim[1] = OrthoDim2InitValue;
  dim[2] = OrthoDim3InitValue;
  step[0] = OrthoDim1StepValue;
  step[1] = OrthoDim2StepValue;
  step[2] = OrthoDim3StepValue;
  bins[0] = 36.0;
  bins[1] = 36.0;
  bins[2] = 36.0;

  return _calcMisoBin(dim, bins, step, r1, r2, r3);
}

void OrthoRhombicOps::determineEulerAngles(int choose, float &synea1, float &synea2, float &synea3)
{
  float init[3];
  float step[3];
  float phi[3];
  float r1, r2, r3;

  init[0] = OrthoDim1InitValue;
  init[1] = OrthoDim2InitValue;
  init[2] = OrthoDim3InitValue;
  step[0] = OrthoDim1StepValue;
  step[1] = OrthoDim2StepValue;
  step[2] = OrthoDim3StepValue;
  phi[0] = static_cast<float>(choose % 36);
  phi[1] = static_cast<float>((choose / 36) % 36);
  phi[2] = static_cast<float>(choose / (36 * 36));

  _calcDetermineHomochoricValues(init, step, phi, choose, r1, r2, r3);
  HomochorictoRod(r1, r2, r3);
  getODFFZRod(r1, r2, r3);
  RodtoEuler(r1, r2, r3, synea1, synea2, synea3);
}


void OrthoRhombicOps::determineRodriguesVector( int choose, float &r1, float &r2, float &r3)
{
  float init[3];
  float step[3];
  float phi[3];

  init[0] = OrthoDim1InitValue;
  init[1] = OrthoDim2InitValue;
  init[2] = OrthoDim3InitValue;
  step[0] = OrthoDim1StepValue;
  step[1] = OrthoDim2StepValue;
  step[2] = OrthoDim3StepValue;
  phi[0] = static_cast<float>(choose % 36);
  phi[1] = static_cast<float>((choose / 36) % 36);
  phi[2] = static_cast<float>(choose / (36 * 36));

  _calcDetermineHomochoricValues(init, step, phi, choose, r1, r2, r3);
  HomochorictoRod(r1, r2, r3);
  getMDFFZRod(r1, r2, r3);
}

int OrthoRhombicOps::getOdfBin(float r1, float r2, float r3)
{
  float dim[3];
  float bins[3];
  float step[3];

  OrientationMath::RodtoHomochoric(r1, r2, r3);

  dim[0] = OrthoDim1InitValue;
  dim[1] = OrthoDim2InitValue;
  dim[2] = OrthoDim3InitValue;
  step[0] = OrthoDim1StepValue;
  step[1] = OrthoDim2StepValue;
  step[2] = OrthoDim3StepValue;
  bins[0] = 36.0f;
  bins[1] = 36.0f;
  bins[2] = 36.0f;

  return _calcODFBin(dim, bins, step, r1, r2, r3);
}

void OrthoRhombicOps::getSchmidFactorAndSS(float loadx, float loady, float loadz, float &schmidfactor, int &slipsys)
{

}

