class CfgPatches
{
    class ld3k_jca_mp5a5_compat_ace3
    {
        requiredAddons[]=
        {
            "Weapons_F_JCA_MP5",
            "Weapons_F_JCA_MP5_Accessories",
            "Weapons_F_JCA_MP5_SMGs_MP5"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class CfgAmmo
{
    // class B_9x21_Ball: BulletBase official BI tool All-in-one Config Arma3 2.17.152041 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    class BulletBase;
    /*class B_9x21_Ball: BulletBase
    {
        hit=5;
        indirectHit=0;
        indirectHitRange=0;
        cartridge="FxCartridge_9mm";
        cost=100;
        typicalSpeed=380;
        airFriction=-0.0016;
        caliber=1.2;
        deflecting=25;
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        airLock=1;
        tracerScale=0.5;
        tracerStartTime=0.05;
        tracerEndTime=1;
        nvgOnly=1;
        audibleFire=30;
        aiAmmoUsageFlags=64;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
    };
    class B_9x21_Ball_Tracer_Green: B_9x21_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
        tracerScale=0.5;
        tracerStartTime=0.05;
        tracerEndTime=1;
        nvgOnly=0;
    };
    class B_9x21_Ball_Tracer_Red: B_9x21_Ball_Tracer_Green
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Red";
    };
    class B_9x21_Ball_Tracer_Yellow: B_9x21_Ball_Tracer_Green
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Yellow";
    };
    class JCA_B_9x21_Ball_Tracer_IR: B_9x21_Ball_Tracer_Green // JCA default config
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        nvgOnly=1;
    };
    class ACE_9x19_Ball: B_9x21_Ball // ACE3 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L505
    {
        airFriction=-0.00201185;
        ACE_caliber=9.017;
        ACE_bulletLength=15.494;
        ACE_bulletMass=8.0352;
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619};
        ACE_ballisticCoefficients[]={0.165};
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={340,370,400};
        ACE_barrelLengths[]={101.6,127.0,228.6};
    };*/
    class JCA_B_9x19_Ball_MP5_FMJ: BulletBase // M17 Sig Sauer NATO 9x19mm +P 124gr FMJ https://www.sigsauer.com/blog/sig-sauer-introduces-m17-9mm-p-ammunition
    {
        ACE_caliber=9.03; // 0.356" CIP diameter https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/tabivcal-en-page28.pdf
        ACE_bulletLength=14.859; // 0.585" https://www.sigsauer.com/9mm-p-124gr-elite-ball-m17-fmj-box-50.html
        ACE_bulletMass=8.035; // 124gr
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619}; // default ACE_ammoTempMuzzleVelocityShifts values /10 (Ammo Temp MV Curve Tables by TiborasaurusRex). Muzzle velocity shift 0m/s 70°F (21°C), -1m/s 15°C
        ACE_ballisticCoefficients[]={0.235}; // ICAO G1 BC from exterior ballistic app "EBC V2" based on Sig Sauer 2024 datas https://cdn.bfldr.com/EN1VTHA0/at/k4vxwr73g8mj5bt485mh8bcz/2024_DSG_CATALOG__6-3-24_SL.pdf#page=57
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_barrelLengths[]={101.6,127,228.6}; // default ACE3 4", 5", 9" barrel lengths
        ACE_muzzleVelocities[]={366,398,430}; // Muzzle Velocities 70°F (21°C) +1m/s, 365m/s (1198fps, 4"), 428m/s (1404fps) 8.858" (225mm) ICAO conditions (15°C, 1013.25hPa, 0%) according to JCA_MP5A5 initSpeed
        hit=5.4; // Full Metal Jacket, 736 Joules, B_9x21_Ball 5
        indirectHit=0;
        indirectHitRange=0;
        cartridge="FxCartridge_9mm";
        cost=100;
        typicalSpeed=428; // JCA_30Rnd_9x19_MP5_Mag and JCA_30Rnd_9x19_MP5_JHP_Mag initSpeed
        airFriction=-0.00173436; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        caliber=1.2; // Full Metal Jacket
        deflecting=25;
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        airLock=1;
        tracerScale=0.5;
        tracerStartTime=0.05;
        tracerEndTime=1;
        nvgOnly=0; // B_9x21_Ball 1
        audibleFire=30;
        aiAmmoUsageFlags=64;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
    };
    class JCA_B_9x19_Ball_MP5_JHP: JCA_B_9x19_Ball_MP5_FMJ // M17 Sig Sauer NATO 9x19mm +P 124gr V-Crown https://www.sigsauer.com/blog/sig-sauer-introduces-m17-9mm-p-ammunition
    {
        ACE_ballisticCoefficients[]={0.204}; // ICAO G1 BC from exterior ballistic app "EBC V2" based on Sig Sauer 2024 datas https://cdn.bfldr.com/EN1VTHA0/at/k4vxwr73g8mj5bt485mh8bcz/2024_DSG_CATALOG__6-3-24_SL.pdf#page=57
        hit=9; // Jacketed Hollow Point, 736 Joules, B_9x21_Ball 5
        airFriction=-0.00199741; // ICAO conditions (15°C, 1013.25hPa, 0%), airFrictionAnalysis.txt in docs folder
        caliber=0.72; // Jacketed Hollow Point, B_9x21_Ball 1.2
    };
    class JCA_B_9x19_Ball_MP5_Tracer_Green: JCA_B_9x19_Ball_MP5_FMJ
    {
        visibleFire=5; // B_9x21_Ball 3, B_762x51_Ball 3, B_762x51_Minigun_Tracer_Red 5
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class JCA_B_9x19_Ball_MP5_Tracer_Red: JCA_B_9x19_Ball_MP5_Tracer_Green
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Red";
    };
    class JCA_B_9x19_Ball_MP5_Tracer_Yellow: JCA_B_9x19_Ball_MP5_Tracer_Green
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_Yellow";
    };
    class JCA_B_9x19_Ball_MP5_Tracer_IR: JCA_B_9x19_Ball_MP5_FMJ
    {
        nvgOnly=1;
    };
};
class CfgMagazines
{
    class CA_Magazine;
    /*class 30Rnd_9x21_Mag: CA_Magazine // official BI tool All-in-one Config Arma3 2.17.152041 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        author="$STR_A3_Bohemia_Interactive";
        scope=2;
        displayName="$STR_A3_CfgMagazines_30Rnd_9x21_Mag0";
        picture="\A3\Weapons_F\Data\UI\M_30Rnd_45ACP_CA.paa";
        ammo="B_9x21_Ball";
        count=30;
        mass=10;
        initSpeed=370;
        tracersEvery=0;
        descriptionShort="$STR_A3_CfgMagazines_30Rnd_9x21_Mag1";
    };*/
    class JCA_30Rnd_9x19_MP5_Mag: CA_Magazine // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        displayName="9 mm 30Rnd MP5 FMJ Mag";
        ammo="JCA_B_9x19_Ball_MP5_FMJ";
        mass=10; // 11.9 magazine 30 rounds empty 170g + 30x 12.3g, 30Rnd_9x21_Mag 10, JCA 10
        initSpeed=428; // according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 370
        descriptionShort="Caliber: 9x19 mm<br />Rounds: 30<br />Used in: MP5A5";
        displaynameshort="FMJ";
    };
    class JCA_30Rnd_9x19_MP5_JHP_Mag: JCA_30Rnd_9x19_MP5_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Jacketed Hollow Point JHP
    {
        author="Laid3acK";
        displayName="9 mm 30Rnd MP5 JHP Mag";
        ammo="JCA_B_9x19_Ball_MP5_JHP";
        displaynameshort="JHP";
    };
    class JCA_30Rnd_9x19_MP5_Red_Mag: JCA_30Rnd_9x19_MP5_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Red";
    };
    class JCA_30Rnd_9x19_MP5_Green_Mag: JCA_30Rnd_9x19_MP5_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Green";
    };
    class JCA_30Rnd_9x19_MP5_Yellow_Mag: JCA_30Rnd_9x19_MP5_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Yellow";
    };
    class JCA_30Rnd_9x19_MP5_IR_Mag: JCA_30Rnd_9x19_MP5_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_IR";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Red_Mag: JCA_30Rnd_9x19_MP5_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Red";
        displaynameshort="Tracer";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Green_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Green";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Yellow";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_IR_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_30Rnd_9x19_MP5_Sand_Mag: JCA_30Rnd_9x19_MP5_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        displayName="9 mm 30Rnd MP5 FMJ Sand Mag";
    };
    class JCA_30Rnd_9x19_MP5_JHP_Sand_Mag: JCA_30Rnd_9x19_MP5_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Jacketed Hollow Point JHP
    {
        author="Laid3acK";
        displayName="9 mm 30Rnd MP5 JHP Sand Mag";
        ammo="JCA_B_9x19_Ball_MP5_JHP";
        displaynameshort="JHP";
    };
    class JCA_30Rnd_9x19_MP5_Red_Sand_Mag: JCA_30Rnd_9x19_MP5_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Red";
    };
    class JCA_30Rnd_9x19_MP5_Green_Sand_Mag: JCA_30Rnd_9x19_MP5_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Green";
    };
    class JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag: JCA_30Rnd_9x19_MP5_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Yellow";
    };
    class JCA_30Rnd_9x19_MP5_IR_Sand_Mag: JCA_30Rnd_9x19_MP5_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_IR";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag: JCA_30Rnd_9x19_MP5_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Red";
        displaynameshort="Tracer";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Green";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_Yellow";
    };
    class JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag: JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag // M17 Sig Sauer NATO 9x19mm +P 124gr Full Metal Jacket FMJ
    {
        ammo="JCA_B_9x19_Ball_MP5_FMJ_Tracer_IR";
        displaynameshort="Tracer IR";
    };
};
class CfgMagazineWells
{
    class JCA_MP5_9x19 // Weapon initSpeed -1 ACE_barrelLength 225mm: 428m/s ICAO conditions (15°C, 1013.25 hPa, 0%) according to JCA_30Rnd_9x19_MP5 magazines initSpeed
    {
        JCA_Magazines[]=
        {
            "JCA_30Rnd_9x19_MP5_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag"
        };
    };
};
class Mode_FullAuto;
class Mode_SemiAuto;
class CfgWeapons
{
    class ItemCore;
    class Rifle_Base_F;
    class Rifle_Short_Base_F: Rifle_Base_F
    {
        class WeaponSlotsInfo;
    };
    class JCA_smg_MP5_base_F: Rifle_Short_Base_F // https://www.heckler-koch.com/en/Products/Military%20and%20Law%20Enforcement/Submachine%20guns/MP5?section=variants&s=true
    {
        ACE_barrelLength=225; // 8.858"
        ACE_barrelTwist=250; // CIP twist https://bobp.cip-bobp.org/uploads/tdcc/tab-iv/tabivcal-en-page28.pdf
        ACE_RailHeightAboveBore=3.74837;  // ACE3 checkScopes.sqf
        maxZeroing=400; // distance 9x19 M17 FMJ 124gr Mach 0.8 (272m/s) ICAO, JCA 400, SMG_05_F (Protector) 200, SMG_02_F (Sting) 600
        initSpeed=-1; // 428m/s according to ACE_muzzleVelocities ICAO conditions (15°C, 1013.25hPa, 0%), JCA 375
        descriptionShort="Submachine Gun<br />Caliber: 9x19 mm";
        magazines[]=
        {
            "JCA_30Rnd_9x19_MP5_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag"
        };
        class Single: Mode_SemiAuto
        {
            dispersion=0.000765; // 4.68 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00116 (3.99 MOA)
        };
        class FullAuto: Mode_FullAuto
        {
            dispersion=0.000765; // 4.68 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00116 (3.99 MOA)
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=67.9; // 3080g w/o magazine https://de.wikipedia.org/wiki/HK_MP5, JCA 50
        };
    };
    class JCA_smg_MP5_AFG_base_F: JCA_smg_MP5_base_F
    {
    };
    class JCA_smg_MP5_VFG_base_F: JCA_smg_MP5_base_F
    {
    };
    class JCA_smg_MP5_FL_base_F: JCA_smg_MP5_base_F
    {
    };
    class JCA_smg_MP5_AFG_sand_F: JCA_smg_MP5_AFG_base_F
    {
        magazines[]=
        {
            "JCA_30Rnd_9x19_MP5_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Mag"
        };
    };
    class JCA_smg_MP5_VFG_sand_F: JCA_smg_MP5_VFG_base_F
    {
        magazines[]=
        {
            "JCA_30Rnd_9x19_MP5_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Mag"
        };
    };
    class JCA_smg_MP5_FL_sand_F: JCA_smg_MP5_FL_base_F
    {
        magazines[]=
        {
            "JCA_30Rnd_9x19_MP5_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Sand_Mag",
            "JCA_30Rnd_9x19_MP5_Mag",
            "JCA_30Rnd_9x19_MP5_JHP_Mag",
            "JCA_30Rnd_9x19_MP5_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_IR_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Red_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Green_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_Yellow_Mag",
            "JCA_30Rnd_9x19_MP5_Tracer_IR_Mag"
        };
    };
    class JCA_optic_ROS_base: ItemCore
    {
        ACE_ScopeHeightAboveRail=3.71751; // ACE3 checkScopes.sqf
    };
    class JCA_muzzle_snds_MP5_base: ItemCore
    {
        class ItemInfo;
    };
    class muzzle_snds_H: ItemCore // Sound Suppressor 6.5mm
    {
        class ItemInfo;
    };
    class JCA_muzzle_snds_MP5_black: JCA_muzzle_snds_MP5_base // Sound Suppressor 9mm, muzzle_snds_L
    {
        class ItemInfo: ItemInfo
        {
            mass=9.5; // Heckler & Koch KAC-Navy MP5N 9mm Suppressor 0.95 lbs, muzzle_snds_L 6, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_L 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.03; // muzzle_snds_L, JCA 0.04, muzzle_snds_H 0.04
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_L 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_L 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_L 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_L, JCA 0.2, muzzle_snds_H 0.2
    };
    class JCA_muzzle_snds_MP5_sand: JCA_muzzle_snds_MP5_base // Sound Suppressor 9mm, muzzle_snds_L
    {
        class ItemInfo: ItemInfo
        {
            mass=9.5; // Heckler & Koch KAC-Navy MP5N 9mm Suppressor 0.95 lbs, muzzle_snds_L 6, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_L 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.03; // muzzle_snds_L, JCA 0.04, muzzle_snds_H 0.04
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_L 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_L 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_L 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_L, JCA 0.2, muzzle_snds_H 0.2
    };
    class JCA_muzzle_snds_MP5_olive: JCA_muzzle_snds_MP5_base // Sound Suppressor 9mm, muzzle_snds_L
    {
        class ItemInfo: ItemInfo
        {
            mass=9.5; // Heckler & Koch KAC-Navy MP5N 9mm Suppressor 0.95 lbs, muzzle_snds_L 6, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_L 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.03; // muzzle_snds_L, JCA 0.04, muzzle_snds_H 0.04
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_L 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_L 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_L 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_L, JCA 0.2, muzzle_snds_H 0.2
    };
    // official BI tool All-in-one Config Arma3 2.17.152041 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    class muzzle_snds_L: muzzle_snds_H // Sound Suppressor 9mm
    {
        class ItemInfo: ItemInfo
        {
            // mass=6;
            class MagazineCoef
            {
                initSpeed=1; // ACE3, muzzle_snds_L 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.03;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, muzzle_snds_L 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_L 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_L 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        // inertia=0.1;
    };
};