/** 
 * @file llframestatview.h
 * @brief LLFrameStatView class definition
 *
 * $LicenseInfo:firstyear=2001&license=viewergpl$
 * 
 * Copyright (c) 2001-2009, Linden Research, Inc.
 * 
 * Second Life Viewer Source Code
 * The source code in this file ("Source Code") is provided by Linden Lab
 * to you under the terms of the GNU General Public License, version 2.0
 * ("GPL"), unless you have obtained a separate licensing agreement
 * ("Other License"), formally executed by you and Linden Lab.  Terms of
 * the GPL can be found in doc/GPL-license.txt in this distribution, or
 * online at http://secondlifegrid.net/programs/open_source/licensing/gplv2
 * 
 * There are special exceptions to the terms and conditions of the GPL as
 * it is applied to this Source Code. View the full text of the exception
 * in the file doc/FLOSS-exception.txt in this software distribution, or
 * online at http://secondlifegrid.net/programs/open_source/licensing/flossexception
 * 
 * By copying, modifying or distributing this software, you acknowledge
 * that you have read and understood your obligations described above,
 * and agree to abide by those obligations.
 * 
 * ALL LINDEN LAB SOURCE CODE IS PROVIDED "AS IS." LINDEN LAB MAKES NO
 * WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY,
 * COMPLETENESS OR PERFORMANCE.
 * $/LicenseInfo$
 */

#ifndef LL_LLFRAMESTATVIEW_H
#define LL_LLFRAMESTATVIEW_H

#include "llview.h"
#include "lltimer.h"
#include "v4color.h"

class LLStat;
class LLFrameStats;

class LLFrameStatView : public LLView
{
public:
	enum
	{
		MAX_STATS = 30
	};
	LLFrameStatView(const std::string& name, const LLRect& rect);
	virtual ~LLFrameStatView();

	void setup(const LLFrameStats &frame_stats);

	virtual BOOL handleMouseDown(S32 x, S32 y, MASK mask);
	virtual BOOL handleMouseUp(S32 x, S32 y, MASK mask);
	virtual BOOL handleHover(S32 x, S32 y, MASK mask);
	virtual void draw();

	F32 mTotalTime;		// Total time to render for graph.
	F32 mTickSpacing;
	F32 mLabelSpacing;
	S32 mCenterOn;
	BOOL mShowPercent;
	void addStat(LLStat *statp, const std::string& label, const LLColor4 &color);
private:
	LLStat *mStats[MAX_STATS];
	LLColor4 mColors[MAX_STATS];
	std::string mLabels[MAX_STATS];
	S32 mNumStats;
};

#endif
