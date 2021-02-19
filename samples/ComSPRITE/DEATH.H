//body
#define death_part		10

const GtSPRAnim_Frame death_body[4]=
{
//  SHAPE	     ,SIZE     ,hflip,vflip ,charno,   dx,dy,
	Gs_OAM_VRECT,Gs_OAM_BIG,  0  ,  0,		0,		0,0,
	Gs_OAM_VRECT,Gs_OAM_BIG,  0  ,  0,		391,	0,0,
	Gs_OAM_VRECT,Gs_OAM_BIG,  0  ,  0,		393,	0,0,
	Gs_OAM_VRECT,Gs_OAM_BIG,  0  ,  0,		395,	0,0
};

const GtSPRAnim_Frame death_body1[1]=
{
	Gs_OAM_VRECT,Gs_OAM_MIDDLE,0 ,	0,		34,		16,8
};


const GtSPRAnim_Frame death_body2[1]=
{
	Gs_OAM_HRECT,Gs_OAM_SMALL,0  ,	0,		98,		16,24
};


//leg  3 frames
const GtSPRAnim_Frame death_leg[3]=
{
	Gs_OAM_HRECT,Gs_OAM_BIG,  0	,	0,		128,	-2,31,
	Gs_OAM_HRECT,Gs_OAM_BIG,  0	,	0,		192,	-2,31,
	Gs_OAM_HRECT,Gs_OAM_BIG,  0	,	0,		256,	-2,31
};

const GtSPRAnim_Frame death_leg1[3]=
{
	Gs_OAM_VRECT,Gs_OAM_SMALL,0	,	0,		132,	30,32,
	Gs_OAM_VRECT,Gs_OAM_SMALL,0 ,	0,		196,	30,32,
	Gs_OAM_VRECT,Gs_OAM_SMALL,0 ,	0,		260,	30,32
};

//left arm 
const GtSPRAnim_Frame death_L_arm[1]=
{
	Gs_OAM_VRECT,Gs_OAM_BIG, 0	,	0,		6,		-9,11
};
//left hand
const GtSPRAnim_Frame death_L_hand[1]=
{
	Gs_OAM_HRECT,Gs_OAM_SMALL,0 ,	0,		68,		-12,23
};
//right arm 
const GtSPRAnim_Frame death_R_arm[1]=
{
	Gs_OAM_VRECT,Gs_OAM_BIG,  0	,	0,		134,	4,10
};
//right hand
const GtSPRAnim_Frame death_R_hand[1]=
{
	Gs_OAM_VRECT,Gs_OAM_SMALL,0 ,	0,		358,	3,13
};
//weap
const GtSPRAnim_Frame death_weap[1]=
{
	Gs_OAM_SQUARE,Gs_OAM_LARGE,0,	0,		8,		-35,-26
};
//PART LIST
const GtSPRFrameList death_frame[death_part]=
{
	{death_weap		,1},
	{death_L_hand	,1},
	{death_R_hand	,1},
	{death_L_arm	,1},
	{death_R_arm	,1},
	{death_body1	,1},
	{death_body2	,1},
	{death_body		,4},
	{death_leg1		,3},
	{death_leg		,3}
};

const GtSPRITE death=
{
	death_frame,
	death_part
};

