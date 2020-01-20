/*
 This code was extracted from HierarchicalSmooth, https://github.com/siddharth-maddali/HierarchicalSmooth,
 from commit 31ef680011f4bbaef59c0944876e84222ea7c49f
*/

// Copyright (c) 2016-2018, Siddharth Maddali
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of Carnegie Mellon University nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

/*
 *
 * Base.h -- Contains basic function definitions
 *
 */

#pragma once

#include "Types.h"

namespace HierarchicalSmooth
{

/* ismember:
 * Mimics the basic functionality of Matlab's 'ismember' function, currently only for
 * integer arrays with 3 columns because it is used on triangulations.
 */
TriMesh isMember(const TriMesh& array1, const std::vector<int>& array2);

/* getindex:
 * Returns a MatIndex object (defined in Types.h) of integers given an
 * STL std::vector< int > object. Variant returns position of each integer
 * with respect to a user-supplied MatIndex.
 */
MatIndex getIndex(const std::vector<int32_t>& inputVec);
MatIndex getIndex(const std::vector<int32_t>& inputVec, const MatIndex& matIndex);

/* getcomplement:
 * Given a MatIndex M and an integer N > max( M ), returns a MatIndex containing
 * { integer i | i < N and i not in M }. Used to find indices of mobile nodes
 * given the foxed ones and vice versa.
 */
MatIndex getComplement(const MatIndex& nSet, int32_t N);

/* matunion:
 * Returns the set union of the indexes in the two input MatIndexes,
 * sorted in ascending order.
 */
MatIndex matUnion(const MatIndex& mat1, const MatIndex& mat2);

/* merge:
 * Copies row data from source array into target array at the locations specified
 * by the input MatIndex. NOTE: Source array should have same number of rows
 * as elements in the MatIndex. Two versions are provided, for sparse and dense.
 */
void merge(const Eigen::Ref<const MeshNode>& source, Eigen::Ref<MeshNode> target, const MatIndex& locations);
void merge(const SparseMatrixF& source, SparseMatrixF& target, const MatIndex& locations);

} // namespace HSmoothBase
