#!/bin/bash

mkdir build
cd build

cmake -S "$SRC_DIR/DREAM3D" -B . -G "Ninja" $CMAKE_ARGS \
  -D CMAKE_BUILD_TYPE:STRING=Release \
  -D CMAKE_INSTALL_PREFIX:PATH="$PREFIX" \
  -D CMAKE_SYSTEM_PREFIX_PATH:PATH="$PREFIX" \
  -D QWT_INSTALL:PATH="$PREFIX" \
  -D DREAM3D_EXTRA_PLUGINS:STRING="$DREAM3D_PLUGINS" \
  -D SIMPL_WRAP_PYTHON:BOOL=ON \
  -D ITKImageProcessing_ENABLE_ITK_MONTAGE:BOOL=OFF \
  -D ITKImageProcessing_ENABLE_ITK_TOTAL_VARIATION:BOOL=OFF \
  -D ITKImageProcessing_LeanAndMean:BOOL=OFF \
  -D SIMPL_USE_MULTITHREADED_ALGOS:BOOL=ON \
  -D SIMPL_EMBED_PYTHON:BOOL=ON \
  -D DREAM3D_DATA_DIR:PATH="$SRC_DIR/DREAM3D_Data" \
  -D DREAM3D_DISABLE_DEPENDENCY_COPY_INSTALL_RULES:BOOL=ON \
  -D SIMPL_Group_REST:BOOL=OFF \
  -D BUILD_TESTING:BOOL=OFF \
  -D SIMPL_BUILD_TESTING:BOOL=OFF \
  -D EbsdLib_ENABLE_TESTING:BOOL=OFF \
  -D H5Support_BUILD_TESTING:BOOL=OFF \
  -D DREAM3D_ANACONDA:BOOL=ON \
  -D DREAM3D_ANACONDA_INSTALL:BOOL=ON \
  -D SIMPLView_BUILD_DOCUMENTATION:BOOL=ON \
  -D PYTHON_EXECUTABLE:FILEPATH="$PYTHON" \
  -D MKDOCS_PYTHON_EXECUTABLE:FILEPATH="$PYTHON" \
  -D CMP_HDF5_USE_CONFIG:BOOL=OFF

cmake --build . --target all

cmake --build . --target install

cd python_package
$PYTHON setup.py install
