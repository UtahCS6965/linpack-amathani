/*
 *  -- High Performance Computing Linpack Benchmark (HPL-GPU)
 *     HPL-GPU - 1.1 - 2011
 *
 *     David Rohr
 *     Matthias Kretz
 *     Matthias Bach
 *     Goethe Universität, Frankfurt am Main
 *     Frankfurt Institute for Advanced Studies
 *     (C) Copyright 2010 All Rights Reserved
 *
 *     Antoine P. Petitet
 *     University of Tennessee, Knoxville
 *     Innovative Computing Laboratory
 *     (C) Copyright 2000-2008 All Rights Reserved
 *
 *  -- Copyright notice and Licensing terms:
 *
 *  Redistribution  and  use in  source and binary forms, with or without
 *  modification, are  permitted provided  that the following  conditions
 *  are met:
 *
 *  1. Redistributions  of  source  code  must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce  the above copyright
 *  notice, this list of conditions,  and the following disclaimer in the
 *  documentation and/or other materials provided with the distribution.
 *
 *  3. All  advertising  materials  mentioning  features  or  use of this
 *  software must display the following acknowledgements:
 *  This  product  includes  software  developed  at  the  University  of
 *  Tennessee, Knoxville, Innovative Computing Laboratory.
 *  This product  includes software  developed at the Frankfurt Institute
 *  for Advanced Studies.
 *
 *  4. The name of the  University,  the name of the  Laboratory,  or the
 *  names  of  its  contributors  may  not  be used to endorse or promote
 *  products  derived   from   this  software  without  specific  written
 *  permission.
 *
 *  -- Disclaimer:
 *
 *  THIS  SOFTWARE  IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE UNIVERSITY
 *  OR  CONTRIBUTORS  BE  LIABLE FOR ANY  DIRECT,  INDIRECT,  INCIDENTAL,
 *  SPECIAL,  EXEMPLARY,  OR  CONSEQUENTIAL DAMAGES  (INCLUDING,  BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA OR PROFITS; OR BUSINESS INTERRUPTION)  HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT,  STRICT LIABILITY,  OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ======================================================================
 */

#ifndef HPL_H
#define HPL_H
/*
* ---------------------------------------------------------------------
* HPL default compile options that can overridden in the Make.<arch>
* ---------------------------------------------------------------------
*/
#ifndef HPL_NO_MPI_DATATYPE         /* Use MPI user-defined data type */
#define HPL_USE_MPI_DATATYPE
#endif

#ifndef HPL_COPY_L  /* do not copy L, use MPI user-defined data types */
#define HPL_NO_COPY_L
#endif

#ifndef HPL_DETAILED_TIMING         /* Do not enable detailed timings */
#define HPL_NO_DETAILED_TIMING
#endif

#ifndef TRACE_CALLS                  /* Don't trace on function level */
#define NO_TRACE_CALLS
#endif

/*
* ---------------------------------------------------------------------
* Include files
* ---------------------------------------------------------------------
*/
#include "hpl_misc.h"
#include "hpl_blas.h"
#include "hpl_auxil.h"
#include "hpl_gesv.h"

#include "hpl_pmisc.h"
#include "hpl_pauxil.h"
#include "hpl_panel.h"
#include "hpl_pfact.h"
#include "hpl_pgesv.h"

#include "hpl_matgen.h"
#include "hpl_test.h"

#include "hpl_ptimer.h"
#include "hpl_pmatgen.h"
#include "hpl_ptest.h"

#ifdef HPL_DETAILED_TIMING
#define HPL_ptimer_detail(arg) HPL_ptimer(arg)
#else
#define HPL_ptimer_detail(arg)
#endif

#ifdef HPL_DETAILED2_TIMING
#define HPL_ptimer_detail2(arg) HPL_ptimer(arg)
#else
#define HPL_ptimer_detail2(arg)
#endif

#ifdef CALDGEMM_TEST
#define fprintfct fprintf
#else
#define fprintfct(...)
#endif

#ifdef CALDGEMM_TEST_DEBUG
#define fprintfctd fprintf
#else
#define fprintfctd(...)
#endif

#ifdef QON_TEST
#define fprintfqt fprintf
#else
#define fprintfqt(...)
#endif

#if defined(HPL_LOOKAHEAD_2B) & defined(HPL_SEND_U_PADDING)
#error Lookahead 2B cannot be used in combination with HPL_SEND_U_PADDING
#endif

#ifndef STD_OUT
#define STD_OUT stdout
#endif

#endif
/*
* End of hpl.h
*/
