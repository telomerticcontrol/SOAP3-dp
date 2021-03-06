/*
 *
 *    BGS-HostAlgnmtAlgo2.h
 *    Soap3(gpu)
 *
 *    Copyright (C) 2011, HKU
 *
 *    This program is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU General Public License
 *    as published by the Free Software Foundation; either version 2
 *    of the License, or (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef __BGS_HOSTALIGNMENT_ALGO_H_2__
#define __BGS_HOSTALIGNMENT_ALGO_H_2__

#include <stdio.h>
#include <stdlib.h>
#include "2bwt-lib/BWT.h"
#include "2bwt-lib/HSP.h"
#include "2bwt-flex/LT.h"
#include "2bwt-flex/SRA2BWTCheckAndExtend.h"

#include "BGS-IO.h"
#include "2bwt-flex/SRAArguments.h"
#include "SAList.h"


//====================MODELIZED BELOW======================
// BWTxxxModelxxx functions are fully generalised BWT search algorithm that searchs for reads contain any number of edit/mismatch
// However, calling these functions requires user to define themselves a 'searching model'.
// The searching model requires each BWT step to be defined. The search algorithm will then follow the defined model.

// BWTMismatchModelAnyDirection_CE matches steps with check and extend mechanism.
// It allows starting off CE in the middle of a step and recursive CE until SRACase completes.

// The following functions are modified such that the resulting SA ranges will be collected


unsigned long long BWTMismatchModelAnyDirection_CE2 ( SRAQueryInput * qInput, int i, int mismatchInserted,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges,
        int occMismatch, uint8_t nbMismatch, char occQuality, SAList * sa_list, OCCList * occ_list );


// BWTExactModelForward_Lookup lookup your pattern in lookup table, bi-directional and assuming forward
unsigned long long BWTExactModelForward_Lookup2 ( SRAQueryInput * qInput,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges, SAList * sa_list, OCCList * occ_list );

// BWTExactModelBackward_Lookup lookup your pattern in lookup table, single direction and assuming backward
unsigned long long BWTExactModelBackward_Lookup2 ( SRAQueryInput * qInput,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges, SAList * sa_list, OCCList * occ_list );

// BWTExactModelBackwardAnyDirection_Lookup lookup your pattern in lookup table, single direction and assuming backward
unsigned long long BWTExactModelBackwardAnyDirection_Lookup2 ( SRAQueryInput * qInput,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges, SingleAlgnResult * algnResult );

// BWTExactModelBackward matches pattern on text without using any other aux, e.g. lookup table.
unsigned long long BWTExactModelBackward2 ( SRAQueryInput * qInput, int i, int errorInserted,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges,
        int occError, uint8_t nbMismatch, char occQuality, SAList * sa_list, OCCList * occ_list );

// BWTMismatchModelAnyDirection matches pattern on text without using any other aux, e.g. lookup table, with mismatches.
unsigned long long BWTExactModelAnyDirection2 ( SRAQueryInput * qInput, int i, int errorInserted,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges,
        int occError, uint8_t nbMismatch, char occQuality, SAList * sa_list, OCCList * occ_list );

// BWTMismatchModelAnyDirection matches pattern on text without using any other aux, e.g. lookup table, with mismatches.
unsigned long long BWTMismatchModelAnyDirection2 ( SRAQueryInput * qInput, int i, int mismatchInserted,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges,
        int occMismatch, uint8_t nbMismatch, char occQuality, SAList * sa_list, OCCList * occ_list );

// BWTMismatchModelBackward matches pattern on text without using any other aux, e.g. lookup table, with mismatches.
unsigned long long BWTMismatchModelBackward2 ( SRAQueryInput * qInput, int i, int mismatchInserted,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges,
        int occMismatch, uint8_t nbMismatch, char occQuality, SAList * sa_list, OCCList * occ_list );


// BWTEditModelAnyDirection matches pattern on text without using any other aux, e.g. lookup table, with mismatches.
unsigned long long BWTEditModelAnyDirection2 ( SRAQueryInput * qInput, int i, int editInserted,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges,
        int occEdit, uint8_t nbMismatch, char occQuality, SAList * sa_list, OCCList * occ_list );

// BWTEditModelBackward matches pattern on text without using any other aux, e.g. lookup table, with mismatches.
unsigned long long BWTEditModelBackward2 ( SRAQueryInput * qInput, int i, int editInserted,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges,
        int occEdit, uint8_t nbMismatch, char occQuality, SAList * sa_list, OCCList * occ_list );

unsigned long long BWTModelSwitchAnyDirection2 ( SRAQueryInput * qInput, int i, int errorInserted,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges,
        int occError, uint8_t nbMismatch, char occQuality, SAList * sa_list, OCCList * occ_list );

unsigned long long BWTModelSwitchBackward2 ( SRAQueryInput * qInput,  int i, int errorInserted,
        SRACase * alignmentCase, int stepInCase,
        unsigned long long * saRanges,
        int occError, uint8_t nbMismatch, char occQuality, SAList * sa_list, OCCList * occ_list );



#endif
